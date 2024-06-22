#include "global.h"
#include "event_data.h"
#include "random.h"
#include "overworld.h"
#include "field_specials.h"
#include "constants/flags.h"
#include "constants/species.h"
#include "constants/maps.h"
#include "constants/region_map_sections.h"
#include "data/pokemon/roamers.h"

// Despite having a variable to track it, the roamer is
// hard-coded to only ever be in map group 3
#define ROAMER_MAP_GROUP 3

enum
{
    MAP_GRP, // map group
    MAP_NUM, // map number
};

#define MAX_ROAMERS 4

EWRAM_DATA u8 sLocationHistory[MAX_ROAMERS][3][2] = {};
EWRAM_DATA u8 sRoamerLocation[MAX_ROAMERS][2] = {};

// work with create index/species then assign to predetermined slot


#define ___ MAP_NUM(UNDEFINED) // For empty spots in the location table

// Note: There are two potential softlocks that can occur with this table if its maps are
//       changed in particular ways. They can be avoided by ensuring the following:
//       - There must be at least 2 location sets that start with a different map,
//         i.e. every location set cannot start with the same map. This is because of
//         the while loop in RoamerMoveToOtherLocationSet.
//       - Each location set must have at least 3 unique maps. This is because of
//         the while loop in RoamerMove. In this loop the first map in the set is
//         ignored, and an additional map is ignored if the roamer was there recently.
//       - Additionally, while not a softlock, it's worth noting that if for any
//         map in the location table there is not a location set that starts with
//         that map then the roamer will be significantly less likely to move away
//         from that map when it lands there.
static const u8 sRoamerLocations[][7] = {
    {MAP_NUM(ROUTE1), MAP_NUM(ROUTE2), MAP_NUM(ROUTE21_NORTH), MAP_NUM(ROUTE22), ___, ___, ___},
    {MAP_NUM(ROUTE2), MAP_NUM(ROUTE1), MAP_NUM(ROUTE3), MAP_NUM(ROUTE22), ___, ___, ___},
    {MAP_NUM(ROUTE3), MAP_NUM(ROUTE2), MAP_NUM(ROUTE4), ___, ___, ___, ___},
    {MAP_NUM(ROUTE4), MAP_NUM(ROUTE3), MAP_NUM(ROUTE5), MAP_NUM(ROUTE9), MAP_NUM(ROUTE24), ___, ___},
    {MAP_NUM(ROUTE5), MAP_NUM(ROUTE4), MAP_NUM(ROUTE6), MAP_NUM(ROUTE7), MAP_NUM(ROUTE8), MAP_NUM(ROUTE9), MAP_NUM(ROUTE24)},
    {MAP_NUM(ROUTE6), MAP_NUM(ROUTE5), MAP_NUM(ROUTE7), MAP_NUM(ROUTE8), MAP_NUM(ROUTE11), ___, ___},
    {MAP_NUM(ROUTE7), MAP_NUM(ROUTE5), MAP_NUM(ROUTE6), MAP_NUM(ROUTE8), MAP_NUM(ROUTE16), ___, ___},
    {MAP_NUM(ROUTE8), MAP_NUM(ROUTE5), MAP_NUM(ROUTE6), MAP_NUM(ROUTE7), MAP_NUM(ROUTE10), MAP_NUM(ROUTE12), ___},
    {MAP_NUM(ROUTE9), MAP_NUM(ROUTE4), MAP_NUM(ROUTE5), MAP_NUM(ROUTE10), MAP_NUM(ROUTE24), ___, ___},
    {MAP_NUM(ROUTE10), MAP_NUM(ROUTE8), MAP_NUM(ROUTE9), MAP_NUM(ROUTE12), ___, ___, ___},
    {MAP_NUM(ROUTE11), MAP_NUM(ROUTE6), MAP_NUM(ROUTE12), ___, ___, ___, ___},
    {MAP_NUM(ROUTE12), MAP_NUM(ROUTE10), MAP_NUM(ROUTE11), MAP_NUM(ROUTE13), ___, ___, ___},
    {MAP_NUM(ROUTE13), MAP_NUM(ROUTE12), MAP_NUM(ROUTE14), ___, ___, ___, ___},
    {MAP_NUM(ROUTE14), MAP_NUM(ROUTE13), MAP_NUM(ROUTE15), ___, ___, ___, ___},
    {MAP_NUM(ROUTE15), MAP_NUM(ROUTE14), MAP_NUM(ROUTE18), MAP_NUM(ROUTE19), ___, ___, ___},
    {MAP_NUM(ROUTE16), MAP_NUM(ROUTE7), MAP_NUM(ROUTE17), ___, ___, ___, ___},
    {MAP_NUM(ROUTE17), MAP_NUM(ROUTE16), MAP_NUM(ROUTE18), ___, ___, ___, ___},
    {MAP_NUM(ROUTE18), MAP_NUM(ROUTE15), MAP_NUM(ROUTE17), MAP_NUM(ROUTE19), ___, ___, ___},
    {MAP_NUM(ROUTE19), MAP_NUM(ROUTE15), MAP_NUM(ROUTE18), MAP_NUM(ROUTE20), ___, ___, ___},
    {MAP_NUM(ROUTE20), MAP_NUM(ROUTE19), MAP_NUM(ROUTE21_NORTH), ___, ___, ___, ___},
    {MAP_NUM(ROUTE21_NORTH), MAP_NUM(ROUTE1), MAP_NUM(ROUTE20), ___, ___, ___, ___},
    {MAP_NUM(ROUTE22), MAP_NUM(ROUTE1), MAP_NUM(ROUTE2), MAP_NUM(ROUTE23), ___, ___, ___},
    {MAP_NUM(ROUTE23), MAP_NUM(ROUTE22), MAP_NUM(ROUTE2), ___, ___, ___, ___},
    {MAP_NUM(ROUTE24), MAP_NUM(ROUTE4), MAP_NUM(ROUTE5), MAP_NUM(ROUTE9), ___, ___, ___},
    {MAP_NUM(ROUTE25), MAP_NUM(ROUTE24), MAP_NUM(ROUTE9), ___, ___, ___, ___},
    {___, ___, ___, ___, ___, ___, ___}
};

