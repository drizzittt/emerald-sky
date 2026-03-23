GraniteCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_B1F_SetHoleWarp
	.byte 0

GraniteCave_B1F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_GRANITE_CAVE_B2F
	end

GraniteCave_B1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_GALE_GRANITE_1, GraniteCave_Text_Grunt1Intro, GraniteCave_Text_Grunt1Defeat
	end

GraniteCave_B1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_GALE_GRANITE_2, GraniteCave_Text_Grunt2Intro, GraniteCave_Text_Grunt2Defeat
	end


GraniteCave_Text_Grunt1Intro:
	.string "Kids shouldn't be wandering\n"
	.string "around alone!$"

GraniteCave_Text_Grunt1Defeat:
	.string "Maybe you can go by yourself$"

GraniteCave_Text_Grunt2Intro:
	.string "We will expand the sky!!\n"
	.string "No one will stop us!$"

GraniteCave_Text_Grunt2Defeat:
	.string "I may be stopped, but the\n"
	.string "sky won't be!$"
