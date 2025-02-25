.equ LOCALID_BILL,  3
.equ LOCALID_CELIO, 4
.equ LOCALID_SCOTT, 8

OneIsland_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OneIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, OneIsland_PokemonCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OneIsland_PokemonCenter_1F_OnFrame
	.byte 0

OneIsland_PokemonCenter_1F_OnLoad::
	call_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile
	call_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 8, OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatileOff
	call_if_set FLAG_SYS_CAN_LINK_WITH_RS, OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn
	goto PokemonCenter_1F_OnLoad
	end

OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile::
	setmetatile 13, 4, METATILE_PokemonCenter_NetworkMachine_Ruby, 1
	return
	
OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatileOff::
	setmetatile 13, 4, METATILE_PokemonCenter_NetworkMachine_RubyGone, 1
	return
	
OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile::
	setmetatile 16, 4, METATILE_PokemonCenter_NetworkMachine_Sapphire, 1
	return

OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn::
	call OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile
	setmetatile 14, 4, METATILE_PokemonCenter_NetworkMachine_ScreenLeft_On, 1
	setmetatile 15, 4, METATILE_PokemonCenter_NetworkMachine_ScreenRight_On, 1
	return

OneIsland_PokemonCenter_1F_OnTransition::
	setrespawn SPAWN_ONE_ISLAND
	call_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6, OneIsland_PokemonCenter_1F_EventScript_SetCelioQuestDone
	call_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 0, OneIsland_PokemonCenter_1F_EventScript_SetBillCelioFirstMeetingPos
	call_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 2, OneIsland_PokemonCenter_1F_EventScript_SetBillCelioReadyToLeavePos
	end

OneIsland_PokemonCenter_1F_EventScript_SetCelioQuestDone::
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 7
	return

OneIsland_PokemonCenter_1F_EventScript_SetBillCelioFirstMeetingPos::
	setobjectxyperm LOCALID_BILL, 9, 8
	setobjectmovementtype LOCALID_BILL, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_CELIO, 15, 6
	setobjectmovementtype LOCALID_CELIO, MOVEMENT_TYPE_FACE_UP
	return

OneIsland_PokemonCenter_1F_EventScript_SetBillCelioReadyToLeavePos::
	setobjectxyperm LOCALID_BILL, 14, 7
	setobjectmovementtype LOCALID_BILL, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_CELIO, 14, 8
	setobjectmovementtype LOCALID_CELIO, MOVEMENT_TYPE_FACE_LEFT
	return

OneIsland_PokemonCenter_1F_OnFrame::
	map_script_2 VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 0, OneIsland_PokemonCenter_1F_EventScript_MeetCelioScene
	.2byte 0

OneIsland_PokemonCenter_1F_EventScript_MeetCelioScene::
	lockall
	setflag FLAG_HIDE_CAVE_BALL
	textcolor NPC_TEXT_COLOR_MALE
	applymovement OBJ_EVENT_ID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToCelio
	applymovement LOCALID_BILL, OneIsland_PokemonCenter_1F_Movement_BillWalkToCelio
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillHeyThereCelio
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_CELIO, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_Delay48
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioCantBelieveYouCameOut
	msgbox OneIsland_PokemonCenter_1F_Text_BillHowsYourResearchComing
	applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_ThisIsMyBuddyCelio
	applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call_if_set FLAG_SYS_GAME_CLEAR, OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerChamp
	call_if_unset FLAG_SYS_GAME_CLEAR, OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerNotChamp
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioThatsReallyImpressive
	msgbox OneIsland_PokemonCenter_1F_Text_BillBringMeUpToSpeed
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioPCsCantLinkWithYours
	closemessage
	applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillLetMeHelpYou
	applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CanYouDeliverThisMeteoritePlayer
	msgreceiveditem OneIsland_PokemonCenter_1F_Text_AcceptedMeteoriteFromBill, ITEM_METEORITE, 1, MUS_OBTAIN_KEY_ITEM
	additem ITEM_METEORITE
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioPleaseTakeThis
	giveitem_msg OneIsland_PokemonCenter_1F_Text_ObtainedTriPass, ITEM_TRI_PASS, 1, MUS_OBTAIN_KEY_ITEM
	msgbox OneIsland_PokemonCenter_1F_Text_PassLetsYouTravelBetweenIslands
	call_if_ge VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMapPage
	call_if_lt VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMap
	setflag FLAG_SYS_SEVII_MAP_123
	msgbox OneIsland_PokemonCenter_1F_Text_BillCatchYouLater
	closemessage
	applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setflag FLAG_SYS_PC_STORAGE_DISABLED
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerChamp::
	msgbox OneIsland_PokemonCenter_1F_Text_PlayerIsReigningPokemonChamp
	return

OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerNotChamp::
	msgbox OneIsland_PokemonCenter_1F_Text_PlayerIsRisingPokemonChamp
	return

OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMapPage::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_KEY_ITEM
	message OneIsland_PokemonCenter_1F_Text_ReceivedExtraPageForTownMap
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	return

OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMap::
	setflag FLAG_HIDE_TOWN_MAP
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	giveitem_msg OneIsland_PokemonCenter_1F_Text_ReceivedTownMap, ITEM_TOWN_MAP, 1, MUS_OBTAIN_KEY_ITEM
	return

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToCelio::
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

OneIsland_PokemonCenter_1F_Movement_BillWalkToCelio::
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_faster_right
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_WalkUp:
	walk_up
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_StepAsideLeft::
	walk_left
	walk_in_place_faster_right
	step_end

OneIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

OneIsland_PokemonCenter_1F_EventScript_Bill::
	lock
	goto_if_set FLAG_SEVII_DETOUR_FINISHED, OneIsland_PokemonCenter_1F_EventScript_BillGoTakeStroll
	msgbox OneIsland_PokemonCenter_1F_Text_HmmHowAboutLikeThis
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BillGoTakeStroll::
	applymovement LOCALID_BILL, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_GotPCWorkingStrollAWhileMore
	release
	end

OneIsland_PokemonCenter_1F_EventScript_Celio::
	lock
	faceplayer
	goto_if_unset FLAG_CHECKED_ALTAR, OneIsland_PokemonCenter_1F_EventScript_Celio_Skip_Battle
	goto_if_unset FLAG_HIDE_ONE_ISLAND_POKECENTER_CELIO, OneIsland_PokemonCenter_1F_EventScript_CelioBattle
OneIsland_PokemonCenter_1F_EventScript_Celio_Skip_Battle::
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 7, OneIsland_PokemonCenter_1F_EventScript_CelioGiveBillFact
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6, OneIsland_PokemonCenter_1F_EventScript_CelioJustGivenSapphire
	goto_if_set FLAG_RECOVERED_SAPPHIRE, OneIsland_PokemonCenter_1F_EventScript_GiveCelioSapphire
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPass
	goto_if_set FLAG_GOT_RUBY, OneIsland_PokemonCenter_1F_EventScript_GiveCelioRuby
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, OneIsland_PokemonCenter_1F_EventScript_CelioWaitingForRuby
	goto_if_set FLAG_SYS_RECEIVED_EXTENDED_DEX, OneIsland_PokemonCenter_1F_EventScript_CelioRequestRuby
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 3, OneIsland_PokemonCenter_1F_EventScript_CelioPlayerMissingNationalDex
	msgbox OneIsland_PokemonCenter_1F_Text_SorryForBeingPoorHost
	closemessage
	applymovement LOCALID_CELIO, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
	
