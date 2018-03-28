// ReadEdit.cpp : implementation file
//

#include "stdafx.h"
#include "ReadEditDemo.h"
#include "ReadEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReadEdit

CReadEdit::CReadEdit()
{
}

CReadEdit::~CReadEdit()
{
}


BEGIN_MESSAGE_MAP(CReadEdit, CEdit)
	//{{AFX_MSG_MAP(CReadEdit)
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReadEdit message handlers

void CReadEdit::OnSetFocus(CWnd* pOldWnd) 
{
	pOldWnd->SetFocus();//将输入焦点返回原窗口	
//	CEdit::OnSetFocus(pOldWnd);//不执行默认的处理函数	
}
void CReadEdit::AppendString(CString str)

{
	CString   strBuffer;    // current contents of edit control
  GetWindowText (strBuffer);//获取编辑框原有文本
  if (!strBuffer.IsEmpty())
     strBuffer += "\r\n";//换行
  strBuffer += str;
  SetWindowText (strBuffer);//显示文本
  LineScroll (GetLineCount(), 0);//滚动编辑框
}
