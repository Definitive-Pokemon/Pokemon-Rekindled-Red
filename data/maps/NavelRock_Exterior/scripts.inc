.set LOCALID_MAXIMUS, 1
.set LOCALID_LUGIA, 2

NavelRock_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NavelRock_Exterior_OnFrame
	.byte 0

NavelRock_Exterior_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_NAVEL_ROCK_EXTERIOR
	call_if_eq VAR_BLOCK, 2, NavelRock_Exterior_EventScript_Location
	end

NavelRock_Exterior_OnFrame::
	map_script_2 VAR_BLOCK, 2, NavelRock_Exterior_EventScript_SetUpFinale
	.2byte 0

NavelRock_Exterior_EventScript_Location::
	setobjectxyperm LOCALID_MAXIMUS, 7, 9
	setmetatile 8, 9, METATILE_General_Floory, 0
	setmetatile 9, 9, METATILE_General_Rocky, 1
	special DrawWholeMapView
	return
	

NavelRock_Exterior_EventScript_SetUpFinale::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, NavelRock_Base_Movement_Invis
	setvar VAR_BLOCK, 3
	delay 100
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	setmetatile 9, 7, METATILE_SeviiIslands6_Unblock, 0
	special DrawWholeMapView
	delay 30
	clearflag FLAG_LUGIA_FLEE
	addobject LOCALID_LUGIA
	setvar VAR_0x8004, 2  @ Num loops
	setvar VAR_0x8005, 35 @ Delay
	applymovement LOCALID_LUGIA, NavelRock_Base_Movement_LugiaInvite
	waitmovement 0
	playmoncry SPECIES_LUGIA, 2
	waitmoncry
	delay 80
	applymovement LOCALID_LUGIA, NavelRock_Base_Movement_LugiaGoForth
	applymovement OBJ_EVENT_ID_PLAYER, NavelRock_Base_Movement_LugiaGoForth
	delay 100
	warp MAP_MT_SILVER, 19, 19
	return

NavelRock_Base_Movement_LugiaGoForth::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
	

NavelRock_Exterior_EventScript_Maximus::
	lock
	faceplayer
	goto_if_set FLAG_ELM_NAVEL, NavelRock_Exterior_EventScript_AfterMaximus
	trainerbattle_single TRAINER_COLLECTOR_MAXIMUS, NavelRock_Exterior_Text_Intro, NavelRock_Exterior_Text_Defeat, NavelRock_Exterior_EventScript_Defeated, NO_MUSIC
	release
	end

NavelRock_Base_Movement_Invis::
	set_invisible
	step_end

NavelRock_Exterior_Text_Intro::
	.string "I am Maxi$"

NavelRock_Exterior_Text_Defeat::
	.string "No.$"

NavelRock_Exterior_EventScript_Defeated::
	msgbox NavelRock_Exterior_Text_Done, MSGBOX_NPC
	closemessage
	applymovement LOCALID_MAXIMUS, NavelRock_Exterior_Movement_Aside1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, NavelRock_Exterior_Movement_AsidePlay
	waitmovement 0
	applymovement LOCALID_MAXIMUS, NavelRock_Exterior_Movement_Aside2
	waitmovement 0
	msgbox NavelRock_Exterior_Text_Asode, MSGBOX_NPC
	closemessage
	delay 20
	setflag FLAG_ELM_NAVEL
	release
	end

NavelRock_Exterior_Text_Done::
	.string "I'm done. I'm stepping aside.$"

NavelRock_Exterior_Movement_Aside1::
	walk_in_place_down
	step_end

NavelRock_Exterior_Movement_AsidePlay::
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

NavelRock_Exterior_Movement_Aside2::
	walk_down
	walk_left
	walk_left
	walk_up
	walk_in_place_right
	step_end

NavelRock_Exterior_Text_Asode::
	.string "I'm now aside. Move along.$"

NavelRock_Exterior_EventScript_AfterMaximus::
	msgbox NavelRock_Exterior_Text_After
	release
	end

NavelRock_Exterior_Text_After::
	.string "Oh yeah. Fuck you.$"

NavelRock_Exterior_EventScript_Sign::
	msgbox NavelRock_Exterior_Text_Sign, MSGBOX_SIGN
	end

NavelRock_Exterior_Text_Sign::
	.string "DANGER! \n"
	.string "Enter at your own risk $"