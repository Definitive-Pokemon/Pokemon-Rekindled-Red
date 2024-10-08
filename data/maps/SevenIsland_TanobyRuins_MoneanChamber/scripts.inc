SevenIsland_TanobyRuins_MoneanChamber_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SevenIsland_TanobyRuins_MoneanChamber_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TanobyRuins_MoneanChamber_OnTransition
	.byte 0

SevenIsland_TanobyRuins_MoneanChamber_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER
	call EventScript_TryDarkenRuins
	end

SevenIsland_TanobyRuins_MoneanChamber_OnLoad::
	goto_if_set FLAG_SYS_UNLOCKED_TANOBY_RUINS, SevenIsland_TanobyRuins_MoneanChamber_EventScript_OpenDoors
	end

SevenIsland_TanobyRuins_MoneanChamber_EventScript_OpenDoors::
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
	end