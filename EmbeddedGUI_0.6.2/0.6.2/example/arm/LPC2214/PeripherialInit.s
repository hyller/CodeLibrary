
; VIC
;------------------------------------------------------------
; VIC register setting 
VIC_InterruptProtectionAddr  EQU    0xFFFFF020
VIC_InterruptProtectionVal   EQU    0x00000001

VIC_InterruptClearAddr		 EQU    0xFFFFF014

VIC_InterruptEnableAddr      EQU    0xFFFFF010
VIC_InterruptEnableVal       EQU    0x00000020;disable all the interrupt
; 0x00012270	   ; FPO ,I2C  , RTC , UART0 , TIMER0/1 

VIC_InterruptSelectAddr      EQU    0xFFFFF00C
VIC_InterruptSelectVal       EQU    0x00000000 ;disable FIQ
;0x00010000    ;	 set the FPO as FIQ

;set the vector-IRQ 
VIC_vectInterrputSlot0SAddr   EQU    0xFFFFF200	
VIC_vectInterrputSlot1SAddr   EQU    0xFFFFF204	 
VIC_vectInterrputSlot2SAddr   EQU    0xFFFFF208	 
VIC_vectInterrputSlot3SAddr   EQU    0xFFFFF20C	 
VIC_vectInterrputSlot4SAddr   EQU    0xFFFFF210	
  
VIC_vectInterrputSlot0SVal    EQU    0x00000025		      ;   Timer1   as  slot0
VIC_vectInterrputSlot1SVal    EQU    0x00000026	 		  ;   UART0    as  slot1
VIC_vectInterrputSlot2SVal    EQU    0x00000024	 		  ;   Timer0   as  slot2
VIC_vectInterrputSlot3SVal    EQU    0x00000029	 		  ;   I2C   as  slot3
VIC_vectInterrputSlot4SVal    EQU    0x0000002D	  		  ;   RTC   as  slot4	

		   	IMPORT Default_vIRQ_ISR

VIC_vectInterrputSlot0AAddr  EQU    0xFFFFF100	  
VIC_vectInterrputSlot1AAddr  EQU    0xFFFFF104	  
VIC_vectInterrputSlot2AAddr  EQU    0xFFFFF108	  
VIC_vectInterrputSlot3AAddr  EQU    0xFFFFF10C	 
VIC_vectInterrputSlot4AAddr  EQU    0xFFFFF110	 	

;VIC_vectInterrputSlot0AVal  EQU    TIMER1_vIRQ_ISR	  ;   Timer1   as  slot0
;VIC_vectInterrputSlot1AVal  EQU    UART0_vIRQ_ISR	  ;   UART0    as  slot1
;VIC_vectInterrputSlot2AVal  EQU    TIMER0_vIRQ_ISR	  ;   Timer0   as  slot2
;VIC_vectInterrputSlot3AVal  EQU    I2C_vIRQ_ISR	  ;   I2C   as  slot3
;VIC_vectInterrputSlot4AVal  EQU    RTC_vIRQ_ISR	  ;   RTC   as  slot4	
	
VIC_vectInterrputDefISRAddr	EQU    0xFFFFF034

;UART
;------------------------------------------------------------
UART_EXT_BAUD_SETTING   EQU     0

UART_LineControlAddr 	EQU     0xE000C00C
UART_LineControlVal	    EQU     0x1B

; set the baud rate as 38400   crystal oscillator 11.0592MHz
;   As to 38400      U0DLM  0    U0DLL  5A    DivVal  0    MulVal   0
UART_DivideLowAddr    	EQU		0xE000C000
UART_DivideLowVal    	EQU		0x5A
UART_DivideLowExtVal   	EQU		0x47
UART_DivideHighAddr    	EQU		0xE000C004
UART_DivideHighVal  	EQU		0x00
UART_DivideHighExtVal  	EQU		0x00

UART_FractionDivideAddr EQU     0xE000C028
UART_FractionDivideVal  EQU     0x000000E5

UART_FIFOControlAddr    EQU		0xE000C008
UART_FIFOControlVal     EQU		0x47		  ;  4chars trigger	  enable FIFO

UART_InterruptEnableAddr EQU    0xE000C004
UART_InterruptEnableVal  EQU    0x05		  ;Enable 2 interrupts

UART_DataAddr           EQU     0xE000C000

;Power Control
;----------------------------------------------------------
;power control register
PCONP_ADDR  EQU         0xE01FC0C4
PCONP_VAL	EQU			0x00000A8E

;GPIO
;----------------------------------------------------------
;GPIO setting 
GPIO_PORT0_BASE		   EQU		 0xE0028000