#undef ___
#define NUM_LOCATION_SETS (ARRAY_COUNT(sRoamerLocations) - 1)
#define NUM_LOCATIONS_PER_SET (ARRAY_COUNT(sRoamerLocations[0]))

static struct Roamer * RoamerSlots(void)
{
    struct Roamer * result[MAX_ROAMERS] = {
        &gSaveBlock1Ptr->roamer1,
        &gSaveBlock1Ptr->roamer2,
        &gSaveBlock1Ptr->roamer3,
        &gSaveBlock1Ptr->roamer4
    };
    return result
}

void ClearRoamerData(void)
{
    u32 i;
    u32 j;
    
    for (i = 0; i < MAX_ROAMERS; i++)
    {
        *RoamerSlots()[i] = (struct Roamer) {};
        sRoamerLocation[i][MAP_GRP] = 0;
        sRoamerLocation[i][MAP_NUM] = 0;
        for (j = 0; j < 3; j++)
        {
            sLocationHistory[i][j][MAP_GRP] = 0;
            sLocationHistory[i][j][MAP_NUM] = 0;
        }
    }
}

void UpdateLocationHistoryForRoamer(void)
{
    u32 i;
    for (i = 0; i < MAX_ROAMERS; i++)
    {
        sLocationHistory[i][2][MAP_GRP] = sLocationHistory[i][1][MAP_GRP];
        sLocationHistory[i][2][MAP_NUM] = sLocationHistory[i][1][MAP_NUM];

        sLocationHistory[i][1][MAP_GRP] = sLocationHistory[i][0][MAP_GRP];
        sLocationHistory[i][1][MAP_NUM] = sLocationHistory[i][0][MAP_NUM];

        sLocationHistory[i][0][MAP_GRP] = gSaveBlock1Ptr->location.mapGroup;
        sLocationHistory[i][0][MAP_NUM] = gSaveBlock1Ptr->location.mapNum;
    }
}

void SlotRoamerMoveToOtherLocationSet(u8 slot)
{
    u8 mapNum = 0;
    // Choose a location set that starts with a map
    // different from the roamer's current map
    if (RoamerSlots()[slot]->active)
    {
        while (1)
        {
            mapNum = sRoamerLocations[Random() % NUM_LOCATION_SETS][0];
            if (sRoamerLocation[slot][MAP_NUM] != mapNum)
            {
                sRoamerLocation[slot][MAP_NUM] = mapNum;
                return;
            }
        }
    }
}


