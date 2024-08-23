#include "global.h"
#include "gflib.h"
#include "bike.h"
#include "event_data.h"
#include "event_object_lock.h"
#include "field_camera.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "item.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "quest_log.h"
#include "script.h"
#include "task.h"
#include "constants/field_tasks.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/metatile_labels.h"
#include "constants/songs.h"

/*  This file handles some persistent tasks that run in the overworld.
 *  - Task_RunTimeBasedEvents: Triggers ambient cries. In RSE, this also periodically updates local time and RTC events.
 *  - Task_RunPerStepCallback: Calls one of the functions in sPerStepCallbacks, listed below...
 *      . DummyPerStepCallback: Default, does nothing. Includes functionality from RS that was removed.
 *      . AshGrassPerStepCallback: Leftover from RS. Removes the ash from ash-covered grass that the player steps on.
 *      . IcefallCaveIcePerStepCallback: Cracks/breaks ice in Icefall Cave that the player steps on.
 *      . CrackedFloorPerStepCallback: Leftover from RS. Breaks cracked floors that the player steps on.
 *
 *  NOTE: "PerStep" is perhaps misleading. One function in sPerStepCallbacks is called
 *        every frame while in the overworld by Task_RunPerStepCallback regardless of
 *        whether or not steps are being taken. However, nearly all of the functions in
 *        the table check if the player has moved from their previous position before
 *        doing anything else.
 */

static void DummyPerStepCallback(u8 taskId);
static void AshGrassPerStepCallback(u8 taskId);
static void IcefallCaveIcePerStepCallback(u8 taskId);
static void RegicePuzzleIcePerStepCallback(u8 taskId);
static void CrackedFloorPerStepCallback(u8 taskId);

static const TaskFunc sPerStepCallbacks[] =
{
    [STEP_CB_DUMMY]             = DummyPerStepCallback,
    [STEP_CB_ASH]               = AshGrassPerStepCallback,
    [STEP_CB_FORTREE_BRIDGE]    = DummyPerStepCallback,
    [STEP_CB_PACIFIDLOG_BRIDGE] = DummyPerStepCallback,
    [STEP_CB_ICE]               = IcefallCaveIcePerStepCallback,
    [STEP_CB_REGICE_PUZZLE]     = RegicePuzzleIcePerStepCallback,
    [STEP_CB_SECRET_BASE]       = DummyPerStepCallback,
    [STEP_CB_CRACKED_FLOOR]     = CrackedFloorPerStepCallback
};

// The positions of each map space with crackable ice in Icefall Cave.
static const u8 sIcefallCaveIceCoords[][2] =
{
    {  8,  3 },
    { 10,  5 },
    { 15,  5 },
    {  8,  9 },
    {  9,  9 },
    { 16,  9 },
    {  8, 10 },
    {  9, 10 },
    {  8, 14 }
};

static const u16 sRegicePuzzleIceColumnVars[] =
{
    0,
    0,
    0,
    VAR_TEMP_1,
    VAR_TEMP_2,
    VAR_TEMP_3,
    VAR_TEMP_4,
    VAR_TEMP_5,
    VAR_TEMP_6,
    VAR_TEMP_7,
    VAR_TEMP_8,
    VAR_TEMP_9,
    0,
    0,
    0,
};

#define tCallbackId data[0]

static void Task_RunPerStepCallback(u8 taskId)
{
    int idx = gTasks[taskId].tCallbackId;
    sPerStepCallbacks[idx](taskId);
}

#define tAmbientCryState data[1]
#define tAmbientCryDelay data[2]

// RTC functionality from RS was removed here.
static void Task_RunTimeBasedEvents(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!ArePlayerFieldControlsLocked() && !QL_IS_PLAYBACK_STATE)
        UpdateAmbientCry(&tAmbientCryState, &tAmbientCryDelay);
}

void SetUpFieldTasks(void)
{
    if (!FuncIsActiveTask(Task_RunPerStepCallback))
    {
        u8 taskId = CreateTask(Task_RunPerStepCallback, 80);
        gTasks[taskId].tCallbackId = STEP_CB_DUMMY;
    }

    if (!FuncIsActiveTask(Task_RunTimeBasedEvents))
        CreateTask(Task_RunTimeBasedEvents, 80);
}

void ActivatePerStepCallback(u8 callbackId)
{
    u8 taskId = FindTaskIdByFunc(Task_RunPerStepCallback);
    if (taskId != TASK_NONE)
    {
        s32 i;
        s16 *data = gTasks[taskId].data;

        for (i = 0; i < NUM_TASK_DATA; i++)
            data[i] = 0;

        if (callbackId >= ARRAY_COUNT(sPerStepCallbacks))
            tCallbackId = STEP_CB_DUMMY;
        else
            tCallbackId = callbackId;
    }
}

void ResetFieldTasksArgs(void)
{
    u8 taskId;
    s16 *data;

    taskId = FindTaskIdByFunc(Task_RunPerStepCallback);
    if (taskId != TASK_NONE)
        data = gTasks[taskId].data;

    taskId = FindTaskIdByFunc(Task_RunTimeBasedEvents);
    if (taskId != TASK_NONE)
    {
        data = gTasks[taskId].data;
        tAmbientCryState = 0;
        tAmbientCryDelay = 0;
    }
}

