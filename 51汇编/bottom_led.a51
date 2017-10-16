		ORG 	00H
START:
		MOV 	R0,#5		;循环闪烁5次，计数器
LOOP:

		MOV 	P1,#0FEH	;低电平，点亮灯
		CALL	DELAY		;调用延时子程序
		MOV 	P1,#0FFH 	;高电平，熄灭灯
		CALL	DELAY		;调用延时子程序
		DJNZ	R0,LOOP		;R0减1
		JB		P2.0,$		;如果P2.0为高电平循环执行本行		
		JMP 	START
		
DELAY:	MOV		R3,#50		;延时500ms
D1:		MOV 	R4,#20
D2:		MOV 	R5,#248
		DJNZ 	R5,$
		DJNZ	R4,D2
		DJNZ 	R3,D1
		RET
		END