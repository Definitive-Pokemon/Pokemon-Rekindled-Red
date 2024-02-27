Icy_Tomb_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Icy_Tomb_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Icy_Tomb_OnResume
	.byte 0

Icy_Tomb_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, Icy_Tomb_EventScript_TryRemoveRegice
	end

Icy_Tomb_EventScript_TryRemoveRegice::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return

Icy_Tomb_OnTransition::
	call_if_set FLAG_FOUGHT_REGICE, Icy_Tomb_EventScript_HideRegice
	call_if_unset FLAG_FOUGHT_REGICE, Icy_Tomb_EventScript_TryShowRegice
	end

Icy_Tomb_EventScript_TryShowRegice::
	goto_if_set FLAG_REGICE_FLED, EventScript_Return
	clearflag FLAG_HIDE_REGICE
	return

Icy_Tomb_EventScript_HideRegice::
	setflag FLAG_HIDE_REGICE
	return

Icy_Tomb_EventScript_Regice::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_REGICE, 60, ITEM_NONE
	waitse
	playmoncry SPECIES_REGICE, CRY_MODE_ENCOUNTER
	msgbox Icy_Tomb_Text_Regice
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
	goto_if_eq Icy_Tomb_EventScript_DefeatedRegice
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Icy_Tomb_EventScript_RanFromRegice
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Icy_Tomb_EventScript_RanFromRegice
	setflag FLAG_FOUGHT_REGICE
	release
	end

Icy_Tomb_EventScript_DefeatedRegice::
	setflag FLAG_REGICE_FLED
	setvar VAR_0x8004, SPECIES_REGICE
	goto Icy_Tomb_EventScript_RegiceFled
	end

Icy_Tomb_EventScript_RanFromRegice::
	setvar VAR_0x8004, SPECIES_REGICE
	goto Icy_Tomb_EventScript_RegiceFled
	end
	
Icy_Tomb_EventScript_RegiceFled::
    fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    msgbox Icy_Tomb_Text_RegiceFled
    release
    end