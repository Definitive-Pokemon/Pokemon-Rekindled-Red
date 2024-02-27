.set LOCALID_BLUE_DOOR1, 1
.set LOCALID_BLUE_DOOR2, 2
.set LOCALID_ROCKET_M, 3

MonitoringStation_Storage_MapScripts::
map_script MAP_SCRIPT_ON_LOAD, MonitoringStation_Storage_EventScript_OnLoad
	.byte 0

MonitoringStation_Storage_EventScript_OnLoad::
	call_if_set FLAG_BLUE_DOOR_POKE, MonitoringStation_Storage_EventScript_BlueDoorPokeShadows
	call_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_Storage_EventScript_Restore_Power
	end
	
MonitoringStation_Storage_EventScript_BlueDoorPokeShadows::
	setmetatile 19, 7, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 20, 8, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 20, 9, METATILE_SilphCo_HideoutFloor, 0
	return
	
MonitoringStation_Storage_EventScript_BlueDoor::
	lock
	checkitem ITEM_BLUE_KEY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MonitoringStation_Storage_EventScript_RemoveBlueDoor
	textcolor 2
	msgbox MonitoringStation_Storage_Text_BlueDoor
	closemessage
	release
	end
	
MonitoringStation_Storage_EventScript_RemoveBlueDoor::
	setflag FLAG_BLUE_DOOR_POKE
	playse SE_RS_DOOR
	waitse
	removeobject LOCALID_BLUE_DOOR1
	removeobject LOCALID_BLUE_DOOR2
	setmetatile 19, 7, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 20, 8, METATILE_SilphCo_HideoutFloor , 0
	setmetatile 20, 9, METATILE_SilphCo_HideoutFloor , 0
	special DrawWholeMapView
	msgbox MonitoringStation_Storage_Text_BlueDoorGone
	closemessage
	release
	end
	
MonitoringStation_Storage_EventScript_Restore_Power::
	setweather WEATHER_NONE
	doweather
	return
	
MonitoringStation_Storage_EventScript_Rocket::
	lock
	msgbox MonitoringStation_Storage_Text_Agh
	playse SE_PIN
	applymovement LOCALID_ROCKET_M, MonitoringStation_Storage_Movement_Rocket_Ex
	waitmovement 0
	faceplayer
	goto_if_set FLAG_FIND_BLUE_KEY, MonitoringStation_Storage_EventScript_RocketBlueKey
	goto_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_Storage_EventScript_RocketPhew
	goto_if_set FLAG_HORROR_ROCKET_EXPLAINED, MonitoringStation_Storage_EventScript_RocketDone
	msgbox MonitoringStation_Storage_Text_Explain
	closemessage
	applymovement LOCALID_ROCKET_M, MonitoringStation_Storage_Movement_Rocket
	waitmovement 0
	msgbox MonitoringStation_Storage_Text_RedKeyAdmin
	setflag FLAG_HORROR_ROCKET_EXPLAINED
	applymovement LOCALID_ROCKET_M, MonitoringStation_Storage_Movement_RocketRight
	waitmovement 0
	release
	end
	
MonitoringStation_Storage_EventScript_RocketDone::
	msgbox MonitoringStation_Storage_Text_Done
	applymovement LOCALID_ROCKET_M, MonitoringStation_Storage_Movement_RocketRight
	waitmovement 0
	release
	end
	
MonitoringStation_Storage_EventScript_RocketPhew::
	msgbox MonitoringStation_Storage_Text_Phew
	applymovement LOCALID_ROCKET_M, MonitoringStation_Storage_Movement_RocketRight
	waitmovement 0
	release
	end

MonitoringStation_Storage_EventScript_RocketBlueKey::
	msgbox MonitoringStation_Storage_Text_BlueKey
	applymovement LOCALID_ROCKET_M, MonitoringStation_Storage_Movement_RocketRight
	waitmovement 0
	release
	end
	
MonitoringStation_Storage_Movement_Rocket::
	walk_in_place_up
	delay_16
	walk_in_place_left
	delay_16
	step_end
	
MonitoringStation_Storage_Movement_Rocket_Ex::
	emote_exclamation_mark
	step_end
	
MonitoringStation_Storage_Movement_RocketRight::
	walk_in_place_right
	step_end