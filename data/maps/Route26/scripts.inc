Route26_MapScripts::
	.byte 0

Route26_EventScript_RouteSign::
	msgbox Route26_Text_RouteSign, MSGBOX_SIGN
	end

Route26_Text_RouteSign::
    .string "ROUTE 26 \n"
    .string "POKéMON LEAGUE RECEPTION GATE$"

Route26_EventScript_RouteSign2::
	msgbox Route26_Text_RouteSign2, MSGBOX_SIGN
	end

Route26_Text_RouteSign2::
    .string "{UP_ARROW_2} North to ROUTE 22\n"
    .string "{DOWN_ARROW_2} South to ROUTE 27$"