/*   F U N N Y   C H A R   */
/*-------------------------------------------------------------------------
    Inserts an extended ascii character into the current buffer selection

    Modify the argument to CharFromAscii to customized this.
-------------------------------------------------------------------------*/
macro FunnyChar()
{
	hbuf = GetCurrentBuf()
	if (hbuf != 0)
		SetBufSelText(hbuf, CharFromAscii(226))
}
