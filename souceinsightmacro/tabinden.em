/*   T A B   O R   I N D E N T   */
/*-------------------------------------------------------------------------
    If selection is extended, indent all the lines. 
    If selection is just an insertion point, insert a tab.
-------------------------------------------------------------------------*/
macro TabOrIndent()
{
	hwnd = GetCurrentWnd()
	if (hwnd != 0)
		{
		sel = GetWndSel(hwnd)
		if (sel.fExtended)
			Indent_Right
		else
			Tab
		}
}

