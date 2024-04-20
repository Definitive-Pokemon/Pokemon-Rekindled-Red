Debug_MapScripts::
	.byte 0

Debug_GiveFormMon::
	lock
	givemon SPECIES_REGIGIGAS, 5, ITEM_NONE
	release
	end

Debug_Battle::
	lock
	setwildbattle SPECIES_REGIGIGAS, 3, ITEM_NONE
	delay 40
	dowildbattle
	release
	end

Debug_GiveNormalMon::
	lock
	givemon SPECIES_KABUTOPS, 5, ITEM_NONE
	release
	end

Debug_TestSprite::
	lock
	msgbox Debug_Text1
	release
	end

Debug_Text1::
	.string "Guuuooon!$"

GiveMewtwo::
	lock
	givemon SPECIES_MEWTWO, 100, ITEM_LEFTOVERS
	release
	end
	
GiveLugia::
	lock
	givemon SPECIES_LUGIA, 100, ITEM_LEFTOVERS
	release
	end
	
GiveHoOh::
	lock
	givemon SPECIES_HO_OH, 100, ITEM_LEFTOVERS
	release
	end
	
GiveRayquaza::
	lock
	givemon SPECIES_RAYQUAZA, 100, ITEM_LEFTOVERS
	release
	end
	
GiveKyogre::
	lock
	givemon SPECIES_KYOGRE, 100, ITEM_LEFTOVERS
	release
	end
	
GiveGroudon::
	lock
	givemon SPECIES_GROUDON, 100, ITEM_LEFTOVERS
	release
	end
	
GiveMasterBall::
	lock
	giveitem ITEM_MASTER_BALL, 99
	release
	end
	
GiveLetter::
	lock
	giveitem ITEM_LETTER
	release
	end
	
