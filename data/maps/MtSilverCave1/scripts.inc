MtSilverCave1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilverCave1_OnTransition
	.byte 0

MtSilverCave1_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MT_SILVER_CAVE
	end