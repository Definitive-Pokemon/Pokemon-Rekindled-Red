.set LOCALID_SELPHY, 1
.set LOCALID_SAMUEL, 2
.set LOCALID_AGATHA, 3
.set LOCALID_CELEBI, 4

FiveIsland_LostCave_Room10_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_LostCave_Room10_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FiveIsland_LostCave_Room10_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FiveIsland_LostCave_Room10_OnFrame
	.byte 0

FiveIsland_LostCave_Room10_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, FiveIsland_LostCave_Room10_EventScript_TryRemoveCelebi
	call_if_defeated TRAINER_LADY_SELPHY, FiveIsland_LostCave_Room10_EventScript_StopSelphySceneTrigger
	end
	
FiveIsland_LostCave_Room10_EventScript_TryRemoveCelebi::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return
	
FiveIsland_LostCave_Room10_OnTransition::
	call_if_set FLAG_FOUGHT_CELEBI, FiveIsland_LostCave_Room10_EventScript_HideCelebi
	call_if_unset FLAG_FOUGHT_CELEBI, FiveIsland_LostCave_Room10_EventScript_TryShowCelebi
	end
	
FiveIsland_LostCave_Room10_EventScript_TryShowCelebi::
	goto_if_set FLAG_CELEBI_FLED, EventScript_Return
	clearflag FLAG_HIDE_STORY_CELEBI
	return
	
FiveIsland_LostCave_Room10_EventScript_HideCelebi::
	setflag FLAG_HIDE_STORY_CELEBI
	return
	
FiveIsland_LostCave_Room10_EventScript_Celebi::
	lock
	faceplayer
	setwildbattle SPECIES_CELEBI, 50, ITEM_NONE
	waitse
	playmoncry SPECIES_CELEBI, 2
	message FiveIsland_LostCave_Room10_Text_Celebi
	waitmessage
	waitmoncry
	delay 10
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FiveIsland_LostCave_Room10_EventScript_DefeatedCelebi
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq FiveIsland_LostCave_Room10_EventScript_RanFromCelebi
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq FiveIsland_LostCave_Room10_EventScript_RanFromCelebi
	setflag FLAG_FOUGHT_CELEBI
	release
	end
	
FiveIsland_LostCave_Room10_EventScript_DefeatedCelebi::
	setflag FLAG_CELEBI_FLED
	setvar VAR_0x8004, SPECIES_CELEBI
	goto FiveIsland_LostCave_Room10_EventScript_CelebiFled
	end

FiveIsland_LostCave_Room10_EventScript_RanFromCelebi::
	setvar VAR_0x8004, SPECIES_CELEBI
	goto FiveIsland_LostCave_Room10_EventScript_CelebiFled
	end
	
FiveIsland_LostCave_Room10_EventScript_CelebiFled::
    fadescreenswapbuffers FADE_TO_BLACK
    removeobject VAR_LAST_TALKED
    fadescreenswapbuffers FADE_FROM_BLACK
    msgbox FiveIsland_LostCave_Room10_Text_CelebiFled
	closemessage
	release
	end
	
FiveIsland_LostCave_Room10_Text_CelebiFled::
	.string "The CELEBI suddenly disappeared.$"
	
