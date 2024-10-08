ForsakenTombB9F_MapScripts::
	.byte 0

ForsakenTombB9F_EventScript_StopChecking::
	end

ForsakenTombB9F_EventScript_Regigigas::
	lock
	setvar VAR_0x8004, SPECIES_REGIROCK
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_ne VAR_RESULT, TRUE, ForsakenTombB9F_EventScript_StopChecking
	setvar VAR_0x8004, SPECIES_REGICE
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_ne VAR_RESULT, TRUE, ForsakenTombB9F_EventScript_StopChecking
	setvar VAR_0x8004, SPECIES_REGISTEEL
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_ne VAR_RESULT, TRUE, ForsakenTombB9F_EventScript_StopChecking
	delay 20
	release
	end