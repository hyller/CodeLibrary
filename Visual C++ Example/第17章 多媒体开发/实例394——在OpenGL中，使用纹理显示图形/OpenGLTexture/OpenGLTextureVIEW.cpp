// OpenGLTextureView.cpp : implementation of the COpenGLTextureView class
//

#include "stdafx.h"
#include "OpenGLTexture.h"

#include "OpenGLTextureDoc.h"
#include "OpenGLTextureView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// COpenGLTextureView

IMPLEMENT_DYNCREATE(COpenGLTextureView, CView)

BEGIN_MESSAGE_MAP(COpenGLTextureView, CView)
	//{{AFX_MSG_MAP(COpenGLTextureView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenGLTextureView construction/destruction

COpenGLTextureView::COpenGLTextureView()
{
	// TODO: add construction code here

}

COpenGLTextureView::~COpenGLTextureView()
{
}

BOOL COpenGLTextureView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
//	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;//剪掉子窗口和兄弟窗口
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// COpenGLTextureView drawing

void COpenGLTextureView::OnDraw(CDC* pDC)
{
	COpenGLTextureDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

}
void COpenGLTextureView::DrawGLSquare(float x1,float y1,float x2,float y2) 
{ //开始显示矩形,注意顶点的顺序
    glBegin(GL_QUADS);
        //分别设置矩形的4个顶点,注意要先设定材质坐标
        glTexCoord2f(0,0);
        glVertex3f(x1,y1,0); //所有顶点的Z值为0
        glTexCoord2f(0,1);
        glVertex3f(x1,y2,0); 
        glTexCoord2f(1,1);
        glVertex3f(x2,y2,0); 
        glTexCoord2f(1,0);
        glVertex3f(x2,y1,0); 
    glEnd();

}

/////////////////////////////////////////////////////////////////////////////
// COpenGLTextureView printing

BOOL COpenGLTextureView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COpenGLTextureView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COpenGLTextureView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// COpenGLTextureView diagnostics

#ifdef _DEBUG
void COpenGLTextureView::AssertValid() const
{
	CView::AssertValid();
}

void COpenGLTextureView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpenGLTextureDoc* COpenGLTextureView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpenGLTextureDoc)));
	return (COpenGLTextureDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpenGLTextureView message handlers

int COpenGLTextureView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
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

	SetTimer(1,200,NULL);//设置定时器

	return 0;
}

void COpenGLTextureView::OnDestroy() 
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

void COpenGLTextureView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);	
	// TODO: Add your message handler code here
	if(m_hglrc)
		wglMakeCurrent(m_pDC->GetSafeHdc(), m_hglrc);//获取当前绘图场景
	else
		return;
	//设定视区
  glViewport(0, 0, cx,cy);
	//设定透视方式
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(220.0, 1.0*(GLfloat)cx/(GLfloat)cy, 1.0, 110.0);
  glMatrixMode(GL_MODELVIEW);
//	初始化模型变换矩阵为单位矩阵
	glLoadIdentity();	
}

BOOL COpenGLTextureView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return true;
	//return CView::OnEraseBkgnd(pDC);
}


void COpenGLTextureView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//每桢改变颜色,使半透明效果更明显
 	int i,j;
    GLubyte color1,alpha;
    //初始化材质
    for(i=0;i<IMAGEWIDTH;i++)
        for(j=0;j<IMAGEHEIGHT;j++)
        {
            color1 = (i&0x4)?255:0;
            alpha = (j&0x4)?255:128;
           // 颜色是蓝白相间
            Image[i][j][0] = color1;
            Image[i][j][1] = color1;
            Image[i][j][2] = 255;
           // 透明和半透明相间
            Image[i][j][3] = (GLubyte) alpha;
        }
        //设置材质
        //材质包括RGBA四个分量,没有边界
    glTexImage2D(GL_TEXTURE_2D, 0, 4,IMAGEWIDTH,IMAGEHEIGHT, 0,
            GL_RGBA, GL_UNSIGNED_BYTE, &Image[0][0][0]);
    //超过材质边界就扩展边界颜色
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    //过滤参数
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    //材质中有半透明颜色,需要启动alpha混合,
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	static float color = 0.0f;
	color+=0.01f;
  if(color>1.0f)color=0.0f;
//设置清除屏幕的颜色，并清除屏幕和深度缓冲
  glClearColor(0.0f,0.0f,0.0f,0.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//设置成模型矩阵模式
  glMatrixMode(GL_MODELVIEW);
//载入单位化矩阵
  glLoadIdentity();
//设定摄像机位置和方向
  gluLookAt (0.0, 0.0, 1.02, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); 
//显示一个无材质的矩形
  glDisable(GL_TEXTURE_2D);
  glColor3f(color,0.5f,color);
  glRectf(-1.5f,-1.5f,1.5f,1.5f);
//显示一个有材质的茶壶
  glEnable(GL_TEXTURE_2D);
  gluLookAt(-0.4, 1.0, 4, 0, 0, 0, 0, -1, 0);	 						//设置观察点位置; 
  glColor3f(1.0f,1.0f,1.0f); //注意这里的颜色对于材质的颜色是有影响的
  auxSolidTeapot(4.0);
//等待现有的OPENGL命令执行完成
  glFlush();
//交换前后缓冲区
  auxSwapBuffers();
  //绘制前景
glDrawBuffer(GL_FRONT);
CView::OnTimer(nIDEvent);
}
