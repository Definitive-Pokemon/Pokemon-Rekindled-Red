.equ LOCALID_FERRY_SAILOR, 6
.set LOCALID_MACHAMP_MASTER, 9
.set LOCALID_FARFETCHD_MASTER, 10
.set TRAINER, VAR_0x8009

.equ HAS_TICKETS, 16
.equ NEEDS_SHOW_EON, 17
.equ NEEDS_SHOW_AURORA, 18
.equ NEEDS_SHOW_MYSTIC, 19
.equ NEEDS_SHOW_OLD_SEA_MAP, 20
.equ HAS_NO_TICKETS, 21
.equ F, 1
.equ N, 2
.equ NF, 3
.equ B, 4
.equ BF, 5
.equ BN, 6
.equ BNF, 7
.equ S, 8
.equ SF, 9
.equ SN, 10
.equ SNF, 11
.equ SB, 12
.equ SBF, 13
.equ SBN, 14
.equ SBNF, 15

VermilionCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_OnFrame
	.byte 0

VermilionCity_OnFrame::
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 2, VermilionCity_EventScript_ExitSSAnne
	.2byte 0

VermilionCity_EventScript_ExitSSAnne::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_ExitSSAnne
	waitmovement 0
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
	releaseall
	end

VermilionCity_Movement_ExitSSAnne::
	walk_up
	walk_up
	step_end

VermilionCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
	call_if_set FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION, VermilionCity_EventScript_HideOaksAide
	goto VermilionCity_MapScript_SetMasterTrainerMovementTypes
	end

VermilionCity_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_MACHAMP
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, VermilionCity_MapScript_MachampMasterMovementType
	setvar TRAINER, MASTER_FARFETCHD
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, VermilionCity_MapScript_FarfetchdMasterMovementType
	end

VermilionCity_MapScript_MachampMasterMovementType::
	setobjectmovementtype LOCALID_MACHAMP_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return
	
VermilionCity_MapScript_FarfetchdMasterMovementType::
	setobjectmovementtype LOCALID_FARFETCHD_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

VermilionCity_EventScript_HideOaksAide::
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
	return

VermilionCity_EventScript_Woman::
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
	end

VermilionCity_EventScript_OldMan1::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
	release
	end

VermilionCity_EventScript_OldMan1SSAnneLeft::
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
	release
	end

VermilionCity_EventScript_FerrySailor::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
	release
	end

VermilionCity_EventScript_CheckSeagallopPresent::
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
	msgbox VermilionCity_Text_TheShipSetSail
	release
	end

VermilionCity_EventScript_SetSailToBattleTower::
	msgbox VermilionCity_Text_Seagallop13Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_BATTLE_TOWER
	goto EventScript_SetSail
	end

VermilionCity_EventScript_SetSailToSouthernIsland::
	msgbox VermilionCity_Text_Seagallop13Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_SOUTHERN_ISLAND
	goto EventScript_SetSail
	end

VermilionCity_EventScript_SetSailToFarawayIsland::
	msgbox VermilionCity_Text_Seagallop14Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_FARAWAY_ISLAND
	goto EventScript_SetSail
	end

VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
	setvar VAR_RESULT, 0
	callnative CheckEventTickets
	switch VAR_RESULT
	case NEEDS_SHOW_EON, VermilionCity_EventScript_ShowEonTicket
	case NEEDS_SHOW_AURORA, VermilionCity_EventScript_ShowAuroraTicket
	case NEEDS_SHOW_MYSTIC, VermilionCity_EventScript_ShowMysticTicket
	case NEEDS_SHOW_OLD_SEA_MAP, VermilionCity_EventScript_ShowOldSeaMap
	case HAS_TICKETS, VermilionCity_EventScript_HasTicketsRainbowPass
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	message VermilionCity_Text_BoardSeagallopRainbowPass
	waitmessage
	multichoice 13, 6, MULTICHOICE_SEVII_BATTLE_TOWER, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, VermilionCity_EventScript_SetSailToBattleTower
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_HasTicketsRainbowPass::
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	message VermilionCity_Text_BoardSeagallopRainbowPass
	waitmessage
	multichoice 13, 5, MULTICHOICE_SEVII_BATTLE_TOWER_OTHER, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, VermilionCity_EventScript_SetSailToBattleTower
	case 2, VermilionCity_EventScript_EventIslandsMultichoice
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_ShowOldSeaMap::
	setflag FLAG_SHOWN_OLD_SEA_MAP
	msgbox VermilionCity_Text_OldSeaMapTakeYouToFarawayIsland
	goto VermilionCity_EventScript_CheckSeagallopPresentTrigger

