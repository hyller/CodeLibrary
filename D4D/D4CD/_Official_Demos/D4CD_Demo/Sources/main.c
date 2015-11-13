#include "main.h"

D4CD_EXTERN_SCREEN(scr_test);
D4CD_EXTERN_OBJECT(tstTimeScr_Time);

void Keys_Handle(void)
{
  const D4CD_KEY_SCANCODE scan_codes[4] =
  {
    D4CD_KEY_SCANCODE_ENTER,
    D4CD_KEY_SCANCODE_ESC,
    D4CD_KEY_SCANCODE_UP,
    D4CD_KEY_SCANCODE_DOWN
  };
  Byte i;  
  
  i = getch() - '1';
  
  if(i < 4){
    D4CD_NewKeyEvent(scan_codes[i]);
    D4CD_NewKeyEvent(scan_codes[i] | D4CD_KEY_SCANCODE_RELEASEMASK);
  }
}

void main(void) {

  if(!D4CD_Init(&scr_test))
    for(;;);

  for(;;) {
    D4CD_Poll();
    Keys_Handle( );
  } /* loop forever */
  /* please make sure that you never leave main */
}
