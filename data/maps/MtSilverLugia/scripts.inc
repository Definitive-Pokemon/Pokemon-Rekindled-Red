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
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, MtSilverLugia_Movement_PlayerFirst
	waitmovement 0
	textcolor 0
	delay 60
	applymovement LOCALID_MAXIMUS, MtSilverLugia_Movement_LookatPlayer
	waitmovement 0
	msgbox MtSilverLugia_Text_Maximus_Intro, MSGBOX_NPC
	closemessage
	delay 20
	applymovement LOCALID_MAXIMUS, MtSilverLugia_Movement_LookUp
	waitmovement 0
	delay 10
	msgbox MtSilverLugia_Text_Maximus_Announce, MSGBOX_NPC
	closemessage
	delay 80
	playse SE_M_DETECT
	fadescreen FADE_TO_WHITE
	waitse
	fadescreen FADE_FROM_WHITE
	textcolor 2
	msgbox MtSilverLugia_Text_Maximus_Show, MSGBOX_NPC
	closemessage
	fadenewbgm MUS_NONE
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MtSilverLugia_Movement_PanToActionFromBottom
	waitmovement 0
	special RemoveCameraObject
	delay 60
	playbgm MUS_AWAKEN_LEGEND, 0
	addobject LOCALID_LUGIA
	clearflag FLAG_MAXIMUS_HIDE_LUGIA
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
	setweather 3
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
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MtSilverLugia_Movement_PanToActionFromTop
	waitmovement 0
	special RemoveCameraObject
	delay 60
	applymovement LOCALID_MAXIMUS, MtSilverLugia_Movement_LookUp
	waitmovement 0
	textcolor 0
	msgbox MtSilverLugia_Text_Maximus_Behold, MSGBOX_NPC
	closemessage
	delay 10
	textcolor 2
	msgbox MtSilverLugia_Text_Maximus_Remote, MSGBOX_NPC
	closemessage
	playse SE_PIN
	waitse
	delay 10
	playse SE_THUNDERSTORM
	fadescreen FADE_TO_WHITE
	waitse
	fadescreen FADE_FROM_WHITE
	delay 10
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 10
	setvar VAR_0x8007, 3
	special ShakeScreen
	playse SE_M_THUNDER_WAVE
	waitse
	playmoncry SPECIES_LUGIA, 12
	waitmoncry
	playmoncry SPECIES_LUGIA, 3
	waitmoncry
	waitse
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 10
	setvar VAR_0x8007, 3
	special ShakeScreen
	playse SE_M_THUNDERBOLT2
	waitse
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 10
	setvar VAR_0x8007, 3
	special ShakeScreen
	playse SE_M_THUNDERBOLT2
	waitse
	delay 20
	playmoncry SPECIES_LUGIA, 11
	waitmoncry
	delay 40
	textcolor 0
	msgbox MtSilverLugia_Text_Maximus_Hah, MSGBOX_NPC
	closemessage
	delay 60
	playmoncry SPECIES_LUGIA, 2
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 10
	setvar VAR_0x8007, 3
	special ShakeScreen
	playmoncry SPECIES_LUGIA, 2
	waitmoncry
	delay 60
	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MtSilverLugia_Movement_CameraBackUp
	setvar VAR_0x8004, 2  @ Num loops
	setvar VAR_0x8005, 35 @ Delay
	special LoopWingFlapSound
	applymovement LOCALID_LUGIA, Movement_LugiaFree
	waitmovement 0
	delay 50
	playse SE_M_SOLAR_BEAM
	waitse
	textcolor 0
	msgbox MtSilverLugia_Text_MaximusWhat
	closemessage
	delay 20
	playse SE_BALL_THROW
	applymovement LOCALID_MAXIMUS, MtSilverLugia_Movement_ThrowTracker
	waitse
	waitmovement 0
	delay 5
	playse SE_BALL_BOUNCE_1
	waitse
	delay 20
	setvar VAR_0x8004, 3  @ Num loops
	setvar VAR_0x8005, 35 @ Delay
	special LoopWingFlapSound
	applymovement OBJ_EVENT_ID_CAMERA, MtSilverLugia_Movement_CameraBackUp
	applymovement LOCALID_LUGIA, Movement_LugiaBackUp
	waitmovement 0
	delay 10
	special RemoveCameraObject
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_LUGIA
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_MAXIMUS_LUGIA
	setflag FLAG_MAXIMUS_HIDE_LUGIA
	setweather 2
	doweather
	delay 60
	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MtSilverLugia_Movement_CameraBackDown
	waitmovement 0
	special RemoveCameraObject
	delay 60
	msgbox MtSilverLugia_Text_MaximusSigh
	closemessage
	delay 20
	applymovement LOCALID_MAXIMUS, MtSilverLugia_Movement_LookatPlayer
	waitmovement 0
	msgbox MtSilverLugia_Text_MaximusOhWell
	closemessage
	delay 20
	playse SE_PC_ON
	applymovement LOCALID_MAXIMUS, MtSilverLugia_Movement_Exclaim
	waitse
	waitmovement 0
	applymovement LOCALID_MAXIMUS, MtSilverLugia_Movement_LookatPlayer
	waitmovement 0
	delay 10
	applymovement LOCALID_MAXIMUS, MtSilverLugia_Movement_LookatPlayer
	waitmovement 0
	applymovement LOCALID_MAXIMUS, MtSilverLugia_Movement_LookatPlayer
	waitmovement 0
	msgbox MtSilverLugia_Text_MaximusAha
	closemessage
	delay 20
	playbgm MUS_B_PIKE, 0
	applymovement LOCALID_MAXIMUS, MtSilverLugia_Movement_LookatPlayer
	waitmovement 0
	msgbox MtSilverLugia_Text_MaximusBye
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_WARP_IN
	waitse
	removeobject LOCALID_MAXIMUS
	setflag FLAG_MAXIMUS_SILVER_HIDE
	clearflag FLAG_HIDE_SILVER_SCIENTIST
	fadescreen FADE_FROM_BLACK
	fadenewbgm MUS_NONE
	delay 100
	warp MAP_MT_SILVER, 11, 5
	waitstate
	releaseall
	end

