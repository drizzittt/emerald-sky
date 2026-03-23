.set LOCALID_HIKER, 1

GraniteCave_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GraniteCave_1F_OnTransition
	.byte 0

GraniteCave_1F_OnTransition:
	call_if_eq VAR_DEWFORD_TOWN_STATE, 1, GraniteCave_1F_EventScript_SetHikerPos
	call_if_eq VAR_DEWFORD_TOWN_STATE, 2, GraniteCave_1F_EventScript_SetHikerPos
	end

GraniteCave_1F_EventScript_SetHikerPos::
	setobjectxyperm LOCALID_HIKER, 34, 7
	setobjectmovementtype LOCALID_HIKER, MOVEMENT_TYPE_FACE_DOWN
	return

GraniteCave_1F_EventScript_BattleDirect::
	goto_if_eq VAR_DEWFORD_TOWN_STATE, 1, GraniteCave_1F_EventScript_Battle
	goto_if_eq VAR_DEWFORD_TOWN_STATE, 2, GraniteCave_1F_EventScript_Go
	end

GraniteCave_1F_EventScript_TriggerLeft::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto GraniteCave_1F_EventScript_Battle
	end

GraniteCave_1F_EventScript_TriggerRight::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto GraniteCave_1F_EventScript_Battle
	end

GraniteCave_1F_EventScript_Battle::
	lockall
	msgbox GraniteCave_1F_Text_WinonaHere, MSGBOX_DEFAULT
	closemessage
	msgbox GraniteCave_1F_Text_WinonaReply, MSGBOX_DEFAULT
	closemessage
	msgbox GraniteCave_1F_Text_HoldHer, MSGBOX_DEFAULT
	closemessage
	setvar VAR_DEWFORD_TOWN_STATE, 2
	releaseall
	end

GraniteCave_1F_EventScript_Go::
	msgbox GraniteCave_1F_Text_Go
	closemessage
	end

GraniteCave_1F_EventScript_Winona::
	msgbox GraniteCave_1F_EventScript_GoAhead, MSGBOX_DEFAULT
	closemessage
	end

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_eq VAR_DEWFORD_TOWN_STATE, 1, GraniteCave_1F_Hiker_BrawlyAndWinona
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GraniteCave_EventScript_BattleHiker
	msgbox GraniteCave_1F_Text_NoFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Hiker_BrawlyAndWinona::
	msgbox GraniteCave_1F_Text_GetsDarkDontCare, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GraniteCave_EventScript_BattleHiker
	release
	end

GraniteCave_EventScript_BattleHiker::
	trainerbattle_single TRAINER_DILBERT, GraniteCave_1F_Hiker_Text_Intro, GraniteCave_1F_Hiker_Text_Defeat, Hiker_Defeated_Script
	end

Hiker_Defeated_Script::
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Here I've been passing out Flash HM's\n"
	.string "for near twenty years. Do I ever get\p"
	.string "a thank you? No. I don't. If you want\n"
	.string "one you can battle me for it. I don't\p"
	.string "feel like being so generous anymore!$"

GraniteCave_1F_Text_GetsDarkDontCare:
	.string "Battling in my spot, young fools!\p"
	.string "Here I've been passing out Flash HM's\n"
	.string "for near twenty years. Do I ever get\p"
	.string "a thank you? No. I don't. If you want\n"
	.string "one you can battle me for it. I don't\p"
	.string "feel like being so generous anymore!$"

GraniteCave_1F_Text_NoFlash:
	.string "Ah, what do I care? Go get lost in\n"
	.string "in the cave! I won't be helping.$"

GraniteCave_1F_Hiker_Text_Intro:
	.string "Young punk!$"

GraniteCave_1F_Hiker_Text_Defeat:
	.string "Fine! Take the thing then!$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Just use it and you can see!\n"
	.string "Need the Dewford badge though.\p"
	.string "Now get out of here.$"

GraniteCave_1F_Text_WinonaHere:
	.string "Brawly: Winona?! What are you\n"
	.string "doing here?$"

GraniteCave_1F_Text_WinonaReply:
	.string "Winona: Brawly, this is bigger\n"
	.string "than you could understand. Please\p"
	.string "don't interfere. I don't want to\n"
	.string "have to hurt you$"

GraniteCave_1F_Text_HoldHer:
	.string "Brawly: I can't let you disrupt\n"
	.string "nature here. Come with me peacefully\p"
	.string "or you'll find out how much I've\n"
	.string "trained firsthand. {PLAYER}, you\p"
	.string "keep going. I'll deal with her!$"

GraniteCave_1F_Text_Go:
	.string "Go, I've got this!$"

GraniteCave_1F_EventScript_GoAhead:
	.string "Go ahead, you won't get far.$"
