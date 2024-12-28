NavelRock_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_1F_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, NavelRock_1F_OnLoad
	.byte 0

NavelRock_1F_OnTransition::
	end

NavelRock_1F_OnLoad::
	call_if_eq VAR_BLOCK, 2, NavelRock_1F_Block
	end

NavelRock_1F_EventScript_CloseEntrance::
	lockall
	textcolor 0
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
	delay 60
	msgbox NavelRock_1F_Text_Huh
	setvar VAR_BLOCK, 2
	releaseall
	end

NavelRock_1F_Block::
	setmetatile 8, 23, METATILE_NavelRock_Floor, 0
	return

NavelRock_1F_Text_Haha::
	.string "HAHAHAHA!\n"
	.string "Idiot.\p"
	.string "You can have LUGIA…\n"
	.string "and rot within NAVEL ROCK!\p"
	.string "Goodbye, TRAINER!$"

NavelRock_1F_Text_Huh::
	.string "What…?!\p"
	.string "My WARPING DEVICE!\n"
	.string "It's malfunctioning!$"