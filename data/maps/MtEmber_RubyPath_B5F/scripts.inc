MtEmber_RubyPath_B5F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MtEmber_RubyPath_B5F_EventScript_OnLoad
	.byte 0
	
MtEmber_RubyPath_B5F_EventScript_OnLoad::
	goto_if_unset FLAG_GOT_RUBY, MtEmber_RubyPath_B5F_EventScript_PuzzleDoorClosed
	end

MtEmber_RubyPath_B5F_EventScript_PuzzleDoorClosed::
	setmetatile 6, 1, METATILE_MtEmber_Upper_Wall, 1
	setmetatile 7, 1, METATILE_MtEmber_Upper_Wall, 1
	setmetatile 8, 1, METATILE_MtEmber_Upper_Wall, 1
	setmetatile 6, 2, METATILE_MtEmber_Lower_Wall, 1
	setmetatile 7, 2, METATILE_MtEmber_Lower_Wall, 1
	setmetatile 8, 2, METATILE_MtEmber_Lower_Wall, 1
	return
	
MtEmber_RubyPath_B5F_EventScript_Ruby::
	lock
	faceplayer
	setflag FLAG_GOT_RUBY
	clearflag FLAG_HIDE_SCOTT
	removeobject LOCALID_RUBY
	giveitem_msg MtEmber_RubyPath_B3F_Text_FoundARuby, ITEM_RUBY, 1, MUS_OBTAIN_KEY_ITEM
	closemessage
	delay 10
	setmetatile 6, 1, METATILE_MtEmber_CaveDoor1, 1
	setmetatile 7, 1, METATILE_MtEmber_CaveDoor2, 1
	setmetatile 8, 1, METATILE_MtEmber_CaveDoor3, 1
	setmetatile 6, 2, METATILE_MtEmber_CaveDoor4, 1
	setmetatile 7, 2, METATILE_MtEmber_CaveDoor5, 0
	setmetatile 8, 2, METATILE_MtEmber_CaveDoor6, 1
	playse SE_DOOR
	special DrawWholeMapView
	waitse
	release
	end

MtEmber_RubyPath_B5F_EventScript_BrailleMessage::
	lockall
	setvar VAR_0x8005, 130
	braillemessage_wait Braille_Text_Everything
	braillemessage_wait Braille_Text_HasMeaning1
	braillemessage_wait Braille_Text_Existence
	braillemessage_wait Braille_Text_HasMeaning2
	braillemessage_wait Braille_Text_BeingAlive
	braillemessage_wait Braille_Text_HasMeaning3
	braillemessage_wait Braille_Text_HaveDreams
	braillemessage Braille_Text_UsePower
	waitbuttonpress
	releaseall
	end
