// EDesktopExampleView.cpp : implementation of the CEDesktopExampleView class
//

#include "stdafx.h"
#include "EDesktopExample.h"

#include "EDesktopExampleDoc.h"
#include "EDesktopExampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#ifdef EG_EXTERN_DEFAULT_STYLE
#ifdef EG_RGB_COLOR
#ifdef EG_RICH_STYLE
	EStyle EG_DefaultStyle(1,1);
#else
	EStyle EG_DefaultStyle;
#endif
#endif
#endif //EG_EXTERN_DEFAULT_STYLE


void HelpCallbackFunc(EControl* control,EEvent* curevent){
	::AfxMessageBox(L"help??  :)");
}

void IconButton1CallbackFunc(EControl* control,EEvent* curevent){
	if((curevent->m_uSource==1)&&(curevent->m_uMessage==1)){
		::AfxMessageBox(L"ib1");
	}
}

EClock clk(EPosition(0,0),false);
HCURSOR hCursor1,hCursor2;
EMenu startMenu("Start\0",40,EPosition(0,0),true);
EMenu::EMenuItem startMenuItem1,startMenuItem2,startMenuItem3;
EPopupMenu popupMenu;
EPopupMenu::EPopupMenuItem popupMenuItem1,popupMenuItem2;
EIconButton iconButton1(IconButton1CallbackFunc,EPosition(12,21),ESize(28,29),2,"ib1\0",false);
EWindow window1("win1\0",EPosition(12,12),ESize(100,90),true);
EWindow window2("win2\0",EPosition(30,10),ESize(80,40),true);
EWindow window3("win3\0",EPosition(40,30),ESize(80,40),true);
EButton btn1(NULL,EPosition(50,50),"btn1\0",35);
EButton btn2(NULL,EPosition(50,50),"btn1\0",35);
EToolBar tb1;
EStatusBar sb1;
EMenu menu1("menu1",40,EPosition(0,0));
EMenu menu2("menu1",40,EPosition(0,0));

// CEDesktopExampleView

void CreateNewWindowCallbackFunc(EControl* control,EEvent* curevent){
	ESimpleDesktop::GetInstance()->AddWindow(&window2);
}

IMPLEMENT_DYNCREATE(CEDesktopExampleView, CView)

BEGIN_MESSAGE_MAP(CEDesktopExampleView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_DESKTOP_CREATEDESKTOP, &CEDesktopExampleView::OnDesktopCreatedesktop)
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CEDesktopExampleView construction/destruction

CEDesktopExampleView::CEDesktopExampleView():rbd(EG_COLUMN,EG_ROW),desk(&rbd)
{
	desk.AppendClock(&clk);
	hCursor1=LoadCursor(NULL,L"IDC_CURSOR1"); 
	hCursor2=::LoadCursor(NULL,L"IDC_POINTER");
	first=true;
}

CEDesktopExampleView::~CEDesktopExampleView()
{
}

BOOL CEDesktopExampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CEDesktopExampleView drawing

void CEDesktopExampleView::OnDraw(CDC* /*pDC*/)
{
	CEDesktopExampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CEDesktopExampleView diagnostics

#ifdef _DEBUG
void CEDesktopExampleView::AssertValid() const
{
	CView::AssertValid();
}

void CEDesktopExampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEDesktopExampleDoc* CEDesktopExampleView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEDesktopExampleDoc)));
	return (CEDesktopExampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CEDesktopExampleView message handlers

void CEDesktopExampleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	this->desk.SetCursorEvent(EPosition(point.x,point.y),1);
	CView::OnLButtonDown(nFlags, point);
}

void CEDesktopExampleView::OnTimer(UINT_PTR nIDEvent)
{
	time=CTime::GetCurrentTime();   
	this->desk.UpdateTime((unsigned char)time.GetHour(),(unsigned char)time.GetMinute());
	this->desk.ScheduleRedraw();
	CView::OnTimer(nIDEvent);
}

void CEDesktopExampleView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	EPosition pos;
	POINT pot;
	GetCursorPos(&pot);
	ScreenToClient(&pot);
	pos.m_uX=pot.x;
	pos.m_uY=pot.y;
	this->desk.SetKeyboardEvent(pos,nChar);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CEDesktopExampleView::OnDesktopCreatedesktop()
{
	ESimpleDesktop::SetInstance(&(this->desk));
	this->desk.RemoveAllWindow();
#ifdef EG_CURSOR
	this->desk.SetCursorShape((unsigned char*)&EG_DefaultCursorShape);
#endif  //EG_CURSOR
	this->SetTimer(NULL,10,NULL);
	this->desk.AppendStartMenu(&startMenu);
	startMenu.AddItem(&startMenuItem1);
	startMenu.AddItem(&startMenuItem2);
	startMenu.AddItem(&startMenuItem3);
	startMenu.SetMenuItem(0,"Help\0",0,HelpCallbackFunc);
	startMenu.SetMenuItem(1,"Q&A\0",0,HelpCallbackFunc);
	startMenu.SetMenuItem(2,"????????\0",0,CreateNewWindowCallbackFunc);
	this->desk.AppendPopupMenu(&popupMenu);
	popupMenu.AddItem(&popupMenuItem1);
	popupMenu.AddItem(&popupMenuItem2);
	popupMenu.SetPopupMenuItem(0,"popupItem1\0",0,HelpCallbackFunc);
	popupMenu.SetPopupMenuItem(1,"item2\0",0,HelpCallbackFunc);
	this->desk.AddIconButton(&iconButton1);
	this->desk.AddWindow(&window1);
	window1.RemoveAllControl();
	window1.AppendToolBar(&tb1,1);
	tb1.AddItem(&btn1);
	window1.AppendStatusBar(&sb1,2);
	window1.AddControl(&btn2);
	window1.AddMenuItem(&menu1);
	window1.AddMenuItem(&menu2);
	//this->desk.AddWindow(&window3);
	this->desk.GlobalRedraw();
}

void CEDesktopExampleView::OnActivateFrame(UINT nState, CFrameWnd* pDeactivateFrame)
{
	if(this->first){   // set the device context
		HDC dc=	this->GetDC()->m_hDC;
		rbd.SetDeviceContext(dc);
		EG_LCDClearBuffer();
		this->first=false;
	}
	CView::OnActivateFrame(nState, pDeactivateFrame);
}

void CEDesktopExampleView::OnMouseMove(UINT nFlags, CPoint point)
{
#ifdef EG_CURSOR
	RECT rect;
	this->GetWindowRect(&rect);
	if((point.x<rect.right)&&(point.x>rect.left)&&(point.y>rect.bottom)&&(point.y<rect.top)){
		::SetCursor(hCursor1);
	}else{
		::SetCursor(hCursor2);
	}
	this->desk.SetCursorEvent(EPosition(point.x,point.y),0);
#endif //EG_CURSOR
	CView::OnMouseMove(nFlags, point);
}

void CEDesktopExampleView::OnRButtonDown(UINT nFlags, CPoint point)
{
	this->desk.SetCursorEvent(EPosition(point.x,point.y),2);
	CView::OnRButtonDown(nFlags, point);
}
