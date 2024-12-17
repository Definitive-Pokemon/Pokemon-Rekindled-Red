.equ NUM_BOULDERS_PRESENT, VAR_TEMP_2
.set LOCALID_ARTICUNO_MASTER, 5
.set LOCALID_MAXIMUS, 6
.set TRAINER, VAR_0x8009

SeafoamIslands_B4F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_B4F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SeafoamIslands_B4F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SeafoamIslands_B4F_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SeafoamIslands_B4F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SeafoamIslands_B4F_OnFrame
	.byte 0

SeafoamIslands_B4F_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, SeafoamIslands_B4F_EventScript_TryRemoveArticuno
	end

SeafoamIslands_B4F_EventScript_TryRemoveArticuno::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Return
	removeobject VAR_LAST_TALKED
	return

SeafoamIslands_B4F_OnTransition::
	call_if_set FLAG_FOUGHT_ARTICUNO, SeafoamIslands_B4F_EventScript_HideArticuno
	call_if_unset FLAG_FOUGHT_ARTICUNO, SeafoamIslands_B4F_EventScript_TryShowArticuno
	call_if_unset FLAG_STOPPED_SEAFOAM_B4F_CURRENT, SeafoamIslands_B4F_EventScript_CheckStoppedCurrent
	call_if_set FLAG_STOPPED_SEAFOAM_B4F_CURRENT, SeafoamIslands_B4F_EventScript_SetNoCurrentLayout
	call SeafoamIslands_B4F_EventScript_HideMaximus
	goto SeafoamIslands_B4F_MapScript_SetMasterTrainerMovementTypes
	end

SeafoamIslands_B4F_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_ARTICUNO
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, SeafoamIslands_B4F_MapScript_ArticunoMasterMovementType
	end

SeafoamIslands_B4F_MapScript_ArticunoMasterMovementType::
	setobjectmovementtype LOCALID_ARTICUNO_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

SeafoamIslands_B4F_EventScript_HideMaximus::
	removeobject LOCALID_MAXIMUS
	setflag FLAG_HIDE_MAXIMUS_SEAFOAM
	return

SeafoamIslands_B4F_EventScript_Maximus::
	textcolor 0
	fadenewbgm MUS_NONE
	msgbox SeafoamIslands_B4F_Text_MaximusCommend, MSGBOX_NPC
	closemessage
	delay 80
	fadescreen FADE_TO_BLACK
	playse SE_WARP_OUT
	waitse
	clearflag FLAG_HIDE_MAXIMUS_SEAFOAM
	addobject LOCALID_MAXIMUS
	fadescreen FADE_FROM_BLACK
	playbgm MUS_B_PIKE, 0
	delay 40
	applymovement LOCALID_MAXIMUS, SeafoamIslands_B4F_Movement_WalkDownPickUpFeather
	waitmovement 0
	textcolor 2
	msgbox SeafoamIslands_B4F_Text_MaximusTook, MSGBOX_NPC
	closemessage
	delay 80
	applymovement LOCALID_MAXIMUS, SeafoamIslands_B4F_Movement_Face
	waitmovement 0
	textcolor 0
	msgbox SeafoamIslands_B4F_Text_MaximusDone, MSGBOX_NPC
	closemessage
	delay 40
	applymovement LOCALID_MAXIMUS, SeafoamIslands_B4F_Movement_Talk
	waitmovement 0
	msgbox SeafoamIslands_B4F_Text_Talk, MSGBOX_NPC
	closemessage
	delay 40
	fadescreen FADE_TO_BLACK
	playse SE_WARP_IN
	waitse
	removeobject LOCALID_MAXIMUS
	setflag FLAG_MAXIMUS_SEAFOAM
	setflag FLAG_HIDE_MAXIMUS_SEAFOAM
	fadescreen FADE_FROM_BLACK
	fadenewbgm MUS_NONE
	delay 60
	playbgm MUS_VIRIDIAN_FOREST, 0
	releaseall
	end

SeafoamIslands_B4F_Text_MaximusCommend::
	.string "I commend you for taking on\n"
	.string "the legendary ARTICUNO.\p"
	.string "To be quite frank, I wasn't sure if\n"
	.string "I would be able to collect this\l"
	.string "CYAN FEATHER without your help.$"

SeafoamIslands_B4F_Movement_WalkDownPickUpFeather::
	walk_down
	delay_16
	walk_in_place_down
	step_end

