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
	call_if_unset FLAG_FOUGHT_RAYQUAZA, AeroCave_EventScript_ShowRayquaza
	end

AeroCave_EventScript_ShowRayquaza::
	checkitem ITEM_RUBY
	goto_if_eq VAR_RESULT, 0, AeroCave_EventScript_HideRayquaza
	checkitem ITEM_SAPPHIRE
	goto_if_eq VAR_RESULT, 0, AeroCave_EventScript_HideRayquaza
	clearflag FLAG_HIDE_AERO_CAVE_RAYQUAZA
	setvar VAR_TEMP_1, 1
	return
AeroCave_EventScript_HideRayquaza::
	setflag FLAG_HIDE_AERO_CAVE_RAYQUAZA
	return

AeroCave_EventScript_Rayquaza::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, AeroCave_Movement_PlayerUp
	waitmovement 0
	fadescreenswapbuffers FADE_TO_WHITE
	playse SE_M_FLY
	applymovement LOCALID_RAYQUAZA, AeroCave_Movement_RayquazaApproach
	waitmovement 0
	fadescreenswapbuffers FADE_FROM_WHITE
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_RAYQUAZA
	setwildbattle SPECIES_RAYQUAZA, 80
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartGroudonKyogreBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AeroCave_EventScript_DefeatedRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AeroCave_EventScript_RanFromRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AeroCave_EventScript_RanFromRayquaza
	setflag FLAG_FOUGHT_RAYQUAZA
	releaseall
	end

AeroCave_EventScript_DefeatedRayquaza::
	setflag FLAG_RAYQUAZA_FLED
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
	.string "RAYQUAZA disappeared into\n"
	.string "the clouds.$"

AeroCave_Movement_PlayerUp::
	face_up
	step_end

AeroCave_Movement_RayquazaApproach:
	init_affine_anim
	walk_down
	walk_down
	walk_down
	step_end

