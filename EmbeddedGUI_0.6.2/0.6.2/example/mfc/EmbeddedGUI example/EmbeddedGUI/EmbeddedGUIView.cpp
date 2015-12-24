// EmbeddedGUIView.cpp : implementation of the CEmbeddedGUIView class
//

#include "stdafx.h"
#include "EmbeddedGUI.h"

#include "EmbeddedGUIDoc.h"
#include "EmbeddedGUIView.h"

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif

#include "GraphicFunc.h"
#include "BufferDriver.h"
//#include "EControl.h"
#include "EFrame.h"

void progressPlusCallback(EControl* control,EEvent* curevent);

void buttonCallback(EControl* control,EEvent* curevent){
	if((curevent->m_uSource==1)&&(curevent->m_uMessage==1))
		::AfxMessageBox(L"button event received");
}

void icon1CBF(EControl* control,EEvent* curevent){
	::AfxMessageBox(L"icon1");
}

void icon2CBF(EControl* control,EEvent* curevent){
	::AfxMessageBox(L"icon2");
}

void menuitem1CBF(EControl* control,EEvent* curevent){
	::AfxMessageBox(L"menu1");
}

void menuitem2CBF(EControl* control,EEvent* curevent){
	::AfxMessageBox(L"menu2");
}

void menuitem3CBF(EControl* control,EEvent* curevent){
	::AfxMessageBox(L"menu3");
}

#ifdef EG_EXTERN_DEFAULT_STYLE
#ifdef EG_RGB_COLOR
#ifdef EG_RICH_STYLE
	EStyle EG_DefaultStyle(1,1);
#else
	EStyle EG_DefaultStyle;
#endif
#endif
#endif //EG_EXTERN_DEFAULT_STYLE

// CEmbeddedGUIView
	EWindow gw("window\0",EPosition(12,23),ESize(150,100),true);
	EWindow gw2("new window\0",EPosition(23,23),ESize(150,100),true);
	EButton gbn2(buttonCallback,EPosition(40,70),"  OK  ",48);
	EStatusBar gstn2(ESize(20,10),EPosition(40,80));
	EButton gb(buttonCallback,EPosition(23,80),"button\0",48);
	EComboBox gcomb(EPosition(20,58),100);
	ECheckButton gcb(false,EPosition(23,34),"checkWindow",11*8);
	EMessageBox gmb(1,EPosition(15,40),"ErrorMessage\0",12*8);
	EDialogBox gdb(1,EPosition(15,40),"DialogBox\0",9);
	EButton gbp(progressPlusCallback,EPosition(15,98),"+5\0",16);
	EProgress gp1(EPosition(43,98),ESize(83,12));
	//EProgress gp2(EPosition(30,105),ESize(84,8));
	//EProgress gp3(EPosition(30,113),ESize(85,8));
#ifdef EG_RICH_STYLE
	EScroll gs(EPosition(140,40),80,10,true);
#else
	EScroll gs(EPosition(140,40),80,10);
#endif  //EG_RICH_STYLE
	EList gl(EPosition(20,40));
	EMenu gm("menu\0",34,EPosition(20,40));
	EMenu::EMenuItem gmi1,gmi2,gmi3;
	EBitmap gbmp(2);
	EPopupMenu gpm;
	EPopupMenu::EPopupMenuItem gpmi1,gpmi2,gpmi3;
	ETree gt(ESize(120,80),EPosition(20,40));
	ETree::ETreeSubItem sub1,sub2,sub3,subsub1,subsub2,subsub3,subsubsub1,subsubsub2;
	ETree::ETreeItem it1,it2,subit1;
	EList::EListItem base,a,b,c;
	EToolBar gtb(EPosition(20,50));
	EIcon gic1(icon1CBF,EPosition(0,0),3),gic2(icon2CBF,EPosition(0,0),4);
	EStatusBar gsb(ESize(160,10),EPosition(20,70));
	EBarChart gbc("XAxis\0","YAxis\0",200,105,ESize(130,70),EPosition(20,40),true,16);
	EBarChart::EBarChartItem bci1,bci2,bci3;

