PokeCenter_MapScripts::
	.byte 0

PokeCenter_EventScript_NoHope::
	lock
	textcolor 2
	msgbox PokeCenter_Text_NoHope
	waitmessage
	setvar VAR_NOHOPE, 1
	release
	end
	
PokeCenter_EventScript_Pointless::
	lock
	textcolor 2
	msgbox PokeCenter_Text_Pointless
	waitmessage
	setvar VAR_POINTLESS, 1
	release
	end
	
PokeCenter_EventScript_BeyondReach::
	lock
	textcolor 2
	msgbox PokeCenter_Text_BeyondReach
	waitmessage
	setvar VAR_BEYONDREACH, 1
	release
	end
	
PokeCenter_EventScript_DontGiveUp::
	lock
	textcolor 2
	msgbox PokeCenter_Text_DontGiveUp
	waitmessage
	setvar VAR_DONTGIVEUP, 1
	release
	end
	
PokeCenter_EventScript_KeepTrying::
	lock
	textcolor 2
	msgbox PokeCenter_Text_KeepTrying
	waitmessage
	setvar VAR_KEEPTRYING, 1
	release
	end
	
PokeCenter_EventScript_Determination::
	lock
	textcolor 2
	msgbox PokeCenter_Text_Determination
	waitmessage
	setvar VAR_DETERMINATION, 1
	release
	end
	
PokeCenter_EventScript_AlmostThere::
	lock
	textcolor 2
	msgbox PokeCenter_Text_AlmostThere
	waitmessage
	setvar VAR_ALMOSTTHERE, 1
	release
	end
	
PokeCenter_EventScript_TheEnd::
	lock
	textcolor 2
	msgbox PokeCenter_Text_TheEnd
	waitmessage
	setflag FLAG_HORROR_ABSOLUTE
	setvar VAR_LOCK_FLASH, 1
	clearflag FLAG_HIDE_HORROR_NPC
	setvar VAR_HONEY1, 0
	setvar VAR_HONEY2, 0
	warp MAP_MONITORING_STATION_SHORTCUT, 255, 3, 3
	delay 50
	release
	end
	
PokeCenter_EventScript_Closed::
	lockall
	msgbox PokeCenter_Text_Closed, MSGBOX_SIGN
	releaseall
	end
	
PokeCenter_EventScript_Adventure::
	msgbox PokeCenter_Text_Adventure, MSGBOX_SIGN
	end