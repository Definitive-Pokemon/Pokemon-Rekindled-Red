.equ LOCALID_GREEN, 1
.equ LOCALID_RED, 2
MtSilverPeak_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilverPeak_OnTransition
	.byte 0

MtSilverPeak_OnTransition::
	setflag FLAG_HIDE_REDGREEN
	removeobject LOCALID_GREEN
	removeobject LOCALID_RED
	end

MtSilverPeak_EventScript_RedorGreen::
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq MtSilverPeak_EventScript_Green
	compare VAR_RESULT, FEMALE
	goto_if_eq MtSilverPeak_EventScript_Red
	end

MtSilverPeak_EventScript_Green::
	addobject LOCALID_GREEN
	textcolor 1
	msgbox MtSilverPeak_Text_GreenAppears, MSGBOX_NPC
	closemessage
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_GREEN_NORMAL
	delay_16
	delay_16
	delay_16
	applymovement LOCALID_GREEN, MtSilverPeak_Movement_GreenUp
	waitmovement 0
	releaseall
	end

MtSilverPeak_Text_GreenAppears::
	.string "Hey!$"
	

MtSilverPeak_EventScript_Red::
	addobject LOCALID_RED
	textcolor 0
	msgbox MtSilverPeak_Text_RedAppears, MSGBOX_NPC
	closemessage
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RED_NORMAL
	delay_16
	delay_16
	delay_16
	applymovement LOCALID_RED, MtSilverPeak_Movement_RedUp
	waitmovement 0
	releaseall
	end

MtSilverPeak_Text_RedAppears::
	.string "...$"

MtSilverPeak_Movement_GreenUp::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MtSilverPeak_Movement_RedUp::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end