void RoamerMoveToOtherLocationSet(void)
{
    u32 i;
    for (i = 0; i < MAX_ROAMERS; i++)
    {
        SlotRoamerMoveToOtherLocationSet(i);
    }
}

void RoamerMove(void)
{
    u32 i; //roamer slot
    u8 locSet = 0;
    for (i = 0; i < MAX_ROAMERS; i++)
    {
        if (!RoamerSlots()[i]->active)
            continue;
        if ((Random() % 16) == 0)
        {
            SlotRoamerMoveToOtherLocationSet(i);
        }
        else
        {
            while (locSet < NUM_LOCATION_SETS)
            {
                // Find the location set that starts with the roamer's current map
                if (sRoamerLocation[i][MAP_NUM] == sRoamerLocations[locSet][0])
                {
                    u8 mapNum;
                    while (1)
                    {
                        // Choose a new map (excluding the first) within this set
                        // Also exclude a map if the roamer was there 2 moves ago
                        mapNum = sRoamerLocations[locSet][(Random() % (NUM_LOCATIONS_PER_SET - 1)) + 1];
                        if (!(sLocationHistory[i][2][MAP_GRP] == ROAMER_MAP_GROUP
                        && sLocationHistory[i][2][MAP_NUM] == mapNum)
                        && mapNum != MAP_NUM(UNDEFINED))
                            break;
                    }
                    sRoamerLocation[i][MAP_NUM] = mapNum;
                    return;
                }
                locSet++;
            }
        }
    }
}

static bool8 IsSpeciesActiveRoamer(u16 species, struct Roamer * possibleSlot)
{
    u32 i; //roamer slot
    struct Roamer * slotData;
    for (i = 0; i < MAX_ROAMERS; i++)
    {
        slotData = RoamerSlots()[i];
        if (slotData->active)
        {
            if (slotData->species == species)
            {
                possibleSlot = slotData;
                return TRUE;
            }
        }
    }
    return FALSE;
}

void UpdateRoamerHPStatus(struct Pokemon *mon)
{
    struct Roamer * slotData;
    IsSpeciesActiveRoamer(GetMonData(mon, MON_DATA_SPECIES), slotData);
    slotData->hp = GetMonData(mon, MON_DATA_HP);
    slotData->status = GetMonData(mon, MON_DATA_STATUS);
}

void SetRoamerInactive(u16 roamerSpecies)
{
    struct Roamer * slot;
    if (IsSpeciesActiveRoamer(roamerSpecies, slot))
    {
        slot->active = FALSE;
    }
}

void GetRoamerLocation(u16 species, u8 *mapGroup, u8 *mapNum)
{
    u32 i; //roamer slot
    struct Roamer * slotData;
    for (i = 0; i < MAX_ROAMERS; i++)
    {
        slotData = RoamerSlots()[i];
        if (slotData->species == species)
        {
                *mapGroup = sRoamerLocation[i][MAP_GRP];
                *mapNum = sRoamerLocation[i][MAP_NUM];
        }
    }
}

u16 GetRoamerLocationMapSectionId(u16 species) 
{
    u32 i;
    struct Roamer * slotData;
    for (i = 0; i < MAX_ROAMERS; i++)
    {
        slotData = RoamerSlots()[i];
        if (slotData->species == species)
        {
            if (!slotData->active)
                return MAPSEC_NONE;
            return Overworld_GetMapHeaderByGroupAndId(sRoamerLocation[i][MAP_GRP], sRoamerLocation[i][MAP_NUM])->regionMapSectionId;
        }
    }
    return 0;
}

static u8 SetRoamerDataToMon(struct Pokemon * mon, struct Roamer * slotMon)
{
    u32 status;
    CreateMonWithIVsPersonality(mon, gRoamersTable[slotMon->roamerDataIndex].species, gRoamersTable[slotMon->roamerDataIndex].level, slotMon->ivs, slotMon->personality);
    // The roamer's status field is u8, but SetMonData expects status to be u32, so will set the roamer's status
    // using the status field and the following 3 bytes (cool, beauty, and cute).
#ifdef BUGFIX
    status = slotMon->status;
    SetMonData(mon, MON_DATA_STATUS, &status);
#else
    SetMonData(mon, MON_DATA_STATUS, &slotMon->status);
#endif
    SetMonData(mon, MON_DATA_HP, &slotMon->hp);
    SetMonData(mon, MON_DATA_COOL, &slotMon->cool);
    SetMonData(mon, MON_DATA_BEAUTY, &slotMon->beauty);
    SetMonData(mon, MON_DATA_CUTE, &slotMon->cute);
    SetMonData(mon, MON_DATA_SMART, &slotMon->smart);
    SetMonData(mon, MON_DATA_TOUGH, &slotMon->tough);
    return slotMon->level;
}

