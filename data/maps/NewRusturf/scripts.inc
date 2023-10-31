.set LOCALID_GALE_GRUNT_1, 4
.set LOCALID_GALE_GRUNT, 5

NewRusturf_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NewRusturf_OnLoad
	.byte 0

NewRusturf_OnLoad::
	end

RusturfTunnel_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_NEWRUSTURF_1, RusturfTunnel_Text_Grunt1Intro, RusturfTunnel_Text_Grunt1Defeat
	end

RusturfTunnel_EventScript_Grunt::
	trainerbattle_single TRAINER_GRUNT_RUSTURF_TUNNEL, RusturfTunnel_Text_GruntIntro, RusturfTunnel_Text_GruntDefeat, Grunt_Defeated_Script
	end

Grunt_Defeated_Script::
	lockall
	msgbox GRUNT_DEFEATED, MSGBOX_DEFAULT
	closemessage
	goto Grunt_Push_Player
	end

Grunt_Push_Player::
	applymovement OBJ_EVENT_ID_PLAYER, GRUNT_PUSH_PLAYER_MOVEMENT
	waitmovement 0
	goto Grunt_Exit_Script
	end

Grunt_Exit_Script::
	applymovement LOCALID_GALE_GRUNT, GRUNT_EXIT_MOVEMENT
	waitmovement 0
	removeobject LOCALID_GALE_GRUNT
	setflag FLAG_HIDE_NEWRUSTURF_GRUNTS
	setvar VAR_DEVON_CORP_3F_STATE, 3
	releaseall
	end

RusturfTunnel_Text_Grunt1Intro:
	.string "Hey! what are you doing? You're\n"
	.string "not supposed to be here!$"

RusturfTunnel_Text_GruntIntro:
	.string "You think you can stop the very\n"
	.string "winds? Gale Force is here, and we\p"
	.string "will reclaim the skies!!$"

RusturfTunnel_Text_Grunt1Defeat:
	.string "You at least shouldn't be\n"
	.string "so strong…$"

RusturfTunnel_Text_GruntDefeat:
	.string "NO! My first real mission…\n"
	.string "The boss won't like this.\p"
	.string "I won't let this be the end of it!$"

GRUNT_DEFEATED:
	.string "I'll make you pay next time!$"

GRUNT_PUSH_PLAYER_MOVEMENT:
	jump_left
	step_end

GRUNT_EXIT_MOVEMENT:
	walk_left
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
