AlteringCaveJirachi_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AlteringCaveJirachi_OnResume
	.byte 0

AlteringCaveJirachi_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, AlteringCaveJirachi_EventScript_TryRemoveJirachi
	end
	
AlteringCaveJirachi_EventScript_TryRemoveJirachi::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	setvar VAR_JIRACHI, 2
	releaseall
	return

AlteringCaveJirachi_EventScript_Jirachi::
	lockall
	setwildbattle SPECIES_JIRACHI, 50, ITEM_NONE
	waitse
	playmoncry SPECIES_JIRACHI, 2
	waitmoncry
	delay 50
	waitse
	playse SE_SHINY
	fadescreen FADE_TO_WHITE
	fadescreen FADE_FROM_WHITE
	waitse
	delay 20
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq AlteringCaveJirachi_EventScript_DefeatedJirachi
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq AlteringCaveJirachi_EventScript_RanFromJirachi
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq AlteringCaveJirachi_EventScript_RanFromJirachi
	releaseall
	end

AlteringCaveJirachi_EventScript_DefeatedJirachi::
	setvar VAR_0x8004, SPECIES_JIRACHI
	goto EventScript_JirachiFled
	end

AlteringCaveJirachi_EventScript_RanFromJirachi::
	setvar VAR_0x8004, SPECIES_JIRACHI
	goto EventScript_JirachiFled
	end
	
EventScript_JirachiFled::
	fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox Text_JirachiFled
	warpteleport MAP_ALTERING_CAVE_JIRACHI, 33, 33
    release
    end
	
Text_JirachiFled::
	.string "JIRACHI disappeared into the void…$"
	
Text_JirachiCaught::
	.string "{PLAYER} caught the mythical\n"
	.string "POKéMON JIRACHI.$"