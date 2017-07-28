// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MedicAdmin.h"

#include "MainFrm.h"
#include "UserTreeView.h"
#include "user.h"
#include "MedicAdminDoc.h"
#include "changePasswordDlg.h"
#include "UserChangDlg.h"
#include "RegisterUserDlg.h"
#include "DeleteUserDlg.h"
#include "SeekUserDlg.h"
#include "CleanUpDlg.h"
#include "storeDlg.h"
#include "saleDlg.h"
#include "MedicListView.h"
#include "searchIDDlg.h"
#include "searchNameDlg.h"
#include "searchTypeDlg.h"
#include "MedicSearch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_CHANGE_PASSWORD, OnChangePassword)
	ON_COMMAND(ID_CHANGE_USER, OnChangeUser)
	ON_COMMAND(ID_REGISTER_USER, OnRegisterUser)
	ON_UPDATE_COMMAND_UI(ID_REGISTER_USER, OnUpdateRegisterUser)
	ON_COMMAND(ID_DELETE_USER, OnDeleteUser)
	ON_UPDATE_COMMAND_UI(ID_DELETE_USER, OnUpdateDeleteUser)
	ON_COMMAND(ID_SELECT_USER, OnSelectUser)
	ON_COMMAND(ID_EXIT, OnExit)
	ON_COMMAND(ID_CLEAN_UP, OnCleanUp)
	ON_UPDATE_COMMAND_UI(ID_CLEAN_UP, OnUpdateCleanUp)
	ON_COMMAND(ID_STORE, OnStore)
	ON_UPDATE_COMMAND_UI(ID_STORE, OnUpdateStore)
	ON_COMMAND(ID_SALE, OnSale)
	ON_WM_CLOSE()
	ON_COMMAND(ID_SEEK_BY_ID, OnSeekById)
	ON_COMMAND(ID_SEEK_BY_NAME, OnSeekByName)
	ON_COMMAND(ID_SEEK_BY_TYPE, OnSeekByType)
	ON_COMMAND(ID_SEEK_ALL, OnSeekAll)
	ON_COMMAND(ID_SEEK_ZERO_NUMBER, OnSeekZeroNumber)
	ON_COMMAND(ID_SEEK_OVERDUE, OnSeekOverdue)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers




BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_wndSplitter.CreateStatic(this,1,2);
	m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CUserTreeView),CSize(130,600),pContext);
	m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CMedicListView),CSize(700,600),pContext);
	return TRUE;
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}

void CMainFrame::OnChangePassword() 
{
	// TODO: Add your command handler code here
	CUser* theUser=&((CMedicAdminDoc*)GetActiveDocument())->theUser;
	CChangePasswordDlg CPDlg;
	CPDlg.m_account=theUser->GetAccount();
	CPDlg.DoModal();
}

void CMainFrame::OnChangeUser() 
{
	// TODO: Add your command handler code here
	CUserChangDlg CUDlg;
	CUDlg.DoModal();
}

void CMainFrame::OnRegisterUser() 
{
	// TODO: Add your command handler code here
	CRegisterUserDlg regDlg;
	regDlg.DoModal();
}


void CMainFrame::OnUpdateRegisterUser(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CUser* theUser=&((CMedicAdminDoc*)GetActiveDocument())->theUser;
	if(theUser->GetType()=="管理员")
	{
		pCmdUI->Enable();
	}
	else
	{
		pCmdUI->Enable(FALSE);
	}
}


void CMainFrame::OnDeleteUser() 
{
	// TODO: Add your command handler code here
	CDeleteUserDlg delUserDlg;
	delUserDlg.DoModal();
}


void CMainFrame::OnUpdateDeleteUser(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CUser* theUser=&((CMedicAdminDoc*)GetActiveDocument())->theUser;
	if(theUser->GetType()=="管理员")
	{
		pCmdUI->Enable();
	}
	else
	{
		pCmdUI->Enable(FALSE);
	}
}


void CMainFrame::OnSelectUser() 
{
	// TODO: Add your command handler code here
	CSeekUserDlg seekUserDlg;
	seekUserDlg.DoModal();
}

void CMainFrame::OnExit() 
{
	// TODO: Add your command handler code here
	/*int flag=AfxMessageBox("确实要退出系统吗?",MB_OKCANCEL);
	if(flag==IDOK)
	{
		ExitProcess(1);
	}*/
	OnClose();
}

