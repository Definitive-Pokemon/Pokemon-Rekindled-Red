.set LOCALID_MOM, 1
.set LOCALID_KABUTOPS_SHADOW, 2

FakePallet2_MapScripts::
	.byte 0

FakePallet2_EventScript_Mom1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, FakePallet2_Movement_FaceMom1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MOM FakePallet2_Movement_Ex
	waitmovement 0
	textcolor 1
	applymovement LOCALID_MOM FakePallet2_Movement_Face1
	waitmovement 0
	msgbox FakePallet2_Text_Mom
	closemessage
	applymovement LOCALID_MOM FakePallet2_Movement_Sad1
	waitmovement 0
	msgbox FakePallet2_Text_Mom2
	closemessage
	applymovement LOCALID_MOM FakePallet2_Movement_Contemplate1
	waitmovement 0
	delay 50
	msgbox FakePallet2_Text_Mom3
	closemessage
	playbgm MUS_DUMMY 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MOM
	addobject LOCALID_KABUTOPS_SHADOW
	clearflag FLAG_HIDE_MOMBUTOPS
	setflag FLAG_HIDE_MOM
	playmoncry SPECIES_KABUTOPS, CRY_MODE_ECHO_START
	waitmoncry
	applymovement LOCALID_KABUTOPS_SHADOW FakePallet2_Movement_Kabutops
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	playse SE_BERRY_BLENDER
	call FakePallet2_EventScript_BrailleMessage
	delay 100
	applymovement OBJ_EVENT_ID_PLAYER, FakePallet2_Movement_Slap1
	waitmovement 0
	applymovement LOCALID_KABUTOPS_SHADOW, FakePallet2_Movement_KabutopsBack1
	playse SE_BANG
	waitmovement 0
	playmoncry SPECIES_KABUTOPS, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30
	fadescreen FADE_TO_WHITE
	setflag FLAG_HIDE_CAGE
	removeobject LOCALID_KABUTOPS_SHADOW
	fadescreen FADE_FROM_WHITE
	delay 200
	formatwarp MAP_MONITORING_STATION_STORAGE, 255, 19, 11
	waitstate
	releaseall
	end
	
FakePallet2_EventScript_Mom2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, FakePallet2_Movement_FaceMom2
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MOM FakePallet2_Movement_Ex
	waitmovement 0
	textcolor 1
	applymovement LOCALID_MOM FakePallet2_Movement_Face2
	waitmovement 0
	msgbox FakePallet2_Text_Mom
	closemessage
	applymovement LOCALID_MOM FakePallet2_Movement_Sad2
	waitmovement 0
	msgbox FakePallet2_Text_Mom2
	closemessage
	applymovement LOCALID_MOM FakePallet2_Movement_Contemplate2
	waitmovement 0
	delay 50
	msgbox FakePallet2_Text_Mom3
	closemessage
	playbgm MUS_DUMMY 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MOM
	addobject LOCALID_KABUTOPS_SHADOW
	clearflag FLAG_HIDE_MOMBUTOPS
	setflag FLAG_HIDE_MOM
	playmoncry SPECIES_KABUTOPS, CRY_MODE_ECHO_START
	waitmoncry
	applymovement LOCALID_KABUTOPS_SHADOW FakePallet2_Movement_Kabutops
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	playse SE_BERRY_BLENDER
	call FakePallet2_EventScript_BrailleMessage
	delay 100
	applymovement OBJ_EVENT_ID_PLAYER, FakePallet2_Movement_Slap2
	waitmovement 0
	applymovement LOCALID_KABUTOPS_SHADOW, FakePallet2_Movement_KabutopsBack2
	waitmovement 0
	playse SE_BANG
	waitse
	playmoncry SPECIES_KABUTOPS, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30
	fadescreen FADE_TO_WHITE
	setflag FLAG_HIDE_CAGE
	removeobject LOCALID_KABUTOPS_SHADOW
	fadescreen FADE_FROM_WHITE
	delay 200
	formatwarp MAP_MONITORING_STATION_STORAGE, 255, 19, 11
	waitstate
	releaseall
	end

