// DragEdit.cpp : implementation file
//

#include "stdafx.h"
#include "DialogEditDrag.h"
#include "DragEdit.h"

//#include <sys/types.h>
//#include <sys/stat.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDragEdit

CDragEdit::CDragEdit()
{
}

CDragEdit::~CDragEdit()
{
}


BEGIN_MESSAGE_MAP(CDragEdit, CEdit)
	//{{AFX_MSG_MAP(CDragEdit)
	ON_WM_CREATE()
	ON_WM_DROPFILES()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDragEdit message handlers

int CDragEdit::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CEdit::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	DragAcceptFiles(TRUE);//可以拖放文件设置
	return 0;
}

void CDragEdit::OnDropFiles(HDROP hDropInfo) 
{
	// TODO: Add your message handler code here and/or call default
	WORD wNumFilesDropped = DragQueryFile(hDropInfo, -1, NULL, 0);//同时拖放文件的数目
	CString firstFile="";
	for (WORD x = 0 ; x < wNumFilesDropped; x++) //只记录第一个拖动的文件
	{
		WORD wPathnameSize = DragQueryFile(hDropInfo, x, NULL, 0);
		char * npszFile = (char *) LocalAlloc(LPTR, wPathnameSize += 1);//分配内存
		if (npszFile == NULL) 
			continue;
		DragQueryFile(hDropInfo, x, npszFile, wPathnameSize);//获取拖放的文件名
		if (firstFile=="")
			firstFile=npszFile;//记录文件名
		LocalFree(npszFile);//释放内存
	}
	DragFinish(hDropInfo);//拖放结束
	SetWindowText(firstFile);//编辑框显示
//	CEdit::OnDropFiles(hDropInfo);
}
