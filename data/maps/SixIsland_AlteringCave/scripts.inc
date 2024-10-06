.equ LOCALID_MURAL, 1

SixIsland_AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_AlteringCave_OnTransition
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_AlteringCave_OnLoad
	.byte 0

SixIsland_AlteringCave_OnLoad::
	goto_if_set FLAG_HIDE_MURAL, SixIsland_AlteringCave_EventScript_SetWarp
	end
	
SixIsland_AlteringCave_EventScript_SetWarp::
	setmetatile 4, 12, METATILE_RockTunnel_TopLeft, 0
	setmetatile 5, 12, METATILE_RockTunnel_Top, 0
	setmetatile 6, 12, METATILE_RockTunnel_TopRight, 0
	setmetatile 6, 13, METATILE_RockTunnel_Right, 0
	setmetatile 6, 14, METATILE_RockTunnel_BottomRight, 0
	setmetatile 5, 14, METATILE_RockTunnel_Bottom, 0
	setmetatile 4, 14, METATILE_RockTunnel_BottomLeft, 0
	setmetatile 4, 13, METATILE_RockTunnel_Left, 0
	setmetatile 5, 13, METATILE_RockTunnel_Hole, 0
	setmetatile 6, 4, METATILE_RockTunnel_Spot, 0
	end

SixIsland_AlteringCave_OnTransition::
	goto_if_unset FLAG_WORLD_MAP_SIX_ISLAND_ALTERING_CAVE, Mystery_Man_Trigger
	end
	
	Mystery_Man_Trigger::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND_ALTERING_CAVE
	clearflag FLAG_MYSTERY_MAN_GONE
	end
