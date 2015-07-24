ECHO OFF
CLS
ECHO *******************************************************************************
ECHO *                      Embedded Systems Building Blocks
ECHO *
ECHO *             (c) Copyright 1999, Jean J. Labrosse, Weston, FL
ECHO *                           All Rights Reserved
ECHO *
ECHO *
ECHO * Filename    : MAKETEST.BAT
ECHO * Description : Batch file to create the application.
ECHO * Output      : TEST.EXE will contain the DOS executable
ECHO * Usage       : MAKETEST
ECHO * Note(s)     : 1) This file assume that we use a MAKE utility.
ECHO *******************************************************************************
ECHO *
ECHO ON
MD    ..\WORK
MD    ..\OBJ
MD    ..\LST
CD    ..\WORK
COPY  ..\TEST\TEST.MAK   TEST.MAK
E:\BC45\BIN\MAKE -f TEST.MAK
CD    ..\TEST
