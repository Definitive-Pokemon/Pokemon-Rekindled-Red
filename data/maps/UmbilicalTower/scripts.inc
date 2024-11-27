UmbilicalTower_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, UmbilicalTower_OnTransition
	.byte 0

UmbilicalTower_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_UMBILICAL_TOWER
	end
	