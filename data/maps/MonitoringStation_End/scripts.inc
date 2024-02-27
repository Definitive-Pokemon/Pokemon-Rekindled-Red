.set LOCALID_RED_DOOR1, 1
.set LOCALID_RED_DOOR2, 2

MonitoringStation_End_MapScripts::
map_script MAP_SCRIPT_ON_LOAD, MonitoringStation_End_EventScript_OnLoad
	.byte 0

MonitoringStation_End_EventScript_OnLoad::
	call_if_set FLAG_RED_DOOR_END, MonitoringStation_End_EventScript_RedDoorEndShadows
	end
	
MonitoringStation_End_EventScript_RedDoorEndShadows::
	setmetatile 3, 7, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 4, 8, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 4, 9, METATILE_SilphCo_HideoutFloor, 0
	return

MonitoringStation_End_EventScript_RedDoor::
	lock
	checkitem ITEM_RED_KEY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MonitoringStation_End_EventScript_RemoveRedDoor
	textcolor 2
	msgbox MonitoringStation_End_Text_RedDoor
	closemessage
	release
	end
	
MonitoringStation_End_EventScript_RemoveRedDoor::
	setflag FLAG_RED_DOOR_END
	playse SE_RS_DOOR
	waitse
	removeobject LOCALID_RED_DOOR1
	removeobject LOCALID_RED_DOOR2
	setmetatile 3, 7, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 4, 8, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 4, 9, METATILE_SilphCo_HideoutFloor, 0
	special DrawWholeMapView
	msgbox MonitoringStation_End_Text_RedDoorGone
	closemessage
	release
	end