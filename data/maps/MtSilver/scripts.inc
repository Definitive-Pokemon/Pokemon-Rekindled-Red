.set LOCALID_SCIENTIST, 3

MtSilver_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtSilver_OnFrame
	.byte 0

MtSilver_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MT_SILVER
	end

MtSilver_OnFrame::
	goto_if_set FLAG_MAXIMUS_SILVER_HIDE, MtSilver_EventScript_Aide
	.2byte 0

MtSilver_EventScript_Sign::
	msgbox MtSilver_Text_Sign, MSGBOX_SIGN

MtSilver_Text_Sign::
	.string "MT. SILVER$"

MtSilver_EventScript_Aide::
	lockall
	delay 30
	applymovement LOCALID_SCIENTIST, MtSilver_Movement_ScientistUp
	waitmovement 0
	delay 10
	textcolor 0
	msgbox MtSilver_Text_Aide, MSGBOX_NPC
	closemessage
	setflag FLAG_HIDE_SILVER_SCIENTIST
	clearflag FLAG_MAXIMUS_SILVER_HIDE
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 4
	waitstate
	releaseall
	end

MtSilver_Movement_ScientistUp::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_up
	step_end

MtSilver_Text_Aide::
	.string "{PLAYER}!\n"
	.string "What are you doing here?\p"
	.string "PROF. OAK noticed a storm cloud\n"
	.string "forming above MT. SILVER, which\p"
	.string "went on to expand and cover all\n"
	.string "of KANTO!\p"
	.string "The PROF sent me here to look\n"
	.string "into what was going on.\p"
	.string "Fortunately, while on my way,\n"
	.string "the cloud disappeared.\p"
	.string "Do you know anything about this\n"
	.string "strange happening, {PLAYER}?\p"
	.string "I see…\p"
	.string "Maybe you should come with me\n"
	.string "to PALLET TOWN.\p"
	.string "PROF. OAK would be very interested\n"
	.string "in hearing what you have to say.$"