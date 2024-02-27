MonitoringStation_Shortcut_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MonitoringStation_Shortcut_EventScript_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MonitoringStation_Shortcut_EventScript_OnFrame
	.byte 0

MonitoringStation_Shortcut_EventScript_OnLoad::
	call_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_Shortcut_EventScript_GreyDoorDownstairsShadows
	end

MonitoringStation_Shortcut_EventScript_OnFrame::
	map_script_2 VAR_LOCK_FLASH, 1, MonitoringStation_Shortcut_EventScript_PokemonScared
	.2byte 0

MonitoringStation_Shortcut_EventScript_GreyDoorDownstairsShadows::
	setmetatile 3, 7, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 4, 8, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 4, 9, METATILE_SilphCo_HideoutFloor, 0
	setweather WEATHER_NONE
	doweather
	return
	
MonitoringStation_Shortcut_EventScript_PokemonScared::
	lockall
	delay 50
	setvar VAR_LOCK_FLASH, 0
	msgbox MonitoringStation_Shortcut_Text_Scared
	waitmessage
	releaseall
	end
	
MonitoringStation_Shortcut_EventScript_KabutopsTakesKey::
	lock
	fadeoutbgm 0
	playmoncry SPECIES_KABUTOPS, 2
	waitmoncry
	delay 100
	textcolor 1
	msgbox MonitoringStation_Shortcut_Text_AdminDefense1
	waitmessage
	delay 100
	msgbox MonitoringStation_Shortcut_Text_AdminDefense2
	waitmessage
	delay 50
	msgbox MonitoringStation_Shortcut_Text_AdminDefense3
	waitmessage
	fadeinbgm 1
	setvar VAR_TAKEKEY, 1
	clearflag FLAG_HIDE_ADMIN2
	release
	end