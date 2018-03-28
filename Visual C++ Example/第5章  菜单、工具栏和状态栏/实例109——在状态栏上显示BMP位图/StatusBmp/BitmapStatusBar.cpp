// BitmapStatusBar.cpp : implementation file
//

#include "stdafx.h"
#include "StatusBmp.h"
#include "BitmapStatusBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBitmapStatusBar

CBitmapStatusBar::CBitmapStatusBar()
{
}

CBitmapStatusBar::~CBitmapStatusBar()
{
}


BEGIN_MESSAGE_MAP(CBitmapStatusBar, CStatusBar)
	//{{AFX_MSG_MAP(CBitmapStatusBar)
	ON_WM_DRAWITEM()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBitmapStatusBar message handlers
void CBitmapStatusBar::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	switch(lpDrawItemStruct->itemID)
        {
        case 1:
            //从资源中选择位图
            CBitmap pBitmap;
            //加载位图,使用Import从文件加载资源,可以不受调色板限制
            pBitmap.LoadBitmap(IDB_BITMAP1);

            //将状态条(StatusBar)附加到一个CDC对象
            CDC dc,SourceDC;
            dc.Attach(lpDrawItemStruct->hDC);

            //得到pane的大小和坐标
            CRect rect(&lpDrawItemStruct->rcItem);

            //将当前位图放入兼容CDC
            SourceDC.CreateCompatibleDC(NULL);//生成兼容的CDC
            CBitmap* pOldBitmap = SourceDC.SelectObject(&pBitmap);//选择位图
            dc.BitBlt(rect.left, rect.top, rect.Width(), rect.Height(),
                     &SourceDC, 0, 0, SRCCOPY);//BitBlt
            SourceDC.SelectObject(pOldBitmap);//删除CDC中所选择的位图
            pBitmap.DeleteObject();//删除位图

            //将状态条(StatusBar)与CDC对象分离,否则hDC将会在CDC废弃时被删除
            dc.Detach();
            return;
        }
	CStatusBar::DrawItem(lpDrawItemStruct);
}

void CBitmapStatusBar::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{

	CStatusBar::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

