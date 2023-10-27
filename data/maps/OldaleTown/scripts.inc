.set LOCALID_MART_EMPLOYEE, 2
.set LOCALID_RIVAL, 3

OldaleTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
	.byte 0

OldaleTown_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_VISITED_OLDALE_TOWN
	@call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_BlockWestEntrance
	call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_MoveMartEmployee
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
	end

@ This script seems pointless because nothing uses VAR_OLDALE_TOWN_STATE
OldaleTown_EventScript_SetOldaleState::
	setvar VAR_OLDALE_TOWN_STATE, 1
	return

@OldaleTown_EventScript_BlockWestEntrance::
@	setobjectxyperm LOCALID_FOOTPRINTS_MAN, 1, 11
@	setobjectmovementtype LOCALID_FOOTPRINTS_MAN, MOVEMENT_TYPE_FACE_LEFT
@	return

OldaleTown_EventScript_MoveMartEmployee::
	setobjectxyperm LOCALID_MART_EMPLOYEE, 13, 14
	setobjectmovementtype LOCALID_MART_EMPLOYEE, MOVEMENT_TYPE_FACE_DOWN
	return

OldaleTown_EventScript_TownSign::
	msgbox OldaleTown_Text_TownSign, MSGBOX_SIGN
	end

OldaleTown_EventScript_Girl::
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
	end

OldaleTown_EventScript_MartEmployee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_ExplainPotion
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_ExplainPotion
	setflag FLAG_TEMP_1
	playbgm MUS_FOLLOW_ME, FALSE
	msgbox OldaleTown_Text_IWorkAtPokemonMart, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, OldaleTown_EventScript_GoToMartSouth
	case DIR_NORTH, OldaleTown_EventScript_GoToMartNorth
	case DIR_EAST, OldaleTown_EventScript_GoToMartEast
	end

OldaleTown_EventScript_GoToMartSouth::
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeSouth
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerSouth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartNorth::
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeNorth
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerNorth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartEast::
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerEast
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeEast
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_ExplainPokemonMart::
	msgbox OldaleTown_Text_ThisIsAPokemonMart, MSGBOX_DEFAULT
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_EventScript_BagIsFull
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_POTION_OLDALE
	fadedefaultbgm
	release
	end

OldaleTown_EventScript_ExplainPotion::
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

OldaleTown_Movement_EmployeeEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_EmployeeSouth:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_EmployeeNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_Unknown1:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_PlayerEast:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerSouth:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_Unknown2:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_EventScript_Rival::
	lockall
	addobject LOCALID_RIVAL
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCALID_RIVAL, Step_Rival_intoScene_Movement_Oldale
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8009, 1, OldaleTown_EventScript_RivalApproachPlayer1
	call_if_eq VAR_0x8009, 2, OldaleTown_EventScript_RivalApproachPlayer2
	call_if_eq VAR_0x8009, 3, OldaleTown_EventScript_RivalApproachPlayer3
	call_if_eq VAR_0x8009, 4, OldaleTown_EventScript_RivalApproachPlayer4
	msgbox Rival_Challenge1, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, Oldale_EventScript_StartMayBattleTreecko
	case 1, Oldale_EventScript_StartMayBattleTorchic
	case 2, Oldale_EventScript_StartMayBattleMudkip
	end

OldaleTown_EventScript_RivalTrigger1::
	lockall
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_Rival

OldaleTown_EventScript_RivalTrigger2::
	lockall
	setvar VAR_0x8009, 2
	goto OldaleTown_EventScript_Rival

OldaleTown_EventScript_RivalTrigger3::
	lockall
	setvar VAR_0x8009, 3
	goto OldaleTown_EventScript_Rival

OldaleTown_EventScript_RivalTrigger4::
	lockall
	setvar VAR_0x8009, 4
	goto OldaleTown_EventScript_Rival

OldaleTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

OldaleTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

OldaleTown_EventScript_RivalApproachPlayer3::
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer3
	waitmovement 0
	return

OldaleTown_EventScript_RivalApproachPlayer4::
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer4
	waitmovement 0
	return

Rival_Challenge1:
	.string "Hi, {PLAYER}!\n"
	.string "My mom finally gave you a pokemon!?\p"
	.string "That means we have to battle!$"

Oldale_EventScript_StartMayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Oldale_Text_MayDefeated
	goto Oldale_EventScript_AfterMayBattle
	end

Oldale_EventScript_StartMayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Oldale_Text_MayDefeated
	goto Oldale_EventScript_AfterMayBattle
	end

Oldale_EventScript_StartMayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Oldale_Text_MayDefeated
	goto Oldale_EventScript_AfterMayBattle
	end

Oldale_EventScript_StartBrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Oldale_Text_BrendanDefeated
	goto Oldale_EventScript_AfterBrendanBattle
	end

Oldale_EventScript_StartBrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Oldale_Text_BrendanDefeated
	goto Oldale_EventScript_AfterBrendanBattle
	end

Oldale_EventScript_StartBrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Oldale_Text_BrendanDefeated
	goto Oldale_EventScript_AfterBrendanBattle
	end

Oldale_EventScript_AfterMayBattle::
	msgbox Oldale_Text_MayReallyGood, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 10
	call_if_eq VAR_RESULT, FALSE, Oldale_EventScript_MayNoRoomForPokeBalls
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox Oldale_Text_MayTimetoHeadBack, MSGBOX_DEFAULT
	goto Oldale_EventScript_RivalExit
	end

