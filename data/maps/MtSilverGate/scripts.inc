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

MtSilverGate_EventScript_NewBarkNoPass::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, MtSilverGate_Movement_FaceNewBark
	waitmovement 0
	textcolor 0
	msgbox MtSilverGate_Text_NewBarkNoPass
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MtSilverGate_Movement_WalkUp
	waitmovement 0
	releaseall
	end

MtSilverGate_EventScript_NewBarkPass::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, MtSilverGate_Movement_FaceNewBark
	waitmovement 0
	textcolor 0
	msgbox MtSilverGate_Text_NewBarkPass
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MtSilverGate_Movement_WalkDown
	waitmovement 0
	setvar VAR_NEW_BARK_ACCESS, 2
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

MtSilverGate_Movement_Face::
	walk_in_place_up
	step_end

MtSilverGate_Movement_FaceNewBark::
	walk_in_place_left
	step_end

MtSilverGate_Movement_WalkRight::
	walk_right
	step_end
	
MtSilverGate_Movement_WalkLeft::
	walk_left
	step_end

MtSilverGate_Movement_WalkUp::
	walk_up
	step_end
	
MtSilverGate_Movement_WalkDown::
	walk_down
	step_end

MtSilverGate_Text_NoPass::
	.string "I'm sorry mister,\n"
	.string "you cannot go past here.\p"
	.string "Come back when you have grown\n"
	.string "significantly as a TRAINER.\p"
	.string "Bwahaha!$"

MtSilverGate_Text_Pass::
	.string "I got word from the VIRIDIAN\n"
	.string "GYM LEADER.\p"
	.string "You can go through now.\n"
	.string "Go right ahead, buddy!$"

MtSilverGate_Text_NewBarkNoPass::
	.string "Sorry buddy, past these routes\n"
	.string "lies the JOHTO region.\p"
	.string "There's nothing for you there.$"

MtSilverGate_Text_NewBarkPass::
	.string "I got word from the PROFESSOR.\p"
	.string "You are allowed access to\n"
	.string "ROUTE 26 and beyond.$"

MtSilverGate_Text_Mt_Silver::
	.string "MT. SILVER lies in this direction.\p"
	.string "The strongest TRAINERS come here\n"
	.string "to battle and train their POKéMON.$"

MtSilverGate_Text_Route_26::
	.string "ROUTE 26 lies in this direction.\p"
	.string "You're heading for JOHTO, right?$"

MtSilverGate_Text_Route_22::
	.string "ROUTE 22 lies in this direction.$"