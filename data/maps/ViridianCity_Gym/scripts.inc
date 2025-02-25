.set LOCALID_GIOVANNI, 8
.set LOCALID_DAISY, 11

ViridianCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ViridianCity_Gym_EventScript_DaisyCheck
	.byte 0

ViridianCity_Gym_EventScript_DaisyCheck::
	call_if_set FLAG_DAISY_READY, ViridianCity_Gym_EventScript_ShowDaisy
	end

ViridianCity_Gym_EventScript_ShowDaisy::
	addobject LOCALID_DAISY
	clearflag FLAG_HIDE_DAISY
	end

ViridianCity_Gym_EventScript_Daisy::
	lock
	faceplayer
	goto_if_set FLAG_BEAT_DAISY, ViridianCity_Gym_EventScript_AfterDaisy
	trainerbattle_single TRAINER_LEADER_DAISY, ViridianCity_Gym_Text_DaisyIntro, ViridianCity_Gym_Text_DaisyDefeat, ViridianCity_Gym_EventScript_DefeatedDaisy, NO_MUSIC
	settrainerflag TRAINER_LEADER_DAISY
	release
	end

ViridianCity_Gym_EventScript_DefeatedDaisy::
	msgbox ViridianCity_Gym_Text_DaisyPostBattle
	closemessage
	setflag FLAG_BEAT_DAISY
	setflag FLAG_HIDE_SILVER_SCIENTIST
	setflag FLAG_HIDE_DAISY
	clearflag FLAG_DAISY_READY
        setflag FLAG_HIDE_CAVE_BALL
	setvar VAR_MT_SILVER_ACCESS, 1
	end

ViridianCity_Gym_EventScript_AfterDaisy::
	lock
	faceplayer
	msgbox ViridianCity_Gym_Text_DaisyAfterBattle
	closemessage
	release
	end

ViridianCity_Gym_Text_DaisyIntro::
	.string "I knew you'd come, {PLAYER}.\n"
	.string "I'm sure you didn't expect this.\p"
	.string "I've been a TRAINER since before\n"
	.string "you and {RIVAL} were born!\p"
	.string "When Grandpa told me what happened\n"
	.string "here between you and GIOVANNI,\l"
	.string "I just couldn't help myself…\p"
	.string "I had to pick up battling again!\p"
	.string "This town needs to be protected\n"
	.string "from evildoers like GIOVANNI.\p"
	.string "You made me realize that I could\n"
	.string "do something about all of this…\l"
	.string "… just like you and {RIVAL}!\p"
	.string "And so, I began training my\n"
	.string "POKéMON again.\p"
	.string "Then, I applied for the position of\n"
	.string "the VIRIDIAN CITY GYM LEADER.\p"
	.string "That's right.\n"
	.string "I'm a GYM LEADER now!\p"
	.string "{PLAYER}…\p"
	.string "I challenge you to take me on!$"

ViridianCity_Gym_Text_DaisyDefeat::
	.string "So this is what they meant…$"

ViridianCity_Gym_Text_DaisyPostBattle::
	.string "You've grown so much, {PLAYER}!\p"
	.string "I wish I could give you another\n"
	.string "GYM BADGE, but you already have\l"
	.string "the one from this GYM, right?\p"
	.string "Don't worry, I can help you in\n"
	.string "a different way.\p"
	.string "Do you know about the gate west\n"
	.string "of ROUTE 22?\p"
	.string "Most TRAINERS are not allowed to\n"
	.string "pass through that gate…\p"
	.string "… but as a GYM LEADER, I can order\n"
	.string "the guards to let you pass.\p"
	.string "Beyond lie places and challenges that\n"
	.string "will absolutely excite you.\p"
	.string "I'll pay them a visit!$"

ViridianCity_Gym_Text_DaisyAfterBattle::
	.string "After informing the ROUTE 22 guards,\n"
	.string "I'll be returning to PALLET TOWN.\p"
	.string "Just know you are always welcome\n"
	.string "to pay me a visit!$"

