GraniteCave_B2F_MapScripts::
	.byte 0

GraniteCave_B1F_EventScript_Grunt::
	trainerbattle_single TRAINER_GRUNT_GALE_GRANITE_3, GraniteCave_Text_GruntIntro, GraniteCave_Text_GruntDefeat
	end


GraniteCave_Text_GruntIntro:
	.string "I don't really like caves.\n"
	.string "I can't see the sky at all…$"

GraniteCave_Text_GruntDefeat:
	.string "I lost. Maybe I won't have\n"
	.string "to do cave jobs anymore…$"
