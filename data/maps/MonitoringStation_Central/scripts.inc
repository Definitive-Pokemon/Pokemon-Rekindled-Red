.set LOCALID_KABUTOPS_SHADOW, 1
.set LOCALID_ROCKET_M, 2
.set LOCALID_MACHOKE, 3
.set LOCALID_PUSHABLE_BOULDER, 7
.set LOCALID_PUSHABLE_BOULDER3, 9
.set LOCALID_ROCKET_M2, 11
.set LOCALID_KANGASKHAN, 12

MonitoringStation_Central_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MonitoringStation_Central_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, MonitoringStation_Central_EventScript_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MonitoringStation_Central_EventScript_OnFrame
	.byte 0

MonitoringStation_Central_OnWarp::
	map_script_2 VAR_MAP_SCENE_MONITORING_STATION_CENTRAL, 1, MonitoringStation_Central_EventScript_TurnPlayerNorth
	.2byte 0

MonitoringStation_Central_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end
	
MonitoringStation_Central_EventScript_OnLoad::
	call_if_set FLAG_GOT_YELLOW_KEY, MonitoringStation_Central_EventScript_SetNewPeople
	call_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_Central_EventScript_GreyDoorAdminShadows
	setflag FLAG_HORROR_HIDE_BOULDER
	end
	
MonitoringStation_Central_EventScript_SetNewPeople::
	clearflag FLAG_ENDGAME
	clearflag FLAG_GOT_YELLOW_KEY
	return
	
MonitoringStation_Central_EventScript_OnFrame::
	map_script_2 VAR_MONITORING_STATION_CENTRAL_STATE, 0, MonitoringStation_Central_EventScript_Kabutops
	map_script_2 VAR_MONITORING_STATION_QUARTET, 1, MonitoringStation_Central_EventScript_QuartetRock
	.2byte 0
	
MonitoringStation_Central_EventScript_QuartetRock::
	lockall
	delay 20
	applymovement LOCALID_ROCKET_M2, MonitoringStation_Central_Movement_QuartetRock
	waitmovement 0
	textcolor 0
	msgbox MonitoringStation_Central_Text_QuartetRock
	closemessage
	setvar VAR_MONITORING_STATION_QUARTET, 2
	setvar VAR_MAP_SCENE_MONITORING_STATION_CENTRAL, 2
	releaseall
	end
	
MonitoringStation_Central_EventScript_QuartetKanga::
	lock
	faceplayer
	msgbox MonitoringStation_Central_Text_QuartetKanga
	goto_if_set FLAG_HIDE_MOM, MonitoringStation_Central_EventScript_QuartetKangaYes
	msgbox MonitoringStation_Central_Text_QuartetKangaNo
	closemessage
	release
	end
	
MonitoringStation_Central_EventScript_QuartetKangaYes::
	msgbox MonitoringStation_Central_Text_QuartetKangaYes
	closemessage
	fadescreen FADE_TO_BLACK
	applymovement OBJ_EVENT_ID_PLAYER, MonitoringStation_Central_Movement_OutOfWay
	waitmovement 0
	lockall
	addobject LOCALID_KANGASKHAN
	clearflag FLAG_HIDE_KANGA
	fadescreen FADE_FROM_BLACK
	delay 20
	msgbox MonitoringStation_Central_Text_Quartet
	closemessage
	delay 40
	applymovement LOCALID_ROCKET_M2, MonitoringStation_Central_Movement_Quartet
	waitmovement 0
	msgbox MonitoringStation_Central_Text_Quartet2
	closemessage
	playmoncry SPECIES_KANGASKHAN, CRY_MODE_NORMAL
	textcolor 2
	msgbox MonitoringStation_Central_Text_Kanga
	closemessage
	waitmoncry
	applymovement LOCALID_KANGASKHAN, MonitoringStation_Central_Movement_Kanga
	waitmovement 0
	playmoncry SPECIES_KANGASKHAN, CRY_MODE_ENCOUNTER
	waitmoncry
	applymovement LOCALID_PUSHABLE_BOULDER3, MonitoringStation_Central_Movement_KangaBoulder
	playse SE_M_STRENGTH
	waitse
	waitmovement 0
	applymovement LOCALID_ROCKET_M2, MonitoringStation_Central_Movement_Quartet2
	waitmovement 0
	textcolor 0
	msgbox MonitoringStation_Central_Text_Quartet3
	closemessage
	applymovement LOCALID_ROCKET_M2, MonitoringStation_Central_Movement_Quartet3
	waitmovement 0
	removeobject LOCALID_ROCKET_M2
	playse SE_EXIT
	waitse
	setflag FLAG_HIDE_CHONKDUO
	setflag FLAG_HIDE_BOULDER3
	clearflag FLAG_HIDE_BOULDER4
	releaseall
	end
	
MonitoringStation_Central_Movement_OutOfWay::
	walk_fast_down
	walk_in_place_up
	step_end
	
