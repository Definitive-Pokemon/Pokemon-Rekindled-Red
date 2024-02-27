.set LOCALID_ROCKET_M1, 1
.set LOCALID_SCIENTIST1, 2
.set LOCALID_ROCKET_M2, 3
.set LOCALID_ROCKET_F1, 4
.set LOCALID_ROCKET_M3, 5
.set LOCALID_SCIENTIST2, 6
.set LOCALID_ROCKET_M4, 7
.set LOCALID_ROCKET_F2, 8

MonitoringStation_ConferenceRoom_MapScripts::
	.byte 0

MonitoringStation_ConferenceRoom_EventScript_RocketM1::
	lock
	faceplayer
	msgbox MonitoringStation_ConferenceRoom_Text_RocketM1
	waitmessage
	release
	end
	
MonitoringStation_ConferenceRoom_EventScript_RocketM2::
	lock
	faceplayer
	msgbox MonitoringStation_ConferenceRoom_Text_RocketM2
	waitmessage
	release
	end
	
MonitoringStation_ConferenceRoom_EventScript_RocketM3::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLUE_KEY, MonitoringStation_ConferenceRoom_EventScript_RocketM33
	msgbox MonitoringStation_ConferenceRoom_Text_RocketM3
	waitmessage
	giveitem_msg MonitoringStation_ConferenceRoom_Text_ObtainedBlueKey, ITEM_BLUE_KEY
	setflag FLAG_GOT_BLUE_KEY
	setflag FLAG_HIDE_ADMIN2
	setflag FLAG_HIDE_STORAGE_GRUNT
	clearflag FLAG_HIDE_ENTRANCE_PEOPLE
	clearflag FLAG_HIDE_BOULDER3
	setflag FLAG_HIDE_BOULDER2
	setvar VAR_ADMIN_CONVO, 1
	msgbox MonitoringStation_ConferenceRoom_Text_RocketM32
	waitmessage
	release
	end
	
MonitoringStation_ConferenceRoom_EventScript_RocketM33::
	msgbox MonitoringStation_ConferenceRoom_Text_RocketM32
	waitmessage
	release
	end

MonitoringStation_ConferenceRoom_EventScript_RocketF1::
	lock
	faceplayer
	msgbox MonitoringStation_ConferenceRoom_Text_RocketF1
	waitmessage
	release
	end
	
MonitoringStation_ConferenceRoom_EventScript_RocketF2::
	lock
	faceplayer
	msgbox MonitoringStation_ConferenceRoom_Text_RocketF2
	waitmessage
	release
	end
	
MonitoringStation_ConferenceRoom_EventScript_Scientist1::
	lock
	faceplayer
	msgbox MonitoringStation_ConferenceRoom_Text_Scientist1
	waitmessage
	release
	end
	
MonitoringStation_ConferenceRoom_EventScript_Scientist2::
	lock
	faceplayer
	msgbox MonitoringStation_ConferenceRoom_Text_Scientist2
	waitmessage
	release
	end
	
MonitoringStation_ConferenceRoom_EventScript_RocketM4::
	lock
	msgbox MonitoringStation_ConferenceRoom_Text_RocketM4
	waitmessage
	release
	end
	
MonitoringStation_ConferenceRoom_EventScript_Text::
	msgbox MonitoringStation_ConferenceRoom_Text_Text, MSGBOX_SIGN
	end