// EDesktopExampleDoc.cpp : implementation of the CEDesktopExampleDoc class
//

#include "stdafx.h"
#include "EDesktopExample.h"

#include "EDesktopExampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEDesktopExampleDoc

IMPLEMENT_DYNCREATE(CEDesktopExampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CEDesktopExampleDoc, CDocument)
END_MESSAGE_MAP()


// CEDesktopExampleDoc construction/destruction

CEDesktopExampleDoc::CEDesktopExampleDoc()
{
	// TODO: add one-time construction code here

}

CEDesktopExampleDoc::~CEDesktopExampleDoc()
{
}

BOOL CEDesktopExampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CEDesktopExampleDoc serialization

void CEDesktopExampleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CEDesktopExampleDoc diagnostics

#ifdef _DEBUG
void CEDesktopExampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEDesktopExampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CEDesktopExampleDoc commands

void CEDesktopExampleDoc::SetTitle(LPCTSTR lpszTitle)
{
	CDocument::SetTitle(L"Test");
}
