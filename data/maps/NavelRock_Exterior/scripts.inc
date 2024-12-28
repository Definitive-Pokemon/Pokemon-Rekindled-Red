.set LOCALID_MAXIMUS, 1
.set LOCALID_LUGIA, 2
.set LOCALID_POLICELER, 3
.set LOCALID_POLICE_GUY, 4

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
	setobjectxyperm LOCALID_MAXIMUS, 8, 9
	setmetatile 8, 9, METATILE_General_Floory, 0
	setmetatile 9, 9, METATILE_SeviiIslands6_Rocky, 1
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
	setvar VAR_0x8004, 30  @ Num loops
	setvar VAR_0x8005, 35 @ Delay
	applymovement LOCALID_LUGIA, NavelRock_Base_Movement_LugiaGoForth
	applymovement OBJ_EVENT_ID_PLAYER, NavelRock_Base_Movement_LugiaGoForth
	delay 100
	playmoncry SPECIES_LUGIA, 2
	waitmoncry
	delay 25
	applymovement OBJ_EVENT_ID_PLAYER, NavelRock_Base_Movement_Back
	waitmovement 0
	releaseall
	return

NavelRock_Base_Movement_LugiaGoForth::
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_down
	walk_down
	walk_slow_down
	walk_slow_down
	step_end

NavelRock_Base_Movement_Back::
	set_visible
	walk_up
	step_end

NavelRock_Exterior_EventScript_MaximusFinal::
	msgbox NavelRock_Exterior_Text_Returned
	closemessage
	delay 20
	msgbox NavelRock_Exterior_Text_HoldIt
	closemessage
	clearflag FLAG_HIDE_NAVEL_POLICE
	addobject LOCALID_POLICELER
	addobject LOCALID_POLICE_GUY
	applymovement LOCALID_POLICELER, NavelRock_Exterior_Movement_Policeler
	applymovement LOCALID_POLICE_GUY, NavelRock_Exterior_Movement_Police_Guy
	waitmovement 0
	msgbox NavelRock_Exterior_Text_Police
	closemessage
	applymovement LOCALID_MAXIMUS, NavelRock_Base_Movement_Response
	waitmovement 0
	delay 20
	msgbox NavelRock_Exterior_Text_Response
	closemessage
	delay 10
	applymovement LOCALID_POLICELER, NavelRock_Exterior_Movement_Flop
	applymovement LOCALID_POLICE_GUY, NavelRock_Exterior_Movement_Flop
	waitmovement 0
	msgbox NavelRock_Exterior_Text_Nu
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NavelRock_Exterior_Movement_Move
	waitmovement 0
	applymovement LOCALID_POLICELER, NavelRock_Exterior_Movement_Take
	delay 20
	applymovement LOCALID_MAXIMUS, NavelRock_Exterior_Movement_Go
	delay 20
	applymovement LOCALID_POLICE_GUY, NavelRock_Exterior_Movement_Take2
	waitmovement 0
	msgbox NavelRock_Exterior_Text_Aap
	closemessage
	delay 50
	releaseall
	return

NavelRock_Exterior_Text_Police::
	.string "You're coming with us, MAXIMUS.\p"
	.string "The KANTO POLICE FORCE has heard\n"
	.string "all about your crimes against\l"
	.string "KANTO's legendary POKéMON.$"

NavelRock_Exterior_Text_Response::
	.string "Mother of…\n"
	.string "Who do you think you are,\p"
	.string "you jumped-up piece of…\n"
	.string "third-rate Columbo!$"

NavelRock_Exterior_Text_Nu::
	.string "Sir, now you've gone too far.\p"
	.string "We have no other choice\n"
	.string "but to arrest you.$"

NavelRock_Exterior_Text_Aap::
	.string "Mother of…\n"
	.string "What a monkey land this is!$"

NavelRock_Exterior_Movement_Policeler::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

NavelRock_Exterior_Movement_Police_Guy::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_left
	step_end

NavelRock_Base_Movement_Response::
	walk_in_place_down
	delay_16
	walk_in_place_right
	step_end

NavelRock_Exterior_Movement_Flop::
	walk_in_place_down
	walk_in_place_right
	walk_in_place_up
	walk_in_place_left
	delay_16
	face_original_direction
	step_end

NavelRock_Exterior_Movement_Move::
	walk_right
	walk_down
	walk_right
	walk_in_place_left
	step_end

NavelRock_Exterior_Movement_Take::
	walk_up
	walk_in_place_up
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_in_place_down
	step_end

NavelRock_Exterior_Movement_Go::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_in_place_down
	step_end

NavelRock_Exterior_Movement_Take2::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	step_end
	
NavelRock_Exterior_Text_Returned::
	.string "So, you've used LUGIA\n"
	.string "to escape from a life\l"
	.string "of captivity.\p"
	.string "Isn't that great for you!\p"
	.string "I guess we'll be sharing\n"
	.string "a spot on the SEAGALLOP!\p"
	.string "My WARP DEVICE broke thanks to\n"
	.string "the thunderstorm LUGIA keeps\l"
	.string "around itself all the time.$"

NavelRock_Exterior_Text_HoldIt::
	.string "Hold it right there!\p"
	.string "The only thing you'll\n"
	.string "be sharing is a prison cell!$"

NavelRock_Exterior_EventScript_Maximus::
	lock
	faceplayer
	goto_if_eq VAR_BLOCK, 3, NavelRock_Exterior_EventScript_MaximusFinal
	goto_if_set FLAG_ELM_NAVEL, NavelRock_Exterior_EventScript_AfterMaximus
	trainerbattle_single TRAINER_COLLECTOR_MAXIMUS, NavelRock_Exterior_Text_Intro, NavelRock_Exterior_Text_Defeat, NavelRock_Exterior_EventScript_Defeated, NO_MUSIC
	release
	end

NavelRock_Base_Movement_Invis::
	set_invisible
	step_end

NavelRock_Exterior_Text_Intro::
	.string "How in blazes did you manage\n"
	.string "to find this island?\p"
	.string "You really are beginning\n"
	.string "to bother me, you know that?\p"
	.string "You want to stop me from\n"
	.string "obtaining LUGIA, right?\p"
	.string "Not a chance!\p"
	.string "I told you that I do not\n"
	.string "do stuff like battling.\p"
	.string "That's not entirely true.\n"
	.string "I have battled many times\l"
	.string "in my life…\p"
	.string "You do not want me to,\n"
	.string "but I guess it's time\l"
	.string "to show you your place!$"

NavelRock_Exterior_Text_Defeat::
	.string "You little… !$"

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
	.string "You win.\n"
	.string "Congratulations.\p"
	.string "Without my POKéMON team,\n"
	.string "I cannot even catch LUGIA.\p"
	.string "Seems you've achieved\n"
	.string "your goal, TRAINER.\p"
	.string "You can have LUGIA.\n"
	.string "I am stepping aside.\p"
	.string "Maybe I have been too obsessed\n"
	.string "with collecting POKéMON for\l"
	.string "a long time…$"

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
	walk_in_place_up
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