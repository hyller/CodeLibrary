// PenDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Sketcher.h"
#include "PenDialog.h"


// CPenDialog dialog

IMPLEMENT_DYNAMIC(CPenDialog, CDialog)

CPenDialog::CPenDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CPenDialog::IDD, pParent)
, m_PenWidth(0)
{

}

CPenDialog::~CPenDialog()
{
}

void CPenDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPenDialog, CDialog)
  ON_BN_CLICKED(IDC_PENWIDTH0, &CPenDialog::OnPenwidth0)
  ON_BN_CLICKED(IDC_PENWIDTH1, &CPenDialog::OnPenwidth1)
  ON_BN_CLICKED(IDC_PENWIDTH2, &CPenDialog::OnPenwidth2)
  ON_BN_CLICKED(IDC_PENWIDTH3, &CPenDialog::OnPenwidth3)
  ON_BN_CLICKED(IDC_PENWIDTH4, &CPenDialog::OnPenwidth4)
  ON_BN_CLICKED(IDC_PENWIDTH5, &CPenDialog::OnPenwidth5)
END_MESSAGE_MAP()


// CPenDialog message handlers


BOOL CPenDialog::OnInitDialog()
{
  CDialog::OnInitDialog();

   // Check the radio button corresponding to the pen width
   switch(m_PenWidth)
   {
      case 1:
         CheckDlgButton(IDC_PENWIDTH1,1);
         break;
      case 2:
         CheckDlgButton(IDC_PENWIDTH2,1);
         break;
      case 3:
         CheckDlgButton(IDC_PENWIDTH3,1);
         break;
      case 4:
         CheckDlgButton(IDC_PENWIDTH4,1);
         break;
      case 5:
         CheckDlgButton(IDC_PENWIDTH5,1);
         break;
      default:
         CheckDlgButton(IDC_PENWIDTH0,1);
   }

  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}


void CPenDialog::OnPenwidth0()
{
   m_PenWidth = 0;
}


void CPenDialog::OnPenwidth1()
{
   m_PenWidth = 1;
}


void CPenDialog::OnPenwidth2()
{
   m_PenWidth = 2;
}


void CPenDialog::OnPenwidth3()
{
   m_PenWidth = 3;
}


void CPenDialog::OnPenwidth4()
{
   m_PenWidth = 4;
}


void CPenDialog::OnPenwidth5()
{
   m_PenWidth = 5;
}
