.set LOCALID_CAGE1, 1
.set LOCALID_CAGE2, 2

MonitoringStation_Pokemon_MapScripts::
	.byte 0
	
MonitoringStation_Pokemon_EventScript_SetDoorRemove::
	setmetatile 5, 1, METATILE_SilphCo_Wall_Upper, 1
	setmetatile 6, 1, METATILE_SilphCo_Wall_Upper, 1
	setmetatile 7, 1, METATILE_SilphCo_Wall_Upper, 1
	setmetatile 5, 2, METATILE_SilphCo_Wall_Lower, 1
	setmetatile 6, 2, METATILE_SilphCo_Wall_Lower, 1
	setmetatile 7, 2, METATILE_SilphCo_Wall_Lower, 1
	special DrawWholeMapView
	setvar VAR_REMOVE_DOOR, 1
	setvar VAR_ADD_CAGE, 1
	end
	
MonitoringStation_Pokemon_EventScript_AddCage::
	setmetatile 5, 12, METATILE_SilphCo_Cage1, 1
	setmetatile 6, 12, METATILE_SilphCo_Cage2, 1
	setmetatile 5, 13, METATILE_SilphCo_Cage3, 1
	setmetatile 6, 13, METATILE_SilphCo_Cage4, 1
	setmetatile 7, 13, METATILE_SilphCo_CageShadow3, 0
	setmetatile 5, 14, METATILE_SilphCo_CageShadow1, 0
	setmetatile 6, 14, METATILE_SilphCo_CageShadow1, 0
	setmetatile 7, 14, METATILE_SilphCo_CageShadow2, 0
	addobject LOCALID_CAGE1
	addobject LOCALID_CAGE2
	clearflag FLAG_HIDE_CAGE
	setvar VAR_ADD_CAGE, 2
	end
	
MonitoringStation_Pokemon_EventScript_Cage1::
	lockall
	textcolor 2
	msgbox MonitoringStation_Pokemon_Text_PutYourselfInCage, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MonitoringStation_Pokemon_EventScript_GoInCage1
	releaseall
	end
	
MonitoringStation_Pokemon_EventScript_Cage2::
	lockall
	textcolor 2
	msgbox MonitoringStation_Pokemon_Text_PutYourselfInCage, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MonitoringStation_Pokemon_EventScript_GoInCage2
	releaseall
	end
	
MonitoringStation_Pokemon_EventScript_GoInCage1::
	msgbox MonitoringStation_Pokemon_Text_StepInCage
	closemessage
	formatwarp MAP_SPECIAL, 255, 0, 0
	waitstate
	releaseall
	end
	
MonitoringStation_Pokemon_EventScript_GoInCage2::
	msgbox MonitoringStation_Pokemon_Text_StepInCage
	closemessage
	formatwarp MAP_SPECIAL, 255, 1, 0
	waitstate
	releaseall
	end

MonitoringStation_Pokemon_EventScript_Aggron::
	lock
	playmoncry SPECIES_AGGRON, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Shiftry::
	lock
	playmoncry SPECIES_SHIFTRY, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Rhydon::
	lock
	playmoncry SPECIES_RHYDON, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Typhlosion::
	lock
	playmoncry SPECIES_TYPHLOSION, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Walrein::
	lock
	playmoncry SPECIES_WALREIN, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Gardevoir::
	lock
	playmoncry SPECIES_GARDEVOIR, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Altaria::
	lock
	playmoncry SPECIES_ALTARIA, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Tauros::
	lock
	playmoncry SPECIES_TAUROS, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Ampharos::
	lock
	playmoncry SPECIES_AMPHAROS, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Cacturne::
	lock
	playmoncry SPECIES_CACTURNE, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Houndoom::
	lock
	playmoncry SPECIES_HOUNDOOM, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end

MonitoringStation_Pokemon_EventScript_Kangaskhan::
	lock
	playmoncry SPECIES_KANGASKHAN, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end
	
MonitoringStation_Pokemon_EventScript_Sharpedo::
	lock
	playmoncry SPECIES_SHARPEDO, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end
	
MonitoringStation_Pokemon_EventScript_Milotic::
	lock
	playmoncry SPECIES_MILOTIC, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end
	
MonitoringStation_Pokemon_EventScript_Starmie::
	lock
	playmoncry SPECIES_STARMIE, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end
	
MonitoringStation_Pokemon_EventScript_Wailmer::
	lock
	playmoncry SPECIES_WAILMER, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end
	
MonitoringStation_Pokemon_EventScript_Luvdisc::
	lock
	playmoncry SPECIES_LUVDISC, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end
	
MonitoringStation_Pokemon_EventScript_Gorebyss::
	lock
	playmoncry SPECIES_GOREBYSS, 4
	waitmoncry
	msgbox MonitoringStation_Pokemon_Text_Scared
	waitmessage
	release
	end
	
MonitoringStation_Pokemon_EventScript_Text::
	goto_if_unset FLAG_HIDE_CAGE, MonitoringStation_Pokemon_EventScript_Text2
	msgbox MonitoringStation_Pokemon_Text_Text, MSGBOX_SIGN
	end
	
MonitoringStation_Pokemon_EventScript_Text2::
	msgbox MonitoringStation_Pokemon_Text_Text2, MSGBOX_SIGN
	end