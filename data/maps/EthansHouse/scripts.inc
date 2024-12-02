EthansHouse_MapScripts::
	.byte 0

EthansHouse_EventScript_Mom::
	lock
	faceplayer
	msgbox EthansHouse_Text_Mom
	release
	end

EthansHouse_Text_Mom::
	.string "My boy can be such a headache.\p"
	.string "He keeps asking for a POKéMON\n"
	.string "of his own.\p"
	.string "He really should learn to behave\n"
	.string "a little first…$"