Debug_MapScripts::
	.byte 0

Green_Give_RainbowWing_Debug::
	lock
	giveitem_msg MtSilverPeak_Text_ReceivedRainbowWingGreen, ITEM_RAINBOW_WING, 1
	release
	end

Debug_Text::
    .string "I AM NO ERROR$"

Debug_UnlockGame::
	@unlock all fly locations
	setflag FLAG_WORLD_MAP_PALLET_TOWN
	setflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	setflag FLAG_WORLD_MAP_PEWTER_CITY
	setflag FLAG_WORLD_MAP_CERULEAN_CITY
	setflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setflag FLAG_WORLD_MAP_VERMILION_CITY
	setflag FLAG_WORLD_MAP_CELADON_CITY
	setflag FLAG_WORLD_MAP_FUCHSIA_CITY
	setflag FLAG_WORLD_MAP_CINNABAR_ISLAND
	setflag FLAG_WORLD_MAP_INDIGO_PLATEAU_EXTERIOR
	setflag FLAG_WORLD_MAP_SAFFRON_CITY
	setflag FLAG_WORLD_MAP_ONE_ISLAND
	setflag FLAG_WORLD_MAP_TWO_ISLAND
	setflag FLAG_WORLD_MAP_THREE_ISLAND
	setflag FLAG_WORLD_MAP_FOUR_ISLAND
	setflag FLAG_WORLD_MAP_FIVE_ISLAND
	setflag FLAG_WORLD_MAP_SEVEN_ISLAND
	setflag FLAG_WORLD_MAP_SIX_ISLAND
	setflag FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F
	setflag FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F
	setflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
	setflag FLAG_WORLD_MAP_MT_MOON_1F
	setflag FLAG_WORLD_MAP_SSANNE_EXTERIOR
	setflag FLAG_WORLD_MAP_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL
	setflag FLAG_WORLD_MAP_UNDERGROUND_PATH_EAST_WEST_TUNNEL
	setflag FLAG_WORLD_MAP_DIGLETTS_CAVE_B1F
	setflag FLAG_WORLD_MAP_VICTORY_ROAD_1F
	setflag FLAG_WORLD_MAP_ROCKET_HIDEOUT_B1F
	setflag FLAG_WORLD_MAP_SILPH_CO_1F
	setflag FLAG_WORLD_MAP_POKEMON_MANSION_1F
	setflag FLAG_WORLD_MAP_SAFARI_ZONE_CENTER
	setflag FLAG_WORLD_MAP_POKEMON_LEAGUE_LORELEIS_ROOM
	setflag FLAG_WORLD_MAP_ROCK_TUNNEL_1F
	setflag FLAG_WORLD_MAP_SEAFOAM_ISLANDS_1F
	setflag FLAG_WORLD_MAP_POKEMON_TOWER_1F
	setflag FLAG_WORLD_MAP_CERULEAN_CAVE_1F
	setflag FLAG_WORLD_MAP_POWER_PLANT
	setflag FLAG_WORLD_MAP_NAVEL_ROCK_EXTERIOR
	setflag FLAG_WORLD_MAP_MT_EMBER_EXTERIOR
	setflag FLAG_WORLD_MAP_THREE_ISLAND_BERRY_FOREST
	setflag FLAG_WORLD_MAP_FOUR_ISLAND_ICEFALL_CAVE_ENTRANCE
	setflag FLAG_WORLD_MAP_FIVE_ISLAND_ROCKET_WAREHOUSE
	setflag FLAG_WORLD_MAP_TRAINER_TOWER_LOBBY
	setflag FLAG_WORLD_MAP_SIX_ISLAND_DOTTED_HOLE_1F
	setflag FLAG_WORLD_MAP_FIVE_ISLAND_LOST_CAVE_ENTRANCE
	setflag FLAG_WORLD_MAP_SIX_ISLAND_PATTERN_BUSH
	setflag FLAG_WORLD_MAP_SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER
	setflag FLAG_WORLD_MAP_THREE_ISLAND_DUNSPARCE_TUNNEL
	setflag FLAG_WORLD_MAP_SEVEN_ISLAND_SEVAULT_CANYON_TANOBY_KEY
	setflag FLAG_WORLD_MAP_BIRTH_ISLAND_EXTERIOR

	@set all trainer flags
	@special SetAllTrainersBattled

	@give master balls
	giveitem ITEM_MASTER_BALL, 50
	@badges
	giveitem ITEM_TOWN_MAP, 01
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_CERULEAN_CAVE_GUARD
	@HMs
	giveitem ITEM_HM01
	giveitem ITEM_HM02
	giveitem ITEM_HM03
	giveitem ITEM_HM04
	giveitem ITEM_HM05
	giveitem ITEM_HM06
	giveitem ITEM_HM07
	giveitem ITEM_HM08
	end