VermilionCity_EventScript_ShowMysticTicket::
	setflag FLAG_SHOWN_MYSTIC_TICKET
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
	goto VermilionCity_EventScript_CheckSeagallopPresentTrigger

VermilionCity_EventScript_ShowAuroraTicket::
	setflag FLAG_SHOWN_AURORA_TICKET
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
	goto VermilionCity_EventScript_CheckSeagallopPresentTrigger

EventScript_SailToNavelRock::
	msgbox VermilionCity_Text_Seagallop10Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
	goto EventScript_SetSail
	end

EventScript_SailToBirthIsland::
	msgbox VermilionCity_Text_Seagallop12Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
	goto EventScript_SetSail
	end

VermilionCity_EventScript_ChooseSeagallopDestTriPass::
	setvar VAR_RESULT, 0
	callnative CheckEventTickets
	switch VAR_RESULT
	case NEEDS_SHOW_EON, VermilionCity_EventScript_ShowEonTicket
	case NEEDS_SHOW_AURORA, VermilionCity_EventScript_ShowAuroraTicket
	case NEEDS_SHOW_MYSTIC, VermilionCity_EventScript_ShowMysticTicket
	case NEEDS_SHOW_OLD_SEA_MAP, VermilionCity_EventScript_ShowOldSeaMap
	case HAS_TICKETS, VermilionCity_EventScript_HasTicketsTriPass
	message VermilionCity_Text_BoardSeagallopTriPass
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
VermilionCity_EventScript_TriPassOriginalMultichoice:
	multichoice 19, 5, MULTICHOICE_SEAGALLOP_123, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToOneIsland2
	case 1, EventScript_SailToTwoIsland2
	case 2, EventScript_SailToThreeIsland2
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

VermilionCity_EventScript_ShowEonTicket::
	setflag FLAG_SHOWN_EON_TICKET
	msgbox VermilionCity_Text_OhEonTicketTakeYouToSouthernIsland
	goto VermilionCity_EventScript_CheckSeagallopPresentTrigger

VermilionCity_EventScript_HasTicketsTriPass::
	message VermilionCity_Text_BoardSeagallopTriPass
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	multichoice 13, 6, MULTICHOICE_SEVII_OTHER, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_TriPassOriginalMultichoice
	case 1, VermilionCity_EventScript_EventIslandsMultichoice
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

VermilionCity_EventScript_EventIslandsMultichoice::
	setvar VAR_RESULT, 1
	callnative CheckEventTickets
	buffernumberstring STR_VAR_1, VAR_RESULT
	switch VAR_RESULT
	case F, VermilionCity_EventScript_Faraway
	case N, VermilionCity_EventScript_Navel
	case NF, VermilionCity_EventScript_NavelFaraway
	case B, VermilionCity_EventScript_Birth
	case BF, VermilionCity_EventScript_BirthFaraway
	case BN, VermilionCity_EventScript_BirthNavel
	case BNF, VermilionCity_EventScript_BirthNavelFaraway
	case S, VermilionCity_EventScript_Southern
	case SF, VermilionCity_EventScript_SouthernFaraway
	case SN, VermilionCity_EventScript_SouthernNavel
	case SNF, VermilionCity_EventScript_SouthernNavelFaraway
	case SB, VermilionCity_EventScript_SouthernBirth
	case SBF, VermilionCity_EventScript_SouthernBirthFaraway
	case SBN, VermilionCity_EventScript_SouthernBirthNavel
	case SBNF, VermilionCity_EventScript_SouthernBirthNavelFaraway
	end

