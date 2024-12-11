.equ LOCALID_MAXIMUS, 6

MtEmber_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtEmber_Summit_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MtEmber_Summit_OnResume
	.byte 0

MtEmber_Summit_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, MtEmber_Summit_EventScript_TryRemoveMoltres
	end

MtEmber_Summit_EventScript_TryRemoveMoltres::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Return
	removeobject VAR_LAST_TALKED
	return

MtEmber_Summit_OnTransition::
	call_if_set FLAG_RAIN_AND_EMBER, MtEmber_Summit_EventScript_SetRain
	call_if_set FLAG_FOUGHT_MOLTRES, MtEmber_Summit_EventScript_HideMoltres
	call_if_unset FLAG_FOUGHT_MOLTRES, MtEmber_Summit_EventScript_TryShowMoltres
	end

MtEmber_Summit_EventScript_SetRain::
	setweather WEATHER_RAIN
	doweather
	return

MtEmber_Summit_EventScript_Maximus::
	lockall
	textcolor 0
	fadenewbgm MUS_NONE
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MtEmber_Summit_Movement_PanToActionFromBottom
	waitmovement 0
	special RemoveCameraObject
	delay 60
	applymovement LOCALID_MAXIMUS, MtEmber_Summit_Movement_TakeFromMoltres
	playmoncry SPECIES_MOLTRES, 11
	waitmoncry
	waitmovement 0
	msgbox MtEmber_Summit_Text_Maximus_Mock, MSGBOX_NPC
	closemessage
	delay 30
	playbgm MUS_B_PIKE, 0
	applymovement LOCALID_MAXIMUS, MtEmber_Summit_Movement_TakeFromMoltres
	waitmovement 0
	delay 10
	applymovement LOCALID_MAXIMUS, MtEmber_Summit_Movement_TakeFromMoltres
	waitmovement 0
	delay 60
	msgbox MtEmber_Summit_Text_Maximus_Mock2, MSGBOX_NPC
	closemessage
	delay 80
	playse SE_PIN
	applymovement LOCALID_MAXIMUS, MtEmber_Summit_Movement_LookDown
	waitse
	waitmovement 0
	msgbox MtEmber_Summit_Text_Maximus_Look, MSGBOX_NPC
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_WARP_IN
	waitse
	removeobject LOCALID_MAXIMUS
	clearflag FLAG_RAIN_AND_EMBER
	setflag FLAG_HIDE_MAXIMUS_MOLTRES
	fadescreen FADE_FROM_BLACK
	setweather WEATHER_VOLCANIC_ASH
	doweather
	setvar VAR_EMBER_RAIN, 1
	fadenewbgm MUS_NONE
	delay 400
	playmoncry SPECIES_MOLTRES, 2
	waitmoncry
	delay 60
	setweather WEATHER_DROUGHT
	playse SE_M_HEAT_WAVE
	waitse
	doweather
	textcolor 2
	message MtEmber_Summit_Text_MoltresPowers
	waitbuttonpress
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MtEmber_Summit_Movement_PanToActionBack
	waitmovement 0
	special RemoveCameraObject
	delay 60
	releaseall
	end

MtEmber_Summit_Text_MoltresPowers::
	.string "MOLTRES seems agitated!$"

MtEmber_Summit_Movement_PanToActionFromBottom::
	walk_slow_up
	walk_slow_up
	step_end

MtEmber_Summit_Movement_PanToActionBack::
	walk_slow_down
	walk_slow_down
	step_end

MtEmber_Summit_Movement_TakeFromMoltres::
	walk_in_place_up
	step_end

MtEmber_Summit_Text_Maximus_Look::
	.string "Looks like this TRAINER here\n"
	.string "is after you, pal.\p"
	.string "Well, I got to go.\n"
	.string "You can play with this lad.$"

MtEmber_Summit_Text_Maximus_Mock2::
	.string "Well, all done!\n"
	.string "Now you can stop whining.\p"
	.string "Our RAIN DANCE was just perfect.\n"
	.string "Look how pathetic you are!\p"
	.string "You're not even worth catching now,\n"
	.string "and I got what I needed from you.\p"
	.string "Guess this is farewell.$"

MtEmber_Summit_Text_Maximus_Mock::
	.string "There, there.\p"
	.string "It doesn't hurt too much,\n"
	.string "does it?$"

MtEmber_Summit_Movement_LookDown::
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_down
	step_end

MtEmber_Summit_EventScript_TryShowMoltres::
	goto_if_set FLAG_MOLTRES_FLEW_AWAY, EventScript_Return
	clearflag FLAG_HIDE_MOLTRES
	return

MtEmber_Summit_EventScript_HideMoltres::
	setflag FLAG_HIDE_MOLTRES
	return

MtEmber_Summit_EventScript_Moltres::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 2
	faceplayer
	setwildbattle SPECIES_MOLTRES, 50, ITEM_NONE
	waitse
	playmoncry SPECIES_MOLTRES, 2
	message Text_Gyaoo
	setweather WEATHER_DROUGHT
	doweather
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
	goto_if_eq MtEmber_Summit_EventScript_DefeatedMoltres
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq MtEmber_Summit_EventScript_RanFromMoltres
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq MtEmber_Summit_EventScript_RanFromMoltres
	setflag FLAG_FOUGHT_MOLTRES
	release
	end

MtEmber_Summit_EventScript_DefeatedMoltres::
	setflag FLAG_MOLTRES_FLEW_AWAY
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto EventScript_MonFlewAway
	end

MtEmber_Summit_EventScript_RanFromMoltres::
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto EventScript_MonFlewAway
	end
