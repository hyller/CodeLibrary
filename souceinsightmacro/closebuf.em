

/*   C L O S E   N O N   D I R T Y   */
/*-------------------------------------------------------------------------
    Close all non-dirty file windows
-------------------------------------------------------------------------*/
macro CloseNonDirty()
{
	hwnd = GetCurrentWnd()
	while (hwnd != 0)
		{
		hwndNext = GetNextWnd(hwnd)
		
		hbuf = GetWndBuf(hwnd)
		if (!IsBufDirty(hbuf))
			CloseBuf(hbuf)
		
		hwnd = hwndNext
		}
}


/*   C L O S E _   O T H E R S _   W I N D O W S   */
/*-------------------------------------------------------------------------
    Close all but the current window.  Leaves any other dirty 
    file windows open too.
-------------------------------------------------------------------------*/
macro Close_Others_Windows()
{
	hCur = GetCurrentWnd();
	hNext = GetNextWnd(hCur);
	while (hNext != 0 && hCur != hNext)
	{
		hT = GetNextWnd(hNext);
		hbuf = GetWndBuf(hNext);
		if (!IsBufDirty(hbuf))
			CloseBuf(hbuf)
		hNext = hT;
	}
}


