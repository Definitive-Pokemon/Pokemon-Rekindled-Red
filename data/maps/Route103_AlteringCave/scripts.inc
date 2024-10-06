Route103_AlteringCave_MapScripts::
	.byte 0

Eventscript_AlterBack::
	lock
	playse SE_ORB
	fadescreen FADE_TO_WHITE
	waitse
	fadescreen FADE_FROM_WHITE
	delay 80
	fadescreen FADE_TO_BLACK
	delay 20
	warp MAP_SIX_ISLAND_ALTERING_CAVE, 26, 12
	release
	end