SeafoamIslands_B4F_Text_MaximusTook::
	.string "The MYSTERIOUS MAN obtained one\n"
	.string "of ARTICUNO's fallen feathers!$"

SeafoamIslands_B4F_Movement_Face::
	face_player
	lock_facing_direction
	walk_in_place_down
	step_end

SeafoamIslands_B4F_Text_MaximusDone::
	.string "That's the last one!\p"
	.string "Wait, I haven't introduced myself\n"
	.string "properly, have I?\p"
	.string "My name is MAXIMUS.\n"
	.string "I am a collector of rare POKéMON,\l"
	.string "hailing from a faraway region.\p"
	.string "As you may realize, I don't eschew…\n"
	.string "more creative methods in order to\l"
	.string "obtain the things I desire.\p"
	.string "You may have already seen what\n"
	.string "I did to poor ZAPDOS…$"

SeafoamIslands_B4F_Movement_Talk::
	face_player
	lock_facing_direction
	walk_in_place_down
	step_end

SeafoamIslands_B4F_Text_Talk::
	.string "… You're expecting some kind of\n"
	.string "battle coming up, am I right?\p"
	.string "I'm sorry, but I don't really\n"
	.string "do these. I have work to do.\p"
	.string "Who knows. Maybe we will meet\n"
	.string "again some other time.\p"
	.string "Maybe I have something special\n"
	.string "to show you then…$"

SeafoamIslands_B4F_EventScript_CheckStoppedCurrent::
	setvar NUM_BOULDERS_PRESENT, 0
	call_if_unset FLAG_HIDE_SEAFOAM_B4F_BOULDER_1, SeafoamIslands_B4F_EventScript_AddBoulderPresent
	call_if_unset FLAG_HIDE_SEAFOAM_B4F_BOULDER_2, SeafoamIslands_B4F_EventScript_AddBoulderPresent
	call_if_eq NUM_BOULDERS_PRESENT, 2, SeafoamIslands_B4F_EventScript_StoppedCurrent
	return

SeafoamIslands_B4F_EventScript_StoppedCurrent::
	setflag FLAG_STOPPED_SEAFOAM_B4F_CURRENT
	return

SeafoamIslands_B4F_EventScript_SetNoCurrentLayout::
	setmaplayoutindex LAYOUT_SEAFOAM_ISLANDS_B4F_CURRENT_STOPPED
	return

SeafoamIslands_B4F_EventScript_TryShowArticuno::
	goto_if_set FLAG_ARTICUNO_FLEW_AWAY, EventScript_Return
	clearflag FLAG_HIDE_ARTICUNO
	return

SeafoamIslands_B4F_EventScript_HideArticuno::
	setflag FLAG_HIDE_ARTICUNO
	return

SeafoamIslands_B4F_OnLoad::
	setvar NUM_BOULDERS_PRESENT, 0
	call_if_unset FLAG_HIDE_SEAFOAM_B4F_BOULDER_1, SeafoamIslands_B4F_EventScript_AddBoulderPresent
	call_if_unset FLAG_HIDE_SEAFOAM_B4F_BOULDER_2, SeafoamIslands_B4F_EventScript_AddBoulderPresent
	goto_if_eq NUM_BOULDERS_PRESENT, 2, SeafoamIslands_B4F_EventScript_SetCalmWaterNearStairs
	end

SeafoamIslands_B4F_EventScript_SetCalmWaterNearStairs::
	setmetatile 12, 14, METATILE_General_CalmWater, 0
	setmetatile 13, 14, METATILE_General_CalmWater, 0
	end

SeafoamIslands_B4F_OnWarp::
	map_script_2 VAR_MAP_SCENE_SEAFOAM_ISLANDS_B4F, 1, SeafoamIslands_B4F_EventScript_WarpInOnCurrent
	.2byte 0

SeafoamIslands_B4F_EventScript_WarpInOnCurrent::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	special ForcePlayerToStartSurfing
	end

SeafoamIslands_B4F_OnFrame::
	map_script_2 VAR_MAP_SCENE_SEAFOAM_ISLANDS_B4F, 1, SeafoamIslands_B4F_EventScript_EnterOnCurrent
	map_script_2 VAR_TEMP_1, 1, SeafoamIslands_B4F_EventScript_EnterByFalling
	.2byte 0

