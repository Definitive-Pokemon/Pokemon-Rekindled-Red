.set LOCALID_SAMUEL, 1
.set LOCALID_AGATHA, 2

FiveIsland_LostCave_Room7_MapScripts::
	.byte 0

FiveIsland_LostCave_Entrance_EventScript_CelebiEvent4::
	lockall
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room7_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room7_Text_Agatha1
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room7_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room7_Text_Oak1
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room7_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room7_Text_Agatha2
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room7_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room7_Text_Oak2
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room7_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room7_Text_Agatha3
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room7_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room7_Text_Oak3
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room7_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room7_Text_Agatha4
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room7_Movement_Oak2
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room7_Movement_Agatha2
	waitmovement 0
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room7_Movement_Oak2
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room7_Movement_Agatha2
	waitmovement 0
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room7_Movement_Oak2
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room7_Movement_Agatha2
	waitmovement 0
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room7_Movement_Oak3
	waitmovement 0
	removeobject LOCALID_SAMUEL
	playse SE_EXIT
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room7_Movement_Agatha3
	waitmovement 0
	removeobject LOCALID_AGATHA
	playse SE_EXIT
	setflag FLAG_HIDE_DUO4
	clearflag FLAG_HIDE_DUO5
	setvar VAR_CELEBI_EVENT4, 2
	setvar VAR_CELEBI_EVENT5, 1
	releaseall
	end

FiveIsland_LostCave_Room7_Text_Agatha1::
	.string "I can't see a thing!\n"
	.string "This mist is crazy!$"
	
FiveIsland_LostCave_Room7_Text_Oak1::
	.string "Just follow the sound of my voice\p"
	.string "You're all safe and sound with me.$"
	
FiveIsland_LostCave_Room7_Text_Agatha2::
	.string "Safe and sound, with you?\p"
	.string "You can't even find your own\n"
	.string "RUNNING SHOES whenever you\p"
	.string "go out.\n"
	.string "Giggle…$"
	
FiveIsland_LostCave_Room7_Text_Oak2::
	.string "Should I just leave you\n"
	.string "behind, then?$"
	
FiveIsland_LostCave_Room7_Text_Agatha3::
	.string "Stop joking around and help me!$"
	
FiveIsland_LostCave_Room7_Text_Oak3::
	.string "Here, I'll hold your hand.$"
	
FiveIsland_LostCave_Room7_Text_Agatha4::
	.string "Giggle…$"
	
FiveIsland_LostCave_Room7_Movement_Agatha1::
	walk_in_place_left
	step_end
	
FiveIsland_LostCave_Room7_Movement_Oak1::
	walk_in_place_right
	step_end
	
FiveIsland_LostCave_Room7_Movement_Oak2::
	walk_down
	step_end
	
FiveIsland_LostCave_Room7_Movement_Agatha2::
	walk_down
	step_end
	
FiveIsland_LostCave_Room7_Movement_Oak3::
	walk_in_place_down
	step_end
	
FiveIsland_LostCave_Room7_Movement_Agatha3::
	walk_left
	walk_in_place_down
	step_end