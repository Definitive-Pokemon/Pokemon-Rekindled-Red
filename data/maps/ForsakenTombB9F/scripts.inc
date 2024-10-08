.set LOCALID_REGIGIGAS, 1

ForsakenTombB9F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ForsakenTombB9F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ForsakenTombB9F_OnResume
	.byte 0

ForsakenTombB9F_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, ForsakenTombB9F_EventScript_TryRemoveRegigigas
	end

ForsakenTombB9F_EventScript_TryRemoveRegigigas::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return

ForsakenTombB9F_OnTransition::
	call_if_set FLAG_FOUGHT_REGIGIGAS, ForsakenTombB9F_EventScript_HideRegigigas
	call_if_unset FLAG_FOUGHT_REGIGIGAS, ForsakenTombB9F_EventScript_TryShowRegigigas
	end

ForsakenTombB9F_EventScript_TryShowRegigigas::
	goto_if_set FLAG_REGIGIGAS_GONE, EventScript_Return
	clearflag FLAG_HIDE_REGIGIGAS
	return

ForsakenTombB9F_EventScript_HideRegigigas::
	setflag FLAG_HIDE_REGIGIGAS
	return

ForsakenTombB9F_EventScript_StopChecking::
	end

ForsakenTombB9F_EventScript_Regigigas::
	lock
	faceplayer
	msgbox ForsakenTombB9F_Text_Engraving
	closemessage
	setvar VAR_0x8004, SPECIES_REGIROCK
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_ne VAR_RESULT, TRUE, ForsakenTombB9F_EventScript_StopChecking
	setvar VAR_0x8004, SPECIES_REGICE
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_ne VAR_RESULT, TRUE, ForsakenTombB9F_EventScript_StopChecking
	setvar VAR_0x8004, SPECIES_REGISTEEL
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_ne VAR_RESULT, TRUE, ForsakenTombB9F_EventScript_StopChecking
	delay 20
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 10
	setvar VAR_0x8007, 3
	special ShakeScreen
	delay 60
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 12
	setvar VAR_0x8007, 2
	special ShakeScreen
	delay 60
	setwildbattle SPECIES_REGIGIGAS, 80, ITEM_NONE
	waitse
	playmoncry SPECIES_REGIGIGAS, 2
	message ForsakenTombB9F_Text_SomethingHappens
	waitmessage
	waitmoncry
	delay 10
	waitbuttonpress
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ForsakenTombB9F_EventScript_DefeatedRegigigas
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq ForsakenTombB9F_EventScript_RanFromRegigigas
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq ForsakenTombB9F_EventScript_RanFromRegigigas
	setflag FLAG_FOUGHT_REGIGIGAS
	release
	end

ForsakenTombB9F_EventScript_DefeatedRegigigas::
	setflag FLAG_REGIGIGAS_GONE
	setvar VAR_0x8004, SPECIES_REGIGIGAS
	goto ForsakenTombB9F_EventScript_RegigigasGone
	end


ForsakenTombB9F_EventScript_RanFromRegigigas::
	setvar VAR_0x8004, SPECIES_REGIGIGAS
	goto ForsakenTombB9F_EventScript_RegigigasGone
	end

ForsakenTombB9F_EventScript_RegigigasGone::
	fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox Text_RegigigasGone
    release
    end

Text_RegigigasGone::
	.string "REGIGIGAS ran away!"

ForsakenTombB9F_Text_Engraving::
	.string "It's a statue of a POKéMON.\n"
	.string "It seems to exude power.\p"
	.string "{PLAYER} read the engraved\n"
	.string "writing…\p"
	.string "A body of rock.\p"
	.string "A body of ice.\p"
	.string "A body of steel.\p"
	.string "When gathers the three POKéMON,\n"
	.string "the king shall appear.$"

ForsakenTombB9F_Text_SomethingHappens::
	.string "…Zut zutt!$"