// changes the given list to include zero index roamers and returns amount of roamers active
static u8 AllActiveRoamersAtLocation(u8 mapGroup, u8 mapNum, u8 list[])
{
    u8 size = 0;
    u32 i;
    struct Roamer * slot;
    for (i = 0; i < MAX_ROAMERS; i++)
    {
        slot = RoamerSlots()[i];
        if (slot->active)
        {
            if (mapGroup == sRoamerLocation[i][MAP_GRP] &&
                mapNum == sRoamerLocation[i][MAP_NUM])
            {
                list[size] = i;
                size++;
            }
        }
    }
    return size;
}

static u8 RandomRoamerFromList(u8 size)
{
    return Random() % size; 
}

// Returns roamer slot index, but as 1,2,3 or 4, instead of zero-based
static u8 EncounterRoamerSlot()
{
    u8 numberOfRoamers;
    u8 localActiveRoamerSlots[] = {0,0,0,0}; // amount of roamer slots
    numberOfRoamers = AllActiveRoamersAtLocation(gSaveBlock1Ptr->location.mapGroup, 
                        gSaveBlock1Ptr->location.mapNum, localActiveRoamerSlots);

    if (numberOfRoamers == 0)
    {
        return 0;
    }
    else
    {
        u8 selectedRoamer = RandomRoamerFromList(numberOfRoamers);
        /*if (selectedRoamer == numberOfRoamers)
        {
            return 0;
        } impossible to happen anyway, random should select a proper index*/
        return localActiveRoamerSlots[selectedRoamer] + 1;
    }
}

u8 TryInitializeRoamerEncounter(struct Pokemon *mon)
{
    u8 select = EncounterRoamerSlot();
    if (select == 0)
    {
        return 0;
    }
    return SetRoamerDataToMon(mon, (struct Roamer *)RoamerSlots()[select - 1]);
}

static void InsertRoamerMon(struct Roamer * slot, u8 template)
{
    struct Pokemon * mon = &gEnemyParty[0];
    u16 species = gRoamersTable[template].species;
    u8 level = gRoamersTable[template].level;
    CreateMon(mon, species, level, USE_RANDOM_IVS, FALSE, 0, OT_ID_PLAYER_ID, 0);
    slot->species = species;
    slot->level = level;
    slot->status = 0;
    slot->active = TRUE;
    slot->ivs = GetMonData(mon, MON_DATA_IVS);
    slot->personality = GetMonData(mon, MON_DATA_PERSONALITY);
    slot->hp = GetMonData(mon, MON_DATA_MAX_HP);
    slot->cool = GetMonData(mon, MON_DATA_COOL);
    slot->beauty = GetMonData(mon, MON_DATA_BEAUTY);
    slot->cute = GetMonData(mon, MON_DATA_CUTE);
    slot->smart = GetMonData(mon, MON_DATA_SMART);
    slot->tough = GetMonData(mon, MON_DATA_TOUGH);
}

static void AssignNewLocationToRoamer(u8 slot)
{
    sRoamerLocation[slot][MAP_GRP] = ROAMER_MAP_GROUP;
    sRoamerLocation[slot][MAP_NUM] = sRoamerLocations[Random() % NUM_LOCATION_SETS][0];
}

void StartRoaming(u8 mon)
{
    u32 i;
    struct Roamer * current;
    for (i = 0; i < MAX_ROAMERS; i++)
    {
        current = RoamerSlots()[i];
        if (!current->active)
        {
            InsertRoamerMon(current, mon);
            AssignNewLocationToRoamer(i);
            break; // return would be allowed, but is poor coding
        }
    }
}

bool8 DEBUG_IsRoamerActiveAt(u8 mapGroup, u8 mapNum)
{
    u8 localActiveRoamerSlots[] = {0,0,0,0};
    if (AllActiveRoamersAtLocation(mapGroup, mapNum, localActiveRoamerSlots) > 0)
        return TRUE;
    return FALSE;
}