void nextButtonCBF(EControl* control,EEvent* curevent);

	EWindow introWin("EGUI Guide\0",EPosition(0,0),ESize(127,63),true);
	EExtLabel lableCtrl(EPosition(4,25),"Example of EGUI",16*8);
	EButton nextButn(nextButtonCBF,EPosition(35,40),"Next>>\0",48);
	ECheckButton chkButn1(false,EPosition(10,14),"choice1",56);
	ECheckButton chkButn2(false,EPosition(10,24),"choice2",56);
	EEdit editCtrl(false,EPosition(10,20),60);
	static unsigned char click;
	
void progressPlusCallback(EControl* control,EEvent* curevent){
	if((curevent->m_uSource==1)&&(curevent->m_uMessage==1)){
		unsigned int n=gp1.GetProgress();
		n+=5;
		gp1.SetProgress(n);
		//gp2.SetProgress(n);
		//gp3.SetProgress(n);
	}
}

void nextButtonCBF(EControl* control,EEvent* curevent){
	if((curevent->m_uSource==1)&&(curevent->m_uMessage==1)){
		::AfxMessageBox(L"next button event received");
		if(click==0){
			introWin.RemoveControl(0);  //remove lable
			introWin.AddControl(&chkButn1);
			introWin.AddControl(&chkButn2);
			click=1;
		}else if(click==1){
			if(chkButn1.GetCheckState()){
				::AfxMessageBox(L"check button 1 is true.");
			}
			if(chkButn2.GetCheckState()){
				::AfxMessageBox(L"check button 2 is true.");
			}
			introWin.RemoveControl(1);  //remove check1
			introWin.RemoveControl(2);  //remove check2
			introWin.AddControl(&editCtrl);	
			click=2;
		}else if(click==2){
			//editCtrl.m_saString
			introWin.RemoveControl(1);  //remove edit
			::AfxMessageBox(L"edit removed");
			click=3;
		}
		//introWin.ForceRedrawAllControls();
	}
}

IMPLEMENT_DYNCREATE(CEmbeddedGUIView, CView)

