LyrasHouse_MapScripts::
	.byte 0

LyrasHouse_EventScript_Dad::
	lock
	faceplayer
	msgbox LyrasHouse_Text_Dad
	release
	end

LyrasHouse_Text_Dad::
	.string "My daughter LYRA is incredibly\n"
	.string "fond of POKéMON.\p"
	.string "She certainly will become a TRAINER\n"
	.string "when she grows up.\p"
	.string "I'm very proud of her.\p"
	.string "I can't say the same about her\n"
	.string "best friend, ETHAN.\p"
	.string "Everyone in town speaks about\n"
	.string "his troublemaking.$"