.set LOCALID_ANABEL, 8

TwoIsland_CapeBrink_MapScripts::
	.byte 0

CapeBrink_EventScript_Anabel::
	lock
	faceplayer
	msgbox CapeBrink_Text_Anabel
	closemessage
	applymovement LOCALID_ANABEL, CapeBrink_Movement_AnaLookUp
	waitmovement 0
	msgbox CapeBrink_Text_Anabel2
	closemessage
	applymovement LOCALID_ANABEL, CapeBrink_Movement_AnabelConcentrate
	waitmovement 0
	msgbox CapeBrink_Text_Anabel3
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CapeBrink_Movement_PlayerTell
	waitmovement 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox ThreeIsland_BerryForest_Text_PlayerRelay
	closemessage
	applymovement LOCALID_ANABEL, CapeBrink_Movement_AnabelTalkBack
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox CapeBrink_Text_Anabel4
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ANABEL
	setflag FLAG_HIDE_ANABEL_SECOND
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_HIDE_ANABEL_THIRD
	release
	end
	
CapeBrink_Text_Anabel::
	.string "Ah, you have arrived…\n"
	.string "Unfortunately, I was too late…$"
	
CapeBrink_Text_Anabel2::
	.string "I fail to understand…\p"
	.string "Why was LATIAS so inclined to let\n"
	.string "me touch its forehead, only to\p"
	.string "flee every subsequent encounter?\p"
	.string "Normally, I understand everything\n"
	.string "that happens to and around me.\p"
	.string "But I have never understood\n"
	.string "LATIAS…\p"
	.string "Oh well…\p"
	.string "I will just reveal LATIAS' current\n"
	.string "hiding place to you…$"
	
CapeBrink_Text_Anabel3::
	.string "Exotic POKéMON…\n"
	.string "Somewhere on the mainland…\p"
	.string "I'm sorry…\n"
	.string "It's hard to be any more specific.\p"
	.string "Do you know of any fitting\n"
	.string "locations?$"
	
CapeBrink_Text_Anabel4::
	.string "… … Let us hope you are correct.\n"
	.string "I am certain we will meet again.$"
	
CapeBrink_Movement_AnabelTalkBack::
	faceplayer
	step_end

CapeBrink_Movement_AnaLookUp::
	face_away_player
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	faceplayer
	step_end
	
CapeBrink_Movement_AnabelConcentrate::
	face_away_player
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
	faceplayer
	step_end
	
CapeBrink_Movement_PlayerTell::
	lock_facing_direction
	walk_in_place_up
	unlock_facing_direction
	step_end

CapeBrink_EventScript_Helena::
	trainerbattle_single TRAINER_PKMN_RANGER_HELENA, CapeBrink_Text_HelenaIntro, CapeBrink_Text_HelenaDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq CapeBrink_EventScript_HelenaRematch
	msgbox CapeBrink_Text_HelenaPostBattle, MSGBOX_AUTOCLOSE
	end

CapeBrink_EventScript_HelenaRematch::
	trainerbattle_rematch TRAINER_PKMN_RANGER_HELENA, CapeBrink_Text_HelenaRematchIntro, CapeBrink_Text_HelenaDefeat
	msgbox CapeBrink_Text_HelenaPostBattle, MSGBOX_AUTOCLOSE
	end

CapeBrink_Text_HelenaIntro:
	.string "I'm combing the beach for litter,\n"
	.string "but I guess I can do a quick battle.$"

CapeBrink_Text_HelenaDefeat:
	.string "I'm all washed up!$"

CapeBrink_Text_HelenaPostBattle:
	.string "It's important to keep the oceans\n"
	.string "clear of our trash.\p"
	.string "Try to get things that are reusable\n"
	.string "or refillable so you're throwing\l"
	.string "less stuff away.$"

CapeBrink_Text_HelenaRematchIntro:
	.string "I'm combing the beach for litter,\n"
	.string "but found a TRAINER instead!$"

CapeBrink_EventScript_Atticus::
	trainerbattle_single TRAINER_COOLTRAINER_ATTICUS, CapeBrink_Text_AtticusIntro, CapeBrink_Text_AtticusDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq CapeBrink_EventScript_AtticusRematch
	msgbox CapeBrink_Text_AtticusPostBattle, MSGBOX_AUTOCLOSE
	end

CapeBrink_EventScript_AtticusRematch::
	trainerbattle_rematch TRAINER_COOLTRAINER_ATTICUS, CapeBrink_Text_AtticusRematchIntro, CapeBrink_Text_AtticusDefeat
	msgbox CapeBrink_Text_AtticusPostBattle, MSGBOX_AUTOCLOSE
	end

CapeBrink_Text_AtticusIntro:
	.string "TWO ISLAND has absolutely nothing\n"
	.string "going on…\l"
	.string "Hey, cure my boredom with a battle!$"

CapeBrink_Text_AtticusDefeat:
	.string "…And now I'm bored again…$"

CapeBrink_Text_AtticusPostBattle:
	.string "TRAINERS come here to battle\n"
	.string "each other.\p"
	.string "This island is so sleepy that\n"
	.string "there's not much else to do here.$"

CapeBrink_Text_AtticusRematchIntro:
	.string "…Yawn…\n"
	.string "…So bored…\p"
	.string "Oh, a battle?\n"
	.string "You bet! Bring it on!$"

