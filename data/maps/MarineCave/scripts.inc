.set LOCALID_KYOGRE, 1

MarineCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MarineCave_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MarineCave_OnTransition
	.byte 0

MarineCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MarineCave_EventScript_TryRemoveKyogre
	end

MarineCave_EventScript_TryRemoveKyogre::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject LOCALID_KYOGRE
	return

MarineCave_OnTransition:
	call_if_unset FLAG_DEFEATED_KYOGRE, MarineCave_EventScript_ShowKyogre
	end

MarineCave_EventScript_ShowKyogre::
	clearflag FLAG_HIDE_MARINE_CAVE_KYOGRE
	setvar VAR_TEMP_1, 1
	return

MarineCave_EventScript_Kyogre::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, MarineCave_Movement_PlayerUp
	waitmovement 0
	applymovement LOCALID_KYOGRE, MarineCave_Movement_KyogreApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_KYOGRE
	setwildbattle SPECIES_KYOGRE, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MarineCave_EventScript_DefeatedKyogre
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MarineCave_EventScript_RanFromKyogre
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MarineCave_EventScript_RanFromKyogre
	setflag FLAG_DEFEATED_KYOGRE
	releaseall
	end

MarineCave_EventScript_DefeatedKyogre::
	setflag FLAG_DEFEATED_KYOGRE
	setvar VAR_0x8004, SPECIES_KYOGRE
	goto MarineCave_EventScript_KyogreFled
	end

MarineCave_EventScript_RanFromKyogre::
	setvar VAR_0x8004, SPECIES_KYOGRE
	goto MarineCave_EventScript_KyogreFled
	end
	
MarineCave_EventScript_KyogreFled::
    fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    msgbox MarineCave_Text_KyogreFled
	closemessage
	releaseall
	end	

MarineCave_Text_KyogreFled::
	.string "KYOGRE returned to the ocean.$"

MarineCave_Movement_PlayerUp::
	face_up
	step_end

MarineCave_Movement_KyogreApproach:
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

