.set LOCALID_SAPPHIRE, 1
.set LOCALID_RUBY, 2
.set LOCALID_EMERALD, 3

PrimordialAltar_MapScripts::
	.byte 0

PrimordialAltar_EventScript_Altar::
	lockall
	msgbox PrimordialAltar_Text_Altar1
	goto_if_unset FLAG_UNPLACED_SAPPHIRE, PrimordialAltar_EventScript_RemoveSapphire
	goto_if_unset FLAG_UNPLACED_RUBY, PrimordialAltar_EventScript_RemoveRuby
	goto_if_unset FLAG_UNPLACED_EMERALD, PrimordialAltar_EventScript_RemoveEmerald
	checkitem ITEM_SAPPHIRE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PrimordialAltar_EventScript_Altar_SapphireOnly
	checkitem ITEM_RUBY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PrimordialAltar_EventScript_Altar_RubyOnly
	checkitem ITEM_EMERALD, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PrimordialAltar_EventScript_Altar_EmeraldOnly
	setflag FLAG_CHECKED_ALTAR
	releaseall	
	end
	
PrimordialAltar_EventScript_RemoveSapphire::
	msgbox PrimordialAltar_Text_RemoveSapphire, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PrimordialAltar_EventScript_DontRemoveSapphire
	removeobject LOCALID_SAPPHIRE
	setflag FLAG_UNPLACED_SAPPHIRE
	giveitem ITEM_SAPPHIRE, 1
	setvar VAR_0x8006, 4
	setdynamicwarp MAP_ONE_ISLAND_TREASURE_BEACH, 255, 30, 29
	releaseall
	end
	
PrimordialAltar_EventScript_DontRemoveSapphire::
	msgbox PrimordialAltar_Text_DontRemoveSapphire
	releaseall
	end
	
PrimordialAltar_EventScript_RemoveRuby::
	msgbox PrimordialAltar_Text_RemoveRuby, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PrimordialAltar_EventScript_DontRemoveRuby
	removeobject LOCALID_RUBY
	setflag FLAG_UNPLACED_RUBY
	giveitem ITEM_RUBY, 1
	setvar VAR_0x8006, 4
	setdynamicwarp MAP_ONE_ISLAND_TREASURE_BEACH, 255, 30, 29
	releaseall
	end
	
PrimordialAltar_EventScript_DontRemoveRuby::
	msgbox PrimordialAltar_Text_DontRemoveRuby
	releaseall
	end
	
PrimordialAltar_EventScript_RemoveEmerald::
	msgbox PrimordialAltar_Text_RemoveEmerald, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PrimordialAltar_EventScript_DontRemoveEmerald
	removeobject LOCALID_EMERALD
	setflag FLAG_UNPLACED_EMERALD
	giveitem ITEM_EMERALD, 1
	setvar VAR_0x8006, 4
	setdynamicwarp MAP_ONE_ISLAND_TREASURE_BEACH, 255, 30, 29
	releaseall
	end
	
PrimordialAltar_EventScript_DontRemoveEmerald::
	msgbox PrimordialAltar_Text_DontRemoveEmerald
	releaseall
	end

PrimordialAltar_EventScript_Altar_SapphireOnly::
	checkitem ITEM_RUBY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PrimordialAltar_EventScript_Altar_SapphireRuby
	checkitem ITEM_EMERALD, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PrimordialAltar_EventScript_Altar_SapphireEmerald
	msgbox PrimordialAltar_Text_Altar2
	multichoice 19, 5, MULTICHOICE_SAPPHIRE, FALSE
	switch VAR_RESULT
	case 0, EventScript_PlaceSapphire
	case 127, EventScript_PlaceNothing
	end
	
PrimordialAltar_EventScript_Altar_SapphireRuby::
	checkitem ITEM_EMERALD, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PrimordialAltar_EventScript_Altar_All
	msgbox PrimordialAltar_Text_Altar2
	multichoice 19, 5, MULTICHOICE_RUBYSAPPHIRE, FALSE
	switch VAR_RESULT
	case 0, EventScript_PlaceRuby
	case 1, EventScript_PlaceSapphire
	case 127, EventScript_PlaceNothing
	end
	
PrimordialAltar_EventScript_Altar_RubyOnly::
	checkitem ITEM_EMERALD, 1
	compare VAR_RESULT, TRUE
	goto_if_eq PrimordialAltar_EventScript_Altar_RubyEmerald
	msgbox PrimordialAltar_Text_Altar2
	multichoice 19, 5, MULTICHOICE_RUBY, FALSE
	switch VAR_RESULT
	case 0, EventScript_PlaceRuby
	case 127, EventScript_PlaceNothing
	end
	
