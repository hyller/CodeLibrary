// SortDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SortDemo.h"
#include "SortDemoDlg.h"
#include "Sort.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

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
// CSortDemoDlg dialog

CSortDemoDlg::CSortDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSortDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSortDemoDlg)
	m_nSize = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSortDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSortDemoDlg)
	DDX_Text(pDX, IDC_NUM, m_nSize);
	DDV_MinMaxInt(pDX, m_nSize, 0, 100);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSortDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CSortDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_STARTSORT, OnStartsort)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSortDemoDlg message handlers

BOOL CSortDemoDlg::OnInitDialog()
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
	CComboBox* pTypeList = (CComboBox*)GetDlgItem(IDC_TYPE);
	pTypeList->SetCurSel(0);

	CComboBox* pMethodList = (CComboBox*)GetDlgItem(IDC_SORTMETHOD);
	pMethodList->SetCurSel(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSortDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSortDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSortDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSortDemoDlg::OnStartsort() 
{
	//把排序结果编辑框置空
	GetDlgItem(IDC_RESULT)->SetWindowText("");
	//把排序按钮置灰
	GetDlgItem(IDC_STARTSORT)->EnableWindow(FALSE);

	//从对话框中获得相应数据
	UpdateData(TRUE);
	
	//取得用户输入的排序数据
	CString strElements;
	GetDlgItem(IDC_ELEMENT)->GetWindowText(strElements);

	//检查数据是否合法
	if (strElements.IsEmpty() || m_nSize <= 0)
	{
		AfxMessageBox("请输入必要的数据");
		//置排序按钮有效
		GetDlgItem(IDC_STARTSORT)->EnableWindow(TRUE);

		return;
	}

	//取得要排序的元素类型
	int nType ;
	CComboBox* pTypeList = (CComboBox*)GetDlgItem(IDC_TYPE);
	nType = pTypeList->GetCurSel();

	//判断使用哪一种排序算法
	int nMethod;
	CComboBox* pMethodList = (CComboBox*)GetDlgItem(IDC_SORTMETHOD);
	nMethod = pMethodList->GetCurSel();

	//取出各个子串
	CStringArray list;
	GetElements(strElements,m_nSize,list);

	CString strResult;          //保存最后的排序结果

	switch(nType)
	{
	case 0:                    //long
		{
			CSort<long> Sort(m_nSize);
			long* lList = new long[m_nSize];
			if (lList == NULL)
			{
				//置排序按钮有效
				GetDlgItem(IDC_STARTSORT)->EnableWindow(TRUE);
				AfxMessageBox("分配内存失败");
				return;
			}

			//取得各个数据
			for (int i=0;i<list.GetSize();i++)
			{
				lList[i] = atol(list.GetAt(i));
			}
			
			//排序
			switch(nMethod)
			{
			case 0:
				Sort.Bubble(lList);
				break;
			case 1:
				Sort.Insertion(lList);
				break;
			case 2:
				Sort.Quick(lList,0,m_nSize-1);
				break;
			case 3:
				Sort.Selection(lList);
				break;
			}

			//存储最后的结果
			CString strTemp;
			for (i=0;i<m_nSize;i++)
			{
				strTemp.Format("%d",lList[i]);
				strResult += strTemp;
				strResult += ' ';
			}

			//释放内存
			delete[] lList;

		}
		break;
	case 1:                    //double
		{
			CSort<double> Sort(m_nSize);
			double* dList = new double[m_nSize];
			if (dList == NULL)
			{
				//置排序按钮有效
				GetDlgItem(IDC_STARTSORT)->EnableWindow(TRUE);
				AfxMessageBox("分配内存失败");
				return;
			}
			
			//取得各个数据
			for (int i=0;i<list.GetSize();i++)
			{
				dList[i] = atof(list.GetAt(i));
			}

			//排序
			switch(nMethod)
			{
			case 0:
				Sort.Bubble(dList);
				break;
			case 1:
				Sort.Insertion(dList);
				break;
			case 2:
				Sort.Quick(dList,0,m_nSize-1);
				break;
			case 3:
				Sort.Selection(dList);
				break;
			}

			//存储最后的结果
			CString strTemp;
			for (i=0;i<m_nSize;i++)
			{
				strTemp.Format("%.3f",dList[i]);
				strResult += strTemp;
				strResult += ' ';
			}

			//释放内存
			delete[] dList;
		}
		break;

	case 2:                    //integer
		{
			CSort<int> Sort(m_nSize);
			int* iList = new int[m_nSize];
			if (iList == NULL)
			{
				//置排序按钮有效
				GetDlgItem(IDC_STARTSORT)->EnableWindow(TRUE);
				AfxMessageBox("分配内存失败");
				return;
			}

			for (int i=0;i<list.GetSize();i++)
			{
				iList[i] = atoi(list.GetAt(i));
			}

			switch(nMethod)
			{
			case 0:
				Sort.Bubble(iList);
				break;
			case 1:
				Sort.Insertion(iList);
				break;
			case 2:
				Sort.Quick(iList,0,m_nSize-1);
				break;
			case 3:
				Sort.Selection(iList);
				break;
			}	
			
			//存储最后的结果
			CString strTemp;
			for (i=0;i<m_nSize;i++)
			{
				strTemp.Format("%d",iList[i]);
				strResult += strTemp;
				strResult += ' ';
			}

			//释放内存
			delete[] iList;
		}
		break;
	}

	//设置最后的显示结果
	GetDlgItem(IDC_RESULT)->SetWindowText(strResult);

	//置排序按钮有效
	GetDlgItem(IDC_STARTSORT)->EnableWindow(TRUE);
}

/**********************************************************************
函数名：GetElements
用途：  从空格分开的各个数字串中取出各个数字子串
参数：  str[in],要分析的以空格分开的数字串，nSize[in],元素的数目
		list[out],用于存放各个子串
返回值：
**********************************************************************/
void CSortDemoDlg::GetElements(CString str,int nSize,CStringArray& list)
{
	//先去掉左右的空格
	str.TrimLeft();
	str.TrimRight();

	//清空列表元素
	list.RemoveAll();
	list.SetSize(nSize);
	//先把数组元素置'0'值
	//如果用户输入的元素数目小于它设定的数组尺寸
	//则剩余的元素默认会被置成0
	for (int i=0;i<nSize;i++)
	{
		list.SetAt(i,'0');
	}

	int nIndex;
	int nTotalNum =0;
	CString strTemp;
	
	while(str.GetLength()>0 && nTotalNum<m_nSize)
	{
		nIndex = str.Find(' ');    //查找空格
		if (nIndex != -1)
		{
			strTemp = str.Left(nIndex);  
			list.SetAt(nTotalNum,strTemp);
			str = str.Right(str.GetLength()-strTemp.GetLength());
			
			//如果左端有空格则删掉
			str.TrimLeft();		

			nTotalNum++;
		}
		else
		{
			list.SetAt(nTotalNum,str);       //最后一个子串
			str.Empty();

			nTotalNum++;
		}
	}	

}
