NavelRock_1F_MapScripts::
	.byte 0

NavelRock_1F_EventScript_CloseEntrance::
	lockall
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	delay 30
	setmetatile 8, 23, METATILE_NavelRock_Floor, 0
	msgbox NavelRock_1F_Text_Haha
	closemessage
	releaseall
	end

NavelRock_1F_Text_Haha::
	.string "Haha$"