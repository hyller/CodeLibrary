;********************************************************************************************************
;                                     Embedded Systems Building Blocks
;                                  Complete and Ready-to-Use Modules in C
;
;                                    Asynchronous Serial Communications
;                                    IBM-PC Serial I/O Low Level Driver
;
;                            (c) Copyright 1999, Jean J. Labrosse, Weston, FL
;                                           All Rights Reserved
;
; Filename   : COMM_PCA.ASM
; Programmer : Jean J. Labrosse
; Notes      : If you are not using uC/OS-II you will need to DELETE the increments of OSIntNesting and
;              the calls to OSIntExit().
;********************************************************************************************************

            PUBLIC _Comm1ISR
            PUBLIC _Comm2ISR

            EXTRN  _OSIntExit:FAR
            EXTRN  _CommISRHandler:FAR

            EXTRN  _OSIntNesting:BYTE

.MODEL      LARGE
.CODE
.186

;/*$PAGE*/
;*********************************************************************************************************
;                                           HANDLE COM1 ISR
;*********************************************************************************************************
;
_Comm1ISR   PROC   FAR
;
            PUSHA                                ; Save interrupted task's context
            PUSH   ES
            PUSH   DS
;
            MOV    AX, DGROUP                    ; Reload DS with DGROUP
            MOV    DS, AX
;
;           NOTE: Comment OUT the next line (i.e. INC _OSIntNesting) if you don't use uC/OS-II.
            INC    BYTE PTR _OSIntNesting        ; Notify uC/OS-II of ISR
;
            PUSH   1                             ; Indicate COMM1
            CALL   FAR PTR _CommISRHandler       ; Process COMM interrupt
            ADD    SP,2
;
;           NOTE: Comment OUT the next line (i.e. CALL _OSIntExit) if you don't use uC/OS-II.
            CALL   FAR PTR _OSIntExit            ; Notify OS of end of ISR
;
            POP    DS                            ; Restore interrupted task's context
            POP    ES
            POPA
;
            IRET                                 ; Return to interrupted task
;
_Comm1ISR   ENDP
;
;/*$PAGE*/
;*********************************************************************************************************
;                                           HANDLE COM2 ISR
;*********************************************************************************************************
;
_Comm2ISR   PROC   FAR
;
            PUSHA                                ; Save interrupted task's context
            PUSH   ES
            PUSH   DS
;
            MOV    AX, DGROUP                    ; Reload DS with DGROUP
            MOV    DS, AX
;
;           NOTE: Comment OUT the next line (i.e. INC _OSIntNesting) if you don't use uC/OS-II.
            INC    BYTE PTR _OSIntNesting        ; Notify uC/OS-II of ISR
;
            PUSH   2                             ; Indicate COMM2
            CALL   FAR PTR _CommISRHandler       ; Process COMM interrupt
            ADD    SP,2
;
;           NOTE: Comment OUT the next line (i.e. CALL _OSIntExit) if you don't use uC/OS-II.
            CALL   FAR PTR _OSIntExit            ; Notify OS of end of ISR
;
            POP    DS                            ; Restore interrupted task's context
            POP    ES
            POPA
;
            IRET                                 ; Return to interrupted task
;
_Comm2ISR   ENDP
;
            END
