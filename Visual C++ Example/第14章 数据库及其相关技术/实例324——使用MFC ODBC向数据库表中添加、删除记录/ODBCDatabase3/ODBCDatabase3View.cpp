// ODBCDatabase3View.cpp : implementation of the CODBCDatabase3View class
//

#include "stdafx.h"
#include "ODBCDatabase3.h"

#include "ODBCDatabase3Set.h"
#include "ODBCDatabase3Doc.h"
#include "ODBCDatabase3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase3View

IMPLEMENT_DYNCREATE(CODBCDatabase3View, CRecordView)

BEGIN_MESSAGE_MAP(CODBCDatabase3View, CRecordView)
	//{{AFX_MSG_MAP(CODBCDatabase3View)
	ON_BN_CLICKED(IDC_ADDRECORD, OnAddrecord)
	ON_BN_CLICKED(IDC_DELETERECORD, OnDeleterecord)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase3View construction/destruction

CODBCDatabase3View::CODBCDatabase3View()
	: CRecordView(CODBCDatabase3View::IDD)
{
	//{{AFX_DATA_INIT(CODBCDatabase3View)
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CODBCDatabase3View::~CODBCDatabase3View()
{
}

void CODBCDatabase3View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CODBCDatabase3View)
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_stuno, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_name, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->m_sex, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT4, m_pSet->m_Age, m_pSet);
	//}}AFX_DATA_MAP
}

BOOL CODBCDatabase3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CODBCDatabase3View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ODBCDatabase3Set;
	CRecordView::OnInitialUpdate();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase3View printing

BOOL CODBCDatabase3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CODBCDatabase3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CODBCDatabase3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase3View diagnostics

#ifdef _DEBUG
void CODBCDatabase3View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CODBCDatabase3View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CODBCDatabase3Doc* CODBCDatabase3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CODBCDatabase3Doc)));
	return (CODBCDatabase3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase3View database support
CRecordset* CODBCDatabase3View::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CODBCDatabase3View message handlers

void CODBCDatabase3View::OnAddrecord() //添加记录
{
	// TODO: Add your control notification handler code here
	m_pSet->AddNew();//添加新记录
    m_bAddMode=TRUE;
	CEdit *pCtrl=(CEdit *)GetDlgItem(IDC_EDIT1);
	int result=pCtrl->SetReadOnly (FALSE);//设置学号编辑框可编辑
	UpdateData(FALSE);//显示
	GetDlgItem(IDC_ADDRECORD)->EnableWindow(false);
}

BOOL CODBCDatabase3View::OnMove(UINT nIDMoveCommand) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_bAddMode)
	{
		GetDlgItem(IDC_ADDRECORD)->EnableWindow(true);
		m_bAddMode=FALSE;
	    UpdateData(TRUE);
	    if(!m_pSet->CanUpdate())//记录可以更新
			return FALSE;
		TRY
		{
		     m_pSet->Update();//更新记录
		}
		CATCH(CDBException,e)
		{
			AfxMessageBox(e->m_strError);
			return FALSE;
		}
		END_CATCH;
	     m_pSet->Requery();	//查询记录
         UpdateData(FALSE);
         CEdit *pCtrl=(CEdit *)GetDlgItem(IDC_EDIT1);
	     pCtrl->SetReadOnly (TRUE);//设置学号为只读
	     return TRUE;
	}
	return CRecordView::OnMove(nIDMoveCommand);
}

void CODBCDatabase3View::OnDeleterecord() 
{
	// TODO: Add your control notification handler code here
		m_pSet->Delete();//删除当前记录
		m_pSet->MoveNext();//移到下一个记录
		if(	m_pSet->IsEOF())
			m_pSet->MoveLast();
		if(	m_pSet->IsBOF())
			m_pSet->SetFieldNull(NULL);
		UpdateData(FALSE);	
}