GPIO_PORT0_DIR_ADDR    EQU    	 0xE0028008
GPIO_PORT0_SET_ADDR    EQU       0xE0028004
GPIO_PORT0_CLR_ADDR    EQU       0xE002800C
GPIO_PORT0_DIR_VAL     EQU    	 0x00000000
GPIO_PORT0_SET_VAL     EQU       0x00000040
GPIO_PORT0_CLR_VAL     EQU       0x7B00BE00

GPIO_PORT1_BASE		   EQU		 0xE0028010

GPIO_PORT1_DIR_ADDR    EQU    	 0xE0028018
GPIO_PORT1_SET_ADDR    EQU       0xE0028014
GPIO_PORT1_CLR_ADDR    EQU       0xE002801C
GPIO_PORT1_DIR_VAL     EQU    	 0x00000000	  
GPIO_PORT1_SET_VAL     EQU       0x00010000
GPIO_PORT1_CLR_VAL     EQU       0x03C00000

GPIO_PORT2_BASE		   EQU		 0xE0028020

GPIO_PORT2_DIR_ADDR    EQU    	 0xE0028028
GPIO_PORT2_SET_ADDR    EQU       0xE0028024
GPIO_PORT2_CLR_ADDR    EQU       0xE002802C
GPIO_PORT2_DIR_VAL     EQU    	 0x00000000
GPIO_PORT2_SET_VAL     EQU       0x00010000
GPIO_PORT2_CLR_VAL     EQU       0x01E00000

GPIO_PORT3_BASE		   EQU		 0xE0028030

GPIO_PORT3_DIR_ADDR    EQU    	 0xE0028038
GPIO_PORT3_SET_ADDR    EQU       0xE0028034
GPIO_PORT3_CLR_ADDR    EQU       0xE002803C
GPIO_PORT3_DIR_VAL     EQU    	 0x00000000
GPIO_PORT3_SET_VAL     EQU       0x20000000
GPIO_PORT3_CLR_VAL     EQU       0x00000000


            PRESERVE8
            AREA    PERI_INIT, CODE, READONLY

			EXPORT PERIPHERIAL_INIT