#undef tAmbientCryState
#undef tAmbientCryDelay

static void DummyPerStepCallback(u8 taskId)
{
}

static void MarkIcePuzzleCoordVisited(s16 x, s16 y)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sIcefallCaveIceCoords); i++)
    {
        if (sIcefallCaveIceCoords[i][0] + MAP_OFFSET == x && sIcefallCaveIceCoords[i][1] + MAP_OFFSET == y)
        {
            FlagSet(i + 1);
            break;
        }
    }
}

void SetIcefallCaveCrackedIceMetatiles(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sIcefallCaveIceCoords); i++)
    {
        if (FlagGet(i + 1) == TRUE)
        {
            int x = sIcefallCaveIceCoords[i][0] + MAP_OFFSET;
            int y = sIcefallCaveIceCoords[i][1] + MAP_OFFSET;
            MapGridSetMetatileIdAt(x, y, METATILE_SeafoamIslands_CrackedIce);
        }
    }
}

#define tState data[1]
#define tPrevX data[2]
#define tPrevY data[3]
#define tIceX  data[4]
#define tIceY  data[5]
#define tDelay data[6]

static void IcefallCaveIcePerStepCallback(u8 taskId)
{
    s16 x, y;
    u8 tileBehavior;
    u16 *iceStepCount;
    s16 *data = gTasks[taskId].data;
    switch (tState)
    {
        case 0:
            PlayerGetDestCoords(&x, &y);
            tPrevX = x;
            tPrevY = y;
            tState = 1;
            break;
        case 1:
            PlayerGetDestCoords(&x, &y);
            // End if player hasn't moved
            if (x == tPrevX && y == tPrevY)
                return;

            tPrevX = x;
            tPrevY = y;
            tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
            if (MetatileBehavior_IsThinIce(tileBehavior) == TRUE)
            {
                // Thin ice, set it to cracked ice
                MarkIcePuzzleCoordVisited(x, y);
                tDelay = 4;
                tState = 2;
                tIceX = x;
                tIceY = y;
            }
            else if (MetatileBehavior_IsCrackedIce(tileBehavior) == TRUE)
            {
                // Cracked ice, set it to broken ice
                tDelay = 4;
                tState = 3;
                tIceX = x;
                tIceY = y;
            }
            break;
        case 2:
            if (tDelay != 0)
            {
                tDelay--;
            }
            else
            {
                // Crack ice
                x = tIceX;
                y = tIceY;
                PlaySE(SE_ICE_CRACK);
                MapGridSetMetatileIdAt(x, y, METATILE_SeafoamIslands_CrackedIce);
                CurrentMapDrawMetatileAt(x, y);
                tState = 1;
            }
            break;
        case 3:
            FreezeObjects_WaitForPlayer();
            if (tDelay != 0)
            {
                tDelay--;
            }
            else
            {
                // Break ice
                x = tIceX;
                y = tIceY;
                PlaySE(SE_ICE_BREAK);
                MapGridSetMetatileIdAt(x, y, METATILE_SeafoamIslands_IceHole);
                CurrentMapDrawMetatileAt(x, y);
                VarSet(VAR_TEMP_1, 1);
                tState = 1;
            }
            break;
    }
}

static bool32 CoordInIcePuzzleRegion(s16 x, s16 y)
{
    if ((u16)(x - 3) < 11 && (u16)(y - 6) < 14 && sRegicePuzzleIceColumnVars[y])
        return TRUE;
    else
        return FALSE;
}

static void MarkRegicePuzzleCoordVisited(s16 x, s16 y)
{
    *GetVarPointer(sRegicePuzzleIceColumnVars[x]) |= (1 << (y - 4));
}

static bool32 IsIcePuzzleCoordVisited(s16 x, s16 y)
{
    u32 var;

    var = VarGet(sRegicePuzzleIceColumnVars[x]) << 16;
    if ((0x10000 << (y - 4)) & var) // TODO: fix that if
        return TRUE;
    else
        return FALSE;
}

void SetRegicePuzzleCrackedIceMetatiles(void)
{
    s32 x, y;
    s32 width = gMapHeader.mapLayout->width;
    s32 height = gMapHeader.mapLayout->height;
    for (x = 0; x < width; x++)
    {
        for (y = 0; y < height; y++)
        {
            if (IsIcePuzzleCoordVisited(x, y) == TRUE)
                MapGridSetMetatileIdAt(x + 7, y + 7, METATILE_SeafoamIslands_CrackedIce);
        }
    }
}

