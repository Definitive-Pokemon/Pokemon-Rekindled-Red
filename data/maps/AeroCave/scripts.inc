.set LOCALID_RAYQUAZA, 1

AeroCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AeroCave_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, AeroCave_OnTransition
	.byte 0

AeroCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AeroCave_EventScript_TryRemoveRayquaza
	end

AeroCave_EventScript_TryRemoveRayquaza::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject LOCALID_RAYQUAZA
	return

AeroCave_OnTransition:
	call_if_unset FLAG_DEFEATED_RAYQUAZA, AeroCave_EventScript_ShowRayquaza
	end

AeroCave_EventScript_ShowRayquaza::
	clearflag FLAG_HIDE_AERO_CAVE_RAYQUAZA
	setvar VAR_TEMP_1, 1
	return

AeroCave_EventScript_Rayquaza::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, AeroCave_Movement_PlayerUp
	waitmovement 0
	applymovement LOCALID_RAYQUAZA, AeroCave_Movement_RayquazaApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_RAYQUAZA
	setwildbattle SPECIES_RAYQUAZA, 80
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRayquazaBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AeroCave_EventScript_DefeatedRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AeroCave_EventScript_RanFromRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AeroCave_EventScript_RanFromRayquaza
	setflag FLAG_DEFEATED_RAYQUAZA
	releaseall
	end

AeroCave_EventScript_DefeatedRayquaza::
	setflag FLAG_DEFEATED_RAYQUAZA
	setvar VAR_0x8004, SPECIES_RAYQUAZA
	goto AeroCave_EventScript_RayquazaFled
	end

AeroCave_EventScript_RanFromRayquaza::
	setvar VAR_0x8004, SPECIES_RAYQUAZA
	goto AeroCave_EventScript_RayquazaFled
	end
	
AeroCave_EventScript_RayquazaFled::
    fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    msgbox AeroCave_Text_RayquazaFled
	closemessage
	releaseall
	end	

AeroCave_Text_RayquazaFled::
	.string "RAYQUAZA disappeared into the clouds.$"

AeroCave_Movement_PlayerUp::
	face_up
	step_end

AeroCave_Movement_RayquazaApproach:
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

