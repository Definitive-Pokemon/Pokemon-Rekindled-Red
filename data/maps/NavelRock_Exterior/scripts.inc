NavelRock_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Exterior_OnTransition
	.byte 0

NavelRock_Exterior_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_NAVEL_ROCK_EXTERIOR
	end

NavelRock_Exterior_EventScript_Maximus::
	lock
	faceplayer
	setflag FLAG_ELM_NAVEL
	release
	end