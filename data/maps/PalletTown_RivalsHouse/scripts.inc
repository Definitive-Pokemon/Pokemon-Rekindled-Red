.equ LOCALID_DAISY,    1
.equ LOCALID_TOWN_MAP, 2
.equ TYPE, VAR_0x8003
.equ ARGUMENT, VAR_0x8004
.equ RECEIVED_TOWN_MAP, VAR_TEMP_1

PalletTown_RivalsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_RivalsHouse_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, PalletTown_RivalsHouse_EventScript_SetStarterGfx
	.byte 0

PalletTown_RivalsHouse_OnTransition::
	clearflag FLAG_TEMP_3
	compare VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	call_if_lt PalletTown_RivalsHouse_EventScript_MoveDaisyToTable
	compare VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	call_if_ge PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap
	goto_if_unset FLAG_GOT_DAISY_STARTER, PalletTown_RivalsHouse_EventScript_CheckRemoveStarter
	setflag FLAG_TEMP_1
	end

PalletTown_RivalsHouse_EventScript_CheckRemoveStarter::
	goto_if_set FLAG_HIDE_CERULEAN_CAVE_GUARD, PalletTown_RivalsHouse_EventScript_PositionForStarterGiveaway
	goto_if_set FLAG_BADGE01_GET, EventScript_ReleaseEnd
	setflag FLAG_TEMP_1
	end

PalletTown_RivalsHouse_EventScript_PositionForStarterGiveaway::
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_DAISY, 8, 5
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm 3, 8, 4
	end
	
PalletTown_RivalsHouse_EventScript_SetStarterGfx::
	compare VAR_STARTER_MON, 0
	call_if_eq PalletTown_RivalsHouse_EventScript_SetSmoochumGfx
	compare VAR_STARTER_MON, 1
	call_if_eq PalletTown_RivalsHouse_EventScript_SetElekidGfx
	compare VAR_STARTER_MON, 2
	call_if_ge PalletTown_RivalsHouse_EventScript_SetMagbyGfx
	return

PalletTown_RivalsHouse_EventScript_SetSmoochumGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SMOOCHUM
	return

PalletTown_RivalsHouse_EventScript_SetElekidGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ELEKID
	return

PalletTown_RivalsHouse_EventScript_SetMagbyGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAGBY
	return

PalletTown_RivalsHouse_EventScript_MoveDaisyToTable::
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_DAISY, 5, 4
	return

PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap::
	setvar RECEIVED_TOWN_MAP, TRUE
	return
	
PalletTown_RivalsHouse_EventScript_Starter::
	lock
	faceplayer
	compare VAR_STARTER_MON, 0
	goto_if_eq PalletTown_RivalsHouse_EventScript_Smoochum
	compare VAR_STARTER_MON, 1
	goto_if_eq PalletTown_RivalsHouse_EventScript_Elekid
	compare VAR_STARTER_MON, 2
	goto_if_ge PalletTown_RivalsHouse_EventScript_Magby
	end
	
PalletTown_RivalsHouse_EventScript_Smoochum::
	waitse
	playmoncry SPECIES_SMOOCHUM, CRY_MODE_NORMAL
	msgbox PalletTown_RivalsHouse_Text_Smoochum
	waitmoncry
	release
	end

PalletTown_RivalsHouse_Text_Smoochum:
	.string "SMOOCHUM: Smoosmoo!$"

PalletTown_RivalsHouse_EventScript_Elekid::
	waitse
	playmoncry SPECIES_ELEKID, CRY_MODE_NORMAL
	msgbox PalletTown_RivalsHouse_Text_Elekid
	waitmoncry
	release
	end

PalletTown_RivalsHouse_Text_Elekid:
	.string "ELEKID: Bzeetts!$"

PalletTown_RivalsHouse_EventScript_Magby::
	waitse
	playmoncry SPECIES_MAGBY, CRY_MODE_NORMAL
	msgbox PalletTown_RivalsHouse_Text_Magby
	waitmoncry
	release
	end

PalletTown_RivalsHouse_Text_Magby:
	.string "MAGBY: Vreoosh!$"

