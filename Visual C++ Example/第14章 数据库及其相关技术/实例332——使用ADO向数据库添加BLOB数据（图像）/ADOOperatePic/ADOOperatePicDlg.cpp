// ADOOperatePicDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ADOOperatePic.h"
#include "ADOOperatePicDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
extern CADOOperatePicApp theApp;
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADOOperatePicDlg dialog

CADOOperatePicDlg::CADOOperatePicDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CADOOperatePicDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CADOOperatePicDlg)
	m_strNo = _T("");
	m_strName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hPhotoBitmap = NULL;
	m_pBMPBuffer = NULL;
}

void CADOOperatePicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADOOperatePicDlg)
	DDX_Control(pDX, IDC_PIC, m_ctlPic);
	DDX_Text(pDX, IDC_EDIT1, m_strNo);
	DDX_Text(pDX, IDC_EDIT2, m_strName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CADOOperatePicDlg, CDialog)
	//{{AFX_MSG_MAP(CADOOperatePicDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOADBMP, OnLoadbmp)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADOOperatePicDlg message handlers

BOOL CADOOperatePicDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CADOOperatePicDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CADOOperatePicDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		if(!m_hPhotoBitmap) 
			return;
		HBITMAP OldBitmap;
		CDC MemDC;
		MemDC.CreateCompatibleDC(&dc);
		CRect rect;
		m_ctlPic.GetWindowRect(&rect);//静态控件的区域
		ScreenToClient(rect);
		OldBitmap=(HBITMAP)MemDC.SelectObject(m_hPhotoBitmap);
		dc.BitBlt(rect.left,rect.top,rect.Width(),rect.Height(),&MemDC,0,0,SRCCOPY);
		MemDC.SelectObject(OldBitmap);
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CADOOperatePicDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CADOOperatePicDlg::OnLoadbmp() 
{
	// TODO: Add your control notification handler code here
	static char BASED_CODE szFilter[] = "BMP Files (*.bmp)|*.bmp|All Files (*.*)|*.*||";
	CFileDialog dlg(TRUE,"BMP",NULL,  OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter);
	if(dlg.DoModal() == IDOK)//打开文件对话框
	{
		CString pathname = dlg.GetPathName();//获取文件的路径名
		if(m_hPhotoBitmap)
		{
			DeleteObject(m_hPhotoBitmap);//清除HBITMAP对象
			m_hPhotoBitmap = NULL;
		}
		if(m_pBMPBuffer)
		{
			delete m_pBMPBuffer;
			m_pBMPBuffer = NULL;
		}
		CFile file;
		if( !file.Open(pathname, CFile::modeRead))//打开BMP文件
			return;
		m_nFileLen = file.GetLength();//文件长度
		m_pBMPBuffer = new char[m_nFileLen + 1];//分配内存
		if(!m_pBMPBuffer)//分配失败
			return;
		if(file.ReadHuge(m_pBMPBuffer,m_nFileLen) != m_nFileLen)//读取文件数据到缓存
			return;
		m_hPhotoBitmap = BufferToHBITMAP();//将内存中的BMP文件内容转换到HBITMAP
		Invalidate();
	}	
}

void CADOOperatePicDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_pBMPBuffer ==NULL||m_hPhotoBitmap == NULL||m_strName == "" || m_strNo == "")
	{
		AfxMessageBox("没有提供完整的用户信息。\r\n这些信息包括:编号、名称、图像");
		return;
	}
	m_pRecordset.CreateInstance("ADODB.Recordset");
	HRESULT hr = m_pRecordset->Open("SELECT * FROM photo",_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);
    if(!SUCCEEDED(hr))
	{
		AfxMessageBox("读取表中的数据失败!");
	}

	char			*pBuf = m_pBMPBuffer;
	VARIANT			varBLOB;
	SAFEARRAY		*psa;
    SAFEARRAYBOUND	rgsabound[1];
	m_pRecordset->AddNew();
	m_pRecordset->PutCollect("name",_variant_t(m_strName));
	m_pRecordset->PutCollect("id",_variant_t(m_strNo));
	if(pBuf)
	{    
		rgsabound[0].lLbound = 0;
		rgsabound[0].cElements = m_nFileLen;
		psa = SafeArrayCreate(VT_UI1, 1, rgsabound);
		for (long i = 0; i < (long)m_nFileLen; i++)
			SafeArrayPutElement (psa, &i, pBuf++);
		varBLOB.vt = VT_ARRAY | VT_UI1;
		varBLOB.parray = psa;
		m_pRecordset->GetFields()->GetItem("photo")->AppendChunk(varBLOB);
	}
	m_pRecordset->Update();
	AfxMessageBox("成功添加记录!");
	m_strName=m_strNo="";
	UpdateData(false);
}
///////////将内存中的BMP文件内容转换到HBITMAP///////
HBITMAP CADOOperatePicDlg::BufferToHBITMAP()
{
	HBITMAP				hBmp;
	LPSTR				hDIB,lpBuffer = m_pBMPBuffer;
	LPVOID				lpDIBBits;
	BITMAPFILEHEADER	bmfHeader;
	DWORD				bmfHeaderLen;

	bmfHeaderLen = sizeof(bmfHeader);
	strncpy((LPSTR)&bmfHeader,(LPSTR)lpBuffer,bmfHeaderLen);
	if (bmfHeader.bfType != (*(WORD*)"BM")) return NULL;
	hDIB = lpBuffer + bmfHeaderLen;
	BITMAPINFOHEADER &bmiHeader = *(LPBITMAPINFOHEADER)hDIB ;
	BITMAPINFO &bmInfo = *(LPBITMAPINFO)hDIB ;
	lpDIBBits=(lpBuffer)+((BITMAPFILEHEADER *)lpBuffer)->bfOffBits;
	CClientDC dc(this);
	hBmp = CreateDIBitmap(dc.m_hDC,&bmiHeader,CBM_INIT,lpDIBBits,&bmInfo,DIB_RGB_COLORS);
	return hBmp;
}