FiveIsland_LostCave_Entrance_EventScript_CelebiEvent6::
	lockall
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, FiveIsland_LostCave_Room10_Movement_PanToActionFromBottom
	waitmovement 0
	special RemoveCameraObject
	delay 60
	setweather WEATHER_NONE
	doweather
	fadeoutbgm 1
	delay 100
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room10_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room10_Text_Agatha1
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room10_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room10_Text_Oak1
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room10_Movement_Agatha1
	waitmovement 0
	playbgm MUS_POKE_TOWER, 0
	fadeinbgm 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room10_Text_Agatha2
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room10_Movement_Oak2
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room10_Text_Oak2
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room10_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room10_Text_Agatha3
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room10_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room10_Text_Oak3
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room10_Movement_Agatha2
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room10_Text_Agatha4
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room10_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room10_Text_Oak4
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room10_Movement_Oak1
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room10_Text_Oak5
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room10_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room10_Text_Agatha5
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room10_Movement_Oak3
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room10_Text_Oak6
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room10_Movement_Agatha3
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room10_Text_Agatha6
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room10_Movement_Oak3
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room10_Text_Oak7
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room10_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room10_Text_Agatha7
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room10_Movement_Oak3
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room10_Text_Oak8
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room10_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room10_Text_Agatha8
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room10_Movement_Oak3
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room10_Text_Oak9
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room10_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room10_Text_Agatha9
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room10_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room10_Text_Agatha10
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room10_Movement_Oak3
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room10_Text_Oak10
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room10_Movement_Agatha1
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room10_Text_Agatha11
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room10_Movement_Oak3
	waitmovement 0
	textcolor 0
	msgbox FiveIsland_LostCave_Room10_Text_Oak11
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room10_Movement_Agatha4
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room10_Text_Agatha12
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room10_Movement_Agatha5
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room10_Movement_Oak3
	waitmovement 0
	textcolor 2
	msgbox FiveIsland_LostCave_Room10_Text_TakeBall
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room10_Movement_Agatha6
	waitmovement 0
	textcolor 1
	msgbox FiveIsland_LostCave_Room10_Text_Agatha13
	closemessage
	applymovement LOCALID_AGATHA, FiveIsland_LostCave_Room10_Movement_Agatha7
	waitmovement 0
	removeobject LOCALID_AGATHA
	playse SE_EXIT
	textcolor 0
	msgbox FiveIsland_LostCave_Room10_Text_Oak12
	closemessage
	textcolor 1
	msgbox FiveIsland_LostCave_Room10_Text_Agatha14
	closemessage
	applymovement LOCALID_SAMUEL, FiveIsland_LostCave_Room10_Movement_Oak4
	waitmovement 0
	removeobject LOCALID_SAMUEL
	playse SE_EXIT
	fadescreen FADE_TO_WHITE
	setweather WEATHER_SHADE
	doweather
	fadescreen FADE_FROM_WHITE
	playbgm MUS_MT_PYRE, 0
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, FiveIsland_LostCave_Room10_Movement_PanToActionFromTop
	waitmovement 0
	special RemoveCameraObject
	delay 60
	setflag FLAG_HIDE_DUO6
	setvar VAR_CELEBI_EVENT6, 2
	releaseall
	end

FiveIsland_LostCave_Room10_EventScript_StopSelphySceneTrigger::
	setvar VAR_MAP_SCENE_FIVE_ISLAND_LOST_CAVE_ROOM10, 1
	return

FiveIsland_LostCave_Room10_OnFrame::
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_LOST_CAVE_ROOM10, 0, FiveIsland_LostCave_Room10_EventScript_FindSelphyScene
	.2byte 0

FiveIsland_LostCave_Room10_EventScript_FindSelphyScene::
	lockall
	textcolor 1
	applymovement LOCALID_SELPHY, FiveIsland_LostCave_Room10_Movement_SelphyWander
	waitmovement 0
	delay 100
	applymovement LOCALID_SELPHY, FiveIsland_LostCave_Room10_Movement_SelphyApproach
	waitmovement 0
	msgbox FiveIsland_LostCave_Room10_Text_SelphyIntro
	goto_if_questlog FiveIsland_LostCave_Room10_EventScript_SelphyQuestLog
	trainerbattle_no_intro TRAINER_LADY_SELPHY, FiveIsland_LostCave_Room10_Text_SelphyDefeat
	msgbox FiveIsland_LostCave_Room10_Text_MayIAskYouToTakeMeHome
	closemessage
	call FiveIsland_LostCave_Room10_EventScript_SetSelphyFound
	warp MAP_FIVE_ISLAND_RESORT_GORGEOUS, 255, 39, 10
	waitstate
	releaseall
	end

FiveIsland_LostCave_Room10_EventScript_SetSelphyFound::
	setflag FLAG_HIDE_LOST_CAVE_SELPHY
	clearflag FLAG_HIDE_RESORT_GORGEOUS_SELPHY
	setvar VAR_MAP_SCENE_FIVE_ISLAND_LOST_CAVE_ROOM10, 1
	setvar VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1
	return

FiveIsland_LostCave_Room10_EventScript_SelphyQuestLog::
	settrainerflag TRAINER_LADY_SELPHY
	call FiveIsland_LostCave_Room10_EventScript_SetSelphyFound
	releaseall
	end

FiveIsland_LostCave_Room10_Movement_SelphyWander::
	walk_left
	delay_16
	walk_right
	delay_16
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	step_end

