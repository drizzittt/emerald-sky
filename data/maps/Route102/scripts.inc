.set LOCALID_RIVAL, 10

Route102_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route102_OnTransition
	.byte 0

Route102_OnTransition::
	call Common_EventScript_SetupRivalGfxId
	end

Route102_EventScript_LittleBoy::
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignRoute102::
	msgbox Route102_Text_RouteSignRoute102, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg::
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy::
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Rival::
	lockall
	addobject LOCALID_RIVAL
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCALID_RIVAL, Step_Rival_intoScene_Movement_Route102
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8009, 1, Route102_EventScript_RivalApproachPlayer1
	call_if_eq VAR_0x8009, 2, Route102_EventScript_RivalApproachPlayer2
	msgbox Rival_Challenge1, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, Route102_EventScript_StartMayBattleTreecko
	case 1, Route102_EventScript_StartMayBattleTorchic
	case 2, Route102_EventScript_StartMayBattleMudkip
	end

Route102_EventScript_RivalTrigger1::
	lockall
	setvar VAR_0x8009, 1
	goto Route102_EventScript_Rival
	end

Route102_EventScript_RivalTrigger2::
	lockall
	setvar VAR_0x8009, 2
	goto Route102_EventScript_Rival
	end

Route102_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, Route102_Movement_RivalApproachPlayer1
	waitmovement 0
	return

Route102_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, Route102_Movement_RivalApproachPlayer2
	waitmovement 0
	return

Rival_Challenge1:
	.string "Hi, {PLAYER}!\n"
	.string "My mom finally gave you a pokemon!?\p"
	.string "That means we have to battle!$"

Route102_EventScript_StartMayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route102_Text_MayDefeated
	goto Route102_EventScript_AfterMayBattle
	end

Route102_EventScript_StartMayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route102_Text_MayDefeated
	goto Route102_EventScript_AfterMayBattle
	end

Route102_EventScript_StartMayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route102_Text_MayDefeated
	goto Route102_EventScript_AfterMayBattle
	end

Route102_EventScript_StartBrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route102_Text_BrendanDefeated
	goto Route102_EventScript_AfterBrendanBattle
	end

Route102_EventScript_StartBrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route102_Text_BrendanDefeated
	goto Route102_EventScript_AfterBrendanBattle
	end

Route102_EventScript_StartBrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route102_Text_BrendanDefeated
	goto Route102_EventScript_AfterBrendanBattle
	end

Route102_EventScript_AfterMayBattle::
	msgbox Route102_Text_MayReallyGood, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 10
	call_if_eq VAR_RESULT, FALSE, Route102_EventScript_MayNoRoomForPokeBalls
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox Route102_Text_MayTimetoHeadBack, MSGBOX_DEFAULT
	goto Route102_EventScript_RivalExit
	end

Route102_EventScript_AfterBrendanBattle::
	msgbox Route102_Text_BrendanReallyGood, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 10
	call_if_eq VAR_RESULT, FALSE, Route102_EventScript_BrendanNoRoomForPokeBalls
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox Route102_Text_BrendanTimetoHeadBack, MSGBOX_DEFAULT
	goto Route102_EventScript_RivalExit
	end

Route102_EventScript_MayNoRoomForPokeBalls::
	msgbox Route102_Text_OhYourBagsFull, MSGBOX_DEFAULT
	return

Route102_EventScript_BrendanNoRoomForPokeBalls::
	msgbox Route102_Text_HeyYourBagsFull, MSGBOX_DEFAULT
	return

Route102_EventScript_RivalExit::
	call_if_eq VAR_0x8009, 1, Route102_EventScript_RivalExit1
	call_if_eq VAR_0x8009, 2, Route102_EventScript_RivalExit2
	end

Route102_EventScript_RivalExit1::
	applymovement LOCALID_RIVAL, RivalExit_Route1021
	waitmovement 0
	goto Route102_EventScript_RivalEnd
	releaseall
	end

Route102_EventScript_RivalExit2::
	applymovement LOCALID_RIVAL, RivalExit_Route1022
	waitmovement 0
	goto Route102_EventScript_RivalEnd
	releaseall
	end

Route102_EventScript_RivalEnd::
	removeobject LOCALID_RIVAL
	setvar VAR_BIRCH_LAB_STATE, 4
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setvar VAR_OLDALE_RIVAL_STATE, 1
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route102_Text_MayDefeated:
	.string "Wow! That’s great!\n"
	.string "{PLAYER}{KUN}, you’re pretty good!$"

Route102_Text_BrendanDefeated:
	.string "Wow! That’s great!\n"
	.string "{PLAYER}{KUN}, you’re pretty good!$"

Route102_Text_MayReallyGood:
	.string "Wow, you’re really good!\n"
	.string "I didn’t expect that since this is your\p"
	.string "first pokemon. I’ll be sure to tell my mom.\n"
	.string "I’m excited to see what you do with more\p"
	.string "Pokemon! Here, take these!$"

Route102_Text_MayTimetoHeadBack:
	.string "I’d better head back though. Mom said\n"
	.string "she had something for me to do. Bye!$"

Route102_Text_BrendanReallyGood:
	.string "Wow, you’re really good!\n"
	.string "I didn’t expect that since this is your\p"
	.string "first pokemon. I’ll be sure to tell my mom.\n"
	.string "I’m excited to see what you do with more\p"
	.string "Pokemon! Here, take these!$"

Route102_Text_BrendanTimetoHeadBack:
	.string "I’d better head back though. Mom said\n"
	.string "she had something for me to do. Bye!$"

Route102_Text_OhYourBagsFull:
	.string "Oh? Your Bag’s full.$"

Route102_Text_HeyYourBagsFull:
	.string "Hey! Your Bag’s full.$"

Step_Rival_intoScene_Movement_Route102:
	walk_right
	walk_right
	step_end

Route102_Movement_RivalApproachPlayer1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route102_Movement_RivalApproachPlayer2:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	step_end

RivalExit_Route1021:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RivalExit_Route1022:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route102_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall::
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister::
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_WatchMeCatchPokemon:
	.string "WALLY: {PLAYER}…\n"
	.string "POKéMON hide in tall grass like this,\l"
	.string "don't they?\p"
	.string "Please watch me and see if I can\n"
	.string "catch one properly.\p"
	.string "…Whoa!$"

Route102_Text_WallyIDidIt:
	.string "WALLY: I did it… It's my…\n"
	.string "My POKéMON!$"

Route102_Text_LetsGoBack:
	.string "{PLAYER}, thank you!\n"
	.string "Let's go back to the GYM!$"

Route102_Text_ImNotVeryTall:
	.string "I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

Route102_Text_CatchWholeBunchOfPokemon:
	.string "I'm going to catch a whole bunch of\n"
	.string "POKéMON!$"

Route102_Text_RouteSignRoute102:
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} Route102 TOWN$"

Route102_Text_RouteSignOldale:
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} OLDALE TOWN$"

Route102_Text_RouteSignPetalburg:
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} PETALBURG CITY$"
