.set LOCALID_BROCK, 1
.set LOCALID_MISTY, 2
.set LOCALID_SURGE, 3
.set LOCALID_ERIKA, 4
.set LOCALID_KOGA, 5
.set LOCALID_SABRINA, 7
.set LOCALID_BLAINE, 6

NewMap2_MapScripts::
	.byte 0

Brock2::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_BROCK_REMATCH_CHALLENGE, LOCALID_BROCK, Gym_Text_Done
	setvar VAR_TEMP_3, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	end

Misty2::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_MISTY_REMATCH_CHALLENGE, LOCALID_MISTY, Gym_Text_Done
	setvar VAR_TEMP_3, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	end

Surge2::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_LT_SURGE_REMATCH_CHALLENGE, LOCALID_SURGE, Gym_Text_Done
	setvar VAR_TEMP_3, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	end

Erika2::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_ERIKA_REMATCH_CHALLENGE, LOCALID_ERIKA, Gym_Text_Done
	setvar VAR_TEMP_3, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	end

Koga2::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_KOGA_REMATCH_CHALLENGE, LOCALID_KOGA, Gym_Text_Done
	setvar VAR_TEMP_3, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	end

Sabrina2::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_SABRINA_REMATCH_CHALLENGE, LOCALID_SABRINA, Gym_Text_Done
	setvar VAR_TEMP_3, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	end

Blaine2::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_BLAINE_REMATCH_CHALLENGE, LOCALID_BLAINE, Gym_Text_Done
	setvar VAR_TEMP_3, SET_LEVEL_GROWTH
	callnative UseBattleHouseVar
	end
	