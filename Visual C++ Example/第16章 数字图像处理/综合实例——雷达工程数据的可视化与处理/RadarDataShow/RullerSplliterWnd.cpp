// RullerSplliterWnd.cpp : implementation file
//

#include "stdafx.h"
#include "RadarDataShow.h"
#include "RullerSplliterWnd.h"

#include "RulerView.h"
#include "CornerView.h"
#include "AscanView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRullerSplliterWnd
IMPLEMENT_DYNCREATE(CRullerSplliterWnd, CMDIChildWnd)
CRullerSplliterWnd::CRullerSplliterWnd()
{
	m_cxSplitter     = 0;
	m_cySplitter     = 0;
	m_cxBorderShare  = 0;
	m_cyBorderShare  = 0;
	m_cxSplitterGap  = 1;
	m_cySplitterGap  = 1;

}

CRullerSplliterWnd::~CRullerSplliterWnd()
{
}


BEGIN_MESSAGE_MAP(CRullerSplliterWnd, CSplitterWnd)
	//{{AFX_MSG_MAP(CRullerSplliterWnd)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRullerSplliterWnd message handlers
BOOL CRullerSplliterWnd::CreateRulers(CFrameWnd *pParent, CCreateContext *pContext)
{
	if (!CreateStatic(pParent, 2, 3))	//两行三列			
		return FALSE;																																	
	if (!CreateView(0, 0, RUNTIME_CLASS(CCornerView), CSize(0,0), pContext))//左上角视图				
		return FALSE;
	if (!CreateView(0, 2, RUNTIME_CLASS(CCornerView), CSize(0,0), pContext))//右上角视图				
		return FALSE;
	if (!CreateView(0, 1, RUNTIME_CLASS(CRulerView), CSize(0,0), pContext))	//水平标尺视图				
		return FALSE;														
	if (!CreateView(1, 0, RUNTIME_CLASS(CRulerView), CSize(0,0), pContext))//垂直标尺视图					
		return FALSE;														
	if (!CreateView(1, 1, pContext->m_pNewViewClass, CSize(0,0),pContext))	//图像视图				
		return FALSE;														
	if (!CreateView(1, 2, RUNTIME_CLASS(CAscanView), CSize(0,0), pContext))	//波形视图				
		return FALSE;																		
	SetColumnInfo(0, 0, 0);	
	SetColumnInfo(1, 0, 0);	
	SetRowInfo(0, 0, 0);																							
	((CRulerView*)GetPane(0, 1))->SetRulerType(RT_HORIZONTAL);//指定水平标尺										
	((CRulerView*)GetPane(1, 0))->SetRulerType(RT_VERTICAL);//指定垂直标尺   
    SetActivePane(1, 1);	 //将图像窗格设置为活动视图  
    return TRUE;
}

void CRullerSplliterWnd::ShowRulers()
{
	int nSize       = 16;//标尺窗格的尺寸
    int nSizeBorder = 3;//分割条尺寸

    SetRowInfo(0, nSize, 0);//水平标尺窗格高度
    SetColumnInfo(0, nSize, 0);//垂直标尺窗格宽度
	SetColumnInfo(1,(GetSystemMetrics(SM_CXSCREEN)-128), 0);//设置图像显示窗口尺寸	
    m_cxSplitterGap  = nSizeBorder;//分割条尺寸
	m_cySplitterGap  = nSizeBorder;
    RecalcLayout();//重新排列窗格
}

void CRullerSplliterWnd::UpdateRulersInfo(stRULER_INFO stRulerInfo)
{

	((CRulerView*)GetPane(0, 1))->UpdateRulersInfo(stRulerInfo);//更新水平标尺
	((CRulerView*)GetPane(1, 0))->UpdateRulersInfo(stRulerInfo);//更新垂直标尺
}
