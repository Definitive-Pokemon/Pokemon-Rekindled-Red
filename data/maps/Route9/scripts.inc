.set LOCALID_NINETALES_MASTER, 13
.set TRAINER, VAR_0x8009
.equ LOCALID_BULBASAUR, 14
.equ LOCALID_LADY, 15

Route9_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_MapScript_SetMasterTrainerMovementTypes
	map_script MAP_SCRIPT_ON_RESUME, Route9_MapScript_OnResume
	.byte 0

Route9_MapScript_OnResume::
	compare VAR_TEMP_1, SPECIES_BULBASAUR
	goto_if_ne Route9_ResumeContinue
	faceplayer
Route9_ResumeContinue::
	end

Route9_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_NINETALES
	callnative ShouldChangeMasterTrainerMovementType
	compare VAR_RESULT, FALSE
	call_if_eq Route9_MapScript_NinetalesMasterMovementType
	end

Route9_MapScript_NinetalesMasterMovementType::
	setobjectmovementtype LOCALID_NINETALES_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route9_EventScript_RouteSign::
	msgbox Route9_Text_RouteSign, MSGBOX_SIGN
	end

Route9_EventScript_Bulbasaur::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BULBASAUR, CRY_MODE_WEAK
	msgbox Route9_Text_Bulbasaur
	waitmoncry
	msgbox Route9_Text_BulbasaurWeak
	release
	end

Route9_EventScript_Lady::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BULBASAUR_FROM_LADY, Route9_EventScript_AlreadyGotBulbasaur
	checkitem ITEM_SUPER_POTION, 1
	compare VAR_RESULT, TRUE
	goto_if_ge Route9_EventScript_WantBulbasaur
	msgbox Route9_Text_FoundInjuredBulbasaur
	release
	end

Route9_EventScript_WantBulbasaur::
	msgbox Route9_Text_WantThisBulbasaur, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route9_EventScript_GiveBulbasaur
	msgbox Route9_Text_Oh
	release
	end

Route9_EventScript_GiveBulbasaur::
	setvar VAR_TEMP_1, SPECIES_BULBASAUR
	givemon SPECIES_BULBASAUR, 20, ITEM_LEAF_STONE
	compare VAR_RESULT, 0
	goto_if_eq Route9_EventScript_ReceiveBulbasaurParty
	compare VAR_RESULT, 1
	goto_if_eq Route9_EventScript_ReceiveBulbasaurPC
	compare VAR_RESULT, 2
	goto_if_eq EventScript_NoMoreRoomForPokemon
	release
	end

Route9_EventScript_ReceiveBulbasaurParty::
	applymovement LOCALID_BULBASAUR, Route9_Movement_Bulbasaur
	waitmovement 0
	msgbox Route9_Text_Administer
	applymovement OBJ_EVENT_ID_PLAYER, Route9_Movement_PlayerHeal
	waitmovement 0
	waitse
	playse SE_USE_ITEM
	applymovement LOCALID_BULBASAUR, Route9_Movement_BulbaJump
	waitmovement 0
	waitse
	playmoncry SPECIES_BULBASAUR, CRY_MODE_DOUBLES
	waitmoncry
	textcolor 3
	msgbox Route9_Text_BulbasaurEager
	removeobject LOCALID_BULBASAUR
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message Route9_Text_ObtainedBulbasaurFromLady
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_BULBASAUR
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq Route9_EventScript_NicknameBulbasaurParty
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route9_EventScript_EndReceiveBulbasaur
Route9_EventScript_NicknameBulbasaurParty::
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto Route9_EventScript_EndReceiveBulbasaur
	end

Route9_EventScript_ReceiveBulbasaurPC::
	applymovement LOCALID_BULBASAUR, Route9_Movement_Bulbasaur
	waitmovement 0
	msgbox Route9_Text_Administer
	applymovement OBJ_EVENT_ID_PLAYER, Route9_Movement_PlayerHeal
	waitmovement 0
	waitse
	playse SE_USE_ITEM
	applymovement LOCALID_BULBASAUR, Route9_Movement_BulbaJump
	waitmovement 0
	waitse
	playmoncry SPECIES_BULBASAUR, CRY_MODE_NORMAL
	waitmoncry
	textcolor 3
	msgbox Route9_Text_BulbasaurEager
	removeobject LOCALID_BULBASAUR
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message Route9_Text_ObtainedBulbasaurFromLady
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_BULBASAUR
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq Route9_EventScript_NicknameBulbasaurPC
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route9_EventScript_BulbasaurTransferredToPC
Route9_EventScript_NicknameBulbasaurPC::
	call EventScript_NameReceivedBoxMon
	goto Route9_EventScript_BulbasaurTransferredToPC
	end

Route9_EventScript_BulbasaurTransferredToPC::
	call EventScript_TransferredToPC
	goto Route9_EventScript_EndReceiveBulbasaur
	end

Route9_EventScript_EndReceiveBulbasaur::
	applymovement OBJ_EVENT_ID_PLAYER, Route9_Movement_PlayerBack
	waitmovement 0
	applymovement LOCALID_LADY, Route9_Movement_LadyBack
	waitmovement 0
	textcolor 1
	msgbox Route9_Text_TreatHimRight
	setflag FLAG_GOT_BULBASAUR_FROM_LADY
	removeitem ITEM_SUPER_POTION, 1
	release
	end

Route9_EventScript_AlreadyGotBulbasaur::
	msgbox Route9_Text_HowIsBulbasaur
	release
	end

Route9_Movement_Bulbasaur::
	walk_down
	walk_in_place_left
	step_end

Route9_Movement_PlayerHeal::
	walk_in_place_right
	step_end

Route9_Movement_BulbaJump::
	jump_in_place_left
	step_end
	
Route9_Movement_PlayerBack::
	walk_in_place_up
	step_end
	
Route9_Movement_LadyBack::
	walk_in_place_down
	step_end