PalletTown_RivalsHouse_EventScript_Daisy::
	lock
	faceplayer
	famechecker FAMECHECKER_DAISY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	goto_if_set FLAG_HIDE_CERULEAN_CAVE_GUARD, PalletTown_RivalsHouse_EventScript_GiveFinalStarter
PalletTown_RivalsHouse_EventScript_DaisyRegular::
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_RivalsHouse_EventScript_GroomMon
	compare RECEIVED_TOWN_MAP, TRUE
	goto_if_eq PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
	compare VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	goto_if_eq PalletTown_RivalsHouse_EventScript_ExplainTownMap
	compare VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1
	goto_if_eq PalletTown_RivalsHouse_EventScript_GiveTownMap
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
	goto_if_ge PalletTown_RivalsHouse_EventScript_HeardBattledRival
	msgbox PalletTown_RivalsHouse_Text_HiBrothersAtLab
	closemessage
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_RivalsHouse_EventScript_HeardBattledRival::
	msgbox PalletTown_RivalsHouse_Text_HeardYouBattledRival
	release
	end

PalletTown_RivalsHouse_EventScript_GroomMon::
	compare VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500
	goto_if_lt PalletTown_RivalsHouse_EventScript_RateMonFriendship
	msgbox PalletTown_RivalsHouse_Text_LikeMeToGroomMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PalletTown_RivalsHouse_EventScript_DeclineGrooming
	msgbox PalletTown_RivalsHouse_Text_GroomWhichOne
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge PalletTown_RivalsHouse_EventScript_DeclineGrooming
	specialvar VAR_RESULT, GetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq PalletTown_RivalsHouse_EventScript_CantGroomEgg
	msgbox PalletTown_RivalsHouse_Text_LookingNiceInNoTime
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_RS_HEAL
	waitfanfare
	special DaisyMassageServices
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_RivalsHouse_Text_ThereYouGoAllDone
	release
	end

PalletTown_RivalsHouse_EventScript_CantGroomEgg::
	msgbox PalletTown_RivalsHouse_Text_CantGroomAnEgg
	release
	end

PalletTown_RivalsHouse_EventScript_DeclineGrooming::
	goto_if_set FLAG_BEAT_DAISY, PalletTown_RivalsHouse_EventScript_DeclineGrooming2
	msgbox PalletTown_RivalsHouse_Text_DontNeedAnyGrooming
	release
	end

PalletTown_RivalsHouse_EventScript_DeclineGrooming2::
	msgbox PalletTown_RivalsHouse_Text_DontNeedAnyGrooming2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PalletTown_RivalsHouse_EventScript_Battle
	msgbox PalletTown_RivalsHouse_Text_Nope
	release
	end

PalletTown_RivalsHouse_Text_DontNeedAnyGrooming2::
    .string "You don't need any grooming done?\n"
    .string "Would you instead like to battle?$"

PalletTown_RivalsHouse_Text_Nope::
    .string "Okay, we'll just have tea.$"

PalletTown_RivalsHouse_EventScript_Battle::
	cleartrainerflag TRAINER_LEADER_DAISY_REMATCH 
	trainerbattle_single TRAINER_LEADER_DAISY_REMATCH, PalletTown_RivalsHouse_Text_DaisyIntro, PalletTown_RivalsHouse_Text_DaisyDefeat, PalletTown_RivalsHouse_EventScript_DefeatedDaisy, NO_MUSIC
	release
	end

PalletTown_RivalsHouse_Text_DaisyIntro::
	.string "Me and my friends have been training\n"
	.string "a lot during your travels.\p"
	.string "We won't go easy on you!\n"
	.string "Give it your all, {PLAYER}!$"

PalletTown_RivalsHouse_Text_DaisyDefeat::
	.string "I'm so proud, {PLAYER}.\n"
	.string "I still have so much to learn.$"

PalletTown_RivalsHouse_EventScript_DefeatedDaisy::
	setvar VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 0
	cleartrainerflag TRAINER_LEADER_DAISY_REMATCH 
	msgbox PalletTown_RivalsHouse_Text_YouWon
	release
	end

