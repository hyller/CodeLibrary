// ScaleDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Sketcher.h"
#include "ScaleDialog.h"


// CScaleDialog dialog

IMPLEMENT_DYNAMIC(CScaleDialog, CDialog)

CScaleDialog::CScaleDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CScaleDialog::IDD, pParent)
  , m_Scale(0)
{

}

CScaleDialog::~CScaleDialog()
{
}

void CScaleDialog::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  DDX_LBIndex(pDX, IDC_SCALE_LIST, m_Scale);
	DDV_MinMaxInt(pDX, m_Scale, 0, 7);
}


BEGIN_MESSAGE_MAP(CScaleDialog, CDialog)
END_MESSAGE_MAP()


// CScaleDialog message handlers


BOOL CScaleDialog::OnInitDialog()
{
  CDialog::OnInitDialog();

  CListBox* pListBox = static_cast<CListBox*>(GetDlgItem(IDC_SCALE_LIST));
  CString scaleStr;
  for(int i = 1 ; i <= 8 ; ++i)
  {
    scaleStr.Format(_T("Scale %d"), i);
    pListBox->AddString(scaleStr);
  }
  pListBox->SetCurSel(m_Scale);        // Set current scale

  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}
