SevenIsland_TanobyRuins_MoneanChamber_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TanobyRuins_MoneanChamber_OnTransition
	.byte 0

SevenIsland_TanobyRuins_MoneanChamber_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER
	call EventScript_TryDarkenRuins
	end

SevenIsland_TanobyRuins_MoneanChamber_EventScript_RegirockCheck::
	lockall
	setvar VAR_0x8004, SPECIES_REGIROCK
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, TRUE, 
SevenIsland_TanobyRuins_MoneanChamber_EventScript_RegiceCheck::
	setvar VAR_0x8004, SPECIES_REGICE
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, TRUE, 
SevenIsland_TanobyRuins_MoneanChamber_EventScript_RegisteelCheck::
	setvar VAR_0x8004, SPECIES_REGISTEEL
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, TRUE, 
SevenIsland_TanobyRuins_MoneanChamber_EventScript_OpenDoor::
	delay 20
	playse SE_DOOR
	setmetatile 7, 0, METATILE_TanobyRuins_DoorTopLeft, 1
	setmetatile 8, 0, METATILE_TanobyRuins_DoorTopCenter, 1
	setmetatile 9, 0, METATILE_TanobyRuins_DoorTopRight, 1
	setmetatile 7, 1, METATILE_TanobyRuins_DoorBottomLeft, 1
	setmetatile 8, 1, METATILE_TanobyRuins_DoorBottomCenter, 0
	setmetatile 9, 1, METATILE_TanobyRuins_DoorBottomRight, 1
	setmetatile 13, 0, METATILE_TanobyRuins_DoorTopLeft, 1
	setmetatile 14, 0, METATILE_TanobyRuins_DoorTopCenter, 1
	setmetatile 15, 0, METATILE_TanobyRuins_DoorTopRight, 1
	setmetatile 13, 1, METATILE_TanobyRuins_DoorBottomLeft, 1
	setmetatile 14, 1, METATILE_TanobyRuins_DoorBottomCenter, 0
	setmetatile 15, 1, METATILE_TanobyRuins_DoorBottomRight, 1
	waitse
	special DrawWholeMapView
	setvar VAR_REGICHECK, 2
	releaseall
	end
	