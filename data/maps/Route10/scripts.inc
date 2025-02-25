.set LOCALID_RATTATA_MASTER, 11
.set LOCALID_ELECTABUZZ_MASTER, 12
.set LOCALID_CHARMELEON_MASTER, 13
.set LOCALID_ALAKAZAM_MASTER, 14
.set TRAINER, VAR_0x8009

Route10_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_MapScript_SetMasterTrainerMovementTypes
	.byte 0

Route10_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_RATTATA
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route10_MapScript_RattataMasterMovementType
	setvar TRAINER, MASTER_ELECTABUZZ
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route10_MapScript_ElectabuzzMasterMovementType
	setvar TRAINER, MASTER_CHARMELEON
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route10_MapScript_CharmeleonMasterMovementType
	setvar TRAINER, MASTER_ALAKAZAM
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, Route10_MapScript_AlakazamMasterMovementType
	end

Route10_MapScript_RattataMasterMovementType::
	setobjectmovementtype LOCALID_RATTATA_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route10_MapScript_ElectabuzzMasterMovementType::
	setobjectmovementtype LOCALID_ELECTABUZZ_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route10_MapScript_CharmeleonMasterMovementType::
	setobjectmovementtype LOCALID_CHARMELEON_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route10_MapScript_AlakazamMasterMovementType::
	setobjectmovementtype LOCALID_ALAKAZAM_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

Route10_EventScript_NorthRockTunnelSign::
	msgbox Route10_Text_RockTunnelDetourToLavender, MSGBOX_SIGN
	end

Route10_EventScript_SouthRockTunnelSign::
	msgbox Route10_Text_RockTunnel, MSGBOX_SIGN
	end

Route10_EventScript_PowerPlantSign::
	msgbox Route10_Text_PowerPlant, MSGBOX_SIGN
	end

Route10_EventScript_Incident::
	msgbox Route10_Text_Incident, MSGBOX_NPC
	end

Route10_Text_Incident::
	.string "I'm sorry, but the POWER PLANT is\n"
	.string "currently off-limits due to an\l"
	.string "act of vandalism committed.\p"
	.string "That's right, someone decided to\n"
	.string "just go mess up things inside.$"