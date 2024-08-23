.set LOCALID_RAIKOU, 1

CinnabarCavern_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CinnabarCavern_OnResume
	.byte 0

CinnabarCavern_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, CinnabarCavern_EventScript_TryRemoveRaikou
	end

CinnabarCavern_EventScript_TryRemoveRaikou::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return

CinnabarCavern_OnTransition::
	call_if_set FLAG_FOUGHT_RAIKOU, CinnabarCavern_EventScript_HideRaikou
	call_if_unset FLAG_FOUGHT_RAIKOU, CinnabarCavern_EventScript_TryShowRaikou
	end

CinnabarCavern_EventScript_TryShowRaikou::
	goto_if_set FLAG_RAIKOU_FLEW_AWAY, EventScript_Return
	clearflag FLAG_HIDE_RAIKOU
	return

CinnabarCavern_EventScript_HideRaikou::
	setflag FLAG_HIDE_RAIKOU
	return

CinnabarCavern_EventScript_Raikou::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_RAIKOU, 50, ITEM_NONE
	waitse
	playmoncry SPECIES_RAIKOU, 2
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
	goto_if_eq CinnabarCavern_EventScript_DefeatedRaikou
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq CinnabarCavern_EventScript_RanFromRaikou
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq CinnabarCavern_EventScript_RanFromRaikou
	setflag FLAG_FOUGHT_RAIKOU
	release
	end

CinnabarCavern_EventScript_DefeatedRaikou::
	setflag FLAG_RAIKOU_FLED
	setvar VAR_0x8004, SPECIES_RAIKOU
	goto EventScript_RaikouFled
	end

CinnabarCavern_EventScript_RanFromRaikou::
	setvar VAR_0x8004, SPECIES_RAIKOU
	goto EventScript_RaikouFled
	end
	
CinnabarCavern_EventScript_RaikouFled::
	fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox Text_RaikouFled
    release
    end
	
CinnabarCavern_Text_RaikouFled::
	.string "RAIKOU fled outside!$"
	

CinnabarCavern_EventScript_Computer::
	msgbox CinnabarCavern_Text_Message, MSGBOX_SIGN
	end
	
CinnabarCavern_Text_Message::
	.string "There's an e-mail message here.\p"
    .string "…\p"
    .string "Finally!\n"
    .string "The ultimate TRAINERS of the\l"
    .string "POKéMON LEAGUE are ready to\l"
    .string "take on all comers!\p"
    .string "Bring your best POKéMON and see\n"
    .string "how you rate as a TRAINER!\p"
    .string "POKéMON LEAGUE HQ\n"
    .string "INDIGO PLATEAU\p"
    .string "PROF. OAK, please visit us!\n"
    .string "…$"
	
