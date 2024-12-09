TwoIsland_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwoIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, PokemonCenter_1F_OnLoad
	.byte 0

TwoIsland_PokemonCenter_1F_OnTransition::
	setrespawn SPAWN_TWO_ISLAND
	end

TwoIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

TwoIsland_PokemonCenter_1F_EventScript_GBAKid::
	msgbox TwoIsland_PokemonCenter_1F_Text_HaveYouVisitedGameCorner, MSGBOX_NPC
	end

TwoIsland_PokemonCenter_1F_EventScript_BugCatcher::
	msgbox TwoIsland_PokemonCenter_1F_Text_OldLadyLivesOutOnCape, MSGBOX_NPC
	end

TwoIsland_PokemonCenter_1F_EventScript_OldWoman::
	msgbox TwoIsland_PokemonCenter_1F_Text_Umbilical_Tower, MSGBOX_NPC
	end

TwoIsland_PokemonCenter_1F_Text_Umbilical_Tower::
	.string "Say, do you travel a lot?\p"
	.string "I used to explore the world all\n"
	.string "the time when I was younger.\p"
	.string "So many mysteries, so many\n"
	.string "great discoveries…\p"
	.string "One mystery in particular\n"
	.string "stood out.\p"
	.string "That mystery still rises high\n"
	.string "into the skies to this day.\p"
	.string "I am talking about the UMBILICAL\n"
	.string "TOWER located south of here.\p"
	.string "It is a shrine dedicated to a\n"
	.string "flying, legendary POKéMON.\p"
	.string "But strangely, no one has ever\n"
	.string "seen it anywhere near that tower.$"