FakePallet2_EventScript_Mom3::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, FakePallet2_Movement_FaceMom3
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MOM FakePallet2_Movement_Ex
	waitmovement 0
	textcolor 1
	applymovement LOCALID_MOM FakePallet2_Movement_Face3
	waitmovement 0
	msgbox FakePallet2_Text_Mom
	closemessage
	applymovement LOCALID_MOM FakePallet2_Movement_Sad3
	waitmovement 0
	msgbox FakePallet2_Text_Mom2
	closemessage
	applymovement LOCALID_MOM FakePallet2_Movement_Contemplate3
	waitmovement 0
	delay 50
	msgbox FakePallet2_Text_Mom3
	closemessage
	playbgm MUS_DUMMY 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MOM
	addobject LOCALID_KABUTOPS_SHADOW
	clearflag FLAG_HIDE_MOMBUTOPS
	setflag FLAG_HIDE_MOM
	playmoncry SPECIES_KABUTOPS, CRY_MODE_ECHO_START
	waitmoncry
	applymovement LOCALID_KABUTOPS_SHADOW FakePallet2_Movement_Kabutops
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	playse SE_BERRY_BLENDER
	call FakePallet2_EventScript_BrailleMessage
	delay 100
	applymovement OBJ_EVENT_ID_PLAYER, FakePallet2_Movement_Slap3
	waitmovement 0
	applymovement LOCALID_KABUTOPS_SHADOW, FakePallet2_Movement_KabutopsBack3
	waitmovement 0
	playse SE_BANG
	waitse
	playmoncry SPECIES_KABUTOPS, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30
	fadescreen FADE_TO_WHITE
	setflag FLAG_HIDE_CAGE
	removeobject LOCALID_KABUTOPS_SHADOW
	fadescreen FADE_FROM_WHITE
	delay 200
	formatwarp MAP_MONITORING_STATION_STORAGE, 255, 19, 11
	waitstate
	releaseall
	end
	
FakePallet2_EventScript_BrailleMessage::
	setvar VAR_0x8005, 130
	braillemessage_wait Braille_Text_Submit
	closemessage
	return
	
FakePallet2_Movement_Face1::
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_up
	step_end
	
FakePallet2_Movement_Face2::
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_right
	step_end
	
FakePallet2_Movement_Face3::
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_down
	step_end
	
FakePallet2_Movement_Ex::
	emote_exclamation_mark
	step_end
	
FakePallet2_Movement_Sad1::
	walk_in_place_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_up
	step_end
	
FakePallet2_Movement_Sad2::
	walk_in_place_left
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_right
	step_end
	
FakePallet2_Movement_Sad3::
	walk_in_place_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_down
	step_end

FakePallet2_Movement_Contemplate1::	
	walk_in_place_left
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_up
	step_end

FakePallet2_Movement_Contemplate2::	
	walk_in_place_left
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_right
	step_end

FakePallet2_Movement_Contemplate3::	
	walk_in_place_left
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_down
	step_end
	
FakePallet2_Movement_FaceMom1::
	walk_in_place_down
	step_end

FakePallet2_Movement_FaceMom2::
	walk_in_place_left
	step_end

FakePallet2_Movement_FaceMom3::
	walk_in_place_up
	step_end
	
FakePallet2_Movement_Slap1::
	lock_facing_direction
	walk_fast_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_down
	jump_down
	step_end
	
FakePallet2_Movement_Slap2::
	lock_facing_direction
	walk_fast_right
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_left
	jump_left
	step_end
	
FakePallet2_Movement_Slap3::
	lock_facing_direction
	walk_fast_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_up
	jump_up
	step_end
	
FakePallet2_Movement_Kabutops::
	face_player
	step_end
	
FakePallet2_Movement_KabutopsBack1::
	lock_facing_direction
	walk_fast_down
	walk_fast_down
	step_end
	
FakePallet2_Movement_KabutopsBack2::
	walk_in_place_down
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	step_end
	
FakePallet2_Movement_KabutopsBack3::
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	step_end