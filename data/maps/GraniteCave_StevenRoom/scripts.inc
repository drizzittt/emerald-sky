GraniteCave_StevenRoom_MapScripts::
	.byte 0

GraniteCave_StevenRoom_GreetAndMonologue::
	lockall
	msgbox GraniteCave_StevenRoom_EventScript_HereItWas, MSGBOX_DEFAULT
	closemessage
	delay 8
	faceplayer
	delay 8
	msgbox GraniteCave_StevenRoom_EventScript_AChild, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq  VAR_RESULT, DIR_NORTH, GraniteCave_StevenRoom_ExitLeft
	goto_if_eq  VAR_RESULT, DIR_EAST, GraniteCave_StevenRoom_ExitDown
	goto_if_eq  VAR_RESULT, DIR_WEST, GraniteCave_StevenRoom_ExitRight
	releaseall
	end

GraniteCave_StevenRoom_ExitLeft::
	applymovement LOCALID_STEVEN, GraniteCave_StevenRoom_Movement_ExitLeft
	waitmovement LOCALID_STEVEN
	removeobject LOCALID_STEVEN
	setflag FLAG_HIDE_GRANITE_GRUNTS
	setflag FLAG_HIDE_WINONA_GRANITECAVE
	setflag FLAG_HIDE_BRAWLY_GRANITECAVE
	setvar VAR_DEWFORD_TOWN_STATE, 3
	return

GraniteCave_StevenRoom_ExitDown::
	applymovement LOCALID_STEVEN, GraniteCave_StevenRoom_Movement_ExitDown
	waitmovement LOCALID_STEVEN
	removeobject LOCALID_STEVEN
	setflag FLAG_HIDE_GRANITE_GRUNTS
	setflag FLAG_HIDE_WINONA_GRANITECAVE
	setflag FLAG_HIDE_BRAWLY_GRANITECAVE
	setvar VAR_DEWFORD_TOWN_STATE, 3
	return

GraniteCave_StevenRoom_ExitRight::
	applymovement LOCALID_STEVEN, GraniteCave_StevenRoom_Movement_ExitRight
	waitmovement LOCALID_STEVEN
	removeobject LOCALID_STEVEN
	setflag FLAG_HIDE_GRANITE_GRUNTS
	setflag FLAG_HIDE_WINONA_GRANITECAVE
	setflag FLAG_HIDE_BRAWLY_GRANITECAVE
	setvar VAR_DEWFORD_TOWN_STATE, 3
	return

GranitCave_StevenRoom_EventScript_Wall::
	lockall
	braillemsgbox GraniteCave_BrailleWall
	releaseall
	end

GraniteCave_StevenRoom_EventScript_HereItWas:
	.string "To think this was right here the whole\n"
	.string "time…$"

GraniteCave_StevenRoom_EventScript_AChild:
	.string "A child? You made it past the guards?\n"
	.string "I wonder… The last time I came across\p"
	.string "a child this strong was… No matter. I\n"
	.string "am not in my monologuing stage yet.\p"
	.string "I have what I came for. I will spare you\n"
	.string "this once. I encourage you to get\p"
	.string "stronger and follow. If you are anything\n"
	.string "like the last, you could be quite useful.\p"
	.string "The skies… they are not as eternal as one\n"
	.string "might think. I will change that.$"

GraniteCave_StevenRoom_Movement_ExitLeft:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	step_end

GraniteCave_StevenRoom_Movement_ExitDown:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	step_end

GraniteCave_StevenRoom_Movement_ExitRight:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	step_end
