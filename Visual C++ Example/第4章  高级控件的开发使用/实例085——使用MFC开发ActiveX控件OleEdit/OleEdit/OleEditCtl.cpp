// OleEditCtl.cpp : Implementation of the COleEditCtrl ActiveX Control class.

#include "stdafx.h"
#include "OleEdit.h"
#include "OleEditCtl.h"
#include "OleEditPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(COleEditCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(COleEditCtrl, COleControl)
	//{{AFX_MSG_MAP(COleEditCtrl)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
	ON_MESSAGE(OCM_COMMAND, OnOcmCommand)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(COleEditCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(COleEditCtrl)
	DISP_PROPERTY_NOTIFY(COleEditCtrl, "bNumbers", m_bNumbers, OnBNumbersChanged, VT_BOOL)
	DISP_PROPERTY_NOTIFY(COleEditCtrl, "bText", m_bText, OnBTextChanged, VT_BOOL)
	DISP_STOCKPROP_FONT()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(COleEditCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(COleEditCtrl, COleControl)
	//{{AFX_EVENT_MAP(COleEditCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(COleEditCtrl, 2)//两个属性
	PROPPAGEID(COleEditPropPage::guid)
	PROPPAGEID(CLSID_CFontPropPage)//字体属性
END_PROPPAGEIDS(COleEditCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(COleEditCtrl, "OLEEDIT.OleEditCtrl.1",
	0xa2e1c1d, 0x5f28, 0x4850, 0x91, 0x29, 0x8d, 0x55, 0xe9, 0xb6, 0xbb, 0x6d)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(COleEditCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DOleEdit =
		{ 0x288788d5, 0xf3bf, 0x4880, { 0x97, 0xb4, 0xcd, 0x1, 0x74, 0x4e, 0x44, 0x91 } };
const IID BASED_CODE IID_DOleEditEvents =
		{ 0x87969e28, 0x660, 0x49cb, { 0xa9, 0x9a, 0x3f, 0x34, 0x55, 0x23, 0x32, 0xea } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwOleEditOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(COleEditCtrl, IDS_OLEEDIT, _dwOleEditOleMisc)


/////////////////////////////////////////////////////////////////////////////
// COleEditCtrl::COleEditCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for COleEditCtrl

BOOL COleEditCtrl::COleEditCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_OLEEDIT,
			IDB_OLEEDIT,
			afxRegApartmentThreading,
			_dwOleEditOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// COleEditCtrl::COleEditCtrl - Constructor

COleEditCtrl::COleEditCtrl()
{
	InitializeIIDs(&IID_DOleEdit, &IID_DOleEditEvents);
	// TODO: Initialize your control's instance data here.
	m_bNumbers=true;//初始化属性
	m_bText=true;
}


/////////////////////////////////////////////////////////////////////////////
// COleEditCtrl::~COleEditCtrl - Destructor

COleEditCtrl::~COleEditCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// COleEditCtrl::OnDraw - Drawing function

void COleEditCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	COLORREF ClrBackground=TranslateColor(GetBackColor());//将背景色从OLE_COLOR类型转换为COLORREF类型 
	CBrush *pOldBrush;
	CBrush bBackground(ClrBackground);
	pdc->FillRect(rcBounds,&bBackground);//将控件矩形填充为背景色
	pOldBrush=pdc->SelectObject(pOldBrush);	
	DoSuperclassPaint(pdc, rcBounds);//重绘控件
	CRect rc(rcBounds);
	pdc->DrawEdge(rc,EDGE_SUNKEN,BF_RECT);//绘制边框
}


/////////////////////////////////////////////////////////////////////////////
// COleEditCtrl::DoPropExchange - Persistence support

void COleEditCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
	PX_Bool(pPX,_T("bNumbers"),m_bNumbers);
	PX_Bool(pPX,_T("bText"),m_bText);

}


/////////////////////////////////////////////////////////////////////////////
// COleEditCtrl::OnResetState - Reset control to default state

void COleEditCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// COleEditCtrl::AboutBox - Display an "About" box to the user

void COleEditCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_OLEEDIT);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// COleEditCtrl::PreCreateWindow - Modify parameters for CreateWindowEx

BOOL COleEditCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("EDIT");
	return COleControl::PreCreateWindow(cs);
}


/////////////////////////////////////////////////////////////////////////////
// COleEditCtrl::IsSubclassedControl - This is a subclassed control

BOOL COleEditCtrl::IsSubclassedControl()
{
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// COleEditCtrl::OnOcmCommand - Handle command messages

LRESULT COleEditCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
#ifdef _WIN32
	WORD wNotifyCode = HIWORD(wParam);
#else
	WORD wNotifyCode = HIWORD(lParam);
#endif

	// TODO: Switch on wNotifyCode here.

	return 0;
}


/////////////////////////////////////////////////////////////////////////////
// COleEditCtrl message handlers

void COleEditCtrl::OnBNumbersChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void COleEditCtrl::OnBTextChanged() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}

void COleEditCtrl::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(_istdigit(nChar))//输入为数字
	{
		if(!m_bNumbers)//数字属性未被选中
		{
			FireError(CTL_E_INVALIDPROPERTYVALUE,_T("不允许输入数字"));//给出错误提示
		}
		else
		{
			COleControl::OnChar(nChar, nRepCnt, nFlags);//正常执行
		}
	}
	else if(_istalpha(nChar))//输入为字符
	{
		if(!m_bText)//字符属性未被选中
		{
			FireError(CTL_E_INVALIDPROPERTYVALUE,_T("不允许输入字符"));//给出错误提示
		}
		else
		{
			COleControl::OnChar(nChar, nRepCnt, nFlags);//正常执行
		}
	}
	else
		COleControl::OnChar(nChar, nRepCnt, nFlags);//正常执行
		

}
