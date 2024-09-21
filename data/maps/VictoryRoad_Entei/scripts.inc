.set LOCALID_ENTEI, 1

VictoryRoad_Entei_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, VictoryRoad_Entei_OnResume
	.byte 0

VictoryRoad_Entei_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, VictoryRoad_Entei_EventScript_TryRemoveEntei
	end
	
VictoryRoad_Entei_EventScript_TryRemoveEntei::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return

VictoryRoad_Entei_OnTransition::
	call_if_set FLAG_FOUGHT_ENTEI, VictoryRoad_Entei_EventScript_HideEntei
	call_if_unset FLAG_FOUGHT_ENTEI, VictoryRoad_Entei_EventScript_TryShowEntei
	end

VictoryRoad_Entei_EventScript_TryShowEntei::
	goto_if_set FLAG_ENTEI_FLED, EventScript_Return
	clearflag FLAG_HIDE_ENTEI_ROAM
	return

VictoryRoad_Entei_EventScript_HideEntei::
	setflag FLAG_HIDE_ENTEI_ROAM
	return

VictoryRoad_Entei_EventScript_Entei::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_ENTEI, 60, ITEM_NONE
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
	goto_if_eq VictoryRoad_Entei_EventScript_DefeatedEntei
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq VictoryRoad_Entei_EventScript_RanFromEntei
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq VictoryRoad_Entei_EventScript_RanFromEntei
	setflag FLAG_FOUGHT_ENTEI
	release
	end

VictoryRoad_Entei_EventScript_DefeatedEntei::
	setflag FLAG_ENTEI_FLED
	setvar VAR_0x8004, SPECIES_ENTEI
	goto EventScript_EnteiFled
	end

VictoryRoad_Entei_EventScript_RanFromEntei::
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