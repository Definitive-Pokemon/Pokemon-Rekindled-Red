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
	setvar VAR_RED_OR_GREEN, 1
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
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	applymovement LOCALID_GREEN, MtSilverPeak_Movement_Up
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, MtSilverPeak_Movement_LookDown
	waitmovement 0
	msgbox MtSilverPeak_Text_GreenIntroduce, MSGBOX_NPC
	closemessage
	applymovement LOCALID_GREEN, MtSilverPeak_Movement_Up2
	waitmovement 0
	msgbox MtSilverPeak_Text_GreenPower, MSGBOX_NPC
	closemessage
	applymovement LOCALID_GREEN, MtSilverPeak_Movement_Readying
	waitmovement 0
	trainerbattle_single TRAINER_GREEN, MtSilverPeak_Text_GreenLetsBattle, MtSilverPeak_Text_GreenDefeat, MtSilverPeak_EventScript_GreenDefeated, NO_MUSIC
	releaseall
	end

MtSilverPeak_Text_GreenAppears::
	.string "It seems someone already climbed\n"
	.string "their way up here…$"

MtSilverPeak_Text_GreenIntroduce::
	.string "Well met, cute stranger!\n"
	.string "My name is GREEN.$"

MtSilverPeak_Text_GreenPower::
	.string "Only real powerful TRAINERS get to\n"
	.string "climb this sacred mountain.\p"
	.string "You must be strong, then!\p"
	.string "But be warned, I am strong too.\n"
	.string "Maybe even stronger than you…$"

MtSilverPeak_Text_GreenLetsBattle::
	.string "I've traveled the world, meeting\n"
	.string "all sorts of people and POKéMON.\p"
	.string "My experience will be of good use\n"
	.string "for pummeling you into the ground\l"
	.string "with my trusted partners!$"

MtSilverPeak_Text_GreenDefeat::
	.string "HAHAHAHAHA!\n"
	.string "YES, you really pack a punch!$"

MtSilverPeak_EventScript_GreenDefeated::
	textcolor 1
	msgbox MtSilverPeak_Text_GreenReward, MSGBOX_NPC
	closemessage
	giveitem_msg MtSilverPeak_Text_ReceivedRainbowWingGreen, ITEM_RAINBOW_WING, 1
	closemessage
	msgbox MtSilverPeak_Text_GreenGoodbye, MSGBOX_NPC
	closemessage
	applymovement LOCALID_GREEN, MtSilverPeak_Movement_Leaving
	waitmovement 0
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	special EnterHallOfFame
	waitstate
	releaseall
	end

MtSilverPeak_Text_GreenReward::
	.string "Wow!\n"
	.string "That felt great!\p"
	.string "I got such a rush battling you.\n"
	.string "You are incredibly powerful!\p"
	.string "I believe you deserve to have this.\n"
	.string "It's a little something I stole…\l"
	.string "I mean BORROWED from TEAM ROCKET!$"

MtSilverPeak_Text_ReceivedRainbowWingGreen::
	.string "{PLAYER} received the RAINBOW WING\n"
	.string "from GREEN!$"

MtSilverPeak_Text_GreenGoodbye::
	.string "People from the JOHTO region claim\n"
	.string "that this item is linked to the\l"
	.string "legendary POKéMON called HO-OH.\p"
	.string "Who knows…\n"
	.string "Maybe there is some place connected\l"
	.string "to this skyborne creature.\p"
	.string "Be sure to take this RAINBOW WING\n"
	.string "with you when you visit such\l"
	.string "a location!\p"
	.string "Anyway, it was fun meeting you.\n"
	.string "I've got places to be, however!\p"
	.string "I hope we meet again!$"
	

MtSilverPeak_EventScript_Red::
	addobject LOCALID_RED
	textcolor 0
	msgbox MtSilverPeak_Text_RedAppears, MSGBOX_NPC
	closemessage
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	applymovement LOCALID_RED, MtSilverPeak_Movement_Up
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, MtSilverPeak_Movement_LookDown
	waitmovement 0
	msgbox MtSilverPeak_Text_RedIntroduce, MSGBOX_NPC
	closemessage
	applymovement LOCALID_RED, MtSilverPeak_Movement_Up2
	waitmovement 0
	msgbox MtSilverPeak_Text_RedPower, MSGBOX_NPC
	closemessage
	applymovement LOCALID_RED, MtSilverPeak_Movement_Readying
	waitmovement 0
	trainerbattle_single TRAINER_RED, MtSilverPeak_Text_RedLetsBattle, MtSilverPeak_Text_RedDefeat, MtSilverPeak_EventScript_RedDefeated, NO_MUSIC
	releaseall
	end

MtSilverPeak_Text_RedAppears::
	.string "…$"

MtSilverPeak_Text_RedIntroduce::
	.string "… … …$"

MtSilverPeak_Text_RedPower::
	.string "…… …… ……$"

MtSilverPeak_Text_RedLetsBattle::
	.string "……… ……… ………!$"

MtSilverPeak_Text_RedDefeat::
	.string "………………………!\n"
	.string "…$"

MtSilverPeak_EventScript_RedDefeated::
	textcolor 0
	msgbox MtSilverPeak_Text_RedReward, MSGBOX_NPC
	closemessage
	giveitem_msg MtSilverPeak_Text_ReceivedRainbowWingRed, ITEM_RAINBOW_WING, 1
	closemessage
	msgbox MtSilverPeak_Text_RedGoodbye, MSGBOX_NPC
	closemessage
	applymovement LOCALID_Red, MtSilverPeak_Movement_Leaving
	waitmovement 0
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	special EnterHallOfFame
	waitstate
	releaseall
	end

MtSilverPeak_Text_RedReward::
	.string "… … …\n"
	.string "…!$"

MtSilverPeak_Text_ReceivedRainbowWingRed::
	.string "{PLAYER} received the RAINBOW WING\n"
	.string "from RED!$"

MtSilverPeak_Text_RedGoodbye::
	.string "………$"

MtSilverPeak_Movement_Up::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MtSilverPeak_Movement_Up2::
	walk_up
	walk_up
	walk_up
	step_end

MtSilverPeak_Movement_LookDown::
	walk_in_place_down
	step_end

MtSilverPeak_Movement_Readying::
	walk_in_place_up
	step_end

MtSilverPeak_Movement_Leaving::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	