/*
 +     Package: Mingw32-sup
 +     Version: 0.2
 +
 +   File Type: stub function
 +    $RCSfile: ttyname.c,v $ 
 +   $Revision: 1.0 $
 +       $Date: 1998/05/19 18:59:09 $
 +
 + Contributor: Earnie Boyd
 +
 +   Copyright: None.  This file has been placed in the Public Domain.
 +
 +  Warranties: None.  See the file in this package named doc/WARRANTIES.
 +
*/

/*
 * $Log: ttyname.c,v $
 * Revision 1.0  1998/05/19 18:59:09  bcoeeb0
 * Release 1.0
 *
 * Revision 0.2  1998/04/03 19:51:03  bcoeeb0
 * Change license to Public Domain.
 *
*/

char * ttyname( int fd )
{
  return "CON";
}
