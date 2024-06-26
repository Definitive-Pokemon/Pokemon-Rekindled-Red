.equ HELIX_FOSSIL, 1
.equ DOME_FOSSIL,  2
.equ OLD_AMBER,    3
.set LOCALID_OMASTAR_MASTER, 3
.set TRAINER, VAR_0x8009

CinnabarIsland_PokemonLab_ExperimentRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PokemonLab_ExperimentRoom_MapScript_SetMasterTrainerMovementTypes
	.byte 0

CinnabarIsland_PokemonLab_ExperimentRoom_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_OMASTAR
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, CinnabarIsland_PokemonLab_ExperimentRoom_MapScript_OmastarMasterMovementType
	end

CinnabarIsland_PokemonLab_ExperimentRoom_MapScript_OmastarMasterMovementType::
	setobjectmovementtype LOCALID_OMASTAR_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_Garett::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_SEEL
	call EventScript_GetInGameTradeSpeciesInfo
	goto_if_set FLAG_DID_SEELOR_TRADE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_AlreadyTraded
	msgbox Trade_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineTrade
	call EventScript_ChooseMonForInGameTrade
	goto_if_ge VAR_0x8004, PARTY_SIZE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineTrade
	call EventScript_GetInGameTradeSpecies
	goto_if_ne VAR_RESULT, VAR_0x8009, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NotRequestedMon
	call EventScript_DoInGameTrade
	msgbox Trade_Text_HeyThanks
	setflag FLAG_DID_SEELOR_TRADE
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineTrade::
	msgbox Trade_Text_AwwOhWell
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Trade_Text_WhatThatsNoMon
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_AlreadyTraded::
	msgbox Trade_Text_IsntMyOldMonGreat
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist::
	lock
	faceplayer
	setvar VAR_RESULT, FALSE
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 2, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveRevivedMon
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilStillReviving
	checkitem ITEM_HELIX_FOSSIL, 1
	copyvar VAR_0x800A, VAR_RESULT
	checkitem ITEM_DOME_FOSSIL, 1
	copyvar VAR_0x800B, VAR_RESULT
	checkitem ITEM_OLD_AMBER, 1
	copyvar VAR_0x8007, VAR_RESULT
	goto_if_ne VAR_0x800A, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_1
	goto_if_ne VAR_0x800B, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_1
	goto_if_ne VAR_0x8007, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_1
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	return

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_1:
	goto_if_ne VAR_0x800A, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_27
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_24:
	goto_if_ne VAR_0x800A, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_23
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_21:
	goto_if_ne VAR_0x800A, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_20
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_19:
	goto_if_ne VAR_0x800A, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_11
	goto_if_ne VAR_0x800B, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_16
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_15:
	goto_if_ne VAR_0x800B, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_13
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
	waitmessage
	multichoice 0, 0, MULTICHOICE_AMBER, FALSE
	goto_if_eq VAR_RESULT, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_55
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_54:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	return

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_8:
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
	waitmessage
	multichoice 0, 0, MULTICHOICE_HELIX_DOME_AMBER, FALSE
	switch VAR_RESULT
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_34
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_33
	case 2, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_35
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_31:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	return

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_9:
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
	waitmessage
	multichoice 0, 0, MULTICHOICE_HELIX_DOME, FALSE
	switch VAR_RESULT
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_39
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_38
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_36:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	return

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_10:
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
	waitmessage
	multichoice 0, 0, MULTICHOICE_HELIX_AMBER, FALSE
	switch VAR_RESULT
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_42
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_43
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_40:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	return

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_11:
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
	waitmessage
	multichoice 0, 0, MULTICHOICE_HELIX, FALSE
	compare VAR_RESULT, 0
	goto_if_eq CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_45
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_44:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	return

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_12:
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
	waitmessage
	multichoice 0, 0, MULTICHOICE_DOME_AMBER, FALSE
	switch VAR_RESULT
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_49
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_50
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_47:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	return

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_13:
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
	waitmessage
	multichoice 0, 0, MULTICHOICE_DOME, FALSE
	compare VAR_RESULT, 0
	goto_if_eq CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_52
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_51:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
	return

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_16:
	goto_if_ne VAR_0x8007, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_12
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_15

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_20:
	goto_if_ne VAR_0x8007, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_10
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_19

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_23:
	goto_if_ne VAR_0x800B, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_9
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_21

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_26:
	goto_if_ne VAR_0x8007, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_8
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_24

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_27:
	goto_if_ne VAR_0x800B, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_26
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_24

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_33:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowDomeFossil
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_31

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_34:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowHelixFossil
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_31

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_35:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowOldAmber
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_31

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_38:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowDomeFossil
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_36

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_39:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowHelixFossil
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_36

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_42:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowHelixFossil
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_40

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_43:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowOldAmber
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_40

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_45:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowHelixFossil
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_44

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_49:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowDomeFossil
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_47

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_50:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowOldAmber
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_47

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_52:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowDomeFossil
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_51

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_55:
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowOldAmber
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist_54

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowHelixFossil::
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
	bufferitemname STR_VAR_2, ITEM_HELIX_FOSSIL
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_HELIX_FOSSIL
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, HELIX_FOSSIL
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowDomeFossil::
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
	bufferitemname STR_VAR_2, ITEM_DOME_FOSSIL
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_DOME_FOSSIL
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, DOME_FOSSIL
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowOldAmber::
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
	bufferitemname STR_VAR_2, ITEM_OLD_AMBER
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor
	textcolor NPC_TEXT_COLOR_MALE
	removeitem ITEM_OLD_AMBER
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, OLD_AMBER
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil::
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_YouComeAgain
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilStillReviving::
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveRevivedMon::
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, HELIX_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveOmanyte
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, DOME_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveKabuto
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, OLD_AMBER, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveAerodactyl
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveOmanyte::
	setvar VAR_TEMP_1, SPECIES_OMANYTE
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilMonBackToLife
	givemon SPECIES_OMANYTE, 40
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
	setflag FLAG_REVIVED_HELIX
	goto_if_eq VAR_RESULT, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveKabuto::
	setvar VAR_TEMP_1, SPECIES_KABUTO
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilMonBackToLife
	givemon SPECIES_KABUTO, 40
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
	setflag FLAG_REVIVED_DOME
	goto_if_eq VAR_RESULT, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveAerodactyl::
	setvar VAR_TEMP_1, SPECIES_AERODACTYL
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilMonBackToLife
	givemon SPECIES_AERODACTYL, 40
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
	setflag FLAG_REVIVED_AMBER
	goto_if_eq VAR_RESULT, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty
	goto_if_eq VAR_RESULT, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_ReceivedMonFromDoctor
	waitmessage
	waitfanfare
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 0
	callnative CheckNuzlockeMode
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameFossilParty
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_EndGiveMon
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameFossilParty::
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_EndGiveMon
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_ReceivedMonFromDoctor
	waitmessage
	waitfanfare
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 0
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameFossilPC
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_MonSentToPC
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameFossilPC::
	call EventScript_NameReceivedBoxMon
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_MonSentToPC
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_MonSentToPC::
	call EventScript_TransferredToPC
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_EndGiveMon
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_EndGiveMon::
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_RevivedAllFossils::
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_YouComeAgain
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil::
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_NoIsTooBad
	release
	end