MonitoringStation_Central_Movement_QuartetRock::
	walk_in_place_down
	step_end
	
MonitoringStation_Central_EventScript_GreyDoorAdminShadows::
	setmetatile 2, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 3, 22, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 3, 23, METATILE_SilphCo_HideoutFloor, 0
	setweather WEATHER_NONE
	doweather
	return
	
MonitoringStation_Central_EventScript_Kanga::
	lock
	faceplayer
	goto_if_set FLAG_HORROR_DONE, MonitoringStation_Central_EventScript_KangaHappy
	playmoncry SPECIES_KANGASKHAN, CRY_MODE_NORMAL
	msgbox MonitoringStation_Central_Text_Kanga
	closemessage
	waitmoncry
	release
	end
	
MonitoringStation_Central_EventScript_KangaHappy::
	playmoncry SPECIES_KANGASKHAN, CRY_MODE_NORMAL
	msgbox MonitoringStation_Central_Text_Kanga
	waitmoncry
	msgbox MonitoringStation_Central_Text_KangaHappy
	closemessage
	release
	end
	
MonitoringStation_Central_EventScript_GreyDoors::
	lock
	textcolor 2
	msgbox MonitoringStation_Central_Text_GreyDoor
	closemessage
	release
	end
	
MonitoringStation_Central_EventScript_Kabutops::
	lockall
	fadeoutbgm 1
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MonitoringStation_Central_Movement_PanToActionFromTop
	waitmovement 0
	special RemoveCameraObject
	delay 60
	applymovement LOCALID_ROCKET_M, MonitoringStation_Central_Movement_RocketTalk
	waitmovement 0
	textcolor 0
	msgbox MonitoringStation_Central_Text_RocketAttack
	waitmessage
	playmoncry SPECIES_MACHOKE, CRY_MODE_ENCOUNTER
	textcolor 2
	msgbox MonitoringStation_Central_Text_MachokeNoise
	closemessage
	playse SE_M_VITAL_THROW
	applymovement LOCALID_MACHOKE, MonitoringStation_Central_Movement_MachokeAttack
	waitmovement 0
	applymovement LOCALID_KABUTOPS_SHADOW, MonitoringStation_Central_Movement_KabutopsTurn
	applymovement LOCALID_MACHOKE, MonitoringStation_Central_Movement_MachokeAttack2
	waitmovement 0
	playse SE_M_VITAL_THROW
	applymovement LOCALID_MACHOKE, MonitoringStation_Central_Movement_MachokeAttackBack
	waitmovement 0
	applymovement LOCALID_KABUTOPS_SHADOW, MonitoringStation_Central_Movement_KabutopsTurnBack
	applymovement LOCALID_MACHOKE, MonitoringStation_Central_Movement_MachokeAttackBack2
	waitmovement 0
	playmoncry SPECIES_KABUTOPS, CRY_MODE_ECHO_START
	clearflag FLAG_HORROR_HIDE_BOULDER
	addobject LOCALID_PUSHABLE_BOULDER
	applymovement LOCALID_PUSHABLE_BOULDER, MonitoringStation_Central_Movement_KabutopsAttack
	waitmovement 0
	playse SE_FALL
	applymovement LOCALID_PUSHABLE_BOULDER, MonitoringStation_Central_Movement_KabutopsAttack2
	waitmovement 0
	playmoncry SPECIES_MACHOKE, CRY_MODE_FAINT
	playse SE_BANG
	applymovement LOCALID_MACHOKE, MonitoringStation_Central_Movement_MachokeSlammedAway
	applymovement LOCALID_PUSHABLE_BOULDER, MonitoringStation_Central_Movement_KabutopsAttack3
	waitmovement 0
	delay 100
	applymovement LOCALID_ROCKET_M, MonitoringStation_Central_Movement_RocketTalk
	waitmovement 0
	textcolor 0
	msgbox MonitoringStation_Central_Text_RocketWhat
	closemessage
	playmoncry SPECIES_KABUTOPS, CRY_MODE_WEAK
	waitmoncry
	applymovement LOCALID_KABUTOPS_SHADOW, MonitoringStation_Central_Movement_KabutopsWalkThrough
	waitmovement 0
	delay 60
	applymovement LOCALID_ROCKET_M, MonitoringStation_Central_Movement_RocketTalk
	waitmovement 0
	msgbox MonitoringStation_Central_Text_RocketNo
	closemessage
	playmoncry SPECIES_KABUTOPS, CRY_MODE_ECHO_START
	waitmoncry
	setobjectsubpriority LOCALID_PUSHABLE_BOULDER, MAP_MONITORING_STATION_CENTRAL, 0
	setobjectsubpriority LOCALID_ROCKET_M, MAP_MONITORING_STATION_CENTRAL, 0
	applymovement LOCALID_KABUTOPS_SHADOW, MonitoringStation_Central_Movement_KabutopsWalkThrough2
	waitmovement 0
	applymovement LOCALID_ROCKET_M, MonitoringStation_Central_Movement_RocketTalk2
	waitmovement 0
	delay 200
	msgbox MonitoringStation_Central_Text_RocketOh
	closemessage
	delay 100
	message MonitoringStation_Central_Text_RocketAh
	applymovement LOCALID_ROCKET_M, MonitoringStation_Central_Movement_RocketRun
	waitmovement 0
	playse SE_EXIT
	closemessage
	waitse
	setobjectxyperm 7, 14, 17
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MonitoringStation_Central_Movement_PanToActionFromBottom
	waitmovement 0
	special RemoveCameraObject
	fadeinbgm 1
	clearflag FLAG_HIDE_BOULDER2
	removeobject LOCALID_MACHOKE
	removeobject LOCALID_KABUTOPS_SHADOW
	removeobject LOCALID_ROCKET_M
	setflag FLAG_KABUTOPS_FIRST_APPEAR
	setvar VAR_MONITORING_STATION_CENTRAL_STATE, 1
	releaseall
	end