MtSilverLugia_Movement_PlayerFirst::
	walk_up
	step_end

MtSilverLugia_Movement_PanToActionFromBottom::
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

MtSilverLugia_Movement_LookatPlayer::
	walk_in_place_down
	step_end

MtSilverLugia_Text_Maximus_Intro::
	.string "You recognize this machinery,\n"
	.string "don't you, TRAINER?\p"
	.string "It's built from all kinds of stuff\n"
	.string "I stole from the POWER PLANT when\l"
	.string "I went to collect ZAPDOS' feather.\p"
	.string "You see, TRAINER, I need all this\n"
	.string "in order to collect the legendary\l"
	.string "POKéMON of flight, LUGIA.\p"
	.string "MOLTRES' BURNING FEATHER,\n"
	.string "ZAPDOS' YELLOW FEATHER,\l"
	.string "and ARTICUNO's CYAN FEATHER.\p"
	.string "When combined, they form one of\n"
	.string "LUGIA's famous SILVER WINGS.\p"
	.string "And guess what?\n"
	.string "LUGIA will only answer the call of\l"
	.string "someone holding a SILVER WING.\p"
	.string "Now, as for the machinery…\p"
	.string "…I think a demonstration speaks\n"
	.string "louder than any explanation could!$"

MtSilverLugia_Text_Maximus_Announce::
	.string "Come, LUGIA!\n"
	.string "Legendary POKéMON of storms!$"

MtSilverLugia_Movement_LookUp::
	walk_in_place_up
	step_end

MtSilverLugia_Text_Maximus_Show::
	.string "MAXIMUS took the SILVER WING\n"
	.string "and lifted it towards the skies!$"

MtSilverLugia_Movement_PanToActionFromTop::
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

MtSilverLugia_Text_Maximus_Behold::
	.string "Look at that!\p"
	.string "It's LUGIA!\p"
	.string "Now, it's time for the machine\n"
	.string "to do its job!$"

MtSilverLugia_Text_Maximus_Remote::
	.string "MAXIMUS took out a strange\n"
	.string "looking remote and pressed\l"
	.string "one of its buttons.$"

MtSilverLugia_Text_Maximus_Hah::
	.string "Hah! LUGIA has been severely\n"
	.string "weakened thanks to my machine.\p"
	.string "LUGIA isn't a fan of lightning.\n"
	.string "Hahahahaha!$"

MtSilverLugia_Movement_CameraBackUp::
	delay_16
	delay_16
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

Movement_LugiaFree::
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end

MtSilverLugia_Text_MaximusWhat::
	.string "WHAT?!\n"
	.string "That thing should be completely\l"
	.string "paralyzed at this point!\p"
	.string "How can it even move?!\p"
	.string "I am NOT letting it get away,\n"
	.string "not after all this work!$"

MtSilverLugia_Movement_ThrowTracker::
	walk_in_place_up
	step_end

Movement_LugiaBackUp::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_up
	delay_16
	delay_16
	step_end

MtSilverLugia_Text_MaximusSigh::
	.string "The QUICK BALL just bounced off\n"
	.string "like it was nothing…$"

MtSilverLugia_Movement_CameraBackDown::
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

MtSilverLugia_Text_MaximusOhWell::
	.string "Oh well…\p"
	.string "I can easily find LUGIA now that\n"
	.string "I have placed my tracking device!\p"
	.string "That's right, TRAINER!\p"
	.string "All my POKé BALLS contain mechanisms\n"
	.string "that release microscopic trackers\l"
	.string "when being thrown at a POKéMON.\p"
	.string "They then instantly latch onto\n"
	.string "the POKéMON's surface.\p"
	.string "Skin, fur, or whatever the thing\n"
	.string "has on it.$"

MtSilverLugia_Movement_Exclaim::
	emote_exclamation_mark
	delay_16
	step_end

MtSilverLugia_Text_MaximusAha::
	.string "Aha!\p"
	.string "So that's where your little\n"
	.string "hiding place is…$"

MtSilverLugia_Text_MaximusBye::
	.string "Well, I know exactly where\n"
	.string "to find my target.\p"
	.string "Of course, I won't be telling you\n"
	.string "anything about its location.\p"
	.string "Sorry, but you would just be\n"
	.string "in the way, TRAINER.\p"
	.string "No, I won't be battling you,\n"
	.string "hahahahaha!$"