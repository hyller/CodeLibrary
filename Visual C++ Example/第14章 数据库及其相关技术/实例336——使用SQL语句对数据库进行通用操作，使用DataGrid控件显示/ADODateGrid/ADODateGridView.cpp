// ADODateGridView.cpp : implementation of the CADODateGridView class
//

#include "stdafx.h"
#include "ADODateGrid.h"
#include "column.h"
#include "columns.h"
#include "ADODateGridDoc.h"
#include "ADODateGridView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CADODateGridView

IMPLEMENT_DYNCREATE(CADODateGridView, CFormView)

BEGIN_MESSAGE_MAP(CADODateGridView, CFormView)
	//{{AFX_MSG_MAP(CADODateGridView)
	ON_BN_CLICKED(IDC_SOURCE, OnSource)
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_EXECUTE, OnExecute)
	ON_BN_CLICKED(IDC_DISCONNECT, OnDisconnect)
	ON_BN_CLICKED(IDC_QUIT, OnQuit)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADODateGridView construction/destruction

CADODateGridView::CADODateGridView()
	: CFormView(CADODateGridView::IDD)
{
	//{{AFX_DATA_INIT(CADODateGridView)
	m_strConnection = _T("");
	m_strSQL = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	isDesc=true;

}

CADODateGridView::~CADODateGridView()
{
}

void CADODateGridView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADODateGridView)
	DDX_Control(pDX, IDC_LIST1, m_ctlList);
	DDX_Text(pDX, IDC_EDIT1, m_strConnection);
	DDX_Text(pDX, IDC_EDIT2, m_strSQL);
	DDX_Control(pDX, IDC_DATAGRID1, m_ctlDataGrid);
	//}}AFX_DATA_MAP
}

BOOL CADODateGridView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CADODateGridView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CADODateGridView printing

BOOL CADODateGridView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CADODateGridView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CADODateGridView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CADODateGridView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CADODateGridView diagnostics

#ifdef _DEBUG
void CADODateGridView::AssertValid() const
{
	CFormView::AssertValid();
}

void CADODateGridView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CADODateGridDoc* CADODateGridView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CADODateGridDoc)));
	return (CADODateGridDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CADODateGridView message handlers

void CADODateGridView::OnSource() //选择数据源
{
	// TODO: Add your control notification handler code here
	HRESULT hr;
	IDataSourceLocatorPtr m_slocator=NULL;//DataSourceLocator对象指针
	_ConnectionPtr m_Conn=NULL;
	::CoInitialize(NULL); 										//初始化COM环境
	hr=m_slocator.CreateInstance(_uuidof(DataLinks));//创建实例
	m_Conn=m_slocator->PromptNew();//弹出连接数据源对话框
	if(m_Conn!=NULL)
	{
		m_strConnection.Format("%s",(char*)m_Conn->ConnectionString);
		UpdateData(false);
	}	
}

void CADODateGridView::OnConnect() //连接数据源
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	try
	{
		m_Connection.CreateInstance("ADODB.Connection");			//创建Connection对象
		m_Connection->Open(_bstr_t(m_strConnection.GetBuffer(0)),"","",-1);
	}
	catch(_com_error e)										//捕捉异常 
	{ 
		CString errormessage; 
		errormessage.Format("连接数据库失败!\r\n错误信息:%s",e.ErrorMessage()); 
		AfxMessageBox(errormessage);						//显示错误信息 
		return;
	}  
	m_ctlList.ResetContent();//清空列表框
	//下面实现获取数据源中包含的所有表的表名，并添加到列表框中
	_bstr_t tablenames;
	CString  str;
	try
	{
		m_Recordset.CreateInstance(_uuidof(Recordset));//创建记录集实例
		//以只读的方式打开结果集，获得表名
		m_Recordset=m_Connection->OpenSchema(adSchemaTables,vtMissing,vtMissing);
		while(!m_Recordset->adoEOF)
		{
			tablenames=m_Recordset->GetCollect("TABLE_NAME");//获取表项的名字
			str=(char*)tablenames;
			if(str.Left(4)!="MSys")//如果是表名
				m_ctlList.AddString(str);//添加到列表框
			m_Recordset->MoveNext();
		}
	}
	catch(_com_error e)										//捕捉异常 
	{ 
		CString errormessage; 
		errormessage.Format("操作失败!\r\n错误信息:%s",e.ErrorMessage()); 
		AfxMessageBox(errormessage);						//显示错误信息 
		return;
	}  
	m_Recordset=NULL;
}



