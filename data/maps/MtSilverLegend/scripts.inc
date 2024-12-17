.set LOCALID_MAXIMUS, 1

MtSilverLegend_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilverLegend_OnTransition
	.byte 0

MtSilverLegend_OnTransition::
	goto_if_unset FLAG_MAXIMUS_SEAFOAM, MtSilverLegend_EventScript_NoMaximus
	goto_if_unset FLAG_SEEN_ZAPDOS, MtSilverLegend_EventScript_NoMaximus
	goto_if_set FLAG_MAXIMUS_SILVER_DONE, MtSilverLegend_EventScript_NoMaximus
	setvar VAR_MAXIMUS_SILVER, 0
	clearflag FLAG_HIDE_MAXIMUS_SILVER
	addobject LOCALID_MAXIMUS
	end

MtSilverLegend_EventScript_NoMaximus::
	setflag FLAG_HIDE_MAXIMUS_SILVER
	removeobject LOCALID_MAXIMUS
	setvar VAR_MAXIMUS_SILVER, 1
	end

MtSilverLegend_EventScript_Maximus::
	lockall
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
	setvar VAR_MAXIMUS_SILVER, 1
	releaseall
	end

MtSilverLegend_Movement_Maximus::
	walk_in_place_down
	step_end

MtSilverLegend_Text_Maximus::
	.string "There you are.\n"
	.string "I have been waiting for you.\p"
	.string "I heard you were heading for this place,\n"
	.string "so I thought this would be the perfect\l"
	.string "opportunity to do what I came here for.\p"
	.string "Now, come.$"

MtSilverLegend_Movement_Maximus2::
	walk_up
	walk_up
	walk_up
	step_end