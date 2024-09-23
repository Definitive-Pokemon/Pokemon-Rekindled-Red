.equ LOCALID_OLD_MAN, 8
.equ LOCALID_LAPRAS, 9

SixIsland_OutcastIsland_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SixIsland_OutcastIsland_OnFrame
	.byte 0
	
SixIsland_OutcastIsland_OnFrame::
	goto_if_set FLAG_WORLD_MAP_SIX_ISLAND_ALTERING_CAVE, SixIsland_OutcastIsland_EventScript_MysteryManCheck
	end
	
SixIsland_OutcastIsland_EventScript_MysteryManCheck::
	goto_if_unset FLAG_MYSTERY_MAN_GONE, SixIsland_OutcastIsland_EventScript_MysteryMan
	end
	
SixIsland_OutcastIsland_EventScript_MysteryMan::
	lockall
	setflag FLAG_MYSTERY_MAN_GONE
	applymovement LOCALID_OLD_MAN SixIsland_OutcastIsland_Movement_OldManUp
	waitmovement 0
	msgbox SixIsland_OutcastIsland_Text_OldMan MSGBOX_NPC
	giveitem_msg OutcastIsland_Text_ObtainedSecretFiles, ITEM_SECRET_FILES
	setflag FLAG_RECEIVED_SECRET_FILES
	msgbox SixIsland_OutcastIsland_Text_OldMan2 MSGBOX_NPC
	applymovement LOCALID_OLD_MAN SixIsland_OutcastIsland_Movement_OldManGo
	waitmovement 0
	fadescreen FADE_TO_WHITE
	playse SE_PIN
	waitse
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	waitse
	addobject LOCALID_LAPRAS
	clearflag FLAG_HIDE_LAPRAS_OLD
	fadescreen FADE_FROM_WHITE
	applymovement LOCALID_OLD_MAN SixIsland_OutcastIsland_Movement_OldManSurf
	applymovement LOCALID_LAPRAS SixIsland_OutcastIsland_Movement_LaprasSurf
	waitmovement 0
	removeobject LOCALID_OLD_MAN
	removeobject LOCALID_LAPRAS
	setflag FLAG_HIDE_LAPRAS_OLD
	releaseall
	end

SixIsland_OutcastIsland_EventScript_Rocket::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_46, SixIsland_OutcastIsland_Text_RocketIntro, SixIsland_OutcastIsland_Text_RocketDefeat
	msgbox SixIsland_OutcastIsland_Text_RocketPostBattle, MSGBOX_AUTOCLOSE
	end
	
SixIsland_OutcastIsland_EventScript_Altering::
	lockall
	msgbox SixIsland_OutcastIsland_Text_Altering MSGBOX_SIGN
	releaseall
	end

SixIsland_OutcastIsland_Movement_OldManUp::
	walk_up
	step_end

SixIsland_OutcastIsland_Movement_OldManGo::
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
	
SixIsland_OutcastIsland_Movement_OldManSurf::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
	
SixIsland_OutcastIsland_Movement_LaprasSurf::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
	
SixIsland_OutcastIsland_Text_OldMan::
	.string "You…\p"
	.string "You seem like a well-travelled\n"
	.string "young man.\p"
	.string "You must help me.\p"
	.string "Could you deliver these files to the\n"
	.string "old woman living on TWO ISLAND?$"

SixIsland_OutcastIsland_Text_OldMan2::
	.string "I retrieved these files from the\n"
	.string "ROCKET WAREHOUSE on FIVE ISLAND.\p"
	.string "These documents contain all sorts\n"
	.string "of information regarding the\p"
	.string "whereabouts of both common and\n"
	.string "rare POKéMON.\p"
	.string "The ROCKETS are after me now,\n"
	.string "but it was worth it!\p"
	.string "Many POKéMON are now spared a\n"
	.string "life in captivity…\p"
	.string "Please bring these files to ULTIMA\n"
	.string "and mention my name: DOGA.\p"
	.string "You are my only hope!$"

OutcastIsland_Text_ObtainedSecretFiles::
	.string "{PLAYER} received SECRET FILES\n"
	.string "from the mysterious old man!$"
	
SixIsland_OutcastIsland_Text_Altering::
	.string "Cave altered.$"