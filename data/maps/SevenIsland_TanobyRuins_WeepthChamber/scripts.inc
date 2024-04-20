.set LOCALID_ENTEI, 1

SevenIsland_TanobyRuins_WeepthChamber_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TanobyRuins_WeepthChamber_OnTransition
	.byte 0

SevenIsland_TanobyRuins_WeepthChamber_OnTransition::
	call EventScript_TryDarkenRuins
	end
	
SevenIsland_TanobyRuins_WeepthChamber_EventScript_Entei::
	lockall
	msgbox SevenIsland_TanobyRuins_WeepthChamber_Text_EnteiCry
	showmonpic SPECIES_ENTEI, 10, 3
	delay 20
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_ENTEI
	special SetSeenMon
	applymovement LOCALID_ENTEI, SevenIsland_TanobyRuins_WeepthChamber_Movement_EnteiGo
	waitmovement 0
	removeobject LOCALID_ENTEI
	setflag FLAG_HIDE_ENTEI
	@roaming command
	releaseall
	end
	
SevenIsland_TanobyRuins_WeepthChamber_Text_EnteiCry::
	.string "Borlrorl!$"

SevenIsland_TanobyRuins_WeepthChamber_Movement_EnteiGo::
	jump_in_place_down
	jump_special_up
	jump_special_up
	jump_special_up
	jump_special_left
	jump_special_left
	jump_special_left
	jump_special_left
	jump_special_left
	jump_special_left
	jump_special_left
	jump_special_down
	jump_special_down
	jump_special_down
	jump_special_left
	jump_special_left
	jump_special_down
	jump_special_down
	jump_special_down
	jump_special_down
	jump_special_down
	jump_special_down
	jump_special_right
	jump_special_right
	jump_special_right
	jump_special_right
	jump_special_right
	jump_special_right
	jump_special_right
	jump_special_right
	jump_special_right
	jump_special_down
	step_end