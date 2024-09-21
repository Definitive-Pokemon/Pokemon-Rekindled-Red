SixIsland_AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_AlteringCave_OnTransition
	.byte 0

SixIsland_AlteringCave_OnTransition::
	goto_if_unset FLAG_WORLD_MAP_SIX_ISLAND_ALTERING_CAVE, Mystery_Man_Trigger
	end
	
	Mystery_Man_Trigger::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND_ALTERING_CAVE
	clearflag FLAG_MYSTERY_MAN_GONE
	end
