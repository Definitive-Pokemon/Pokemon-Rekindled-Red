NewBarkTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_OnTransition
	.byte 0

NewBarkTown_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_NEW_BARK_TOWN
	end

NewBarkTown_EventScript_EthansHouse::
	msgbox NewBarkTown_Text_EthansHouse, MSGBOX_SIGN
	end

NewBarkTown_EventScript_LyrasHouse::
	msgbox NewBarkTown_Text_LyrasHouse, MSGBOX_SIGN
	end

NewBarkTown_EventScript_NewBark::
	msgbox NewBarkTown_Text_NewBark, MSGBOX_SIGN
	end

NewBarkTown_EventScript_ElmsLab::
	msgbox NewBarkTown_Text_ElmsLab, MSGBOX_SIGN
	end

NewBarkTown_Text_EthansHouse::
	.string "ETHAN's house$"

NewBarkTown_Text_LyrasHouse::
	.string "LYRA's house$"

NewBarkTown_Text_NewBark::
    .string "NEW BARK TOWN\n"
    .string "Winds of a New Beginning$"

NewBarkTown_Text_ElmsLab::
    .string "PROF. ELM's LAB$"

NewBarkTown_EventScript_Man::
	lock
	faceplayer
	msgbox NewBarkTown_Text_Man
	release
	end

NewBarkTown_Text_Man::
	.string "Yo, stranger!\p"
	.string "I hear PROF. ELM discovered\n"
	.string "some new type of POKéMON.$"

NewBarkTown_EventScript_Woman::
	lock
	faceplayer
	msgbox NewBarkTown_Text_Woman
	release
	end

NewBarkTown_Text_Woman::
	.string "I like your BAG!\p"
	.string "It looks more modern than any BAG\n"
	.string "we got in JOHTO.$"