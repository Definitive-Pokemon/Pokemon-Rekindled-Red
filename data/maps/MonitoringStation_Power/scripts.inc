.set LOCALID_MOM, 1
.set LOCALID_GIOVANNI, 2
.set LOCALID_LANCE, 3
.set LOCALID_GYM_SIGN, 4
.set LOCALID_KABUTOPS_SHADOW, 5

MonitoringStation_Power_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MonitoringStation_Power_EventScript_OnLoad
	.byte 0

MonitoringStation_Power_EventScript_OnLoad::
	call_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_Power_EventScript_Weather
	call_if_unset FLAG_HORROR_POWER_RESTORED, MonitoringStation_Power_EventScript_Music
	end

MonitoringStation_Power_EventScript_Weather::
	setflashlevel 0
	setweather WEATHER_NONE
	doweather
	return
	
MonitoringStation_Power_EventScript_Music::
	fadeoutbgm 0
	return
	
MonitoringStation_Power_EventScript_Rocket::
	lock
	faceplayer
	msgbox MonitoringStation_Power_Text_Rocket
	closemessage
	playse SE_M_BUBBLE_BEAM
	release
	end
	
MonitoringStation_Power_EventScript_Gym::
	lock
	msgbox MonitoringStation_Power_Text_Gym
	closemessage
	release
	end
	
MonitoringStation_Power_EventScript_Lance::
	lock
	faceplayer
	msgbox MonitoringStation_Power_Text_Lance
	closemessage
	playse SE_M_LEER
	release
	end
	
MonitoringStation_Power_EventScript_Honey1::
	lock
	playmoncry SPECIES_PARASECT, 2
	msgbox MonitoringStation_Power_Text_Honey1
	closemessage
	setvar VAR_HONEY1, 1
	end
	
MonitoringStation_Power_EventScript_Honey2::
	lock
	msgbox MonitoringStation_Power_Text_Honey2
	closemessage
	setvar VAR_HONEY2, 1
	end
	
MonitoringStation_Power_EventScript_Mom::
	lock
	faceplayer
	msgbox MonitoringStation_Power_Text_Mom
	closemessage
	release
	end
	
MonitoringStation_Power_EventScript_Giovanni::
	lock
	faceplayer
	msgbox MonitoringStation_Power_Text_Giovanni
	closemessage
	playmoncry SPECIES_MEWTWO, 2
	release
	end
	
MonitoringStation_Power_EventScript_Restore_Power::
	lock
	goto_if_set FLAG_HORROR_POWER_RESTORED, MonitoringStation_Power_EventScript_Working
	goto_if_unset FLAG_HORROR_ABSOLUTE, MonitoringStation_Power_EventScript_Absolute
	removeobject LOCALID_MOM
	removeobject LOCALID_GIOVANNI
	removeobject LOCALID_LANCE
	removeobject LOCALID_GYM_SIGN
	playse SE_PC_LOGIN
	delay 60
	playse SE_M_CONFUSE_RAY
	animateflash 0
	setflashlevel 0
	playse SE_SLIDING_DOOR
	setweather WEATHER_NONE
	doweather
	delay 60
	msgbox MonitoringStation_Power_Text_Restore_Power
	waitmessage
	setflag FLAG_HIDE_HORROR_NPC
	setflag FLAG_HORROR_POWER_RESTORED
	setvar VAR_MONITORING_STATION_HALLWAY2_HELP, 1
	setvar VAR_TAKEKEY, 0
	fadeinbgm 1
	release
	end
	
MonitoringStation_Power_EventScript_Absolute::
	playbgm MUS_DUMMY, 0
	playmoncry SPECIES_KABUTOPS, 4
	waitmoncry
	applymovement LOCALID_KABUTOPS_SHADOW, MonitoringStation_Power_Movement_Jump
	delay 20
	fadescreen FADE_TO_BLACK
	fadeinbgm 1
	formatwarp MAP_POKE_CENTER, 255, 8, 5
	release
	end
	
MonitoringStation_Power_EventScript_Working::
	msgbox MonitoringStation_Power_Text_Working
	waitmessage
	release
	end
	
MonitoringStation_Power_Movement_Jump::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end