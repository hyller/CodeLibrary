// EmbeddedGUIDoc.cpp : implementation of the CEmbeddedGUIDoc class
//

#include "stdafx.h"
#include "EmbeddedGUI.h"

#include "EmbeddedGUIDoc.h"

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif


// CEmbeddedGUIDoc

IMPLEMENT_DYNCREATE(CEmbeddedGUIDoc, CDocument)

BEGIN_MESSAGE_MAP(CEmbeddedGUIDoc, CDocument)
END_MESSAGE_MAP()


// CEmbeddedGUIDoc construction/destruction

CEmbeddedGUIDoc::CEmbeddedGUIDoc()
{
	// TODO: add one-time construction code here

}

CEmbeddedGUIDoc::~CEmbeddedGUIDoc()
{
}

BOOL CEmbeddedGUIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CEmbeddedGUIDoc serialization

void CEmbeddedGUIDoc::Serialize(CArchive& ar)
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


// CEmbeddedGUIDoc diagnostics

#ifdef _DEBUG
void CEmbeddedGUIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEmbeddedGUIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CEmbeddedGUIDoc commands

void CEmbeddedGUIDoc::SetTitle(LPCTSTR lpszTitle)
{
	CDocument::SetTitle(L"Test");
}
