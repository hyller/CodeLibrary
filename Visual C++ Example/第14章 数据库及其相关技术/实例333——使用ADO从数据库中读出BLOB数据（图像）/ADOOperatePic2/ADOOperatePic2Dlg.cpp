// ADOOperatePic2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ADOOperatePic2.h"
#include "ADOOperatePic2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
extern CADOOperatePic2App theApp;
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
// CADOOperatePic2Dlg dialog

CADOOperatePic2Dlg::CADOOperatePic2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CADOOperatePic2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CADOOperatePic2Dlg)
	m_strNo = _T("");
	m_strName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hPhotoBitmap = NULL;
	m_pBMPBuffer = NULL;
}

void CADOOperatePic2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADOOperatePic2Dlg)
	DDX_Control(pDX, IDC_PIC, m_ctlPic);
	DDX_Text(pDX, IDC_EDIT1, m_strNo);
	DDX_Text(pDX, IDC_EDIT2, m_strName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CADOOperatePic2Dlg, CDialog)
	//{{AFX_MSG_MAP(CADOOperatePic2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_PREV, OnPrev)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADOOperatePic2Dlg message handlers

BOOL CADOOperatePic2Dlg::OnInitDialog()
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

	m_pRecordset.CreateInstance("ADODB.Recordset");//记录集对象
	HRESULT hr = m_pRecordset->Open("SELECT * FROM photo",_variant_t((IDispatch *)theApp.m_pConnection,true),adOpenDynamic,adLockPessimistic,adCmdText);
    if(SUCCEEDED(hr))
	{
		ReadRecord();//读取记录集的第一条记录并显示
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CADOOperatePic2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CADOOperatePic2Dlg::OnPaint() 
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
HCURSOR CADOOperatePic2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



///////////将内存中的BMP文件内容转换到HBITMAP///////
HBITMAP CADOOperatePic2Dlg::BufferToHBITMAP()
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

void CADOOperatePic2Dlg::OnRemove() //删除记录
{
	// TODO: Add your control notification handler code here
	m_pRecordset->Delete(adAffectCurrent);//删除当前记录
	m_pRecordset->MoveFirst();//移动到第一条
	ReadRecord();
	Invalidate();//更新显示		
}

void CADOOperatePic2Dlg::ReadRecord()
{
	if(m_hPhotoBitmap)//清除分配的对象
	{
		DeleteObject(m_hPhotoBitmap);
		m_hPhotoBitmap = NULL;
	}
	if(m_pBMPBuffer)
	{
		delete m_pBMPBuffer;
		m_pBMPBuffer = NULL;
	}
	if(m_pRecordset->adoEOF||m_pRecordset->BOF) //记录集中没有记录
		{
			m_strName.Empty();
			m_strNo.Empty();
			UpdateData(FALSE);
			return;
		}
	long lDataSize = m_pRecordset->GetFields()->GetItem("photo")->ActualSize;
	if(lDataSize > 0)
	{
		_variant_t	varBLOB;
		varBLOB = m_pRecordset->GetFields()->GetItem("photo")->GetChunk(lDataSize);
		if(varBLOB.vt == (VT_ARRAY | VT_UI1))
		{
			if(m_pBMPBuffer = new char[lDataSize+1])				///重新分配必要的存储空间
			{	
				char *pBuf = NULL;
				SafeArrayAccessData(varBLOB.parray,(void **)&pBuf);
				memcpy(m_pBMPBuffer,pBuf,lDataSize);				///复制数据到缓冲区m_pBMPBuffer
				SafeArrayUnaccessData (varBLOB.parray);
				m_nFileLen = lDataSize;
				m_hPhotoBitmap = BufferToHBITMAP();					///生成BITMAP对象
			}
		}
	}
	m_strName = m_pRecordset->GetCollect("name").bstrVal;
	m_strNo = m_pRecordset->GetCollect("id").bstrVal;
	UpdateData(FALSE);
}

void CADOOperatePic2Dlg::OnNext() 
{
	// TODO: Add your control notification handler code here
	m_pRecordset->MoveNext();//移动到下一条
	if(m_pRecordset->adoEOF)//如果是最后一条
		m_pRecordset->MoveLast();
	ReadRecord();
	Invalidate();//更新显示	
	
}

void CADOOperatePic2Dlg::OnPrev() 
{
	// TODO: Add your control notification handler code here
	m_pRecordset->MovePrevious();//移动记录集到上一条
	if(m_pRecordset->BOF)//如果是第一条
		m_pRecordset->MoveFirst();
	ReadRecord();
	Invalidate();	//更新显示		
}
