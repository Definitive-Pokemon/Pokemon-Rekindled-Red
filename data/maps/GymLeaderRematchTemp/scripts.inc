.set LOCALID_BROCK, 2
.set LOCALID_MISTY, 6
.set LOCALID_SURGE, 3
.set LOCALID_ERIKA, 4
.set LOCALID_KOGA, 5
.set LOCALID_SABRINA, 7
.set LOCALID_BLAINE, 1

GymLeaderRematchTemp_MapScripts::
	.byte 0

GymLeaderRematchTemp_EventScript_CitySign::
	msgbox GymLeaderRematchTemp_Text_Sign, MSGBOX_SIGN
	end

GymLeaderRematchTemp_Text_Sign::
	.string "Welcome to this interior, designed\n"
	.string "to let you rematch KANTO's LEADERS\l"
	.string "for now.\p"
	.string "If you started playing this hack\n"
	.string "before the fix for the official\p"
	.string "rematches released in JANUARY 2025,\n"
	.string "this is the way of rematching them.\p"
	.string "This house features three rooms.\p"
	.string "Each room contains a team for every\n"
	.string "GYM LEADER, save for GIOVANNI.\p"
	.string "This room contains the weakest\n"
	.string "version of each LEADER.\p"
	.string "The next contains stronger teams.\n"
	.string "The last one contains the strongest.\p"
	.string "This is a TEMPORARY room, and will be\n"
	.string "properly replaced by a GYM house\l"
	.string "according to quality standards.$"

Brock1::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_BROCK_REMATCH, LOCALID_BROCK, Gym_Text_Done
	end

Misty1::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_MISTY_REMATCH, LOCALID_MISTY, Gym_Text_Done
	setvar VAR_TEMP_3, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	end

Surge1::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_LT_SURGE_REMATCH, LOCALID_SURGE, Gym_Text_Done
	setvar VAR_TEMP_3, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	end

Erika1::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_ERIKA_REMATCH, LOCALID_ERIKA, Gym_Text_Done
	setvar VAR_TEMP_3, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	end

Koga1::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_KOGA_REMATCH, LOCALID_KOGA, Gym_Text_Done
	setvar VAR_TEMP_3, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	end

Sabrina1::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_SABRINA_REMATCH, LOCALID_SABRINA, Gym_Text_Done
	setvar VAR_TEMP_3, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	end

Blaine1::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_BLAINE_REMATCH, LOCALID_BLAINE, Gym_Text_Done
	setvar VAR_TEMP_3, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	end

Gym_Text_Done::
	.string "Good job!$"