FiveIsland_LostCave_Room10_Movement_SelphyApproach::
	walk_down
	walk_down
	step_end

FiveIsland_LostCave_Room10_Text_Agatha1::
	.string "So… where is CELEBI…?$"
	
FiveIsland_LostCave_Room10_Text_Oak1::
	.string "I think… I think that there\n"
	.string "is CELEBI…$"
	
FiveIsland_LostCave_Room10_Text_Agatha2::
	.string "THAT THERE?!\p"
	.string "You're telling me we've braved this\n"
	.string "horrible place for some ugly\p"
	.string "cave troll?!$"

FiveIsland_LostCave_Room10_Text_Oak2::
	.string "Don't insult it, sweet.\p"
	.string "CELEBI is said to be an intelligent\n"
	.string "creature.$"
	
FiveIsland_LostCave_Room10_Text_Agatha3::
	.string "So what if it is intelligent!\p"
	.string "You said CELEBI rivals LUGIA\n"
	.string "and HO-OH!\p"
	.string "This so-called intelligent creature\n"
	.string "won't even harm a RATICATE!$"
	
FiveIsland_LostCave_Room10_Text_Oak3::
	.string "Maybe so, but even then…\p"
	.string "This POKéMON hasn't been spotted in\n"
	.string "recent times.\p"
	.string "If I catch and befriend it, we can\n"
	.string "learn so much about POKéMON…!$"
	
FiveIsland_LostCave_Room10_Text_Agatha4::
	.string "But what about being the strongest?\p"
	.string "This… thing isn't going to secure your\n"
	.string "future as the CHAMPION of KANTO.$"
	
FiveIsland_LostCave_Room10_Text_Oak4::
	.string "But love, being a CHAMPION isn't all\n"
	.string "there is to POKéMON.$"
	
FiveIsland_LostCave_Room10_Text_Oak5::
	.string "The discoveries, the adventure, the\n"
	.string "experiences gained along the way!\p"
	.string "POKéMON isn't just about battling,\n"
	.string "AGATHA.\p"
	.string "Telling people about your latest\n"
	.string "catch, visiting ancient ruins and\p"
	.string "hidden caverns with no idea what to\n"
	.string "expect!\p"
	.string "Investing time into every single\n"
	.string "POKéMON you've caught, or\p"
	.string "obtained from a dear friend.\p"
	.string "Giving each of your partners utmost\n"
	.string "care to make them grow stronger\p"
	.string "and wiser!\p"
	.string "All of that is POKéMON!\n"
	.string "POKéMON is fun!$"
	
FiveIsland_LostCave_Room10_Text_Agatha5::
	.string "And all that in service of battling,\n"
	.string "right?\p"
	.string "How else did you become CHAMPION?\p"
	.string "Did you spelunk caves and invest in\n"
	.string "your team for the sake of 'fun?'$"
	
FiveIsland_LostCave_Room10_Text_Oak6::
	.string "Of course, sweet AGATHA.\p"
	.string "I wouldn't be a CHAMPION if I didn't\n"
	.string "enjoy every step required to be one.$"
	
FiveIsland_LostCave_Room10_Text_Agatha6::
	.string "But you aren't just a CHAMPION.\p"
	.string "You are the strongest CHAMPION in\n"
	.string "recent KANTO history!\p"
	.string "And this stupid creature isn't what we\n"
	.string "have worked so hard for!$"
	
FiveIsland_LostCave_Room10_Text_Oak7::
	.string "Does that really matter, love?\p"
	.string "Isn't the journey more important than\n"
	.string "the destination?\p"
	.string "We've walked this path together, no\n"
	.string "matter what the outcome is.\p"
	.string "To me, that is the best bit of all.\p"
	.string "POKéMON has brought us together.$"
	
FiveIsland_LostCave_Room10_Text_Agatha7::
	.string "But you don't seem to be too\n"
	.string "focused on our future.\p"
	.string "CELEBI clearly isn't gonna be the\n"
	.string "star of your POKéMON team.$"
	
FiveIsland_LostCave_Room10_Text_Oak8::
	.string "Yes, that is probably true.\p"
	.string "But to be honest, I don't care if I\n"
	.string "get to be CHAMPION or not.\p"
	.string "I came this far because I wanted to\n"
	.string "see what the world has to offer.\p"
	.string "There's no need to be CHAMPION just\n"
	.string "for the sake of it.$"
	
