// ExListBox.cpp : implementation file
//

#include "stdafx.h"
#include "ExListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExListBox

CExListBox::CExListBox()
{
	m_nMaxWidth=0;
}

CExListBox::~CExListBox()
{
}


BEGIN_MESSAGE_MAP(CExListBox, CListBox)
	//{{AFX_MSG_MAP(CExListBox)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExListBox message handlers
int CExListBox::AddString(LPCTSTR lpszItem)
{
	int nRet = CListBox::AddString(lpszItem);//调用基类的AddString函数
	//调用GetScrollInfo获得垂直滚动条的相关信息
    SCROLLINFO scrollInfo;//滚动条结构
    memset(&scrollInfo, 0, sizeof(SCROLLINFO));
    scrollInfo.cbSize = sizeof(SCROLLINFO);
    scrollInfo.fMask  = SIF_ALL;
    GetScrollInfo(SB_VERT, &scrollInfo, SIF_ALL);//获取垂直滚动条信息
	//SCROLLINFO的成员nPage保存了列表框“每页”能够显示的项目数，nMax是列表框内项目总数。当nMax大于或等于nPage，就出现了垂直滚动条。
	int nScrollWidth = 0;
    if(GetCount()>1&& ((int)scrollInfo.nMax >= (int)scrollInfo.nPage))//如果列表框有垂直滚动条
    {
       nScrollWidth = GetSystemMetrics(SM_CXVSCROLL);//获取垂直滚动条的宽度
    }
	//声明一个SIZE变量sSize，并实例化对话框的CClientDC： 
    SIZE      sSize;
    CClientDC myDC(this);
	 CFont* pListBoxFont = GetFont();//获取字体
    if(pListBoxFont != NULL)
    {
        CFont* pOldFont = myDC.SelectObject(pListBoxFont);
		//调用GetTextExtendPoint32()函数获得字符串的宽度
        GetTextExtentPoint32(myDC.m_hDC, lpszItem, strlen(lpszItem), &sSize);
        m_nMaxWidth = max(m_nMaxWidth, (int)sSize.cx);
		SetHorizontalExtent(m_nMaxWidth + nScrollWidth);//设置水平滚动条
		myDC.SelectObject(pOldFont);     
	}
	 return nRet;

}