; Initialise peripherials System
PERIPHERIAL_INIT
				; Initialise Interrupt System
				LDR     R0,=VIC_InterruptClearAddr		  ;clear all the interrupts.
				LDR     R1,=0xFFFFFFF
				STR     R1,[R0]		
											   
				LDR     R0,=VIC_InterruptSelectAddr 	   
				LDR     R1,=VIC_InterruptSelectVal
				STR     R1,[R0]				  ;	   select the FIQ

				LDR     R0,= VIC_InterruptProtectionAddr
				LDR     R1,= VIC_InterruptProtectionVal
				STR     R1,[R0]						; Protect the VIC at the user mode

				LDR     R0,=VIC_vectInterrputSlot0SAddr
				LDR     R1,=VIC_vectInterrputSlot0SVal
				STR     R1,[R0]
									  									  
				LDR     R0,= VIC_vectInterrputDefISRAddr
				LDR     R1,= Default_vIRQ_ISR
				STR     R1,[R0]						; set the default ISR address

				LDR     R0,= VIC_InterruptEnableAddr
				LDR     R1,= VIC_InterruptEnableVal	   ;
				STR     R1,[R0]						; Disable all the interrupts 

				; set the fast GPIO with mask
		;		LDR     R0,=CSC_ADDR
		;		LDR     R1,=CSC_VAL
		;		STR     R1,[R0]

				;   set the state of GPIO
				LDR     R0,=GPIO_PORT0_BASE
				LDR     R1,=GPIO_PORT0_DIR_VAL
				STR     R1,[R0,#0x08]	 ;  GPIO_PORT0_DIR_ADDR
				LDR     R1,=GPIO_PORT0_SET_VAL
				STR     R1,[R0,#0x04]		; GPIO_PORT0_SET_ADDR
				LDR     R1,=GPIO_PORT0_CLR_VAL
				STR     R1,[R0,#0x0C]		 ;GPIO_PORT0_CLR_ADDR

				LDR     R0,=GPIO_PORT1_BASE
				LDR     R1,=GPIO_PORT1_DIR_VAL
				STR     R1,[R0,#0x08]	 ;  GPIO_PORT1_DIR_ADDR
				LDR     R1,=GPIO_PORT1_SET_VAL
				STR     R1,[R0,#0x04]		; GPIO_PORT1_SET_ADDR
				LDR     R1,=GPIO_PORT1_CLR_VAL
				STR     R1,[R0,#0x0C]		 ;GPIO_PORT1_CLR_ADDR

				LDR     R0,=GPIO_PORT2_BASE
				LDR     R1,=GPIO_PORT2_DIR_VAL
				STR     R1,[R0,#0x08]	 ;  GPIO_PORT2_DIR_ADDR
				LDR     R1,=GPIO_PORT2_SET_VAL
				STR     R1,[R0,#0x04]		; GPIO_PORT2_SET_ADDR
				LDR     R1,=GPIO_PORT2_CLR_VAL
				STR     R1,[R0,#0x0C]		 ;GPIO_PORT2_CLR_ADDR

				LDR     R0,=GPIO_PORT3_BASE
				LDR     R1,=GPIO_PORT3_DIR_VAL
				STR     R1,[R0,#0x08]	 ;  GPIO_PORT3_DIR_ADDR
				LDR     R1,=GPIO_PORT3_SET_VAL
				STR     R1,[R0,#0x04]		; GPIO_PORT3_SET_ADDR
				LDR     R1,=GPIO_PORT3_CLR_VAL
				STR     R1,[R0,#0x0C]		 ;GPIO_PORT3_CLR_ADDR

				;  init the UART0 
				LDR     R0,=UART_LineControlAddr
				MOV     R1,#0x80	 ;enter DLAB mode 
				STRB    R1,[R0]

                IF      UART_EXT_BAUD_SETTING <> 0
				LDR     R0,=UART_DivideLowAddr
				LDR     R1,=UART_DivideLowExtVal
				STRB    R1,[R0]
				LDR     R0,=UART_DivideHighAddr
				LDR     R1,=UART_DivideHighExtVal
				STRB    R1,[R0]
				LDR     R0,=UART_FractionDivideAddr
				LDR     R1,=UART_FractionDivideVal
				STR     R1,[R0]
				ELSE
				LDR     R0,=UART_DivideLowAddr
				LDR     R1,=UART_DivideLowVal
				STRB    R1,[R0]
				LDR     R0,=UART_DivideHighAddr
				LDR     R1,=UART_DivideHighVal
				STRB    R1,[R0]
				ENDIF
				LDR     R0,=UART_LineControlAddr
				MOV     R1,#UART_LineControlVal  ;#0x1B		;DLAB = 0   Even Parity  &  8 chars 
				STRB    R1,[R0]
				LDR     R0,=UART_FIFOControlAddr
				MOV     R1,#UART_FIFOControlVal
				STRB    R1,[R0]
				LDR     R0,=UART_InterruptEnableAddr
				MOV     R1,#UART_InterruptEnableVal
				STRB    R1,[R0]
				; read at U0RBR
				LDR     R0,=UART_DataAddr
				LDRB    R1,[R0]
				; write at U0THR to avoid too much interrupts.
				MOV     R1,#0x00
				STRB    R1,[R0]

				;  turn off some peripherials
				LDR     R0,=PCONP_ADDR
				LDR     R1,=PCONP_VAL
				STR     R1,[R0]

				;  init the I2C bus
			;	LDR     R0,=I2C_ControlSetAddr
			;	LDR     R1,=I2C_ControlSetVal
			;	STRB    R1,[R0]
			;	LDR     R0,=I2C_ControlClearAddr
			;	LDR     R1,=I2C_ControlClearVal
			;	STRB    R1,[R0]
			;	LDR     R0,=I2C_DutyCycleHighAddr
			;	LDR     R1,=I2C_DutyCycleHighVal
			;	STRH    R1,[R0]
			;	LDR     R0,=I2C_DutyCycleLowAddr
			;	LDR     R1,=I2C_DutyCycleLowVal
			;	STRH    R1,[R0]

			    ; init MAM
				LDR R1,=0xE01FC000		; MAMCR
				MOV R0,#0x00	   ;disable MAM
				STRB R0,[R1]
				LDR R1,=0xE01FC004		; Fcclk	>40MHz  ,so MAMTIM=3
				MOV R0,#0x03
				STRB R0,[R1]   
				LDR R1,=0xE01FC000		
				MOV R0,#0x02    	;enable MAM
				STRB R0,[R1]

				; init the timer1 
 				LDR R1,=0xE0008000
				LDR R0,= 0x01
				STRB R0,[R1]		  ; T1IR
				LDR R1,=0xE0008008
				MOV R0,#0x00
				STRB R0,[R1]		   ; T1TC
				LDR R1,=0xE0008004
				MOV R0,#0x01
				STRB R0,[R1]		 ;  T1TCR
				LDR R1,=0xE0008014
				MOV R0,#0x03
				STRH R0,[R1]		   ; T1MCR
				LDR R1,=0xE0008018 
				LDR R0,=11059200/5    ; Fosc * 4 /  OS_TICKS_PER_SEC
				STR R0,[R1]			;	  T1MR0
			
				BX LR


			END 