OneIsland_PokemonCenter_1F_EventScript_CelioBattle::
	msgbox OneIsland_PokemonCenter_1F_Text_Altar
	closemessage
	playse SE_PIN
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioExclaim
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_Altar2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OneIsland_PokemonCenter_1F_EventScript_CelioNoBattle
	trainerbattle_single TRAINER_CELIO, OneIsland_PokemonCenter_1F_Text_LetsBattle, OneIsland_PokemonCenter_1F_Text_CelioDefeat, OneIsland_PokemonCenter_1F_EventScript_CelioDefeated, NO_MUSIC
	end
	
OneIsland_PokemonCenter_1F_EventScript_CelioDefeated::
	msgbox OneIsland_PokemonCenter_1F_Text_GiveStones
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine
	waitmovement 0
	playse SE_CLICK
	setmetatile 13, 4, METATILE_PokemonCenter_NetworkMachine_RubyGone, 1
	setmetatile 16, 4, METATILE_PokemonCenter_NetworkMachine_SapphireGone, 1
	setmetatile 14, 4, METATILE_PokemonCenter_NetworkMachine_ScreenLeft_Off, 1
	setmetatile 15, 4, METATILE_PokemonCenter_NetworkMachine_ScreenRight_Off, 1
	special DrawWholeMapView
	delay 30
	applymovement LOCALID_CELIO, Common_Movement_FacePlayer
	waitmovement 0
	giveitem ITEM_RUBY, 1
	giveitem ITEM_SAPPHIRE, 1
	msgbox OneIsland_PokemonCenter_1F_Text_Phew
	closemessage
	goto_if_eq VAR_FACING, DIR_EAST, OneIsland_PokemonCenter_1F_EventScript_CelioGoLeft
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioGo
	waitmovement 0
	removeobject LOCALID_CELIO
	playse SE_EXIT
	waitse
	setflag FLAG_HIDE_ONE_ISLAND_POKECENTER_CELIO
	release
	clearflag FLAG_SYS_CAN_LINK_WITH_RS
        clearflag FLAG_HIDE_TOWER_CELIO
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 8
	end
	
OneIsland_PokemonCenter_1F_EventScript_CelioGoLeft::
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioGoLeft
	waitmovement 0
	removeobject LOCALID_CELIO
	playse SE_EXIT
	waitse
	setflag FLAG_HIDE_ONE_ISLAND_POKECENTER_CELIO
	release
	clearflag FLAG_SYS_CAN_LINK_WITH_RS
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 8
	end
	
OneIsland_PokemonCenter_1F_Movement_CelioGo::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	step_end
	
OneIsland_PokemonCenter_1F_Movement_CelioGoLeft::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_down
	step_end
	
OneIsland_PokemonCenter_1F_Movement_CelioExclaim::
	emote_exclamation_mark
	step_end

OneIsland_PokemonCenter_1F_EventScript_CelioNoBattle::
	msgbox OneIsland_PokemonCenter_1F_Text_NoBattle
	release
	end
	
OneIsland_PokemonCenter_1F_Text_Altar::
	.string "Hello, {PLAYER}!\n"
	.string "How is the exploring going?\p"
	.string "Did you find anything using that\n"
	.string "HM I gave you?$"
	
OneIsland_PokemonCenter_1F_Text_Altar2::
	.string "Interesting…\p"
	.string "So you found an altar containing\n"
	.string "a hole that perfectly matches\l"
	.string "the shape of the two stones\l"
	.string "you collected for me?\p"
	.string "That can only mean one thing…\p"
	.string "Those stones are made to fit\n"
	.string "into that hole you found!\p"
	.string "{PLAYER}, it scares me to even\n"
	.string "think about this, but…\p"
	.string "We have no choice but to battle.\n"
	.string "The winner gets the stones.\p"
	.string "I can't give these away for free.\n"
	.string "They've made my dream come true.\p"
	.string "So…\p"
	.string "Will you challenge me to a\n"
	.string "POKéMON battle?$"
	
OneIsland_PokemonCenter_1F_Text_LetsBattle::
	.string "Let's do this, then.\p"
	.string "May the best TRAINER win.$"
	
