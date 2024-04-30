#ifndef GUARD_ROAMER_H
#define GUARD_ROAMER_H

#include "global.h"

void ClearRoamerData(void);
void StartRoaming(void);
void UpdateLocationHistoryForRoamer(void);
void RoamerMoveToOtherLocationSet(void);
void RoamerMove(void);
u8 TryInitializeRoamerEncounter(struct Pokemon *mon);
void UpdateRoamerHPStatus(struct Pokemon *mon);
void SetRoamerInactive(u16 roamerSpecies);
void GetRoamerLocation(u8 *mapGroup, u8 *mapNum);//unused
u16 GetRoamerLocationMapSectionId(u16 roamerSpecies);

#endif // GUARD_ROAMER_H
