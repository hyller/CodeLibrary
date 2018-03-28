// MagicBox.h : Declaration of the CMagicBox

#ifndef __MAGICBOX_H_
#define __MAGICBOX_H_

#include "resource.h"       // main symbols
#include <atlctl.h>
#include "MagicBoxerCP.h"


/////////////////////////////////////////////////////////////////////////////
// CMagicBox
class ATL_NO_VTABLE CMagicBox : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CStockPropImpl<CMagicBox, IMagicBox, &IID_IMagicBox, &LIBID_MAGICBOXERLib>,
	public CComControl<CMagicBox>,
	public IPersistStreamInitImpl<CMagicBox>,
	public IOleControlImpl<CMagicBox>,
	public IOleObjectImpl<CMagicBox>,
	public IOleInPlaceActiveObjectImpl<CMagicBox>,
	public IViewObjectExImpl<CMagicBox>,
	public IOleInPlaceObjectWindowlessImpl<CMagicBox>,
	public IConnectionPointContainerImpl<CMagicBox>,
	public IPersistStorageImpl<CMagicBox>,
	public ISpecifyPropertyPagesImpl<CMagicBox>,
	public IQuickActivateImpl<CMagicBox>,
	public IDataObjectImpl<CMagicBox>,
	public IProvideClassInfo2Impl<&CLSID_MagicBox, &DIID__IMagicBoxEvents, &LIBID_MAGICBOXERLib>,
	public IPropertyNotifySinkCP<CMagicBox>,
	public CComCoClass<CMagicBox, &CLSID_MagicBox>,
	public CProxy_IMagicBoxEvents< CMagicBox >
{
public:
	BOOL m_bfilltype;         									//填充模式
	CMagicBox()
	{
		m_bfilltype=TRUE;										//初始化
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MAGICBOX)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CMagicBox)
	COM_INTERFACE_ENTRY(IMagicBox)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

BEGIN_PROP_MAP(CMagicBox)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	PROP_ENTRY("BackColor", DISPID_BACKCOLOR, CLSID_StockColorPage)
	PROP_ENTRY("FillColor", DISPID_FILLCOLOR, CLSID_StockColorPage)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CMagicBox)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
	CONNECTION_POINT_ENTRY(DIID__IMagicBoxEvents)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CMagicBox)
	CHAIN_MSG_MAP(CComControl<CMagicBox>)
	DEFAULT_REFLECTION_HANDLER()
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);



// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IMagicBox
public:

	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		RECT& rc = *(RECT*)di.prcBounds;
		HBRUSH hBrush;										//画刷
		if(m_bfilltype)
			hBrush = CreateSolidBrush(m_clrBackColor);				//背景色
		else
			hBrush = CreateSolidBrush(m_clrFillColor);					//填充色
		SelectObject(di.hdcDraw, hBrush);
		Rectangle(di.hdcDraw, rc.left,rc.top,rc.right,rc.bottom/2);				//绘制上半部分的矩形
		if(m_bfilltype)
			hBrush = CreateSolidBrush(m_clrFillColor);					//填充色
		else
			hBrush = CreateSolidBrush(m_clrBackColor);				//背景色
		SelectObject(di.hdcDraw, hBrush);
		Rectangle(di.hdcDraw, rc.left,rc.bottom/2,rc.right,rc.bottom);			//绘制下半部分的矩形
		return S_OK;
	}
	OLE_COLOR m_clrBackColor;
	OLE_COLOR m_clrFillColor;
	LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// TODO : Add Code for message handler. Call DefWindowProc if necessary.
		WORD x=LOWORD(lParam);									//鼠标x坐标
		WORD y=HIWORD(lParam);									//鼠标y坐标
		m_bfilltype=!m_bfilltype;
		FireViewChange();											//更新视图
		Fire_ClickBox(x,y);												//触发Click事件
		return 0;
	}
};

#endif //__MAGICBOX_H_
