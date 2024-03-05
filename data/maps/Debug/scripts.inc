Debug_MapScripts::
	.byte 0

Debug_GiveFormMon::
	lock
	givemon SPECIES_FOSSILIZED_KABUTOPS , 5, ITEM_NONE
	release
	end

Debug_Battle::
	lock
	setwildbattle SPECIES_FOSSILIZED_KABUTOPS, 3, ITEM_NONE
	delay 40
	dowildbattle
	release
	end

Debug_GiveNormalMon::
	lock
	givemon SPECIES_KABUTOPS, 5, ITEM_NONE
	release
	end