MonitoringStation_Central_Eventscript_Admin::
	lock
	faceplayer
	goto_if_set FLAG_FIND_BLUE_KEY, MonitoringStation_Central_Eventscript_Admin2
	msgbox MonitoringStation_Central_Text_Admin
	waitmessage
	setflag FLAG_FIND_BLUE_KEY
	release
	end
	
MonitoringStation_Central_Eventscript_Admin2::
	msgbox MonitoringStation_Central_Text_Admin2
	waitmessage
	release
	end
	
MonitoringStation_Central_Eventscript_Boulder::
	lock
	msgbox MonitoringStation_Central_Text_Boulder
	waitmessage
	release
	end
	
MonitoringStation_Central_Eventscript_BoulderPostScare::
	msgbox MonitoringStation_Central_Text_Boulder2
	waitmessage
	release
	end
	
MonitoringStation_Central_Movement_Kanga::
	walk_up
	walk_in_place_right
	step_end
	
MonitoringStation_Central_Movement_KangaBoulder::
	walk_right
	step_end
	
MonitoringStation_Central_Movement_Quartet::
	walk_in_place_up
	step_end
	
MonitoringStation_Central_Movement_Quartet2::
	walk_in_place_down
	step_end
	
MonitoringStation_Central_Movement_Quartet3::
	walk_up
	walk_up
	walk_in_place_up
	step_end

MonitoringStation_Central_Movement_PanToActionFromTop::
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_right
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_right
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_right
	step_end
	
MonitoringStation_Central_Movement_RocketTalk::
	walk_in_place_right
	step_end

MonitoringStation_Central_Movement_MachokeAttack::
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end
	
MonitoringStation_Central_Movement_MachokeAttack2::
	walk_fast_right
	walk_in_place_right
	delay_16
	walk_in_place_left
	step_end
	
MonitoringStation_Central_Movement_KabutopsTurn::
	walk_in_place_right
	step_end
	
MonitoringStation_Central_Movement_MachokeAttackBack::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
	
MonitoringStation_Central_Movement_MachokeAttackBack2::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_left
	delay_16
	walk_in_place_right
	step_end
	
MonitoringStation_Central_Movement_KabutopsTurnBack::
	walk_in_place_left
	step_end
	
MonitoringStation_Central_Movement_KabutopsAttack::
	walk_fast_left
	walk_fast_down
	step_end

MonitoringStation_Central_Movement_KabutopsAttack2::	
	walk_fast_left
	walk_fast_left
	step_end
	
MonitoringStation_Central_Movement_KabutopsAttack3::
	walk_left
	walk_left
	step_end
	
MonitoringStation_Central_Movement_MachokeSlammedAway::
	walk_in_place_up
	lock_facing_direction
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
	
MonitoringStation_Central_Movement_KabutopsWalkThrough::
	walk_slow_left
	delay_16
	delay_16
	delay_16
	delay_16
	walk_slow_left
	delay_16
	delay_16
	delay_16
	delay_16
	walk_slow_left
	delay_16
	delay_16
	delay_16
	delay_16
	walk_slow_left
	delay_16
	delay_16
	delay_16
	delay_16
	walk_slow_left
	delay_16
	delay_16
	delay_16
	delay_16
	step_end
	
MonitoringStation_Central_Movement_KabutopsWalkThrough2::
	walk_left
	delay_16
	delay_16
	walk_left
	delay_16
	delay_16
	walk_left
	delay_16
	delay_16
	walk_left
	delay_16
	delay_16
	walk_left
	delay_16
	delay_16
	walk_left
	delay_16
	delay_16
	walk_left
	delay_16
	delay_16
	walk_left
	delay_16
	delay_16
	step_end
	
MonitoringStation_Central_Movement_RocketTalk2::
	walk_in_place_left
	step_end
	
MonitoringStation_Central_Movement_RocketRun::
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
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
	
MonitoringStation_Central_Movement_PanToActionFromBottom::
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_left
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_left
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_left
	step_end