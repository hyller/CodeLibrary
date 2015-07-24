###############################################################################
#                      Embedded Systems Building Blocks
#                         
#              (c) Copyright 1999, Jean J. Labrosse, Weston, FL
#                             All Rights Reserved
#
#
# Filename    : TEST.MAK
###############################################################################
#
#/*$PAGE*/
###############################################################################
#                                   TOOLS
###############################################################################
#

BORLAND=E:\BC45
BORLAND_EXE=E:\BC45\BIN

CC=$(BORLAND_EXE)\BCC
ASM=$(BORLAND_EXE)\TASM
LINK=$(BORLAND_EXE)\TLINK

###############################################################################
#                                DIRECTORIES
###############################################################################
#

TARGET=..\TEST
SOURCE=..\SOURCE
TEST=..\TEST
WORK=..\WORK
OBJ=..\OBJ
LST=..\LST

#

AIO=\SOFTWARE\BLOCKS\AIO\SOURCE
CLK=\SOFTWARE\BLOCKS\CLK\SOURCE
COMM=\SOFTWARE\BLOCKS\COMM\SOURCE
DIO=\SOFTWARE\BLOCKS\DIO\SOURCE
KEY=\SOFTWARE\BLOCKS\KEY_MN\SOURCE
LCD=\SOFTWARE\BLOCKS\LCD\SOURCE
LED=\SOFTWARE\BLOCKS\LED\SOURCE
OS=\SOFTWARE\uCOS-II\SOURCE
PC=\SOFTWARE\BLOCKS\PC\BC45
PORT=\SOFTWARE\uCOS-II\Ix86L-FP\BC45
TMR=\SOFTWARE\BLOCKS\TMR\SOURCE

#

LIB_PATH = $(BORLAND)\LIB
INCLUDE_PATH = $(BORLAND)\INCLUDE

#
#/*$PAGE*/
###############################################################################
#                               ASSEMBLER FLAGS
#
# /ml                Large model
# /zi                Full debug info
###############################################################################
#

ASM_FLAGS=/ml /zi  

###############################################################################
#                               COMPILER FLAGS
#
# -1                 Generate 80186 code
# -B                 Compile and call assembler
# -c                 Compiler to .OBJ
# -d                 Duplicate strings merged
# -dc                Put strings in code segment
# -f287              Generate floating-point processor instructions
# -G                 Select code for speed
# -I                 Path to include directory
# -k-                Don't use standard stack frame
# -ml                Large memory model
# -N-                Do not check for stack overflow
# -n                 Path to object directory
# -O                 Optimize jumps
# -S                 Generate assembler source
# -v                 Source debugging ON
# -vi                Turn inline expansion ON
# -wpro              Error reporting: call to functions with no prototype
# -Z                 Suppress redundant loads
###############################################################################
#

C_FLAGS=-f287 -c -ml -1 -G -O -Ogemvlbpi -Z -d -n..\obj -k- -v -vi- -wpro -I$(INCLUDE_PATH)

###############################################################################
#                                LINKER FLAGS
###############################################################################
#
LINK_FLAGS= 

#/*$PAGE*/
###############################################################################
#                          CREATION OF .HEX FILES
#
# Note(s): 1) The following files are not included as part of this build because
#             they are not used:
#                         $(OBJ)\KEY.OBJ        \
#                         $(OBJ)\LED.OBJ        \
#                         $(OBJ)\LED_IA.OBJ     \
#                         $(OBJ)\LCD.OBJ        \
#          2) The following files are provided in object form from the 
#             distribution diskette of ESBB.  
#                         $(OBJ)\OS_CPU_A.OBJ   \
#                         $(OBJ)\OS_CPU_C.OBJ   \
#                         $(OBJ)\uCOS_II.OBJ    \
#             You can obtain the source files by purchasing a copy of my other 
#             book called "MicroC/OS-II, The Real-Time Kernel", ISBN 0-87930-543-6.
###############################################################################

