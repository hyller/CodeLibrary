;********************************************************************************************************
;                                    Embedded Systems Building Blocks
;                                 Complete and Ready-to-Use Modules in C
;
;                                     Multiplexed LED Display Driver
;                                            LED Multiplex ISR
;                                        Intel 80x86 (LARGE MODEL)
;
;                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
;                                          All Rights Reserved
;
; File : LED_IA.ASM
; By   : Jean J. Labrosse
;********************************************************************************************************

            PUBLIC _DispMuxISR

            EXTRN  _DispMuxHandler:FAR
            EXTRN  _OSIntExit:FAR
            EXTRN  _OSIntNesting:BYTE

.MODEL      LARGE
.CODE
.186

;*********************************************************************************************************
;                          OUTPUT NEXT SEGMENTS PATTERN TO LED DISPLAY MATRIX
;                                         void DispMuxISR(void)
;*********************************************************************************************************

_DispMuxISR PROC FAR
;
            PUSHA                                ;Save processor's context
            PUSH   ES
            PUSH   DS
;
            INC    BYTE PTR _OSIntNesting        ; Notify uC/OS-II of ISR
            CALL   FAR  PTR _DispMuxHandler      ; Call C routine to handle multiplexing
            CALL   FAR  PTR _OSIntExit           ; Exit through uC/OS-II scheduler
;
            POP    DS                            ;Restore processor's context
            POP    ES
            POPA
;
            IRET                                 ;Return to interrupted code
;
_DispMuxISR ENDP

            END
