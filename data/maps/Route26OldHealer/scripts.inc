Route26OldHealer_MapScripts::
	.byte 0

Route26_EventScript_HealingWoman::
	lock
	faceplayer
	msgbox Route26_Text_HealingWoman
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox Route26_Text_AfterHeal
	release
	end
	
Route26_Text_HealingWoman::
	.string "Did you think you were lucky to find\n"
	.string "a place to rest right where you\l"
	.string "needed it?\p"
	.string "Don't be reserved!\n"
	.string "I look forward to people's smiles.\p"
	.string "Let your POKéMON rest here!$"

Route26_Text_AfterHeal::
	.string "There!\n"
	.string "Your POKéMON are looking good!\p"
	.string "Keep at it!$"