$(TARGET)\TEST.EXE:      $(OBJ)\AIO.OBJ        \
                         $(OBJ)\CFG.OBJ        \
                         $(OBJ)\CLK.OBJ        \
                         $(OBJ)\COMM_PC.OBJ    \
                         $(OBJ)\COMM_PCA.OBJ   \
                         $(OBJ)\COMMRTOS.OBJ   \
                         $(OBJ)\DIO.OBJ        \
                         $(OBJ)\PC.OBJ         \
                         $(OBJ)\TEST.OBJ       \
                         $(OBJ)\TMR.OBJ        \
                         $(SOURCE)\TEST.LNK
                         COPY    $(SOURCE)\TEST.LNK
                         DEL     $(TARGET)\TEST.MAP
                         DEL     $(TARGET)\TEST.EXE
                         $(LINK) $(LINK_FLAGS) @TEST.LNK
                         COPY    $(OBJ)\TEST.EXE   $(WORK)\TEST.EXE    /y
                         COPY    $(OBJ)\TEST.MAP   $(TARGET)\TEST.MAP  /y
                         COPY    $(OBJ)\TEST.EXE   $(TARGET)\TEST.EXE  /y
                         DEL     TEST.MAK


###############################################################################
#                        CREATION OF .O (Object) FILES
###############################################################################

$(OBJ)\AIO.OBJ:          $(AIO)\AIO.C    \
                         INCLUDES.H
                         COPY   $(AIO)\AIO.C          AIO.C
                         DEL    $(OBJ)\AIO.OBJ
                         $(CC)  $(C_FLAGS)            AIO.C


$(OBJ)\CFG.OBJ:          $(SOURCE)\CFG.C    \
                         INCLUDES.H
                         COPY   $(SOURCE)\CFG.C       CFG.C
                         DEL    $(OBJ)\CFG.OBJ
                         $(CC)  $(C_FLAGS)            CFG.C


$(OBJ)\CLK.OBJ:          $(CLK)\CLK.C    \
                         INCLUDES.H
                         COPY   $(CLK)\CLK.C          CLK.C
                         DEL    $(OBJ)\CLK.OBJ
                         $(CC)  $(C_FLAGS)            CLK.C


$(OBJ)\COMM_PC.OBJ:      $(COMM)\COMM_PC.C    \
                         INCLUDES.H
                         COPY   $(COMM)\COMM_PC.C     COMM_PC.C
                         DEL    $(OBJ)\COMM_PC.OBJ
                         $(CC)  $(C_FLAGS)            COMM_PC.C


$(OBJ)\COMM_PCA.OBJ:     $(COMM)\COMM_PCA.ASM
                         COPY   $(COMM)\COMM_PCA.ASM  COMM_PCA.ASM
                         DEL    $(OBJ)\COMM_PCA.OBJ
                         $(ASM) $(ASM_FLAGS)          $(COMM)\COMM_PCA.ASM, $(OBJ)\COMM_PCA.OBJ


$(OBJ)\COMMRTOS.OBJ:     $(COMM)\COMMRTOS.C    \
                         INCLUDES.H
                         COPY   $(COMM)\COMMRTOS.C    COMMRTOS.C
                         DEL    $(OBJ)\COMMRTOS.OBJ
                         $(CC)  $(C_FLAGS)            COMMRTOS.C


$(OBJ)\DIO.OBJ:          $(DIO)\DIO.C    \
                         INCLUDES.H
                         COPY   $(DIO)\DIO.C          DIO.C
                         DEL    $(OBJ)\DIO.OBJ
                         $(CC)  $(C_FLAGS)            DIO.C


$(OBJ)\KEY.OBJ:          $(KEY)\KEY.C    \
                         INCLUDES.H
                         COPY   $(KEY)\KEY.C          KEY.C
                         DEL    $(OBJ)\KEY.OBJ
                         $(CC)  $(C_FLAGS)            KEY.C


$(OBJ)\LCD.OBJ:          $(LCD)\LCD.C    \
                         INCLUDES.H
                         COPY   $(LCD)\LCD.C          LCD.C
                         DEL    $(OBJ)\LCD.OBJ
                         $(CC)  $(C_FLAGS)            LCD.C


$(OBJ)\LED.OBJ:          $(LED)\LED.C    \
                         INCLUDES.H
                         COPY   $(LED)\LED.C          LED.C
                         DEL    $(OBJ)\LED.OBJ
                         $(CC)  $(C_FLAGS)            LED.C


$(OBJ)\LED_IA.OBJ:       $(LED)\LED_IA.ASM
                         COPY   $(LED)\LED_IA.ASM     LED_IA.ASM
                         DEL    $(OBJ)\LED_IA.OBJ
                         $(ASM) $(ASM_FLAGS)          $(LED)\LED_IA.ASM, $(OBJ)\LED_IA.OBJ


