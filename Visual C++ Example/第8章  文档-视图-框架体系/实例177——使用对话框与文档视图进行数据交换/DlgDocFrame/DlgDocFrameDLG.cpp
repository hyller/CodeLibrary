// DlgDocFrameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DlgDocFrame.h"
#include "DlgDocFrameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgDocFrameDlg dialog


CDlgDocFrameDlg::CDlgDocFrameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgDocFrameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgDocFrameDlg)
	m_dbX = 0.0;
	m_dbY = 0.0;
	//}}AFX_DATA_INIT
}


void CDlgDocFrameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDocFrameDlg)
	DDX_Text(pDX, IDC_EDITX, m_dbX);
	DDX_Text(pDX, IDC_EDITY, m_dbY);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgDocFrameDlg, CDialog)
	//{{AFX_MSG_MAP(CDlgDocFrameDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDocFrameDlg message handlers
