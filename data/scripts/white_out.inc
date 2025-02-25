EventScript_AfterWhiteOutHeal::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox Text_FirstShouldRestoreMonsHealth
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	call_if_unset FLAG_DEFEATED_BROCK, EventScript_AfterWhiteOutHealMsgPreBrock
	call_if_set FLAG_DEFEATED_BROCK, EventScript_AfterWhiteOutHealMsg
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

EventScript_NuzlockeHaveMons_Nurse::
	lockall
	textcolor 1
	msgbox Text_SwappedForYou_NuzlockeOnly
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

EventScript_NoPMCHaveMons_Nurse::
	lockall
	textcolor 1
	msgbox Text_SwappedForYou_NoPMCOnly
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

Text_SwappedForYou_NuzlockeOnly::
	.string "I've swapped a POKéMON from your\n"
	.string "BOX with a POKéMON in your party.\p"
	.string "If your POKéMON's energy, HP, is\n"
	.string "low, come see us before they faint.\p"
	.string "If you're planning to go far in the\n"
	.string "field, you should buy some POTIONS\l"
	.string "at the POKéMON MART.\p"
	.string "We hope you excel!$"

Text_SwappedForYou_NoPMCOnly::
	.string "I've swapped a POKéMON from your\n"
	.string "BOX with a POKéMON in your party.\p"
	.string "If you're planning to go far in the\n"
	.string "field, you should buy some POTIONS\l"
	.string "at the POKéMON MART.\p"
	.string "We hope you excel!$"

EventScript_AfterWhiteOutHealMsgPreBrock::
	textcolor 1
	msgbox Text_MonsHealedShouldBuyPotions
	return

EventScript_AfterWhiteOutHealMsg::
	textcolor 1
	msgbox Text_MonsHealed
	return

@ LOCALID_MOM set by PalletTown_PlayersHouse_1F

EventScript_AfterWhiteOutMomHeal::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Text_HadQuiteAnExperienceTakeRest
	call EventScript_OutOfCenterPartyHeal
	textcolor 1
	msgbox Text_MomExplainHPGetPotions
	fadedefaultbgm
	releaseall
	end

EventScript_AfterWhiteOutElmHeal::
    lockall
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox ElmsLab_Text_YouShouldTakeQuickRest
	call EventScript_OutOfCenterPartyHeal
	msgbox ElmsLab_Text_LookingGreatTakeCare
	closemessage
	fadedefaultbgm
	applymovement LOCALID_ELM, Movement_ElmFacingYou
	waitmovement 0
	textcolor 0
	msgbox ElmsLab_Text_Heyy
	closemessage
	applymovement LOCALID_ELM, Movement_ElmFacingAway
	waitmovement 0
	releaseall
	end

Movement_ElmFacingYou::
	walk_in_place_left
	step_end

Movement_ElmFacingAway::
	face_down
	step_end

ElmsLab_Text_Heyy::
	.string "Hey, it's {PLAYER}!\p"
	.string "I guess even a CHAMPION still loses\n"
	.string "battles occasionally.\p"
	.string "Please be more careful from here on!$"

EventScript_NuzlockeGameOver::
	lockall
	textcolor 3
	signmsg
	msgbox Text_NuzlockeGameOver
	msgbox EventScript_NuzlockeGameOver_Text_0, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NuzlockeGameOver_1
	msgbox EventScript_NuzlockeGameOver_Text_3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NuzlockeGameOver_7
	setvar VAR_TEMP_9, 2
	goto EventScript_NuzlockeGameOver_Loop
	return

EventScript_NuzlockeGameOver_1:
	msgbox EventScript_NuzlockeGameOver_Text_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NuzlockeGameOver_4
	setvar VAR_TEMP_9, 1
	goto EventScript_NuzlockeGameOver_Loop
	return

EventScript_NuzlockeGameOver_4:
	msgbox EventScript_NuzlockeGameOver_Text_2
	callnative DoSoftReset
	return

EventScript_NuzlockeGameOver_7:
	msgbox EventScript_NuzlockeGameOver_Text_4
	normalmsg
	callnative TurnOffNuzlockeMode
	callnative ResetTintFilter
	goto EventScript_AfterWhiteOutHeal
	return

EventScript_NuzlockeGameOver_Loop::
	switch VAR_TEMP_9
	case 1, EventScript_NuzlockeGameOver_Loop_2
	case 2, EventScript_NuzlockeGameOver_Loop_3
	return

