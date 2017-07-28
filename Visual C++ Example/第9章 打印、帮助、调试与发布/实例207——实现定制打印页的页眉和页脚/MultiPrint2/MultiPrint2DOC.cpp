// MultiPrint2Doc.cpp : implementation of the CMultiPrint2Doc class
//

#include "stdafx.h"
#include "MultiPrint2.h"

#include "MultiPrint2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiPrint2Doc

IMPLEMENT_DYNCREATE(CMultiPrint2Doc, CDocument)

BEGIN_MESSAGE_MAP(CMultiPrint2Doc, CDocument)
	//{{AFX_MSG_MAP(CMultiPrint2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiPrint2Doc construction/destruction

CMultiPrint2Doc::CMultiPrint2Doc()
{
	// TODO: add one-time construction code here
	m_LinePerPage=6;//每页打印6行
}

CMultiPrint2Doc::~CMultiPrint2Doc()
{
}

BOOL CMultiPrint2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_stringArray.SetSize(16);
	m_stringArray[0]="轻轻的我走了，";
	m_stringArray[1]="正如我轻轻的来；";
	m_stringArray[2]="我轻轻地招手，";
	m_stringArray[3]="作别西天的云彩。";
	m_stringArray[4]="那河畔的金柳，";
	m_stringArray[5]="是夕阳中的新娘；";
	m_stringArray[6]="波光里的艳影，";
	m_stringArray[7]="在我心头荡漾。";
	m_stringArray[8]="软泥上的青荇，";
	m_stringArray[9]="油油的在水底招摇；";
	m_stringArray[10]="在康河的柔波里，";
	m_stringArray[11]="我甘心做一条水草。";
	m_stringArray[12]="那榆荫下的一潭，";
	m_stringArray[13]="不是清泉，是天上虹；";
	m_stringArray[14]="揉碎的浮藻间，";
	m_stringArray[15]="沉淀着彩虹似的梦。";

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMultiPrint2Doc serialization

void CMultiPrint2Doc::Serialize(CArchive& ar)
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
// CMultiPrint2Doc diagnostics

#ifdef _DEBUG
void CMultiPrint2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMultiPrint2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMultiPrint2Doc commands
