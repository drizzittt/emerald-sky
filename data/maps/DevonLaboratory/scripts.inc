DevonLaboratory_MapScripts::
	.byte 0

DevonLaboratory_EventScript_DontBotherMe::
	lockall
	faceplayer
	msgbox DevonLaboratory_Text_DontBotherMe, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

DevonLaboratory_EventScript_Laptop::
	lockall
	faceplayer
	msgbox DevonLaboratory_Text_Laptop, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

DevonLaboratory_Text_DontBotherMe:
	.string "Please don't bother me right now.\n"
	.string "I really need to focus on these\p"
	.string "experiments.$"

DevonLaboratory_Text_Laptop:
	.string "I'm working on a new type of computer\n"
	.string "that you can carry around with you!\p"
	.string "I call it a Laptop!$"
