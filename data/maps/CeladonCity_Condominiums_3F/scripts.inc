CeladonCity_Condominiums_3F_MapScripts::
	.byte 0

CeladonCity_Condominiums_3F_EventScript_Programmer::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheProgrammer, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_GraphicArtist::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Writer::
	msgbox CeladonCity_Condominiums_3F_Text_IWroteTheStory, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Designer::
	lock
	faceplayer
	specialvar VAR_RESULT, HasAllKantoMons
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_Condominiums_3F_EventScript_CompletedPokedex
	msgbox CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex
	release
	end

CeladonCity_Condominiums_3F_EventScript_CompletedPokedex::
	goto CeladonCity_Condominiums_3F_EventScript_ShowDiploma
	end

CeladonCity_Condominiums_3F_EventScript_ShowDiploma::
	message CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations
	waitmessage
	delay 60
	goto_if_questlog EventScript_ReleaseEnd
	special ShowDiploma
	waitstate
	release
	end

CeladonCity_Condominiums_3F_EventScript_GiveMysticTicket::
	goto_if_unset FLAG_SYS_RECEIVED_EXTENDED_DEX, CeladonCity_Condominiums_3F_EventScript_CantGiveMysticTicket
	textcolor 0
	msgbox CeladonCity_Condominiums_3F_Text_GiveMysticTicket
	textcolor 3
	giveitem ITEM_MYSTIC_TICKET, 1
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	textcolor 0
	msgbox CeladonCity_Condominiums_3F_Text_ExplainMysticTicket
	release
	end

CeladonCity_Condominiums_3F_EventScript_CantGiveMysticTicket::
	textcolor 0
	msgbox CeladonCity_Condominiums_3F_Text_CantGiveMysticTicket
	release
	end

CeladonCity_Condominiums_3F_Text_CantGiveMysticTicket:
	.string "I have a gift for filling up your\n"
	.string "POKéDEX, but it's probably best to\l"
	.string "wait until it's been upgraded first.\p"
	.string "Come see me when your POKéDEX\n"
	.string "can handle registering more POKéMON.$"

CeladonCity_Condominiums_3F_Text_GiveMysticTicket:
	.string "Here's a little gift for filling up\n"
	.string "your POKéDEX.$"

CeladonCity_Condominiums_3F_Text_ExplainMysticTicket:
	.string "Bring that ticket to the docks in\n"
	.string "VERMILION CITY.\p"
	.string "With it, you can go to NAVEL ROCK\n"
	.string "between FOUR and FIVE ISLAND.\p"
	.string "Since you like catching POKéMON,\n"
	.string "you'll want to see what's there.\p"
	.string "Good luck!$"

CeladonCity_Condominiums_3F_EventScript_DevelopmentRoomSign::
	msgbox CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer1::
	msgbox CeladonCity_Condominiums_3F_Text_ItsTheGameProgram, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer2::
	msgbox CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer3::
	msgbox CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_TitleGiver::
	lock
	faceplayer
	callnative CheckHasAnyMasterTitle
	compare VAR_RESULT, FALSE
	goto_if_eq CeladonCity_Condominiums_3F_EventScript_TitleGiver_NoTitles
	callnative CheckCurrentMasterTitle
	compare VAR_RESULT, 0
	call_if_eq CeladonCity_Condominiums_3F_EventScript_TitleGiver_NoTitleSelected
	compare VAR_RESULT, 0
	call_if_ne CeladonCity_Condominiums_3F_EventScript_TitleGiver_TitleSelected
	setvar VAR_0x8004, LISTMENU_MASTER_TRAINER_TITLES
	special ListMenu
	waitstate
	switch VAR_RESULT
	case 0, CeladonCity_Condominiums_3F_EventScript_TitleGiver_ChoseNoTitle
	case 152, CeladonCity_Condominiums_3F_EventScript_TitleGiver_ChoseGrandMaster
	case 153, CeladonCity_Condominiums_3F_EventScript_TitleGiver_PressedB
	// chose an actual mon
	callnative SetCurrentMasterTitle
	bufferspeciesname STR_VAR_2, VAR_RESULT
	msgbox CeladonCity_Condominiums_3F_Text_TitleGiver_ChoseMonMaster, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_TitleGiver_NoTitles:
	msgbox CeladonCity_Condominiums_3F_Text_TitleGiver_NoTitles, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_TitleGiver_NoTitleSelected:
	msgbox CeladonCity_Condominiums_3F_Text_TitleGiver_WelcomeNoTitle
	return

CeladonCity_Condominiums_3F_EventScript_TitleGiver_TitleSelected:
	compare VAR_RESULT, 152
	call_if_eq CeladonCity_Condominiums_3F_EventScript_TitleGiver_BufferGrand
	compare VAR_RESULT, 152
	call_if_ne CeladonCity_Condominiums_3F_EventScript_TitleGiver_BufferSpecies
	msgbox CeladonCity_Condominiums_3F_Text_TitleGiver_WelcomeTitle
	return

CeladonCity_Condominiums_3F_EventScript_TitleGiver_BufferGrand:
	bufferstring 1, CeladonCity_Condominiums_3F_EventScript_TitleGiver_Grand
	return

CeladonCity_Condominiums_3F_EventScript_TitleGiver_BufferSpecies:
	bufferspeciesname STR_VAR_2, VAR_RESULT
	return

CeladonCity_Condominiums_3F_EventScript_TitleGiver_ChoseNoTitle:
	callnative SetCurrentMasterTitle
	msgbox CeladonCity_Condominiums_3F_Text_TitleGiver_ChoseNoTitles, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_TitleGiver_ChoseGrandMaster:
	callnative SetCurrentMasterTitle
	msgbox CeladonCity_Condominiums_3F_Text_TitleGiver_ChoseGrandMaster, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_TitleGiver_PressedB:
	msgbox CeladonCity_Condominiums_3F_Text_TitleGiver_PressedB, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_Text_TitleGiver_NoTitles:
	.string "Welcome!\p"
	.string "You probably don't know what I'm\n"
	.string "talking about, but come back once\l"
	.string "you have earned a title!$"

CeladonCity_Condominiums_3F_Text_TitleGiver_WelcomeNoTitle:
	.string "Welcome!\p"
	.string "Or would you like me to call you\n"
	.string "by a title?$"

CeladonCity_Condominiums_3F_Text_TitleGiver_WelcomeTitle:
	.string "Welcome, {STR_VAR_2} MASTER!\p"
	.string "Or would you like me to call you\n"
	.string "by a different title?$"

CeladonCity_Condominiums_3F_Text_TitleGiver_ChoseNoTitles:
	.string "Oh, you don't want to have a title?\n"
	.string "I guess you really don't need one!$"

CeladonCity_Condominiums_3F_Text_TitleGiver_ChoseGrandMaster:
	.string "Yo, GRAND MASTER!\n"
	.string "A fitting title for you indeed.$"

CeladonCity_Condominiums_3F_Text_TitleGiver_PressedB:
	.string "Oh, you're not going to change\n"
	.string "your title?\p"
	.string "I guess you really like the one\n"
	.string "you have now!$"

CeladonCity_Condominiums_3F_Text_TitleGiver_ChoseMonMaster:
	.string "Yo, {STR_VAR_2} MASTER!\n"
	.string "A fitting title for you indeed.$"

CeladonCity_Condominiums_3F_EventScript_TitleGiver_Grand:
	.string "GRAND$"

