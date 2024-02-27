.set LOCALID_ROCKET_F1, 1
.set LOCALID_ROCKET_M1, 2
.set LOCALID_ROCKET_M2, 3
.set LOCALID_ROCKET_M3, 4
.set LOCALID_ROCKET_F2, 5
.set LOCALID_ROCKET_M4, 6

MonitoringStation_Quarters_MapScripts::
	.byte 0

MonitoringStation_Quarters_EventScript_RocketM1::
	lock
	faceplayer
	msgbox MonitoringStation_Quarters_Text_RocketM1
	waitmessage
	release
	end
	
MonitoringStation_Quarters_EventScript_RocketM2::
	lock
	faceplayer
	msgbox MonitoringStation_Quarters_Text_RocketM2
	waitmessage
	release
	end
	
MonitoringStation_Quarters_EventScript_RocketM3::
	lock
	faceplayer
	setvar VAR_MAP_SCENE_MONITORING_STATION_CENTRAL, 1
	msgbox MonitoringStation_Quarters_Text_RocketM3
	closemessage
	setvar VAR_MONITORING_STATION_QUARTET, 1
	setflag FLAG_QUARTET_ACTIVE
	clearflag FLAG_HIDE_CHONKDUO
	formatwarp MAP_MONITORING_STATION_CENTRAL, 255, 15, 5
	release
	end

MonitoringStation_Quarters_EventScript_RocketM4::
	lock
	faceplayer
	msgbox MonitoringStation_Quarters_Text_RocketM4
	waitmessage
	release
	end
	
MonitoringStation_Quarters_EventScript_RocketF1::
	lock
	faceplayer
	goto_if_set FLAG_HORROR_DONE, MonitoringStation_Quarters_EventScript_Funny
	msgbox MonitoringStation_Quarters_Text_RocketF1
	waitmessage
	release
	end

MonitoringStation_Quarters_EventScript_Funny::
	msgbox MonitoringStation_Quarters_Text_Funny
	waitmessage
	release
	end
	
MonitoringStation_Quarters_EventScript_RocketF2::
	lock
	faceplayer
	msgbox MonitoringStation_Quarters_Text_RocketF2
	waitmessage
	release
	end
