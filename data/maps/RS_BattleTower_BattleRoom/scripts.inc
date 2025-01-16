	.set LOCALID_ATTENDANT, 2

RS_BattleTower_BattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleTower_BattleRoom_OnFrame
	.byte 0

BattleTower_BattleRoom_OnFrame::
	map_script_2 VAR_TEMP_0, 0, BattleTower_BattleRoom_StartPlayerWalk
	.2byte 0

BattleTower_BattleRoom_StartPlayerWalk::
	setvar VAR_TEMP_0, 1
	applymovement OBJ_EVENT_ID_PLAYER, BattleTower_BattleRoom_Movement_160AB7
	waitmovement 0
BattleTower_BattleRoom_EventScript_Battle::
	special ChooseNextBattleTowerTrainer
	addobject 1
	applymovement 1, BattleTower_BattleRoom_Movement_160AC0
	waitmovement 0
	compare VAR_LAST_TALKED, 0
	call_if_eq BattleTower_BattleRoom_EventScript_TextcolorMale
	compare VAR_LAST_TALKED, 1
	call_if_eq BattleTower_BattleRoom_EventScript_TextcolorFemale
	goto_if_eq VAR_0x8006, 1, BattleTower_BrainBattleMessage
	goto_if_eq VAR_0x8006, 2, BattleTower_SecondBrainBattleMessage
	setvar VAR_0x8004, 0
	special PrintBattleTowerTrainerGreeting
	msgbox gStringVar4, MSGBOX_DEFAULT
	goto BattleTower_BattleRoom_EventScript_Battle_Message_Continue
BattleTower_BrainBattleMessage::
	msgbox BattleTower_BattleRoom_BrainAnabel_Intro
	goto BattleTower_BattleRoom_EventScript_Battle_Message_Continue
BattleTower_SecondBrainBattleMessage::
	msgbox BattleTower_BattleRoom_BrainAnabel2_Intro
BattleTower_BattleRoom_EventScript_Battle_Message_Continue::
	waitmessage
	closemessage
	callnative HealPlayerPartyOak
	setvar VAR_0x8005, 0
	special StartSpecialBattle
	waitstate
	switch VAR_RESULT
	case 1, BattleTower_BattleRoom_EventScript_PlayerWin
	special LoadPlayerParty
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 5
	special SetBattleTowerProperty
	setvar VAR_0x8004, 14
	special SetBattleTowerProperty
	setvar VAR_0x8004, 3
	//special sub_810FF60 //fan club thing
	warp MAP_RS_BATTLE_TOWER_LOBBY, 255, 6, 6
	waitstate

BattleTower_BattleRoom_EventScript_PlayerWin::
	setvar VAR_0x8004, 6
	special SetBattleTowerProperty
	switch VAR_RESULT
	case 8, BattleTower_BattleRoom_EventScript_RoundDone
	applymovement 1, BattleTower_BattleRoom_Movement_160AC6
	waitmovement 0
	removeobject 1
	applymovement LOCALID_ATTENDANT, BattleTower_BattleRoom_Movement_160ACB
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleTower_BattleRoom_Movement_160ABC
	waitmovement 0
	textcolor 0x1
	msgbox BattleTower_BattleRoom_Text_Heal, MSGBOX_DEFAULT
	special LoadPlayerParty
	special SavePlayerParty
	special SetBattleTowerParty
	playfanfare MUS_RS_HEAL
	waitfanfare
	callnative HealPlayerPartyOak
	special IsNextBattleTowerTrainerFrontierLeader
	@ this special will also set special var 4 to brain if necessary, required for special battle case
	goto_if_eq VAR_0x8006, FALSE, BattleTower_BattleRoom_EventScript_PlayerChooseContinueNormal
	@ for sake of text matching, brain starts a different dialog loop
	textcolor 0x1
	msgbox BattleTower_BattleRoom_Text_BrainAnnounce, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTower_BattleRoom_EventScript_PlayerChoseStopBrain
	case YES, BattleTower_BattleRoom_EventScript_PlayerContinuesRound
	case 127, BattleTower_BattleRoom_EventScript_PlayerChoseStopBrain

BattleTower_BattleRoom_EventScript_PlayerChooseContinueNormal::
	textcolor 0x1
	msgbox BattleTower_BattleRoom_Text_OpponentAnnounce, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTower_BattleRoom_EventScript_PlayerChoseStopNormal
	case YES, BattleTower_BattleRoom_EventScript_PlayerContinuesRound
	case 127, BattleTower_BattleRoom_EventScript_PlayerChoseStopNormal

