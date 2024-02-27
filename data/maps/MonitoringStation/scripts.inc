.set LOCALID_ROCKET_M, 1
.set LOCALID_RED_DOOR1, 2
.set LOCALID_RED_DOOR2, 3
.set LOCALID_ROCKET_ADMIN, 4
.set LOCALID_ROCKET_STORAGE, 5
.set LOCALID_ROCKET_QUARTET, 6
.set LOCALID_ROCKET_ADMIN2, 7
.set LOCALID_ROCKET_STORAGE2, 8
.set LOCALID_ROCKET_EXECUTIVE, 9
.set LOCALID_ROCKET_ADMINFINAL, 10
.set LOCALID_ROCKET_EXECUTIVEFINAL, 11
.set LOCALID_ROCKET_STORAGEFINAL, 12

MonitoringStation_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MonitoringStation_EventScript_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MonitoringStation_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, MonitoringStation_OnTransition
	.byte 0
	
MonitoringStation_EventScript_OnLoad::
	clearflag FLAG_DONT_TRANSITION_MUSIC
	call_if_set FLAG_RED_DOOR_SHORTCUT, MonitoringStation_EventScript_RedDoorShortShadows
	call_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_EventScript_Restore_Power
	end
	
MonitoringStation_OnFrame::
	map_script_2 VAR_TEMP_D, 2, MonitoringStation_EventScript_ExitElevator
	map_script_2 VAR_ADMIN_INWAY, 1, MonitoringStation_EventScript_DoorMove
	.2byte 0
	
MonitoringStation_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MONITORING_STATION
	getplayerxy VAR_RESULT, VAR_TEMP_D
	end
	
MonitoringStation_EventScript_RedDoorShortShadows::
	setmetatile 9, 8, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 10, 9, METATILE_SilphCo_HideoutFloor , 0
	setmetatile 10, 10, METATILE_SilphCo_HideoutFloor , 0
	return

MonitoringStation_EventScript_AdminFinal::
	lock
	faceplayer
	msgbox MonitoringStation_Text_AdminFinal
	waitmessage
	release
	end

MonitoringStation_EventScript_StorageFinal::
	lock
	faceplayer
	msgbox MonitoringStation_Text_StorageFinal
	waitmessage
	release
	end	
	
MonitoringStation_EventScript_AdminConvo::
	lockall
	textcolor 1
	msgbox MonitoringStation_Text_Admin
	closemessage
	applymovement LOCALID_ROCKET_STORAGE, MonitoringStation_Movement_StorageGrunt
	waitmovement 0
	textcolor 0
	msgbox MonitoringStation_Text_StorageGrunt
	closemessage
	applymovement LOCALID_ROCKET_QUARTET, MonitoringStation_Movement_Quartet
	waitmovement 0
	msgbox MonitoringStation_Text_Quartet
	closemessage
	playse SE_PIN
	applymovement LOCALID_ROCKET_ADMIN, MonitoringStation_Movement_Both
	applymovement LOCALID_ROCKET_STORAGE, MonitoringStation_Movement_Both
	waitmovement 0
	applymovement LOCALID_ROCKET_ADMIN, MonitoringStation_Movement_Admin
	waitmovement 0
	textcolor 1
	msgbox MonitoringStation_Text_Admin2
	closemessage
	textcolor 0
	msgbox MonitoringStation_Text_Executive
	closemessage
	delay 40
	applymovement LOCALID_ROCKET_STORAGE, MonitoringStation_Movement_StorageGrunt2
	waitmovement 0
	msgbox MonitoringStation_Text_StorageGrunt2
	closemessage
	applymovement LOCALID_ROCKET_QUARTET, MonitoringStation_Movement_ExecutiveWalk
	waitmovement 0
	applymovement LOCALID_ROCKET_STORAGE, MonitoringStation_Movement_StorageListen
	applymovement LOCALID_ROCKET_ADMIN, MonitoringStation_Movement_AdminListen
	waitmovement 0
	msgbox MonitoringStation_Text_Executive2
	closemessage
	applymovement LOCALID_ROCKET_ADMIN, MonitoringStation_Movement_AdminListen
	waitmovement 0
	textcolor 1
	msgbox MonitoringStation_Text_Admin3
	closemessage
	applymovement LOCALID_ROCKET_QUARTET, MonitoringStation_Movement_Executive
	waitmovement 0
	textcolor 0
	msgbox MonitoringStation_Text_Executive3
	closemessage
	applymovement LOCALID_ROCKET_QUARTET, MonitoringStation_Movement_Executive
	waitmovement 0
	textcolor 2
	msgbox MonitoringStation_Text_TookYellowKey
	closemessage
	applymovement LOCALID_ROCKET_QUARTET, MonitoringStation_Movement_ExecutiveWalkBack
	waitmovement 0
	textcolor 0
	msgbox MonitoringStation_Text_Executive4
	closemessage
	giveitem_msg MonitoringStation_Text_ObtainedYellowKey, ITEM_YELLOW_KEY
	applymovement LOCALID_ROCKET_QUARTET, MonitoringStation_Movement_ExecutiveLeft
	waitmovement 0
	textcolor 0
	msgbox MonitoringStation_Text_Executive5
	closemessage
	setflag FLAG_HIDE_ENTRANCE_PEOPLE
	setflag FLAG_GOT_YELLOW_KEY
	setflag FLAG_ENDGAME
	setvar VAR_ADMIN_CONVO, 2
	releaseall
	end
	
