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
	goto_if_eq VAR_DEWFORD_TOWN_STATE, 1, GraniteCave_1F_EventScript_HikerScared
	goto_if_eq VAR_DEWFORD_TOWN_STATE, 2, GraniteCave_1F_EventScript_HikerScaredShare
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_HikerScaredShare::
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	release
	end

GraniteCave_1F_EventScript_HikerScared::
	msgbox GraniteCave_1F_Text_HikerScared, MSGBOX_DEFAULT
	closemessage
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "That guy who came by earlier…\n"
	.string "STEVEN, I think it was.\p"
	.string "He knew how to use FLASH, so he ought\n"
	.string "to be all right, but…\p"
	.string "Well, for us HIKERS, helping out those\n"
	.string "that we meet is our motto.\p"
	.string "Here you go, I'll pass this on to you.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Teach that hidden move FLASH to\n"
	.string "a POKéMON and use it.\p"
	.string "It lights up even the inky darkness\n"
	.string "of caves.\p"
	.string "But, to use it, you need the GYM BADGE\n"
	.string "from DEWFORD's POKéMON GYM.$"

GraniteCave_1F_Text_HikerScaredShare:
	.string "Hey, if you're going to keep going\n"
	.string "You'll need Flash. It gets awfully\p"
	.string "dark ahead!$"

GraniteCave_1F_Text_HikerScared:
	.string "I have no idea what's going on\n"
	.string "here, but I am staying far from\p"
	.string "that battle!$"

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
