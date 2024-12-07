MtSilver_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_OnTransition
	.byte 0

MtSilver_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MT_SILVER
	end

MtSilver_EventScript_Sign::
	msgbox MtSilver_Text_Sign, MSGBOX_SIGN

MtSilver_Text_Sign::
	.string "MT. SILVER$"