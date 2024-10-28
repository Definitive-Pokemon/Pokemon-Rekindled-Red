MtSilverGate_MapScripts::
	.byte 0

MtSilverGate_EventScript_NoPass::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, MtSilverGate_Movement_Face
	waitmovement 0
	textcolor 0
	msgbox MtSilverGate_Text_NoPass
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MtSilverGate_Movement_WalkRight
	waitmovement 0
	releaseall
	end

MtSilverGate_EventScript_Pass::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, MtSilverGate_Movement_Face
	waitmovement 0
	textcolor 0
	msgbox MtSilverGate_Text_Pass
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MtSilverGate_Movement_WalkLeft
	waitmovement 0
	setvar VAR_MT_SILVER_ACCESS, 2
	releaseall
	end

MtSilverGate_EventScript_Mt_Silver::
	lock
	faceplayer
	msgbox MtSilverGate_Text_Mt_Silver
	closemessage
	release
	end

MtSilverGate_EventScript_Route_26::
	lock
	faceplayer
	msgbox MtSilverGate_Text_Route_26
	closemessage
	release
	end

MtSilverGate_EventScript_Route_22::
	lock
	faceplayer
	msgbox MtSilverGate_Text_Route_22
	closemessage
	release
	end

MtSilverGate_EventScript_Route_26::
	lock
	faceplayer
	msgbox MtSilverGate_Text_Route_26
	closemessage
	release
	end

MtSilverGate_Movement_Face::
	walk_in_place_up
	step_end

MtSilverGate_Movement_WalkRight::
	walk_right
	step_end
	
MtSilverGate_Movement_WalkLeft::
	walk_left
	step_end

MtSilverGate_Text_NoPass::
	.string "I'm sorry mister,\n"
	.string "you cannot go past here.\p"
	.string "Come back when you have grown\n"
	.string "significantly as a TRAINER.\p"
	.string "Bwahaha!$"

MtSilverGate_Text_Pass::
	.string "You sure have become a\n"
	.string "powerful TRAINER.\p"
	.string "Go right ahead, buddy!$"

MtSilverGate_Text_Mt_Silver::
	.string "Mt. Silver lies in this direction.\p"
	.string "The strongest TRAINERS come here\n"
	.string "to battle and train their POKéMON.$"

MtSilverGate_Text_Route_26::
	.string "ROUTE 26 lies in this direction.\p"
	.string "You're heading for JOHTO, right?$"

MtSilverGate_Text_Route_22::
	.string "ROUTE 22 lies in this direction.$"