// LimitEdit.cpp : implementation file
//

#include "stdafx.h"
#include "LimitEditBox.h"
#include "LimitEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLimitEdit

CLimitEdit::CLimitEdit()
{
}

CLimitEdit::~CLimitEdit()
{
}


BEGIN_MESSAGE_MAP(CLimitEdit, CEdit)
	//{{AFX_MSG_MAP(CLimitEdit)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLimitEdit message handlers

void CLimitEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default.
	if (::IsCharAlpha((TCHAR)nChar))//判断nChar是否为字母
	{
		nChar=(UINT)::CharUpper((LPTSTR)nChar);//转换为大写字母
		//通过DefWindowProc函数调用默认的消息处理函数
		DefWindowProc(WM_CHAR, nChar, MAKELPARAM(nRepCnt, nFlags));
	}
}