@ The current the player is forced in on from B3F
SeafoamIslands_B4F_EventScript_EnterOnCurrent::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, SeafoamIslands_B4F_Movement_EnterOnCurrent
	waitmovement 0
	setvar VAR_MAP_SCENE_SEAFOAM_ISLANDS_B4F, 0
	releaseall
	end

SeafoamIslands_B4F_Movement_EnterOnCurrent::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

@ The current the player lands on when entering the map by falling
SeafoamIslands_B4F_EventScript_EnterByFalling::
	lockall
	setvar NUM_BOULDERS_PRESENT, 0
	call_if_unset FLAG_HIDE_SEAFOAM_B4F_BOULDER_1, SeafoamIslands_B4F_EventScript_AddBoulderPresent
	call_if_unset FLAG_HIDE_SEAFOAM_B4F_BOULDER_2, SeafoamIslands_B4F_EventScript_AddBoulderPresent
	goto_if_eq NUM_BOULDERS_PRESENT, 2, SeafoamIslands_B4F_EventScript_CurrentBlocked
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_lt VAR_0x8008, 9, SeafoamIslands_B4F_EventScript_RideCurrentFar
	call_if_ge VAR_0x8008, 9, SeafoamIslands_B4F_EventScript_RideCurrentClose
	special SeafoamIslandsB4F_CurrentDumpsPlayerOnLand
	setvar VAR_TEMP_1, 0
	releaseall
	end

SeafoamIslands_B4F_EventScript_AddBoulderPresent::
	addvar NUM_BOULDERS_PRESENT, 1
	return

SeafoamIslands_B4F_EventScript_RideCurrentFar::
	applymovement OBJ_EVENT_ID_PLAYER, SeafoamIslands_B4F_Movement_RideCurrentFar
	waitmovement 0
	return

SeafoamIslands_B4F_EventScript_RideCurrentClose::
	applymovement OBJ_EVENT_ID_PLAYER, SeafoamIslands_B4F_Movement_RideCurrentClose
	waitmovement 0
	return

SeafoamIslands_B4F_EventScript_CurrentBlocked::
	setvar VAR_TEMP_1, 0
	releaseall
	end

SeafoamIslands_B4F_Movement_RideCurrentFar::
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

SeafoamIslands_B4F_Movement_RideCurrentClose::
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

@ Triggers blocking re-entry to B3F
SeafoamIslands_B4F_EventScript_UpwardCurrent::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, SeafoamIslands_B4F_Movement_WalkUp
	waitmovement 0
	releaseall
	end

SeafoamIslands_B4F_Movement_WalkUp::
	walk_up
	step_end

SeafoamIslands_B4F_EventScript_Articuno::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_ARTICUNO, 50
	waitse
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	message Text_Gyaoo
	waitmessage
	waitmoncry
	delay 10
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SeafoamIslands_B4F_EventScript_DefeatedArticuno
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SeafoamIslands_B4F_EventScript_RanFromArticuno
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SeafoamIslands_B4F_EventScript_RanFromArticuno
	setflag FLAG_FOUGHT_ARTICUNO
	goto_if_unset FLAG_MAXIMUS_SEAFOAM, SeafoamIslands_B4F_EventScript_Maximus
	end

SeafoamIslands_B4F_EventScript_DefeatedArticuno::
	setflag FLAG_ARTICUNO_FLEW_AWAY
	setvar VAR_0x8004, SPECIES_ARTICUNO
	goto_if_set FLAG_MAXIMUS_SEAFOAM, EventScript_MonFlewAway
	goto EventScript_MonFlewAwayMaximus
	end

SeafoamIslands_B4F_EventScript_RanFromArticuno::
	setvar VAR_0x8004, SPECIES_ARTICUNO
	goto_if_set FLAG_MAXIMUS_SEAFOAM, EventScript_MonFlewAway
	goto EventScript_MonFlewAwayMaximus
	end

EventScript_MonFlewAwayMaximus::
    fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox Text_MonFlewAway
	closemessage
	delay 50
	goto SeafoamIslands_B4F_EventScript_Maximus
    end

SeafoamIslands_B4F_EventScript_BoulderHintSign::
	msgbox SeafoamIslands_B4F_Text_BouldersMightChangeWaterFlow, MSGBOX_SIGN
	end

SeafoamIslands_B4F_EventScript_FastCurrentSign::
	msgbox SeafoamIslands_B4F_Text_DangerFastCurrent, MSGBOX_SIGN
	end