static void RegicePuzzleIcePerStepCallback(u8 taskId)
{
    s16 x, y;
    u16 tileBehavior;
    u16 *iceStepCount;
    s16 *data = gTasks[taskId].data;
    switch (data[1])
    {
        case 0:
            PlayerGetDestCoords(&x, &y);
            data[2] = x;
            data[3] = y;
            data[1] = 1;
            break;
        case 1:
            PlayerGetDestCoords(&x, &y);
            if (x != data[2] || y != data[3])
            {
                data[2] = x;
                data[3] = y;
                tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
                iceStepCount = GetVarPointer(VAR_ICE_STEP_COUNT);
                if (MetatileBehavior_IsThinIce(tileBehavior) == TRUE)
                {
                    (*iceStepCount)++;
                    data[6] = 4;
                    data[1] = 2;
                    data[4] = x;
                    data[5] = y;
                }
                else if (MetatileBehavior_IsCrackedIce(tileBehavior) == TRUE)
                {
                    *iceStepCount = 0;
                    data[6] = 4;
                    data[1] = 3;
                    data[4] = x;
                    data[5] = y;
                }
            }
            break;
        case 2:
            if (data[6] != 0)
            {
                data[6]--;
            }
            else
            {
                x = data[4];
                y = data[5];
                PlaySE(SE_ICE_CRACK);
                MapGridSetMetatileIdAt(x, y, METATILE_SeafoamIslands_CrackedIce);
                CurrentMapDrawMetatileAt(x, y);
                MarkRegicePuzzleCoordVisited(x - 7, y - 7);
                data[1] = 1;
            }
            break;
        case 3:
            if (data[6] != 0)
            {
                data[6]--;
            }
            else
            {
                x = data[4];
                y = data[5];
                PlaySE(SE_ICE_BREAK);
                MapGridSetMetatileIdAt(x, y, METATILE_SeafoamIslands_IceHole);
                CurrentMapDrawMetatileAt(x, y);
                data[1] = 1;
            }
            break;
    }
}


#undef tState
#undef tPrevX
#undef tPrevY
#undef tIceX
#undef tIceY
#undef tDelay

#define tPrevX data[1]
#define tPrevY data[2]

static void AshGrassPerStepCallback(u8 taskId)
{
    s16 x, y;
    u16 *ashGatherCount;
    s16 *data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);

    // End if player hasn't moved
    if (x == tPrevX && y == tPrevY)
        return;

    tPrevX = x;
    tPrevY = y;
    if (MetatileBehavior_IsAshGrass((u8)MapGridGetMetatileBehaviorAt(x, y)))
    {
        if (MapGridGetMetatileIdAt(x, y) == METATILE_SeviiIslands123_OneIsland_AshGrass)
            StartAshFieldEffect(x, y, METATILE_SeviiIslands123_OneIsland_Grass, 4);

        if (CheckBagHasItem(ITEM_SOOT_SACK, 1))
        {
            ashGatherCount = GetVarPointer(VAR_ASH_GATHER_COUNT);
            if (*ashGatherCount < 9999)
                (*ashGatherCount)++;
        }
    }
}

#undef tPrevX
#undef tPrevY

// Unused. For some reason these were not dummied out like the other RSE-exclusive step callbacks.
static void SetCrackedFloorHoleMetatile(s16 x, s16 y)
{
    MapGridSetMetatileIdAt(x, y, MapGridGetMetatileIdAt(x, y) == METATILE_RSCave_CrackedFloor ? METATILE_RSCave_CrackedFloor_Hole : METATILE_Pacifidlog_SkyPillar_CrackedFloor_Hole);
    CurrentMapDrawMetatileAt(x, y);
}

#define tPrevX       data[2]
#define tPrevY       data[3]
#define tFloor1Delay data[4]
#define tFloor1X     data[5]
#define tFloor1Y     data[6]
#define tFloor2Delay data[7]
#define tFloor2X     data[8]
#define tFloor2Y     data[9]

// Unused. See above.
static void CrackedFloorPerStepCallback(u8 taskId)
{
    s16 x, y;
    u16 behavior;
    s16 *data = gTasks[taskId].data;
    PlayerGetDestCoords(&x, &y);
    behavior = MapGridGetMetatileBehaviorAt(x, y);

    // Update up to 2 previous cracked floor spaces
    if (tFloor1Delay != 0 && (--tFloor1Delay) == 0)
        SetCrackedFloorHoleMetatile(tFloor1X, tFloor1Y);
    if (tFloor2Delay != 0 && (--tFloor2Delay) == 0)
        SetCrackedFloorHoleMetatile(tFloor2X, tFloor2Y);

    // End if player hasn't moved
    if (x == tPrevX && y == tPrevY)
        return;

    tPrevX = x;
    tPrevY = y;
    if (MetatileBehavior_IsCrackedFloor(behavior))
    {
        if (GetPlayerSpeed() != PLAYER_SPEED_FASTEST)
            VarSet(VAR_ICE_STEP_COUNT, 0); // this var does double duty

        if (tFloor1Delay == 0)
        {
            tFloor1Delay = 3;
            tFloor1X = x;
            tFloor1Y = y;
        }
        else if (tFloor2Delay == 0)
        {
            tFloor2Delay = 3;
            tFloor2X = x;
            tFloor2Y = y;
        }
    }
}

#undef tPrevX
#undef tPrevY
#undef tFloor1Delay
#undef tFloor1X
#undef tFloor1Y
#undef tFloor2Delay
#undef tFloor2X
#undef tFloor2Y
