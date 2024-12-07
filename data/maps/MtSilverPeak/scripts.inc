.equ LOCALID_
MtSilverPeak_MapScripts::
	.byte 0	

MtSilverPeak_EventScript_RedorGreen::
	lockall
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm 3, 14, 8
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq MtSilverPeak_EventScript_Green
	compare VAR_RESULT, FEMALE
	goto_if_eq MtSilverPeak_EventScript_Red
	end

MtSilverPeak_EventScript_Green::
	textcolor 1
	msgbox MtSilverPeak_Text_GreenAppears, MSGBOX_NPC
	closemessage
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_GREEN_NORMAL
	delay_16
	delay_16
	delay_16
	applymovement 1, MtSilverPeak_Movement_Up
	waitmovement 0
	releaseall
	end
	

MtSilverPeak_EventScript_Red::
	textcolor 0
	msgbox MtSilverPeak_Text_RedAppears, MSGBOX_NPC
	closemessage
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RED_NORMAL
	delay_16
	delay_16
	delay_16
	applymovement MtSilverPeak_Movement_Up
	waitmovement 0
	releaseall
	end



MtSilverPeak_Movement_Up::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end