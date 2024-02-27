.set LOCALID_KABUTOPS_SHADOW, 1
.set LOCALID_ROCKET_ADMIN, 2
.set LOCALID_DUSCLOPS, 3

MonitoringStation_Office_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MonitoringStation_Office_OnFrame
	.byte 0

MonitoringStation_Office_OnFrame::
	map_script_2 VAR_WELCOME, 0, MonitoringStation_Office_EventScript_Welcome
	.2byte 0
	
MonitoringStation_Office_EventScript_Var::
	lockall
	textcolor 1
	goto_if_set FLAG_GOT_RED_KEY, MonitoringStation_Office_EventScript_Continue
	applymovement LOCALID_ROCKET_ADMIN, MonitoringStation_Office_Movement_AdminLookUp
	waitmovement 0
	msgbox MonitoringStation_Office_Text_NotDone
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MonitoringStation_Office_Movement_PlayerDown
	waitmovement 0
	releaseall
	end
	
MonitoringStation_Office_EventScript_Text::
	msgbox MonitoringStation_Office_Text_Text, MSGBOX_SIGN
	end
	
MonitoringStation_Office_EventScript_Continue::
	applymovement LOCALID_ROCKET_ADMIN, MonitoringStation_Office_Movement_AdminLookUp
	waitmovement 0
	msgbox MonitoringStation_Office_Text_Done
	closemessage
	formatwarp MAP_MONITORING_STATION, 255, 3, 11
	setvar VAR_GOT_RED_KEY, 2
	setflag FLAG_HIDE_OFFICE_ADMIN
	setflag FLAG_ENDGAME
	setvar VAR_ADMIN_INWAY, 1
	clearflag FLAG_FINAL_NPCS
	releaseall
	end
	
MonitoringStation_Office_EventScript_Talk::
	lock
	faceplayer
	msgbox MonitoringStation_Office_Text_Talk
	closemessage
	release
	end
	
MonitoringStation_Office_EventScript_Welcome::
	lockall
	setvar VAR_WELCOME, 1
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MonitoringStation_Office_Movement_PanToActionFromTop
	waitmovement 0
	delay 120
	playmoncry SPECIES_KABUTOPS, 2
	call MonitoringStation_Office_EventScript_BrailleMessage1
	delay 100
	applymovement OBJ_EVENT_ID_PLAYER, MonitoringStation_Office_Movement_Walk
	waitmovement 0
	delay 100
	call MonitoringStation_Office_EventScript_BrailleMessage2
	delay 80
	addobject LOCALID_ROCKET_ADMIN
	applymovement LOCALID_ROCKET_ADMIN, MonitoringStation_Office_Movement_AdminRun
	textcolor 1
	msgbox MonitoringStation_Office_Text_Admin
	closemessage
	applymovement LOCALID_ROCKET_ADMIN, MonitoringStation_Office_Movement_Admin
	waitmovement 0
	msgbox MonitoringStation_Office_Text_AdminHelp
	closemessage
	applymovement LOCALID_KABUTOPS_SHADOW, MonitoringStation_Office_Movement_KabWalkUp
	waitmovement 0
	playmoncry SPECIES_KABUTOPS, 4
	waitmoncry
	applymovement OBJ_EVENT_ID_PLAYER, MonitoringStation_Office_Movement_Attack1
	waitmovement 0
	playse SE_M_VITAL_THROW
	applymovement LOCALID_KABUTOPS_SHADOW, MonitoringStation_Office_Movement_KabTurn
	applymovement OBJ_EVENT_ID_PLAYER, MonitoringStation_Office_Movement_Attack2
	waitmovement 0
	applymovement LOCALID_ROCKET_ADMIN, MonitoringStation_Office_Movement_Admin
	waitmovement 0
	msgbox MonitoringStation_Office_Text_AdminNo
	closemessage
	applymovement LOCALID_ROCKET_ADMIN, MonitoringStation_Office_Movement_AdminRunUp
	waitmovement 0
	msgbox MonitoringStation_Office_Text_AdminPokemon
	closemessage
	playse SE_BALL_OPEN
	fadescreen FADE_TO_WHITE
	clearflag FLAG_HIDE_DUSCLOPS
	addobject LOCALID_DUSCLOPS
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_DUSCLOPS, 0
	waitmoncry
	delay 80
	msgbox MonitoringStation_Office_Text_AdminAttack
	closemessage
	playmoncry SPECIES_DUSCLOPS, 2
	waitmoncry
	applymovement LOCALID_DUSCLOPS, MonitoringStation_Office_Movement_DusclopsAttack
	delay 5
	applymovement LOCALID_KABUTOPS_SHADOW, MonitoringStation_Office_Movement_KabutopsLook
	playse SE_M_VITAL_THROW2
	waitse
	playmoncry SPECIES_KABUTOPS, 11
	waitmoncry
	delay 100
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_KABUTOPS_SHADOW
	fadescreen FADE_FROM_BLACK
	delay 100
	msgbox MonitoringStation_Office_Text_AdminComeBack
	closemessage
	playse SE_BALL_OPEN
	fadescreen FADE_TO_WHITE
	setflag FLAG_HIDE_DUSCLOPS
	removeobject LOCALID_DUSCLOPS
	fadescreen FADE_FROM_WHITE
	delay 100
	applymovement LOCALID_ROCKET_ADMIN, MonitoringStation_Office_Movement_AdminWalkDown
	waitmovement 0
	msgbox MonitoringStation_Office_Text_AdminKey
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, MonitoringStation_Office_Movement_PanToActionFromBottom
	waitmovement 0
	special RemoveCameraObject
	clearflag FLAG_HIDE_OFFICE_ADMIN
	setvar VAR_GOT_RED_KEY, 1
	releaseall
	end
	
