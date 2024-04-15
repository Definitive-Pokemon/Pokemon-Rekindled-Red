.set LOCALID_MUDKIP, 1
.set LOCALID_LATIAS, 2
.set LOCALID_CLEFAIRY1, 3
.set LOCALID_CLEFAIRY2, 4
.set LOCALID_CLEFAIRY3, 5
.set LOCALID_CLEFAIRY4, 6
.set LOCALID_CLEFAIRY5, 7
.set LOCALID_AERODACTYL, 8


MtMoon_Square_MapScripts::
	.byte 0

MtMoon_Square_EventScript_LatiasFinal::
	lock
	faceplayer
	setwildbattle SPECIES_SEVIIAN_AERODACTYL, 70, ITEM_NONE
	waitse
	playmoncry SPECIES_LATIAS, 2
	waitmoncry
	delay 30
	applymovement LOCALID_AERODACTYL, MtMoon_Square_Movement_AerodactylScare
	playmoncry SPECIES_AERODACTYL, CRY_MODE_ECHO_START
	waitmoncry
	delay 10
	waitbuttonpress
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MtMoon_Square_EventScript_DefeatedAerodactyl
	setflag FLAG_FOUGHT_AERODACTYL
	release
	end

MtMoon_Square_EventScript_Latias4::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, MtMoon_Square_Movement_FaceUp
	waitmovement 0
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MtMoon_Square_Movement_PanToActionFromBottom
	waitmovement 0
	special RemoveCameraObject
	delay 60
	applymovement LOCALID_CLEFAIRY1, MtMoon_Square_Movement_ClefairyJump1
	applymovement LOCALID_CLEFAIRY2, MtMoon_Square_Movement_ClefairyJump2
	applymovement LOCALID_CLEFAIRY3, MtMoon_Square_Movement_ClefairyJump3
	applymovement LOCALID_CLEFAIRY4, MtMoon_Square_Movement_ClefairyJump4
	applymovement LOCALID_CLEFAIRY5, MtMoon_Square_Movement_ClefairyJump5
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	playmoncry SPECIES_LATIAS, CRY_MODE_NORMAL
	waitmoncry
	delay 100
	playse SE_PIN
	applymovement LOCALID_CLEFAIRY1, MtMoon_Square_Movement_MudkipExclamation
	applymovement LOCALID_CLEFAIRY2, MtMoon_Square_Movement_MudkipExclamation
	applymovement LOCALID_CLEFAIRY3, MtMoon_Square_Movement_MudkipExclamation
	applymovement LOCALID_CLEFAIRY4, MtMoon_Square_Movement_MudkipExclamation
	applymovement LOCALID_CLEFAIRY5, MtMoon_Square_Movement_MudkipExclamation
	waitmovement 0
	applymovement LOCALID_CLEFAIRY1, MtMoon_Square_Movement_ClefairyLookDown
	applymovement LOCALID_CLEFAIRY2, MtMoon_Square_Movement_ClefairyLookDown
	applymovement LOCALID_CLEFAIRY3, MtMoon_Square_Movement_ClefairyLookDown
	applymovement LOCALID_CLEFAIRY4, MtMoon_Square_Movement_ClefairyLookDown
	applymovement LOCALID_CLEFAIRY5, MtMoon_Square_Movement_ClefairyLookDown
	waitse
	delay 30
	waitmovement 0
	applymovement LOCALID_CLEFAIRY1, MtMoon_Square_Movement_Clefairy1Leave
	applymovement LOCALID_CLEFAIRY2, MtMoon_Square_Movement_Clefairy2Leave
	applymovement LOCALID_CLEFAIRY3, MtMoon_Square_Movement_Clefairy3Leave
	applymovement LOCALID_CLEFAIRY4, MtMoon_Square_Movement_Clefairy4Leave
	applymovement LOCALID_CLEFAIRY5, MtMoon_Square_Movement_Clefairy5Leave
	waitmovement 0
	playmoncry SPECIES_LATIAS, CRY_MODE_NORMAL
	waitmoncry
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MtMoon_Square_Movement_PanToActionFromTop
	waitmovement 0
	special RemoveCameraObject
	delay 60
	removeobject LOCALID_CLEFAIRY1
	removeobject LOCALID_CLEFAIRY2
	removeobject LOCALID_CLEFAIRY3
	removeobject LOCALID_CLEFAIRY4
	removeobject LOCALID_CLEFAIRY5
	setflag FLAG_HIDE_CLEFAIRY
	setvar VAR_LATIAS_FOURTH, 2
	setvar VAR_LATIAS_FINAL, 1
	releaseall
	end

MtMoon_Square_EventScript_WelcomeSign::
	msgbox MtMoon_Square_Text_Sign, MSGBOX_SIGN
	end

MtMoon_Square_EventScript_MudkipStand::
	lock
	faceplayer
	compare VAR_MT_MOON_MUDKIP_BERRY_GIVEN, 1
	goto_if_eq MtMoon_Square_EventScript_MudkipHappy
	playmoncry SPECIES_MUDKIP, CRY_MODE_ENCOUNTER
	textcolor 2
	msgbox MtMoon_Square_Text_MudkipNoise
	waitmoncry
	release
	end

