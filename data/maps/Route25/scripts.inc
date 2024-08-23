.set LOCALID_STARMIE_MASTER, 14
.set LOCALID_SUICUNE, 15
.set TRAINER, VAR_0x8009

Route25_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_MapScript_SetMasterTrainerMovementTypes
	map_script MAP_SCRIPT_ON_RESUME, Route25_OnResume
	.byte 0

Route25_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_STARMIE
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route25_MapScript_StarmieMasterMovementType
	end

Route25_MapScript_StarmieMasterMovementType::
	setobjectmovementtype LOCALID_STARMIE_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route25_EventScript_SeaCottageSign::
	msgbox Route25_Text_SeaCottageSign, MSGBOX_SIGN
	end

Route25_EventScript_Man::
	msgbox Route25_Text_AreYouHereAlone, MSGBOX_NPC
	end

Route25_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, Route25_EventScript_TryRemoveSuicune
	end

Route25_EventScript_TryRemoveSuicune::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return

Route25_OnTransition::
	call_if_set FLAG_FOUGHT_SUICUNE, Route25_EventScript_HideSuicune
	call_if_unset FLAG_FOUGHT_SUICUNE, Route25_EventScript_TryShowSuicune
	end

Route25_EventScript_TryShowSuicune::
	goto_if_set FLAG_SUICUNE_FLEW_AWAY, EventScript_Return
	clearflag FLAG_HIDE_SUICUNE
	return

Route25_EventScript_HideSuicune::
	setflag FLAG_HIDE_SUICUNE
	return

Route25_EventScript_Suicune::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_SUICUNE, 50, ITEM_NONE
	waitse
	playmoncry SPECIES_SUICUNE, 2
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
	goto_if_eq Route25_EventScript_DefeatedSuicune
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Route25_EventScript_RanFromSuicune
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Route25_EventScript_RanFromSuicune
	setflag FLAG_FOUGHT_SUICUNE
	release
	end

Route25_EventScript_DefeatedSuicune::
	setflag FLAG_SUICUNE_FLED
	setvar VAR_0x8004, SPECIES_SUICUNE
	goto EventScript_SuicuneFled
	end

Route25_EventScript_RanFromSuicune::
	setvar VAR_0x8004, SPECIES_SUICUNE
	goto EventScript_SuicuneFled
	end
	
Route25_EventScript_SuicuneFled::
	fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox Text_SuicuneFled
    release
    end
	
Route25_Text_SuicuneFled::
	.string "SUICUNE fled to the north!$"