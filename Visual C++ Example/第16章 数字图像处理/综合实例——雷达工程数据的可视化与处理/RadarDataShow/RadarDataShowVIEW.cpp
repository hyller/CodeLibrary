// RadarDataShowView.cpp : implementation of the CRadarDataShowView class
//

#include "stdafx.h"
#include "RadarDataShow.h"

#include "RadarDataShowDoc.h"
#include "RadarDataShowView.h"
#include "AscanView.h"
#include "CornerView.h"
#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define color_style		0
#define gray_style		1
/////////////////////////////////////////////////////////////////////////////
// CRadarDataShowView

IMPLEMENT_DYNCREATE(CRadarDataShowView, CScrollView)

BEGIN_MESSAGE_MAP(CRadarDataShowView, CScrollView)
	//{{AFX_MSG_MAP(CRadarDataShowView)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SHOWGRAY, OnShowgray)
	ON_UPDATE_COMMAND_UI(ID_SHOWGRAY, OnUpdateShowgray)
	ON_COMMAND(ID_SHOWCOLOR, OnShowcolor)
	ON_UPDATE_COMMAND_UI(ID_SHOWCOLOR, OnUpdateShowcolor)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)

	ON_UPDATE_COMMAND_UI(ID_INDICATOR_NUMXX, OnUpdateeIndicatorXX)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_NUMYY, OnUpdateeIndicatorYY)


END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CRadarDataShowView construction/destruction
CRadarDataShowView::CRadarDataShowView()
{
	// TODO: add construction code here
	Show_Style=color_style;	
	Mouse_Move.x=1;
	Mouse_Move.y=1;
	strollx=0;
}

CRadarDataShowView::~CRadarDataShowView()
{
}

BOOL CRadarDataShowView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRadarDataShowView drawing

