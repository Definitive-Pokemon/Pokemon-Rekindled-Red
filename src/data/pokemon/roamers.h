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
{                                               \
    species = roamerSpecies,                    \
    heldItem = roamerHeldItem,                  \
    moves[MAX_MON_MOVES] = roamerMoves,         \
    level = roamerLevel,                        \
    ppBonuses = 0,                              \
    hpEV = 0,                                   \
    attackEV = 0,                               \
    defenseEV = 0,                              \
    speedEV = 0,                                \
    spAttackEV = 0,                             \
    spDefenseEV = 0,                            \
    otId = OT_ID_RANDOM_NO_SHINY,               \
    hpIV:5 = 2,                                 \
    attackIV:5 = 2,                             \
    defenseIV:5 = 2,                            \
    speedIV:5 = 2,                              \
    spAttackIV:5 = 2,                           \
    spDefenseIV:5 = 2,                          \
    gap:1 = 0,                                  \
    abilityNum:1 = 0,                           \
    personality = 0,                            \
    nickname[POKEMON_NAME_LENGTH + 1] = {},     \
    friendship = 0,                             \
    }

const struct BattleTowerPokemon gRoamersTable[] = 
{
    [0] = {},
    ROAMING_MON(ENTEI, 65),
};

