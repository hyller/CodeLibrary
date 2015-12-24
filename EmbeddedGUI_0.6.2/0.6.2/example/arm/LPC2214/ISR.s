I_Bit	  EQU 0x00000080

UART_LSR  EQU 0xE000C014
UART_IER  EQU 0xE000C004
UART_THR  EQU 0xE000C000
UART_IIR  EQU 0xE000C008

I2C_STAT 	 EQU 0xE001C004
I2C_CONSET	 EQU 0xE001C000
I2C_DATA  	 EQU 0xE001C008
I2C_CONCLR	 EQU 0xE001C018

		EXPORT ABORT_CODE

		AREA ISR_MEM,DATA,READWRITE
ABORT_CODE   SPACE 4 
ABORT_ADDR   SPACE 4

		EXPORT Undefine_ISR
		EXPORT SWI_ISR
		EXPORT PAbt_ISR
		EXPORT DAbt_ISR
		EXPORT FIQ_ISR

		PRESERVE8
		AREA ISR,CODE,READONLY		
Undefine_ISR
		STMFD SP!,{R0,R1}
		SUB R0,LR,#4
		LDR R1,=ABORT_ADDR
		STR R0,[R1]
		LDR R0,[LR,#-4]
		LDR R1,=ABORT_CODE
		STR R0,[R1]
		LDMFD SP!,{R0,R1}
		MOVS PC,LR
SWI_ISR
		STMFD SP!,{R0,R1,LR}
		LDR R1,[LR,#-4]
		LDR R0,=0x00FFFFFF
		AND R0,R0,R1
		LDMFD SP!,{R0,R1,PC}^
PAbt_ISR
		STMFD SP!,{R0,R1}
		SUB R0,LR,#4
		LDR R1,=ABORT_ADDR
		STR R0,[R1]
		LDR R0,[LR,#-4]
		LDR R1,=ABORT_CODE
		STR R0,[R1]
		LDMFD SP!,{R0,R1}
		SUBS PC,LR,#4
DAbt_ISR
		STMFD SP!,{R0,R1}
		SUB R0,LR,#8
		LDR R1,=ABORT_ADDR
		STR R0,[R1]
		LDR R0,[LR,#-8]
		LDR R1,=ABORT_CODE
		STR R0,[R1]
		LDMFD SP!,{R0,R1}
		SUBS PC,LR,#8


		EXPORT Default_vIRQ_ISR 

Default_vIRQ_ISR
		SUB LR,LR,#4 ; Adjust LR to point to return
		STMFD SP!,{R0-R4,LR} ; Get some free regs
		MRS LR, SPSR ; See if we got an interrupt while
		TST LR, #I_Bit ; interrupts were disabled.
		LDMNEFD SP!,{R0-R4,PC}^ ; If so, just return immediately.
								; The interrupt will remain pending since we haven¡¯t
								; acknowledged it and will be reissued when interrupts
								; are next enabled.
		LDR PC,=0xFFFFF030; Rest of interrupt routine

FIQ_ISR
		SUBS PC,R14,#4




		END
