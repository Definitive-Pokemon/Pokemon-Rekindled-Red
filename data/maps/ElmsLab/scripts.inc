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
	goto_if_unset FLAG_ELM_NAVEL, ElmsLab_EventScript_Crisis
	specialvar VAR_RESULT, HasAllMons
	goto_if_eq VAR_RESULT, TRUE, ElmsLab_EventScript_CompletedDex
	msgbox ElmsLab_Text_NoProblem, MSGBOX_NPC
	release
	end

ElmsLab_EventScript_Crisis::
	checkitem ITEM_MYSTIC_TICKET, 1
	goto_if_eq VAR_RESULT, TRUE, ElmsLab_EventScript_GoPlayer
	msgbox ElmsLab_Text_Crisis, MSGBOX_NPC
	closemessage
	applymovement LOCALID_ELM, ElmsLab_Movement_Elm
	waitmovement 0
	msgbox ElmsLab_Text_Lugia, MSGBOX_NPC
	closemessage
	giveitem_msg ElmsLab_Text_ReceivedMysticTicket, ITEM_MYSTIC_TICKET, 1
	msgbox ElmsLab_Text_ElmNavel, MSGBOX_NPC
	release
	end

ElmsLab_Text_Crisis::
	.string "Heya!\n"
	.string "You must be {PLAYER}.\p"
	.string "PROF. OAK has already messaged\n"
	.string "me about the state of things.\p"
	.string "You came to the right person.\n"
	.string "I know a handful of things about\l"
	.string "this legendary POKéMON you met.$"

ElmsLab_Movement_Elm::
	delay_16
	delay_16
	walk_in_place_down
	step_end

ElmsLab_Text_Lugia::
	.string "LUGIA is an ancient POKéMON\n"
	.string "that once lived in the center\l"
	.string "of the JOHTO region.\p"
	.string "However, 150 years ago, the tower\n"
	.string "it resided in was mysteriously\l"
	.string "burned down.\p"
	.string "Since then, LUGIA has hid itself\n"
	.string "inside NAVEL ROCK, an island part\l"
	.string "of the SEVII ISLANDS chain.\p"
	.string "LUGIA's psychic powers cause hefty\n"
	.string "storms wherever it appears.\p"
	.string "These storms could be dangerous\n"
	.string "for both JOHTO and KANTO.\p"
	.string "That's why we need to calm down\n"
	.string "LUGIA, and stop MAXIMUS.\p"
	.string "{PLAYER}, only you are strong enough\n"
	.string "to take on LUGIA by yourself.\p"
	.string "I'm giving you this MYSTICTICKET.\p"
	.string "Please show this to the sailor\n"
	.string "at the VERMILION HARBOR.$"

ElmsLab_Text_ReceivedMysticTicket::
	.string "{PLAYER} received the MYSTICTICKET\n"
	.string "from PROF. ELM!$"

ElmsLab_Text_ElmNavel::
	.string "This MYSTICTICKET is used by lead\n"
	.string "experts on LEGENDARY POKéMON\l"
	.string "to get access to NAVEL ROCK.\p"
	.string "Normally, you wouldn't be allowed\n"
	.string "on the island, but this is clearly\l"
	.string "a special case.\p"
	.string "I urge you to stop MAXIMUS\n"
	.string "before he teleports away.\p"
	.string "After that, calm down LUGIA\n"
	.string "and things should be good.$"

ElmsLab_EventScript_GoPlayer::
	msgbox ElmsLab_Text_GoPlayer, MSGBOX_NPC
	release
	end

ElmsLab_Text_GoPlayer::
	.string "Good luck with your task!\n"
	.string "Oh, and use my HEAL MACHINE\p"
	.string "whenever your POKéMON\n"
	.string "need a break!$"

ElmsLab_Text_NoProblem::
	.string "{PLAYER}! There you are!\p"
	.string "Did you manage to put a stop\n"
	.string "to MAXIMUS while calming\l"
	.string "down LUGIA?\p"
	.string "… That's great news!\n"
	.string "I knew we could count on you!\p"
	.string "{PLAYER}, just know that you're\n"
	.string "always welcome at my LAB!\p"
	.string "Maybe you should go out and\n"
	.string "explore JOHTO sometime.\p"
	.string "There are many more adventures\n"
	.string "to be had, here in JOHTO!$"
	
ElmsLab_EventScript_CompletedDex::
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
	.string "PROF. OAK has told me all\n"
	.string "about you!\p"
	.string "Say, how about helping me out\n"
	.string "with my research?\p"
	.string "All you need is this little radar.$"

ElmsLab_Text_ReceivedShinyRadar::
	.string "{PLAYER} received the SHINY RADAR\n"
	.string "from PROF. ELM!$"

ElmsLab_Text_ElmAfter::
	.string "This SHINY RADAR will help you\n"
	.string "with finding SHINY POKéMON.\p"
	.string "SHINY POKéMON are strange variations of\n"
	.string "familiar species, sporting a unique\l"
	.string "color scheme.\p"
	.string "I hung up a note all about it\n"
	.string "right behind me!\p"
	.string "You would help me tremendously\n"
	.string "simply by finding SHINY POKéMON\l"
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
	.string "still take a long time before you\l"
	.string "manage to encounter one.\p"
	.string "I'd encourage you to not give up.\p"
	.string "But as a CHAMPION, you must have\n"
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
	