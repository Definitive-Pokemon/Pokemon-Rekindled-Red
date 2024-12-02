.set LOCALID_GROUDON, 1

TerraCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TerraCave_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TerraCave_OnTransition
	.byte 0

TerraCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TerraCave_EventScript_TryRemoveGroudon
	end

TerraCave_EventScript_TryRemoveGroudon::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject LOCALID_GROUDON
	return

TerraCave_OnTransition:
	call_if_unset FLAG_DEFEATED_GROUDON, TerraCave_EventScript_ShowGroudon
	end

TerraCave_EventScript_ShowGroudon::
	clearflag FLAG_HIDE_TERRA_CAVE_GROUDON
	setvar VAR_TEMP_1, 1
	return

TerraCave_EventScript_Groudon::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TerraCave_Movement_PlayerUp
	waitmovement 0
	applymovement LOCALID_GROUDON, TerraCave_Movement_GroudonApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_GROUDON
	setwildbattle SPECIES_GROUDON, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartGroudonKyogreBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TerraCave_EventScript_DefeatedGroudon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TerraCave_EventScript_RanFromGroudon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TerraCave_EventScript_RanFromGroudon
	setflag FLAG_DEFEATED_GROUDON
	releaseall
	end

TerraCave_EventScript_DefeatedGroudon::
	setflag FLAG_DEFEATED_GROUDON
	setvar VAR_0x8004, SPECIES_GROUDON
	goto TerraCave_EventScript_GroudonFled
	end

TerraCave_EventScript_RanFromGroudon::
	setvar VAR_0x8004, SPECIES_GROUDON
	goto TerraCave_EventScript_GroudonFled
	end
	
TerraCave_EventScript_GroudonFled::
    fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    msgbox TerraCave_Text_GroudonFled
	closemessage
	releaseall
	end	

TerraCave_Text_GroudonFled::
	.string "GROUDON dug a hole and disappeared.$"

TerraCave_Movement_PlayerUp::
	face_up
	step_end

TerraCave_Movement_GroudonApproach:
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

