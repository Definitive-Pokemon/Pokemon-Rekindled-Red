#include "pokemon.h"

#define ROAMING_MON(roamerSpecies, roamerLevel) \
[ROAMER_##roamerSpecies] = {                    \
    .species = SPECIES_##roamerSpecies,         \
    .heldItem = 0,                              \
    .moves = {},                                \
    .level = roamerLevel,                       \
    .ppBonuses = 0,                             \
    .hpEV = 0,                                  \
    .attackEV = 0,                              \
    .defenseEV = 0,                             \
    .speedEV = 0,                               \
    .spAttackEV = 0,                            \
    .spDefenseEV = 0,                           \
    .otId = 2,                                  \
    .hpIV = 2,                                  \
    .attackIV = 2,                              \
    .defenseIV = 2,                             \
    .speedIV = 2,                               \
    .spAttackIV = 2,                            \
    .spDefenseIV = 2,                           \
    .gap = 0,                                   \
    .abilityNum = 0,                            \
    .personality = 0,                           \
    .nickname = {},                             \
    .friendship = 0,                            \
    }

#define ROAMING_MON_CUSTOM(roamerSpecies, roamerLevel, roamerHeldItem, roamerMoves) \
[ROAMER_##roamerSpecies] = {                    \
    .species = SPECIES_##roamerSpecies,         \
    .heldItem = roamerHeldItem,                 \
    .moves = roamerMoves,                       \
    .level = roamerLevel,                       \
    .ppBonuses = 0,                             \
    .hpEV = 0,                                  \
    .attackEV = 0,                              \
    .defenseEV = 0,                             \
    .speedEV = 0,                               \
    .spAttackEV = 0,                            \
    .spDefenseEV = 0,                           \
    .otId = 2,                                  \
    .hpIV = 2,                                  \
    .attackIV = 2,                              \
    .defenseIV = 2,                             \
    .speedIV = 2,                               \
    .spAttackIV = 2,                            \
    .spDefenseIV = 2,                           \
    .gap = 0,                                   \
    .abilityNum = 0,                            \
    .personality = 0,                           \
    .nickname = {},                             \
    .friendship = 0,                            \
    }

const struct BattleTowerPokemon gRoamersTable[] = 
{
    [0] = {},
    ROAMING_MON(ENTEI, 65),
    ROAMING_MON(SUICUNE, 65),
    ROAMING_MON(RAIKOU, 65),
    ROAMING_MON(SEVIIAN_AERODACTYL, 50),
};

