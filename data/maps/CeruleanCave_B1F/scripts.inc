.equ LOCALID_MEWTWO, 3
.equ LOCALID_GIOVANNI, 13
.equ LOCALID_BALL, 14

CeruleanCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CeruleanCave_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCave_B1F_OnTransition
	.byte 0

CeruleanCave_B1F_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, CeruleanCave_B1F_EventScript_TryRemoveMewtwo
	end

CeruleanCave_B1F_EventScript_GiovanniEvent::
	lockall
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCave_B1F_Movement_PanToActionFromBottom
	waitmovement 0
	special RemoveCameraObject
	delay 60
	applymovement LOCALID_GIOVANNI, CeruleanCave_B1F_Movement_CatchMewtwo
	showobject LOCALID_BALL
	waitmovement 0
	playse SE_BALL_THROW
	applymovement LOCALID_BALL, CeruleanCave_B1F_Movement_BallThrow
	waitmovement
	waitse
	playse SE_BALL_OPEN
	fadescreen FADE_TO_WHITE
	removeobject LOCALID_MEWTWO
	waitse
	fadescreen FADE_FROM_WHITE
	playse SE_BALL_BOUNCE_1
	waitse
	playse SE_BALL_BOUNCE_2
	waitse
	playse SE_BALL_BOUNCE_3
	waitse
	playse SE_BALL_BOUNCE_4
	waitse
	playse SE_BALL_CLICK
	waitse
	textcolor 0
	msgbox CeruleanCave_B1F_Text_Muhaha, MSGBOX_NPC
	closemessage
	playse SE_PIN
	applymovement LOCALID_GIOVANNI, CeruleanCave_B1F_Movement_Pin
	waitmovement 0
	delay_16
	applymovement LOCALID_GIOVANNI, CeruleanCave_B1F_Movement_Turn
	waitmovement 0
	msgbox CeruleanCave_B1F_Text_You, MSGBOX_NPC
	closemessage
	applymovement LOCALID_GIOVANNI, CeruleanCave_B1F_Movement_Turn
	waitmovement 0
	msgbox CeruleanCave_B1F_Text_Haha, MSGBOX_NPC
	releaseall
	end
	

CeruleanCave_B1F_Movement_PanToActionFromBottom::
	walk_slow_up
	step_end

CeruleanCave_B1F_Movement_CatchMewtwo::
	walk_in_place_up
	step_end

CeruleanCave_B1F_Movement_BallThrow::
	walk_fast_up
	step_end

CeruleanCave_B1F_Movement_Pin::
	emote_exclamation_mark
	step_end

CeruleanCave_B1F_Movement_Turn::
	walk_in_place_down
	step_end

CeruleanCave_B1F_Text_Muhaha::
	.string "Finally!\n"
	.string "I've retrieved my creation.\p"
	.string "I've still got what it takes!$"

CeruleanCave_B1F_Text_You::
	.string "It's… it's you…$"

CeruleanCave_B1F_Text_Haha::
	.string "Haha! To be continued!$"

CeruleanCave_B1F_EventScript_TryRemoveMewtwo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Return
	removeobject VAR_LAST_TALKED
	return

CeruleanCave_B1F_OnTransition::
	call_if_set FLAG_FOUGHT_MEWTWO, CeruleanCave_B1F_EventScript_HideMewtwo
	call_if_unset FLAG_FOUGHT_MEWTWO, CeruleanCave_B1F_EventScript_TryShowMewtwo
	end

CeruleanCave_B1F_EventScript_TryShowMewtwo::
	goto_if_set FLAG_MEWTWO_FLEW_AWAY, EventScript_Return
	clearflag FLAG_HIDE_MEWTWO
	return

CeruleanCave_B1F_EventScript_HideMewtwo::
	setflag FLAG_HIDE_MEWTWO
	return

CeruleanCave_B1F_EventScript_Mewtwo::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	message CeruleanCave_B1F_Text_Mew
	waitmessage
	waitmoncry
	delay 20
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setwildbattle SPECIES_MEWTWO, 90
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CeruleanCave_B1F_EventScript_DefeatedMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CeruleanCave_B1F_EventScript_RanFromMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CeruleanCave_B1F_EventScript_RanFromMewtwo
	setflag FLAG_FOUGHT_MEWTWO
	release
	end

CeruleanCave_B1F_EventScript_DefeatedMewtwo::
	setflag FLAG_MEWTWO_FLEW_AWAY
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto EventScript_MonFlewAway
	end

CeruleanCave_B1F_EventScript_RanFromMewtwo::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto EventScript_MonFlewAway
	end
