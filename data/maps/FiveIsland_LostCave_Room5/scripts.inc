.set LOCALID_SAMUEL, 1
.set LOCALID_AGATHA, 2

FiveIsland_LostCave_Room5_MapScripts::
	.byte 0

FiveIsland_LostCave_Entrance_EventScript_CelebiEvent3::
	lockall
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room5_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room5_Text_Oak1
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room5_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room5_Text_Agatha1
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room5_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room5_Text_Oak2
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room5_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room5_Text_Agatha2
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room5_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room5_Text_Oak3
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room5_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room5_Text_Agatha3
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room5_Movement_Oak2
	waitmovement 0
	removeobject LOCALID_SAMUEL
	playse SE_EXIT
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room5_Movement_Agatha2
	waitmovement 0
	removeobject LOCALID_AGATHA
	playse SE_EXIT
	setflag FLAG_HIDE_DUO3
	clearflag FLAG_HIDE_DUO4
	setvar VAR_CELEBI_EVENT3, 2
	setvar VAR_CELEBI_EVENT4, 1
	releaseall
	end
	
FiveIsland_LostCave_Room5_Text_Oak1::
	.string "…clear that this puzzle, related to\n"
	.string "time, was conceived by CELEBI itself.$"
	
FiveIsland_LostCave_Room5_Text_Agatha1::
	.string "CELEBI is able to manipulate time?\n"
	.string "That's incredible!\p"
	.string "No TRAINER will be able to stand\n"
	.string "against you!$"
	
FiveIsland_LostCave_Room5_Text_Oak2::
	.string "Yup!\p"
	.string "With this POKéMON, I'll surely remain\n"
	.string "the CHAMPION for quite some time.$"
	
FiveIsland_LostCave_Room5_Text_Agatha2::
	.string "And you already are so strong!$"
	
FiveIsland_LostCave_Room5_Text_Oak3::
	.string "Haha, my strength is nothing compared\n"
	.string "to the power of CELEBI.\p"
	.string "It is said to rival even the POKéMON\n"
	.string "of light, HO-OH, as well as the\p"
	.string "POKéMON of sound, LUGIA.$"
	
FiveIsland_LostCave_Room5_Text_Agatha3::
	.string "Amazing!\n"
	.string "Then what are we waiting for!$"
	
FiveIsland_LostCave_Room5_Movement_Oak1::
	walk_in_place_up
	step_end
	
FiveIsland_LostCave_Room5_Movement_Agatha1::
	walk_in_place_down
	step_end
	
FiveIsland_LostCave_Room5_Movement_Oak2::
	walk_in_place_right
	step_end
	
FiveIsland_LostCave_Room5_Movement_Agatha2::
	walk_down
	walk_in_place_right
	step_end