.equ LOCALID_OLD_MAN, 8
.equ LOCALID_LAPRAS, 9

SixIsland_OutcastIsland_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SixIsland_OutcastIsland_OnFrame
	.byte 0
	
SixIsland_OutcastIsland_OnFrame::
	map_script_2 VAR_TEMP_0, 0, SixIsland_OutcastIsland_EventScript_MysteryManCheck
	.2byte 0

SixIsland_OutcastIsland_EventScript_MysteryManCheck::
	setvar VAR_TEMP_0, 1
	goto_if_unset FLAG_MYSTERY_MAN_GONE, SixIsland_OutcastIsland_EventScript_MysteryMan
	end
	
SixIsland_OutcastIsland_EventScript_MysteryMan::
	lockall
	applymovement LOCALID_OLD_MAN SixIsland_OutcastIsland_Movement_OldManUp
	waitmovement 0
	textcolor 0
	msgbox SixIsland_OutcastIsland_Text_OldMan MSGBOX_NPC
	applymovement LOCALID_OLD_MAN SixIsland_OutcastIsland_Movement_OldManGo
	waitmovement 0
	fadescreen FADE_TO_WHITE
	playse SE_BALL_OPEN
	waitse
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	waitse
	addobject LOCALID_LAPRAS
	clearflag FLAG_HIDE_LAPRAS_OLD
	delay 20
	fadescreen FADE_FROM_WHITE
	delay 20
	applymovement LOCALID_OLD_MAN SixIsland_OutcastIsland_Movement_OldManSurf
	applymovement LOCALID_LAPRAS SixIsland_OutcastIsland_Movement_LaprasSurf
	waitmovement 0
	removeobject LOCALID_OLD_MAN
	removeobject LOCALID_LAPRAS
	setflag FLAG_HIDE_LAPRAS_OLD
	setflag FLAG_MYSTERY_MAN_GONE
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
	
SixIsland_OutcastIsland_Text_OldMan::
	.string "You…\p"
	.string "You seem like a well-traveled\n"
	.string "young man.\p"
	.string "This cave…\p"
	.string "It has absolutely nothing\n"
	.string "special in it.\p"
	.string "And yet…\p"
	.string "It seems as if it is hiding\n"
	.string "things beyond comprehension.\p"
	.string "I am too old to discover the secret\n"
	.string "of ALTERING CAVE.\p"
	.string "Oh well. I should be going…$"