BEGIN_MESSAGE_MAP(CEmbeddedGUIView, CView)
	ON_COMMAND(ID_GRAPHICFUNCTION_DRAWHORIZONLINE, &CEmbeddedGUIView::OnGraphicfunctionDrawhorizonline)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DESKTOP_CLEARSCREEN, &CEmbeddedGUIView::OnDesktopClearscreen)
	ON_COMMAND(ID_GRAPHICFUNCTION_DRAWVERTICALLINE, &CEmbeddedGUIView::OnGraphicfunctionDrawverticalline)
	ON_COMMAND(ID_GRAPHICFUNCTION_DRAWLINE, &CEmbeddedGUIView::OnGraphicfunctionDrawline)
	ON_COMMAND(ID_GRAPHICFUNCTION_DRAWCIRCLE, &CEmbeddedGUIView::OnGraphicfunctionDrawcircle)
	ON_COMMAND(ID_GRAPHICFUNCTION_DRAWFILLEDCIRCLE, &CEmbeddedGUIView::OnGraphicfunctionDrawfilledcircle)
	ON_COMMAND(ID_GRAPHICFUNCTION_DR, &CEmbeddedGUIView::OnGraphicfunctionDr)
	ON_COMMAND(ID_GRAPHICFUNCTION_DRAWFILLEDRECTANGLE, &CEmbeddedGUIView::OnGraphicfunctionDrawfilledrectangle)
	ON_COMMAND(ID_CONTROL_Label, &CEmbeddedGUIView::OnControlLabel)
	ON_COMMAND(ID_CONTROL_EXTLabel, &CEmbeddedGUIView::OnControlExtLabel)
	ON_COMMAND(ID_CONTROL_BUTTON, &CEmbeddedGUIView::OnControlButton)
	ON_COMMAND(ID_CONTROL_EDIT, &CEmbeddedGUIView::OnControlEdit)
	ON_COMMAND(ID_CONTROL_COMBOBOX, &CEmbeddedGUIView::OnControlCombobox)
	ON_COMMAND(ID_CONTROL_CHECKBUTTON, &CEmbeddedGUIView::OnControlCheckbutton)
	ON_COMMAND(ID_CONTROL_PROGRESS, &CEmbeddedGUIView::OnControlProgress)
	ON_COMMAND(ID_GRAPHICFUNCTION_DRAWSTRING, &CEmbeddedGUIView::OnGraphicfunctionDrawstring)
	ON_COMMAND(ID_WINDOW_PLAINWINDOW, &CEmbeddedGUIView::OnWindowPlainwindow)
	ON_COMMAND(ID_WINDOW_WINDOW, &CEmbeddedGUIView::OnWindowWindow)
	ON_COMMAND(ID_Menu, &CEmbeddedGUIView::OnMenu)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_COMMAND(ID_GRAPHICFUNCTION_DRAWFONTSTRING, &CEmbeddedGUIView::OnGraphicfunctionDrawfontstring)
	ON_COMMAND(ID_GRAPHICFUNCTION_DRAWIMAGE, &CEmbeddedGUIView::OnGraphicfunctionDrawimage)
	ON_COMMAND(ID_DESKTOP_MESSAGEBOXINDESKTOP, &CEmbeddedGUIView::OnDesktopMessageboxindesktop)
	ON_COMMAND(ID_DESKTOP_DIALOGBOXINDESKTOP, &CEmbeddedGUIView::OnDesktopDialogboxindesktop)
	ON_COMMAND(ID_DESKTOP_NEWDESKTOP2, &CEmbeddedGUIView::OnDesktopNewdesktop2)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_DESKTOP_ELISTINDESKTOP, &CEmbeddedGUIView::OnDesktopElistindesktop)
	ON_COMMAND(ID_DESKTOP_EMENUINDESKTOP, &CEmbeddedGUIView::OnDesktopEmenuindesktop)
	ON_COMMAND(ID_DESKTOP_EPOPMENUINDESKTOP, &CEmbeddedGUIView::OnDesktopEpopmenuindesktop)
	ON_COMMAND(ID_CONTROL_TREE, &CEmbeddedGUIView::OnControlTree)
	ON_COMMAND(ID_DESKTOP_ETREEINDESKTOP, &CEmbeddedGUIView::OnDesktopEtreeindesktop)
	ON_COMMAND(ID_CONTROL_ICONBUTTON, &CEmbeddedGUIView::OnControlIconbutton)
	ON_COMMAND(ID_GRAPHICFUNCTION_DRAWWIDTHLINE, &CEmbeddedGUIView::OnGraphicfunctionDrawwidthline)
	ON_COMMAND(ID_GRAPHICFUNCTION_DRAWQUARTERARC, &CEmbeddedGUIView::OnGraphicfunctionDrawquarterarc)
	ON_COMMAND(ID_GRAPHICFUNCTION_DRAWARC, &CEmbeddedGUIView::OnGraphicfunctionDrawarc)
	ON_COMMAND(ID_GRAPHICFUNCTION_DRAWPIESLICE, &CEmbeddedGUIView::OnGraphicfunctionDrawpieslice)
	ON_COMMAND(ID_GRAPHICFUNCTION_DRAWELLIPSE, &CEmbeddedGUIView::OnGraphicfunctionDrawellipse)
	ON_COMMAND(ID_GRAPHICFUNCTION_DRAWFILLEDELLIPSE, &CEmbeddedGUIView::OnGraphicfunctionDrawfilledellipse)
	ON_COMMAND(ID_DESKTOP_ETOOLBARINDESKTOP, &CEmbeddedGUIView::OnDesktopEtoolbarindesktop)
	ON_COMMAND(ID_CONTROL_STATUSBAR, &CEmbeddedGUIView::OnControlStatusbar)
	ON_COMMAND(ID_DESKTOP_NEWDESKTOP3, &CEmbeddedGUIView::OnDesktopNewdesktop3)
	ON_COMMAND(ID_DESKTOP_CHANGEDESKTOP3STATE, &CEmbeddedGUIView::OnDesktopChangedesktop3state)
	ON_COMMAND(ID_DESKTOP_MOVEDESKTOP3, &CEmbeddedGUIView::OnDesktopMovedesktop3)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_DESKTOP_EBARCHARTINDESKTOP, &CEmbeddedGUIView::OnDesktopEbarchartindesktop)
	ON_COMMAND(ID_CONTROL_CLOCK, &CEmbeddedGUIView::OnControlClock)