EventScript_NuzlockeGameOver_Loop_2:
	msgbox EventScript_NuzlockeGameOver_Text_3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NuzlockeGameOver_Loop_4
	setvar VAR_TEMP_9, 2
	goto EventScript_NuzlockeGameOver_Loop
	return

EventScript_NuzlockeGameOver_Loop_3:
	msgbox EventScript_NuzlockeGameOver_Text_0, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NuzlockeGameOver_Loop_7
	setvar VAR_TEMP_9, 1
	goto EventScript_NuzlockeGameOver_Loop
	return

EventScript_NuzlockeGameOver_Loop_4:
	msgbox EventScript_NuzlockeGameOver_Text_4
	normalmsg
	callnative TurnOffNuzlockeMode
	callnative ResetTintFilter
	goto EventScript_AfterWhiteOutHeal
	return

EventScript_NuzlockeGameOver_Loop_7:
	msgbox EventScript_NuzlockeGameOver_Text_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NuzlockeGameOver_Loop_10
	setvar VAR_TEMP_9, 1
	goto EventScript_NuzlockeGameOver_Loop
	return

EventScript_NuzlockeGameOver_Loop_10:
	msgbox EventScript_NuzlockeGameOver_Text_2
	callnative DoSoftReset
	return

EventScript_NuzlockeGameOver_Text_0:
	.string "Would you like to reset to the\nlast save point?$"

EventScript_NuzlockeGameOver_Text_1:
	.string "Are you sure?\pYou will lose all progress since\nyou last saved.$"

EventScript_NuzlockeGameOver_Text_2:
	.string "The game will now reset.$"

EventScript_NuzlockeGameOver_Text_3:
	.string "Would you like to turn off\nNUZLOCKE MODE and heal your party?$"

EventScript_NuzlockeGameOver_Text_4:
	.string "NUZLOCKE MODE has been turned off.$"

EventScript_NuzlockeGameOver_Mom::
	lockall
	textcolor 3
	signmsg
	msgbox Text_NuzlockeGameOver
	msgbox EventScript_NuzlockeGameOver_Text_0, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NuzlockeGameOver_Mom_1
	msgbox EventScript_NuzlockeGameOver_Text_3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NuzlockeGameOver_Mom_7
	setvar VAR_TEMP_9, 2
	goto EventScript_NuzlockeGameOver_Loop_Mom
	return

EventScript_NuzlockeGameOver_Mom_1:
	msgbox EventScript_NuzlockeGameOver_Text_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NuzlockeGameOver_Mom_4
	setvar VAR_TEMP_9, 1
	goto EventScript_NuzlockeGameOver_Loop_Mom
	return

EventScript_NuzlockeGameOver_Mom_4:
	msgbox EventScript_NuzlockeGameOver_Text_2
	callnative DoSoftReset
	return

EventScript_NuzlockeGameOver_Mom_7:
	msgbox EventScript_NuzlockeGameOver_Text_4
	normalmsg
	callnative TurnOffNuzlockeMode
	callnative ResetTintFilter
	goto EventScript_AfterWhiteOutMomHeal
	return


EventScript_NuzlockeGameOver_Loop_Mom::
	switch VAR_TEMP_9
	case 1, EventScript_NuzlockeGameOver_Loop_Mom_2
	case 2, EventScript_NuzlockeGameOver_Loop_Mom_3
	return

EventScript_NuzlockeGameOver_Loop_Mom_2:
	msgbox EventScript_NuzlockeGameOver_Text_3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NuzlockeGameOver_Loop_Mom_4
	setvar VAR_TEMP_9, 2
	goto EventScript_NuzlockeGameOver_Loop_Mom
	return

EventScript_NuzlockeGameOver_Loop_Mom_3:
	msgbox EventScript_NuzlockeGameOver_Text_0, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NuzlockeGameOver_Loop_Mom_7
	setvar VAR_TEMP_9, 1
	goto EventScript_NuzlockeGameOver_Loop_Mom
	return

EventScript_NuzlockeGameOver_Loop_Mom_4:
	msgbox EventScript_NuzlockeGameOver_Text_4
	normalmsg
	callnative TurnOffNuzlockeMode
	callnative ResetTintFilter
	goto EventScript_AfterWhiteOutMomHeal
	return

