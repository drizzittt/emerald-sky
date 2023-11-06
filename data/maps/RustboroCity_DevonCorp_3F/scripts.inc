.set LOCALID_DEVON_EMPLOYEE, 2
.set LOCALID_PROF_ALDEN, 4
.set LOCALID_ROXANNE, 3
.set LOCALID_MAXIE, 1

RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	call_if_eq VAR_DEVON_CORP_3F_STATE, 3, RustboroCity_DevonCorp_3F_EventScript_ReturnKey_Position
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ToldComing, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_HeresPlayer, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkAway
	waitmovement 0
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 3, 2
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	turnobject LOCALID_PROF_ALDEN, DIR_NORTH
	msgbox RustboroCity_DevonCorp_3F_Text_AldenGreets1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAXIE, Devon_3F_Move_MaxieGreets
	waitmovement 16
	msgbox RustboroCity_DevonCorp_3F_Text_AldenGreets2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROXANNE, Devon_3F_Move_RoxanneGreets
	waitmovement 16
	msgbox DevonCorp_3F_Text_AldenReceive, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, ITEM_PACKAGE
	call Common_EventScript_PlayerHandedOverTheItem
	applymovement LOCALID_PROF_ALDEN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox DevonCorp_3F_Text_AldenExplain, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROXANNE, RustboroCity_DevonCorp_3F_move_RoxannetoPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox RustboroCity_DevonCorp_3F_Text_RoxanneGym, MSGBOX_DEFAULT
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox RustboroCity_DevonCorp_3F_Text_Maxie, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROXANNE, RustboroCity_DevonCorp_3F_move_RoxanneLeave
	waitmovement 0
	removeobject LOCALID_ROXANNE
	setflag FLAG_HIDE_ROXANNE_DEVON
	msgbox RustboroCity_DevonCorP_3F_Text_MaxieGo, MSGBOX_DEFAULT
	closemessage
	@@LEFT OFF MODDING HERE
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setflag FLAG_HIDE_RUSTBOROGYM_BLOCKER
	releaseall
	end

RustboroCity_DevonCorp_3F_EventScript_ReturnKey_Position::
	setobjectxyperm LOCALID_PROF_ALDEN, 15, 7
	setobjectmovementtype LOCALID_PROF_ALDEN, MOVEMENT_TYPE_FACE_UP
	end

RustboroCity_DevonCorp_3F_EventScript_Alden_Main::
	goto_if_eq VAR_DEVON_CORP_3F_STATE, 1, RustboroCity_DevonCorp_3F_EventScript_GoodLuck
	goto_if_eq VAR_DEVON_CORP_3F_STATE, 2, RustboroCity_DevonCorp_3F_EventScript_ReturnKey
	goto_if_eq VAR_DEVON_CORP_3F_STATE, 3, RustboroCity_DevonCorp_3F_EventScript_GoodLuck
	end

RustboroCity_DevonCorp_3F_EventScript_ReturnKey::
	lockall
	faceplayer
	msgbox RustboroCity_DevonCorp_3F_Text_AldenKey, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, ITEM_KEYSTONE
	call Common_EventScript_PlayerHandedOverTheItem
	applymovement LOCALID_PROF_ALDEN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_AldenKey_Cont, MSGBOX_DEFAULT
	closemessage
	msgbox RustboroCity_DevonCorp_3F_Text_MaxieKey, MSGBOX_DEFAULT
	closemessage
	msgbox RustboroCity_DevonCorp_3F_Text_AldenCont, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_RARE_CANDY
	msgbox RustboroCity_DevonCorp_3F_Text_AldenGiveReward, MSGBOX_DEFAULT
	closemessage
	setvar VAR_DEVON_CORP_3F_STATE, 3
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
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
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkAway:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	@walk_up
	@walk_left
	@walk_left
	@face_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	step_end

Devon_3F_Move_MaxieGreets:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

Devon_3F_Move_RoxanneGreets:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

RustboroCity_DevonCorp_3F_move_RoxannetoPlayer:
	walk_left
	walk_left
	walk_up
	walk_up
	face_right
	step_end

