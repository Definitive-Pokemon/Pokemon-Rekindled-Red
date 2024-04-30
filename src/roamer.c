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
#define ROAMER(num) (&gSaveBlock1Ptr->roamer##num)

EWRAM_DATA u8 sLocationHistory[4][3][2] = {};
EWRAM_DATA u8 sRoamerLocation[4][2] = {};

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

static struct Roamer * GetRoamer(u8 slot)
{
    struct Roamer * result = ROAMER(1);
    // get properties of roamer struct?
    // first get the next free spot
    if (slot == 2)
    {
        result = ROAMER(2);
    }
    else if (slot == 3)
    {
        result = ROAMER(3);
    }
    else if (slot == 4)
    {
        result = ROAMER(4);
    }
    return result;
}

void ClearRoamerData(void)
{
    u32 i;
    u32 j;
    *ROAMER(1) = (struct Roamer){};
    *ROAMER(2) = (struct Roamer){};
    *ROAMER(3) = (struct Roamer){};
    *ROAMER(4) = (struct Roamer){};
    
    for (i = 0; i < MAX_ROAMERS; i++)
    {
        sRoamerLocation[i][MAP_GRP] = 0;
        sRoamerLocation[i][MAP_NUM] = 0;
        for (j = 0; j < ARRAY_COUNT(sLocationHistory); j++)
        {
            sLocationHistory[i][j][MAP_GRP] = 0;
            sLocationHistory[i][j][MAP_NUM] = 0;
        }
    }
}

u16 GetRoamerSpecies(void)
{
    u16 species = SPECIES_NONE;
    u16 starter = GetStarterSpecies();

    switch(starter)
    {
        case SPECIES_ELEKID:
            if(!FlagGet(FLAG_CAUGHT_RAIKOU))
            {
                species = SPECIES_RAIKOU;
            }
            else if(!FlagGet(FLAG_CAUGHT_ENTEI))
            {
                species = SPECIES_ENTEI;
            }
            else
            {
                species = SPECIES_SUICUNE;
            }
            break;
        case SPECIES_MAGBY:
            if(!FlagGet(FLAG_CAUGHT_ENTEI))
            {
                species = SPECIES_ENTEI;
            }
            else if(!FlagGet(FLAG_CAUGHT_SUICUNE))
            {
                species = SPECIES_SUICUNE;
            }
            else
            {
                species = SPECIES_RAIKOU;
            }
            break;
        case SPECIES_SMOOCHUM:
            if(!FlagGet(FLAG_CAUGHT_SUICUNE))
            {
                species = SPECIES_SUICUNE;
            }
            else if(!FlagGet(FLAG_CAUGHT_RAIKOU))
            {
                species = SPECIES_RAIKOU;
            }
            else
            {
                species = SPECIES_ENTEI;
            }
            break;
    }
    return species;
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

void RoamerMoveToOtherLocationSet(void)
{
    u8 mapNum = 0;
    u32 i;

    // Choose a location set that starts with a map
    // different from the roamer's current map
    for (i = 0; i < MAX_ROAMERS; i++)
    {
        if (GetRoamer(i + 1)->active)
        {
            while (1)
            {
                mapNum = sRoamerLocations[Random() % NUM_LOCATION_SETS][0];
                if (sRoamerLocation[i][MAP_NUM] != mapNum)
                {
                    sRoamerLocation[i][MAP_NUM] = mapNum;
                    return;
                }
            }
        }
    }
}

void RoamerMove(void)
{
    u32 i; //roamer slot
    u8 locSet = 0;
    for (i = 0; i < MAX_ROAMERS; i++)
    {
        if (!GetRoamer(i)->active)
            continue;
        if ((Random() % 16) == 0)
        {
            RoamerMoveToOtherLocationSet();
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
        slotData = GetRoamer(i);
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
        slotData = GetRoamer(i);
        if (slotData->species == species)
        {
                *mapGroup = sRoamerLocation[i][MAP_GRP];
                *mapNum = sRoamerLocation[i][MAP_NUM];
        }
    }
}

u16 GetRoamerLocationMapSectionId(u16 species) 
{
    u32 i; //roamer slot
    struct Roamer * slotData;
    for (i = 0; i < MAX_ROAMERS; i++)
    {
        slotData = GetRoamer(i);
        if (slotData->species == species)
        {
            if (!slotData->active)
                return MAPSEC_NONE;
            return Overworld_GetMapHeaderByGroupAndId(sRoamerLocation[i][MAP_GRP], sRoamerLocation[i][MAP_NUM])->regionMapSectionId;
        }
    }
}

static u8 SetRoamerDataToMon(struct Pokemon * mon, struct Roamer * slotMon)
{
    // struct BattleTowerPokemon * template = &gRoamersTable[&slotMon->roamerDataIndex];
    u32 status;
    CreateMonWithIVsPersonality(mon, slotMon->species, slotMon->level, slotMon->ivs, slotMon->personality);
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

static u8 AllActiveRoamersAtLocation(u8 mapGroup, u8 mapNum, u8 list[])
{
    u8 size = 0;
    u32 i;
    struct Roamer * slot;
    for (i = 1; i < MAX_ROAMERS + 1; i++)
    {
        slot = GetRoamer(i);
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

// TODO this random logic is all very simple
static u8 RandomRoamerFromList(u8 size)
{
    u8 result = size;
    if ((Random() % (MAX_ROAMERS + 1 - size)) == 0)
    {
        result = Random() % size;
    }
    return result; //larger than list means no roamer encounter should happen
}

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
        if (selectedRoamer == numberOfRoamers)
        {
            return 0;
        }
        return localActiveRoamerSlots[selectedRoamer];
    }
}

u8 TryInitializeRoamerEncounter(struct Pokemon *mon)
{
    u8 select = EncounterRoamerSlot();
    if (select == 0)
    {
        return 0;
    }
    return SetRoamerDataToMon(mon, GetRoamer(select));
}

static void InsertRoamerMon(struct Roamer * slot, u8 template)
{
    const struct BattleTowerMon * roamerData = &(gRoamersTable[template]);
    struct Pokemon * mon = &gEnemyParty[0];
    u16 species = roamerData->species;
    u8 level = roamerData->level;
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
    // first get the next free spot
    if (!ROAMER(1)->active)
    {
        InsertRoamerMon(ROAMER(1), mon);
        AssignNewLocationToRoamer(0);
    }
    else if (!ROAMER(2)->active)
    {
        InsertRoamerMon(ROAMER(2), mon);
        AssignNewLocationToRoamer(1);
    }
    else if (!ROAMER(3)->active)
    {
        InsertRoamerMon(ROAMER(3), mon);
        AssignNewLocationToRoamer(2);
    }
    else if (!ROAMER(4)->active)
    {
        InsertRoamerMon(ROAMER(4), mon);
        AssignNewLocationToRoamer(3);
    }
}

