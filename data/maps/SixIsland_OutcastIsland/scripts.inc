.equ LOCALID_OLD_MAN, 8
.equ LOCALID_LAPRAS, 9

SixIsland_OutcastIsland_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SixIsland_OutcastIsland_OnLoad
	.byte 0
	
SixIsland_OutcastIsland_OnLoad::
	goto_if_set FLAG_WORLD_MAP_SIX_ISLAND_ALTERING_CAVE, SixIsland_OutcastIsland_EventScript_MysteryManCheck
	end
	
SixIsland_OutcastIsland_EventScript_MysteryManCheck::
	goto_if_unset FLAG_MYSTERY_MAN_GONE, SixIsland_OutcastIsland_EventScript_MysteryMan
	end
	
SixIsland_OutcastIsland_EventScript_MysteryMan::
	lockall
	applymovement SixIsland_OutcastIsland_Movement_OldManUp
	waitmovement 0
	msgbox SixIsland_OutcastIsland_Text_OldMan MSGBOX_NPC
	applymovement SixIsland_OutcastIsland_Movement_OldManGo
	waitmovement 0
	fadescreen FADE_TO_WHITE
	playse SE_PIN
	waitse
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	waitse
	addobject LOCALID_LAPRAS
	clearflag FLAG_HIDE_LAPRAS_OLD
	fadescreen FADE_FROM_WHITE
	applymovement SixIsland_OutcastIsland_Movement_OldManSurf
	applymovement SixIsland_OutcastIsland_Movement_LaprasManSurf
	waitmovement 0
	removeobject LOCALID_OLD_MAN
	removeobject LOCALID_LAPRAS
	setflag FLAG_MYSTERY_MAN_GONE
	setflag FLAG_HIDE_LAPRAS_OLD
	releaseall
	end

SixIsland_OutcastIsland_EventScript_Rocket::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_46, SixIsland_OutcastIsland_Text_RocketIntro, SixIsland_OutcastIsland_Text_RocketDefeat
	msgbox SixIsland_OutcastIsland_Text_RocketPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_OutcastIsland_Movement_OldManUp::
	walk_up
	step_end

SixIsland_OutcastIsland_Movement_OldManGo::
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
	
SixIsland_OutcastIsland_Movement_OldManSurf::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
	
SixIsland_OutcastIsland_Movement_LaprasSurf::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end