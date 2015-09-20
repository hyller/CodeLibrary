/*
	Prints the currently selected text.
	Note: this alters the contents of the clipboard
	
	As with other macros, to use this:
		1. Add this macro file to your project.
		2. Run the Options->Menu Assignments command.
		3. Find and select the macro name "PrintSelection" in the command list
		4. Insert the command onto a menu.  
		Now you can run the macro command

*/

macro PrintSelection()
{
	hbufCur = GetCurrentBuf()
	filename = GetBufName(hbufCur)
	Copy
	hbufTemp = NewBuf("Output: @filename@")
	SetCurrentBuf(hbufTemp)
	Paste
	Print()
	CloseBuf(hbufTemp)
}


