// SinglePrintDoc.cpp : implementation of the CSinglePrintDoc class
//

#include "stdafx.h"
#include "SinglePrint.h"

#include "SinglePrintDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSinglePrintDoc

IMPLEMENT_DYNCREATE(CSinglePrintDoc, CDocument)

BEGIN_MESSAGE_MAP(CSinglePrintDoc, CDocument)
	//{{AFX_MSG_MAP(CSinglePrintDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSinglePrintDoc construction/destruction

CSinglePrintDoc::CSinglePrintDoc()
{
	// TODO: add one-time construction code here

}

CSinglePrintDoc::~CSinglePrintDoc()
{
}

BOOL CSinglePrintDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_stringArray.SetSize(8);
	m_stringArray[0]="轻轻的我走了，";
	m_stringArray[1]="正如我轻轻的来；";
	m_stringArray[2]="我轻轻地招手，";
	m_stringArray[3]="作别西天的云彩。";
	m_stringArray[4]="那河畔的金柳，";
	m_stringArray[5]="是夕阳中的新娘；";
	m_stringArray[6]="波光里的艳影，";
	m_stringArray[7]="在我心头荡漾。";
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSinglePrintDoc serialization

void CSinglePrintDoc::Serialize(CArchive& ar)
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

/////////////////////////////////////////////////////////////////////////////
// CSinglePrintDoc diagnostics

#ifdef _DEBUG
void CSinglePrintDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSinglePrintDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSinglePrintDoc commands
