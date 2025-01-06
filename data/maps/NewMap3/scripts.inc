.set LOCALID_BROCK, 1
.set LOCALID_MISTY, 2
.set LOCALID_SURGE, 3
.set LOCALID_ERIKA, 4
.set LOCALID_KOGA, 5
.set LOCALID_SABRINA, 7
.set LOCALID_BLAINE, 6

NewMap3_MapScripts::
	.byte 0

Brock3::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_LEADER_BROCK_CHALLENGE, LOCALID_BROCK, Gym_Text_Done
	call EventScript_Debug_IncreaseLevelScale
	end

Misty3::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_LEADER_MISTY_CHALLENGE, LOCALID_MISTY, Gym_Text_Done
	call EventScript_Debug_IncreaseLevelScale
	end

Surge3::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_LEADER_LT_SURGE_CHALLENGE, LOCALID_SURGE, Gym_Text_Done
	call EventScript_Debug_IncreaseLevelScale
	end

Erika3::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_LEADER_ERIKA_CHALLENGE, LOCALID_ERIKA, Gym_Text_Done
	call EventScript_Debug_IncreaseLevelScale
	end

Koga3::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_LEADER_KOGA_CHALLENGE, LOCALID_KOGA, Gym_Text_Done
	call EventScript_Debug_IncreaseLevelScale
	end

Sabrina3::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_LEADER_SABRINA_CHALLENGE, LOCALID_SABRINA, Gym_Text_Done
	call EventScript_Debug_IncreaseLevelScale
	end

Blaine3::
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, TRAINER_LEADER_BLAINE_CHALLENGE, LOCALID_BLAINE, Gym_Text_Done
	call EventScript_Debug_IncreaseLevelScale
	end
