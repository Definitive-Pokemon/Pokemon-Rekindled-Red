.set LOCALID_ENTEI, 1

SevenIsland_TanobyRuins_WeepthChamber_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TanobyRuins_WeepthChamber_OnTransition
	.byte 0

SevenIsland_TanobyRuins_WeepthChamber_OnTransition::
	call EventScript_TryDarkenRuins
	end
	
SevenIsland_TanobyRuins_WeepthChamber_EventScript_Entei::
	lockall
	showmonpic SPECIES_ENTEI, 10, 3
	playmoncry SPECIES_ENTEI, 2
	waitmoncry
	delay 20
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_ENTEI
	special SetSeenMon
	faceplayer
	fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    msgbox SevenIsland_TanobyRuins_WeepthChamber_Text_EnteiFled
	closemessage
	removeflag FLAG_HIDE_ENTEI_ROAM
	releaseall
	end
	
SevenIsland_TanobyRuins_WeepthChamber_Text_EnteiFled::
	.string "ENTEI has fled the ruins!$"