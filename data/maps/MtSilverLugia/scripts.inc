.set LOCALID_MAXIMUS, 1
.set LOCALID_LUGIA, 2

MtSilverLugia_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MtSilverLugia_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtSilverLugia_OnFrame
	.byte 0

MtSilverLugia_OnLoad::
	goto_if_set FLAG_MAXIMUS_LUGIA, MtSilverLugia_OnLoad_SetVarForScene
	end
MtSilverLugia_OnLoad_SetVarForScene::
	setvar VAR_TEMP_0, 1
	end

MtSilverLugia_OnFrame::
	map_script_2 VAR_TEMP_0, 1, MtSilverLugia_EventScript_Event
	.2byte 0

MtSilverLugia_EventScript_Event::
	lockall
	setvar VAR_TEMP_0, 0
	textcolor 0
	fadenewbgm MUS_NONE
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MtSilverLugia_Movement_PanToActionFromBottom
	waitmovement 0
	special RemoveCameraObject
	delay 60
	applymovement LOCALID_MAXIMUS, MtSilverLugia_Movement_LookatPlayer
	waitmovement 0
	msgbox MtSilverLugia_Text_Maximus_Announce, MSGBOX_NPC
	closemessage
	applymovement LOCALID_MAXIMUS, MtSilverLugia_Movement_LookUp
	waitmovement 0
	delay 80
	playse SE_M_DETECT
	fadescreen FADE_TO_WHITE
	waitse
	fadescreen FADE_FROM_WHITE
	textcolor 2
	msgbox MtSilverLugia_Text_Maximus_Show, MSGBOX_NPC
	closemessage
	fadescreen FADE_TO_WHITE
	playbgm MUS_AWAKEN_LEGEND, 0
	addobject LOCALID_LUGIA
	clearflag FLAG_MAXIMUS_HIDE_LUGIA
	fadescreen FADE_FROM_WHITE
	delay 50
	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	setvar VAR_0x8004, 3  @ Num loops
	setvar VAR_0x8005, 35 @ Delay
	special LoopWingFlapSound
	applymovement LOCALID_LUGIA, Movement_HoOhAppear
	applymovement OBJ_EVENT_ID_CAMERA, Movement_CameraPanUp
	waitmovement 0
	delay 50
	setweather 5
	doweather
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	delay 60
	setvar VAR_0x8004, 3  @ Num loops
	setvar VAR_0x8005, 35 @ Delay
	special LoopWingFlapSound
	applymovement OBJ_EVENT_ID_CAMERA, Movement_CameraPanDown
	applymovement LOCALID_LUGIA, Movement_HoOhApproach
	waitmovement 0
	special RemoveCameraObject
	delay 50
	msgbox MtSilverLugia_Text_Maximus_Behold, MSGBOX_NPC
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_LUGIA
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_MAXIMUS_LUGIA
	setflag FLAG_MAXIMUS_HIDE_LUGIA
	releaseall
	end

MtSilverLugia_Movement_PanToActionFromBottom::
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

MtSilverLugia_Movement_LookatPlayer::
	walk_in_place_down
	step_end

MtSilverLugia_Text_Maximus_Announce::
	.string "It is time!\n"
	.string "It is time to summon LUGIA,\n"
	.string "legendary POKéMON of flight,\p"
	.string "using the SILVER WING I created\n"
	.string "by combining the feathers I took\l"
	.string "from the legendary birds!$"

MtSilverLugia_Movement_LookUp::
	walk_in_place_up
	step_end

MtSilverLugia_Text_Maximus_Show::
	.string "MAXIMUS took out the\n"
	.string "SILVER WING and held\l"
	.string "it to the skies!$"

MtSilverLugia_Text_Maximus_Behold::
	.string "Look at that!\n"
	.string "It's LUGIA!\l"
	.string "Finally it's mine!$"