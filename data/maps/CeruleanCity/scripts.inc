.set LOCALID_POLICEMAN, 1
.set LOCALID_GRUNT,     2
.set LOCALID_SLOWBRO,   5
.set LOCALID_LASS,      6
.set LOCALID_RIVAL,     8
.set LOCALID_WOMAN,     11
.set LOCALID_POLIWRATH_MASTER, 13
.set LOCALID_JYNX_MASTER,      14
.set TRAINER, VAR_0x8009
.equ TOTODILE_PRICE, 5000

CeruleanCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_OnTransition
	.byte 0

CeruleanCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CERULEAN_CITY
	call_if_unset FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_BlockExits
	goto CeruleanCity_MapScript_SetMasterTrainerMovementTypes
	end

CeruleanCity_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_POLIWRATH
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, CeruleanCity_MapScript_PoliwrathMasterMovementType
	setvar TRAINER, MASTER_JYNX
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, CeruleanCity_MapScript_JynxMasterMovementType
	end

CeruleanCity_MapScript_PoliwrathMasterMovementType::
	setobjectmovementtype LOCALID_POLIWRATH_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return
	
CeruleanCity_MapScript_JynxMasterMovementType::
	setobjectmovementtype LOCALID_JYNX_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

CeruleanCity_EventScript_BlockExits::
	setobjectxyperm LOCALID_POLICEMAN, 30, 12
	setobjectxyperm LOCALID_SLOWBRO, 26, 31
	setobjectxyperm LOCALID_LASS, 27, 31
	return

CeruleanCity_EventScript_RivalTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_RIVAL, 23, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm LOCALID_RIVAL, 24, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_Rival::
	textcolor NPC_TEXT_COLOR_MALE
	setvar VAR_MAP_SCENE_ROUTE22, 2
	playbgm MUS_ENCOUNTER_RIVAL, 0
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalEnter
	waitmovement 0
	msgbox CeruleanCity_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_RIVAL
	call_if_eq VAR_STARTER_MON, 2, CeruleanCity_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, CeruleanCity_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, CeruleanCity_EventScript_RivalCharmander
	famechecker FAMECHECKER_BILL, 0
	msgbox CeruleanCity_Text_RivalPostBattle
	closemessage
	playbgm MUS_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 1, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 2, CeruleanCity_EventScript_RivalStartExitRight
	msgbox CeruleanCity_Text_OhRightLittlePresentAsFavor
	setvar VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1
	setflag FLAG_GOT_FAME_CHECKER
	giveitem ITEM_FAME_CHECKER
	msgbox CeruleanCity_Text_ExplainFameCheckerSmellYa
	closemessage
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_RIVAL
	releaseall
	end

CeruleanCity_EventScript_RivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_SQUIRTLE, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_BULBASAUR, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_CHARMANDER, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalStartExit::
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExit
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalStartExit
	waitmovement 0
	return

CeruleanCity_EventScript_RivalStartExitRight::
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExitRight
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalStartExitRight
	waitmovement 0
	return

CeruleanCity_Movement_PlayerWatchRivalExit::
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

CeruleanCity_Movement_PlayerWatchRivalExitRight::
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

CeruleanCity_Movement_RivalEnter::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Movement_RivalStartExit::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalStartExitRight::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalExit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_EventScript_Grunt::
	lock
	faceplayer
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_EventScript_GruntDefeated
	message CeruleanCity_Text_GruntIntro
	waitmessage
	playbgm MUS_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	goto CeruleanCity_EventScript_GruntDefeated
	end

CeruleanCity_EventScript_GruntDefeated::
	msgbox CeruleanCity_Text_OkayIllReturnStolenTM
	checkitemspace ITEM_TM28
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_EventScript_NoRoomForTM28
	giveitem_msg CeruleanCity_Text_RecoveredTM28FromGrunt, ITEM_TM28
	msgbox CeruleanCity_Text_BetterGetMovingBye
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_GRUNT
	fadescreen FADE_FROM_BLACK
	setflag FLAG_GOT_TM28_FROM_ROCKET
	release
	end

CeruleanCity_EventScript_NoRoomForTM28::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox CeruleanCity_Text_MakeRoomForThisCantRun
	release
	end

CeruleanCity_EventScript_GruntTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	goto CeruleanCity_EventScript_GruntTrigger
	end

CeruleanCity_EventScript_GruntTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto CeruleanCity_EventScript_GruntTrigger
	end