void CADODateGridView::OnExecute() //执行SQL语句
{
	// TODO: Add your control notification handler code here
	try
	{
		m_Recordset.CreateInstance(_uuidof(Recordset));//创建记录集实例
		UpdateData(true);
		m_Recordset->CursorLocation=adUseClient;//设定游标服务
		m_Recordset->Open(m_strSQL.GetBuffer(0),m_Connection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error e)										//捕捉异常 
	{ 
		CString errormessage; 
		errormessage.Format("操作失败!\r\n错误信息:%s",e.ErrorMessage()); 
		AfxMessageBox(errormessage);						//显示错误信息 
		return;
	}  
	//将执行SQL语句得到的结果集在DataGrid控件中显示
	m_ctlDataGrid.SetRefDataSource((LPUNKNOWN)m_Recordset);
	m_ctlDataGrid.Refresh();//刷新控件
	UpdateData(false);
	m_Recordset=NULL;
}

void CADODateGridView::OnDisconnect() //断开连接
{
	// TODO: Add your control notification handler code here
	try
	{
		m_Connection->Close();//断开连接
		m_Connection=NULL;

	}
	catch(_com_error e)										//捕捉异常 
	{ 
		CString errormessage; 
		errormessage.Format("操作失败!\r\n错误信息:%s",e.ErrorMessage()); 
		AfxMessageBox(errormessage);						//显示错误信息 
		return;
	}  
	//使得各控件恢复到初始状态
	m_ctlList.ResetContent();//清空列表框
	m_ctlDataGrid.SetRefDataSource(NULL);//清空DataGrid
	m_ctlDataGrid.ClearFields();
	m_ctlDataGrid.Refresh();
	m_strSQL="";
	UpdateData(false);	
}

void CADODateGridView::OnQuit() //退出窗口
{
	// TODO: Add your control notification handler code here
	if(m_Recordset!=NULL)
		m_Recordset->Close();//关闭记录集
	if(m_Connection!=NULL)
		m_Connection->Close();//断开连接
	PostMessage(WM_QUIT);//退出窗口
}

void CADODateGridView::OnSelchangeList1() 
{
	// TODO: Add your control notification handler code here
	int index=m_ctlList.GetCurSel();
	m_ctlList.GetText(index,m_strTable);//获取列表框中选中的表名
	m_strSQL="Select * from ["+m_strTable+"]";
	UpdateData(false);
	OnExecute();//执行SQL语句
}

BEGIN_EVENTSINK_MAP(CADODateGridView, CFormView)
    //{{AFX_EVENTSINK_MAP(CADODateGridView)
	ON_EVENT(CADODateGridView, IDC_DATAGRID1, 216 /* HeadClick */, OnHeadClickDatagrid1, VTS_I2)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CADODateGridView::OnHeadClickDatagrid1(short ColIndex) 
{
	// TODO: Add your control notification handler code here
	CColumns cols=m_ctlDataGrid.GetColumns();//获取控件的各列
	VARIANT index;
	index.intVal=ColIndex;
	index.vt=VT_I4;//整型
	CColumn col=cols.GetItem(index);//得到单击的列
	CString strCol;//列名
	strCol=col.GetCaption();
	CString strSQL;
	int len;//记录SQL语句的长度
	if(m_Connection!=NULL)
	{
		if(strCol.GetLength()!=0)
		{
			len=m_strSQL.GetLength();
			strSQL="Order by ["+strCol+"]";
			if(isDesc)//降序排列
			{
				strSQL+="desc";
				isDesc=false;
			}
			else//升序排列
				isDesc=true;
		}
		m_strSQL+=strSQL;
		UpdateData(false);
		OnExecute();//执行SQL语句
		m_strSQL.Delete(len,strSQL.GetLength());//恢复排序前的SQL语句
	}
}
