.set LOCALID_VOLTORB_MASTER, 9
.set LOCALID_ZAPDOS_MASTER, 10
.set TRAINER, VAR_0x8009

PowerPlant_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PowerPlant_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, PowerPlant_OnTransition
	.byte 0

PowerPlant_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, PowerPlant_EventScript_TryRemoveStaticMon
	end

PowerPlant_EventScript_TryRemoveStaticMon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Return
	removeobject VAR_LAST_TALKED
	return

PowerPlant_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POWER_PLANT
	call_if_set FLAG_FOUGHT_ZAPDOS, PowerPlant_EventScript_HideZapdos
	call_if_unset FLAG_FOUGHT_ZAPDOS, PowerPlant_EventScript_TryShowZapdos
	call_if_unset FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1, PowerPlant_EventScript_ShowElectrode1
	call_if_unset FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2, PowerPlant_EventScript_ShowElectrode2
	call_if_unset FLAG_FOUGHT_POWER_PLANT_MACHOKE_1, PowerPlant_EventScript_ShowMachoke1
	call_if_unset FLAG_FOUGHT_POWER_PLANT_MACHOKE_2, PowerPlant_EventScript_ShowMachoke2
	call_if_unset FLAG_FOUGHT_POWER_PLANT_MACHOKE_3, PowerPlant_EventScript_ShowMachoke3
	call_if_unset FLAG_FOUGHT_POWER_PLANT_MACHOKE_4, PowerPlant_EventScript_ShowMachoke4
	goto PowerPlant_MapScript_SetMasterTrainerMovementTypes
	end

PowerPlant_MapScript_SetMasterTrainerMovementTypes::
	setvar TRAINER, MASTER_VOLTORB
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, PowerPlant_MapScript_VoltorbMasterMovementType
	setvar TRAINER, MASTER_ZAPDOS
	callnative ShouldChangeMasterTrainerMovementType
	call_if_eq VAR_RESULT, FALSE, PowerPlant_MapScript_ZapdosMasterMovementType
	end

PowerPlant_MapScript_VoltorbMasterMovementType::
	setobjectmovementtype LOCALID_VOLTORB_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

PowerPlant_MapScript_ZapdosMasterMovementType::
	setobjectmovementtype LOCALID_ZAPDOS_MASTER, MOVEMENT_TYPE_RAISE_HAND_AND_STOP
	return

PowerPlant_EventScript_TryShowZapdos::
	goto_if_set FLAG_ZAPDOS_FLEW_AWAY, EventScript_Return
	clearflag FLAG_HIDE_ZAPDOS
	return

PowerPlant_EventScript_SeenZapdos::
	setvar VAR_SEEN_ZAPDOS, 1
	setflag FLAG_SEEN_ZAPDOS
	end

PowerPlant_EventScript_HideZapdos::
	setflag FLAG_HIDE_ZAPDOS
	return

PowerPlant_EventScript_ShowElectrode1::
	clearflag FLAG_HIDE_POWER_PLANT_ELECTRODE_1
	return

PowerPlant_EventScript_ShowElectrode2::
	clearflag FLAG_HIDE_POWER_PLANT_ELECTRODE_2
	return

PowerPlant_EventScript_ShowMachoke1::
	clearflag FLAG_HIDE_POWER_PLANT_MACHOKE_1
	return

PowerPlant_EventScript_ShowMachoke2::
	clearflag FLAG_HIDE_POWER_PLANT_MACHOKE_2
	return

PowerPlant_EventScript_ShowMachoke3::
	clearflag FLAG_HIDE_POWER_PLANT_MACHOKE_3
	return

PowerPlant_EventScript_ShowMachoke4::
	clearflag FLAG_HIDE_POWER_PLANT_MACHOKE_4
	return

PowerPlant_EventScript_Zapdos::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	setwildbattle SPECIES_ZAPDOS, 50
	waitse
	playmoncry SPECIES_ZAPDOS, 11
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
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerPlant_EventScript_DefeatedZapdos
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_RanFromZapdos
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_RanFromZapdos
	setflag FLAG_FOUGHT_ZAPDOS
	release
	end

PowerPlant_EventScript_DefeatedZapdos::
	setflag FLAG_ZAPDOS_FLEW_AWAY
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto EventScript_MonFlewAway
	end

PowerPlant_EventScript_RanFromZapdos::
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto EventScript_MonFlewAway
	end

PowerPlant_EventScript_Machoke1::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	setwildbattle SPECIES_MACHOKE, 45
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerPlant_EventScript_FoughtMachoke1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_FoughtMachoke1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_FoughtMachoke1
	setflag FLAG_FOUGHT_POWER_PLANT_MACHOKE_1
	release
	end

PowerPlant_EventScript_FoughtMachoke1::
	setflag FLAG_FOUGHT_POWER_PLANT_MACHOKE_1
	goto EventScript_RemoveStaticMon
	end

PowerPlant_EventScript_Machoke2::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	setwildbattle SPECIES_MACHOKE, 45
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerPlant_EventScript_FoughtMachoke2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_FoughtMachoke2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_FoughtMachoke2
	setflag FLAG_FOUGHT_POWER_PLANT_MACHOKE_2
	release
	end

PowerPlant_EventScript_FoughtMachoke2::
	setflag FLAG_FOUGHT_POWER_PLANT_MACHOKE_2
	goto EventScript_RemoveStaticMon
	end

PowerPlant_EventScript_Machoke3::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	setwildbattle SPECIES_MACHOKE, 45
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerPlant_EventScript_FoughtMachoke3
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_FoughtMachoke3
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_FoughtMachoke3
	setflag FLAG_FOUGHT_POWER_PLANT_MACHOKE_3
	release
	end

PowerPlant_EventScript_FoughtMachoke3::
	setflag FLAG_FOUGHT_POWER_PLANT_MACHOKE_3
	goto EventScript_RemoveStaticMon
	end

PowerPlant_EventScript_Machoke4::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	setwildbattle SPECIES_MACHOKE, 45
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerPlant_EventScript_FoughtMachoke4
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_FoughtMachoke4
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_FoughtMachoke4
	setflag FLAG_FOUGHT_POWER_PLANT_MACHOKE_4
	release
	end

PowerPlant_EventScript_FoughtMachoke4::
	setflag FLAG_FOUGHT_POWER_PLANT_MACHOKE_4
	goto EventScript_RemoveStaticMon
	end

PowerPlant_EventScript_Electrode1::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 45
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerPlant_EventScript_FoughtElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_FoughtElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_FoughtElectrode1
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1
	release
	end

PowerPlant_EventScript_FoughtElectrode1::
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_1
	goto EventScript_RemoveStaticMon
	end

PowerPlant_EventScript_Electrode2::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 45
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerPlant_EventScript_FoughtElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_FoughtElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_FoughtElectrode2
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2
	release
	end

PowerPlant_EventScript_FoughtElectrode2::
	setflag FLAG_FOUGHT_POWER_PLANT_ELECTRODE_2
	goto EventScript_RemoveStaticMon
	end