FiveIsland_LostCave_Room10_Text_Agatha8::
	.string "So you don't care about the future\n"
	.string "WE are fighting for?$"
	
FiveIsland_LostCave_Room10_Text_Oak9::
	.string "What do you even mean by that,\n"
	.string "love?\p"
	.string "Our future lies with us, not with\n"
	.string "me being the CHAMPION.$"
	
FiveIsland_LostCave_Room10_Text_Agatha9::
	.string "You being CHAMPION IS our future,\n"
	.string "you oaf!\p"
	.string "How are we going to pay our bills\n"
	.string "if you waste your time exploring\p"
	.string "murky caves for no reason at all?$"
	
FiveIsland_LostCave_Room10_Text_Agatha10::
	.string "Don't forget this:\n"
	.string "We OWN KANTO!\p"
	.string "The money, the fame!\p"
	.string "You're prepared to throw all that\n"
	.string "away?$"
	
FiveIsland_LostCave_Room10_Text_Oak10::
	.string "I just don't feel these things are so\n"
	.string "important to me.\p"
	.string "I got you and my POKéMON.$"
	
FiveIsland_LostCave_Room10_Text_Agatha11::
	.string "You always told me to give it my all,\n"
	.string "and now you're just giving up on\p"
	.string "our shared dream!\p"
	.string "To me, that feels like giving up on a\n"
	.string "promising future.\p"
	.string "Throwing away our potential…$"
	
FiveIsland_LostCave_Room10_Text_Oak11::
	.string "Sweet…$"
	
FiveIsland_LostCave_Room10_Text_Agatha12::
	.string "Spare me your 'sweet.'\p"
	.string "If you won't work towards our future,\n"
	.string "I'll have to do it myself!$"
	
FiveIsland_LostCave_Room10_Text_TakeBall::
	.string "AGATHA took the GS BALL from\n"
	.string "SAMUEL!$"
	
FiveIsland_LostCave_Room10_Text_Agatha13::
	.string "You won't need this POKé BALL\n"
	.string "anymore.\p"
	.string "I will use it to build my own team!\p"
	.string "I'll start right here, inside this\n"
	.string "stupid cave!\p"
	.string "I'll see you soon…$"
	
FiveIsland_LostCave_Room10_Text_Oak12::
	.string "Sweet!\p"
	.string "Please come back, you'll get lost\n"
	.string "in here!$"
	
FiveIsland_LostCave_Room10_Text_Agatha14::
	.string "I know my way around here, OAK!\p"
	.string "Don't be silly!$"
	
FiveIsland_LostCave_Room10_Movement_PanToActionFromBottom::
	walk_slow_up
	walk_slow_up
	step_end
	
FiveIsland_LostCave_Room10_Movement_PanToActionFromTop::
	walk_slow_down
	walk_slow_down
	step_end
	
FiveIsland_LostCave_Room10_Movement_Agatha1::
	walk_in_place_up
	step_end
	
FiveIsland_LostCave_Room10_Movement_Oak1::
	walk_in_place_up
	step_end
	
FiveIsland_LostCave_Room10_Movement_Oak2::
	walk_up
	walk_up
	walk_in_place_up
	step_end
	
FiveIsland_LostCave_Room10_Movement_Agatha2::
	walk_up
	walk_in_place_up
	step_end
	
FiveIsland_LostCave_Room10_Movement_Oak3::
	walk_in_place_down
	step_end	
	
FiveIsland_LostCave_Room10_Movement_Agatha3::
	walk_right
	walk_in_place_up
	step_end
	
FiveIsland_LostCave_Room10_Movement_Agatha4::
	walk_down
	walk_in_place_down
	step_end
	
FiveIsland_LostCave_Room10_Movement_Agatha5::
	walk_fast_up
	walk_in_place_up
	walk_fast_down
	step_end
	
FiveIsland_LostCave_Room10_Movement_Agatha6::
	walk_in_place_down
	step_end
	
FiveIsland_LostCave_Room10_Movement_Agatha7::
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end
	
FiveIsland_LostCave_Room10_Movement_Oak4::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	step_end
	
FiveIsland_LostCave_Room10_Text_Celebi::
	.string "Biiii!$"