VermilionCity_EventScript_Faraway::
	multichoice 13, 8, MULTICHOICE_FARAWAY, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToFarawayIsland
	case 1, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_Navel::
	multichoice 13, 8, MULTICHOICE_NAVEL, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToNavelRock
	case 1, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_NavelFaraway::
	multichoice 13, 6, MULTICHOICE_NAVEL_FARAWAY, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToNavelRock
	case 1, VermilionCity_EventScript_SetSailToFarawayIsland
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_Birth::
	multichoice 13, 8, MULTICHOICE_BIRTH, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToBirthIsland
	case 1, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_BirthFaraway::
	multichoice 13, 6, MULTICHOICE_BIRTH_FARAWAY, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToBirthIsland
	case 1, VermilionCity_EventScript_SetSailToFarawayIsland
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_BirthNavel::
	multichoice 13, 6, MULTICHOICE_BIRTH_NAVEL, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToBirthIsland
	case 1, EventScript_SailToNavelRock
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_BirthNavelFaraway::
	multichoice 13, 5, MULTICHOICE_BIRTH_NAVEL_FARAWAY, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToBirthIsland
	case 1, EventScript_SailToNavelRock
	case 2, VermilionCity_EventScript_SetSailToFarawayIsland
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_Southern::
	multichoice 13, 8, MULTICHOICE_SOUTHERN, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToSouthernIsland
	case 1, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_SouthernFaraway::
	multichoice 13, 6, MULTICHOICE_SOUTHERN_FARAWAY, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToSouthernIsland
	case 1, VermilionCity_EventScript_SetSailToFarawayIsland
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_SouthernNavel::
	multichoice 13, 6, MULTICHOICE_SOUTHERN_NAVEL, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToSouthernIsland
	case 1, EventScript_SailToNavelRock
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_SouthernNavelFaraway::
	multichoice 13, 5, MULTICHOICE_SOUTHERN_NAVEL_FARAWAY, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToSouthernIsland
	case 1, EventScript_SailToNavelRock
	case 2, VermilionCity_EventScript_SetSailToFarawayIsland
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_SouthernBirth::
	multichoice 13, 6, MULTICHOICE_SOUTHERN_BIRTH, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToSouthernIsland
	case 1, EventScript_SailToBirthIsland
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_SouthernBirthFaraway::
	multichoice 13, 5, MULTICHOICE_SOUTHERN_BIRTH_FARAWAY, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToSouthernIsland
	case 1, EventScript_SailToBirthIsland
	case 2, VermilionCity_EventScript_SetSailToFarawayIsland
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_SouthernBirthNavel::
	multichoice 13, 5, MULTICHOICE_SOUTHERN_BIRTH_NAVEL, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToSouthernIsland
	case 1, EventScript_SailToBirthIsland
	case 2, EventScript_SailToNavelRock
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_SouthernBirthNavelFaraway::
	multichoice 13, 3, MULTICHOICE_SOUTHERN_BIRTH_NAVEL_FARAWAY, FALSE
	switch VAR_RESULT
	case 0, VermilionCity_EventScript_SetSailToSouthernIsland
	case 1, EventScript_SailToBirthIsland
	case 2, EventScript_SailToNavelRock
	case 3, VermilionCity_EventScript_SetSailToFarawayIsland
	case 4, EventScript_CancelSail
	case 127, EventScript_CancelSail 
	end

VermilionCity_EventScript_CheckTicketLeft::
	lockall
	goto VermilionCity_EventScript_CheckTicket
	end

VermilionCity_EventScript_CheckTicketRight::
	lockall
	goto VermilionCity_EventScript_CheckTicket
	end

VermilionCity_EventScript_ExitedTicketCheck::
	lockall
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
	releaseall
	end