OneIsland_PokemonCenter_1F_Text_CelioDefeat::
    .string "Woah!\n"
    .string "You did it, {PLAYER}!\p"
    .string "I will give you the stones\n"
    .string "as promised.$"
	
OneIsland_PokemonCenter_1F_Text_GiveStones::
	.string "I gave it my all, but against you\n"
	.string "that simply isn't enough.\p"
	.string "You've earned these, {PLAYER}.$"
	
OneIsland_PokemonCenter_1F_Text_Phew::
	.string "That was a great fight!\p"
	.string "It's been a while since I had a\n"
	.string "POKéMON battle to begin with!\p"
	.string "I can no longer pursue my original\n"
	.string "dream now, but don't worry.\p"
	.string "In this world, there will always be\n"
	.string "dreams to chase.\p"
	.string "Never forget that, {PLAYER}!\p"
	.string "I will find a new path for myself.\n"
	.string "To be frank, I needed this fight.\p"
	.string "Sitting inside, tampering with\n"
	.string "machinery is great fun.\p"
	.string "But it sure isn't everything!\p"
	.string "There is an entire world waiting\n"
	.string "for me outside.\p"
	.string "A world I had long abandoned…\p"
	.string "I'll be seeing you, {PLAYER}.\n"
	.string "I think I'm going to pick up\p"
	.string "POKéMON battling again,\n"
	.string "thanks to you.\p"
	.string "I'm going to train some at the\n"
	.string "TRAINER TOWER.\l"
	.string "I'll be seeing you, {PLAYER}.$"
	
OneIsland_PokemonCenter_1F_Text_NoBattle::
	.string "I will be waiting, {PLAYER}.\p"
	.string "I cannot keep doing things\n"
	.string "my way forever…$"

OneIsland_PokemonCenter_1F_EventScript_CelioGiveBillFact::
	msgbox OneIsland_PokemonCenter_1F_Text_CelioHearingRumorsAboutYou
	random 3
	goto_if_eq VAR_RESULT, 0, OneIsland_PokemonCenter_1F_EventScript_BillFact1
	goto_if_eq VAR_RESULT, 1, OneIsland_PokemonCenter_1F_EventScript_BillFact2
	famechecker FAMECHECKER_BILL, 5
	msgbox OneIsland_PokemonCenter_1F_Text_BillCantStomachMilk
	release
	end
	
OneIsland_PokemonCenter_1F_EventScript_CelioGiveBillFact2::
	msgbox OneIsland_PokemonCenter_1F_Text_CelioHearingRumorsAboutYou2
	random 3
	goto_if_eq VAR_RESULT, 0, OneIsland_PokemonCenter_1F_EventScript_BillFact1
	goto_if_eq VAR_RESULT, 1, OneIsland_PokemonCenter_1F_EventScript_BillFact2
	famechecker FAMECHECKER_BILL, 5
	msgbox OneIsland_PokemonCenter_1F_Text_BillCantStomachMilk
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BillFact1::
	famechecker FAMECHECKER_BILL, 3
	msgbox OneIsland_PokemonCenter_1F_Text_BillsFirstMonWasAbra
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BillFact2::
	famechecker FAMECHECKER_BILL, 4
	msgbox OneIsland_PokemonCenter_1F_Text_BillsHometownInGoldenrod
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioJustGivenSapphire::
	msgbox OneIsland_PokemonCenter_1F_Text_WishYouBestOfLuck
	release
	end

