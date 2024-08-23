.set LOCALID_MOLTRES_MASTER, 14
.set TRAINER, VAR_0x8009
.set LOCALID_BOULDER1, 11
.set LOCALID_BOULDER2, 12

VictoryRoad_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_2F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_2F_MapScript_SetMasterTrainerMovementTypes
	map_script MAP_SCRIPT_ON_RESUME, VictoryRoad_2F_OnResume
	.byte 0

VictoryRoad_2F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_MOLTRES
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, VictoryRoad_2F_MapScript_MoltresMasterMovementType
	end

VictoryRoad_2F_MapScript_MoltresMasterMovementType::
	setobjectmovementtype LOCALID_MOLTRES_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

VictoryRoad_2F_OnLoad::
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_SetRockBarrier1
	call_if_eq VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_MoveSwitch1Boulder
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_SetRockBarrier2
	call_if_eq VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_MoveSwitch2Boulder
	end

VictoryRoad_2F_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, VictoryRoad_2F_EventScript_TryRemoveEntei
	end

VictoryRoad_2F_EventScript_TryRemoveEntei::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return

VictoryRoad_2F_OnTransition::
	call_if_set FLAG_FOUGHT_ENTEI, VictoryRoad_2F_EventScript_HideEntei
	call_if_unset FLAG_FOUGHT_ENTEI, VictoryRoad_2F_EventScript_TryShowEntei
	end

VictoryRoad_2F_EventScript_TryShowEntei::
	goto_if_set FLAG_ENTEI_FLED, EventScript_Return
	clearflag FLAG_HIDE_ENTEI_ROAM
	return

VictoryRoad_2F_EventScript_HideEntei::
	setflag FLAG_HIDE_ENTEI_ROAM
	return

VictoryRoad_2F_EventScript_Entei::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_ENTEI, 50, ITEM_NONE
	waitse
	playmoncry SPECIES_ENTEI, 2
	fadescreen FADE_TO_WHITE
	fadescreen FADE_FROM_WHITE
	waitmoncry
	delay 10
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq VictoryRoad_2F_EventScript_DefeatedEntei
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq VictoryRoad_2F_EventScript_RanFromEntei
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq VictoryRoad_2F_EventScript_RanFromEntei
	setflag FLAG_FOUGHT_ENTEI
	release
	end

VictoryRoad_2F_EventScript_DefeatedEntei::
	setflag FLAG_ENTEI_FLED
	setvar VAR_0x8004, SPECIES_ENTEI
	goto EventScript_EnteiFled
	end

VictoryRoad_2F_EventScript_RanFromEntei::
	setvar VAR_0x8004, SPECIES_ENTEI
	goto EventScript_EnteiFled
	end
	
EventScript_EnteiFled::
	fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox Text_EnteiFled
    release
    end
	
Text_EnteiFled::
	.string "ENTEI fled the scene!$"
	
VictoryRoad_2F_EventScript_MoveSwitch1Boulder::
	setobjectxyperm LOCALID_BOULDER1, 2, 19
	return

VictoryRoad_2F_EventScript_MoveSwitch2Boulder::
	setobjectxyperm LOCALID_BOULDER2, 14, 19
	return

VictoryRoad_2F_EventScript_SetRockBarrier1::
	setmetatile 13, 10, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 13, 11, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_2F_EventScript_SetRockBarrier2::
	setmetatile 33, 16, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 33, 17, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_2F_EventScript_FloorSwitch1::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed
	setmetatile 13, 10, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 13, 11, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_BOULDER1
	setvar VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed::
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch2::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed
	setmetatile 33, 16, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 33, 17, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_BOULDER2
	setvar VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed::
	releaseall
	end

VictoryRoad_2F_EventScript_Dawson::
	trainerbattle_single TRAINER_POKEMANIAC_DAWSON, VictoryRoad_2F_Text_DawsonIntro, VictoryRoad_2F_Text_DawsonDefeat
	msgbox VictoryRoad_2F_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Daisuke::
	trainerbattle_single TRAINER_BLACK_BELT_DAISUKE, VictoryRoad_2F_Text_DaisukeIntro, VictoryRoad_2F_Text_DaisukeDefeat
	msgbox VictoryRoad_2F_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Nelson::
	trainerbattle_single TRAINER_JUGGLER_NELSON, VictoryRoad_2F_Text_NelsonIntro, VictoryRoad_2F_Text_NelsonDefeat
	msgbox VictoryRoad_2F_Text_NelsonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Gregory::
	trainerbattle_single TRAINER_JUGGLER_GREGORY, VictoryRoad_2F_Text_GregoryIntro, VictoryRoad_2F_Text_GregoryDefeat
	msgbox VictoryRoad_2F_Text_GregoryPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Vincent::
	trainerbattle_single TRAINER_TAMER_VINCENT, VictoryRoad_2F_Text_VincentIntro, VictoryRoad_2F_Text_VincentDefeat
	msgbox VictoryRoad_2F_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end
