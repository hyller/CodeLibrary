#include "StdAfx.h"
#include "DlgRegularDll.h"
#include "ColoarDlg.h"
extern "C" _declspec(dllexport)ShowDlg(int m_r,int m_g,int m_b)	//导出函数
{  
	AFX_MANAGE_STATE(AfxGetStaticModuleState());				//获取DLL模块状态
	CColoarDlg dlg;											//创建对话框对象
	dlg.m_Red=m_r;										//给对话框控件变量赋值
	dlg.m_Green=m_g;										//给对话框控件变量赋值
	dlg.m_Blue=m_b;										//给对话框控件变量赋值
	dlg.DoModal();						//创建模态对话框
}