CeruleanCity_EventScript_GruntTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox CeruleanCity_Text_GruntIntro
	setvar VAR_LAST_TALKED, LOCALID_GRUNT
	setflag FLAG_HIDE_SUICUNE_ROAM
	setflag FLAG_HIDE_ENTEI_ROAM
	setflag FLAG_HIDE_RAIKOU_ROAM
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	goto CeruleanCity_EventScript_GruntDefeated
	end

CeruleanCity_EventScript_Policeman::
	lock
	faceplayer
	msgbox CeruleanCity_Text_PeopleHereWereRobbed
	closemessage
	applymovement LOCALID_POLICEMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeruleanCity_EventScript_LittleBoy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_CERULEAN_CAVE_GUARD, CeruleanCity_EventScript_LittleBoySlowbroMoved
	msgbox CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree
	release
	end

CeruleanCity_EventScript_LittleBoySlowbroMoved::
	msgbox CeruleanCity_Text_YouCanCutDownSmallTrees
	release
	end

CeruleanCity_EventScript_BaldingMan::
	msgbox CeruleanCity_Text_PokemonEncyclopediaAmusing, MSGBOX_NPC
	end

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_TrainerLifeIsToughIsntIt, MSGBOX_NPC
	end

CeruleanCity_EventScript_CeruleanCaveGuard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_EventScript_Woman::
	lock
	faceplayer
	msgbox CeruleanCity_Text_WantBrightRedBicycle
	closemessage
	applymovement LOCALID_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeruleanCity_EventScript_Lass::
	lock
	random 3
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroCommand1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroCommand2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroCommand3
	waitmessage
	delay 40
	playse SE_PIN
	applymovement LOCALID_SLOWBRO, Common_Movement_QuestionMark
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroFailed1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroFailed2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroFailed3
	release
	end

CeruleanCity_EventScript_SlowbroCommand1::
	message CeruleanCity_Text_SlowbroUseSonicboom
	return

CeruleanCity_EventScript_SlowbroCommand2::
	message CeruleanCity_Text_SlowbroPunch
	return

CeruleanCity_EventScript_SlowbroCommand3::
	message CeruleanCity_Text_SlowbroWithdraw
	return

CeruleanCity_EventScript_SlowbroFailed1::
	msgbox CeruleanCity_Text_SlowbroPayAttention
	return

CeruleanCity_EventScript_SlowbroFailed2::
	msgbox CeruleanCity_Text_NoYouBlewItAgain
	return

CeruleanCity_EventScript_SlowbroFailed3::
	msgbox CeruleanCity_Text_HardToControlMonsObedience
	return

CeruleanCity_EventScript_Slowbro::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroText1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroText2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroText3
	call_if_eq VAR_0x8008, 3, CeruleanCity_EventScript_SlowbroText4
	release
	end

CeruleanCity_EventScript_SlowbroText1::
	msgbox CeruleanCity_Text_SlowbroTookSnooze
	return

CeruleanCity_EventScript_SlowbroText2::
	msgbox CeruleanCity_Text_SlowbroLoafingAround
	return

CeruleanCity_EventScript_SlowbroText3::
	msgbox CeruleanCity_Text_SlowbroTurnedAway
	return

CeruleanCity_EventScript_SlowbroText4::
	msgbox CeruleanCity_Text_SlowbroIgnoredOrders
	return

CeruleanCity_EventScript_CitySign::
	msgbox CeruleanCity_Text_CitySign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_TrainerTips::
	msgbox CeruleanCity_Text_TrainerTipsHeldItems, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_MISTY, 0
	msgbox CeruleanCity_Text_GymSign
	releaseall
	end

CeruleanCity_EventScript_SetCeruleanCaveWarp::
	callnative DetermineCeruleanCaveLayout
	compare VAR_RESULT, 0
	goto_if_eq CeruleanCity_EventScript_SetCeruleanCaveRG
	compare VAR_RESULT, 1
	goto_if_eq CeruleanCity_EventScript_SetCeruleanCaveRB
	compare VAR_RESULT, 2
	goto_if_eq CeruleanCity_EventScript_SetCeruleanCaveY
	end

CeruleanCity_EventScript_SetCeruleanCaveRG::
	setdynamicwarp MAP_CERULEAN_CAVE_1F, 255, 33, 21
	release
	end

CeruleanCity_EventScript_SetCeruleanCaveRB::
	setdynamicwarp MAP_CERULEAN_CAVE_1F_BLUE, 255, 33, 21
	release
	end

CeruleanCity_EventScript_SetCeruleanCaveY::
	setdynamicwarp MAP_CERULEAN_CAVE_1F_YELLOW, 255, 33, 21
	release
	end