void CRadarDataShowView::OnDraw(CDC* pDC)
{
	CRadarDataShowDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int j_bmp;
	BITMAPINFO *lpbminf;
	lpbminf = new BITMAPINFO [sizeof(BITMAPINFOHEADER)+sizeof(RGBQUAD)*256];	
		//对信息头进行赋值
	lpbminf->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	lpbminf->bmiHeader.biWidth = pDoc->data_head.rh_slice;
	lpbminf->bmiHeader.biHeight = pDoc->data_head.rh_nsamp;
	lpbminf->bmiHeader.biPlanes = 1;
	lpbminf->bmiHeader.biBitCount = 8;
	lpbminf->bmiHeader.biCompression = BI_RGB;
	lpbminf->bmiHeader.biSizeImage = pDoc->data_head.rh_nsamp*pDoc->data_head.rh_slice;
	lpbminf->bmiHeader.biXPelsPerMeter = 0;
	lpbminf->bmiHeader.biYPelsPerMeter = 0;
	lpbminf->bmiHeader.biClrUsed = 0;
	lpbminf->bmiHeader.biClrImportant = 0;
	//对调色板进行赋值
	if(Show_Style==color_style)
	{
		for(j_bmp=0; j_bmp<16; j_bmp++)
		{
			lpbminf->bmiColors[j_bmp].rgbBlue = (BYTE)255;
			lpbminf->bmiColors[j_bmp].rgbGreen = (BYTE)(0+4*j_bmp);
			lpbminf->bmiColors[j_bmp].rgbRed = (BYTE)(0+2*j_bmp);
			lpbminf->bmiColors[j_bmp].rgbReserved = 0;
		}
		for(j_bmp=16;j_bmp<32; j_bmp++)
		{
			lpbminf->bmiColors[j_bmp].rgbBlue = (BYTE)250;
			lpbminf->bmiColors[j_bmp].rgbGreen = (BYTE)(64+4*(j_bmp-16));
			lpbminf->bmiColors[j_bmp].rgbRed = (BYTE)(32+2*(j_bmp-16));
			lpbminf->bmiColors[j_bmp].rgbReserved = 0;
		}
		for(j_bmp=32;j_bmp<48; j_bmp++)
		{
			lpbminf->bmiColors[j_bmp].rgbBlue = (BYTE)250;
			lpbminf->bmiColors[j_bmp].rgbGreen = (BYTE)(128+4*(j_bmp-32));
			lpbminf->bmiColors[j_bmp].rgbRed = (BYTE)(64+1*(j_bmp-16));
			lpbminf->bmiColors[j_bmp].rgbReserved = 0;
		}
		for(j_bmp=48;j_bmp<64; j_bmp++)
		{
			lpbminf->bmiColors[j_bmp].rgbBlue = (BYTE)245;
			lpbminf->bmiColors[j_bmp].rgbGreen = (BYTE)(192+3*(j_bmp-48));
			lpbminf->bmiColors[j_bmp].rgbRed = (BYTE)(80+1*(j_bmp-48));
			lpbminf->bmiColors[j_bmp].rgbReserved = 0;
		}
		for(j_bmp=64;j_bmp<80; j_bmp++)
		{
			lpbminf->bmiColors[j_bmp].rgbBlue = (BYTE)(240-2*(j_bmp-64));
			lpbminf->bmiColors[j_bmp].rgbGreen = (BYTE)(240+0*(j_bmp-64));
			lpbminf->bmiColors[j_bmp].rgbRed = (BYTE)(96+2*(j_bmp-64));
			lpbminf->bmiColors[j_bmp].rgbReserved = 0;
		}
			for(j_bmp=80;j_bmp<96; j_bmp++)
			{
				lpbminf->bmiColors[j_bmp].rgbBlue = (BYTE)(208-2*(j_bmp-80));
				lpbminf->bmiColors[j_bmp].rgbGreen = (BYTE)(240+0*(j_bmp-80));
				lpbminf->bmiColors[j_bmp].rgbRed = (BYTE)(128+1*(j_bmp-80));
				lpbminf->bmiColors[j_bmp].rgbReserved = 0;
			}
			for(j_bmp=96;j_bmp<112; j_bmp++)
			{
				lpbminf->bmiColors[j_bmp].rgbBlue = (BYTE)(176-2*(j_bmp-96));
				lpbminf->bmiColors[j_bmp].rgbGreen = (BYTE)(240+0*(j_bmp-96));
				lpbminf->bmiColors[j_bmp].rgbRed = (BYTE)(144+1*(j_bmp-96));
				lpbminf->bmiColors[j_bmp].rgbReserved = 0;
			}
			for(j_bmp=112;j_bmp<128; j_bmp++)
			{
				lpbminf->bmiColors[j_bmp].rgbBlue = (BYTE)(114+2*(j_bmp-112));
				lpbminf->bmiColors[j_bmp].rgbGreen = (BYTE)(250+0*(j_bmp-112));
				lpbminf->bmiColors[j_bmp].rgbRed = (BYTE)(160+2*(j_bmp-112));
				lpbminf->bmiColors[j_bmp].rgbReserved = 0;
			}
			for(j_bmp=128;j_bmp<144; j_bmp++)
			{
				lpbminf->bmiColors[j_bmp].rgbBlue = (BYTE)(176-1*(j_bmp-128));
				lpbminf->bmiColors[j_bmp].rgbGreen = (BYTE)(250+0*(j_bmp-128));
				lpbminf->bmiColors[j_bmp].rgbRed = (BYTE)(192+2*(j_bmp-128));
				lpbminf->bmiColors[j_bmp].rgbReserved = 0;
			}
			for(j_bmp=144;j_bmp<160; j_bmp++)
			{
				lpbminf->bmiColors[j_bmp].rgbBlue = (BYTE)(160-2*(j_bmp-144));
				lpbminf->bmiColors[j_bmp].rgbGreen = (BYTE)(250+0*(j_bmp-144));
				lpbminf->bmiColors[j_bmp].rgbRed = (BYTE)(224+1*(j_bmp-144));
				lpbminf->bmiColors[j_bmp].rgbReserved = 0;
			}
			for(j_bmp=160;j_bmp<176; j_bmp++)
			{
				lpbminf->bmiColors[j_bmp].rgbBlue = (BYTE)(128+2*(j_bmp-160));
				lpbminf->bmiColors[j_bmp].rgbGreen = (BYTE)(240-3*(j_bmp-160));
				lpbminf->bmiColors[j_bmp].rgbRed = (BYTE)(240+0*(j_bmp-160));
				lpbminf->bmiColors[j_bmp].rgbReserved = 0;
			}
			for(j_bmp=176;j_bmp<192; j_bmp++)
			{
				lpbminf->bmiColors[j_bmp].rgbBlue = (BYTE)(160+2*(j_bmp-176));
				lpbminf->bmiColors[j_bmp].rgbGreen = (BYTE)(192-3*(j_bmp-176));
				lpbminf->bmiColors[j_bmp].rgbRed = (BYTE)(240+0*(j_bmp-176));
				lpbminf->bmiColors[j_bmp].rgbReserved = 0;
			}
			for(j_bmp=192;j_bmp<208; j_bmp++)
			{
				lpbminf->bmiColors[j_bmp].rgbBlue = (BYTE)(192+3*(j_bmp-192));
				lpbminf->bmiColors[j_bmp].rgbGreen = (BYTE)(144-2*(j_bmp-192));
				lpbminf->bmiColors[j_bmp].rgbRed = (BYTE)(240+0*(j_bmp-192));
				lpbminf->bmiColors[j_bmp].rgbReserved = 0;
			}
			for(j_bmp=208;j_bmp<224; j_bmp++)
			{
				lpbminf->bmiColors[j_bmp].rgbBlue = (BYTE)(240-5*(j_bmp-208));
				lpbminf->bmiColors[j_bmp].rgbGreen = (BYTE)(112-2*(j_bmp-208));
				lpbminf->bmiColors[j_bmp].rgbRed = (BYTE)(240+0*(j_bmp-208));
				lpbminf->bmiColors[j_bmp].rgbReserved = 0;
			}
			for(j_bmp=224;j_bmp<240; j_bmp++)
			{
				lpbminf->bmiColors[j_bmp].rgbBlue = (BYTE)(160-5*(j_bmp-224));
				lpbminf->bmiColors[j_bmp].rgbGreen = (BYTE)(80-2*(j_bmp-224));
				lpbminf->bmiColors[j_bmp].rgbRed = (BYTE)(245+0*(j_bmp-224));
				lpbminf->bmiColors[j_bmp].rgbReserved = 0;
			}
			for(j_bmp=240;j_bmp<256; j_bmp++)
			{
				lpbminf->bmiColors[j_bmp].rgbBlue = (BYTE)(80-5*(j_bmp-240));
				lpbminf->bmiColors[j_bmp].rgbGreen = (BYTE)(48-3*(j_bmp-240));
				lpbminf->bmiColors[j_bmp].rgbRed = (BYTE)(250+0*(j_bmp-240));
				lpbminf->bmiColors[j_bmp].rgbReserved = 0;
			}
		
		}
		else if(Show_Style==gray_style)
		{
			for(j_bmp=0; j_bmp<256; j_bmp++)
			{
				lpbminf->bmiColors[j_bmp].rgbBlue = (BYTE)j_bmp;
				lpbminf->bmiColors[j_bmp].rgbGreen = (BYTE)j_bmp;
				lpbminf->bmiColors[j_bmp].rgbRed = (BYTE)j_bmp;
				lpbminf->bmiColors[j_bmp].rgbReserved = 0;
			}
		}
   		//得到DIB信息
		int xSrc = 0, ySrc =0;
		Dst.x = 0; 
		Dst.y = 0;
		int dxSrc = lpbminf->bmiHeader.biWidth; 
		int dySrc = lpbminf->bmiHeader.biHeight;	
	    dDst.x = dxSrc*4;
		//dDst.x = dxSrc;
		dDst.y = dySrc;
		m_ImageSize = CSize(dDst.x,dDst.y);
       	//显示图象
		SetStretchBltMode(pDC->m_hDC,COLORONCOLOR); 
		StretchDIBits(pDC->m_hDC,Dst.x,Dst.y,dDst.x,dDst.y,xSrc,ySrc,dxSrc,dySrc,lpBufPtr_bmp,lpbminf,DIB_RGB_COLORS,SRCCOPY);
		//释放内存
		delete lpbminf;
}