MonitoringStation_EventScript_Admin::
	lock
	faceplayer
	msgbox MonitoringStation_Text_AdminLoose
	waitmessage
	release
	end
	
MonitoringStation_EventScript_StorageGrunt::
	lock
	faceplayer
	msgbox MonitoringStation_Text_StorageGruntLoose
	waitmessage
	release
	end
	
MonitoringStation_EventScript_Executive::
	lock
	faceplayer
	msgbox MonitoringStation_Text_Executive5
	waitmessage
	release
	end
	
MonitoringStation_EventScript_ExecutiveReal::
	lock
	faceplayer
	textcolor 0
	call_if_unset FLAG_TALKED_EXECUTIVE, MonitoringStation_EventScript_ExecutiveIntro
	msgbox MonitoringStation_Text_ExecutiveKey
	setflag FLAG_TALKED_EXECUTIVE
	checkitem ITEM_RED_KEY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MonitoringStation_EventScript_ExecutiveYay
	msgbox MonitoringStation_Text_ExecutiveAww
	waitmessage
	release
	end
	
MonitoringStation_EventScript_ExecutiveIntro::
	msgbox MonitoringStation_Text_ExecutiveIntro
	return
	
MonitoringStation_EventScript_ExecutiveYay::
	msgbox MonitoringStation_Text_ExecutiveYay
	waitmessage
	release
	end
	
MonitoringStation_Movement_StorageListen::
	walk_in_place_down
	step_end
	
MonitoringStation_Movement_AdminListen::
	walk_in_place_down
	step_end
	
MonitoringStation_Movement_Both::
	emote_exclamation_mark
	walk_in_place_left
	step_end
	
MonitoringStation_Movement_StorageGrunt::
	walk_in_place_right
	step_end
	
MonitoringStation_Movement_Quartet::
	walk_in_place_right
	step_end
	
MonitoringStation_Movement_Admin::
	walk_in_place_left
	step_end
	
MonitoringStation_Movement_StorageGrunt2::
	walk_in_place_left
	step_end
	
MonitoringStation_Movement_ExecutiveWalk::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end
	
MonitoringStation_Movement_Executive::
	walk_in_place_up
	step_end
	
MonitoringStation_Movement_ExecutiveWalkBack::
	walk_left
	walk_left
	walk_left
	walk_up
	walk_in_place_left
	step_end
	
