// DebugDemoView.cpp : implementation of the CDebugDemoView class
//

#include "stdafx.h"
#include "DebugDemo.h"

#include "DebugDemoDoc.h"
#include "DebugDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define number 8
/////////////////////////////////////////////////////////////////////////////
// CDebugDemoView

IMPLEMENT_DYNCREATE(CDebugDemoView, CView)

BEGIN_MESSAGE_MAP(CDebugDemoView, CView)
	//{{AFX_MSG_MAP(CDebugDemoView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDebugDemoView construction/destruction

CDebugDemoView::CDebugDemoView()
{
	// TODO: add construction code here

}

CDebugDemoView::~CDebugDemoView()
{
}

BOOL CDebugDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDebugDemoView drawing

void CDebugDemoView::OnDraw(CDC* pDC)
{
	CDebugDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	srand( (unsigned)time( NULL ) );//产生随机种子
	int array[number];
	CString str1,str2;
	str1="原始顺序：";
	for(int i=0;i<number;i++)
	{
		array[i]=rand();
		str2.Format("%d  ",array[i]);
		str1+=str2;
	}
	pDC->TextOut(20,10,str1);//输出原始数组顺序
	BubbleSort(array, 1, number);
	str1="排序顺序：";
	for( i=0;i<number;i++)
	{
		str2.Format("%d  ",array[i]);
		str1+=str2;
	}
	pDC->TextOut(20,30,str1);//输出排序后的数组顺序
}

/////////////////////////////////////////////////////////////////////////////
// CDebugDemoView printing

BOOL CDebugDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDebugDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDebugDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDebugDemoView diagnostics

#ifdef _DEBUG
void CDebugDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CDebugDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDebugDemoDoc* CDebugDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDebugDemoDoc)));
	return (CDebugDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDebugDemoView message handlers

void CDebugDemoView::Swap(int &a, int &b)
{
	int c=a;a=b;b=c;
}

void CDebugDemoView::BubbleSort(int array[], BOOL asc, int num)
{
	while(num>=0)
	{
		for (int j=0;j<num;j++)
		{
			switch(asc)
			{
				case 1://升序
					if(array[j]>array[j+1])
					{
						Swap(array[j],array[j+1]);
					}
					break;
				case 0://降序
					if(array[j]<array[j+1])
					{
						Swap(array[j],array[j+1]);
					}
					break;	
			}
		}
		num--;
	}
}
