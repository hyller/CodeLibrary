// RadarDataShowDoc.cpp : implementation of the CRadarDataShowDoc class
//

#include "stdafx.h"
#include "RadarDataShow.h"

#include "RadarDataShowDoc.h"
#include "FilePara.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRadarDataShowDoc

IMPLEMENT_DYNCREATE(CRadarDataShowDoc, CDocument)

BEGIN_MESSAGE_MAP(CRadarDataShowDoc, CDocument)
	//{{AFX_MSG_MAP(CRadarDataShowDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRadarDataShowDoc construction/destruction

CRadarDataShowDoc::CRadarDataShowDoc()
{
	// TODO: add one-time construction code here
	Window=20;

}

CRadarDataShowDoc::~CRadarDataShowDoc()
{
	if(lpBufPtr_Raw_data != NULL)
	{
		delete[] lpBufPtr_Raw_data;
		lpBufPtr_Raw_data = NULL;
	}
	if(lpBufPtr_Ascan!= NULL)
	{
		delete[] lpBufPtr_Ascan;
		lpBufPtr_Ascan = NULL;
	}

}

BOOL CRadarDataShowDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRadarDataShowDoc serialization

void CRadarDataShowDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRadarDataShowDoc diagnostics

#ifdef _DEBUG
void CRadarDataShowDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRadarDataShowDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRadarDataShowDoc commands

BOOL CRadarDataShowDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
// TODO: Add your specialized creation code here
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
    CFile MyFile;
	CFileException fe;
    int i;//剖面数据
	// 打开文件
	if (!MyFile.Open(lpszPathName, CFile::modeRead | CFile::shareDenyWrite, &fe))
	{
		// 打开文件失败
		ReportSaveLoadException(lpszPathName, &fe,FALSE, AFX_IDP_FAILED_TO_OPEN_DOC);
		return FALSE;
	}
	DeleteContents();
	DWORD dwSize = GetFileSize ((LPVOID)MyFile.m_hFile, NULL);
	if(dwSize != 0xFFFFFFFF)
	{ 
		CString PathName = lpszPathName;
		filename=PathName;
		int dot_p = PathName.Find('.');
		CString file_e = PathName.Right(PathName.GetLength()-dot_p-1); //获取文件的扩展名
		if(file_e == "rde")
			{
			/* 读取文件头信息*/
			BYTE m_buffer[1024];//贮存头文件信息1024个字节
			MyFile.Read(m_buffer,1024);
			unsigned long data_bits;//数据的位数  12
			memcpy(&data_bits,m_buffer+12,sizeof(unsigned long));
			unsigned long zero_shift;//数据的零偏  2048
			memcpy(&zero_shift,m_buffer+16,sizeof(unsigned long));
			unsigned long account_channels;//总通道数
			memcpy(&account_channels,m_buffer+24,sizeof(unsigned long));
			unsigned long active_channel;//当前通道序号
			memcpy(&active_channel,m_buffer+28,sizeof(unsigned long));
			unsigned long window_time;//时窗宽度
			memcpy(&window_time,m_buffer+40,sizeof(unsigned long));
			unsigned long sample_points;//每个scan的采样点数
			memcpy(&sample_points,m_buffer+44,sizeof(unsigned long));
			Window=window_time;
			int sample_num;//测量的点数
			sample_num=(int)((dwSize-1024)/(2*sample_points));//每个记录数据占两个字节
			data_head.rh_data = 1024;
			data_head.rh_nsamp =(int) sample_points;
			data_head.rh_bits = (int)data_bits;
			data_head.rh_zero = (int)zero_shift;
			int kk=20;
			data_head.rh_slice = sample_num/kk;
			CFilePara filepara;
			filepara.m_Samplepole=data_head.rh_slice;
			filepara.m_Samplenum=data_head.rh_nsamp;
			filepara.m_Sampleslice=1;//1个测量剖面
			filepara.m_Timewindow=(int) window_time;
			if(filepara.DoModal() != IDOK)//弹出参数对话框
			{
				return FALSE;// 返回
			}
			_int16	*lpBufPtr;
			lpBufPtr = new _int16[dwSize/2];
			MyFile.Seek(1024,CFile::begin); //去除头文件
			MyFile.Read(lpBufPtr,dwSize);//读取文件数据	
			MyFile.Close();	//关闭文件
			for(int u=0;u<data_head.rh_slice*data_head.rh_nsamp*kk;u++)
			{
				if(lpBufPtr[u]>2048)
					lpBufPtr[u]= lpBufPtr[u]-4096;//变为-2048~0范围
				else
					lpBufPtr[u]= lpBufPtr[u];	
				lpBufPtr[u]=lpBufPtr[u]*2;
			}
			if(filepara.m_Radio1==1&&filepara.m_Radio3==0)
				{
					data_head.rh_slice=filepara.m_Poleend-filepara.m_Polebegin+1;
					lpBufPtr_Raw_data=new double[data_head.rh_slice*data_head.rh_nsamp];
					int p,q,t;
					for(p=0;p<data_head.rh_slice;p++)
					{
						for(q=0;q<data_head.rh_nsamp;q++)
					{
						int s=0;
						for (t=0;t<kk;t++)
						{
							s=s+lpBufPtr[(t+(p+filepara.m_Polebegin)*kk)*data_head.rh_nsamp+q];
						}
						s=s/kk;
		
						  lpBufPtr_Raw_data[p*data_head.rh_nsamp+q] = (double)(s/2048.0);
					}

				}
					delete[] lpBufPtr;

				}
				if(filepara.m_Radio1==1&&filepara.m_Radio3==1)
				{

				lpBufPtr_Raw_data=new double[data_head.rh_slice*data_head.rh_nsamp];
				int p,q,t;
				for(p=0;p<data_head.rh_slice;p++)
				{
					for(q=0;q<data_head.rh_nsamp;q++)
					{
						int s=0;
						for (t=0;t<kk;t++)
						{
							s=s+lpBufPtr[(t+p*kk)*data_head.rh_nsamp+q];
						}
						s=s/kk;
						
						  lpBufPtr_Raw_data[p*data_head.rh_nsamp+q] = (double)(s/2048.0);
					}

				}
					delete[] lpBufPtr;
				}

				lpBufPtr_Ascan=new unsigned char[data_head.rh_nsamp]; 
				for(i=0;i<data_head.rh_nsamp;i++)
				{
					lpBufPtr_Ascan[i]= (unsigned char)((lpBufPtr_Raw_data[data_head.rh_nsamp*(int)(data_head.rh_slice/2)+i]+1)*255/6);//
				}
			}

			else
			{
				AfxMessageBox ("文件类型不正确!",MB_OK);
				return FALSE;
			}
		}		 
	return TRUE;
}

BOOL CRadarDataShowDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	return true;

}
