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
	message SevenIsland_TanobyRuins_WeepthChamber_Text_EnteiCry
	waitbuttonpress
	delay 20
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_ENTEI
	special SetSeenMon
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ENTEI
	setflag FLAG_HIDE_ENTEI
	@roaming command
	fadescreen FADE_FROM_BLACK
	msgbox SevenIsland_TanobyRuins_WeepthChamber_Text_EnteiGone
	releaseall
	end
	
SevenIsland_TanobyRuins_WeepthChamber_Text_EnteiCry::
	.string "Borlrorl!$"
	
SevenIsland_TanobyRuins_WeepthChamber_Text_EnteiGone::
	.string "ENTEI has ran off to roam\n"
	.string "the KANTO region.$"