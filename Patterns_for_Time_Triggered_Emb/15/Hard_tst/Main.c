/*------------------------------------------------------------------*-

   Main.C (v1.00)

  ------------------------------------------------------------------

   Testing hardware timeouts.


   COPYRIGHT
   ---------

   This code is from the book:

   PATTERNS FOR TIME-TRIGGERED EMBEDDED SYSTEMS by Michael J. Pont 
   [Pearson Education, 2001; ISBN: 0-201-33138-1].

   This code is copyright (c) 2001 by Michael J. Pont.
 
   See book for copyright details and other information.

-*------------------------------------------------------------------*/

#include "Main.H"
#include "TimeoutH.H"

// Function prototypes
void Test_50micros(void);  
void Test_500micros(void);  
void Test_1ms(void);  
void Test_5ms(void);  
void Test_10ms(void);  
void Test_15ms(void);  
void Test_20ms(void);  
void Test_50ms(void);  

// TIMEOUT code variable & TIMEOUT code (dummy here)
#define TIMEOUT 0xFF
tByte Error_code_G;

/*------------------------------------------------------------------*/
void main(void)
   {
   while(1) 
      {
      Test_50micros();  
      Test_500micros();  
      Test_1ms();  
      Test_5ms();  
      Test_10ms();  
      Test_15ms();  
      Test_20ms();  
      Test_50ms();  
      }
   }

/*------------------------------------------------------------------*/
void Test_50micros(void)
   {
   // Configure Timer 0 as a 16-bit timer 
   TMOD &= 0xF0; // Clear all T0 bits (T1 left unchanged)
   TMOD |= 0x01; // Set required T0 bits (T1 left unchanged) 

   ET0 = 0;  // No interrupts

   // Simple timeout feature - approx 50 µs
   TH0 = T_50micros_H; // See TimeoutH.H for T_ details
   TL0 = T_50micros_L;
   TF0 = 0; // Clear flag
   TR0 = 1; // Start timer

   while (!TF0);

   TR0 = 0;  

   // Normally need to report timeout TIMEOUTs
   // (this test is for demo purposes here)
   if (TF0 == 1)
      {
      // Operation timed out
      Error_code_G = TIMEOUT;
      }
   }

/*------------------------------------------------------------------*/
void Test_500micros(void)
   {
   // Configure Timer 0 as a 16-bit timer 
   TMOD &= 0xF0; // Clear all T0 bits (T1 left unchanged)
   TMOD |= 0x01; // Set required T0 bits (T1 left unchanged) 

   ET0 = 0;  // No interrupts

   // Simple timeout feature - approx 500 µs
   TH0 = T_500micros_H; // See TimeoutH.H for T_ details
   TL0 = T_500micros_L;
   TF0 = 0; // Clear flag
   TR0 = 1; // Start timer

   while (!TF0);

   TR0 = 0;  

   // Normally need to report timeout TIMEOUTs
   // (this test is for demo purposes here)
   if (TF0 == 1)
      {
      // Operation timed out
      Error_code_G = TIMEOUT;
      }
   }

/*------------------------------------------------------------------*/
void Test_1ms(void)
   {
   // Configure Timer 0 as a 16-bit timer 
   TMOD &= 0xF0; // Clear all T0 bits (T1 left unchanged)
   TMOD |= 0x01; // Set required T0 bits (T1 left unchanged) 

   ET0 = 0;  // No interrupts

   // Simple timeout feature - approx 1 ms
   TH0 = T_01ms_H; // See TimeoutH.H for T_ details
   TL0 = T_01ms_L;
   TF0 = 0; // Clear flag
   TR0 = 1; // Start timer

   while (!TF0);

   TR0 = 0;  

   // Normally need to report timeout TIMEOUTs
   // (this test is for demo purposes here)
   if (TF0 == 1)
      {
      // Operation timed out
      Error_code_G = TIMEOUT;
      }
   }

