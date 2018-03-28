// MedicListView.cpp : implementation file
//

#include "stdafx.h"
#include "MedicAdmin.h"
#include "MedicListView.h"
#include "MedicAdminDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMedicListView

IMPLEMENT_DYNCREATE(CMedicListView, CListView)

CMedicListView::CMedicListView()
{
}

CMedicListView::~CMedicListView()
{
}


BEGIN_MESSAGE_MAP(CMedicListView, CListView)
	//{{AFX_MSG_MAP(CMedicListView)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMedicListView drawing

void CMedicListView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CMedicListView diagnostics

#ifdef _DEBUG
void CMedicListView::AssertValid() const
{
	CListView::AssertValid();
}

void CMedicListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMedicListView message handlers

void CMedicListView::OnInitialUpdate() 
{
	CListView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	CFrameWnd* pWnd=(CFrameWnd*)AfxGetMainWnd();
	CMedicAdminDoc* pDoc=(CMedicAdminDoc*)pWnd->GetActiveDocument();
	medicSet=&pDoc->theMedicSet;
	if(medicSet->IsOpen())
	{
		medicSet->Close();
	}
	medicSet->Open();
	saleSet=&pDoc->theSaleSet;
	if(saleSet->IsOpen())
	{
		saleSet->Close();
	}
	saleSet->Open();
	medicSet->m_strFilter="";
	medicSet->Requery();
	CString str;
	for(int i=0;;i++)
	{
		if(medicSet->IsEOF())
		{
			break;
		}
		theListCtrl->InsertItem(i,medicSet->m_MedicineID);
		theListCtrl->SetItemText(i,1,medicSet->m_MedicineName);
		theListCtrl->SetItemText(i,2,medicSet->m_MedicineClassification);
		str.Format("%d",medicSet->m_MedicineNumber);
		theListCtrl->SetItemText(i,3,str);
		theListCtrl->SetItemText(i,4,medicSet->m_ProduceCompany);
		theListCtrl->SetItemText(i,5,medicSet->m_Produceplace);
		CTime produceTime=medicSet->m_ProduceDate;
		str=produceTime.Format("%B %d,%Y");
		theListCtrl->SetItemText(i,6,str);
		str.Format("%d",medicSet->m_QeulityAssurancePeriod);
		theListCtrl->SetItemText(i,7,str);
		str.Format("%f",medicSet->m_UnitPrice);
		theListCtrl->SetItemText(i,8,str);
		medicSet->MoveNext();
	}
}

int CMedicListView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;	
	// TODO: Add your specialized creation code here
	theListCtrl=&GetListCtrl();
	ModifyStyle(0,LVS_REPORT);
	ASSERT(GetStyle() & LVS_REPORT);
	CString medicField[9]={"药品代号","药品名称","药品类别","库存数量","出产公司","产地","出产时间","保质期(月)","单价(元)"};
	for(int i=0;i<8;i++)
	{
		theListCtrl->InsertColumn(i,medicField[i],LVCFMT_LEFT,70);
	}
	theListCtrl->InsertColumn(8,medicField[8],LVCFMT_LEFT,58);
	return 0;
}
