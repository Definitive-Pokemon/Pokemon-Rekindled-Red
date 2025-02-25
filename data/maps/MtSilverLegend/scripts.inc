.set LOCALID_MAXIMUS, 1

MtSilverLegend_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilverLegend_OnTransition
	.byte 0

MtSilverLegend_OnTransition::
	goto_if_unset FLAG_MAXIMUS_SEAFOAM, MtSilverLegend_EventScript_NoMaximus
	goto_if_unset FLAG_SEEN_ZAPDOS, MtSilverLegend_EventScript_NoMaximus
	goto_if_set FLAG_MAXIMUS_SILVER_DONE, MtSilverLegend_EventScript_MaximusReady
	setvar VAR_MAXIMUS_SILVER, 0
	clearflag FLAG_HIDE_MAXIMUS_SILVER
	addobject LOCALID_MAXIMUS
	end
	
	
MtSilverLegend_EventScript_DoorLocked::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	msgbox MtSilverLegend_Text_DoorIsLocked
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CinnabarIsland_Movement_ForcePlayerFromDoor
	waitmovement 0
	releaseall
	end

MtSilverLegend_EventScript_NoMaximus::
	setflag FLAG_HIDE_MAXIMUS_SILVER
	removeobject LOCALID_MAXIMUS
	setvar VAR_MAXIMUS_SILVER, 1
	end

MtSilverLegend_EventScript_MaximusReady::
	setvar VAR_MAXIMUS_SILVER, 2
	end

MtSilverLegend_EventScript_Maximus::
	lockall
	delay 30
	applymovement LOCALID_MAXIMUS, MtSilverLegend_Movement_Maximus
	waitmovement 0
	textcolor 0
	msgbox MtSilverLegend_Text_Maximus
	closemessage
	applymovement LOCALID_MAXIMUS, MtSilverLegend_Movement_Maximus2
	waitmovement 0
	removeobject LOCALID_MAXIMUS
	playse SE_EXIT
	waitse
	setflag FLAG_HIDE_MAXIMUS_SILVER
	setflag FLAG_MAXIMUS_SILVER_DONE
	setvar VAR_MAXIMUS_SILVER, 2
	setflag FLAG_MAXIMUS_LUGIA
	setflag FLAG_MAXIMUS_HIDE_LUGIA
	setflag FLAG_HIDE_FING_BALL
	releaseall
	end

MtSilverLegend_Movement_Maximus::
	walk_in_place_down
	step_end

MtSilverLegend_Text_Maximus::
	.string "There you are, TRAINER.\n"
	.string "I have been waiting just for you.\p"
	.string "It took me a while to set up\n"
	.string "this part of the operation,\p"
	.string "so I had plenty work to do before\n"
	.string "you would show up.\p"
	.string "What I have been up to?\n"
	.string "You will see very soon.$"

MtSilverLegend_Movement_Maximus2::
	walk_up
	walk_up
	walk_up
	step_end