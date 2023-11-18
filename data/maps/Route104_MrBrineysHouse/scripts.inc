.set LOCALID_BRAWLY, 1
.set LOCALID_BRINEY, 2

Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition:
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	end

Route104_MrBrineysHouse_Trigger_Brawly1::
	lock
	msgbox Route104_MrBrineysHouse_Text_BrawlyDeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRAWLY, Route104_MrBrineysHouse_Movement_BrawlyExit1
	waitmovement 0
	msgbox Route104_MrBrineysHouse_Text_BrawlyTrainer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRAWLY, Route104_MrBrineysHouse_Movement_BrawlyLeave1
	waitmovement 0
	removeobject LOCALID_BRAWLY
	setflag FLAG_HIDE_BRINEYS_HOUSE_BRAWLY
	setvar VAR_BRINEY_HOUSE_STATE, 1
	release
	end

Route104_MrBrineysHouse_Trigger_Brawly2::
	lock
	msgbox Route104_MrBrineysHouse_Text_BrawlyDeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRAWLY, Route104_MrBrineysHouse_Movement_BrawlyExit2
	waitmovement 0
	msgbox Route104_MrBrineysHouse_Text_BrawlyTrainer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRAWLY, Route104_MrBrineysHouse_Movement_BrawlyLeave2
	waitmovement 0
	removeobject LOCALID_BRAWLY
	setflag FLAG_HIDE_BRINEYS_HOUSE_BRAWLY
	setvar VAR_BRINEY_HOUSE_STATE, 1
	release
	end

Route104_MrBrineysHouse_Trigger_Brawly3::
	lock
	msgbox Route104_MrBrineysHouse_Text_BrawlyDeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRAWLY, Route104_MrBrineysHouse_Movement_BrawlyExit3
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox Route104_MrBrineysHouse_Text_BrawlyTrainer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRAWLY, Route104_MrBrineysHouse_Movement_BrawlyLeave3
	waitmovement 0
	removeobject LOCALID_BRAWLY
	setflag FLAG_HIDE_BRINEYS_HOUSE_BRAWLY
	setvar VAR_BRINEY_HOUSE_STATE, 1
	release
	end

Route104_MrBrineysHouse_Trigger_Brawly4::
	lock
	msgbox Route104_MrBrineysHouse_Text_BrawlyDeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRAWLY, Route104_MrBrineysHouse_Movement_BrawlyExit4
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox Route104_MrBrineysHouse_Text_BrawlyTrainer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BRAWLY, Route104_MrBrineysHouse_Movement_BrawlyLeave4
	waitmovement 0
	removeobject LOCALID_BRAWLY
	setflag FLAG_HIDE_BRINEYS_HOUSE_BRAWLY
	setvar VAR_BRINEY_HOUSE_STATE, 1
	release
	end

Route104_MrBrineysHouse_EventScript_Briney::
	lock
	faceplayer
	msgbox Route104_MrBrineysHouse_Text_Briney
	closemessage
	release
	end

Route104_MrBrineysHouse_Text_BrawlyDeal:
	.string "I had a great deal of respect for your\n"
	.string "father. I'm glad we could come to an\p"
	.string "agreement we both think would honor him,\n"
	.string "and benefit us both. I look forward\p"
	.string "to working with you!$"

Route104_MrBrineysHouse_Text_BrawlyTrainer:
	.string "Ah, what good timing! A young trainer\n"
	.string "perhaps to be the first passenger!\p"
	.string "Come see me at the Gym when you get\n"
	.string "to Dewford!$"

Route104_MrBrineysHouse_Text_Briney:
	.string "So you're here trying to get to\n"
	.string "Dewford? Well you'll have to come back\p"
	.string "later. I only just signed the crummy\n"
	.string "deal, I still have to finish setting up.\p"
	.string "Maybe go checkout Rustboro if you\n"
	.string "haven't yet. Even if you have, get out\p"
	.string "of here and go check again. I'm not\n"
	.string "ready yet!$"

Route104_MrBrineysHouse_Movement_BrawlyExit1:
	walk_left
	walk_down
	step_end

Route104_MrBrineysHouse_Movement_BrawlyLeave1:
	walk_right
	walk_down
	walk_down
	step_end

Route104_MrBrineysHouse_Movement_BrawlyExit2:
	walk_down
	step_end

Route104_MrBrineysHouse_Movement_BrawlyLeave2:
	walk_left
	walk_down
	walk_down
	step_end

Route104_MrBrineysHouse_Movement_BrawlyExit3:
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

Route104_MrBrineysHouse_Movement_BrawlyLeave3:
	face_down
	step_end

Route104_MrBrineysHouse_Movement_BrawlyExit4:
	walk_down
	walk_down
	walk_down
	face_right
	step_end

Route104_MrBrineysHouse_Movement_BrawlyLeave4:
	face_down
	step_end
