.equ LOCALID_MURAL, 1

SixIsland_AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_AlteringCave_OnTransition
	.byte 0

SixIsland_AlteringCave_OnTransition::
	goto_if_unset FLAG_WORLD_MAP_SIX_ISLAND_ALTERING_CAVE, Mystery_Man_Trigger
	end
	
	Mystery_Man_Trigger::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND_ALTERING_CAVE
	clearflag FLAG_MYSTERY_MAN_GONE
	end

SixIsland_AlteringCave_EventScript_Mural::
	lock
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_FillOutQuestionnaire, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_DeclineMural
	setvar VAR_0x8004, EASY_CHAT_TYPE_ALTERING_CAVE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	specialvar VAR_0x8008, GetMartClerkObjectId
	textcolor NPC_TEXT_COLOR_MALE
	goto_if_eq VAR_0x8004, 0, EventScript_AlterCave
	goto_if_eq VAR_RESULT, 0, EventScript_DeclineMural
	goto_if_eq VAR_RESULT, 1, EventScript_TookMural
	end

SixIsland_AlteringCave_EventScript_AlterCave::
	lock
	delay 20
	playse SE_ICE_BREAK
	fadescreen FADE_TO_WHITE
	waitse
	removeobject LOCALID_MURAL
	fadescreen FADE_FROM_WHITE
	delay 80
	playse SE_ORB
	fadescreen FADE_TO_WHITE
	waitse
	fadescreen FADE_FROM_WHITE
	delay 20
	playse SE_DOOR
	waitse
	setmetatile 4, 12, METATILE_RockTunnel_TopLeft, 0
	setmetatile 5, 12, METATILE_RockTunnel_Top, 0
	setmetatile 6, 12, METATILE_RockTunnel_TopRight, 0
	setmetatile 6, 13, METATILE_RockTunnel_Right, 0
	setmetatile 6, 14, METATILE_RockTunnel_BottomRight, 0
	setmetatile 5, 14, METATILE_RockTunnel_Bottom, 0
	setmetatile 4, 14, METATILE_RockTunnel_BottomLeft, 0
	setmetatile 4, 13, METATILE_RockTunnel_Left, 0
	setmetatile 5, 13, METATILE_RockTunnel_Hole, 0
	setmetatile 6, 4, METATILE_RockTunnel_Spot, 0
	special DrawWholeMapView
	release
	end

SixIsland_AlteringCave_EventScript_DeclineMural::
	release
	end

SixIsland_AlteringCave_EventScript_TookMural::
	release
	end