ArticunoMaxiFlag::
	setflag FLAG_MAXIMUS_SEAFOAM
	end
	
ZapdosMaxiFlag::
	setflag FLAG_SEEN_ZAPDOS
	end
	
MuralJirachiFlag::
	clearflag FLAG_HIDE_MURAL
	end

GiveMewtwo::
	lock
	givemon SPECIES_MEWTWO, 100, ITEM_LEFTOVERS
	release
	end
	
GiveLugia::
	lock
	givemon SPECIES_LUGIA, 100, ITEM_LEFTOVERS
	release
	end
	
GiveHoOh::
	lock
	givemon SPECIES_HO_OH, 100, ITEM_LEFTOVERS
	release
	end
	
GiveRayquaza::
	lock
	givemon SPECIES_RAYQUAZA, 100, ITEM_LEFTOVERS
	release
	end
	
GiveKyogre::
	lock
	givemon SPECIES_KYOGRE, 100, ITEM_LEFTOVERS
	release
	end
	
GiveGroudon::
	lock
	givemon SPECIES_GROUDON, 100, ITEM_LEFTOVERS
	release
	end
	
GiveRock::
	lock
	givemon SPECIES_REGIROCK, 100, ITEM_LEFTOVERS
	release
	givemon SPECIES_MOLTRES, 100, ITEM_LEFTOVERS
	end
	
GiveIce::
	lock
	givemon SPECIES_REGICE, 100, ITEM_LEFTOVERS
	release
	end
	
GiveSteel::
	lock
	givemon SPECIES_REGISTEEL, 100, ITEM_LEFTOVERS
	release
	end
	
GiveMasterBall::
	lock
	giveitem ITEM_MASTER_BALL, 99
	givemon SPECIES_FOSSILIZED_KABUTOPS, 100, ITEM_LEFTOVERS
	givemon SPECIES_SEVIIAN_AERODACTYL, 100, ITEM_LEFTOVERS
	givemon SPECIES_BLASTOISE, 100, ITEM_LEFTOVERS
	givemon SPECIES_CHARIZARD, 100, ITEM_LEFTOVERS
	givemon SPECIES_VENUSAUR, 100, ITEM_LEFTOVERS
	release
	end
	
GiveLetter::
	lock
	giveitem ITEM_LETTER
	clearflag FLAG_MOM_GONE_DOWN
	setflag FLAG_OAK_HAS_LETTER
	release
	end
	
Debug_Sapphire::
	lock
	giveitem ITEM_SAPPHIRE
	release
	end
	
Debug_Ruby::
	lock
	giveitem ITEM_RUBY
	release
	end
	
Debug_Emerald::
	lock
	giveitem ITEM_EMERALD
	release
	end

Debug_GiveAllKeyItems::
	lock
	giveitem ITEM_LETTER
	giveitem ITEM_RUBY
	giveitem ITEM_SAPPHIRE
	giveitem ITEM_EMERALD
	giveitem ITEM_METEORITE
	giveitem ITEM_RAINBOW_WING
	giveitem ITEM_COIN_CASE
	giveitem ITEM_ITEMFINDER
	giveitem ITEM_OLD_ROD
	giveitem ITEM_GOOD_ROD
	giveitem ITEM_SUPER_ROD
	giveitem ITEM_SS_TICKET
	giveitem ITEM_BLUE_KEY
	giveitem ITEM_YELLOW_KEY
	giveitem ITEM_RED_KEY
	giveitem ITEM_SHINY_RADAR
	giveitem ITEM_OAKS_PARCEL
	giveitem ITEM_POKE_FLUTE
	giveitem ITEM_EON_TICKET
	giveitem ITEM_SECRET_KEY
	giveitem ITEM_BIKE_VOUCHER
	giveitem ITEM_GOLD_TEETH
	giveitem ITEM_OLD_AMBER
	giveitem ITEM_CARD_KEY
	giveitem ITEM_LIFT_KEY
	giveitem ITEM_HELIX_FOSSIL
	giveitem ITEM_DOME_FOSSIL
	giveitem ITEM_SILPH_SCOPE
	giveitem ITEM_BICYCLE
	giveitem ITEM_TOWN_MAP
	giveitem ITEM_FAME_CHECKER
	giveitem ITEM_TEACHY_TV
	giveitem ITEM_TRI_PASS
	giveitem ITEM_TEA
	giveitem ITEM_MYSTIC_TICKET
	giveitem ITEM_AURORA_TICKET
	giveitem ITEM_OLD_SEA_MAP
	giveitem ITEM_LINK_BRACELET
	release
	end