void CRadarDataShowView::OnInitialUpdate()
{

	CRadarDataShowDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CSize sizeTotal;
	sizeTotal.cx = pDoc->data_head.rh_slice*4;//设定滚动窗口的范围
	sizeTotal.cy = pDoc->data_head.rh_nsamp;
	SetScrollSizes(MM_TEXT,sizeTotal);
	m_pParent = ((CChildFrame*)GetParentFrame());
    m_pParent->ShowRulers();//更新显示标尺
    OnUpdate(NULL, 0, NULL);
	CMDIChildWnd *pWnd=(CMDIChildWnd *)GetParentFrame(); 
	pWnd->SetWindowText("原始数据 － "+GetDocument()->GetTitle());//设置文档标题
	unsigned char *lpBufPtr_bmp_1;
	lpBufPtr_bmp = new unsigned char[pDoc->data_head.rh_nsamp*(10+pDoc->data_head.rh_slice)];
	lpBufPtr_bmp_1 = new unsigned char[pDoc->data_head.rh_nsamp*(10+pDoc->data_head.rh_slice)];
	for(int i=0;i<pDoc->data_head.rh_nsamp*pDoc->data_head.rh_slice;i++)
		lpBufPtr_bmp_1[i] = (unsigned char)((pDoc->lpBufPtr_Raw_data[i]+1)*256/2);//转换为灰度
	//按BMP格式重新排列数据
	int lie_n = ((int)((double)pDoc->data_head.rh_slice/4 + 0.999))*4;//转换为4的整数倍
	for(int hang = 0;hang <pDoc->data_head.rh_nsamp;hang++)
		for(int lie = 0;lie <lie_n+1;lie++)
			if(lie>(pDoc->data_head.rh_slice-1))
				lpBufPtr_bmp[hang*lie_n+lie] = 255;
			else
				lpBufPtr_bmp[hang*lie_n+lie] = lpBufPtr_bmp_1[pDoc->data_head.rh_nsamp*lie+pDoc->data_head.rh_nsamp-hang-1];
	delete[] lpBufPtr_bmp_1;
	CScrollView::OnInitialUpdate();
}

