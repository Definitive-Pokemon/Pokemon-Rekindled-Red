EventScript_Questionnaire::
	lock
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_FillOutQuestionnaire, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_DeclineQuestionnaire
	setvar VAR_0x8004, EASY_CHAT_TYPE_ALTERING_CAVE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	specialvar VAR_0x8008, GetMartClerkObjectId
	textcolor NPC_TEXT_COLOR_MALE
	goto_if_eq VAR_0x8004, 0, EventScript_AlterCave
	goto_if_eq VAR_RESULT, 0, EventScript_DeclineQuestionnaire
	goto_if_eq VAR_RESULT, 1, EventScript_TookQuestionnaire
	end

EventScript_AlterCave::
	lock
	delay 20
	fadeoutbgm 1
	fadescreen FADE_TO_WHITE
	playse SE_ICE_BREAK
	waitse
	removeobject VAR_LAST_TALKED
	fadescreen FADE_FROM_WHITE
	delay 80
	playse SE_ORB
	animateflash 8
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
	setflag FLAG_HIDE_MURAL
	fadeinbgm 1
	release
	end

EventScript_DeclineQuestionnaire::
	release
	end

EventScript_TookQuestionnaire::
	release
	end
