		ORG 	00H
START:
		MOV 	R0,#5		;ѭ����˸5�Σ�������
LOOP:

		MOV 	P1,#0FEH	;�͵�ƽ��������
		CALL	DELAY		;������ʱ�ӳ���
		MOV 	P1,#0FFH 	;�ߵ�ƽ��Ϩ���
		CALL	DELAY		;������ʱ�ӳ���
		DJNZ	R0,LOOP		;R0��1
		JB		P2.0,$		;���P2.0Ϊ�ߵ�ƽѭ��ִ�б���		
		JMP 	START
		
DELAY:	MOV		R3,#50		;��ʱ500ms
D1:		MOV 	R4,#20
D2:		MOV 	R5,#248
		DJNZ 	R5,$
		DJNZ	R4,D2
		DJNZ 	R3,D1
		RET
		END