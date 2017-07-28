// OpenGLBaseView.cpp : implementation of the COpenGLBaseView class
//

#include "stdafx.h"
#include "OpenGLBase.h"

#include "OpenGLBaseDoc.h"
#include "OpenGLBaseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenGLBaseView

IMPLEMENT_DYNCREATE(COpenGLBaseView, CView)

BEGIN_MESSAGE_MAP(COpenGLBaseView, CView)
	//{{AFX_MSG_MAP(COpenGLBaseView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenGLBaseView construction/destruction

COpenGLBaseView::COpenGLBaseView()
{
	// TODO: add construction code here

}

COpenGLBaseView::~COpenGLBaseView()
{
}

BOOL COpenGLBaseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
//	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;//剪掉子窗口和兄弟窗口
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// COpenGLBaseView drawing

void COpenGLBaseView::OnDraw(CDC* pDC)
{
	COpenGLBaseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//指定在后台缓存中绘制
	glDrawBuffer(GL_BACK);
	//初始化变换矩阵
	glLoadIdentity();
	glClearColor(0.0,0.0,0.0,0.0f);//设置背景颜色为黑色
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//清除背景颜色
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0); // 设置观察点位置
	glLoadIdentity(); // 设置当前矩阵为单位矩阵（无缩放和旋转）
	glColor3f(1.0f, 0.0f, 0.0f); // 设置绘图颜色为红色
	DrawGLSquare(); // 画正方形
	glPushMatrix();
		glScalef(2.0f, 0.5f, 0.0f); // x方向的尺寸放大一倍, y方向的尺寸缩小一倍
		glColor3f(0.0f, 1.0f, 0.0f); // 设置绘图颜色为绿色
		DrawGLSquare(); // 画扁矩形
	glPopMatrix();
	glPushMatrix();
		glRotatef(45.0f, 0.0f, 0.0f, 1.0f); // 沿z轴旋转45度
		glColor3f(0.0f, 0.0f, 1.0f); // 设置绘图颜色为蓝色
		DrawGLSquare(); // 画菱形
		glScalef(0.5f, 0.5f, 0.0f); // x方向与y方向的尺寸都缩小一半
		glColor3f(1.0f, 1.0f, 0.0f); // 设置绘图颜色为黄色
		DrawGLSquare();// 画小菱形
	glPopMatrix();
	gluLookAt(3, 2, 6, 0, 0, 0, 0, 1, 0); // 设置观察点位置
	glColor3f(1.0f, 1.0f, 0.0f); //设置绘图颜色
	glPushMatrix();
	glColor3f(0.0,1.0,1.0);
	glTranslatef(-5.0,0.2,0.0);
	auxWireTeapot(1.6);// 画茶壶网格
	glTranslatef(9.0,3.0,0.0);
	auxSolidTeapot(1.6);//实心茶壶
	glPopMatrix();	
	//交换前后缓存
	SwapBuffers(wglGetCurrentDC());
	//绘制前景
	glDrawBuffer(GL_FRONT);
}
void COpenGLBaseView::DrawGLSquare() 
{ // X-Y平面中的正方形
	glBegin(GL_LINES); // 逆时针画边线框
		// 画左边线
		glVertex3f(-1.0f, 1.0f, 0.0f); // 似MoveTo
		glVertex3f(-1.0f, -1.0f, 0.0f); // 似LineTo
		// 画下边线
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
		// 画右边线
		glVertex3f(1.0f, -1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		// 画上边线
		glVertex3f(1.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
	glEnd();
}

/////////////////////////////////////////////////////////////////////////////
// COpenGLBaseView printing

BOOL COpenGLBaseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COpenGLBaseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COpenGLBaseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// COpenGLBaseView diagnostics

#ifdef _DEBUG
void COpenGLBaseView::AssertValid() const
{
	CView::AssertValid();
}

void COpenGLBaseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpenGLBaseDoc* COpenGLBaseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpenGLBaseDoc)));
	return (COpenGLBaseDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpenGLBaseView message handlers

int COpenGLBaseView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
    m_pDC = new CClientDC(this);
    ASSERT(m_pDC != NULL);
	//	初始化像素格式
    static PIXELFORMATDESCRIPTOR pfd = 
	{
        sizeof(PIXELFORMATDESCRIPTOR),   // 结构大小
        1,                               // 版本
        PFD_DRAW_TO_WINDOW   |          // 支持Windows
          PFD_SUPPORT_OPENGL |          // 支持 OpenGL
          PFD_DOUBLEBUFFER,             // 双缓冲
        PFD_TYPE_RGBA,		            // 像素类型
        24,                             // 24-bit颜色位数
        0, 0, 0, 0, 0, 0,               // 忽略R、G、B位数
        0,                              // α值位数
        0,                              // α值偏移
        0,                              // 光栅缓存位数
        0, 0, 0, 0,                     // 光栅各分量缓存位数
        32,                             // 深度缓存位数
        0,                              // 图案缓存位数
        0,                              // 辅助缓存位数
        PFD_MAIN_PLANE,                 // 层类型
        0,                              // 保留
        0, 0, 0                         // 忽略掩码
    };
	//	选择像素格式
    int pixelformat;
    if ( (pixelformat = ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd)) == 0 )
    {
        AfxMessageBox("选择像素格式失败！");
        return -1;
    }
	//	设置像素格式
    if (SetPixelFormat(m_pDC->GetSafeHdc(), pixelformat, &pfd) == FALSE)
    {
        AfxMessageBox("设置像素格式失败！");
        return -1;
    }	
	//	创建绘制情景对象
    m_hglrc = wglCreateContext(m_pDC->GetSafeHdc());
	return 0;
}

void COpenGLBaseView::OnDestroy() 
{
	CView::OnDestroy();	
	// TODO: Add your message handler code here
	::wglMakeCurrent(NULL,  NULL);
	//	删除当前绘图情景对象并释放所占内存
    if (m_hglrc)
	{
        ::wglDeleteContext(m_hglrc);
		m_hglrc = NULL;
	}
    if (m_pDC)
        delete m_pDC;
}

void COpenGLBaseView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);	
	// TODO: Add your message handler code here
	if(m_hglrc)
		wglMakeCurrent(m_pDC->GetSafeHdc(), m_hglrc);//获取当前绘图场景
	else
		return;
	glViewport(0,0,cx,cy);//设置视口大小
	glMatrixMode(GL_PROJECTION);//设置变换模式为投影变换
	glLoadIdentity();//初始化投影变换矩阵
	//根据窗口大小设置调整正射投影矩阵
	if(cx<=cy)
		glOrtho(-5.0,5.0,-5.0*(GLfloat)cy/(GLfloat)cx,
			5.0*(GLfloat)cy/(GLfloat)cx,-12.0,12.0);
	else
		glOrtho(-5.0*(GLfloat)cx/(GLfloat)cy,
			5.0*(GLfloat)cx/(GLfloat)cy,-5.0,5.0,-12.0,12.0);
	//	设置变换模式为模型变换
	glMatrixMode(GL_MODELVIEW);
	//	初始化模型变换矩阵为单位矩阵
	glLoadIdentity();	
}

BOOL COpenGLBaseView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return true;
	//return CView::OnEraseBkgnd(pDC);
}
