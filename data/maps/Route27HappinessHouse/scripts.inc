Route27HappinessHouse_MapScripts::
	.byte 0

Route27HappinessHouse_EventScript_Woman::
	lock
	faceplayer
	msgbox Route27HappinessHouse_Text_Woman, MSGBOX_NPC
	release
	end

Route27HappinessHouse_Text_Woman::
	.string "Where are you off to with POKéMON?\p"
	.string "NEWBARK TOWN?\p"
	.string "It is a quaint little village\n"
	.string "with little to it.\p"
	.string "But I've heard that PROFESSOR ELM,\n"
	.string "who lives there, has made a\p"
	.string "groundbreaking discovery.$"