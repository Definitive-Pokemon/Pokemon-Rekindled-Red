ElmsLab_MapScripts::
	.byte 0

ElmsLab_EventScript_AideFullRestores::
	lock
	faceplayer
	compare VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 1000
	goto_if_lt ElmsLab_EventScript_ComeBackLater
	msgbox ElmsLab_Text_AideFullRestores, MSGBOX_NPC
	closemessage
	giveitem_msg PalletTown_ElmsLab_Text_ReceivedFullRestores, ITEM_FULL_RESTORE, 5
	release
	end

ElmsLab_Text_AideFullRestores::
	.string "Hello, you're not from here,\n"
	.string "are you?\p"
	.string "Your POKéMON seem very powerful!\n"
	.string "I think you could use these.\p"

PalletTown_ElmsLab_Text_ReceivedFullRestores::
	.string "{PLAYER} received five FULL RESTORES\n"
	.string "from ELM's AIDE!$"

ElmsLab_EventScript_ComeBackLater::
	msgbox ElmsLab_Text_ComeBackLater, MSGBOX_NPC
	release
	end

ElmsLab_Text_ComeBackLater::
	.string "I don't have any FULL RESTORES left\n"
	.string "at this point.\p"
	.string "Please come back another time.\n"
	.string "The LAB will have more supplies then.$"

ElmsLab_EventScript_Heal::
	msgbox ElmsLab_Text_YouShouldTakeQuickRest MSGBOX_NPC
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox ElmsLab_Text_LookingGreatTakeCare MSGBOX_NPC
	release
	end

ElmsLab_Text_YouShouldTakeQuickRest::
	.string "{PLAYER} used the machine\n"
	.string "to heal his POKéMON.$"

ElmsLab_Text_LookingGreatTakeCare::
	.string "{PLAYER}'s POKéMON are\n"
	.string "fully healed.$"

ElmsLab_EventScript_Notice1::
	msgbox ElmsLab_Text_Notice1, MSGBOX_SIGN
	end

ElmsLab_EventScript_Notice2::
	msgbox ElmsLab_Text_Notice2, MSGBOX_SIGN
	end

ElmsLab_Text_Notice1::
	.string "Regarding SHINY POKéMON\p"
	.string "It has occurred to me that\n"
	.string "very, very rarely, wild POKéMON\p"
	.string "appear to have a completely\n"
	.string "different color than usual.\p"
	.string "It is unknown whether such POKéMON\n"
	.string "were born with this condition or not.\p"
	.string "In fact, we know next to nothing about\n"
	.string "this mysterious phenomenon.\p"
	.string "However, I have created a device that\n"
	.string "attracts these specific POKéMON.\p"
	.string "These encounters are very rare still,\n"
	.string "but it should increase the odds.$"

ElmsLab_Text_Notice2::
	.string "Regarding \p"
	.string "$"