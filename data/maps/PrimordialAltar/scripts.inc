.set LOCALID_SAPPHIRE, 1
.set LOCALID_RUBY, 2
.set LOCALID_EMERALD, 3

PrimordialAltar_MapScripts::
	.byte 0

PrimordialAltar_EventScript_Altar::
	lockall
	message PrimordialAltar_Text_Altar
	waitmessage
	checkitem ITEM_SAPPHIRE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PrimordialAltar_EventScript_Altar_SapphireOnly
	checkitem ITEM_RUBY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PrimordialAltar_EventScript_Altar_RubyOnly
	checkitem ITEM_EMERALD, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PrimordialAltar_EventScript_Altar_EmeraldOnly
	multichoice 19, 5, MULTICHOICE_NO_STONES, FALSE
	switch VAR_RESULT
	case 127, EventScript_PlaceNothing
	end

PrimordialAltar_EventScript_Altar_SapphireOnly::
	checkitem ITEM_RUBY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PrimordialAltar_EventScript_Altar_SapphireRuby
	checkitem ITEM_EMERALD, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PrimordialAltar_EventScript_Altar_SapphireEmerald
	multichoice 19, 5, MULTICHOICE_SAPPHIRE, FALSE
	case 0, EventScript_PlaceSapphire
	case 127, EventScript_PlaceNothing
	end
	
PrimordialAltar_EventScript_Altar_SapphireRuby::
	checkitem ITEM_EMERALD, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PrimordialAltar_EventScript_Altar_All
	multichoice 19, 5, MULTICHOICE_RUBYSAPPHIRE, FALSE
	case 0, EventScript_PlaceSapphire
	case 1, EventScript_PlaceRuby
	case 127, EventScript_PlaceNothing
	end
	
PrimordialAltar_EventScript_Altar_RubyOnly::
	checkitem ITEM_EMERALD, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PrimordialAltar_EventScript_Altar_RubyEmerald
	multichoice 19, 5, MULTICHOICE_RUBY, FALSE
	case 0, EventScript_PlaceRuby
	case 127, EventScript_PlaceNothing
	end
	
PrimordialAltar_EventScript_Altar_RubyEmerald::
	multichoice 19, 5, MULTICHOICE_RUBYEMERALD, FALSE
	case 0, EventScript_PlaceRuby
	case 1, EventScript_PlaceEmerald
	case 127, EventScript_PlaceNothing
	end
	
PrimordialAltar_EventScript_Altar_EmeraldOnly::
	multichoice 19, 5, MULTICHOICE_EMERALD, FALSE
	case 0, EventScript_PlaceEmerald
	case 127, EventScript_PlaceNothing
	end
	
PrimordialAltar_EventScript_Altar_All::
	multichoice 19, 5, MULTICHOICE_ALLSTONES, FALSE
	switch VAR_RESULT
	case 0, EventScript_PlaceSapphire
	case 1, EventScript_PlaceRuby
	case 2, EventScript_PlaceEmerald
	case 127, EventScript_PlaceNothing
	end
	
EventScript_PlaceSapphire::
	addobject LOCALID_SAPPHIRE
	clearflag FLAG_UNPLACED_SAPPHIRE
	removeitem ITEM_SAPPHIRE, 1
	playse SE_EXP_MAX
	waitse
	message PrimordialAltar_Text_PlacedSapphire
	waitmessage
	warp MAP_MARINE_CAVE, 255, 0, 0
	waitstate
	releaseall
	end

EventScript_PlaceRuby::
	addobject LOCALID_RUBY
	clearflag FLAG_UNPLACED_RUBY
	removeitem ITEM_RUBY, 1
	playse SE_EXP_MAX
	waitse
	message PrimordialAltar_Text_PlacedRuby
	waitmessage
	warp MAP_MARINE_CAVE, 255, 0, 0
	waitstate
	releaseall
	end
	
EventScript_PlaceEmerald::
	addobject LOCALID_EMERALD
	clearflag FLAG_UNPLACED_EMERALD
	removeitem ITEM_EMERALD, 1
	playse SE_EXP_MAX
	waitse
	message PrimordialAltar_Text_PlacedEmerald
	waitmessage
	warp MAP_MARINE_CAVE, 255, 0, 0
	waitstate
	releaseall
	end
	
EventScript_PlaceNothing::
	releaseall
	end

PrimordialAltar_Text_Altar::
	.string "PLACE ALTAR.$"

PrimordialAltar_Text_PlacedSapphire::
	.string "PLACED SAPPHIRE.$"
	
PrimordialAltar_Text_PlacedRuby::
	.string "PLACED RUBY.$"
	
PrimordialAltar_Text_PlacedEmerald::
	.string "PLACED EMERALD.$"