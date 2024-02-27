.set LOCALID_ROCKET_M, 3

MonitoringStation_Hallway2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MonitoringStation_Hallway2_EventScript_OnLoad
	.byte 0

MonitoringStation_Hallway2_EventScript_OnLoad::
	call_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_Hallway2_EventScript_Weather
	end
	
MonitoringStation_Hallway2_EventScript_Weather::
	setweather WEATHER_NONE
	doweather
	return
	
MonitoringStation_Hallway2_EventScript_Help::
	lock
	textcolor 0
	msgbox MonitoringStation_Hallway2_Text_Help
	waitmessage
	setvar VAR_MONITORING_STATION_HALLWAY2_HELP, 1
	release
	end
	
MonitoringStation_Hallway2_EventScript_Help2::
	lock
	msgbox MonitoringStation_Hallway2_Text_Help2
	closemessage
	release
	end