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
    .string "PROFESSOR ELM's LAB$"