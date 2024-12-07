MtSilver_PokeCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_PokeCenter_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, PokemonCenter_1F_OnLoad
	.byte 0

MtSilver_PokeCenter_OnTransition::
	setrespawn SPAWN_MT_SILVER
	end

MtSilver_PokeCenter_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end