PrimordialAltar_EventScript_Altar_RubyEmerald::
	msgbox PrimordialAltar_Text_Altar2
	multichoice 19, 5, MULTICHOICE_RUBYEMERALD, FALSE
	switch VAR_RESULT
	case 0, EventScript_PlaceRuby
	case 1, EventScript_PlaceEmerald
	case 127, EventScript_PlaceNothing
	end
	
PrimordialAltar_EventScript_Altar_SapphireEmerald::
	msgbox PrimordialAltar_Text_Altar2
	multichoice 19, 5, MULTICHOICE_SAPPHIREEMERALD, FALSE
	switch VAR_RESULT
	case 0, EventScript_PlaceRuby
	case 1, EventScript_PlaceEmerald
	case 127, EventScript_PlaceNothing
	end
	end

PrimordialAltar_EventScript_Altar_EmeraldOnly::
	msgbox PrimordialAltar_Text_Altar2
	multichoice 19, 5, MULTICHOICE_EMERALD, FALSE
	switch VAR_RESULT
	case 0, EventScript_PlaceEmerald
	case 127, EventScript_PlaceNothing
	end
	
PrimordialAltar_EventScript_Altar_All::
	msgbox PrimordialAltar_Text_Altar2
	multichoice 19, 5, MULTICHOICE_ALLSTONES, FALSE
	switch VAR_RESULT
	case 0, EventScript_PlaceRuby
	case 1, EventScript_PlaceSapphire
	case 2, EventScript_PlaceEmerald
	case 127, EventScript_PlaceNothing
	end
	
EventScript_PlaceSapphire::
	addobject LOCALID_SAPPHIRE
	clearflag FLAG_UNPLACED_SAPPHIRE
	removeitem ITEM_SAPPHIRE, 1
	playse SE_EXP_MAX
	waitse
	msgbox PrimordialAltar_Text_PlacedSapphire
	setvar VAR_0x8006, 1
	setdynamicwarp MAP_MARINE_CAVE, 255, 20, 4
	releaseall
	end

EventScript_PlaceRuby::
	addobject LOCALID_RUBY
	clearflag FLAG_UNPLACED_RUBY
	removeitem ITEM_RUBY, 1
	playse SE_EXP_MAX
	waitse
	msgbox PrimordialAltar_Text_PlacedRuby
	setvar VAR_0x8006, 2
	setdynamicwarp MAP_TERRA_CAVE, 255, 5, 4
	releaseall
	end
	
EventScript_PlaceEmerald::
	addobject LOCALID_EMERALD
	clearflag FLAG_UNPLACED_EMERALD
	removeitem ITEM_EMERALD, 1
	playse SE_EXP_MAX
	waitse
	msgbox PrimordialAltar_Text_PlacedEmerald
	setvar VAR_0x8006, 3
	setdynamicwarp MAP_TRAINER_TOWER_LOBBY, 255, 17, 8
	releaseall
	end
	
EventScript_PlaceNothing::
	msgbox PrimordialAltar_Text_PlacedNothing
	releaseall
	end

PrimordialAltar_Text_Altar1::
	.string "This altar looks peculiar…$"
	
PrimordialAltar_Text_Altar2::
	.string "Place a gemstone upon it?$"

PrimordialAltar_Text_PlacedSapphire::
	.string "You placed the SAPPHIRE.$"
	
PrimordialAltar_Text_PlacedRuby::
	.string "You placed the RUBY.$"
	
PrimordialAltar_Text_PlacedEmerald::
	.string "You placed the EMERALD.$"
	
PrimordialAltar_Text_DontRemoveSapphire::
	.string "You left the SAPPHIRE alone.$"
	
PrimordialAltar_Text_DontRemoveRuby::
	.string "You left the RUBY alone.$"
	
PrimordialAltar_Text_DontRemoveEmerald::
	.string "You left the EMERALD alone.$"
	
PrimordialAltar_Text_RemoveSapphire::
	.string "Remove the SAPPHIRE?$"
	
PrimordialAltar_Text_RemoveRuby::
	.string "Remove the RUBY?$"
	
PrimordialAltar_Text_RemoveEmerald::
	.string "Remove the EMERALD?$"
	
PrimordialAltar_Text_PlacedNothing::
	.string "You placed nothing.$"