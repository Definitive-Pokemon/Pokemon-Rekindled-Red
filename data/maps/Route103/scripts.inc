Route103_MapScripts::
	.byte 0

Route103_EventScript_Groudon::
	lockall
	waitse
	playmoncry SPECIES_GROUDON, 2
	waitmoncry
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_GoLeft
	waitmovement 0
	msgbox Route103_Text
	waitmessage
	releaseall
	end

Route103_EventScript_Kyogre::
	lockall
	waitse
	playmoncry SPECIES_KYOGRE, 2
	waitmoncry
	delay 20
	msgbox Route103_Text
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_GoRight
	waitmovement 0
	releaseall
	end
	
Route103_Movement_GoLeft::
	walk_fast_left
	step_end

Route103_Movement_GoRight::
	walk_fast_right
	step_end
	
Route103_Text::
	.string "A ferocious cry can be heard\n"
	.string "in the distance!\p"
	.string "It's best to stay away from\n"
	.string "this direction.$"