void CMainFrame::OnCleanUp() 
{
	// TODO: Add your command handler code here
	CCleanUpDlg cleanUpDlg;
	cleanUpDlg.DoModal();
}

void CMainFrame::OnUpdateCleanUp(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CUser* theUser=&((CMedicAdminDoc*)GetActiveDocument())->theUser;
	if(theUser->GetType()=="管理员")
	{
		pCmdUI->Enable();
	}
	else
	{
		pCmdUI->Enable(FALSE);
	}
}

void CMainFrame::OnStore() 
{
	// TODO: Add your command handler code here
	CStoreDlg storeDlg;
	storeDlg.DoModal();
}

void CMainFrame::OnUpdateStore(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CUser* theUser=&((CMedicAdminDoc*)GetActiveDocument())->theUser;
	if(theUser->GetType()=="管理员")
	{
		pCmdUI->Enable();
		//pCmdUI->setVisible();
	}
	else
	{
		pCmdUI->Enable(FALSE);
	}
}

void CMainFrame::OnSale() 
{
	// TODO: Add your command handler code here
	CSaleDlg saleDlg;
	saleDlg.DoModal();
}

void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	int flag=AfxMessageBox("确实要退出系统吗?",MB_OKCANCEL);
	if(flag==IDOK)
	{
		CFrameWnd::OnClose();
	}
}

void CMainFrame::OnSeekById() 
{
	// TODO: Add your command handler code here
	CSearchIDDlg idDlg;
	idDlg.DoModal();
}

void CMainFrame::OnSeekByName() 
{
	// TODO: Add your command handler code here
	CSearchNameDlg nameDlg;
	nameDlg.DoModal();
}

void CMainFrame::OnSeekByType() 
{
	// TODO: Add your command handler code here
	CSearchTypeDlg typeDlg;
	typeDlg.DoModal();
}

void CMainFrame::OnSeekAll() 
{
	// TODO: Add your command handler code here
	CMedicSearch medicSearch;
	CMedicAdminDoc* pDoc=(CMedicAdminDoc*)GetActiveDocument();
	CMedicSet* theMedicSet=&pDoc->theMedicSet;
	POSITION pos=pDoc->GetFirstViewPosition();
	while(pos != NULL)
	{
		CView* pView=pDoc->GetNextView(pos);
		if(pView->IsKindOf(RUNTIME_CLASS(CMedicListView)))
		{
			CListCtrl* theListCtrl=((CMedicListView*)pView)->theListCtrl;
			medicSearch.SetListCtrl(theListCtrl);
			medicSearch.SetMedicSet(theMedicSet);
			medicSearch.SearchAll();
		}
	}
}

void CMainFrame::OnSeekZeroNumber() 
{
	// TODO: Add your command handler code here
	CMedicSearch medicSearch;
	CMedicAdminDoc* pDoc=(CMedicAdminDoc*)GetActiveDocument();
	CMedicSet* theMedicSet=&pDoc->theMedicSet;
	POSITION pos=pDoc->GetFirstViewPosition();
	while(pos != NULL)
	{
		CView* pView=pDoc->GetNextView(pos);
		if(pView->IsKindOf(RUNTIME_CLASS(CMedicListView)))
		{
			CListCtrl* theListCtrl=((CMedicListView*)pView)->theListCtrl;
			medicSearch.SetListCtrl(theListCtrl);
			medicSearch.SetMedicSet(theMedicSet);
			medicSearch.SearchZeroNumber();
		}
	}
}

void CMainFrame::OnSeekOverdue() 
{
	// TODO: Add your command handler code here
	CMedicSearch medicSearch;
	CMedicAdminDoc* pDoc=(CMedicAdminDoc*)GetActiveDocument();
	CMedicSet* theMedicSet=&pDoc->theMedicSet;
	POSITION pos=pDoc->GetFirstViewPosition();
	while(pos != NULL)
	{
		CView* pView=pDoc->GetNextView(pos);
		if(pView->IsKindOf(RUNTIME_CLASS(CMedicListView)))
		{
			CListCtrl* theListCtrl=((CMedicListView*)pView)->theListCtrl;
			medicSearch.SetListCtrl(theListCtrl);
			medicSearch.SetMedicSet(theMedicSet);
			medicSearch.SearchOverdueMedic();
		}
	}
}
