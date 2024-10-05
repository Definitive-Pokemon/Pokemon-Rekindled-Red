Route103_AlteringCave_MapScripts::
	.byte 0

Eventscript_AlterBack::
	fadescreen FADE_TO_WHITE
	playse SE_THUNDER
	fadescreen FADE_FROM_WHITE
	special ShakeScreen
	waitse
	delay 60
	lockall
	warp MAP_SIX_ISLAND_ALTERING_CAVE, 26, 12
	releaseall
	end