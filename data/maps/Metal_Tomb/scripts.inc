Metal_Tomb_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Metal_Tomb_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Metal_Tomb_OnResume
	.byte 0

Metal_Tomb_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, Metal_Tomb_EventScript_TryRemoveRegisteel
	end

Metal_Tomb_EventScript_TryRemoveRegisteel::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return

Metal_Tomb_OnTransition::
	call_if_set FLAG_FOUGHT_REGISTEEL, Metal_Tomb_EventScript_HideRegisteel
	call_if_unset FLAG_FOUGHT_REGISTEEL, Metal_Tomb_EventScript_TryShowRegisteel
	end

Metal_Tomb_EventScript_TryShowRegisteel::
	goto_if_set FLAG_REGISTEEL_FLED, EventScript_Return
	clearflag FLAG_HIDE_REGISTEEL
	return

Metal_Tomb_EventScript_HideRegisteel::
	setflag FLAG_HIDE_REGISTEEL
	return

Metal_Tomb_EventScript_Registeel::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_REGISTEEL, 60, ITEM_NONE
	waitse
	playmoncry SPECIES_REGISTEEL, CRY_MODE_ENCOUNTER
	msgbox Metal_Tomb_Text_Registeel
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
	goto_if_eq Metal_Tomb_EventScript_DefeatedRegisteel
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Metal_Tomb_EventScript_RanFromRegisteel
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Metal_Tomb_EventScript_RanFromRegisteel
	setflag FLAG_FOUGHT_REGISTEEL
	release
	end

Metal_Tomb_EventScript_DefeatedRegisteel::
	setflag FLAG_REGISTEEL_FLED
	setvar VAR_0x8004, SPECIES_REGISTEEL
	goto Metal_Tomb_EventScript_RegisteelFled
	end

Metal_Tomb_EventScript_RanFromRegisteel::
	setvar VAR_0x8004, SPECIES_REGISTEEL
	goto Metal_Tomb_EventScript_RegisteelFled
	end
	
Metal_Tomb_EventScript_RegisteelFled::
    fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    msgbox Metal_Tomb_Text_RegisteelFled
    release
    end