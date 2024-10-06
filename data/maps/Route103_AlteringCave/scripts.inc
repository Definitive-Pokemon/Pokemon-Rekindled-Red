Route103_AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route103_AlteringCave_EventScript_OnLoad
	.byte 0

Route103_AlteringCave_EventScript_OnLoad::
	goto_if_set FLAG_CAUGHT_JIRACHI, Route103_AlteringCave_EventScript_AlteringDoorClosed
	end
	
Route103_AlteringCave_EventScript_AlteringDoorClosed::
	setmetatile 17, 23, METATILE_Cave_Wall, 1
	setmetatile 18, 23, METATILE_Cave_Wall, 1
	setmetatile 19, 23, METATILE_Cave_Wall, 1
	setmetatile 18, 22, METATILE_Cave_Floor, 0
	return