PalletTown_RivalsHouse_Text_YouWon::
	.string "Just like last time, I really put\n"
	.string "everything I had into this fight.\p"
	.string "We'd love to battle you again\n"
	.string "sometime soon.\p"
	.string "My POKéMON feel get excited just\n"
	.string "thinking about it.$"

PalletTown_RivalsHouse_EventScript_RateMonFriendship::
	msgbox PalletTown_RivalsHouse_Text_MayISeeFirstMon
	specialvar VAR_RESULT, GetLeadMonFriendship
	switch VAR_RESULT
	case 0, PalletTown_RivalsHouse_EventScript_MonFriendshipLowest
	case 1, PalletTown_RivalsHouse_EventScript_MonFriendshipLower
	case 2, PalletTown_RivalsHouse_EventScript_MonFriendshipLow
	case 3, PalletTown_RivalsHouse_EventScript_MonFriendshipMid
	case 4, PalletTown_RivalsHouse_EventScript_MonFriendshipHigh
	case 5, PalletTown_RivalsHouse_EventScript_MonFriendshipHigher
	case 6, PalletTown_RivalsHouse_EventScript_MonFriendshipHighest
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLowest::
	msgbox PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLower::
	msgbox PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLow::
	msgbox PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipMid::
	msgbox PalletTown_RivalsHouse_Text_ItsWarmingUpToYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigh::
	msgbox PalletTown_RivalsHouse_Text_ItsQuiteFriendly
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigher::
	msgbox PalletTown_RivalsHouse_Text_ItLooksVeryHappy
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHighest::
	msgbox PalletTown_RivalsHouse_Text_CouldntLoveYouMore
	release
	end

PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest::
	msgbox PalletTown_RivalsHouse_Text_PleaseGiveMonsRest
	release
	end

PalletTown_RivalsHouse_EventScript_GiveTownMap::
	msgbox PalletTown_RivalsHouse_Text_ErrandForGrandpaThisWillHelp
	closemessage
	checkitemspace ITEM_TOWN_MAP, 1
	compare VAR_RESULT, FALSE
	goto_if_eq PalletTown_RivalsHouse_EventScript_NoRoomForTownMap
	applymovement LOCALID_DAISY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	removeobject LOCALID_TOWN_MAP
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	delay 15
	applymovement LOCALID_DAISY, Common_Movement_FacePlayer
	waitmovement 0
	delay 12
	giveitem_msg PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy, ITEM_TOWN_MAP, 1, MUS_OBTAIN_KEY_ITEM
	release
	end

PalletTown_RivalsHouse_EventScript_NoRoomForTownMap::
	msgbox PalletTown_RivalsHouse_Text_DontHaveSpaceForThis
	release
	end

PalletTown_RivalsHouse_EventScript_ExplainTownMap::
	msgbox PalletTown_RivalsHouse_Text_ExplainTownMap
	release
	end

PalletTown_RivalsHouse_EventScript_TownMap::
	msgbox PalletTown_RivalsHouse_Text_ItsBigMapOfKanto, MSGBOX_NPC
	end

PalletTown_RivalsHouse_EventScript_Bookshelf::
	msgbox PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_EventScript_Picture::
	msgbox PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_EventScript_GiveFinalStarter::
	goto_if_set FLAG_GOT_DAISY_STARTER, PalletTown_RivalsHouse_EventScript_GiveFinalStarter_2
PalletTown_RivalsHouse_EventScript_GiveFinalStarter_1:
	switch VAR_STARTER_MON
	case 0, PalletTown_RivalsHouse_EventScript_GiveFinalStarter_6
	case 1, PalletTown_RivalsHouse_EventScript_GiveFinalStarter_7
	case 2, PalletTown_RivalsHouse_EventScript_GiveFinalStarter_8