OneIsland_PokemonCenter_1F_EventScript_GiveCelioSapphire::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message OneIsland_PokemonCenter_1F_Text_HandedSapphireToCelio
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	removeitem ITEM_SAPPHIRE
	msgbox OneIsland_PokemonCenter_1F_Text_ThankYouGiveMeTime
	closemessage
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine
	waitmovement 0
	playse SE_CLICK
	call OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile
	special DrawWholeMapView
	msgbox OneIsland_PokemonCenter_1F_Text_OkayThisIsGood
	closemessage
	delay 60
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine
	waitmovement 0
	delay 30
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine
	waitmovement 0
	delay 40
	playse SE_PC_ON
	call OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn
	special DrawWholeMapView
	msgbox OneIsland_PokemonCenter_1F_Text_LinkedUpWithLanette
	applymovement LOCALID_CELIO, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_ManagedToLinkWithHoennThankYou
	giveitem ITEM_HM08, 1
	msgbox OneIsland_PokemonCenter_1F_Text_ExplainDive
	special SetPostgameFlags
	setflag FLAG_SYS_CAN_LINK_WITH_RS
	setflag FLAG_HIDE_LORELEI_IN_HER_HOUSE
	setflag FLAG_HIDE_CERULEAN_CAVE_GUARD
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6
	release
	end

OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPass::
	msgbox OneIsland_PokemonCenter_1F_Text_PassLetYouGetToAllIslands
	release
	end

OneIsland_PokemonCenter_1F_EventScript_GiveCelioRuby::
	msgbox OneIsland_PokemonCenter_1F_Text_OhThats
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message OneIsland_PokemonCenter_1F_Text_HandedRubyToCelio
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	closemessage
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine
	waitmovement 0
	playse SE_CLICK
	call OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile
	special DrawWholeMapView
	delay 30
	applymovement LOCALID_CELIO, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_MayIAskOneMoreFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio
	goto OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass
	end

OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio::
	msgbox OneIsland_PokemonCenter_1F_Text_PleaseINeedYourHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio
	goto OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass
	end

OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass::
	msgbox OneIsland_PokemonCenter_1F_Text_AnotherGemstoneInSeviiIslands
	removeitem ITEM_RUBY
	removeitem ITEM_TRI_PASS
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5
	additem ITEM_RAINBOW_PASS
	setflag FLAG_SYS_SEVII_MAP_4567
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_KEY_ITEM
	message OneIsland_PokemonCenter_1F_Text_ReturnedTriPassForRainbowPass
	waitmessage
	waitfanfare
	playfanfare MUS_OBTAIN_KEY_ITEM
	message OneIsland_PokemonCenter_1F_Text_ObtainedExtraMapPage
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	goto OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPassScott
	end

OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPassScott::
	msgbox OneIsland_PokemonCenter_1F_Text_PassLetYouGetToAllIslandsScott
	closemessage
	turnobject LOCALID_SCOTT, DIR_NORTH
	playse SE_PIN
	applymovement LOCALID_SCOTT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SCOTT, Common_Movement_Delay48
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_YoureTheChamp
	closemessage
	getplayerxy VAR_0x8005, VAR_0x8007
	call_if_lt VAR_0x8005, 15, OneIsland_PokemonCenter_1F_EventScript_ScottToLeft
	call_if_eq VAR_0x8005, 15, OneIsland_PokemonCenter_1F_EventScript_ScottToCenter
	call_if_gt VAR_0x8005, 15, OneIsland_PokemonCenter_1F_EventScript_ScottToRight
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox OneIsland_PokemonCenter_1F_Text_ExcuseMe
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	getplayerxy VAR_0x8005, VAR_0x8007
	call_if_eq VAR_0x8005, 15, OneIsland_PokemonCenter_1F_EventScript_ScottLeftOne
	call_if_gt VAR_0x8005, 15, OneIsland_PokemonCenter_1F_EventScript_ScottLeftTwo
	applymovement LOCALID_SCOTT, OneIsland_PokemonCenter_1F_Movement_ScottExits
	waitmovement 0
	call_if_ne VAR_0x8005, 15, OneIsland_PokemonCenter_1F_EventScript_ScottExitsDownStep
	removeobject LOCALID_SCOTT
	playse SE_EXIT
	release
	end

OneIsland_PokemonCenter_1F_EventScript_ScottExitsDownStep::
	applymovement LOCALID_SCOTT, OneIsland_PokemonCenter_1F_Movement_ScottExitsDownStep
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_Movement_ScottExitsDownStep::
	walk_down
	step_end