MtMoon_Square_EventScript_Mudkip::
	lockall
	playse SE_PIN
	applymovement LOCALID_MUDKIP, MtMoon_Square_Movement_MudkipExclamation
	waitmovement 0
	applymovement LOCALID_MUDKIP, MtMoon_Square_Movement_MudkipJump3times
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	waitse
	playmoncry SPECIES_MUDKIP, CRY_MODE_ENCOUNTER
	textcolor 2
	msgbox MtMoon_Square_Text_MudkipNoise
	waitmoncry
	msgbox MtMoon_Square_Text_MudkipAngryFood, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MtMoon_Square_EventScript_MudkipGiveBerry
	waitse
	playmoncry SPECIES_MUDKIP, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox MtMoon_Square_Text_MudkipStillAngry
	releaseall
	end
	
MtMoon_Square_EventScript_MudkipGiveBerry::
	checkitem ITEM_SITRUS_BERRY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MtMoon_Square_EventScript_MudkipBerryTaken
	waitse
	playmoncry SPECIES_MUDKIP, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox MtMoon_Square_Text_MudkipStillAngry
	releaseall
	end
	
MtMoon_Square_EventScript_MudkipBerryTaken::
	removeitem ITEM_SITRUS_BERRY, 1
	setvar VAR_MT_MOON_MUDKIP_BERRY_GIVEN 1
	goto_if_eq MtMoon_Square_EventScript_MudkipHappy

MtMoon_Square_EventScript_MudkipHappy::
	applymovement LOCALID_MUDKIP, MtMoon_Square_Movement_MudkipJump2times
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	waitse
	playmoncry SPECIES_MUDKIP, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox MtMoon_Square_Text_MudkipHappyJoin, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MtMoon_Square_EventScript_GiveMudkip
	waitse
	playmoncry SPECIES_MUDKIP, CRY_MODE_WEAK
	waitmoncry
	msgbox MtMoon_Square_Text_MudkipSad
	releaseall
	end
	
MtMoon_Square_EventScript_GiveMudkip::
	setvar VAR_TEMP_1, SPECIES_MUDKIP
	givemon SPECIES_MUDKIP, 5, ITEM_SOFT_SAND
	compare VAR_RESULT, 0
	goto_if_eq MtMoon_Square_EventScript_ReceiveMudkipParty
	compare VAR_RESULT, 1
	goto_if_eq MtMoon_Square_EventScript_ReceiveMudkipPC
	compare VAR_RESULT, 2
	goto_if_eq EventScript_NoMoreRoomForPokemon
	release
	end

MtMoon_Square_EventScript_ReceiveMudkipParty::
	removeobject LOCALID_MUDKIP
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message MtMoon_Square_Text_ObtainedMudkip
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_MUDKIP
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq MtMoon_Square_EventScript_NicknameMudkipParty
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MtMoon_Square_EventScript_EndReceiveMudkip
	MtMoon_Square_EventScript_NicknameMudkipParty::
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto MtMoon_Square_EventScript_EndReceiveMudkip
	end

MtMoon_Square_EventScript_ReceiveMudkipPC::
	removeobject LOCALID_MUDKIP
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message MtMoon_Square_Text_ObtainedMudkip
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_MUDKIP
	callnative CheckNuzlockeMode
	compare VAR_RESULT, TRUE
	goto_if_eq MtMoon_Square_EventScript_NicknameMudkipPC
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MtMoon_Square_EventScript_MudkipTransferredToPC
	MtMoon_Square_EventScript_NicknameMudkipPC::
	call EventScript_NameReceivedBoxMon
	goto MtMoon_Square_EventScript_MudkipTransferredToPC
	end

MtMoon_Square_EventScript_MudkipTransferredToPC::
	call EventScript_TransferredToPC
	goto MtMoon_Square_EventScript_EndReceiveMudkip
	end
	
MtMoon_Square_EventScript_EndReceiveMudkip::
	setflag FLAG_GOT_MUDKIP
	release
	end
	
MtMoon_Square_Movement_Clefairy1Leave::
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	step_end
	
MtMoon_Square_Movement_Clefairy2Leave::
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	jump_2_up
	step_end
	
MtMoon_Square_Movement_Clefairy3Leave::
	jump_2_up
	jump_2_up
	jump_2_up
	step_end
	
MtMoon_Square_Movement_Clefairy4Leave::
	jump_2_up
	jump_2_up
	jump_2_up
	step_end
	
MtMoon_Square_Movement_Clefairy5Leave::
	jump_2_up
	jump_2_up
	jump_2_up
	step_end
	
MtMoon_Square_Movement_ClefairyLookDown::
	face_down
	step_end

MtMoon_Square_Movement_ClefairyJump1::
	jump_in_place_up
	step_end
	
MtMoon_Square_Movement_ClefairyJump2::
	jump_in_place_up
	step_end
	
MtMoon_Square_Movement_ClefairyJump3::
	jump_in_place_left
	step_end
	
MtMoon_Square_Movement_ClefairyJump4::
	jump_in_place_right
	step_end
	
MtMoon_Square_Movement_ClefairyJump5::
	jump_in_place_down
	step_end
	
MtMoon_Square_Movement_PanToActionFromBottom::
	walk_slow_up
	walk_slow_up
	walk_slow_left
	step_end
	
MtMoon_Square_Movement_PanToActionFromTop::
	walk_slow_right
	walk_slow_down
	walk_slow_down
	step_end
	
MtMoon_Square_Movement_FaceUp::
	walk_in_place_up
	step_end
	
MtMoon_Square_Movement_MudkipExclamation::
	emote_exclamation_mark
	step_end
	
MtMoon_Square_Movement_MudkipJump3times::
	jump_in_place_down
	jump_in_place_down
	jump_in_place_down
	step_end
	
MtMoon_Square_Movement_MudkipJump2times::
	jump_in_place_down
	jump_in_place_down
	step_end