
PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
[Pearson Education, 2001; ISBN: 0-201-33138-1].

This code is copyright (c) 2001 by Michael J. Pont.

See book for copyright details and other information.

----------

This directory contains the files from Chapter 17.

The sub-directories contain a number of complete 
(hybrid) scheduler examples. 

The projects (and sub-directories) are named as follows:

  Timer_Tick_Oscillator

For example, the scheduler in directory 2_01_24h has the following 
features:
- The scheduler is driven by Timer 2;
- The scheduler has a 1 millisecond tick interval;
- The scheduler code assumes use of a 24 MHz oscillator.

All of the examples are 'hybrid' and have a 'h' suffix (e.g. 2_01_24h).  

All of the examples may be easily adapted (for example, to generate 
different tick intervals or for use with different oscillators).
