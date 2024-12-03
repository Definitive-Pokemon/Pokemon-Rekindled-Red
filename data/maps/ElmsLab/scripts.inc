.equ LOCALID_ELM,    1

ElmsLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ElmsLab_EventScript_OnTransition
	.byte 0

ElmsLab_EventScript_OnTransition::
    setrespawn SPAWN_NEW_BARK_TOWN
	end

ElmsLab_EventScript_Elm::
	lock
	faceplayer
	checkitem ITEM_SHINY_RADAR, 1
	goto_if_eq VAR_RESULT, TRUE, ElmsLab_EventScript_Nothing
	msgbox ElmsLab_Text_ElmShinyRadar
	closemessage
	giveitem_msg ElmsLab_Text_ReceivedShinyRadar, ITEM_SHINY_RADAR, 1
	msgbox ElmsLab_Text_ElmAfter
	release
	end

ElmsLab_Text_ElmShinyRadar::
	.string "Heya!\n"
	.string "You must be {PLAYER}!\p"
	.string "PROFESSOR OAK has told me all\n"
	.string "about you!\p"
	.string "Say, how about helping me out\n"
	.string "with my research?\p"
	.string "All you need is this little radar.$"

ElmsLab_Text_ReceivedShinyRadar::
	.string "{PLAYER} received the SHINY RADAR\n"
	.string "from PROFESSOR ELM!$"

ElmsLab_Text_ElmAfter::
	.string "This SHINY RADAR will help you\n"
	.string "with finding SHINY POKéMON.\p"
	.string "SHINY POKéMON are strange variations of\n"
	.string "familiar species, sporting a unique\p"
	.string "color scheme.\p"
	.string "I hung up a note all about it\n"
	.string "right behind me!\p"
	.string "You would help me tremendously\n"
	.string "simply by finding SHINY POKéMON\p"
	.string "of all sorts.$"

ElmsLab_EventScript_Nothing::
	msgbox ElmsLab_Text_ElmHow MSGBOX_NPC
	release
	end

ElmsLab_Text_ElmHow::
	.string "Hi, {PLAYER}!\n"
	.string "How is it going?\p"
	.string "Have you been catching some\n"
	.string "SHINY POKéMON?\p"
	.string "Even with the SHINY RADAR, it might\n"
	.string "still take a long time before you\p"
	.string "manage to encounter one.\p"
	.string "I'd encourage you to not give up,\n"
	.string "but as a CHAMPION, you must have\p"
	.string "a full schedule, am I right?$"

ElmsLab_EventScript_Heal::
	msgbox ElmsLab_Text_YouShouldTakeQuickRest MSGBOX_NPC
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox ElmsLab_Text_LookingGreatTakeCare MSGBOX_NPC
	release
	end

ElmsLab_EventScript_AideFullRestores::
	lock
	faceplayer
	msgbox ElmsLab_Text_AideFullRestores, MSGBOX_NPC
	release
	end

ElmsLab_Text_AideFullRestores::
	.string "You're not from here,\n"
	.string "are you?\p"
	.string "Your POKéMON seem very powerful!$"

ElmsLab_Text_YouShouldTakeQuickRest::
	.string "{PLAYER} used the machine\n"
	.string "to heal his POKéMON.$"

ElmsLab_Text_LookingGreatTakeCare::
	.string "{PLAYER}'s POKéMON are\n"
	.string "restored to full health.$"

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
	.string "were born this way or not.\p"
	.string "In fact, we know very little about\n"
	.string "this mysterious phenomenon.\p"
	.string "However, I have created a device\n"
	.string "that attracts SHINY POKéMON.\p"
	.string "These encounters are very rare still,\n"
	.string "but it should increase the odds.$"

ElmsLab_Text_Notice2::
	.string "Regarding EGGs\p"
	.string "Though the KANTO region does not\n"
	.string "know about this phenomenon,\p"
	.string "in other regions, POKéMON are known\n"
	.string "to lay EGGs when paired together.\p"
	.string "Such an EGG will hatch into a\n"
	.string "newborn POKéMON.\p"
	.string "Further research pending.$"
	