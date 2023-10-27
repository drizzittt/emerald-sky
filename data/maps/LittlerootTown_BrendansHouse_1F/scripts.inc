.set LOCALID_MOM, 1
@.set LOCALID_RIVAL_MOM, 4
@.set LOCALID_RIVAL, 7

LittlerootTown_BrendansHouse_1F_MapScripts::
	@map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	@map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
@	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

@LittlerootTown_BrendansHouse_1F_OnLoad:
@	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, 
@	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
@	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerEnterFirst::
	lockall
	pokenavcall PlayerHouse_1F_Text_MayPokenavCall
	waitmessage
	closemessage
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_ENABLE_MOM_MATCH_CALL
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_MomApproach
	waitmovement 0
	msgbox PlayersHouse_1F_Text_MomGiveBag, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	msgbox PlayersHouse_1F_ExplainRunningShoes, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_MOM_START_STATE, 0, MoveMom_to_Table
	setvar VAR_MOM_START_STATE, 1
	releaseall
	end

@LittlerootTown_BrendansHouse_1F_EventScript_MomMoves1::
@
@	return

LittlerootTown_BrendansHouse_1F_EventScript_PlayerEnterFirst_2::
	lockall
	pokenavcall PlayerHouse_1F_Text_MayPokenavCall
	waitmessage
	closemessage
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_MomApproach_2
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox PlayersHouse_1F_Text_MomGiveBag, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	msgbox PlayersHouse_1F_ExplainRunningShoes, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_MOM_START_STATE, 0, MoveMom_to_Table_2
	setvar VAR_MOM_START_STATE, 1
	releaseall
	end

	LittlerootTown_BrendansHouse_1F_EventScript_PlayerEnterFirst_3::
	lockall
	pokenavcall PlayerHouse_1F_Text_MayPokenavCall
	waitmessage
	closemessage
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_MomApproach_3
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox PlayersHouse_1F_Text_MomGiveBag, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	msgbox PlayersHouse_1F_ExplainRunningShoes, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_MOM_START_STATE, 0, MoveMom_to_Table_3
	setvar VAR_MOM_START_STATE, 1
	releaseall
	end

MoveMom_to_Table::
	applymovement LOCALID_MOM, PlayersHouse_1F_Movement_MomtoTable
	waitmovement 0
	setvar VAR_MOM_START_STATE, 1
	releaseall
	return

MoveMom_to_Table_2::
	applymovement LOCALID_MOM, PlayersHouse_1F_Movement_MomtoTable_2
	waitmovement 0
	setvar VAR_MOM_START_STATE, 1
	releaseall
	return

MoveMom_to_Table_3::
	applymovement LOCALID_MOM, PlayersHouse_1F_Movement_MomtoTable_3
	waitmovement 0
	setvar VAR_MOM_START_STATE, 1
	releaseall
	return

@PlayerEnters1F_EventScript::


LittlerootTown_BrendansHouse_1F_Movement_MomApproach:
	delay_8
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_MomApproach_2:
	delay_8
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_MomApproach_3:
	delay_8
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

PlayersHouse_1F_Movement_MomtoTable:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	face_right
	step_end

PlayersHouse_1F_Movement_MomtoTable_2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	face_right
	step_end

PlayersHouse_1F_Movement_MomtoTable_3:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	face_right
	step_end

PlayerHouse_1F_Text_MayPokenavCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "May: Hi, {PLAYER}!\p"
	.string "… … … … … …\n"
	.string "I need you to meet me at my\l"
	.string "lab as soon as you can,\p"
	.string "I have a task for you!\n"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

PlayersHouse_1F_Text_MomGiveBag:
	.string "Wow, she sure seemed in a hurry.\p"
	.string "You'd better get your shoes on\n"
	.string "and head out. Here you go!$"

PlayersHouse_1F_Text_SwitchShoesWithRunningShoes:
	.string "{PLAYER} switched shoes with the\n"
	.string "running shoes.$"

PlayersHouse_1F_ExplainRunningShoes:
	.string "I just bought those for you yesterday.\p"
	.string "The manual says 'hold B to run'\n"
	.string "I'm not sure where this B you're\p"
	.string "meant to hold is though.\n"
	.string "Maybe just try running normally?\p"
	.string "Anyways, you'd better be off.$"

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

@LittlerootTown_BrendansHouse_1F_OnTransition:
@	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
@	end

@LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
@	setobjectxyperm LOCALID_MOM, 8, 4
@	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
@	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
@LittlerootTown_BrendansHouse_1F_OnFrame:
	@map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	@.2byte 0

PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "MOM: See, {PLAYER}?\n"
	.string "Isn't it nice in here, too?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "The mover's POKéMON do all the work\n"
	.string "of moving us in and cleaning up after.\l"
	.string "This is so convenient!\p"
	.string "{PLAYER}, your room is upstairs.\n"
	.string "Go check it out, dear!\p"
	.string "DAD bought you a new clock to mark\n"
	.string "our move here.\l"
	.string "Don't forget to set it!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "MOM: Well, {PLAYER}?\p"
	.string "Aren't you interested in seeing your\n"
	.string "very own room?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MOM: {PLAYER}.\p"
	.string "Go set the clock in your room, honey.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MOM: Oh! {PLAYER}, {PLAYER}!\n"
	.string "Quick! Come quickly!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MOM: Look! It's PETALBURG GYM!\n"
	.string "Maybe DAD will be on!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MOM: Oh… It's over.\p"
	.string "I think DAD was on, but we missed him.\n"
	.string "Too bad.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "Oh, yes.\n"
	.string "One of DAD's friends lives in town.\p"
	.string "PROF. BIRCH is his name.\p"
	.string "He lives right next door, so you should\n"
	.string "go over and introduce yourself.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MOM: See you, honey!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "MOM: Did you introduce yourself to\n"
	.string "PROF. BIRCH?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MOM: How are you doing, {PLAYER}?\n"
	.string "You look a little tired.\p"
	.string "I think you should rest a bit.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MOM: Take care, honey!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "Mom: Oh? Did DAD give you that BADGE?\p"
	.string "Then here's something from your MOM!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Don't push yourself too hard, dear.\n"
	.string "You can always come home.\p"
	.string "Go for it, honey!$"

PlayerHouse_1F_Text_GoSeeMay:
	.string "You'd better and go see Professor\p"
	.string "May. She seemed in a hurry.$"

PlayersHouse_1F_Text_NewPokemon:
	.string "Mom: The Prof gave you a Pokemon?\n"
	.string "I supppose that means you're off on\p"
	.string "an adventure. Remember you can always\n"
	.string "come home. Now, you had better rest\p"
	.string "before heading out.$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MOM: What is that, honey? A POKéNAV?\n"
	.string "Someone from DEVON gave it to you?\p"
	.string "Well, honey, how about registering\n"
	.string "your mom?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "Registered MOM\n"
	.string "in the POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "INTERVIEWER: …We brought you this\n"
	.string "report from in front of PETALBURG GYM.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "There is a movie on TV.\p"
	.string "Two men are dancing on a big piano\n"
	.string "keyboard.\p"
	.string "Better get going!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "It's the instruction booklet for the\n"
	.string "RUNNING SHOES.\p"
	.string "“Press the B Button to run while\n"
	.string "wearing your RUNNING SHOES.\p"
	.string "“Lace up your RUNNING SHOES and hit\n"
	.string "the road running!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "DAD: Hm?\p"
	.string "Hey, it's {PLAYER}!\p"
	.string "It's been a while since I saw you,\n"
	.string "but you look…stronger, somehow.\p"
	.string "That's the impression I get.\n"
	.string "But your old man hasn't given up yet!\p"
	.string "Oh, yes, I have something for you.\n"
	.string "This came to you from someone named\l"
	.string "MR. BRINEY.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "DAD: Hm, a TICKET for a ferry?\p"
	.string "If I recall, there are ferry ports in\n"
	.string "SLATEPORT and LILYCOVE.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "I'd better get back to PETALBURG GYM.\p"
	.string "MOM, thanks for looking after the house\n"
	.string "while I'm away.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MOM: That DAD of yours…\p"
	.string "He comes home for the first time in a\n"
	.string "while, but all he talks about is POKéMON.\p"
	.string "He should relax and stay a little longer.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MOM: Is that a breaking news story?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "We bring you this emergency\n"
	.string "news flash!\p"
	.string "In various HOENN locales, there have\n"
	.string "been reports of a BZZT…colored\l"
	.string "POKéMON in flight.\p"
	.string "The identity of this POKéMON is\n"
	.string "currently unknown.\p"
	.string "We now return you to the regular\n"
	.string "movie program.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MOM: {PLAYER}, did you catch that?\p"
	.string "What color did the announcer say\n"
	.string "that POKéMON was?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MOM: Well, isn't that something!\n"
	.string "There are still unknown POKéMON.$"