ViridianCity_Gym_EventScript_Giovanni::
	famechecker FAMECHECKER_GIOVANNI, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	callnative IsChallengeModeToVarResult
	goto_if_eq VAR_RESULT, TRUE, ViridianCity_Gym_EventScript_Giovanni_ChallengeMode
	trainerbattle_single TRAINER_LEADER_GIOVANNI, ViridianCity_Gym_Text_GiovanniIntro, ViridianCity_Gym_Text_GiovanniDefeat, ViridianCity_Gym_EventScript_DefeatedGiovanni, NO_MUSIC
	settrainerflag TRAINER_LEADER_GIOVANNI_CHALLENGE
	goto ViridianCity_Gym_EventScript_GiveTM26
	end

ViridianCity_Gym_EventScript_Giovanni_ChallengeMode::
	trainerbattle_single TRAINER_LEADER_GIOVANNI_CHALLENGE, ViridianCity_Gym_Text_GiovanniIntro, ViridianCity_Gym_Text_GiovanniDefeat, ViridianCity_Gym_EventScript_DefeatedGiovanni, NO_MUSIC
	settrainerflag TRAINER_LEADER_GIOVANNI
	goto ViridianCity_Gym_EventScript_GiveTM26
	end

ViridianCity_Gym_EventScript_DefeatedGiovanni::
	famechecker FAMECHECKER_GIOVANNI, 3
	setflag FLAG_HIDE_MISC_KANTO_ROCKETS
	setflag FLAG_DEFEATED_LEADER_GIOVANNI
	setflag FLAG_BADGE08_GET
	setvar VAR_MAP_SCENE_ROUTE22, 3
	set_gym_trainers 8
	goto ViridianCity_Gym_EventScript_GiveTM26
	end

ViridianCity_Gym_EventScript_GiveTM26::
	msgbox ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis
	giveitem_msg ViridianCity_Gym_Text_ReceivedTM26FromGiovanni, ITEM_TM26
	setflag FLAG_GOT_TM26_FROM_GIOVANNI
	msgbox ViridianCity_Gym_Text_ExplainTM26
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_GIOVANNI
	fadescreen FADE_FROM_BLACK
	release
	end

ViridianCity_Gym_EventScript_Jason::
	trainerbattle_single TRAINER_TAMER_JASON, ViridianCity_Gym_Text_JasonIntro, ViridianCity_Gym_Text_JasonDefeat
	msgbox ViridianCity_Gym_Text_JasonPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Cole::
	trainerbattle_single TRAINER_TAMER_COLE, ViridianCity_Gym_Text_ColeIntro, ViridianCity_Gym_Text_ColeDefeat
	msgbox ViridianCity_Gym_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Atsushi::
	trainerbattle_single TRAINER_BLACK_BELT_ATSUSHI, ViridianCity_Gym_Text_AtsushiIntro, ViridianCity_Gym_Text_AtsushiDefeat
	msgbox ViridianCity_Gym_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Kiyo::
	trainerbattle_single TRAINER_BLACK_BELT_KIYO, ViridianCity_Gym_Text_KiyoIntro, ViridianCity_Gym_Text_KiyoDefeat
	msgbox ViridianCity_Gym_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Takashi::
	trainerbattle_single TRAINER_BLACK_BELT_TAKASHI, ViridianCity_Gym_Text_TakashiIntro, ViridianCity_Gym_Text_TakashiDefeat
	msgbox ViridianCity_Gym_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Samuel::
	trainerbattle_single TRAINER_COOLTRAINER_SAMUEL, ViridianCity_Gym_Text_SamuelIntro, ViridianCity_Gym_Text_SamuelDefeat
	msgbox ViridianCity_Gym_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Yuji::
	trainerbattle_single TRAINER_COOLTRAINER_YUJI, ViridianCity_Gym_Text_YujiIntro, ViridianCity_Gym_Text_YujiDefeat
	msgbox ViridianCity_Gym_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Warren::
	trainerbattle_single TRAINER_COOLTRAINER_WARREN, ViridianCity_Gym_Text_WarrenIntro, ViridianCity_Gym_Text_WarrenDefeat
	msgbox ViridianCity_Gym_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_GIOVANNI, ViridianCity_Gym_EventScript_GymGuyPostVictory
	msgbox ViridianCity_Gym_Text_GymGuyAdvice
	release
	end

ViridianCity_Gym_EventScript_GymGuyPostVictory::
	famechecker FAMECHECKER_GIOVANNI, 4
	msgbox ViridianCity_Gym_Text_GymGuyPostVictory
	release
	end

ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end