EventScript_NuzlockeGameOver_Loop_Mom_7:
	msgbox EventScript_NuzlockeGameOver_Text_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NuzlockeGameOver_Loop_Mom_10
	setvar VAR_TEMP_9, 1
	goto EventScript_NuzlockeGameOver_Loop_Mom
	return

EventScript_NuzlockeGameOver_Loop_Mom_10:
	msgbox EventScript_NuzlockeGameOver_Text_2
	callnative DoSoftReset
	return

Text_NuzlockeGameOver::
	.string "You have no more POKéMON that can\n"
	.string "battle in your POKéMON PC.\p"
	.string "You can either reset to the last\n"
	.string "time you saved, or turn off\l"
	.string "NUZLOCKE MODE and heal your party.$"

EventScript_NuzlockeHaveMons_Mom::
	lockall
	textcolor 1
	applymovement 1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Text_SwappedForYou_NuzlockeOnly_Mom
	fadedefaultbgm
	releaseall
	end

EventScript_NoPMCHaveMons_Mom::
	lockall
	textcolor 1
	applymovement 1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Text_SwappedForYou_NoPMCOnly_Mom
	fadedefaultbgm
	releaseall
	end

Text_SwappedForYou_NuzlockeOnly_Mom::
	.string "MOM: {PLAYER}!\n"
	.string "Welcome home.\p"
	.string "It sounds like you had quite\n"
	.string "an experience.\p"
	.string "I've swapped a POKéMON from your\n"
	.string "BOX with a POKéMON in your party.\p"
	.string "I just heard from PROF. OAK.\p"
	.string "He said that POKéMON's energy is\n"
	.string "measured in HP.\p"
	.string "If your POKéMON lose their HP,\n"
	.string "you can restore them at any\l"
	.string "POKéMON CENTER before they faint.\p"
	.string "If you're going to travel far away,\n"
	.string "the smart TRAINER stocks up on\l"
	.string "POTIONS at the POKéMON MART.\p"
	.string "Make me proud, honey!\p"
	.string "Take care!$"

Text_SwappedForYou_NoPMCOnly_Mom::
	.string "MOM: {PLAYER}!\n"
	.string "Welcome home.\p"
	.string "It sounds like you had quite\n"
	.string "an experience.\p"
	.string "I've swapped a POKéMON from your\n"
	.string "BOX with a POKéMON in your party.\p"
	.string "I just heard from PROF. OAK.\p"
	.string "He said that POKéMON's energy is\n"
	.string "measured in HP.\p"
	.string "If you're going to travel far away,\n"
	.string "the smart TRAINER stocks up on\l"
	.string "POTIONS at the POKéMON MART to\l"
	.string "restore their POKéMON's HP.\p"
	.string "Make me proud, honey!\p"
	.string "Take care!$"

EventScript_FieldPoison::
	lockall
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special TryFieldPoisonWhiteOut
	waitstate
	goto_if_eq VAR_RESULT, TRUE, EventScript_FieldWhiteOut
	releaseall
	end

EventScript_FieldWhiteOut::
	checkmoney 1
	goto_if_eq VAR_RESULT, FALSE, EventScript_FieldWhiteOutNoMoney
	goto_if_eq VAR_RESULT, TRUE, EventScript_FieldWhiteOutHasMoney
	end

EventScript_FieldWhiteOutNoMoney::
	msgbox Text_WhitedOut
	goto EventScript_FieldWhiteOutFade
	end

EventScript_FieldWhiteOutHasMoney::
	special OverworldWhiteOutGetMoneyLoss
	msgbox Text_WhitedOutLostMoney
	goto EventScript_FieldWhiteOutFade
	end

EventScript_FieldWhiteOutFade::
	special Script_FadeOutMapMusic
	waitstate
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate
	end

EventScript_BothGameOver::
	lockall
	textcolor 3
	signmsg
	msgbox EventScript_BothGameOver_Text_0
	msgbox EventScript_BothGameOver_Text_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_BothGameOver_1
	msgbox EventScript_BothGameOver_Text_4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_BothGameOver_7
	setvar VAR_TEMP_9, 2
	goto EventScript_BothGameOver_Loop
	return

EventScript_BothGameOver_1:
	msgbox EventScript_BothGameOver_Text_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_BothGameOver_4
	setvar VAR_TEMP_9, 1
	goto EventScript_BothGameOver_Loop
	return

EventScript_BothGameOver_4:
	msgbox EventScript_BothGameOver_Text_3
	callnative DoSoftReset
	return