Cerulean_City_EventScript_TotodileSalesman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TOTODILE, Cerulean_City_EventScript_AlreadyBoughtTotodile
	showmoneybox 0, 0, 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Cerulean_City_EventScript_AskBuyTotodileMale
	compare VAR_RESULT, FEMALE
	goto_if_eq Cerulean_City_EventScript_AskBuyTotodileFemale
	end

Cerulean_City_EventScript_AskBuyTotodileMale::
	msgbox Cerulean_City_Text_LaddieBuyTotodileForJust500, MSGBOX_YESNO
	goto Cerulean_City_EventScript_TryBuyTotodile
	end

Cerulean_City_EventScript_AskBuyTotodileFemale::
	msgbox Cerulean_City_Text_SweetieBuyTotodileForJust500, MSGBOX_YESNO
	goto Cerulean_City_EventScript_TryBuyTotodile
	end

Cerulean_City_EventScript_TryBuyTotodile::
	compare VAR_RESULT, NO
	goto_if_eq Cerulean_City_EventScript_DeclineTotodile
	checkmoney TOTODILE_PRICE, 0
	compare VAR_RESULT, FALSE
	goto_if_eq Cerulean_City_EventScript_NotEnoughMoney
	textcolor 3
	setvar VAR_TEMP_1, SPECIES_TOTODILE
	givemon SPECIES_TOTODILE, 15, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq Cerulean_City_EventScript_BuyTotodileParty
	compare VAR_RESULT, 1
	goto_if_eq Cerulean_City_EventScript_BuyTotodilePC
	compare VAR_RESULT, 2
	goto_if_eq Cerulean_City_EventScript_NoRoomForTotodile
	end

Cerulean_City_EventScript_BuyTotodileParty::
	call Cerulean_City_EventScript_PayForTotodile
	goto_if_eq CeladonCity_Condominiums_RoofRoom_EventScript_NicknameTotodileParty
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Cerulean_City_EventScript_EndPurchaseTotodile
CeladonCity_Condominiums_RoofRoom_EventScript_NicknameTotodileParty::
	call EventScript_GetGiftMonPartySlot
	fadescreen FADE_TO_BLACK
	hidemoneybox
	special ChangePokemonNickname
	waitstate
	goto Cerulean_City_EventScript_BoughtTotodile
	end

Cerulean_City_EventScript_BuyTotodilePC::
	call Cerulean_City_EventScript_PayForTotodile
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq CeladonCity_Condominiums_RoofRoom_EventScript_NicknameTotodilePC
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Cerulean_City_EventScript_TransferTotodileCloseMoneyBox
CeladonCity_Condominiums_RoofRoom_EventScript_NicknameTotodilePC::
	fadescreen FADE_TO_BLACK
	hidemoneybox
	special ChangeBoxPokemonNickname
	waitstate
	lock
	faceplayer
	goto Cerulean_City_EventScript_TransferTotodile
	end

Cerulean_City_EventScript_TransferTotodileCloseMoneyBox::
	call EventScript_TransferredToPC
	goto Cerulean_City_EventScript_EndPurchaseTotodile
	end

Cerulean_City_EventScript_TransferTotodile::
	call EventScript_TransferredToPC
	goto Cerulean_City_EventScript_BoughtTotodile
	end

Cerulean_City_EventScript_EndPurchaseTotodile::
	hidemoneybox
	goto Cerulean_City_EventScript_BoughtTotodile
	end

Cerulean_City_EventScript_BoughtTotodile::
	setflag FLAG_GOT_TOTODILE
	release
	end

Cerulean_City_EventScript_PayForTotodile::
	removemoney TOTODILE_PRICE, 0
	updatemoneybox 0
	playfanfare MUS_LEVEL_UP
	message Cerulean_City_Text_PaidOutrageouslyForTotodile
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_TOTODILE
	return

Cerulean_City_EventScript_DeclineTotodile::
	msgbox Cerulean_City_Text_OnlyDoingThisAsFavorToYou
	hidemoneybox
	release
	end

Cerulean_City_EventScript_NotEnoughMoney::
	msgbox Cerulean_City_Text_YoullNeedMoreMoney
	hidemoneybox
	release
	end

Cerulean_City_EventScript_AlreadyBoughtTotodile::
	msgbox Cerulean_City_Text_IDontGiveRefunds
	release
	end

Cerulean_City_EventScript_NoRoomForTotodile::
	textcolor 0
	msgbox Cerulean_City_Text_NoRoomForMorePokemon
	hidemoneybox
	release
	end
