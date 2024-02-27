MonitoringStation_Lair_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MonitoringStation_Lair_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MonitoringStation_Lair_OnResume
	.byte 0

MonitoringStation_Lair_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, MonitoringStation_Lair_EventScript_TryRemoveKabutops
	end

MonitoringStation_Lair_EventScript_TryRemoveKabutops::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return

MonitoringStation_Lair_OnTransition::
	call_if_set FLAG_FOUGHT_KABUTOPS, MonitoringStation_Lair_EventScript_HideKabutops
	call_if_unset FLAG_FOUGHT_KABUTOPS, MonitoringStation_Lair_EventScript_TryShowKabutops
	end

MonitoringStation_Lair_EventScript_TryShowKabutops::
	goto_if_set FLAG_KABUTOPS_FLED, EventScript_Return
	clearflag FLAG_HIDE_KABUTOPS
	return

MonitoringStation_Lair_EventScript_HideKabutops::
	setflag FLAG_HIDE_KABUTOPS
	return

MonitoringStation_Lair_EventScript_Kabutops::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_FOSSILIZED_KABUTOPS, 70, ITEM_NONE
	waitse
	playmoncry SPECIES_KABUTOPS, 2
	message MonitoringStation_Lair_Text_Kabutops
	waitmessage
	waitmoncry
	delay 10
	waitbuttonpress
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MonitoringStation_Lair_EventScript_DefeatedKabutops
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq MonitoringStation_Lair_EventScript_RanFromKabutops
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq MonitoringStation_Lair_EventScript_RanFromKabutops
	setflag FLAG_FOUGHT_KABUTOPS
	release
	end

MonitoringStation_Lair_EventScript_DefeatedKabutops::
	setflag FLAG_KABUTOPS_FLED
	setvar VAR_0x8004, SPECIES_KABUTOPS
	goto MonitoringStation_Lair_EventScript_KabutopsFled
	end

MonitoringStation_Lair_EventScript_RanFromKabutops::
	setvar VAR_0x8004, SPECIES_KABUTOPS
	goto MonitoringStation_Lair_EventScript_KabutopsFled
	end
	
MonitoringStation_Lair_EventScript_KabutopsFled::
    fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    msgbox MonitoringStation_Lair_Text_KabutopsFled
    release
    end
	
MonitoringStation_Lair_EventScript_Braille1::
	lockall
	setvar VAR_0x8005, 130
	braillemessage_wait Braille_Text_Three
	braillemessage_wait Braille_Text_Caverns
	braillemessage_wait Braille_Text_Sealed
	braillemessage_wait Braille_Text_Away
	braillemessage Braille_Text_Pokemon
	waitbuttonpress
	releaseall
	end
	
MonitoringStation_Lair_EventScript_Braille2::
	lockall
	setvar VAR_0x8005, 130
	braillemessage_wait Braille_Text_ForWe
	braillemessage Braille_Text_Feared
	waitbuttonpress
	releaseall
	end
	
MonitoringStation_Lair_EventScript_Braille3::
	lockall
	setvar VAR_0x8005, 130
	braillemessage_wait Braille_Text_Two
	braillemessage_wait Braille_Text_Protectors
	braillemessage_wait Braille_Text_Watch
	braillemessage_wait Braille_Text_Them
	braillemessage Braille_Text_Peace
	waitbuttonpress
	releaseall
	end
	
MonitoringStation_Lair_EventScript_Braille4::
	lockall
	setvar VAR_0x8005, 130
	braillemessage_wait Braille_Text_You
	braillemessage_wait Braille_Text_Disrupted
	braillemessage_wait Braille_Text_ThePeace
	braillemessage_wait Braille_Text_Bested
	braillemessage_wait Braille_Text_OneOf
	braillemessage Braille_Text_Guardians
	waitbuttonpress
	releaseall
	end
	
MonitoringStation_Lair_EventScript_Braille5::
	lockall
	setvar VAR_0x8005, 130
	braillemessage_wait Braille_Text_Door
	braillemessage_wait Braille_Text_Opens
	braillemessage_wait Braille_Text_Eternal
	braillemessage_wait Braille_Text_Pokemon2
	braillemessage Braille_Text_Waits
	waitbuttonpress
	releaseall
	end
	
MonitoringStation_Lair_EventScript_FinalBraille::
	lockall
	setvar VAR_0x8005, 130
	braillemessage_wait Braille_Text_Door
	braillemessage_wait Braille_Text_Opens
	braillemessage_wait Braille_Text_Eternal
	braillemessage_wait Braille_Text_Pokemon2
	braillemessage Braille_Text_Waits
	waitbuttonpress
	call_if_unset FLAG_REGISTEEL_DOOR_OPENED, MonitoringStation_Lair_EventScript_Registeel_Open
	releaseall
	end
	
MonitoringStation_Lair_EventScript_Registeel_Open::
	fadeoutbgm 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 10
	setvar VAR_0x8007, 3
	special ShakeScreen
	delay 60
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 12
	setvar VAR_0x8007, 2
	special ShakeScreen
	delay 60
	playse SE_LAVARIDGE_FALL_WARP
	waitse
	playse SE_DOOR
	waitse
	msgbox MtEmberRegirockPuzzle_Text_SomethingHappened, MSGBOX_DEFAULT
	closemessage
	fadeinbgm 0
	setflag FLAG_REGISTEEL_DOOR_OPENED
	return