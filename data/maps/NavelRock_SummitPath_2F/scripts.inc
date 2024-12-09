NavelRock_SummitPath_2F_MapScripts::
	.byte 0

UmbilicalTower_2F_EventScript_Old_Man::
	lock
	checkitem ITEM_RAINBOW_WING, 1
	compare VAR_RESULT, TRUE
	goto_if_lt UmbilicalTower_2F_EventScript_Old_ManHahaha
	msgbox UmbilicalTower_2F_Text_Old_Man_Worthy, MSGBOX_NPC
	release
	end

UmbilicalTower_2F_EventScript_Old_ManHahaha::
	msgbox UmbilicalTower_2F_Text_Old_Man_Hahaha, MSGBOX_NPC
	release
	end

UmbilicalTower_2F_Text_Old_Man_Worthy::
	.string "Th… The RAINBOW WING!\n"
	.string "You are worthy!\p"
	.string "Go ahead and try to reach the\n"
	.string "highest point of this tower!\p"
	.string "Go, and meet with HO-OH!$"

UmbilicalTower_2F_Text_Old_Man_Hahaha::
	.string "WHAHAHAHA!\p"
	.string "You aren't worthy of meeting the\n"
	.string "legendary bringer of light, HO-OH.\p"
	.string "You may attempt to climb this tower,\n"
	.string "but you will be climbing for naught.$"