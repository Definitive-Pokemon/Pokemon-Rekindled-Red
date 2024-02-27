CinnabarIsland_BerryFarm_MapScripts::
	.byte 0
	
CinnabarIsland_BerryFarm_EventScript_Woman::
	msgbox CinnabarIsland_BerryFarm_Text_Woman, MSGBOX_NPC
	end	

CinnabarIsland_BerryFarm_EventScript_Gentleman::
	lock
	faceplayer
	checkitem ITEM_LUM_BERRY, 1
	compare VAR_RESULT, TRUE
	goto_if_set FLAG_GOT_LUM_BERRY, CinnabarIsland_BerryFarm_EventScript_Hello
	msgbox CinnabarIsland_BerryFarm_Text_Farm, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq CinnabarIsland_BerryFarm_EventScript_FarmExplain
	msgbox CinnabarIsland_BerryFarm_Text_Okay
	release
	end

CinnabarIsland_BerryFarm_EventScript_FarmExplain::
	msgbox CinnabarIsland_BerryFarm_Text_FarmExplain
	giveitem_msg CinnabarIsland_BerryFarm_Text_ObtainedLumBerry, ITEM_LUM_BERRY
	msgbox CinnabarIsland_BerryFarm_Text_Thanks
	setflag FLAG_GOT_LUM_BERRY
	release
	end
	
CinnabarIsland_BerryFarm_EventScript_Hello::
	msgbox CinnabarIsland_BerryFarm_Text_Hello
	release
	end

CinnabarIsland_BerryFarm_EventScript_Man::
	lock
	faceplayer
	goto_if_unset FLAG_GET_JAR, CinnabarIsland_BerryFarm_EventScript_ManGiveJar
	msgbox CinnabarIsland_BerryFarm_Text_Farmer
	release
	end

CinnabarIsland_BerryFarm_EventScript_ManGiveJar::
	msgbox CinnabarIsland_BerryFarm_Text_GiveJar
	waitmessage
	giveitem_msg CinnabarIsland_BerryFarm_Text_ObtainedBerryPowder, ITEM_POWDER_JAR
	setflag FLAG_GET_JAR
	msgbox CinnabarIsland_BerryFarm_Text_Enjoy
	release
	end