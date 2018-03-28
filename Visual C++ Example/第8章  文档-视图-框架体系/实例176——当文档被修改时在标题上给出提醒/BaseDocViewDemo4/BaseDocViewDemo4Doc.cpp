// BaseDocViewDemo4Doc.cpp : implementation of the CBaseDocViewDemo4Doc class
//

#include "stdafx.h"
#include "BaseDocViewDemo4.h"

#include "BaseDocViewDemo4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo4Doc

IMPLEMENT_DYNCREATE(CBaseDocViewDemo4Doc, CDocument)

BEGIN_MESSAGE_MAP(CBaseDocViewDemo4Doc, CDocument)
	//{{AFX_MSG_MAP(CBaseDocViewDemo4Doc)
	ON_COMMAND(ID_MENU_UNDO, OnMenuUndo)
	ON_COMMAND(ID_MENU_CLEAR, OnMenuClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo4Doc construction/destruction

CBaseDocViewDemo4Doc::CBaseDocViewDemo4Doc()
{
	// TODO: add one-time construction code here

}

CBaseDocViewDemo4Doc::~CBaseDocViewDemo4Doc()
{
}

BOOL CBaseDocViewDemo4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo4Doc serialization

void CBaseDocViewDemo4Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		m_lineArray.Serialize(ar);								//数组序列化
	}
	else
	{
		// TODO: add loading code here
		m_lineArray.Serialize(ar);			 					//数组序列化
	}
}

void CBaseDocViewDemo4Doc::AddLine(CPoint pStar,CPoint pEnd)//添加线条
{
	CDrawLine *pLine=new CDrawLine(pStar,pEnd);
	m_lineArray.Add(pLine);									//加入数组对象
	SetModifiedFlag(true);//设置修改标记
}

CDrawLine *CBaseDocViewDemo4Doc::GetLine(int index)
{
	if(index<0||index>m_lineArray.GetUpperBound())					//无效的线条
		return 0;
	return (CDrawLine *)m_lineArray.GetAt(index);					//从数组中获取线条指针
}

int CBaseDocViewDemo4Doc::GetTotalLine()
{
	return m_lineArray.GetSize();								//数组中存储的线条数目
}



/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo4Doc diagnostics

#ifdef _DEBUG
void CBaseDocViewDemo4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBaseDocViewDemo4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo4Doc commands

void CBaseDocViewDemo4Doc::OnMenuUndo() 
{
	// TODO: Add your command handler code here
	int index;
	index=m_lineArray.GetUpperBound();						//获取数组最后的元素
	if(index>=0)
	{
		delete m_lineArray.GetAt(index); 						//删除线条
		m_lineArray.RemoveAt(index);							//删除数组对象
	}
	UpdateAllViews(NULL);
	SetModifiedFlag(true);//设置修改标记
}

void CBaseDocViewDemo4Doc::OnMenuClear() 
{
	// TODO: Add your command handler code here
	int index;
	index=m_lineArray.GetUpperBound();						//获取数组最后的元素
	if(index>=0)
	{
		m_lineArray.RemoveAll();					//清空数组
	}
	UpdateAllViews(NULL);//更新视图
	SetModifiedFlag(true);//设置修改标记
}

void CBaseDocViewDemo4Doc::SetModifiedFlag(BOOL bModified)
{
	CString strTitle = GetTitle();//获取文档的标题
    CString strDirtyFlag = " 文档已被修改，注意保存!"; //注意引号内前面的空格！
	//假如被修改了
    if (!IsModified() && bModified)
    {
		//标题栏也修改
        SetTitle(strTitle + strDirtyFlag);
    }
    else if ( IsModified() && !bModified )//已经保存了文档
    {
        int nTitleLength = strTitle.GetLength();
        int nDirtyLength = strDirtyFlag.GetLength();
        SetTitle( strTitle.Left(nTitleLength - nDirtyLength) );//恢复原来的标题
    }
    UpdateFrameCounts();
    CDocument::SetModifiedFlag(bModified);
}