PalletTown_RivalsHouse_EventScript_GiveFinalStarter_4:
	msgbox PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PalletTown_RivalsHouse_EventScript_GiveFinalStarter_10
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq PalletTown_RivalsHouse_EventScript_GiveFinalStarter_13
	textcolor 3
	waitse
	playmoncry VAR_TEMP_2, CRY_MODE_NORMAL
	msgbox PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_6
	waitmoncry
	release
	turnobject 3, DIR_SOUTH
	applymovement LOCALID_DAISY, PalletTown_RivalsHouse_Movement_FaceUp
	waitmovement 0
	removeobject 3
	delay 16
	faceplayer
	givemon VAR_TEMP_2, 5, ITEM_NONE
	playfanfare MUS_LEVEL_UP
	message PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_7
	waitmessage
	waitfanfare
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq PalletTown_RivalsHouse_EventScript_GiveFinalStarter_16
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PalletTown_RivalsHouse_EventScript_GiveFinalStarter_16
PalletTown_RivalsHouse_EventScript_GiveFinalStarter_15:
	call EventScript_RestorePrevTextColor
	setflag FLAG_GOT_DAISY_STARTER
	msgbox PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_8
	closemessage
	applymovement LOCALID_DAISY, PalletTown_RivalsHouse_Movement_Away
	waitmovement 0
	msgbox PalletTown_RivalsHouse_Text_Going
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_DAISY
	setflag FLAG_DAISY_READY
	fadescreen FADE_FROM_BLACK
	release
	end

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_2:
	goto PalletTown_RivalsHouse_EventScript_DaisyRegular
	goto PalletTown_RivalsHouse_EventScript_GiveFinalStarter_1

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_6:
	bufferspeciesname STR_VAR_1, SPECIES_SMOOCHUM
	bufferstring 1, PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_0
	setvar VAR_TEMP_2, SPECIES_SMOOCHUM
	goto PalletTown_RivalsHouse_EventScript_GiveFinalStarter_4

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_7:
	bufferspeciesname STR_VAR_1, SPECIES_ELEKID
	bufferstring 1, PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_1
	setvar VAR_TEMP_2, SPECIES_ELEKID
	goto PalletTown_RivalsHouse_EventScript_GiveFinalStarter_4

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_8:
	bufferspeciesname STR_VAR_1, SPECIES_MAGBY
	bufferstring 1, PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_2
	setvar VAR_TEMP_2, SPECIES_MAGBY
	goto PalletTown_RivalsHouse_EventScript_GiveFinalStarter_4

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_10:
	msgbox PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_4
	release
	end

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_13:
	msgbox PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_5
	release
	end

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_16:
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto PalletTown_RivalsHouse_EventScript_GiveFinalStarter_15


PalletTown_RivalsHouse_Movement_FaceUp:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_up
	step_end

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_0:
	.string "SMOOCHUM: Smoosmoo!$"

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_1:
	.string "ELEKID: Bzeetts!$"

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_2:
	.string "MAGBY: Vreoosh!$"

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_3:
	.string "DAISY: Grandpa gave me a {STR_VAR_1}\nto look after, but…\p{STR_VAR_1}'s gotten terribly bored \ncooped up here at home.\p{PLAYER}, I think it would be much\nhappier traveling with you.\pWill you please take {STR_VAR_1}\nwith you on your adventures?$"

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_4:
	.string "I understand, though {STR_VAR_1}\nlooks disappointed.\pPlease come back if you change\nyour mind.$"

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_5:
	.string "Oh, you have no room to take\n{STR_VAR_1} with you.\pWe'll wait here until you've\nmade some space.$"

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_6:
	.string "{STR_VAR_2}$"

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_7:
	.string "{PLAYER} received a {STR_VAR_1}\nfrom DAISY!$"

PalletTown_RivalsHouse_EventScript_GiveFinalStarter_Text_8:
	.string "DAISY: Thank you, {PLAYER}!\pTake good care of\n{STR_VAR_1}!$"

PalletTown_RivalsHouse_Text_Going:
	.string "{PLAYER}…\n"
	.string "There's something else…\p"
	.string "I'm leaving for the VIRIDIAN GYM.\n"
	.string "I need to do something there…$"
	
PalletTown_RivalsHouse_Movement_Away::
	walk_in_place_up
	delay_16
	delay_16
	delay_16
	face_player
	step_end