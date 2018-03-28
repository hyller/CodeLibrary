// DlgDocFrameView.cpp : implementation of the CDlgDocFrameView class
//

#include "stdafx.h"
#include "DlgDocFrame.h"

#include "DlgDocFrameDoc.h"
#include "DlgDocFrameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgDocFrameView

IMPLEMENT_DYNCREATE(CDlgDocFrameView, CView)

BEGIN_MESSAGE_MAP(CDlgDocFrameView, CView)
	//{{AFX_MSG_MAP(CDlgDocFrameView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDocFrameView construction/destruction

CDlgDocFrameView::CDlgDocFrameView()
{
	// TODO: add construction code here

}

CDlgDocFrameView::~CDlgDocFrameView()
{
}

BOOL CDlgDocFrameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDlgDocFrameView drawing

void CDlgDocFrameView::OnDraw(CDC* pDC)
{
	CDlgDocFrameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	const int xOrg = 100;
	const int yOrg = 350;
	const int xMax = 700;
	const int yMin = 20;
	const int xMin = xOrg;
	const int yMax = yOrg;
	
	if(pDoc->m_nPointCount>0)
	{
		//找出最大和最小
		double dbXMin = pDoc->m_dbXdata[0];
		double dbXMax = pDoc->m_dbXdata[0];
		double dbYMin = pDoc->m_dbYdata[0];
		double dbYMax = pDoc->m_dbYdata[0];
		
		for(int i=1; i< pDoc->m_nPointCount; i++)
		{
			pDoc->m_dbXdata[i]<dbXMin?dbXMin=pDoc->m_dbXdata[i]:
		pDoc->m_dbXdata[i]>dbXMax?dbXMax=pDoc->m_dbXdata[i]:dbXMax;
		pDoc->m_dbYdata[i]<dbYMin?dbYMin=pDoc->m_dbYdata[i]:
		pDoc->m_dbYdata[i]>dbYMax?dbYMax=pDoc->m_dbYdata[i]:dbYMax;
		}
		
		//调整最大最小值
		dbXMax = dbXMax + (dbXMax-dbXMin)/ pDoc->m_nPointCount;
		dbXMin = dbXMin - (dbXMax-dbXMin)/ pDoc->m_nPointCount;
		dbYMax = dbYMax + (dbYMax-dbYMin)/ pDoc->m_nPointCount;
		dbYMin = dbYMin - (dbYMax-dbYMin)/ pDoc->m_nPointCount;
		
		//换算比率，
		//同时当x或y的最大值和最小值相等或几乎相等时，限制比率不要太大
		double dbXRatio = (dbXMax-dbXMin) < 10e-15 ?
			10e-15 : (xMax-xOrg)/(dbXMax-dbXMin);
		double dbYRatio = (dbYMax-dbYMin) < 10e-15 ?
			10e-15 : (yOrg-yMin)/(dbYMax-dbYMin);
		
		//画折线
		int x = (int) (dbXRatio * (pDoc->m_dbXdata[0]-dbXMin) + xOrg);
		int y = (int) (yOrg - dbYRatio * (pDoc->m_dbYdata[0]-dbYMin));
		pDC->MoveTo(x,y);
		
		CBrush brushNewBrush(RGB(0, 0, 0));
		CBrush *pbrushOldBrush = pDC->SelectObject(&brushNewBrush);
		
		CRect rectSymbol(x-3, y-3, x+3, y+3);
		pDC->Ellipse(rectSymbol);
		
		for(i=1; i<pDoc->m_nPointCount; i++)
		{
			x = (int) (dbXRatio * (pDoc->m_dbXdata[i]-dbXMin) + xOrg);
			y = (int) (yOrg - dbYRatio * (pDoc->m_dbYdata[i]-dbYMin));
			rectSymbol.left = x - 3;
			rectSymbol.top = y - 3;
			rectSymbol.right = x + 3;
			rectSymbol.bottom = y + 3;
			pDC->Ellipse(rectSymbol);
			pDC->LineTo(x,y);
		}
		
		//画轴
		pDC->SelectObject(pbrushOldBrush);  //恢复
		
		pDC->MoveTo(xOrg,yOrg);
		pDC->LineTo(xMax,yOrg);
		pDC->MoveTo(xOrg,yOrg);
		pDC->LineTo(xOrg,yMin);
		
		//画刻度
		const iNumScal = 8;
		double dbXInc = (dbXMax - dbXMin)/iNumScal;
		
		y = yOrg;
		for(i = 0; i<=iNumScal; ++i)
		{
			x = (int) (dbXRatio * i * dbXInc + xOrg);
			pDC->MoveTo(x, y);
			pDC->LineTo(x, y+8);
			CString strBufOut;
			strBufOut.Format("%6.2f", (dbXMin + i * dbXInc));
			pDC->TextOut(x - 20 , y + 15, strBufOut);
		}
		
		double dbYInc = (dbYMax - dbYMin)/iNumScal;
		x = xOrg;
		for(i = 0; i<=iNumScal; ++i)
		{
			y = (int) (yOrg - dbYRatio * dbYInc * i);
			pDC->MoveTo(x, y);
			pDC->LineTo(x - 8, y);
			CString strBufOut;
			strBufOut.Format("%6.2f", (dbYMin + i * dbYInc));
			pDC->TextOut(x - 55 , y - 8, strBufOut);
		}
		
		//写轴标题
		x = (xMax-xOrg)/8 * 7;
		y = yOrg + 40;
		pDC->TextOut(x, y, "X");
		
		x = xOrg - 80;
		y = (yOrg - yMin)/8;
		pDC->TextOut(x, y, "Y");
	}
	else					//无数据时显示提示信息
	{
		pDC->TextOut(15,50, "单击鼠标左键输入数据！");
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDlgDocFrameView printing

BOOL CDlgDocFrameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDlgDocFrameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDlgDocFrameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDlgDocFrameView diagnostics

#ifdef _DEBUG
void CDlgDocFrameView::AssertValid() const
{
	CView::AssertValid();
}

void CDlgDocFrameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDlgDocFrameDoc* CDlgDocFrameView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDlgDocFrameDoc)));
	return (CDlgDocFrameDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDlgDocFrameView message handlers

void CDlgDocFrameView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CDlgDocFrameDoc* pDoc = GetDocument();//获取关联的文档对象
	ASSERT_VALID(pDoc);
	CDlgDocFrameDlg dlgInput;			//对话框对象
	if (dlgInput.DoModal()== IDOK)				//如果是OK按钮将数据保存Doc类
	{
		pDoc->m_dbXdata[pDoc->m_nPointCount] = dlgInput.m_dbX;
		pDoc->m_dbYdata[pDoc->m_nPointCount] = dlgInput.m_dbY;
		pDoc->m_nPointCount++;
		Invalidate();//更新视图
	}
	CView::OnLButtonDown(nFlags, point);
}
