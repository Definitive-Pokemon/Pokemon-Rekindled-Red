.set LOCALID_LOSTELLE, 1
.set LOCALID_LATIAS, 15
.set LOCALID_ANABEL, 16

ThreeIsland_BerryForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_BerryForest_OnTransition
	.byte 0

ThreeIsland_BerryForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_THREE_ISLAND_BERRY_FOREST
	getplayerxy VAR_RESULT, VAR_TEMP_1
	goto_if_ge VAR_RESULT, 59, ThreeIsland_BerryForest_SetNewAreaEscapeWarp
	setescapewarp MAP_THREE_ISLAND_BOND_BRIDGE, 255, 12, 26
	end

ThreeIsland_BerryForest_SetNewAreaEscapeWarp::
	setescapewarp MAP_THREE_ISLAND_BOND_BRIDGE, 255, 28, 5
	end

ThreeIsland_BerryForest_EventScript_Lostelle::
	lock
	faceplayer
	msgbox ThreeIsland_BerryForest_Text_HelpScaryPokemon
	playse SE_PIN
	applymovement LOCALID_LOSTELLE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LOSTELLE, ThreeIsland_BerryForest_Movement_LostelleLookAround
	waitmovement 0
	msgbox ThreeIsland_BerryForest_Text_HereItComesAgain
	goto_if_questlog EventScript_ReleaseEnd
	waitse
	playmoncry SPECIES_HYPNO, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_HYPNO, 45
	dowildbattle
	special QuestLog_CutRecording
	applymovement LOCALID_LOSTELLE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox ThreeIsland_BerryForest_Text_ThankYouHaveThis
	giveitem ITEM_KELPSY_BERRY
	call_if_eq VAR_RESULT, FALSE, ThreeIsland_BerryForest_EventScript_NoRoomForBerry
	special BufferBigGuyOrBigGirlString
	msgbox ThreeIsland_BerryForest_Text_LetsGoHome
	closemessage
	setflag FLAG_RESCUED_LOSTELLE
	setflag FLAG_HIDE_LOSTELLE_IN_BERRY_FOREST
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2
	clearflag FLAG_HIDE_TWO_ISLAND_GAME_CORNER_LOSTELLE
	warp MAP_TWO_ISLAND_JOYFUL_GAME_CORNER, 6, 6
	waitstate
	release
	end

ThreeIsland_BerryForest_EventScript_NoRoomForBerry::
	msgbox ThreeIsland_BerryForest_Text_BerryPouchIsFull
	return

ThreeIsland_BerryForest_Movement_LostelleLookAround::
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_left
	step_end

ThreeIsland_BerryForest_EventScript_WelcomeSign::
	msgbox ThreeIsland_BerryForest_Text_WelcomeToBerryForest, MSGBOX_SIGN
	end

ThreeIsland_BerryForest_EventScript_BewareSign::
	msgbox ThreeIsland_BerryForest_Text_BewareWildBerryLovingMons, MSGBOX_SIGN
	end

ThreeIsland_BerryForest_EventScript_Latias::
	lockall
	playmoncry SPECIES_LATIAS, CRY_MODE_ENCOUNTER
	fadescreen FADE_TO_BLACK
	playse SE_M_FLY
	waitse
	removeobject LOCALID_LATIAS
	fadescreen FADE_FROM_BLACK
	msgbox ThreeIsland_BerryForest_Text_Flew
	closemessage
	addobject LOCALID_ANABEL
	clearflag FLAG_HIDE_ANABEL_FIRST
	applymovement LOCALID_ANABEL, ThreeIsland_BerryForest_Movement_AnabelArrive
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, ThreeIsland_BerryForest_Movement_PlayerTurn
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox ThreeIsland_BerryForest_Text_AnabelTalk
	closemessage
	trainerbattle_single_nowhiteout TRAINER_MYSTERY_GIRL_ANABEL, ThreeIsland_BerryForest_Text_AnabelDefeat, ThreeIsland_BerryForest_Text_AnabelVictory
	goto ThreeIsland_BerryForest_EventScript_Win
	end

ThreeIsland_BerryForest_EventScript_Win::
	lockall
	callnative HealPlayerPartyOak
	msgbox ThreeIsland_BerryForest_Text_AnabelTalk2
	closemessage
	delay 50
	applymovement LOCALID_ANABEL, ThreeIsland_BerryForest_Movement_AnabelTalk
	waitmovement 0
	msgbox ThreeIsland_BerryForest_Text_AnabelTalk3
	closemessage
	applymovement LOCALID_ANABEL, ThreeIsland_BerryForest_Movement_AnabelConcentrate
	waitmovement 0
	msgbox ThreeIsland_BerryForest_Text_AnabelTalk4
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, ThreeIsland_BerryForest_Movement_PlayerTell
	waitmovement 0
	textcolor 2
	msgbox ThreeIsland_BerryForest_Text_PlayerRelay
	closemessage
	applymovement LOCALID_ANABEL, ThreeIsland_BerryForest_Movement_AnabelTalkBack
	waitmovement 0
	textcolor 1
	msgbox ThreeIsland_BerryForest_Text_AnabelTalk5
	closemessage
	applymovement LOCALID_ANABEL, ThreeIsland_BerryForest_Movement_AnabelGo
	waitmovement 0
	removeobject LOCALID_ANABEL
	delay 100
	setflag FLAG_HIDE_ANABEL_FIRST
	setflag FLAG_HIDE_LATIAS_FIRST
	setvar VAR_LATIAS_FIRST, 1
	clearflag FLAG_HIDE_ANABEL_SECOND
	releaseall
	end
	
ThreeIsland_BerryForest_Movement_AnabelArrive::
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
ThreeIsland_BerryForest_Movement_PlayerTurn::
	walk_in_place_down
	step_end
	
ThreeIsland_BerryForest_Movement_PlayerTell::
	walk_in_place_down
	step_end
	
ThreeIsland_BerryForest_Movement_AnabelTalk::
	walk_in_place_up
	step_end
	
ThreeIsland_BerryForest_Movement_AnabelConcentrate::
	walk_in_place_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_up
	step_end
	
ThreeIsland_BerryForest_Movement_AnabelTalkBack::
	walk_in_place_up
	step_end
	
ThreeIsland_BerryForest_Movement_AnabelGo::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end
