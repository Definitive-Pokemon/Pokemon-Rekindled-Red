Route27_MapScripts::
	.byte 0

Route27_EventScript_RouteSign::
	msgbox Route27_Text_RouteSign, MSGBOX_SIGN
	end

Route27_Text_RouteSign::
    .string "TOHJO FALLS \p"
    .string "The link between\n"
    .string "KANTO and JOHTO$"

Route27_EventScript_Man::
	lock
	faceplayer
	msgbox Route27_Text_Man, MSGBOX_NPC
	release
	end

Route27_Text_Man::
	.string "You're about to take your first step\n"
	.string "into JOHTO!\p"
	.string "JOHTO isn't a part of your TOWN MAP,\n"
	.string "but you will be able to FLY to\p"
	.string "NEW BARK TOWN once you've made\n"
	.string "your visit.$"