CapeBrink_EventScript_Deforest::
	trainerbattle_single TRAINER_FISHERMAN_DEFOREST, CapeBrink_Text_DeforestIntro, CapeBrink_Text_DeforestDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq CapeBrink_EventScript_DeforestRematch
	msgbox CapeBrink_Text_DeforestPostBattle, MSGBOX_AUTOCLOSE
	end

CapeBrink_EventScript_DeforestRematch::
	trainerbattle_rematch TRAINER_FISHERMAN_DEFOREST, CapeBrink_Text_DeforestRematchIntro, CapeBrink_Text_DeforestRematchDefeat
	msgbox CapeBrink_Text_DeforestPostBattle, MSGBOX_AUTOCLOSE
	end

CapeBrink_Text_DeforestIntro:
	.string "Ach! Nothing's biting!\p"
	.string "I'll take my frustration out\n"
	.string "on your POKéMON!$"

CapeBrink_Text_DeforestDefeat:
	.string "Like a fish out of water!$"

CapeBrink_Text_DeforestPostBattle:
	.string "These fast-moving currents make it\n"
	.string "impossible to catch fish, but I\l"
	.string "still keep trying.$"

CapeBrink_Text_DeforestRematchIntro:
	.string "You want another battle? Sure,\n"
	.string "it's not like I've hooked anything.$"

CapeBrink_Text_DeforestRematchDefeat:
	.string "Why won't my POLIWHIRL evolve\n"
	.string "into POLITOED?$"

CapeBrink_EventScript_Spedo::
	trainerbattle_single TRAINER_BIRD_KEEPER_SPEDO, CapeBrink_Text_SpedoIntro, CapeBrink_Text_SpedoDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq CapeBrink_EventScript_SpedoRematch
	msgbox CapeBrink_Text_SpedoPostBattle, MSGBOX_AUTOCLOSE
	end

CapeBrink_EventScript_SpedoRematch::
	trainerbattle_rematch TRAINER_BIRD_KEEPER_SPEDO, CapeBrink_Text_SpedoRematchIntro, CapeBrink_Text_SpedoDefeat
	msgbox CapeBrink_Text_SpedoPostBattle, MSGBOX_AUTOCLOSE
	end

CapeBrink_Text_SpedoIntro:
	.string "We may not be able to swim or\n"
	.string "SURF, but my POKéMON sure can FLY!$"

CapeBrink_Text_SpedoDefeat:
	.string "Crash landing!$"

CapeBrink_Text_SpedoPostBattle:
	.string "Even if it's too dangerous to get\n"
	.string "in the water, I still have fun\l"
	.string "hanging out on the beach.$"

CapeBrink_Text_SpedoRematchIntro:
	.string "Can't swim and can't SURF,\n"
	.string "so let's have fun by battling!$"

CapeBrink_EventScript_Caspara::
	trainerbattle_single TRAINER_COOLTRAINER_CASPARA, CapeBrink_Text_CasparaIntro, CapeBrink_Text_CasparaDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq CapeBrink_EventScript_CasparaRematch
	msgbox CapeBrink_Text_CasparaPostBattle, MSGBOX_AUTOCLOSE
	end

CapeBrink_EventScript_CasparaRematch::
	trainerbattle_rematch TRAINER_COOLTRAINER_CASPARA, CapeBrink_Text_CasparaRematchIntro, CapeBrink_Text_CasparaDefeat
	msgbox CapeBrink_Text_CasparaPostBattle, MSGBOX_AUTOCLOSE
	end

CapeBrink_Text_CasparaIntro:
	.string "Hey! You're in my sun!\n"
	.string "Get out of here, kid!$"

CapeBrink_Text_CasparaDefeat:
	.string "Great, now go somewhere else.$"

CapeBrink_Text_CasparaPostBattle:
	.string "The sun is really bad for you,\n"
	.string "especially without sunscreen.\p"
	.string "Sometimes I wonder if tanning\n"
	.string "like this is really worth it.$"

CapeBrink_Text_CasparaRematchIntro:
	.string "You don't have to keep bothering me,\n"
	.string "that chair over there is free.\p"
	.string "Another battle?\n"
	.string "…If it makes you go away, then fine.$"

CapeBrink_EventScript_Sedef::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_SEDEF, CapeBrink_Text_SedefIntro, CapeBrink_Text_SedefDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq CapeBrink_EventScript_SedefRematch
	msgbox CapeBrink_Text_SedefPostBattle, MSGBOX_AUTOCLOSE
	end

CapeBrink_EventScript_SedefRematch::
	trainerbattle_rematch TRAINER_SWIMMER_FEMALE_SEDEF, CapeBrink_Text_SedefRematchIntro, CapeBrink_Text_SedefDefeat
	msgbox CapeBrink_Text_SedefPostBattle, MSGBOX_AUTOCLOSE
	end

CapeBrink_Text_SedefIntro:
	.string "I'm the best SWIMMER in the world!\n"
	.string "Watch me sink your POKéMON!$"

CapeBrink_Text_SedefDefeat:
	.string "Caught in a riptide!$"

CapeBrink_Text_SedefPostBattle:
	.string "I could easily swim in these\n"
	.string "currents, I just prefer lying here.$"

CapeBrink_Text_SedefRematchIntro:
	.string "I'm the best relaxer in the world!\n"
	.string "I'll beat you while snoozing!$"

CapeBrink_EventScript_Tuber::
	msgbox CapeBrink_Text_Tuber, MSGBOX_NPC
	end

CapeBrink_Text_Tuber:
	.string "This beach is famous for attracting\n"
	.string "strong TRAINERS from all over.\p"
	.string "I like watching their battles\n"
	.string "from up here.$"
	