$(OBJ)\OS_CPU_A.OBJ:     $(PORT)\OS_CPU_A.ASM   \
                         INCLUDES.H
                         COPY   $(PORT)\OS_CPU_A.ASM  OS_CPU_A.ASM
                         DEL    $(OBJ)\OS_CPU_A.OBJ
	                     $(ASM) $(ASM_FLAGS)  $(PORT)\OS_CPU_A.ASM,$(OBJ)\OS_CPU_A.OBJ


$(OBJ)\OS_CPU_C.OBJ:     $(PORT)\OS_CPU_C.C   \
                         INCLUDES.H
                         COPY   $(PORT)\OS_CPU_C.C    OS_CPU_C.C
                         DEL    $(OBJ)\OS_CPU_C.OBJ
                         $(CC)  $(C_FLAGS)            OS_CPU_C.C


$(OBJ)\PC.OBJ:           $(PC)\PC.C    \
                         INCLUDES.H
                         COPY   $(PC)\PC.C            PC.C
                         DEL    $(OBJ)\PC.OBJ
                         $(CC)  $(C_FLAGS)            PC.C


$(OBJ)\TEST.OBJ:         $(SOURCE)\TEST.C   \
                         INCLUDES.H
                         COPY   $(SOURCE)\TEST.C      TEST.C
                         DEL    $(OBJ)\TEST.OBJ
                         $(CC)  $(C_FLAGS)            TEST.C


$(OBJ)\TMR.OBJ:          $(TMR)\TMR.C   \
                         INCLUDES.H
                         COPY   $(TMR)\TMR.C          TMR.C
                         DEL    $(OBJ)\TMR.OBJ
                         $(CC)  $(C_FLAGS)            TMR.C


$(OBJ)\uCOS_II.OBJ:      $(OS)\uCOS_II.C   \
                         INCLUDES.H
                         COPY   $(OS)\uCOS_II.C       uCOS_II.C
                         DEL    $(OBJ)\uCOS_II.OBJ
                         $(CC)  $(C_FLAGS)            uCOS_II.C


#/*$PAGE*/
###############################################################################
#                                HEADER FILES
###############################################################################

INCLUDES.H:              $(SOURCE)\INCLUDES.H \
                         AIO.H                \
                         CFG.H                \
                         CLK.H                \
                         COMM_PC.H            \
                         COMMRTOS.H           \
                         DIO.H                \
                         KEY.H                \
                         LCD.H                \
                         LED.H                \
                         OS_CFG.H             \
                         OS_CPU.H             \
                         PC.H                 \
                         TMR.H                \
                         uCOS_II.H               
                         $(BORLAND_EXE)\TOUCH $(SOURCE)\INCLUDES.H
                         COPY $(SOURCE)\INCLUDES.H     INCLUDES.H

AIO.H:                   $(AIO)\AIO.H
                         COPY $(AIO)\AIO.H             AIO.H

CFG.H:                   $(SOURCE)\CFG.H
                         COPY $(SOURCE)\CFG.H          CFG.H

CLK.H:                   $(CLK)\CLK.H
                         COPY $(CLK)\CLK.H             CLK.H

COMM_PC.H:               $(COMM)\COMM_PC.H
                         COPY $(COMM)\COMM_PC.H        COMM_PC.H

COMMRTOS.H:              $(COMM)\COMMRTOS.H
                         COPY $(COMM)\COMMRTOS.H       COMMRTOS.H

DIO.H:                   $(DIO)\DIO.H
                         COPY $(DIO)\DIO.H             DIO.H

KEY.H:                   $(KEY)\KEY.H
                         COPY $(KEY)\KEY.H             KEY.H

LCD.H:                   $(LCD)\LCD.H
                         COPY $(LCD)\LCD.H             LCD.H

LED.H:                   $(LED)\LED.H
                         COPY $(LED)\LED.H             LED.H

OS_CFG.H:                $(SOURCE)\OS_CFG.H
                         COPY $(SOURCE)\OS_CFG.H       OS_CFG.H

OS_CPU.H:                $(PORT)\OS_CPU.H
                         COPY $(PORT)\OS_CPU.H         OS_CPU.H

PC.H:                    $(PC)\PC.H
                         COPY $(PC)\PC.H               PC.H

TMR.H:                   $(TMR)\TMR.H
                         COPY $(TMR)\TMR.H             TMR.H

uCOS_II.H:               $(OS)\uCOS_II.H
                         COPY $(OS)\uCOS_II.H          uCOS_II.H