BattleTower_BattleRoom_EventScript_PlayerChoseStopNormal::
	textcolor 0x1
	msgbox BattleTower_BattleRoom_Text_ConfirmSaveAndQuit, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTower_BattleRoom_EventScript_160A0E
	case YES, BattleTower_BattleRoom_EventScript_160A94
	case 127, BattleTower_BattleRoom_EventScript_160A0E

BattleTower_BattleRoom_EventScript_160A0E::
	textcolor 0x1
	msgbox BattleTower_BattleRoom_Text_19AD66, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTower_BattleRoom_EventScript_PlayerChooseContinueNormal
	case YES, BattleTower_BattleRoom_EventScript_QuitRound
	case 127, BattleTower_BattleRoom_EventScript_PlayerChooseContinueNormal

BattleTower_BattleRoom_EventScript_PlayerChooseContinueLoopBrain::
	textcolor 0x1
	msgbox BattleTower_BattleRoom_Text_BrainAnnounce_Repeat, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTower_BattleRoom_EventScript_PlayerChoseStopBrain
	case YES, BattleTower_BattleRoom_EventScript_PlayerContinuesRound
	case 127, BattleTower_BattleRoom_EventScript_PlayerChoseStopBrain

BattleTower_BattleRoom_EventScript_PlayerChoseStopBrain::
	textcolor 0x1
	msgbox BattleTower_BattleRoom_Text_ConfirmSaveAndQuit, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTower_BattleRoom_EventScript_160A0EBrain
	case YES, BattleTower_BattleRoom_EventScript_160A94
	case 127, BattleTower_BattleRoom_EventScript_160A0EBrain

BattleTower_BattleRoom_EventScript_160A0EBrain::
	textcolor 0x1
	msgbox BattleTower_BattleRoom_Text_19AD66, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTower_BattleRoom_EventScript_PlayerChooseContinueLoopBrain
	case YES, BattleTower_BattleRoom_EventScript_QuitRound
	case 127, BattleTower_BattleRoom_EventScript_PlayerChooseContinueLoopBrain

BattleTower_BattleRoom_EventScript_PlayerContinuesRound::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BattleTower_BattleRoom_Movement_160ABE
	waitmovement 0
	applymovement LOCALID_ATTENDANT, BattleTower_BattleRoom_Movement_160AD0
	waitmovement 0
	goto BattleTower_BattleRoom_EventScript_Battle

BattleTower_BattleRoom_EventScript_RoundDone::
	special LoadPlayerParty
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 4
	special SetBattleTowerProperty
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	special SetBattleTowerProperty
	setvar VAR_0x8004, 7
	special SetBattleTowerProperty
	setvar VAR_0x8004, 14
	special SetBattleTowerProperty
	setvar VAR_0x8004, 3
	//special sub_810FF60 //fan club thing
	warp MAP_RS_BATTLE_TOWER_LOBBY, 255, 6, 6
	waitstate

BattleTower_BattleRoom_EventScript_160A94::
	setvar VAR_0x8004, 2
	special SaveBattleTowerProgress
	textcolor 0x3
	message BattleTower_BattleRoom_Text_System_Saving
	delay 60
	waitmessage
	playse SE_SAVE
	waitse
	msgbox BattleTower_BattleRoom_Text_1C6D05, MSGBOX_DEFAULT
	
BattleTower_BattleRoom_EventScript_QuitRound::
	fadescreen FADE_TO_BLACK
	special BattleTower_SoftReset
	end

BattleTower_BattleRoom_EventScript_TextcolorMale::
	textcolor 0x0
	return

BattleTower_BattleRoom_EventScript_TextcolorFemale::
	textcolor 0x1
	return

BattleTower_BattleRoom_Movement_160AB7::
	walk_up
	walk_up
	walk_up
	face_right
	step_end

BattleTower_BattleRoom_Movement_160ABC::
	face_down
	step_end

BattleTower_BattleRoom_Movement_160ABE::
	face_right
	step_end

BattleTower_BattleRoom_Movement_160AC0::
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

BattleTower_BattleRoom_Movement_160AC6::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleTower_BattleRoom_Movement_160ACB::
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleTower_BattleRoom_Movement_160AD0::
	walk_down
	walk_left
	walk_left
	walk_left
	face_right
	step_end
