MtSilverPokeCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilverPokeCenter_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, PokemonCenter_1F_OnLoad
	.byte 0

MtSilverPokeCenter_OnTransition::
	setrespawn SPAWN_MT_SILVER
	end

MtSilverPokeCenter_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end
