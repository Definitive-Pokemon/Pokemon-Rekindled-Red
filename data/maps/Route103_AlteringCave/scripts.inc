Route103_AlteringCave_MapScripts::
	.byte 0

Eventscript_AlterBack::
	lock
	fadescreen FADE_TO_WHITE
	playse SE_ORB
	waitse
	fadescreen FADE_FROM_WHITE
	delay 60
	warp MAP_SIX_ISLAND_ALTERING_CAVE, 26, 12
	release
	end