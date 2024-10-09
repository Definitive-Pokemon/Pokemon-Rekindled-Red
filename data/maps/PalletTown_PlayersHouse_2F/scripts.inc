.equ LOCALID_MOM, 1

PalletTown_PlayersHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_PlayersHouse_2F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_PlayersHouse_2F_OnFrame
	.byte 0

PalletTown_PlayersHouse_2F_OnFrame::
	map_script_2 VAR_TEMP_0, 0, PalletTown_PlayersHouse_2F_EventScript_MomCheck
	.2byte 0


PalletTown_PlayersHouse_2F_EventScript_MomCheck::
	setvar VAR_TEMP_0, 1
	goto_if_set FLAG_MOM_GONE_DOWN, PalletTown_PlayersHouse_2F_EventScript_DontDoMomEvent
	goto_if_set FLAG_OAK_HAS_LETTER, PalletTown_PlayersHouse_2F_EventScript_Mom
	end

PalletTown_PlayersHouse_2F_EventScript_DontDoMomEvent::
	end
	
PalletTown_PlayersHouse_2F_EventScript_Mom:
	lockall
	delay 60
	playse SE_EXIT
	addobject LOCALID_MOM
	clearflag FLAG_HIDE_MOM
	applymovement LOCALID_MOM PalletTown_PlayersHouse_2F_Movement_MomGoUp
	waitmovement 0
	waitse
	applymovement LOCALID_MOM PalletTown_PlayersHouse_2F_Movement_MomLookDown
	waitmovement 0
	textcolor 1
	msgbox PalletTown_PlayersHouse_2F_Text_Mom MSGBOX_NPC
	playse SE_EXIT
	applymovement LOCALID_OLD_MAN PalletTown_PlayersHouse_2F_Movement_MomGo
	waitmovement 0
	waitse
	removeobject LOCALID_MOM
	setflag FLAG_HIDE_MOM
	setflag FLAG_MOM_GONE_DOWN
	releaseall
	end

PalletTown_PlayersHouse_2F_OnTransition::
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_EventScript_SetRespawn
	end

PalletTown_PlayersHouse_2F_EventScript_SetRespawn::
	setrespawn SPAWN_PALLET_TOWN
	return

PalletTown_PlayersHouse_2F_OnWarp::
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_FirstWarpIn
	.2byte 0

PalletTown_PlayersHouse_2F_FirstWarpIn::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	setvar VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 1
	end

PalletTown_PlayersHouse_2F_EventScript_NES::
	msgbox PalletTown_PlayersHouse_2F_Text_PlayedWithNES, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_2F_EventScript_Sign::
	msgbox PalletTown_PlayersHouse_2F_Text_PressLRForHelp, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_2F_EventScript_PC::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	setvar VAR_0x8004, HELPCONTEXT_BEDROOM_PC
	special Script_SetHelpContext
	setvar VAR_0x8004, 1
	special AnimatePcTurnOn
	playse SE_PC_ON
	msgbox Text_PlayerBootedUpPC
	special BedroomPC
	waitstate
	special SetHelpContextForMap
	releaseall
	end

EventScript_PalletTown_PlayersHouse_2F_ShutDownPC::
	setvar VAR_0x8004, 1
	playse SE_PC_OFF
	special AnimatePcTurnOff
	special SetHelpContextForMap
	releaseall
	end

PalletTown_PlayersHouse_2F_Movement_MomLookDown::
	walk_in_place_down
	step_end

PalletTown_PlayersHouse_2F_Text_Mom::
	.string "Hey honey, PROFESSOR OAK\n"
	.string "just dropped by.\p"
	.string "He said he had something just\n"
	.string "for you.\p"
	.string "Pay him a visit when you can.\p"
	.string "My, you've really become a famous\n"
	.string "POKéMON TRAINER…\p"
	.string "Well, I'll be waiting for you\n"
	.string "downstairs!$"
	
	
PalletTown_PlayersHouse_2F_Movement_MomGo::
	walk_in_place_left
	step_end

PalletTown_PlayersHouse_2F_Movement_MomGoUp::
	walk_in_place_right
	step_end