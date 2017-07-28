// ColoarDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DlgRegularDll.h"
#include "ColoarDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColoarDlg dialog


CColoarDlg::CColoarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CColoarDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CColoarDlg)
	m_Red = 0;
	m_Green = 0;
	m_Blue = 0;
	//}}AFX_DATA_INIT
}


void CColoarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CColoarDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Red);
	DDV_MinMaxInt(pDX, m_Red, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, m_Green);
	DDV_MinMaxInt(pDX, m_Green, 0, 255);
	DDX_Text(pDX, IDC_EDIT3, m_Blue);
	DDV_MinMaxInt(pDX, m_Blue, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CColoarDlg, CDialog)
	//{{AFX_MSG_MAP(CColoarDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColoarDlg message handlers

void CColoarDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}