Oldale_EventScript_AfterBrendanBattle::
	msgbox Oldale_Text_BrendanReallyGood, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 10
	call_if_eq VAR_RESULT, FALSE, Oldale_EventScript_BrendanNoRoomForPokeBalls
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox Oldale_Text_BrendanTimetoHeadBack, MSGBOX_DEFAULT
	goto Oldale_EventScript_RivalExit
	end

Oldale_EventScript_MayNoRoomForPokeBalls::
	msgbox Oldale_Text_OhYourBagsFull, MSGBOX_DEFAULT
	return

Oldale_EventScript_BrendanNoRoomForPokeBalls::
	msgbox Oldale_Text_HeyYourBagsFull, MSGBOX_DEFAULT
	return

Oldale_EventScript_RivalExit::
	call_if_eq VAR_0x8009, 1, OldaleTown_EventScript_RivalExit1
	call_if_eq VAR_0x8009, 2, OldaleTown_EventScript_RivalExit2
	call_if_eq VAR_0x8009, 3, OldaleTown_EventScript_RivalExit3
	call_if_eq VAR_0x8009, 4, OldaleTown_EventScript_RivalExit4
	end

OldaleTown_EventScript_RivalExit1::
	applymovement LOCALID_RIVAL, RivalExit_Oldale1
	waitmovement 0
	goto Oldale_EventScript_RivalEnd
	releaseall
	end

OldaleTown_EventScript_RivalExit2::
	applymovement LOCALID_RIVAL, RivalExit_Oldale2
	waitmovement 0
	goto Oldale_EventScript_RivalEnd
	releaseall
	end

OldaleTown_EventScript_RivalExit3::
	applymovement LOCALID_RIVAL, RivalExit_Oldale3
	waitmovement 0
	goto Oldale_EventScript_RivalEnd
	end

OldaleTown_EventScript_RivalExit4::
	applymovement LOCALID_RIVAL, RivalExit_Oldale4
	waitmovement 0
	goto Oldale_EventScript_RivalEnd
	releaseall
	end

Oldale_EventScript_RivalEnd::
	removeobject LOCALID_RIVAL
	setvar VAR_BIRCH_LAB_STATE, 4
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setvar VAR_OLDALE_RIVAL_STATE, 1
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Oldale_Text_MayDefeated:
	.string "Wow! That’s great!\n"
	.string "{PLAYER}{KUN}, you’re pretty good!$"

Oldale_Text_BrendanDefeated:
	.string "Wow! That’s great!\n"
	.string "{PLAYER}{KUN}, you’re pretty good!$"

Oldale_Text_MayReallyGood:
	.string "Wow, you’re really good!\n"
	.string "I didn’t expect that since this is your\p"
	.string "first pokemon. I’ll be sure to tell my mom.\n"
	.string "I’m excited to see what you do with more\p"
	.string "Pokemon! Here, take these!$"

Oldale_Text_MayTimetoHeadBack:
	.string "I’d better head back though. Mom said\p"
	.string "she had something for me to do. Bye!$"

Oldale_Text_BrendanReallyGood:
	.string "Wow, you’re really good!\n"
	.string "I didn’t expect that since this is your\p"
	.string "first pokemon. I’ll be sure to tell my mom.\n"
	.string "I’m excited to see what you do with more\p"
	.string "Pokemon! Here, take these!$"

Oldale_Text_BrendanTimetoHeadBack:
	.string "I’d better head back though. Mom said\p"
	.string "she had something for me to do. Bye!$"

Oldale_Text_OhYourBagsFull:
	.string "Oh? Your Bag’s full.$"

Oldale_Text_HeyYourBagsFull:
	.string "Hey! Your Bag’s full.$"

Step_Rival_intoScene_Movement_Oldale:
	walk_down
	walk_down
	step_end

OldaleTown_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_down
	step_end

OldaleTown_Movement_RivalApproachPlayer2:
	walk_down
	walk_down
	step_end

OldaleTown_Movement_RivalApproachPlayer3:
	walk_down
	walk_right
	walk_down
	step_end

OldaleTown_Movement_RivalApproachPlayer4:
	walk_down
	walk_right
	walk_right
	walk_down
	step_end

RivalExit_Oldale1:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RivalExit_Oldale2:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RivalExit_Oldale3:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RivalExit_Oldale4:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OldaleTown_Movement_PlayerStepBack:
	delay_8
	walk_right
	step_end

OldaleTown_Movement_BackUp:
	walk_fast_up
	walk_in_place_faster_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

OldaleTown_Movement_ReturnToOriginalPosition:
	walk_down
	walk_left
	step_end

OldaleTown_Text_SavingMyProgress:
	.string "I want to take a rest, so I’m saving my\n"
	.string "progress.$"

OldaleTown_Text_IWorkAtPokemonMart:
	.string "Hi!\n"
	.string "I work at a POKéMON MART.\p"
	.string "Can I get you to come with me?$"

OldaleTown_Text_ThisIsAPokemonMart:
	.string "This is a POKéMON MART.\n"
	.string "Just look for our blue roof.\p"
	.string "We sell a variety of goods including\n"
	.string "POKé BALLS for catching POKéMON.\p"
	.string "Here, I’d like you to have this as\n"
	.string "a promotional item.$"

OldaleTown_Text_PotionExplanation:
	.string "A POTION can be used anytime, so it’s\n"
	.string "even more useful than a Pokémon Center\l"
	.string "in certain situations.$"

OldaleTown_Text_TownSign:
	.string "Oldale Town\n"
	.string "“Where things start off scarce!”$"
