.set LOCALID_RAIKOU, 1

SevenIsland_TanobyRuins_ScufibChamber_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TanobyRuins_ScufibChamber_OnTransition
	.byte 0

SevenIsland_TanobyRuins_ScufibChamber_OnTransition::
	call EventScript_TryDarkenRuins
	end

SevenIsland_TanobyRuins_ScufibChamber_EventScript_Raikou::
	lockall
	showmonpic SPECIES_RAIKOU, 10, 3
	playmoncry SPECIES_RAIKOU, 2
	waitmoncry
	delay 20
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_RAIKOU
	special SetSeenMon
	faceplayer
	fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    msgbox SevenIsland_TanobyRuins_ScufibChamber_Text_RaikouFled
	closemessage
	removeflag FLAG_HIDE_RAIKOU_ROAM
	releaseall
	end
	
SevenIsland_TanobyRuins_ScufibChamber_Text_RaikouFled::
	.string "RAIKOU has fled the ruins!$"