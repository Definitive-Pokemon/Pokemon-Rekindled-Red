.set LOCALID_SUICUNE, 1

SevenIsland_TanobyRuins_DilfordChamber_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TanobyRuins_DilfordChamber_OnTransition
	.byte 0

SevenIsland_TanobyRuins_DilfordChamber_OnTransition::
	call EventScript_TryDarkenRuins
	end

SevenIsland_TanobyRuins_DilfordChamber_EventScript_Suicune::
	lockall
	showmonpic SPECIES_SUICUNE, 10, 3
	playmoncry SPECIES_SUICUNE, 2
	waitmoncry
	delay 20
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_SUICUNE
	special SetSeenMon
	faceplayer
	fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    msgbox SevenIsland_TanobyRuins_DilfordChamber_Text_SuicuneFled
	closemessage
	removeflag FLAG_HIDE_SUICUNE_ROAM
	releaseall
	end
	
SevenIsland_TanobyRuins_DilfordChamber_Text_SuicuneFled::
	.string "SUICUNE has fled the ruins!$"