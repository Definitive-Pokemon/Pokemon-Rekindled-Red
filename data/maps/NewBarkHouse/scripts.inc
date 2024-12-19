NewBarkHouse_MapScripts::
	.byte 0

NewBarkHouse_EventScript_Girl::
	lock
	faceplayer
	msgbox NewBarkHouse_Text_Girl
	release
	end

NewBarkHouse_Text_Girl::
	.string "PIKACHU is an evolved POKéMON.\p"
	.string "…This fact was first discovered\n"
	.string "by PROF. ELM.\p"
	.string "I was amazed by PROF. ELM's\n"
	.string "findings.\p"
	.string "He's so famous for his research on\n"
	.string "POKéMON evolution.\p"
	.string "Sigh…\p"
	.string "I wish I could be a researcher\n"
	.string "like him…$"