VermilionCity_EventScript_CheckTicket::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
	msgbox VermilionCity_Text_DoYouHaveATicket
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
	msgbox VermilionCity_Text_FlashedSSTicket
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
	releaseall
	end

VermilionCity_EventScript_DontHaveSSTicket::
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
	closemessage
	goto VermilionCity_EventScript_WalkUpPier
	end

VermilionCity_EventScript_CheckSeagallopPresentTrigger::
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
	msgbox VermilionCity_Text_TheShipSetSail
	closemessage
	goto VermilionCity_EventScript_WalkUpPier
	end

VermilionCity_EventScript_Sailor::
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
	end

VermilionCity_EventScript_OaksAide::
	lock
	faceplayer
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
	release
	end

VermilionCity_EventScript_OldMan2::
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
	end

VermilionCity_EventScript_Machop::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	msgbox VermilionCity_Text_Machop
	waitmoncry
	msgbox VermilionCity_Text_MachopStompingLandFlat
	release
	end

VermilionCity_EventScript_CitySign::
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
	end

VermilionCity_EventScript_SnorlaxNotice::
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
	end

VermilionCity_EventScript_PokemonFanClubSign::
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

VermilionCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_LTSURGE, 0
	msgbox VermilionCity_Text_GymSign
	releaseall
	end

VermilionCity_EventScript_HarborSign::
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
	end

VermilionCity_EventScript_PoliceMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SQUIRTLE_FROM_POLICE, VermilionCity_EventScript_AlreadyGotSquirtle
	goto_if_set FLAG_BADGE03_GET, VermilionCity_EventScript_WantSquirtle
	msgbox VermilionCity_Text_JustCaughtASquirtle
	release
	end

VermilionCity_EventScript_WantSquirtle::
	msgbox VermilionCity_Text_WantThisSquirtle, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq VermilionCity_EventScript_GiveSquirtle
	msgbox VermilionCity_Text_Oh
	release
	end

VermilionCity_EventScript_GiveSquirtle::
	setvar VAR_TEMP_1, SPECIES_SQUIRTLE
	givemon SPECIES_SQUIRTLE, 20, ITEM_THUNDER_STONE
	compare VAR_RESULT, 0
	goto_if_eq VermilionCity_EventScript_ReceiveSquirtleParty
	compare VAR_RESULT, 1
	goto_if_eq VermilionCity_EventScript_ReceiveSquirtlePC
	compare VAR_RESULT, 2
	goto_if_eq EventScript_NoMoreRoomForPokemon
	release
	end

VermilionCity_EventScript_ReceiveSquirtleParty::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message VermilionCity_Text_ObtainedSquirtleFromPolice
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_SQUIRTLE
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq VermilionCity_EventScript_NicknameSquirtleParty
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VermilionCity_EventScript_EndReceiveSquirtle
	VermilionCity_EventScript_NicknameSquirtleParty::
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto VermilionCity_EventScript_EndReceiveSquirtle
	end

VermilionCity_EventScript_ReceiveSquirtlePC::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message VermilionCity_Text_ObtainedSquirtleFromPolice
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_SQUIRTLE
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq VermilionCity_EventScript_NicknameSquirtlePC
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VermilionCity_EventScript_SquirtleTransferredToPC
	VermilionCity_EventScript_NicknameSquirtlePC::
	call EventScript_NameReceivedBoxMon
	goto VermilionCity_EventScript_SquirtleTransferredToPC
	end

VermilionCity_EventScript_SquirtleTransferredToPC::
	call EventScript_TransferredToPC
	goto VermilionCity_EventScript_EndReceiveSquirtle
	end

VermilionCity_EventScript_EndReceiveSquirtle::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox VermilionCity_Text_TreatHimRight
	setflag FLAG_GOT_SQUIRTLE_FROM_POLICE
	release
	end

VermilionCity_EventScript_AlreadyGotSquirtle::
	msgbox VermilionCity_Text_HowIsSquirtle
	release
	end
	