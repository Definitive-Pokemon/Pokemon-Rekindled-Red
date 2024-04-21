.set LOCALID_SAMUEL, 1
.set LOCALID_AGATHA, 2

FiveIsland_LostCave_Room9_MapScripts::
	.byte 0

FiveIsland_LostCave_Entrance_EventScript_CelebiEvent5::
	lockall
	fadeoutbgm 1
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room9_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room9_Text_Agatha1
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room9_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room9_Text_Oak1
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room9_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room9_Text_Agatha2
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room9_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room9_Text_Oak2
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room9_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room9_Text_Agatha3
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room9_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room9_Text_Oak3
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room9_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room9_Text_Oak4
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room9_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room9_Text_Agatha4
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room9_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room9_Text_Oak5
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room9_Movement_Agatha1
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room9_Movement_Oak1
	waitmovement 0
	textcolor 2
	msgbox FiveIsland_LostCave_Room9_Text_Both
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room9_Movement_Agatha2
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room9_Movement_Oak2
	waitmovement 0
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room9_Movement_Agatha2
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room9_Movement_Oak2
	waitmovement 0
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room9_Movement_Agatha2
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room9_Movement_Oak2
	waitmovement 0
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room9_Movement_Oak1
	waitmovement 0
	removeobject LOCALID_SAMUEL
	playse SE_EXIT
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room9_Movement_Agatha3
	waitmovement 0
	removeobject LOCALID_AGATHA
	playse SE_EXIT
	setflag FLAG_HIDE_DUO5
	clearflag FLAG_HIDE_DUO6
	setvar VAR_CELEBI_EVENT5, 2
	setvar VAR_CELEBI_EVENT6, 1
	fadeinbgm 1
	releaseall
	end

FiveIsland_LostCave_Room9_Text_Agatha1::
	.string "Sam… I'm scared…$"
	
FiveIsland_LostCave_Room9_Text_Oak1::
	.string "I'll admit that I am starting to feel\n"
	.string "a little nervous as well…$"
	
FiveIsland_LostCave_Room9_Text_Agatha2::
	.string "This POKéMON… is really powerful,\n"
	.string "right?$"

FiveIsland_LostCave_Room9_Text_Oak1::
	.string "So I've heard…$"
	
FiveIsland_LostCave_Room9_Text_Agatha3::
	.string "Are we gonna make it?$"

FiveIsland_LostCave_Room9_Text_Oak3::
	.string "Of course we are, sweet.\p"
	.string "Remember, I'm the CHAMPION.$"
	
FiveIsland_LostCave_Room9_Text_Oak4::
	.string "Are you ready, AGATHA?$"
	
FiveIsland_LostCave_Room9_Text_Agatha4::
	.string "…\p"
	.string "Yes, I am.\p"
	.string "What about you, SAMUEL?$"
	
FiveIsland_LostCave_Room9_Text_Oak5::
	.string "As ready as ever, love.\n"
	.string "No going back now.$"
	
FiveIsland_LostCave_Room9_Text_Both::
	.string "Let's go!!$"
	
FiveIsland_LostCave_Room9_Movement_Agatha1::
	walk_in_place_up
	step_end
	
FiveIsland_LostCave_Room9_Movement_Oak1::
	walk_in_place_up
	step_end
	
FiveIsland_LostCave_Room9_Movement_Agatha2::
	walk_up
	step_end
	
FiveIsland_LostCave_Room9_Movement_Oak2::
	walk_up
	step_end
	
FiveIsland_LostCave_Room9_Movement_Agatha3::
	walk_right
	walk_in_place_up
	step_end