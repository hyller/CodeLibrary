
PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
[Pearson Education, 2001; ISBN: 0-201-33138-1].

This code is copyright (c) 2001 by Michael J. Pont.

See book for copyright details and other information.

----------

This directory contains the files associated with Chapter 14.

The sub-directory 'Func_Ptr' contains the function pointer example 
(Listing 14.1 and 14.2).

The remaining sub-directories contain a number of complete scheduler examples. 
These projects (and sub-directories) are named as follows:

  TIMER_TICK_OSCILLATOR 

For example, the scheduler in sub-directory 0_01_12 has the following features:
- The scheduler is driven by Timer 0;
- The scheduler has a 1 millisecond tick interval;
- The scheduler code assumes use of a 12 MHz oscillator.

Most of the examples are 'generic' and have a 'g' suffix (e.g. 0_01_12g).  
These examples can be adapted without difficulty for use with a wide range
of 8051 devices.  

Two of the examples (with an 'i' suffix; e.g. 2_01_10i) are adapted for
use with the Infineon family of microcontrollers.

All of the examples may be easily adapted (for example, to generate different 
tick intervals or for use with different oscillators).
