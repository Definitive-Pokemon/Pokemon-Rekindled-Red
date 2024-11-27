NewBarkTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_OnTransition
	.byte 0

NewBarkTown_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_NEW_BARK_TOWN
	end

