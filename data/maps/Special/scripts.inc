Special_MapScripts::
	.byte 0

Special_EventScript_Cage::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Special_Movement_Cage
	waitmovement 0
	delay 200
	textcolor 2
	msgbox SpecialArea_Text_NoEscape
	closemessage
	delay 300
	msgbox SpecialArea_Text_Asleep
	closemessage
	warp MAP_FAKE_PALLET1, 255, 2, 5
	releaseall
	end
	
Special_Movement_Cage::
	walk_in_place_down
	step_end