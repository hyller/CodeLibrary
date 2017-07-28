// FloatEdit.cpp : implementation file
//

#include "stdafx.h"
#include "FloatEditDemo.h"
#include "FloatEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFloatEdit

CFloatEdit::CFloatEdit()
{
}

CFloatEdit::~CFloatEdit()
{
}


BEGIN_MESSAGE_MAP(CFloatEdit, CEdit)
	//{{AFX_MSG_MAP(CFloatEdit)
	ON_CONTROL_REFLECT(EN_CHANGE, OnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFloatEdit message handlers

int CFloatEdit::GetStringNum(CString str)//获得字符串中间.号的个数
{
	int nNum=0; 
	while(1)
	{ 
		int nCount=str.Find('.');//查找.号
		if(nCount==-1)
		break; 
		str=str.Right(str.GetLength()-nCount-1); //提取.号右边的字符串
		nNum++;
	} 
	return nNum;
}


void CFloatEdit::OnChange() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CEdit::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	CString m_estr,szTemp;
	GetWindowText(m_estr);//获取编辑框文本
	int nLen=m_estr.GetLength();//获取文本长度
	if(!m_estr.IsEmpty())
	{
		szTemp=m_estr.Right(1);
		BOOL bNum=TRUE;
		CString strtemp=szTemp.SpanIncluding("0123456789");
		if(!strtemp.IsEmpty()) //这个字符串为数字
		bNum=TRUE;
		else 
			bNum=FALSE;
		int nPoint=GetStringNum(m_estr);//查找.号的个数
		if(strcmp(szTemp,".")==0 || bNum)
		{
			if(nPoint>1)//.号多于1个
			{
				nPoint--;
				::AfxMessageBox(".号已经存在!");
				m_estr=m_estr.Left(m_estr.GetLength()-1); //去除当前输入
				SetWindowText(m_estr); 
				nLen--;
				SendMessage(EM_SETSEL,nLen,nLen);//设置输入位置
				return;
			}
		}
		else//输入字符不为数字
		{
			::AfxMessageBox("请输入数字或.号");
			m_estr=m_estr.Left(m_estr.GetLength()-1);//去除当前输入
			SetWindowText(m_estr);
			nLen--;
			SendMessage(EM_SETSEL,nLen,nLen);//设置输入位置
			return; 
		}
	} 
}