RustboroCity_DevonCorp_3F_move_RoxanneLeave:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_eq VAR_DEVON_CORP_3F_STATE, 3, RustboroCity_DevonCorp_3F_EventScript_GoodLuck
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GoodLuck::
	msgbox RustboroCity_DevonCorp_3F_Text_GoodLuck, MSGBOX_DEFAULT
	closemessage
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_GoodLuck, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_AldenGreets1:
	.string "Prof Alden: So you're {PLAYER}. May\n"
	.string "told me about you. Welcome to Devon\p"
	.string "Corp! This is Maxie, President of Devon$"

RustboroCity_DevonCorp_3F_Text_AldenGreets2:
	.string "and this is Roxanne, the local Gym Leader.$"

DevonCorp_3F_Text_AldenReceive:
	.string "...\p"
	.string "What's this about a package from May?$"

DevonCorp_3F_Text_AldenExplain:
	.string "Prof Alden: ..! How did she find..?!\n"
	.string "Maxie, Roxanne, this is exactly\p"
	.string "what we were looking for!\p"
	.string "Roxanne: Wow, that's good timing!\p"
	.string "Maxie: So we can actually find\n"
	.string" them?\p"
	.string "Prof Alden: Yes, and I think we have\n"
	.string "found someone to help us!\p"
	.string "{PLAYER}, as you know, twenty years\n"
	.string "ago Groudon and Kyogre\p"
	.string "went on a rampage and were only\n"
	.string "calmed by Rayquaza, with the help of\p"
	.string "the champion. Well, Rayquaza\n"
	.string "has disappeared. We fear Kyogre and\p"
	.string "Groudon will awaken and nothing will be\n"
	.string "able to stop them. Their past rampaging\p"
	.string "has greatly affected Hoenn, destroying\n"
	.string "sites, uncovering lost caves and areas,\p"
	.string "making new ones, and, of course,\n"
	.string "attracting new Pokémon.\p"
	.string "Maxie: Some of these are good things,\n"
	.string "but there was a lot of destruction.\p"
	.string "We believe we have uncovered the site\n"
	.string "of the legendary Oldale Ruins.\p"
	.string "Roxanne: Prof Alden believes these ruins\n"
	.string "hold secrets important to finding\p"
	.string "Rayquaza and preventing more\n"
	.string "destruction.\p"
	.string "Prof Alden: I know they do! We just need\n"
	.string "the keys to unlock them! What you have\p"
	.string "just delivered is a map of sorts to\n"
	.string "track them down, and the first aligns\p"
	.string "with my suspicions! It's nearby, in\n"
	.string "the recently uncovered area of\p"
	.string "Rusturf Tunnel!\p"
	.string "{PLAYER}, will you help us retrieve this\n"
	.string "key?\p"
	.string "...\p"
	.string "Prof Alden: Excellent! Thank you!$"

RustboroCity_DevonCorp_3F_Text_RoxanneGym:
	.string "Roxanne: I would recommend you take on\n"
	.string "my Gym first to make sure your\p"
	.string "Pokémon are strong enough. There's no\n"
	.string "telling what you'll run into out there.\p"
	.string "Speaking of which, I need to head back.\n"
	.string "I've been out a while now and don't want\p"
	.string "to miss challengers.$"
	
RustboroCity_DevonCorp_3F_Text_Maxie:
	.string "Maxie: That's an excellent idea!\n"
	.string "Thank you for being here Roxanne.$"