/*------------------------------------------------------------------*/
void Test_5ms(void)
   {
   // Configure Timer 0 as a 16-bit timer 
   TMOD &= 0xF0; // Clear all T0 bits (T1 left unchanged)
   TMOD |= 0x01; // Set required T0 bits (T1 left unchanged) 

   ET0 = 0;  // No interrupts

   // Simple timeout feature - approx 10 ms
   TH0 = T_05ms_H; // See TimeoutH.H for T_ details
   TL0 = T_05ms_L;
   TF0 = 0; // Clear flag
   TR0 = 1; // Start timer

   while (!TF0);

   TR0 = 0;  

   // Normally need to report timeout TIMEOUTs
   // (this test is for demo purposes here)
   if (TF0 == 1)
      {
      // Operation timed out
      Error_code_G = TIMEOUT;
      }
   }

/*------------------------------------------------------------------*/
void Test_10ms(void)
   {
   // Configure Timer 0 as a 16-bit timer 
   TMOD &= 0xF0; // Clear all T0 bits (T1 left unchanged)
   TMOD |= 0x01; // Set required T0 bits (T1 left unchanged) 

   ET0 = 0;  // No interrupts

   // Simple timeout feature - approx 10 ms
   TH0 = T_10ms_H; // See TimeoutH.H for T_ details
   TL0 = T_10ms_L;
   TF0 = 0; // Clear flag
   TR0 = 1; // Start timer

   while (!TF0);

   TR0 = 0;  

   // Normally need to report timeout TIMEOUTs
   // (this test is for demo purposes here)
   if (TF0 == 1)
      {
      // Operation timed out
      Error_code_G = TIMEOUT;
      }
   }

/*------------------------------------------------------------------*/
void Test_15ms(void)
   {
   // Configure Timer 0 as a 16-bit timer 
   TMOD &= 0xF0; // Clear all T0 bits (T1 left unchanged)
   TMOD |= 0x01; // Set required T0 bits (T1 left unchanged) 

   ET0 = 0;  // No interrupts

   // Simple timeout feature - approx 10 ms
   TH0 = T_15ms_H; // See TimeoutH.H for T_ details
   TL0 = T_15ms_L;
   TF0 = 0; // Clear flag
   TR0 = 1; // Start timer

   while (!TF0);

   TR0 = 0;  

   // Normally need to report timeout TIMEOUTs
   // (this test is for demo purposes here)
   if (TF0 == 1)
      {
      // Operation timed out
      Error_code_G = TIMEOUT;
      }
   }

/*------------------------------------------------------------------*/
void Test_20ms(void)
   {
   // Configure Timer 0 as a 16-bit timer 
   TMOD &= 0xF0; // Clear all T0 bits (T1 left unchanged)
   TMOD |= 0x01; // Set required T0 bits (T1 left unchanged) 

   ET0 = 0;  // No interrupts

   // Simple timeout feature - approx 10 ms
   TH0 = T_20ms_H; // See TimeoutH.H for T_ details
   TL0 = T_20ms_L;
   TF0 = 0; // Clear flag
   TR0 = 1; // Start timer

   while (!TF0);

   TR0 = 0;  

   // Normally need to report timeout TIMEOUTs
   // (this test is for demo purposes here)
   if (TF0 == 1)
      {
      // Operation timed out
      Error_code_G = TIMEOUT;
      }
   }

/*------------------------------------------------------------------*/
void Test_50ms(void)
   {
   // Configure Timer 0 as a 16-bit timer 
   TMOD &= 0xF0; // Clear all T0 bits (T1 left unchanged)
   TMOD |= 0x01; // Set required T0 bits (T1 left unchanged) 

   ET0 = 0;  // No interrupts

   // Simple timeout feature - approx 10 ms
   TH0 = T_50ms_H; // See TimeoutH.H for T_ details
   TL0 = T_50ms_L;
   TF0 = 0; // Clear flag
   TR0 = 1; // Start timer

   while (!TF0);

   TR0 = 0;  

   // Normally need to report timeout TIMEOUTs
   // (this test is for demo purposes here)
   if (TF0 == 1)
      {
      // Operation timed out
      Error_code_G = TIMEOUT;
      }
   }

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