MonitoringStation_Office_Movement_PlayerDown::
	walk_down
	step_end
	
MonitoringStation_Office_Movement_AdminLookUp::
	walk_in_place_up
	step_end
	
MonitoringStation_Office_Movement_AdminWalkDown::
	walk_down
	walk_down
	step_end
	
MonitoringStation_Office_Movement_DusclopsAttack::
	walk_fast_down
	walk_in_place_down
	step_end
	
MonitoringStation_Office_Movement_Walk::
	walk_slow_down
	walk_down
	step_end
	
MonitoringStation_Office_Movement_AdminRun::
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	step_end
	
MonitoringStation_Office_Movement_Admin::
	walk_in_place_down
	step_end
	
MonitoringStation_Office_Movement_KabWalkUp::
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end
	
MonitoringStation_Office_Movement_Attack1::
	lock_facing_direction
	walk_fast_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_down
	jump_down
	unlock_facing_direction
	step_end
	
MonitoringStation_Office_Movement_KabTurn::
	walk_fast_down
	step_end
	
MonitoringStation_Office_Movement_Attack2::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_in_place_up
	step_end
	
MonitoringStation_Office_Movement_AdminRunUp::
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_in_place_down
	step_end
	
MonitoringStation_Office_Movement_KabutopsLook::
	walk_in_place_up
	lock_facing_direction
	walk_fast_down
	step_end
	
MonitoringStation_Office_EventScript_BrailleMessage1::
	setvar VAR_0x8005, 130
	braillemessage_wait Braille_Text_Welcome
	closemessage
	return
	
MonitoringStation_Office_EventScript_BrailleMessage2::
	setvar VAR_0x8005, 130
	braillemessage_wait Braille_Text_Journey
	braillemessage_wait Braille_Text_Gone
	braillemessage_wait Braille_Text_For
	braillemessage_wait Braille_Text_Enough
	closemessage
	return
	
MonitoringStation_Office_Movement_PanToActionFromTop::
	walk_slow_down
	walk_slow_down
	step_end

MonitoringStation_Office_Movement_PanToActionFromBottom::
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end