Debug_GiveOtherKeyItems::
	lock
	giveitem ITEM_COIN_CASE
	giveitem ITEM_ITEMFINDER
	giveitem ITEM_OLD_ROD
	giveitem ITEM_GOOD_ROD
	giveitem ITEM_SUPER_ROD
	giveitem ITEM_SS_TICKET
	giveitem ITEM_BLUE_KEY
	giveitem ITEM_YELLOW_KEY
	giveitem ITEM_RED_KEY
	giveitem ITEM_SHINY_RADAR
	giveitem ITEM_OAKS_PARCEL
	giveitem ITEM_POKE_FLUTE
	giveitem ITEM_EON_TICKET
	giveitem ITEM_SECRET_KEY
	giveitem ITEM_BIKE_VOUCHER
	giveitem ITEM_GOLD_TEETH
	giveitem ITEM_OLD_AMBER
	giveitem ITEM_CARD_KEY
	giveitem ITEM_LIFT_KEY
	giveitem ITEM_HELIX_FOSSIL
	giveitem ITEM_DOME_FOSSIL
	giveitem ITEM_SILPH_SCOPE
	giveitem ITEM_BICYCLE
	giveitem ITEM_TOWN_MAP
	giveitem ITEM_FAME_CHECKER
	giveitem ITEM_TEACHY_TV
	giveitem ITEM_TRI_PASS
	giveitem ITEM_TEA
	giveitem ITEM_MYSTIC_TICKET
	giveitem ITEM_AURORA_TICKET
	giveitem ITEM_OLD_SEA_MAP
	giveitem ITEM_LINK_BRACELET
	release
	end

Debug_GiveMeteorite::
	lock
	giveitem ITEM_METEORITE
	release
	end

Debug_RemoveKeyItemsSane::
	removeitem ITEM_LETTER
	removeitem ITEM_RUBY
	removeitem ITEM_SAPPHIRE
	removeitem ITEM_EMERALD
	removeitem ITEM_METEORITE
	removeitem ITEM_RAINBOW_WING
	removeitem ITEM_COIN_CASE
	removeitem ITEM_ITEMFINDER
	removeitem ITEM_OLD_ROD
	removeitem ITEM_GOOD_ROD
	removeitem ITEM_SUPER_ROD
	removeitem ITEM_SS_TICKET
	removeitem ITEM_BLUE_KEY
	removeitem ITEM_YELLOW_KEY
	removeitem ITEM_RED_KEY
	removeitem ITEM_SHINY_RADAR
	removeitem ITEM_OAKS_PARCEL
	removeitem ITEM_POKE_FLUTE
	removeitem ITEM_EON_TICKET
	removeitem ITEM_SECRET_KEY
	removeitem ITEM_BIKE_VOUCHER
	removeitem ITEM_GOLD_TEETH
	removeitem ITEM_OLD_AMBER
	removeitem ITEM_CARD_KEY
	removeitem ITEM_LIFT_KEY
	removeitem ITEM_HELIX_FOSSIL
	removeitem ITEM_DOME_FOSSIL
	removeitem ITEM_SILPH_SCOPE
	removeitem ITEM_BICYCLE
	removeitem ITEM_TOWN_MAP
	removeitem ITEM_FAME_CHECKER
	removeitem ITEM_TEACHY_TV
	removeitem ITEM_TRI_PASS
	removeitem ITEM_TEA
	removeitem ITEM_MYSTIC_TICKET
	removeitem ITEM_AURORA_TICKET
	removeitem ITEM_OLD_SEA_MAP
	removeitem ITEM_LINK_BRACELET
	playse SE_FAILURE
	end

Debug_RemoveLetter::
	removeitem ITEM_LETTER
	playse SE_FAILURE
	end

Debug_RemoveRuby::
	removeitem ITEM_RUBY
	playse SE_FAILURE
	end

Debug_RemoveSapphire::
	removeitem ITEM_SAPPHIRE
	playse SE_FAILURE
	end

Debug_RemoveEmerald::
	removeitem ITEM_EMERALD
	playse SE_FAILURE
	end

Debug_RemoveMeteorite::
	removeitem ITEM_METEORITE
	playse SE_FAILURE
	end

Debug_RemoveRainbowWing::
	removeitem ITEM_RAINBOW_WING
	playse SE_FAILURE
	end


Daisy::
	setflag FLAG_HIDE_DAISY
	end