END_MESSAGE_MAP()

// CEmbeddedGUIView construction/destruction

CEmbeddedGUIView::CEmbeddedGUIView():rbd(EG_COLUMN,EG_ROW),desk(&rbd)
{
	this->first=true;	
	this->deskOpen=false;
	this->max=true;
}

CEmbeddedGUIView::~CEmbeddedGUIView()
{
}

BOOL CEmbeddedGUIView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

// CEmbeddedGUIView drawing

void CEmbeddedGUIView::OnDraw(CDC* /*pDC*/)
{
	CEmbeddedGUIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}


// CEmbeddedGUIView diagnostics

#ifdef _DEBUG
void CEmbeddedGUIView::AssertValid() const
{
	CView::AssertValid();
}

void CEmbeddedGUIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEmbeddedGUIDoc* CEmbeddedGUIView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEmbeddedGUIDoc)));
	return (CEmbeddedGUIDoc*)m_pDocument;
}
#endif //_DEBUG


// CEmbeddedGUIView message handlers

void CEmbeddedGUIView::OnGraphicfunctionDrawhorizonline()
{
#ifdef EG_RGB_COLOR
	EG_Graphic_DrawHorizonLine(EPosition(40,40),50,EColor(182,23,53));
#else
	EG_Graphic_DrawHorizonLine(40,40,50);
#endif
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnMouseMove(UINT nFlags, CPoint point)
{
#ifdef EG_CURSOR
	this->desk.SetCursorEvent(EPosition(point.x,point.y),0);
#endif //EG_CURSOR
	CView::OnMouseMove(nFlags, point);
}

void CEmbeddedGUIView::OnActivateFrame(UINT nState, CFrameWnd* pDeactivateFrame)
{
	if(this->first){   // set the device context
		HDC dc=	this->GetDC()->m_hDC;
		rbd.SetDeviceContext(dc);
		EG_LCDClearBuffer();
		this->first=false;
	}

	CView::OnActivateFrame(nState, pDeactivateFrame);
}

void CEmbeddedGUIView::OnDesktopClearscreen()
{
	EG_LCDClearBuffer();
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnGraphicfunctionDrawverticalline()
{
#ifdef EG_RGB_COLOR
	EG_Graphic_DrawVerticalLine(EPosition(30,20),90,EColor(56,23,253));
#else
	EG_Graphic_DrawVerticalLine(30,20,90);
#endif
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnGraphicfunctionDrawline()
{
#ifdef EG_RGB_COLOR
	EG_Graphic_DrawLine(EPosition(20,90),EPosition(90,120),EColor(32,154,177),false);
#else
	EG_Graphic_DrawLine(20,90,90,120,0);
#endif
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnGraphicfunctionDrawcircle()
{
#ifdef EG_RGB_COLOR
	EG_Graphic_DrawEmptyCircle(EPosition(60,60),35,EColor(233,34,213));
#else
	EG_Graphic_DrawEmptyCircle(60,60,35);
#endif
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnGraphicfunctionDrawfilledcircle()
{
#ifdef EG_RGB_COLOR
	EG_Graphic_DrawFilledCircle(EPosition(40,90),14,EColor(200,100,100));
#else
	EG_Graphic_DrawFilledCircle(40,90,14);
#endif
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnGraphicfunctionDr()
{
#ifdef EG_RGB_COLOR
	EG_Graphic_DrawEmptyRectangle(EPosition(40,40),ESize(34,23),EColor(23,233,21));
#else
	EG_Graphic_DrawEmptyRectangle(40,40,34,23);
#endif
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnGraphicfunctionDrawfilledrectangle()
{
#ifdef EG_RGB_COLOR
	EG_Graphic_DrawFilledRectangle(EPosition(80,80),ESize(34,23),EColor(23,233,21));
#else
	EG_Graphic_DrawFilledRectangle(80,80,34,23);
#endif
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnControlLabel()
{
	ELabel l(EPosition(23,43),"Label",40);
	l.RedrawControl();
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnControlExtLabel()
{
	EExtLabel el(EPosition(53,73),"extLabel",8);
	el.ChangeState();
	el.ChangeState();
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnControlButton()
{
	EButton b(NULL,EPosition(53,43),"Buttop",48);
	b.RedrawControl();
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnControlEdit()
{
	EEdit e("Edit\0",true,EPosition(23,93),60);
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnControlCombobox()
{
	EComboBox cb(EPosition(53,23),50);
	cb.AddItem("first");
	cb.SetSelectIndex(0);
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnControlCheckbutton()
{
	ECheckButton cb(true,EPosition(53,53),"CheckButton",88);
	cb.RedrawControl();
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnControlProgress()
{
	EProgress p(20,EPosition(23,73),ESize(60,12));
	p.RedrawControl();
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnGraphicfunctionDrawstring()
{
#ifdef EG_RGB_COLOR
	EG_Graphic_DrawConstString(EPosition(40,10),"This is a const string",22,EColor(23,132,32));
#else
	EG_Graphic_DrawConstString(40,10,"This is a const string",22);
#endif
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnWindowPlainwindow()
{
	EEvent e;
	e.m_uSource=1;
	e.m_uMessage=0;
	e.m_pPosition.m_uX=26;
	e.m_pPosition.m_uY=82;

	ESimpleWindow pw;
	EButton b(buttonCallback,EPosition(23,80),"button",6);
	ECheckButton cb(false,EPosition(23,43),"checkWindow",11);
	pw.AddControl(&cb);
	pw.AddControl(&b);

	pw.ForceRedrawAllControls();
	pw.DispatchEvent(&e);

	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnWindowWindow()
{
	EEvent e;
	e.m_uSource=1;
	e.m_uMessage=0;
	e.m_pPosition.m_uX=26;
	e.m_pPosition.m_uY=82;

	EWindow w("window\0",EPosition(12,23),ESize(150,100),true);
	EButton b(buttonCallback,EPosition(23,80),"button",6);
	ECheckButton cb(false,EPosition(23,43),"checkWindow",11);
	w.AddControl(&cb);
	w.AddControl(&b);

	w.ForceRedrawAllControls();
	w.DispatchEvent(&e);

	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnMenu()
{
	gw.RemoveAllControl();
	gw.AddControl(&gcb);
	gw.AddControl(&gbp);
	gw.AddControl(&gp1);
	//gw.AddControl(&gp2);
	//gw.AddControl(&gp3);
	gw.AddControl(&gs);
	gw.AddControl(&gcomb);
	gcomb.AddItem("item1\0");
	gcomb.AddItem("item2\0");
	gcomb.AddItem("item3\0");
	gw.ForceOpenNormalWindow();
	this->deskOpen=true;
#ifdef EG_CURSOR
	this->desk.SetCursorShape((unsigned char*)&EG_DefaultCursorShape);
#endif  //EG_CURSOR
	this->desk.AddWindow(&gw);
	this->SetTimer(NULL,10,NULL);
	this->desk.GlobalRedraw();
}

void CEmbeddedGUIView::OnLButtonDown(UINT nFlags, CPoint point)
{
	//if(this->deskOpen){	
	//	gp.SetProgress(gp.GetProgress()+4);
	//}
	this->desk.SetCursorEvent(EPosition(point.x,point.y),1);
	CView::OnLButtonDown(nFlags, point);
}

void CEmbeddedGUIView::OnTimer(UINT_PTR nIDEvent)
{
	this->desk.ScheduleRedraw();
	CView::OnTimer(nIDEvent);
}

void CEmbeddedGUIView::OnGraphicfunctionDrawfontstring()
{
#ifdef EG_RGB_COLOR
	EG_Graphic_DrawFontString(EPosition(40,10),"Font string\0",EColor(23,132,32),EFont(4,1));
#else
	EG_Graphic_DrawFontString(40,10,"Font string\0",EFont(1,1));
#endif
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnGraphicfunctionDrawimage()
{
#ifdef EG_SINGLE_COLOR
	unsigned char bmparr[16]={
	0x55,0xFF,0xAA,0xFF,0xAA,0xFF,0xAA,0xFF,
	0xAA,0xFF,0xAA,0xFF,0xAA,0xFF,0xAA,0xFF
	};
	EBitmap pbmp(8,2,(unsigned char*)bmparr);
	EBitmap pbmp2(7);
	EG_Graphic_DrawBitmap(100,20,&pbmp2);
	// backoverBuffer
	// size : 24*24
 const unsigned char backoverBuffer[72]={
128,31,0,64,64,64,67,67,102,108,
104,112,113,123,127,127,127,127,127,127,
127,127,63,128,0,255,255,127,111,199,
131,1,0,0,68,198,199,199,199,199,
199,199,199,199,255,255,255,0,1,252,
254,254,254,254,254,254,254,126,62,30,
30,190,254,254,254,254,254,254,254,254,
252,1};
	EBitmap pbmp3(24,3,(unsigned char*)backoverBuffer);
	EG_Graphic_DrawBitmap(20,20,&pbmp3);

#else

	EBitmap pbmp(0);
	EBitmap pbmp1(1);
	EBitmap pbmp2(2);
#endif //EG_SINGLE_COLOR

#ifdef EG_SINGLE_COLOR
	//EG_Graphic_DrawBitmap(50,40,&pbmp);
#else
	EG_Graphic_DrawBitmap(EPosition(50,40),&pbmp);
#endif //EG_SINGLE_COLOR
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnDesktopMessageboxindesktop()
{
	gw.RemoveAllControl();
	//gmb.m_bOpen=true;
	gw.AddControl(&gmb);
	gmb.SwitchState();
	//gmb.RedrawControl();
}

void CEmbeddedGUIView::OnDesktopDialogboxindesktop()
{
	gw.RemoveAllControl();
	gdb.SetDialogBoxState(0);
	gw.AddControl(&gdb);
}

void CEmbeddedGUIView::OnDesktopNewdesktop2()
{
	this->desk.RemoveAllWindow();
	introWin.RemoveAllControl();
	introWin.AddControl(&lableCtrl);
	introWin.AddControl(&nextButn);
	this->deskOpen=true;
#ifdef EG_CURSOR
	this->desk.SetCursorShape((unsigned char*)&EG_DefaultCursorShape);
#endif //EG_CURSOR
	this->desk.AddWindow(&introWin);
	this->SetTimer(NULL,10,NULL);
	this->desk.GlobalRedraw();
	click=0;
}

void CEmbeddedGUIView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
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

void CEmbeddedGUIView::OnDesktopElistindesktop()
{
	gw.RemoveAllControl();
	gw.AddControl(&gl);
	gl.RemoveAllItems();
	gl.RemoveAllColumns();
	gl.AddColumn(46);
	gl.AddColumn(40);
	gl.AddColumn(47);
	gl.AddItem(&base);
	gl.AddItem(&a);
	gl.AddItem(&b);
	gl.AddItem(&c);
	gl.SetItem(0,0,"Name\0");
	gl.SetItem(0,1,"Age\0");
	gl.SetItem(0,2,"Hobby\0");
	gl.SetItem(1,0,"Bob\0");
	gl.SetItem(1,1,"20\0");
	gl.SetItem(1,2,"swim\0");
	gl.SetItem(2,0,"Smith\0");
	gl.SetItem(2,1,"25\0");
	gl.SetItem(2,2,"movie\0");
	gl.SetItem(3,0,"Mike\0");
	gl.SetItem(3,1,"22\0");
	gl.SetItem(3,2,"hike\0");
	gl.SelectItem(2);
}

void CEmbeddedGUIView::OnDesktopEmenuindesktop()
{
	gw.RemoveAllControl();
	gw.AddControl(&gm);
	gm.AddItem(&gmi1);
	gm.AddItem(&gmi2);
	gm.AddItem(&gmi3);
	gm.SetMenuItem(0,"item1\0",0,menuitem1CBF);
	gm.SetMenuItem(1,"menuitem2\0",0,menuitem2CBF);
	gm.SetMenuItem(2,"item3\0",0,menuitem3CBF);
}

void CEmbeddedGUIView::OnDesktopEpopmenuindesktop()
{
	gw.RemoveAllControl();
	gw.AddControl(&gpm);
	gpm.AddItem(&gpmi1);
	gpm.AddItem(&gpmi2);
	gpm.AddItem(&gpmi3);
	gpm.SetPopupMenuItem(0,"item1\0",0,menuitem1CBF);
	gpm.SetPopupMenuItem(1,"menuitem2\0",0,menuitem2CBF);
	gpm.SetPopupMenuItem(2,"item3\0",0,menuitem3CBF);
	gpm.ShowPopupMenu(EPosition(20,50));
}

void CEmbeddedGUIView::OnControlTree()
{
	gt.AddRoot(&sub1,"root1\0");
	gt.AddRoot(&sub2,"root2\0");
	gt.AddRoot(&sub3,"root3\0");
	//gt.AddBranch(&it1,0);
	//gt.AddBranch(&it2,2);
	//gt.AddLeaf(0,&subsub1,"leaf1\0");
	//gt.AddLeaf(0,&subsub2,"leaf2\0");
	//gt.AddLeaf(2,&subsub3,"leaf3\0");
	//gt.AddBranch(&subit1,2,0);
	//gt.AddLeaf(2,0,&subsubsub1,"leafleaf1\0");
	//gt.AddLeaf(2,0,&subsubsub2,"leafleaf2\0");
	gt.OpenAllLeafs();
	gt.RedrawControl();
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnDesktopEtreeindesktop()
{
	gt.RemoveAllRoots();
	gt.AddRoot(&sub1,"root1\0");
	gt.AddRoot(&sub2,"root2\0");
	gt.AddRoot(&sub3,"root3\0");
	gt.AddBranch(&it1,0);
	gt.AddBranch(&it2,2);
	//gt.AddLeaf(0,&subsub1,"leaf1\0");
	//gt.AddLeaf(0,&subsub2,"leaf2\0");
	gt.AddLeaf(2,&subsub3,"leaf3\0");
	gt.AddBranch(&subit1,2,0);
	gt.AddLeaf(2,0,&subsubsub1,"leafleaf1\0");
	//gt.AddLeaf(2,0,&subsubsub2,"leafleaf2\0");
	gt.OpenAllLeafs();
	gw.RemoveAllControl();
	gw.AddControl(&gt);
}

void CEmbeddedGUIView::OnControlIconbutton()
{
#ifdef EG_RGB_COLOR
	EIconButton ib(NULL,EPosition(20,60),ESize(43,36),ESize(17,17),(unsigned char*)EG_DefaultWarningBuffer,"iconB\0",false);
#else
	EIconButton ib(NULL,EPosition(20,60),ESize(35,28),ESize(16,2),(unsigned char*)(&EG_DefaultIcon[0][0]),"file\0",false);
#endif
	ib.RedrawControl();
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnGraphicfunctionDrawwidthline()
{
#ifdef EG_RGB_COLOR
	EG_Graphic_DrawWidthLine(EPosition(40,90),EPosition(50,30),EColor(200,100,100),3);
#else
	EG_Graphic_DrawWidthLine(40,90,50,30,3);
#endif
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnGraphicfunctionDrawquarterarc()
{
#ifdef EG_RGB_COLOR
	EG_Graphic_DrawQuarterArc(EPosition(40,40),20,EColor(100,200,100),2);
#else
	EG_Graphic_DrawQuarterArc(40,40,20,2);
#endif
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnGraphicfunctionDrawarc()
{
#ifdef EG_RGB_COLOR
	EG_Graphic_DrawArc(EPosition(40,40),20,EColor(20,100,220),0,100);
#else
	EG_Graphic_DrawArc(40,40,20,0,120);
#endif
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnGraphicfunctionDrawpieslice()
{
#ifdef EG_RGB_COLOR
	EG_Graphic_DrawPieSlice(EPosition(40,40),20,EColor(200,100,100),120,0);
#else
	EG_Graphic_DrawPieSlice(40,40,20,0,120);
#endif
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnGraphicfunctionDrawellipse()
{
#ifdef EG_RGB_COLOR
	EG_Graphic_DrawEmptyEllipse(40,40,20,70,EColor(200,100,100));
#else
	EG_Graphic_DrawEmptyEllipse(40,40,20,70);
#endif
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnGraphicfunctionDrawfilledellipse()
{
#ifdef EG_RGB_COLOR
	EG_Graphic_DrawFilledEllipse(40,40,20,70,EColor(200,100,100));
#else
	EG_Graphic_DrawFilledEllipse(40,40,20,70);
#endif
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnDesktopEtoolbarindesktop()
{
	gw.RemoveAllControl();
	gw.AddControl(&gtb);
	gtb.AddItem(&gic1);
	gtb.AddItem(&gic2);
}

void CEmbeddedGUIView::OnControlStatusbar()
{
	gsb.SetLabelString("lablestring\0");
	gsb.SetStatusString("NUM\0",1);
	gsb.SetStatusString("INS\0",2);
	gsb.RedrawControl();
	rbd.BufferDisplay();
}

void CEmbeddedGUIView::OnDesktopNewdesktop3()
{
	//gw2.MaximizeWindow();
	gw2.AddControl(&gbn2);
	gw2.AppendToolBar(&gtb,1);
	gtb.AddItem(&gic1);
	gtb.AddItem(&gic2);
	gw2.AppendStatusBar(&gstn2,2);
	gstn2.SetLabelString("state\0");
	gstn2.SetStatusString("fd\0",2);
	gstn2.SetStatusString("gh\0",1);
	gw2.AppendPopupMenu(&gpm);
	gpm.RemovedAllItems();
	gpm.AddItem(&gpmi1);
	gpm.AddItem(&gpmi2);
	gpm.AddItem(&gpmi3);
	gpm.SetPopupMenuItem(0,"item1\0",1,NULL);
	gpm.SetPopupMenuItem(1,"menuitem2\0",0,menuitem2CBF);
	gpm.SetPopupMenuItem(2,"item3\0",0,menuitem3CBF);
	this->desk.RemoveAllWindow();
	this->deskOpen=true;
#ifdef EG_CURSOR
	this->desk.SetCursorShape((unsigned char*)&EG_DefaultCursorShape);
#endif  //EG_CURSOR
	this->desk.AddWindow(&gw2);
	this->SetTimer(NULL,10,NULL);
	this->desk.GlobalRedraw();
}

void CEmbeddedGUIView::OnDesktopChangedesktop3state()
{
	if(this->max){
		gw2.MaximizeWindow();
		this->max=false;
	}else{
		gw2.RecoverWindow();
		this->max=true;
	}
}

void CEmbeddedGUIView::OnDesktopMovedesktop3()
{
	EPosition pos;
	pos.m_uX=23;
	pos.m_uY=23;
	if((gw2.GetWindowPosition()->m_uX==pos.m_uX)&&
		(gw2.GetWindowPosition()->m_uY==pos.m_uY)){
		pos.m_uX=40;
		pos.m_uY=30;
		gw2.MoveWindow(pos);
	}else{
		gw2.MoveWindow(pos);
	}
}

void CEmbeddedGUIView::OnRButtonDown(UINT nFlags, CPoint point)
{
	this->desk.SetCursorEvent(EPosition(point.x,point.y),2);
	CView::OnRButtonDown(nFlags, point);
}

void CEmbeddedGUIView::OnDesktopEbarchartindesktop()
{
#ifdef EG_RGB_COLOR
	bci1.m_cBarColor=EColor(20,100,150);
	bci2.m_cBarColor=EColor(20,100,150);
	bci3.m_cBarColor=EColor(20,100,150);
#endif
	bci1.m_pItemText="bar1\0";
	bci1.m_uBarHeight=30;
	bci1.m_uBarWidth=13;
	bci2.m_pItemText="bar2\0";
	bci2.m_uBarHeight=50;
	bci2.m_uBarWidth=13;
	bci3.m_pItemText="bar3\0";
	bci3.m_uBarHeight=20;
	bci3.m_uBarWidth=13;
	gbc.AddBarItem(&bci1);
	gbc.AddBarItem(&bci2);
	gbc.AddBarItem(&bci3);
	gw.RemoveAllControl();
	gw.AddControl(&gbc);
	gw.ForceRedrawAllControls();
}

void CEmbeddedGUIView::OnControlClock()
{
	EClock clo(EPosition(45,23),true);
	clo.UpdateTime(12,59,59);
	clo.AccumulateSecond();
	rbd.BufferDisplay();
}
