KyogreDen_MapScripts::
	.byte 0

KyogreDen_BrailleMessage::
	lockall
	setvar VAR_0x8005, 130
	braillemessage_wait Braille_Text_Primordial
	braillemessage_wait Braille_Text_Altar
	braillemessage Braille_Text_Ahead
	waitbuttonpress
	releaseall
	end