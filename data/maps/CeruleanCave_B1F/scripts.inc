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

CeruleanCave_B1F_EventScript_GiovanniEvent::
	lockall
	fadenewbgm MUS_NONE
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCave_B1F_Movement_LookUp
	waitmovement 0
	delay 60
	cleartrainerflag TRAINER_LEADER_GIOVANNI_MEWTWO
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCave_B1F_Movement_PanToActionFromBottom
	waitmovement 0
	special RemoveCameraObject
	delay 60
	applymovement LOCALID_GIOVANNI, CeruleanCave_B1F_Movement_LookUp
	clearflag FLAG_HIDE_CAVE_BALL
	addobject LOCALID_BALL
	waitmovement 0
	playse SE_BALL_THROW
	applymovement LOCALID_BALL, CeruleanCave_B1F_Movement_BallThrow
	waitmovement 0
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
	delay 50
	applymovement LOCALID_GIOVANNI, CeruleanCave_B1F_Movement_WalkUp
	waitmovement 0
	setflag FLAG_HIDE_CAVE_BALL
	removeobject LOCALID_BALL
	delay 50
	textcolor 0
	msgbox CeruleanCave_B1F_Text_Muhaha, MSGBOX_NPC
	closemessage
	playse SE_PIN
	applymovement LOCALID_GIOVANNI, CeruleanCave_B1F_Movement_Pin
	waitmovement 0
	delay 60
	msgbox CeruleanCave_B1F_Text_You, MSGBOX_NPC
	closemessage
	applymovement LOCALID_GIOVANNI, CeruleanCave_B1F_Movement_Talk
	playbgm MUS_SILPH, 0
	waitmovement 0
	trainerbattle_single TRAINER_LEADER_GIOVANNI_MEWTWO, CeruleanCave_B1F_Text_Haha, CeruleanCave_B1F_Text_GiovanniDefeat1, CeruleanCave_B1F_EventScript_GiovanniOntoBattle2, NO_MUSIC
	releaseall
	end

CeruleanCave_B1F_Movement_LookUp::
	walk_in_place_up
	step_end

CeruleanCave_B1F_Movement_PanToActionFromBottom::
	walk_slow_up
	step_end

CeruleanCave_B1F_Movement_BallThrow::
	walk_fast_up
	step_end

CeruleanCave_B1F_Movement_Pin::
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_down
	step_end

CeruleanCave_B1F_Movement_WalkUp::
	walk_up
	walk_in_place_up
	step_end

CeruleanCave_B1F_Movement_Talk::
	walk_down
	walk_in_place_down
	step_end

CeruleanCave_B1F_Text_Muhaha::
	.string "Finally!\n"
	.string "I've retrieved my creation.\p"
	.string "I've still got what it takes!$"

CeruleanCave_B1F_Text_You::
	.string "I shouldn't be surprised to meet\n"
	.string "you here, {PLAYER}.$"

CeruleanCave_B1F_Text_Haha::
	.string "You are here looking for POKéMON,\n"
	.string "am I correct?\p"
	.string "You should stop bothering…\p"
	.string "… for I just captured the most\n"
	.string "powerful POKéMON alive!\p"
	.string "In fact, it was mine to begin with!\p"
	.string "TEAM ROCKET created this POKéMON,\n"
	.string "with the help of a renowned team\l"
	.string "of scientists and scholars.\p"
	.string "It managed to escape our grasp,\n"
	.string "but now that's in the past.\p"
	.string "The all-powerful MEWTWO belongs\n"
	.string "to me once more!\p"
	.string "Even you, CHAMPION of KANTO, won't\n"
	.string "stand any chance against this foe.\p"
	.string "You will be the first victim of my\n"
	.string "newfound succes!$"

CeruleanCave_B1F_Text_GiovanniDefeat1::
	.string "Wh… what the?!\n"
	.string "My creation, defeated?\l"
	.string "But, how…?$"

CeruleanCave_B1F_EventScript_GiovanniOntoBattle2::
	applymovement LOCALID_GIOVANNI, CeruleanCave_B1F_Movement_Down
	waitmovement 0
	cleartrainerflag TRAINER_LEADER_GIOVANNI_MEWTWO
	textcolor 0
	trainerbattle_single TRAINER_LEADER_GIOVANNI_REMATCH, CeruleanCave_B1F_Text_Impressive, CeruleanCave_B1F_Text_GiovanniDefeat2, CeruleanCave_B1F_EventScript_GiovanniAfter, NO_MUSIC
	releaseall
	end

CeruleanCave_B1F_Text_Impressive::
	.string "Very impressive…\n"
	.string "It appears MEWTWO wasn't fully\l"
	.string "used to obeying commands yet.\p"
	.string "Still… this isn't over yet.\n"
	.string "Prepare for a world of pain!$"

CeruleanCave_B1F_Movement_Down::
	walk_down
	step_end

CeruleanCave_B1F_Text_GiovanniDefeat2::
	.string "Completely impossible!!$"

CeruleanCave_B1F_EventScript_GiovanniAfter::
	textcolor 0
	msgbox CeruleanCave_B1F_Text_GiovanniUnbelievable, MSGBOX_NPC
	closemessage
	playse SE_BALL_OPEN
	fadescreen FADE_TO_WHITE
	addobject LOCALID_MEWTWO
	waitse
	fadescreen FADE_FROM_WHITE
	applymovement LOCALID_GIOVANNI, CeruleanCave_B1F_Movement_LookUp
	waitmovement 0
	msgbox CeruleanCave_B1F_Text_GiovanniArgh, MSGBOX_NPC
	closemessage
	applymovement LOCALID_GIOVANNI, CeruleanCave_B1F_Movement_LookDown
	waitmovement 0
	msgbox CeruleanCave_B1F_Text_GiovanniDone, MSGBOX_NPC
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_GIOVANNI
	removeobject LOCALID_GIOVANNI
	fadescreen FADE_FROM_BLACK
	setvar VAR_GIOVANNI, 1
	releaseall
	end

CeruleanCave_B1F_Movement_LookDown::
	walk_in_place_down
	step_end

CeruleanCave_B1F_Text_GiovanniUnbelievable::
	.string "Such incredible strength…\p"
	.string "You would have been a perfect\n"
	.string "second-in-command for me…\l"
	.string "like your father once was.\p"
	.string "Surprised? Your father once served\n"
	.string "as my strongest and most loyal\l"
	.string "TEAM ROCKET EXECUTIVE.\p"
	.string "Unfortunately, even I do not know\n"
	.string "where he's gone to. Such a shame…\p"
	.string "Oh well…\p"
	.string "I still have MEWTWO in my possession.\n"
	.string "Once properly trained, it will be\l"
	.string "completely indestructible!$"

CeruleanCave_B1F_Text_GiovanniArgh::
	.string "WHAT?!\n"
	.string "How could MEWTWO escape from this\l"
	.string "MASTER BALL?!\p"
	.string "That… that's impossible!$"

CeruleanCave_B1F_Text_GiovanniDone::
	.string "What did you do?!\p"
	.string "… Say what?!\p"
	.string "You redirected your POKéMON's moves\n"
	.string "to break it during our battle?\p"
	.string "Very clever…\p"
	.string "I must say I'm impressed.\p"
	.string "I need copies of the MASTER BALL,\n"
	.string "and more powerful POKéMON if I am\l"
	.string "to lead TEAM ROCKET again.\p"
	.string "I hope you will someday follow\n"
	.string "in your father's footsteps,\l"
	.string "no matter how unlikely.\p"
	.string "If not, I hope this is farewell.$"

CeruleanCave_B1F_EventScript_Mewtwo::
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