EventScript_BothGameOver_7:
	msgbox EventScript_BothGameOver_Text_5
	normalmsg
	callnative TurnOffNuzlockeMode
	callnative TurnOffNoPMC
	callnative ResetTintFilter
	goto EventScript_AfterWhiteOutHeal
	return


EventScript_BothGameOver_Loop::
	switch VAR_TEMP_9
	case 1, EventScript_BothGameOver_Loop_2
	case 2, EventScript_BothGameOver_Loop_3
	return

EventScript_BothGameOver_Loop_2:
	msgbox EventScript_BothGameOver_Text_4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_BothGameOver_Loop_4
	setvar VAR_TEMP_9, 2
	goto EventScript_BothGameOver_Loop
	return

EventScript_BothGameOver_Loop_3:
	msgbox EventScript_BothGameOver_Text_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_BothGameOver_Loop_7
	setvar VAR_TEMP_9, 1
	goto EventScript_BothGameOver_Loop
	return

EventScript_BothGameOver_Loop_4:
	msgbox EventScript_BothGameOver_Text_5
	normalmsg
	callnative TurnOffNuzlockeMode
	callnative TurnOffNoPMC
	callnative ResetTintFilter
	goto EventScript_AfterWhiteOutHeal
	return

EventScript_BothGameOver_Loop_7:
	msgbox EventScript_BothGameOver_Text_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_BothGameOver_Loop_10
	setvar VAR_TEMP_9, 1
	goto EventScript_BothGameOver_Loop
	return

EventScript_BothGameOver_Loop_10:
	msgbox EventScript_BothGameOver_Text_3
	callnative DoSoftReset
	return

EventScript_BothGameOver_Text_0:
	.string "You have no more POKéMON that can\nbattle in your POKéMON PC.\pYou can either reset to the last\ntime you saved, or turn off\lNUZLOCKE MODE and NO FREE HEALS\land heal your party.$"

EventScript_BothGameOver_Text_1:
	.string "Would you like to reset to the\nlast save point?$"

EventScript_BothGameOver_Text_2:
	.string "Are you sure?\pYou will lose all progress since\nyou last saved.$"

EventScript_BothGameOver_Text_3:
	.string "The game will now reset.$"

EventScript_BothGameOver_Text_4:
	.string "Would you like to turn off NUZLOCKE\nMODE and NO FREE HEALS and heal\lyour party?$"

EventScript_BothGameOver_Text_5:
	.string "NUZLOCKE MODE and NO FREE HEALS\nhave been turned off.$"

EventScript_BothGameOver_Mom::
	lockall
	textcolor 3
	signmsg
	msgbox EventScript_BothGameOver_Mom_Text_0
	msgbox EventScript_BothGameOver_Mom_Text_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_BothGameOver_Mom_1
	msgbox EventScript_BothGameOver_Mom_Text_4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_BothGameOver_Mom_7
	setvar VAR_TEMP_9, 2
	goto EventScript_BothGameOver_Loop_Mom
	return

EventScript_BothGameOver_Mom_1:
	msgbox EventScript_BothGameOver_Mom_Text_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_BothGameOver_Mom_4
	setvar VAR_TEMP_9, 1
	goto EventScript_BothGameOver_Loop_Mom
	return

EventScript_BothGameOver_Mom_4:
	msgbox EventScript_BothGameOver_Mom_Text_3
	callnative DoSoftReset
	return

EventScript_BothGameOver_Mom_7:
	msgbox EventScript_BothGameOver_Mom_Text_5
	normalmsg
	callnative TurnOffNuzlockeMode
	callnative TurnOffNoPMC
	callnative ResetTintFilter
	goto EventScript_AfterWhiteOutMomHeal
	return


EventScript_BothGameOver_Loop_Mom::
	switch VAR_TEMP_9
	case 1, EventScript_BothGameOver_Loop_Mom_2
	case 2, EventScript_BothGameOver_Loop_Mom_3
	return

EventScript_BothGameOver_Loop_Mom_2:
	msgbox EventScript_BothGameOver_Mom_Text_4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_BothGameOver_Loop_Mom_4
	setvar VAR_TEMP_9, 2
	goto EventScript_BothGameOver_Loop_Mom
	return

EventScript_BothGameOver_Loop_Mom_3:
	msgbox EventScript_BothGameOver_Mom_Text_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_BothGameOver_Loop_Mom_7
	setvar VAR_TEMP_9, 1
	goto EventScript_BothGameOver_Loop_Mom
	return

