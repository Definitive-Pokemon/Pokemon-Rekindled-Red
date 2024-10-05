EventScript_Questionnaire::
	lockall
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_FillOutQuestionnaire, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_DeclineQuestionnaire
	setvar VAR_0x8004, EASY_CHAT_TYPE_ALTERING_CAVE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	specialvar VAR_0x8008, GetMartClerkObjectId
	textcolor NPC_TEXT_COLOR_MALE
	goto_if_eq VAR_0x8004, 0, EventScript_AlterCave
	goto_if_eq VAR_RESULT, 0, EventScript_DeclineQuestionnaire
	goto_if_eq VAR_RESULT, 1, EventScript_TookQuestionnaire
	end

EventScript_AlterCave::
	msgbox Text_YouKnowThoseWords
	warp MAP_ROUTE103_ALTERINGCAVE, 26, 12
	releaseall
	end

EventScript_DeclineQuestionnaire::
	releaseall
	end

EventScript_TookQuestionnaire::
	applymovement VAR_0x8008, Common_Movement_FaceDown
	waitmovement 0
	msgbox Text_QuestionnaireThankYou
	releaseall
	end