RustboroCity_DevonCorP_3F_Text_MaxieGo:
	.string "{PLAYER}, please return here once you\n"
	.string "have whatever is in that tunnel, and\p"
	.string "good luck out there.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "MR. STONE: Now, you should know that\n"
	.string "I am a great PRESIDENT.\p"
	.string "So, I'd never be so cheap as to ask\n"
	.string "a favor for nothing in return.\p"
	.string "That's why I want you to have this!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} received a POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "MR. STONE: That device…\p"
	.string "It's a POKéMON NAVIGATOR, or POKéNAV\n"
	.string "for short.\p"
	.string "It's an indispensable tool for any\n"
	.string "TRAINER on an adventure.\p"
	.string "It has a map of the HOENN region.\p"
	.string "You can check the locations of\n"
	.string "DEWFORD and SLATEPORT easily!\p"
	.string "By the way, I've heard that sinister\n"
	.string "criminals--MAGMA and AQUA, I believe--\l"
	.string "have been making trouble far and wide.\p"
	.string "I think it would be best if you rested\n"
	.string "up before you go on your way.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "MR. STONE: Well, then, {PLAYER}{KUN},\n"
	.string "go with caution and care!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "Maxie: We're counting on you!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "MR. STONE: You delivered my LETTER?\n"
	.string "Thank you kindly!\p"
	.string "This is my way of thanking you.\n"
	.string "It should help you, a TRAINER.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "MR. STONE: A POKéMON holding that\n"
	.string "EXP. SHARE will be given some of the\l"
	.string "EXP Points from battle.\p"
	.string "It will get EXP Points even if it didn't\n"
	.string "actually battle.\p"
	.string "I would say EXP. SHARE is quite useful\n"
	.string "for raising weak POKéMON.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "MR. STONE: Since my youth, I've immersed\n"
	.string "myself in work.\p"
	.string "Consequently, I'm not familiar with\n"
	.string "trends and that sort of thing.\p"
	.string "But do young people all want to be\n"
	.string "TRAINERS in the POKéMON LEAGUE?$"

RustboroCity_DevonCorp_3F_Text_ToldComing:
	.string "This is the Devon Corporation's\n"
	.string "third floor.\p"
	.string "Do you have an appointment..?\n"
	.string "...\p"
	.string "Ah, {PLAYER}, they buzzed up and said\n"
	.string "you were coming. Right this way.$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Our PRESIDENT would like to have\n"
	.string "a word with you.\p"
	.string "Please come with me.$"

RustboroCity_DevonCorp_3F_Text_HeresPlayer:
	.string "Here is {PLAYER}, from Prof. May.$"

RustboroCity_DevonCorp_3F_Text_GoodLuck:
	.string "Good luck out there.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "DEVON's new products, the REPEAT BALL\n"
	.string "and TIMER BALL, have become hugely\l"
	.string "popular among TRAINERS.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "It's a collection of rare rocks and\n"
	.string "stones assembled by the PRESIDENT.$"

RustboroCity_DevonCorp_3F_Text_AldenKey:
	.string "Prof Alden: {PLAYER}! Were\n"
	.string "you successful?!\p"
	.string ".....$"

RustboroCity_DevonCorp_3F_Text_AldenKey_Cont:
	.string "Prof Alden: That's wonderful! I\n"
	.string "can't believe it! We actually\p"
	.string "have a Keystone! Maxie, this\n"
	.string "proves I'm right!$"

RustboroCity_DevonCorp_3F_Text_MaxieKey:
	.string "Maxie: I appreciate your enthusiasm\n"
	.string "Professor, but this hardly proves\p"
	.string "everything you've been saying.\n"
	.string "We still need the two other keys\n"
	.string "and to locate the ruins themselves.$"

RustboroCity_DevonCorp_3F_Text_AldenCont:
	.string "Prof Alden: Yes, of course. I'm\n"
	.string "close to the ruins though. If only\p"
	.string "your short-tenured predecessor\n"
	.string "hadn't stolen my research on his\p"
	.string "way out! Steven could cost everyone\n"
	.string "everything, the madman!\p"
	.string "Anyways, {PLAYER}, thank you for\n"
	.string "your help! I'm certain I'll have\p"
	.string "more work for you in the future.\n"
	.string "In the meantime, take this.$"

RustboroCity_DevonCorp_3F_Text_AldenGiveReward:
	.string "Prof Alden:\n"
	.string "I highly recommend you carry\p"
	.string "on with the gym challenge.\n"
	.string "You seem to have great aptitude\p"
	.string "as a Trainer, and I have a\n"
	.string "feeling you'll need all the\p"
	.string "strength you can get if these\n"
	.string "Gale Force people you mentioned\p"
	.string "are after the keys as well!\n"
	.string "I believe Brawly in Dewford\p"
	.string "is still the second leader.\n"
	.string "I'll get ahold of you if anything\p"
	.string "comes up. Good luck out there!$"