EventScript_BothGameOver_Loop_Mom_4:
	msgbox EventScript_BothGameOver_Mom_Text_5
	normalmsg
	callnative TurnOffNuzlockeMode
	callnative TurnOffNoPMC
	callnative ResetTintFilter
	goto EventScript_AfterWhiteOutMomHeal
	return

EventScript_BothGameOver_Loop_Mom_7:
	msgbox EventScript_BothGameOver_Mom_Text_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_BothGameOver_Loop_Mom_10
	setvar VAR_TEMP_9, 1
	goto EventScript_BothGameOver_Loop_Mom
	return

EventScript_BothGameOver_Loop_Mom_10:
	msgbox EventScript_BothGameOver_Mom_Text_3
	callnative DoSoftReset
	return

EventScript_BothGameOver_Mom_Text_0:
	.string "You have no more POKéMON that can\nbattle in your POKéMON PC.\pYou can either reset to the last\ntime you saved, or turn off\lNUZLOCKE MODE and NO FREE HEALS\land heal your party.$"

EventScript_BothGameOver_Mom_Text_1:
	.string "Would you like to reset to the\nlast save point?$"

EventScript_BothGameOver_Mom_Text_2:
	.string "Are you sure?\pYou will lose all progress since\nyou last saved.$"

EventScript_BothGameOver_Mom_Text_3:
	.string "The game will now reset.$"

EventScript_BothGameOver_Mom_Text_4:
	.string "Would you like to turn off NUZLOCKE\nMODE and NO FREE HEALS and heal\lyour party?$"

EventScript_BothGameOver_Mom_Text_5:
	.string "NUZLOCKE MODE and NO FREE HEALS\nhave been turned off.$"

EventScript_NoPMCGameOver_Mom::
	lockall
	textcolor 3
	signmsg
	msgbox EventScript_NoPMCGameOver_Mom_Text_0
	msgbox EventScript_NoPMCGameOver_Mom_Text_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NoPMCGameOver_Mom_1
	msgbox EventScript_NoPMCGameOver_Mom_Text_4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NoPMCGameOver_Mom_7
	setvar VAR_TEMP_9, 2
	goto EventScript_NoPMCGameOver_Loop_Mom
	return

EventScript_NoPMCGameOver_Mom_1:
	msgbox EventScript_NoPMCGameOver_Mom_Text_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NoPMCGameOver_Mom_4
	setvar VAR_TEMP_9, 1
	goto EventScript_NoPMCGameOver_Loop_Mom
	return

EventScript_NoPMCGameOver_Mom_4:
	msgbox EventScript_NoPMCGameOver_Mom_Text_3
	callnative DoSoftReset
	return

EventScript_NoPMCGameOver_Mom_7:
	msgbox EventScript_NoPMCGameOver_Mom_Text_5
	normalmsg
	callnative TurnOffNoPMC
	callnative ResetTintFilter
	goto EventScript_AfterWhiteOutMomHeal
	return


EventScript_NoPMCGameOver_Loop_Mom::
	switch VAR_TEMP_9
	case 1, EventScript_NoPMCGameOver_Loop_Mom_2
	case 2, EventScript_NoPMCGameOver_Loop_Mom_3
	return

EventScript_NoPMCGameOver_Loop_Mom_2:
	msgbox EventScript_NoPMCGameOver_Mom_Text_4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NoPMCGameOver_Loop_Mom_4
	setvar VAR_TEMP_9, 2
	goto EventScript_NoPMCGameOver_Loop_Mom
	return

EventScript_NoPMCGameOver_Loop_Mom_3:
	msgbox EventScript_NoPMCGameOver_Mom_Text_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NoPMCGameOver_Loop_Mom_7
	setvar VAR_TEMP_9, 1
	goto EventScript_NoPMCGameOver_Loop_Mom
	return

EventScript_NoPMCGameOver_Loop_Mom_4:
	msgbox EventScript_NoPMCGameOver_Mom_Text_5
	normalmsg
	callnative TurnOffNoPMC
	callnative ResetTintFilter
	goto EventScript_AfterWhiteOutMomHeal
	return

EventScript_NoPMCGameOver_Loop_Mom_7:
	msgbox EventScript_NoPMCGameOver_Mom_Text_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NoPMCGameOver_Loop_Mom_10
	setvar VAR_TEMP_9, 1
	goto EventScript_NoPMCGameOver_Loop_Mom
	return

