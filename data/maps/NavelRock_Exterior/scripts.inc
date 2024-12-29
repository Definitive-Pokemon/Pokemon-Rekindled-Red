.set LOCALID_MAXIMUS, 1
.set LOCALID_LUGIA, 2
.set LOCALID_POLICELER, 3
.set LOCALID_POLICE_GUY, 4

NavelRock_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NavelRock_Exterior_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, NavelRock_Exterior_OnLoad
	.byte 0

NavelRock_Exterior_OnLoad::
	call_if_eq VAR_BLOCK, 3, NavelRock_Exterior_Block

NavelRock_Exterior_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_NAVEL_ROCK_EXTERIOR
	call_if_eq VAR_BLOCK, 1, NavelRock_Exterior_EventScript_Moved
	call_if_eq VAR_BLOCK, 3, NavelRock_Exterior_EventScript_Location
	call_if_eq VAR_BLOCK, 4, NavelRock_Exterior_EventScript_Music
	end

NavelRock_Exterior_OnFrame::
	map_script_2 VAR_BLOCK, 3, NavelRock_Exterior_EventScript_SetUpFinale
	.2byte 0

NavelRock_Exterior_EventScript_Moved::
	setobjectxyperm LOCALID_MAXIMUS, 8, 10
	return

NavelRock_Exterior_EventScript_Music::
	playbgm MUS_SEVII_ROUTE, 0
	setweather 2
	doweather
	return

NavelRock_Exterior_EventScript_Location::
	setobjectxyperm LOCALID_MAXIMUS, 8, 9
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_NAVEL_ROCK_EXTERIOR
	return

NavelRock_Exterior_Block::
	setmetatile 8, 9, METATILE_General_Floory, 0
	setmetatile 9, 9, METATILE_SeviiIslands6_Rocky, 1
	special DrawWholeMapView
	return

NavelRock_Exterior_EventScript_SetUpFinale::
	lockall
	setvar VAR_BLOCK, 4
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
	setweather 2
	doweather
	playmoncry SPECIES_LUGIA, 2
	waitmoncry
	waitmovement 0
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_NAVEL_ROCK_EXTERIOR
	applymovement OBJ_EVENT_ID_PLAYER, NavelRock_Base_Movement_Back
	waitmovement 0
	delay 25
	releaseall
	return

Movement_LugiaGo::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

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
	walk_up
	step_end

NavelRock_Exterior_EventScript_MaximusFinal::
	setvar VAR_0x8004, 8  @ Num loops
	setvar VAR_0x8005, 35 @ Delay
	special LoopWingFlapSound
	playmoncry SPECIES_LUGIA, 2
	applymovement LOCALID_LUGIA, Movement_LugiaGo
	waitmovement 0
	removeobject LOCALID_LUGIA
	setflag FLAG_LUGIA_FLEE
	msgbox NavelRock_Exterior_Text_Returned
	closemessage
	delay 20
	msgbox NavelRock_Exterior_Text_HoldIt
	closemessage
	playbgm MUS_FUCHSIA, 0
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
	delay 45
	applymovement LOCALID_MAXIMUS, NavelRock_Exterior_Movement_Go
	delay 30
	applymovement LOCALID_POLICE_GUY, NavelRock_Exterior_Movement_Take2
	waitmovement 0
	msgbox NavelRock_Exterior_Text_Aap
	closemessage
	playse SE_EXIT
	applymovement LOCALID_POLICELER, NavelRock_Exterior_Movement_LastPoliceler
	waitmovement 0
	removeobject LOCALID_POLICELER
	waitse
	applymovement LOCALID_MAXIMUS, NavelRock_Exterior_Movement_LastMax
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_MAXIMUS
	waitse
	applymovement LOCALID_POLICE_GUY, NavelRock_Exterior_Movement_LastPoliceGuy
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_POLICE_GUY
	waitse
	setflag FLAG_HIDE_NAVEL_POLICE
	setflag FLAG_MAXIMUS_GONE
	fadenewbgm MUS_SEVII_ROUTE
	delay 50
	setflag FLAG_ELM_NAVEL
	releaseall
	return

