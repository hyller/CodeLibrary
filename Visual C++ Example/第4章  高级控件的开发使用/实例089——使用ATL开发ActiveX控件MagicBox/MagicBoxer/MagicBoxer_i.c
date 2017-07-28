/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Jun 27 10:30:20 2008
 */
/* Compiler settings for D:\MagicBoxer\MagicBoxer.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IMagicBox = {0x463C57B6,0xCA1D,0x4E3A,{0x91,0x0C,0x05,0x63,0xA6,0x99,0x2F,0xFA}};


const IID LIBID_MAGICBOXERLib = {0x0A9BCD72,0xB597,0x455F,{0x87,0x4A,0xFE,0x0B,0xE7,0x2E,0x92,0xB9}};


const IID DIID__IMagicBoxEvents = {0xF56D5432,0xD8AD,0x40D2,{0x92,0x55,0x81,0xA6,0x41,0x42,0xFF,0x88}};


const CLSID CLSID_MagicBox = {0x9C4A11F3,0x7AA3,0x4587,{0xBB,0x40,0x7A,0x53,0x69,0x06,0x31,0x37}};


#ifdef __cplusplus
}
#endif

