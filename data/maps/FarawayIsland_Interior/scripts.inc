.set LOCALID_MEW, 1

FarawayIsland_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, FarawayIsland_Interior_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Interior_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FarawayIsland_Interior_OnFrame
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, FarawayIsland_Interior_OnReturnToField
	.byte 0

FarawayIsland_Interior_OnReturnToField:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FarawayIsland_Interior_EventScript_TrySetMewAboveGrass
	end

FarawayIsland_Interior_EventScript_TrySetMewAboveGrass::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FarawayIsland_Interior_EventScript_SetMewAboveGrass
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq FarawayIsland_Interior_EventScript_SetMewAboveGrass
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq FarawayIsland_Interior_EventScript_SetMewAboveGrass
	compare VAR_RESULT, B_OUTCOME_MON_TELEPORTED
	goto_if_eq FarawayIsland_Interior_EventScript_SetMewAboveGrass
	return

FarawayIsland_Interior_EventScript_SetMewAboveGrass::
	setvar VAR_0x8004, 1
	special SetMewAboveGrass
	return

FarawayIsland_Interior_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FarawayIsland_Interior_EventScript_TryRemoveMew
	end
	
FarawayIsland_Interior_EventScript_TryRemoveMew::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return

FarawayIsland_Interior_OnTransition:
	setvar VAR_FARAWAY_ISLAND_STEP_COUNTER, 0
	setvar VAR_TEMP_1, 1
	call_if_set FLAG_FOUGHT_MEW, FarawayIsland_Interior_EventScript_HideMew
	call_if_unset FLAG_FOUGHT_MEW, FarawayIsland_Interior_EventScript_TryShowMew
	end

FarawayIsland_Interior_EventScript_HideMew::
	setflag FLAG_HIDE_MEW
	return

FarawayIsland_Interior_EventScript_TryShowMew::
	goto_if_set FLAG_MEW_FLEW_AWAY, EventScript_Return
	clearflag FLAG_HIDE_MEW
	setvar VAR_TEMP_1, 0
	return

FarawayIsland_Interior_OnFrame:
	map_script_2 VAR_TEMP_1, 0, FarawayIsland_Interior_EventScript_FindMew
	.2byte 0

FarawayIsland_Interior_EventScript_FindMew::
	lockall
	playse SE_PIN
	applymovement LOCALID_MEW, FarawayIsland_Interior_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MEW, FarawayIsland_Interior_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MEW, FarawayIsland_Interior_Movement_MewMoveAndHide
	waitmovement 0
	copyobjectxytoperm LOCALID_MEW
	setvar VAR_TEMP_1, 1
	releaseall
	end

FarawayIsland_Interior_Movement_ExclamationMark:
	emote_exclamation_mark
	step_end

FarawayIsland_Interior_Movement_Delay48:
	delay_16
	delay_16
	delay_16
	step_end

FarawayIsland_Interior_Movement_MewMoveAndHide:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	set_invisible
	step_end

FarawayIsland_Interior_Movement_MewAppear:
	set_visible
	step_end

FarawayIsland_Interior_Movement_MewFloatUpNorth:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_down
	walk_in_place_down
	step_end

FarawayIsland_Interior_Movement_MewFloatUpSouth:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_up
	walk_in_place_up
	step_end

FarawayIsland_Interior_Movement_MewFloatUpWest:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_right
	walk_in_place_right
	step_end

FarawayIsland_Interior_Movement_MewFloatUpEast:
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	walk_in_place_left
	walk_in_place_left
	step_end

FarawayIsland_Interior_EventScript_Mew::
	lock
	faceplayer
	applymovement LOCALID_MEW, FarawayIsland_Interior_Movement_MewAppear
	waitmovement 0
	setvar VAR_0x8004, 0
	special SetMewAboveGrass
	message FarawayIsland_Interior_Text_Mew
	waitse
	playmoncry SPECIES_MEW, 2
	compare VAR_FACING, DIR_NORTH
	call_if_eq FarawayIsland_Interior_EventScript_FoundMewNorth
	compare VAR_FACING, DIR_SOUTH
	call_if_eq FarawayIsland_Interior_EventScript_FoundMewSouth
	compare VAR_FACING, DIR_WEST
	call_if_eq FarawayIsland_Interior_EventScript_FoundMewWest
	compare VAR_FACING, DIR_EAST
	call_if_eq FarawayIsland_Interior_EventScript_FoundMewEast
	delay 40
	waitmoncry
	setvar VAR_0x8004, SPECIES_MEW
	setvar VAR_0x8005, 50 @ level
	setvar VAR_0x8006, ITEM_NONE
	special CreateEnemyEventMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FarawayIsland_Interior_EventScript_MewDefeated
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq FarawayIsland_Interior_EventScript_PlayerOrMewRan
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq FarawayIsland_Interior_EventScript_PlayerOrMewRan
	compare VAR_RESULT, B_OUTCOME_MON_TELEPORTED
	goto_if_eq FarawayIsland_Interior_EventScript_PlayerOrMewRan
	setflag FLAG_FOUGHT_MEW
	release
	end

FarawayIsland_Interior_EventScript_MewDefeated::
	setflag FLAG_MEW_FLEW_AWAY
	setvar VAR_0x8004, SPECIES_MEW
	goto EventScript_MonFlewAway
	end

FarawayIsland_Interior_EventScript_PlayerOrMewRan::
	setvar VAR_0x8004, SPECIES_MEW
	goto EventScript_MonFlewAway
	end

FarawayIsland_Interior_EventScript_FoundMewNorth::
	applymovement LOCALID_MEW, FarawayIsland_Interior_Movement_MewFloatUpNorth
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_FoundMewSouth::
	applymovement LOCALID_MEW, FarawayIsland_Interior_Movement_MewFloatUpSouth
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_FoundMewWest::
	applymovement LOCALID_MEW, FarawayIsland_Interior_Movement_MewFloatUpWest
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_FoundMewEast::
	applymovement LOCALID_MEW, FarawayIsland_Interior_Movement_MewFloatUpEast
	waitmovement 0
	return

FarawayIsland_Interior_EventScript_HideMewWhenGrassCut::
	lockall
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_MEW
	removeobject LOCALID_MEW
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox FarawayIsland_Interior_Text_TheFeelingOfBeingWatchedFaded, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

FarawayIsland_Interior_Text_TheFeelingOfBeingWatchedFaded:
	.string "The feeling of being watched faded…$"

FarawayIsland_Interior_Text_Mew:
	.string "Myuu…$"
	