MonitoringStation_Movement_ExecutiveLeft::
	walk_in_place_left
	step_end

MonitoringStation_EventScript_RedDoor::
	lock
	checkitem ITEM_RED_KEY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MonitoringStation_EventScript_RemoveRedDoor
	textcolor 2
	msgbox MonitoringStation_Text_RedDoor
	closemessage
	release
	end
	
MonitoringStation_Movement_FinalWalk::
	walk_in_place_left
	step_end
	
MonitoringStation_EventScript_RemoveRedDoor::
	setflag FLAG_RED_DOOR_SHORTCUT
	playse SE_RS_DOOR
	waitse
	removeobject LOCALID_RED_DOOR1
	removeobject LOCALID_RED_DOOR2
	setmetatile 9, 8, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 10, 9, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 10, 10, METATILE_SilphCo_HideoutFloor, 0
	special DrawWholeMapView
	msgbox MonitoringStation_Text_RedDoorGone
	closemessage
	applymovement LOCALID_ROCKET_EXECUTIVEFINAL, MonitoringStation_Movement_FinalWalk
	waitmovement 0
	textcolor 0
	msgbox MonitoringStation_Text_ExecutiveFinal
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ROCKET_ADMINFINAL
	removeobject LOCALID_ROCKET_EXECUTIVEFINAL
	removeobject LOCALID_ROCKET_STORAGEFINAL
	setflag FLAG_HORROR_DONE
	setflag FLAG_FINAL_NPCS
	setflag FLAG_ENDGAME
	setflag FLAG_HIDE_FINAL_ADMIN
	fadescreen FADE_FROM_BLACK
	release
	end
	
MonitoringStation_EventScript_Restore_Power::
	setweather WEATHER_NONE
	doweather
	return

MonitoringStation_EventScript_ExitElevator::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, MonitoringStation_Movement_ExitElevator
	waitmovement 0
	setvar VAR_TEMP_D, 0
	releaseall
	end

MonitoringStation_EventScript_DoorMove::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, MonitoringStation_Movement_DoorMove
	waitmovement 0
	playse SE_EXIT
	addobject LOCALID_ROCKET_ADMINFINAL
	applymovement LOCALID_ROCKET_ADMINFINAL, MonitoringStation_Movement_AdminMove
	waitmovement 0
	setvar VAR_ADMIN_INWAY, 2
	clearflag FLAG_HIDE_FINAL_ADMIN
	releaseall
	end
	
MonitoringStation_Movement_DoorMove::
	walk_up
	step_end
	
MonitoringStation_Movement_AdminMove::
	set_visible
	walk_in_place_up
	step_end
	
MonitoringStation_EventScript_ElevatorBroken::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	msgbox MonitoringStation_Text_OutOfOrder
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MonitoringStation_Movement_ForcePlayerFromDoor
	waitmovement 0
	releaseall
	end	
	
MonitoringStation_Movement_ForcePlayerFromDoor::
	walk_down
	step_end
	
MonitoringStation_EventScript_RocketLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto MonitoringStation_EventScript_Rocket
	end

MonitoringStation_EventScript_RocketMiddle::
	lockall
	setvar VAR_TEMP_1, 1
	goto MonitoringStation_EventScript_Rocket
	end

MonitoringStation_EventScript_RocketRight::
	lockall
	setvar VAR_TEMP_1, 2
	goto MonitoringStation_EventScript_Rocket
	end
	
