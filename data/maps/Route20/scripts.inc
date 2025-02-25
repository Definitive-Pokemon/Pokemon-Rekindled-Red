.set LOCALID_BLASTOISE_MASTER, 12
.set LOCALID_TENTACOOL_MASTER, 13
.set LOCALID_CLOYSTER_MASTER, 14
.set LOCALID_WARTORTLE_MASTER, 15
.set LOCALID_TENTACRUEL_MASTER, 16
.set LOCALID_MAXIMUS, 17
.set TRAINER, VAR_0x8009

Route20_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	.byte 0

Route20_OnTransition::
	call_if_unset FLAG_STOPPED_SEAFOAM_B3F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB3F
	call_if_unset FLAG_STOPPED_SEAFOAM_B4F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB4F
	goto Route20_MapScript_SetMasterTrainerMovementTypes
	end

Route20_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_BLASTOISE
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route20_MapScript_BlastoiseMasterMovementType
	setvar TRAINER, MASTER_TENTACOOL
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route20_MapScript_TentacoolMasterMovementType
	setvar TRAINER, MASTER_CLOYSTER
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route20_MapScript_CloysterMasterMovementType
	setvar TRAINER, MASTER_WARTORTLE
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route20_MapScript_WartortleMasterMovementType
	setvar TRAINER, MASTER_TENTACRUEL
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route20_MapScript_TentacruelMasterMovementType
	end

Route20_MapScript_BlastoiseMasterMovementType::
	setobjectmovementtype LOCALID_BLASTOISE_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_SWIM
	return

Route20_MapScript_TentacoolMasterMovementType::
	setobjectmovementtype LOCALID_TENTACOOL_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route20_MapScript_CloysterMasterMovementType::
	setobjectmovementtype LOCALID_CLOYSTER_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_SWIM
	return

Route20_MapScript_WartortleMasterMovementType::
	setobjectmovementtype LOCALID_WARTORTLE_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_SWIM
	return


Route20_MapScript_TentacruelMasterMovementType::
	setobjectmovementtype LOCALID_TENTACRUEL_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route20_EventScript_ResetSeafoamBouldersForB3F::
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_1
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_2
	return

Route20_EventScript_ResetSeafoamBouldersForB4F::
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_3
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_4
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_5
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_6
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_2
	return

Route20_EventScript_SeafoamIslandsSign::
	msgbox Route20_Text_SeafoamIslands, MSGBOX_SIGN
	end

Route20_EventScript_Maximus::
	lock
	textcolor 0
	message Route20_Text_Maximus
	waitmessage
	waitbuttonpress
	release
	end

Route20_Text_Maximus::
	.string "So this is where the legendary\n"
	.string "ARTICUNO is hiding…\p"
	.string "Good to know, but first I will visit\n"
	.string "MT. EMBER at the SEVII ISLANDS…\p"
	.string "MOLTRES is an easier target,\n"
	.string "after all.$"