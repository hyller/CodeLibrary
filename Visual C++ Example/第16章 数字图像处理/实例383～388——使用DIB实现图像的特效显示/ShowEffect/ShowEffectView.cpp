// ShowEffectView.cpp : implementation of the CShowEffectView class
//

#include "stdafx.h"
#include "ShowEffect.h"

#include "ShowEffectDoc.h"
#include "ShowEffectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowEffectView

IMPLEMENT_DYNCREATE(CShowEffectView, CView)

BEGIN_MESSAGE_MAP(CShowEffectView, CView)
	//{{AFX_MSG_MAP(CShowEffectView)
	ON_COMMAND(ID_BLOCK, OnBlock)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_COMMAND_RANGE(ID_LTOR, ID_BTOT, OnImageScan)//消息映射宏
	ON_COMMAND_RANGE(ID_LEFT, ID_BOTTOM, OnImageMove)//消息映射宏
	ON_COMMAND_RANGE(ID_HOR, ID_VER, OnImageJalousie)//消息映射宏
	ON_COMMAND_RANGE(ID_GRID_HOR, ID_GRID_VER, OnImageGrid)//消息映射宏
	ON_COMMAND_RANGE(ID_EXTEND_VER, ID_SHRINK_HOR, OnImageStunt)//消息映射宏
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowEffectView construction/destruction

CShowEffectView::CShowEffectView()
{
	// TODO: add construction code here

}

CShowEffectView::~CShowEffectView()
{
}

BOOL CShowEffectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShowEffectView drawing

void CShowEffectView::OnDraw(CDC* pDC)
{
	CShowEffectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	HGLOBAL hDIB = pDoc->GetHObject();	
	if (hDIB != NULL)							   		// 判断DIB是否为空
	{
		LPSTR lpDibSection = (LPSTR) ::GlobalLock(hDIB);				
		int cxDIB = (int) pDoc->m_dib.GetWidth(lpDibSection);			// 获取DIB宽度	
		int cyDIB = (int) pDoc->m_dib.GetHeight(lpDibSection);			// 获取DIB高度
		::GlobalUnlock(hDIB);		
		CRect rcDIB;
		rcDIB.top = rcDIB.left = 0;
		rcDIB.right = cxDIB;
		rcDIB.bottom = cyDIB;		
		CRect rcDest= rcDIB;	
		// 重画DIB
		pDoc->m_dib.DrawDib(pDC->m_hDC, &rcDest, pDoc->GetHObject(),&rcDIB, pDoc->GetDocPal());                                               
	}
	else
	{
		pDC->TextOut(20,20,"通过文件菜单先打开BMP图像，而后就可以通过扫描特效菜单命令进行特效显示");
	}

}

/////////////////////////////////////////////////////////////////////////////
// CShowEffectView printing

BOOL CShowEffectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CShowEffectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CShowEffectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CShowEffectView diagnostics

#ifdef _DEBUG
void CShowEffectView::AssertValid() const
{
	CView::AssertValid();
}

void CShowEffectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShowEffectDoc* CShowEffectView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShowEffectDoc)));
	return (CShowEffectDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowEffectView message handlers
void CShowEffectView::OnImageScan(UINT nID)
{
	CShowEffectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	SetCursor(LoadCursor(NULL, IDC_WAIT));			//光标显示为处理状态
	long	lSrcWidth;								//图像的宽度和高度
	long	lSrcHeight;
	LPSTR	lpSrcDib;							//指向源图像的指针	
	LPSTR   lpDstDib;
	LPSTR lpSrcStartBits;
	lpSrcDib= (LPSTR) ::GlobalLock((HGLOBAL) pDoc->GetHObject());// 锁定DIB
	lSrcWidth= pDoc->m_dib.GetWidth(lpSrcDib);		// 获取图像的宽度		
	lSrcHeight= pDoc->m_dib.GetHeight(lpSrcDib);		// 获取图像的高度
	lpSrcStartBits=pDoc->m_dib.GetBits(lpSrcDib);		// 找到DIB图像象素起始位置
	LPBITMAPINFO lpbmi;						// 指向BITMAPINFO结构的指针
	// 分配内存
	HGLOBAL hDIB = (HGLOBAL) ::GlobalAlloc(GHND, lSrcWidth*lSrcHeight);
	if (hDIB == NULL)							// 判断是否是有效的DIB对象
	{		
		return;								// 不是，则返回
	}		
	lpDstDib=  (char * )::GlobalLock((HGLOBAL) hDIB);// 锁定内存
	memcpy(lpDstDib, lpSrcDib, lSrcWidth*lSrcHeight);	// 复制DIB数据
	lpbmi = (LPBITMAPINFO)lpDstDib;				// 获取指针
	CDC *pDC=GetDC();							//获取视的客户区
	CRect rect(0,0,lSrcWidth,lSrcHeight);
	CBrush brush(RGB(200,200,200));				//创建画刷
	pDC->FillRect(&rect,&brush);					//特技显示前，填充客户区背景
	CPalette * pPal=new CPalette;					// 创建新调色板
	pDoc->m_dib.ConstructPalette(pDoc->m_dib.m_hDib,pPal);
    CPalette * pOldPal=pDC->SelectPalette(pPal, TRUE);	//将逻辑调色板选为当前调色板
    pDC->RealizePalette();							//实现调色板
	int i=0,j=0,k=0;								//设置一些循环变量
	int nScanLine=2;								//设定栅格特技时的定位量
	switch(nID)								//判断当前的菜单命令
	{
		case ID_TTOB:					//自上而下
			for(j=0;j<=lSrcHeight;j++)
			{
				for(i=0;i<=lSrcWidth;i++)
				{
					::StretchDIBits(pDC->GetSafeHdc(),i,0,1,j,
						i,lSrcHeight-j,1,j,
						lpSrcStartBits, lpbmi,
						DIB_RGB_COLORS, SRCCOPY); 	 
				}
				//每显示一行暂停2毫秒
				Sleep(2);				
			}
		pDC->SelectPalette(pOldPal, TRUE);			//恢复原调色板
        ::DeleteObject(pPal);						//删除新建的调色板对象
		break;
		
		case ID_BTOT:					//自下而上
			for(j=0;j<=lSrcHeight;j++)
			{
				for(i=0;i<=lSrcWidth;i++)
				{
					::StretchDIBits(pDC->GetSafeHdc(),i,lSrcHeight-j,1,j,
						i,0,1,j,
						lpSrcStartBits, lpbmi,
						DIB_RGB_COLORS, SRCCOPY); 	 
				}
		//每显示一行暂停2毫秒
				Sleep(2);				
			}
		pDC->SelectPalette(pOldPal, TRUE);			//恢复原调色板
        ::DeleteObject(pPal);						//删除新建的调色板对象
		break;
	
		case ID_LTOR:						//自左向右
			for(i=0;i<lSrcWidth;i++)
			{
				::StretchDIBits(pDC->GetSafeHdc(),   i, 0, 1, lSrcHeight,
					i,  0, 1, lSrcHeight,
					lpSrcStartBits, lpbmi,
					DIB_RGB_COLORS, SRCCOPY);
				//每显示一行暂停3毫秒
			Sleep(3); 					
			}
            pDC->SelectPalette(pOldPal, TRUE);		//恢复原调色板
           ::DeleteObject(pPal);					//删除新建的调色板对象
			break;
		case ID_RTOL:				 		//自右向左
			for(i=0;i<lSrcWidth;i++)
			{
				::StretchDIBits(pDC->GetSafeHdc(),  lSrcWidth-i, 0, 1, lSrcHeight,
					lSrcWidth-i,  0, 1, lSrcHeight,
					lpSrcStartBits, lpbmi,
					DIB_RGB_COLORS, SRCCOPY);
				//每显示一行暂停3毫秒
					Sleep(3); 					
			}
			pDC->SelectPalette(pOldPal, TRUE);
			::DeleteObject(pPal);
			break;
		default :							//没有处理的消息来此
			AfxMessageBox("无扫描效果！");//给出提示
			break;
	}
	Invalidate();								//刷新客户区
	SetCursor(LoadCursor(NULL, IDC_ARROW));		//恢复光标原始状态
}

void CShowEffectView::OnImageMove(UINT nID)
{
	CShowEffectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	SetCursor(LoadCursor(NULL, IDC_WAIT));					//光标显示为处理状态
	long	lSrcWidth;										//图像的宽度和高度
	long	lSrcHeight;
	LPSTR	lpSrcDib;							//指向源图像的指针	
	LPSTR   lpDstDib;
	LPSTR lpSrcStartBits;
	lpSrcDib= (LPSTR) ::GlobalLock((HGLOBAL) pDoc->GetHObject());// 锁定DIB
	lSrcWidth= pDoc->m_dib.GetWidth(lpSrcDib);		// 获取图像的宽度		
	lSrcHeight= pDoc->m_dib.GetHeight(lpSrcDib);		// 获取图像的高度
	lpSrcStartBits=pDoc->m_dib.GetBits(lpSrcDib);		// 找到DIB图像象素起始位置
	LPBITMAPINFO lpbmi;						// 指向BITMAPINFO结构的指针
	// 分配内存
	HGLOBAL hDIB = (HGLOBAL) ::GlobalAlloc(GHND, lSrcWidth*lSrcHeight);
	if (hDIB == NULL)							// 判断是否是有效的DIB对象
	{		
		return;
	}		
	lpDstDib=  (char * )::GlobalLock((HGLOBAL) hDIB);// 锁定内存
	memcpy(lpDstDib, lpSrcDib, lSrcWidth*lSrcHeight);	// 复制DIB数据
	lpbmi = (LPBITMAPINFO)lpDstDib;				// 获取指针
	CDC *pDC=GetDC();							//获取视的客户区
	CRect rect(0,0,lSrcWidth,lSrcHeight);
	CBrush brush(RGB(200,200,200));				//创建画刷
	pDC->FillRect(&rect,&brush);					//特技显示前，填充客户区背景
	CPalette * pPal=new CPalette;					// 创建新调色板
	pDoc->m_dib.ConstructPalette(pDoc->m_dib.m_hDib,pPal);
    CPalette * pOldPal=pDC->SelectPalette(pPal, TRUE);	//将逻辑调色板选为当前调色板
    pDC->RealizePalette();							//实现调色板
	int i=0,j=0,k=0;								//设置一些循环变量
	int nScanLine=2;								//设定栅格特技时的定位量
	switch(nID)								//判断当前的菜单命令
	{
		case ID_LEFT:					//从左边移动进入
			for(i=0;i<=lSrcWidth;i++)
			{
				for(j=0;j<=lSrcHeight;j=j+8)
				{
					::StretchDIBits(pDC->GetSafeHdc(),0,  j-8 ,  i+1, 8,
						lSrcWidth-i, lSrcHeight-j, i+1, 8,
						lpSrcStartBits, lpbmi,
						DIB_RGB_COLORS, SRCCOPY); 	 
				}
				Sleep(2); 					
			}
            pDC->SelectPalette(pOldPal, TRUE);		//恢复原调色板
        	::DeleteObject(pPal);					//删除新建的调色板对象
			break;
		case ID_BOTTOM:						//从底部移动进入
			for(i=0;i<=lSrcHeight;i++)
			{
				for(j=0;j<=lSrcWidth;j=j++)
				{
					::StretchDIBits(pDC->GetSafeHdc(), j ,  lSrcHeight-i , 1, i  ,
						j , lSrcHeight-i , 1, i ,
						lpSrcStartBits, lpbmi,
						DIB_RGB_COLORS, SRCCOPY); 
				}		
				Sleep(2); 					
			}
			pDC->SelectPalette(pOldPal, TRUE);		//恢复原调色板
        	::DeleteObject(pPal);					//删除新建的调色板对象
			break;
		case ID_RIGHT:					//水平向左插入
			for(i=0;i<=lSrcWidth;i++)
			{
				for(j=0;j<=lSrcHeight;j++)
				{
					::StretchDIBits(pDC->GetSafeHdc(),lSrcWidth-i,j,i,1,
						0,lSrcHeight-j,i,1,
						lpSrcStartBits, lpbmi,
						DIB_RGB_COLORS, SRCCOPY); 	 
				}
				Sleep(2); 					
			}
			pDC->SelectPalette(pOldPal, TRUE);		//恢复原调色板
        	::DeleteObject(pPal);					//删除新建的调色板对象
			break;
		case ID_TOP:					//从顶部移动进入
			for(i=0;i<=lSrcHeight;i++)
			{
				{
					::StretchDIBits(pDC->GetSafeHdc(),0,0,lSrcWidth,i,
						0,0,lSrcWidth,i,
						lpSrcStartBits,lpbmi,
						DIB_RGB_COLORS,SRCCOPY); 
				}
				Sleep(2); 					
			}
			pDC->SelectPalette(pOldPal, TRUE);		//恢复原调色板
        	  	::DeleteObject(pPal);					//删除新建的调色板对象
			break;
	}
	Invalidate();								//刷新客户区
	SetCursor(LoadCursor(NULL, IDC_ARROW));		//恢复光标原始状态
}

void CShowEffectView::OnBlock() 
{
	// TODO: Add your command handler code here
	CShowEffectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	SetCursor(LoadCursor(NULL, IDC_WAIT));					//光标显示为处理状态
	long	lSrcWidth;										//图像的宽度和高度
	long	lSrcHeight;
	LPSTR	lpSrcDib;									//指向源图像的指针	
	LPSTR   lpDstDib;
	LPSTR lpSrcStartBits;
	lpSrcDib= (LPSTR) ::GlobalLock((HGLOBAL) pDoc->GetHObject());// 锁定DIB
	lSrcWidth= pDoc->m_dib.GetWidth(lpSrcDib);		// 获取图像的宽度		
	lSrcHeight= pDoc->m_dib.GetHeight(lpSrcDib);		// 获取图像的高度
	lpSrcStartBits=pDoc->m_dib.GetBits(lpSrcDib);		// 找到DIB图像象素起始位置
	LPBITMAPINFO lpbmi;						// 指向BITMAPINFO结构的指针
	// 分配内存
	HGLOBAL hDIB = (HGLOBAL) ::GlobalAlloc(GHND, lSrcWidth*lSrcHeight);
	if (hDIB == NULL)							// 判断是否是有效的DIB对象
	{		
		return;
	}		
	lpDstDib=  (char * )::GlobalLock((HGLOBAL) hDIB);// 锁定内存
	memcpy(lpDstDib, lpSrcDib, lSrcWidth*lSrcHeight);	// 复制DIB数据
	lpbmi = (LPBITMAPINFO)lpDstDib;				// 获取指针
	CDC *pDC=GetDC();							//获取视的客户区
	CRect rect(0,0,lSrcWidth,lSrcHeight);
	CBrush brush(RGB(200,200,200));				//创建画刷
	pDC->FillRect(&rect,&brush);					//特技显示前，填充客户区背景
	CPalette * pPal=new CPalette;					// 创建新调色板
	pDoc->m_dib.ConstructPalette(pDoc->m_dib.m_hDib,pPal);
    CPalette * pOldPal=pDC->SelectPalette(pPal, TRUE);	//将逻辑调色板选为当前调色板
    pDC->RealizePalette();							//实现调色板
	int i=0,j=0,k=0;								//设置一些循环变量
	long lBlockX,lBlockY;					//块坐标
	int nrw,nrh,nBlockNum; 				//块余数及块号
	lBlockX=lBlockY=nrw=nrh=nBlockNum=0;
	//块大小40，当不能分为整数块时，将余下的作为一块
	if((lSrcWidth%40)!=0)	
	{
		nrw=1;
	}
	if((lSrcHeight%40)!=0)
	{
		nrh=1;
	}
	long lBlockNum;						//总块数
	lBlockNum=(lSrcWidth/20+nrw)*(lSrcHeight/20+nrh);
	POINT* pPoint;						//用来记录每块的首地址
	pPoint=new POINT[lBlockNum];
	for(nBlockNum=0;nBlockNum<lBlockNum;nBlockNum++)
	{								//完成块首地址数组的赋值
		pPoint[nBlockNum].x=lBlockX;
		pPoint[nBlockNum].y=lBlockY;
		lBlockX=lBlockX+40;
		if(lBlockX>lSrcWidth)
		{
			lBlockX=0;
			lBlockY=lBlockY+40;
		}
	}
	for(i=0;i<=1;i++)//循环两次
	{
		for(nBlockNum=lBlockNum-1;nBlockNum>=0;nBlockNum--)
		{	//逐块显示，k为随机数，用来指示随机显示象素块的顺序
			k=(int)((double)lBlockNum*rand()/RAND_MAX);
			lBlockX=pPoint[k].x;			//提取块坐标
			lBlockY=pPoint[k].y;
			::StretchDIBits(pDC->GetSafeHdc(),lBlockX, lBlockY, 40,40,
						lBlockX,lSrcHeight-lBlockY-40, 40,40,
						lpSrcStartBits, lpbmi,
						DIB_RGB_COLORS, SRCCOPY);
			pPoint[k].x=pPoint[nBlockNum].x;
			pPoint[k].y=pPoint[nBlockNum].y;
			Sleep(5);								
		}
	
	}
	pDC->SelectPalette(pOldPal, TRUE);		//恢复原调色板
    ::DeleteObject(pPal);					//删除新建的调色板对象
	delete[] pPoint;						//删除临时数组 
	Invalidate();								//刷新客户区
	SetCursor(LoadCursor(NULL, IDC_ARROW));		//恢复光标原始状态
}


void CShowEffectView::OnImageJalousie(UINT nID)//百叶窗特效
{
	CShowEffectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	SetCursor(LoadCursor(NULL, IDC_WAIT));					//光标显示为处理状态
	long	lSrcWidth;										//图像的宽度和高度
	long	lSrcHeight;
	LPSTR	lpSrcDib;							//指向源图像的指针	
	LPSTR   lpDstDib;
	LPSTR lpSrcStartBits;
	lpSrcDib= (LPSTR) ::GlobalLock((HGLOBAL) pDoc->GetHObject());// 锁定DIB
	lSrcWidth= pDoc->m_dib.GetWidth(lpSrcDib);		// 获取图像的宽度		
	lSrcHeight= pDoc->m_dib.GetHeight(lpSrcDib);		// 获取图像的高度
	lpSrcStartBits=pDoc->m_dib.GetBits(lpSrcDib);		// 找到DIB图像象素起始位置
	LPBITMAPINFO lpbmi;						// 指向BITMAPINFO结构的指针
	// 分配内存
	HGLOBAL hDIB = (HGLOBAL) ::GlobalAlloc(GHND, lSrcWidth*lSrcHeight);
	if (hDIB == NULL)							// 判断是否是有效的DIB对象
	{		
		return;
	}		
	lpDstDib=  (char * )::GlobalLock((HGLOBAL) hDIB);// 锁定内存
	memcpy(lpDstDib, lpSrcDib, lSrcWidth*lSrcHeight);	// 复制DIB数据
	lpbmi = (LPBITMAPINFO)lpDstDib;				// 获取指针
	CDC *pDC=GetDC();							//获取视的客户区
	CRect rect(0,0,lSrcWidth,lSrcHeight);
	CBrush brush(RGB(200,200,200));				//创建画刷
	pDC->FillRect(&rect,&brush);					//特技显示前，填充客户区背景
	CPalette * pPal=new CPalette;					// 创建新调色板
	pDoc->m_dib.ConstructPalette(pDoc->m_dib.m_hDib,pPal);
    CPalette * pOldPal=pDC->SelectPalette(pPal, TRUE);	//将逻辑调色板选为当前调色板
    pDC->RealizePalette();							//实现调色板
	int i=0,j=0,k=0;								//设置一些循环变量
	switch(nID)								//判断当前的菜单命令
	{
		case ID_VER:					//垂直方向
		for(i=0;i<=lSrcWidth/15;i++)//分成15格
		{
			for(j=0;j<=15;j++)
			{
				::StretchDIBits(pDC->GetSafeHdc(),j*lSrcWidth/15, 0, i, lSrcHeight,
					j*lSrcWidth/15, 0, i, lSrcHeight,
					lpSrcStartBits, lpbmi,
					DIB_RGB_COLORS, SRCCOPY);
				Sleep(2);				 
			}
		}
		pDC->SelectPalette(pOldPal, TRUE);		//恢复原调色板
        ::DeleteObject(pPal);					//删除新建的调色板对象
		break;
	case ID_HOR:						//水平方向
		for(j=0;j<=lSrcHeight/15;j++)
		{
			for(i=0;i<=15;i++)
			{
				::StretchDIBits(pDC->GetSafeHdc(),0, i*lSrcHeight/15, lSrcWidth,j,
					0, (14-i)*lSrcHeight/15, lSrcWidth,j,
					lpSrcStartBits, lpbmi,
					DIB_RGB_COLORS, SRCCOPY);
				Sleep(2); 				
			}
		}
		pDC->SelectPalette(pOldPal, TRUE);		//恢复原调色板
        ::DeleteObject(pPal);					//删除新建的调色板对象
		break;

	}
	Invalidate();								//刷新客户区
	SetCursor(LoadCursor(NULL, IDC_ARROW));		//恢复光标原始状态
}

void CShowEffectView::OnImageGrid(UINT nID)//栅格交错特效
{
	CShowEffectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	SetCursor(LoadCursor(NULL, IDC_WAIT));					//光标显示为处理状态
	long	lSrcWidth;										//图像的宽度和高度
	long	lSrcHeight;
	LPSTR	lpSrcDib;							//指向源图像的指针	
	LPSTR   lpDstDib;
	LPSTR lpSrcStartBits;
	lpSrcDib= (LPSTR) ::GlobalLock((HGLOBAL) pDoc->GetHObject());// 锁定DIB
	lSrcWidth= pDoc->m_dib.GetWidth(lpSrcDib);		// 获取图像的宽度		
	lSrcHeight= pDoc->m_dib.GetHeight(lpSrcDib);		// 获取图像的高度
	lpSrcStartBits=pDoc->m_dib.GetBits(lpSrcDib);		// 找到DIB图像象素起始位置
	LPBITMAPINFO lpbmi;						// 指向BITMAPINFO结构的指针
	// 分配内存
	HGLOBAL hDIB = (HGLOBAL) ::GlobalAlloc(GHND, lSrcWidth*lSrcHeight);
	if (hDIB == NULL)							// 判断是否是有效的DIB对象
	{		
		return;
	}		
	lpDstDib=  (char * )::GlobalLock((HGLOBAL) hDIB);// 锁定内存
	memcpy(lpDstDib, lpSrcDib, lSrcWidth*lSrcHeight);	// 复制DIB数据
	lpbmi = (LPBITMAPINFO)lpDstDib;				// 获取指针
	CDC *pDC=GetDC();							//获取视的客户区
	CRect rect(0,0,lSrcWidth,lSrcHeight);
	CBrush brush(RGB(200,200,200));				//创建画刷
	pDC->FillRect(&rect,&brush);					//特技显示前，填充客户区背景
	CPalette * pPal=new CPalette;					// 创建新调色板
	pDoc->m_dib.ConstructPalette(pDoc->m_dib.m_hDib,pPal);
    CPalette * pOldPal=pDC->SelectPalette(pPal, TRUE);	//将逻辑调色板选为当前调色板
    pDC->RealizePalette();							//实现调色板
	int i=0,j=0,k=0;								//设置一些循环变量
	int nScanLine=2;								//设定栅格的宽度
	switch(nID)								//判断当前的菜单命令
	{
		case ID_GRID_HOR:						//水平栅格交错
			for(i=0;i<=lSrcWidth;i++)
			{
				for(j=0;j<=lSrcHeight;j=j+2*nScanLine)
				{
					::StretchDIBits(pDC->GetSafeHdc(),0,j,i+1,nScanLine,
						lSrcWidth-i,lSrcHeight-j,i+1,nScanLine,lpSrcStartBits,lpbmi,
						DIB_RGB_COLORS,SRCCOPY);
					k=j+nScanLine;				//偶数格子的起始地址
					::StretchDIBits(pDC->GetSafeHdc(),lSrcWidth-i,k,i+1,nScanLine,
						0,lSrcHeight-k,i+1,nScanLine,
						lpSrcStartBits,lpbmi,
						DIB_RGB_COLORS,SRCCOPY);
				}
			}
            pDC->SelectPalette(pOldPal, TRUE);		//恢复原调色板
        	  ::DeleteObject(pPal);					//删除新建的调色板对象
			break;
		case ID_GRID_VER:						//垂直栅格交错
			for(j=0;j<=lSrcHeight;j++)
			{
				for(i=0;i<=lSrcWidth;i=i+2*nScanLine)
				{
					::StretchDIBits(pDC->GetSafeHdc(),i,  0 ,  nScanLine, j+1,
						i, 0, nScanLine, j+1,
						lpSrcStartBits, lpbmi,
						DIB_RGB_COLORS, SRCCOPY);
					k=i+nScanLine;				//偶数格子(即右半部分)的起始地址
					::StretchDIBits(pDC->GetSafeHdc(), k, lSrcHeight-j ,  nScanLine,  j+1,
						k,lSrcHeight-j, nScanLine, j+1,
						lpSrcStartBits, lpbmi,
						DIB_RGB_COLORS, SRCCOPY);
					
				}
			}
            pDC->SelectPalette(pOldPal, TRUE);		//恢复原调色板
        	::DeleteObject(pPal);					//删除新建的调色板对象
			break;
	}
	Invalidate();								//刷新客户区
	SetCursor(LoadCursor(NULL, IDC_ARROW));		//恢复光标原始状态
}

void CShowEffectView::OnImageStunt(UINT nID)//伸缩特效显示
{
	CShowEffectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	SetCursor(LoadCursor(NULL, IDC_WAIT));			//光标显示为处理状态
	long	lSrcWidth;								//图像的宽度和高度
	long	lSrcHeight;
	LPSTR	lpSrcDib;							//指向源图像的指针	
	LPSTR   lpDstDib;
	LPSTR lpSrcStartBits;
	lpSrcDib= (LPSTR) ::GlobalLock((HGLOBAL) pDoc->GetHObject());// 锁定DIB
	lSrcWidth= pDoc->m_dib.GetWidth(lpSrcDib);		// 获取图像的宽度		
	lSrcHeight= pDoc->m_dib.GetHeight(lpSrcDib);		// 获取图像的高度
	lpSrcStartBits=pDoc->m_dib.GetBits(lpSrcDib);		// 找到DIB图像象素起始位置
	LPBITMAPINFO lpbmi;						// 指向BITMAPINFO结构的指针
	// 分配内存
	HGLOBAL hDIB = (HGLOBAL) ::GlobalAlloc(GHND, lSrcWidth*lSrcHeight);
	if (hDIB == NULL)							// 判断是否是有效的DIB对象
	{		
		return;								// 不是，则返回
	}		
	lpDstDib=  (char * )::GlobalLock((HGLOBAL) hDIB);// 锁定内存
	memcpy(lpDstDib, lpSrcDib, lSrcWidth*lSrcHeight);	// 复制DIB数据
	lpbmi = (LPBITMAPINFO)lpDstDib;				// 获取指针
	CDC *pDC=GetDC();							//获取视的客户区
	CRect rect(0,0,lSrcWidth,lSrcHeight);
	CBrush brush(RGB(200,200,200));				//创建画刷
	pDC->FillRect(&rect,&brush);					//特技显示前，填充客户区背景
	CPalette * pPal=new CPalette;					// 创建新调色板
	pDoc->m_dib.ConstructPalette(pDoc->m_dib.m_hDib,pPal);
    CPalette * pOldPal=pDC->SelectPalette(pPal, TRUE);	//将逻辑调色板选为当前调色板
    pDC->RealizePalette();							//实现调色板
	int i=0,j=0,k=0;								//设置一些循环变量
	switch(nID)								//判断当前的菜单命令
	{
		case ID_EXTEND_VER:					//上下展开
			for(i=0;i<=lSrcWidth/2;i++)
			{		
				::StretchDIBits(pDC->GetSafeHdc(),0 ,  lSrcHeight/2+i  , lSrcWidth, 1 ,
					0  , lSrcHeight/2-i , lSrcWidth,1 ,
					lpSrcStartBits, lpbmi,
					DIB_RGB_COLORS, SRCCOPY); 
				::StretchDIBits(pDC->GetSafeHdc(),0 ,  lSrcHeight/2-i  , lSrcWidth, 1 ,
					0  , lSrcHeight/2+i , lSrcWidth,1 ,
					lpSrcStartBits, lpbmi,
					DIB_RGB_COLORS, SRCCOPY); 
				Sleep(2); 					
			}
            pDC->SelectPalette(pOldPal, TRUE);		//恢复原调色板
        	::DeleteObject(pPal);					//删除新建的调色板对象
			break;
		case ID_SHRINK_VER:					//上下收缩
			for(j=0;j<lSrcHeight/2;j++)
			{
				::StretchDIBits(pDC->GetSafeHdc(),0, j, lSrcWidth, 1,
					0, lSrcHeight-j, lSrcWidth, 1,
					lpSrcStartBits, lpbmi,
					DIB_RGB_COLORS, SRCCOPY);
				::StretchDIBits(pDC->GetSafeHdc(),0, lSrcHeight-j, lSrcWidth, 1,
					0,  j, lSrcWidth, 1,
					lpSrcStartBits, lpbmi,
					DIB_RGB_COLORS, SRCCOPY);
				Sleep(2); 	
			}
            pDC->SelectPalette(pOldPal, TRUE);		//恢复原调色板
        	::DeleteObject(pPal);					//删除新建的调色板对象
		break;
		case ID_EXTEND_HOR:					//左右展开
			for(j=0;j<=lSrcWidth/2;j++)
			{		
				::StretchDIBits(pDC->GetSafeHdc(),lSrcWidth/2+j,0,1,lSrcHeight,
					lSrcWidth/2+j,0,1,lSrcHeight,
					lpSrcStartBits, lpbmi,
					DIB_RGB_COLORS, SRCCOPY); 
				::StretchDIBits(pDC->GetSafeHdc(),lSrcWidth/2-j,0,1,lSrcHeight,
					lSrcWidth/2-j,0,1,lSrcHeight,
					lpSrcStartBits, lpbmi,
					DIB_RGB_COLORS, SRCCOPY); 
				Sleep(2);								
			}
            pDC->SelectPalette(pOldPal, TRUE);		//恢复原调色板
        	::DeleteObject(pPal);					//删除新建的调色板对象
		   break;
		case ID_SHRINK_HOR:					//左右收缩
			for(j=0;j<lSrcWidth/2;j++)
			{
				::StretchDIBits(pDC->GetSafeHdc(),j, 0, 1, lSrcHeight,
					j, 0, 1, lSrcHeight,
					lpSrcStartBits, lpbmi,
					DIB_RGB_COLORS, SRCCOPY);
				::StretchDIBits(pDC->GetSafeHdc(),lSrcWidth-j,0,1,lSrcHeight,
					lSrcWidth-j,0,1,lSrcHeight,
					lpSrcStartBits, lpbmi,
					DIB_RGB_COLORS, SRCCOPY);
				Sleep(2);					
			}
            pDC->SelectPalette(pOldPal, TRUE);		//恢复原调色板
        	  ::DeleteObject(pPal);					//删除新建的调色板对象
		   break;
	}
	Invalidate();								//刷新客户区
	SetCursor(LoadCursor(NULL, IDC_ARROW));		//恢复光标原始状态
}