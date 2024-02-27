Stone_Tomb_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Stone_Tomb_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Stone_Tomb_OnResume
	.byte 0

Stone_Tomb_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, Stone_Tomb_EventScript_TryRemoveRegirock
	end

Stone_Tomb_EventScript_TryRemoveRegirock::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return

Stone_Tomb_OnTransition::
	call_if_set FLAG_FOUGHT_REGIROCK, Stone_Tomb_EventScript_HideRegirock
	call_if_unset FLAG_FOUGHT_REGIROCK, Stone_Tomb_EventScript_TryShowRegirock
	end

Stone_Tomb_EventScript_TryShowRegirock::
	goto_if_set FLAG_REGIROCK_FLED, EventScript_Return
	clearflag FLAG_HIDE_REGIROCK
	return

Stone_Tomb_EventScript_HideRegirock::
	setflag FLAG_HIDE_REGIROCK
	return

Stone_Tomb_EventScript_Regirock::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_REGIROCK, 60, ITEM_NONE
	waitse
	playmoncry SPECIES_REGIROCK, CRY_MODE_ENCOUNTER
	msgbox Stone_Tomb_Text_Regirock
	waitmessage
	waitmoncry
	delay 10
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Stone_Tomb_EventScript_DefeatedRegirock
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Stone_Tomb_EventScript_RanFromRegirock
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Stone_Tomb_EventScript_RanFromRegirock
	setflag FLAG_FOUGHT_REGIROCK
	release
	end

Stone_Tomb_EventScript_DefeatedRegirock::
	setflag FLAG_REGIROCK_FLED
	setvar VAR_0x8004, SPECIES_REGIROCK
	goto Stone_Tomb_EventScript_RegirockFled
	end

Stone_Tomb_EventScript_RanFromRegirock::
	setvar VAR_0x8004, SPECIES_REGIROCK
	goto Stone_Tomb_EventScript_RegirockFled
	end
	
Stone_Tomb_EventScript_RegirockFled::
    fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    msgbox Stone_Tomb_Text_RegirockFled
    release
    end