/////////////////////////////////////////////////////////////////////////////
// CRadarDataShowView printing

BOOL CRadarDataShowView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRadarDataShowView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRadarDataShowView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRadarDataShowView diagnostics

#ifdef _DEBUG
void CRadarDataShowView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CRadarDataShowView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CRadarDataShowDoc* CRadarDataShowView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRadarDataShowDoc)));
	return (CRadarDataShowDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRadarDataShowView message handlers
void  CRadarDataShowView::UpdateRulersInfo(int nMessage, CPoint ScrollPos,CPoint Pos)
{
	if (!m_pParent)
        return;

	
	CRadarDataShowDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	m_ImageSize = CSize(pDoc->data_head.rh_slice*4,pDoc->data_head.rh_nsamp);


	stRULER_INFO pRulerInfo;
    pRulerInfo.uMessage    = nMessage;
    pRulerInfo.ScrollPos   = ScrollPos;
    pRulerInfo.DocSize     = m_ImageSize;
	pRulerInfo.Pos         = Pos;

	m_pParent->UpdateRulersInfo(pRulerInfo);
}

void CRadarDataShowView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	UpdateRulersInfo(RW_POSITION, GetScrollPosition());
    Invalidate();	
}

void CRadarDataShowView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	strollx=GetScrollPosition().x;
	UpdateRulersInfo(RW_HSCROLL, GetScrollPosition());
	CScrollView::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CRadarDataShowView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	UpdateRulersInfo(RW_VSCROLL, GetScrollPosition());

	CAscanView* pWnd=((CAscanView*)m_pParent->m_Rulers.GetPane(1,2));
	pWnd->v_scroll_Draw=GetScrollPosition().y;
	pWnd->Invalidate();
	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CRadarDataShowView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CPoint Scro;
	Scro = GetScrollPosition();
	Mouse_Move = point + Scro;
	UpdateRulersInfo(RW_POSITION, GetScrollPosition(), point);
	CScrollView::OnMouseMove(nFlags, point);
}

//状态栏显示坐标
void CRadarDataShowView::OnUpdateeIndicatorXX(CCmdUI* pCmdUI)
{	
	CString strXY,xx;
	char X_char[10];
	sprintf(X_char,"%d",Mouse_Move.x);
	xx = (CString)X_char;
	strXY = xx+" m";
	pCmdUI->Enable(TRUE);
	pCmdUI->SetText(strXY);
}
void CRadarDataShowView::OnUpdateeIndicatorYY(CCmdUI* pCmdUI)
{
	CString strXY,yy;
	char Y_char[5];
	sprintf(Y_char,"%d",Mouse_Move.y);
	yy = (CString)Y_char;
	strXY = yy+" ns";
	pCmdUI->Enable(TRUE);
	pCmdUI->SetText(strXY);
}


void CRadarDataShowView::OnShowgray() 
{
	// TODO: Add your command handler code here
	Show_Style=gray_style;
	CRadarDataShowDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->UpdateAllViews(NULL);
	
}

void CRadarDataShowView::OnUpdateShowgray(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(Show_Style==gray_style);
}

void CRadarDataShowView::OnShowcolor() 
{
	// TODO: Add your command handler code here
	Show_Style=color_style;
	CRadarDataShowDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->UpdateAllViews(NULL);
}

void CRadarDataShowView::OnUpdateShowcolor(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(Show_Style==color_style);
	
}

void CRadarDataShowView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
		int i;
		long Mouse_Y;
		CPoint Scro;
		Scro = GetScrollPosition();
		Mouse_X = point.x + Scro.x;
		Mouse_Y = point.y + Scro.y;
		if((Mouse_X>Dst.x)&(Mouse_X<Dst.x+dDst.x)&(Mouse_Y>Dst.y)&(Mouse_Y<Dst.y+dDst.y))
		 {				
			 CRadarDataShowDoc* pDoc = GetDocument();
			 for(i=0;i<pDoc->data_head.rh_nsamp;i++)
				 pDoc->lpBufPtr_Ascan[i]= (unsigned char)((pDoc->lpBufPtr_Raw_data[(int)(Mouse_X/4)*pDoc->data_head.rh_nsamp+i]+1)*256/6);
			CChildFrame* child_1;
			child_1=(CChildFrame *)GetParentFrame();
			CAscanView* pWnd_A= (CAscanView*) child_1->m_Rulers.GetPane(1,2);
			pWnd_A->Invalidate();
			CCornerView* pWnd_cor=(CCornerView*) child_1->m_Rulers.GetPane(0,2);
			pWnd_cor->A_Num=(Mouse_X-Dst.x)/4;
			pWnd_cor->Invalidate();
      	  }
	CScrollView::OnLButtonDown(nFlags, point);
}