MonitoringStation_EventScript_Rocket::
	setvar VAR_HONEY2, 1
	setvar VAR_HONEY1, 1
	setflag FLAG_HIDE_ADMIN2
	setflag FLAG_HIDE_HORROR_NPC
	setvar VAR_TAKEKEY, 1
	playbgm MUS_ENCOUNTER_ROCKET, 0
	compare VAR_TEMP_1, 0
	call_if_eq MonitoringStation_EventScript_RocketTwoSteps
	compare VAR_TEMP_1, 1
	call_if_eq MonitoringStation_EventScript_RocketOneStep
	compare VAR_TEMP_1, 2
	call_if_eq MonitoringStation_EventScript_RocketNoSteps
	textcolor 0
	msgbox MonitoringStation_Text_RocketWhat
	closemessage
	fadeoutbgm 0
	playmoncry SPECIES_KABUTOPS, 2
	waitmoncry
	playse SE_PIN
	applymovement LOCALID_ROCKET_M, MonitoringStation_Movement_RocketScared
	waitmovement 0
	msgbox MonitoringStation_Text_RocketAh
	waitmessage
	applymovement LOCALID_ROCKET_M, MonitoringStation_Movement_RocketMoveToPlayer
	waitmovement 0
	msgbox MonitoringStation_Text_RocketCheck
	closemessage
	compare VAR_TEMP_1, 0
	call_if_eq MonitoringStation_EventScript_RocketMoveTwoSteps
	compare VAR_TEMP_1, 1
	call_if_eq MonitoringStation_EventScript_RocketMoveOneStep
	compare VAR_TEMP_1, 2
	call_if_eq MonitoringStation_EventScript_RocketMoveNoSteps
	playse SE_EXIT
	removeobject LOCALID_ROCKET_M
	setflag FLAG_HORROR_ROCKET_MOVED
	delay 100
	msgbox MonitoringStation_Text_RocketNo
	closemessage
	playbgm MUS_WEATHER_GROUDON, 1
	fadeinbgm 1
	setvar VAR_MAP_SCENE_MONITORING_STATION, 4
	end
	
MonitoringStation_EventScript_RocketMoveTwoSteps::
	applymovement LOCALID_ROCKET_M, MonitoringStation_Movement_RocketMoveTwoSteps
	waitmovement 0
	return

MonitoringStation_EventScript_RocketMoveOneStep::
	applymovement LOCALID_ROCKET_M, MonitoringStation_Movement_RocketMoveOneStep
	waitmovement 0
	return

MonitoringStation_EventScript_RocketMoveNoSteps::
	applymovement LOCALID_ROCKET_M, MonitoringStation_Movement_RocketMoveNoSteps
	waitmovement 0
	return
	
MonitoringStation_EventScript_RocketTwoSteps::
	applymovement LOCALID_ROCKET_M, MonitoringStation_Movement_RocketTwoSteps
	waitmovement 0
	return

MonitoringStation_EventScript_RocketOneStep::
	applymovement LOCALID_ROCKET_M, MonitoringStation_Movement_RocketOneStep
	waitmovement 0
	return

MonitoringStation_EventScript_RocketNoSteps::
	applymovement LOCALID_ROCKET_M, MonitoringStation_Movement_RocketNoSteps
	waitmovement 0
	return
	
MonitoringStation_Movement_RocketMoveTwoSteps::
	walk_down
	walk_down
	walk_down
	step_end
	
MonitoringStation_Movement_RocketMoveOneStep::
	walk_down
	walk_left
	walk_down
	walk_down
	step_end
	
MonitoringStation_Movement_RocketMoveNoSteps::
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
	
MonitoringStation_Movement_RocketMove::
	walk_down
	
MonitoringStation_Movement_RocketMoveToPlayer::
	walk_in_place_left
	walk_in_place_down
	walk_in_place_left
	step_end
	
MonitoringStation_Movement_RocketScared::
	emote_exclamation_mark
	walk_in_place_down
	step_end

MonitoringStation_Movement_RocketTwoSteps::
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	walk_left
	walk_left	
	step_end
	
MonitoringStation_Movement_RocketOneStep::
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	walk_left	
	step_end
	
MonitoringStation_Movement_RocketNoSteps::
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16	
	step_end
	
MonitoringStation_Movement_ExitElevator::
	walk_down
	step_end