NavelRock_Exterior_Movement_LastPoliceler::
	walk_in_place_down
	step_end

NavelRock_Exterior_Movement_LastMax::
	walk_down
	walk_in_place_down
	step_end

NavelRock_Exterior_Movement_LastPoliceGuy::
	walk_down
	walk_down
	walk_in_place_down
	step_end

NavelRock_Exterior_Text_Police::
	.string "You're coming with us, MAXIMUS.\p"
	.string "The KANTO POLICE FORCE has heard\n"
	.string "all about your crimes against\l"
	.string "KANTO's legendary POKéMON.$"

NavelRock_Exterior_Text_Response::
	.string "Mother of…\p"
	.string "Who do you think you are,\n"
	.string "you jumped-up piece of…\l"
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
	walk_in_place_right
	delay_16
	walk_in_place_down
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
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	step_end

NavelRock_Exterior_Movement_Go::
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

NavelRock_Exterior_Movement_Take2::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
NavelRock_Exterior_Text_Returned::
	.string "So, you've used LUGIA to escape\n"
	.string "from a life of captivity.\p"
	.string "Isn't that great for you!\p"
	.string "My WARP DEVICE broke thanks to\n"
	.string "the thunderstorm LUGIA keeps\l"
	.string "around itself all the time.\p"
	.string "I guess we'll be sharing a spot\n"
	.string "on the SEAGALLOP!$"

NavelRock_Exterior_Text_HoldIt::
	.string "Hold it right there!\p"
	.string "The only thing you'll be sharing\n"
	.string "is a prison cell!$"

NavelRock_Exterior_EventScript_Maximus::
	lock
	faceplayer
	goto_if_set FLAG_TO_END, NavelRock_Exterior_EventScript_MaximusFinal
	goto_if_set FLAG_DEFEATED_MAXIMUS, NavelRock_Exterior_EventScript_AfterMaximus
	trainerbattle_single TRAINER_COLLECTOR_MAXIMUS, NavelRock_Exterior_Text_Intro, NavelRock_Exterior_Text_Defeat, NavelRock_Exterior_EventScript_Defeated, NO_MUSIC
	release
	end

NavelRock_Base_Movement_Invis::
	set_invisible
	step_end

NavelRock_Exterior_Text_Intro::
	.string "How in blazes did you manage\n"
	.string "to find this island?\p"
	.string "You really are starting to bother me,\n"
	.string "you know that?\p"
	.string "You want to stop me from obtaining\n"
	.string "LUGIA, am I right?\p"
	.string "Not a chance!\p"
	.string "I told you that I do not do stuff\n"
	.string "like battling.\p"
	.string "That's not entirely true.\p"
	.string "I have battled many times\n"
	.string "in my life…\p"
	.string "You do not want me to, but I guess\n"
	.string "it's time to show you your place!$"

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
	setvar VAR_BLOCK, 1
	setflag FLAG_DEFEATED_MAXIMUS
	release
	end

NavelRock_Exterior_Text_Done::
	.string "You win.\n"
	.string "Congratulations.\p"
	.string "Without my POKéMON, I cannot\n"
	.string "even capture LUGIA.\p"
	.string "It looks like you've achieved\n"
	.string "your goal, TRAINER.\p"
	.string "You can have LUGIA.\n"
	.string "You have won fair and square.\p"
	.string "Maybe I have been obsessed with\n"
	.string "collecting POKéMON for too long…$"

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
	.string "There.\n"
	.string "Go ahead and capture LUGIA.$"

NavelRock_Exterior_EventScript_AfterMaximus::
	msgbox NavelRock_Exterior_Text_After
	release
	end

NavelRock_Exterior_Text_After::
	.string "You are incredibly powerful.\p"
	.string "Using such potential for the good\n"
	.string "of all POKéMON is something to\l"
	.string "be proud of.$"

NavelRock_Exterior_EventScript_Sign::
	msgbox NavelRock_Exterior_Text_Sign, MSGBOX_SIGN
	end

NavelRock_Exterior_Text_Sign::
	.string "DANGER! \n"
	.string "Enter at your own risk $"