EventScript_NoPMCGameOver_Loop_Mom_10:
	msgbox EventScript_NoPMCGameOver_Mom_Text_3
	callnative DoSoftReset
	return

EventScript_NoPMCGameOver_Mom_Text_0:
	.string "You have no more POKéMON that can\nbattle in your POKéMON PC.\pYou can either reset to the last\ntime you saved, or turn off\lNO FREE HEALS and heal your party.$"

EventScript_NoPMCGameOver_Mom_Text_1:
	.string "Would you like to reset to the\nlast save point?$"

EventScript_NoPMCGameOver_Mom_Text_2:
	.string "Are you sure?\pYou will lose all progress since\nyou last saved.$"

EventScript_NoPMCGameOver_Mom_Text_3:
	.string "The game will now reset.$"

EventScript_NoPMCGameOver_Mom_Text_4:
	.string "Would you like to turn off\nNO FREE HEALS and heal your party?$"

EventScript_NoPMCGameOver_Mom_Text_5:
	.string "NO FREE HEALS has been turned off.$"

EventScript_NoPMCGameOver::
	lockall
	textcolor 3
	signmsg
	msgbox EventScript_NoPMCGameOver_Text_0
	msgbox EventScript_NoPMCGameOver_Text_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NoPMCGameOver_1
	msgbox EventScript_NoPMCGameOver_Text_4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NoPMCGameOver_7
	setvar VAR_TEMP_9, 2
	goto EventScript_NoPMCGameOver_Loop
	return

EventScript_NoPMCGameOver_1:
	msgbox EventScript_NoPMCGameOver_Text_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NoPMCGameOver_4
	setvar VAR_TEMP_9, 1
	goto EventScript_NoPMCGameOver_Loop
	return

EventScript_NoPMCGameOver_4:
	msgbox EventScript_NoPMCGameOver_Text_3
	callnative DoSoftReset
	return

EventScript_NoPMCGameOver_7:
	msgbox EventScript_NoPMCGameOver_Text_5
	normalmsg
	callnative TurnOffNoPMC
	callnative ResetTintFilter
	goto EventScript_AfterWhiteOutHeal
	return


EventScript_NoPMCGameOver_Loop::
	switch VAR_TEMP_9
	case 1, EventScript_NoPMCGameOver_Loop_2
	case 2, EventScript_NoPMCGameOver_Loop_3
	return

EventScript_NoPMCGameOver_Loop_2:
	msgbox EventScript_NoPMCGameOver_Text_4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NoPMCGameOver_Loop_4
	setvar VAR_TEMP_9, 2
	goto EventScript_NoPMCGameOver_Loop
	return

EventScript_NoPMCGameOver_Loop_3:
	msgbox EventScript_NoPMCGameOver_Text_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NoPMCGameOver_Loop_7
	setvar VAR_TEMP_9, 1
	goto EventScript_NoPMCGameOver_Loop
	return

EventScript_NoPMCGameOver_Loop_4:
	msgbox EventScript_NoPMCGameOver_Text_5
	normalmsg
	callnative TurnOffNoPMC
	callnative ResetTintFilter
	goto EventScript_AfterWhiteOutHeal
	return

EventScript_NoPMCGameOver_Loop_7:
	msgbox EventScript_NoPMCGameOver_Text_2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_NoPMCGameOver_Loop_10
	setvar VAR_TEMP_9, 1
	goto EventScript_NoPMCGameOver_Loop
	return

EventScript_NoPMCGameOver_Loop_10:
	msgbox EventScript_NoPMCGameOver_Text_3
	callnative DoSoftReset
	return

EventScript_NoPMCGameOver_Text_0:
	.string "You have no more POKéMON that can\nbattle in your POKéMON PC.\pYou can either reset to the last\ntime you saved, or turn off\lNO FREE HEALS and heal your party.$"

EventScript_NoPMCGameOver_Text_1:
	.string "Would you like to reset to the\nlast save point?$"

EventScript_NoPMCGameOver_Text_2:
	.string "Are you sure?\pYou will lose all progress since\nyou last saved.$"

EventScript_NoPMCGameOver_Text_3:
	.string "The game will now reset.$"

EventScript_NoPMCGameOver_Text_4:
	.string "Would you like to turn off\nNO FREE HEALS and heal your party?$"

EventScript_NoPMCGameOver_Text_5:
	.string "NO FREE HEALS has been turned off.$"
