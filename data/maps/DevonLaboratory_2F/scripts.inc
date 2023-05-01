DevonLaboratory_2F_MapScripts::
	.byte 0

DevonLaboratory_2F_EventScript_TestingEgg::
	lockall
	faceplayer
	msgbox DevonLaboratory_2F_Text_TestingEgg, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

DevonLaboratory_2F_EventScript_Reports::
	lockall
	faceplayer
	msgbox DevonLaboratory_2F_Text_Reports, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

DevonLaboratory_2F_Text_TestingEgg:
	.string "I'm experimenting with a new method\n"
	.string "of hatching eggs. I'm getting close\p"
	.string "to a breakthrough!$"

DevonLaboratory_2F_Text_Reports:
	.string "I'm way behind on my reports.\n"
	.string "I'm going to get in trouble if the\p"
	.string "boss checks up on me.$"