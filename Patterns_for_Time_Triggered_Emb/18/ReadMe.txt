
PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
[Pearson Education, 2001; ISBN: 0-201-33138-1].

This code is copyright (c) 2001 by Michael J. Pont.

See book for copyright details and other information.

----------

This directory contains the files from Chapter 18.

The sub-directories contain a number of complete code libraries. 

The projects (and sub-directories) are named as follows:

  X_Tick_Baud

Here:
X  -   This is either 'IO' for an 'Input-Output' library,
       or 'O' for an 'Output-only library'  
 
       Input-Output libraries allow data transmission from 
       the microcontroller to the PC, and vice versa.

       Output-only libraries allow data transfer from the
       microcontroller to the PC only.

Tick - This identifies the timer used to drive the scheduler (T0, T2).

Baud - This identifies the timer used to generate the required 
       baud rate: this is T1, T2 or a dedicated internal baud-rate
       timer (identified as 'in')

For example, the library in directory IO_T2_T1 has the following features:
- The library allows data transfers to and from the PC
- The scheduler is driven by Timer 2;
- The baud rate is generated using Timer 1.