OneIsland_PokemonCenter_1F_EventScript_ScottLeftOne::
	applymovement LOCALID_SCOTT, OneIsland_PokemonCenter_1F_Movement_ScottLeftOne
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_ScottLeftTwo::
	applymovement LOCALID_SCOTT, OneIsland_PokemonCenter_1F_Movement_ScottLeftTwo
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_Movement_ScottLeftOne::
	walk_left
	step_end

OneIsland_PokemonCenter_1F_Movement_ScottLeftTwo::
	walk_left
	walk_left
	step_end

OneIsland_PokemonCenter_1F_Movement_ScottExits::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

OneIsland_PokemonCenter_1F_Text_ExcuseMe::
	.string "Excuse me!\n"
	.string "I couldn't help but overhear.\p"
	.string "Let me introduce myself.\n"
	.string "My name's SCOTT.\p"
	.string "I've been traveling everywhere in\n"
	.string "search of outstanding TRAINERS.\p"
	.string "More specifically, I'm looking for\n"
	.string "POKéMON battle experts.\p"
	.string "There's a place I'd like to\n"
	.string "invite someone like you.\p"
	.string "It's the…\n"
	.string "BATTLE TOWER!\p"
	.string "I'm about to head to VERMILION\n"
	.string "to continue my search.\p"
	.string "I'll tell the ferryman there to let\n"
	.string "you sail to HOENN and check it out\l"
	.string "for yourself!\p"
	.string "Well, I'll be seeing you!$"

OneIsland_PokemonCenter_1F_EventScript_ScottToLeft::
	applymovement LOCALID_SCOTT, OneIsland_PokemonCenter_1F_Movement_ScottToLeft
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_ScottToCenter::
	applymovement LOCALID_SCOTT, OneIsland_PokemonCenter_1F_Movement_ScottToCenter
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_ScottToRight::
	applymovement LOCALID_SCOTT, OneIsland_PokemonCenter_1F_Movement_ScottToRight
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_Text_YoureTheChamp::
	.string "You're the KANTO LEAGUE CHAMPION?$"

OneIsland_PokemonCenter_1F_EventScript_Scott::
	msgbox OneIsland_PokemonCenter_1F_Text_ScottOnPhone
	faceplayer
	msgbox OneIsland_PokemonCenter_1F_Text_HeyOnCall
	turnobject LOCALID_SCOTT, DIR_EAST
	release
	end

OneIsland_PokemonCenter_1F_Text_ScottOnPhone:
	.string "…I'm not so sure about the\n"
	.string "TRAINERS here.\p"
	.string "I think I'm going to roam the\n"
	.string "towns in KANTO instead.$"

OneIsland_PokemonCenter_1F_Text_HeyOnCall:
	.string "Hey! Can't you see I'm on a call?$"

OneIsland_PokemonCenter_1F_Movement_ScottToLeft::
	walk_up
	walk_left
	walk_up
	step_end

OneIsland_PokemonCenter_1F_Movement_ScottToCenter::
	walk_up
	step_end

OneIsland_PokemonCenter_1F_Movement_ScottToRight::
	walk_up
	walk_right
	walk_up
	step_end

OneIsland_PokemonCenter_1F_EventScript_CelioWaitingForRuby::
	msgbox OneIsland_PokemonCenter_1F_Text_TryingToFindGem
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioRequestRuby::
	msgbox OneIsland_PokemonCenter_1F_Text_CelioCaughtMoreMonMaybeICanBeUseful
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_YoullBeTradingFromTrainersFarAway
	applymovement LOCALID_CELIO, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_NeedsSpecialGemstone
	setvar VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 1
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioPlayerMissingNationalDex::
	msgbox OneIsland_PokemonCenter_1F_Text_CelioImModifyingMyNetworkMachine
	release
	end

OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine::
	walk_in_place_up
	delay_8
	walk_in_place_up
	step_end

OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine::
	walk_in_place_faster_up
	walk_in_place_up
	delay_16
	walk_in_place_up
	walk_in_place_up
	step_end

OneIsland_PokemonCenter_1F_EventScript_LittleBoy::
	msgbox OneIsland_PokemonCenter_1F_Text_CameFromPalletDontKnowIt, MSGBOX_NPC
	end

OneIsland_PokemonCenter_1F_EventScript_Hiker::
	msgbox OneIsland_PokemonCenter_1F_Text_EnormousVolcanoOnIsland, MSGBOX_NPC
	end

OneIsland_PokemonCenter_1F_EventScript_BattleGirl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, OneIsland_PokemonCenter_1F_EventScript_BattleGirlHoennLinked
	msgbox OneIsland_PokemonCenter_1F_Text_WishICouldTradeWithBoyfriend
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BattleGirlHoennLinked::
	msgbox OneIsland_PokemonCenter_1F_Text_TradedWithFarAwayBoyfriend
	release
	end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachine::
	lockall
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithHoenn
	goto_if_set FLAG_SEVII_DETOUR_FINISHED, OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithKanto
	msgbox OneIsland_PokemonCenter_1F_Text_MachineUnderAdjustment
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithKanto::
	msgbox OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKanto
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithHoenn::
	msgbox OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKantoAndHoenn
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerTop::
	lockall
	setvar VAR_TEMP_1, 1
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerMidTop::
	lockall
	setvar VAR_TEMP_1, 2
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerMidBottom::
	lockall
	setvar VAR_TEMP_1, 3
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 4
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene::
	textcolor NPC_TEXT_COLOR_MALE
	playse SE_PIN
	applymovement LOCALID_BILL, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillOhHeyPlayer
	closemessage
	call_if_eq VAR_TEMP_1, 1, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillTop
	call_if_eq VAR_TEMP_1, 2, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidTop
	call_if_eq VAR_TEMP_1, 3, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidBottom
	call_if_eq VAR_TEMP_1, 4, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillBottom
	delay 10
	msgbox OneIsland_PokemonCenter_1F_Text_BillWeGotItDone
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioJobWentQuick
	applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillYouveLearnedALot
	msgbox OneIsland_PokemonCenter_1F_Text_CelioOhReallyEhehe
	closemessage
	applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 15
	msgbox OneIsland_PokemonCenter_1F_Text_BillWeShouldHeadBackToKanto
	closemessage
	applymovement LOCALID_BILL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 15
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioPromiseIllShowYouAroundSometime
	closemessage
	delay 25
	applymovement OBJ_EVENT_ID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerExit
	applymovement LOCALID_BILL, OneIsland_PokemonCenter_1F_Movement_BillExit
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_ONE_ISLAND_POKECENTER_BILL
	setflag FLAG_MOLTRES_FIRST_TIME
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 3
	clearflag FLAG_HIDE_CINNABAR_BILL
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND, 3
	setvar VAR_0x8004, SEAGALLOP_ONE_ISLAND
	setvar VAR_0x8006, SEAGALLOP_CINNABAR_ISLAND
	goto EventScript_SetSail
	end

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillTop::
	applymovement OBJ_EVENT_ID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillTop
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidTop::
	applymovement OBJ_EVENT_ID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidTop
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidBottom::
	applymovement OBJ_EVENT_ID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidBottom
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillBottom::
	applymovement OBJ_EVENT_ID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillBottom
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillTop::
	walk_right
	walk_down
	walk_in_place_faster_right
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidTop::
	walk_right
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidBottom::
	walk_right
	walk_up
	walk_in_place_faster_right
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillBottom::
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_DelayWalkInPlaceLeft::
	delay_16
	delay_16
	delay_4
	walk_in_place_faster_left
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_WalkInPlaceDown::
	walk_in_place_fast_down
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerExit::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

OneIsland_PokemonCenter_1F_Movement_BillExit::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end
