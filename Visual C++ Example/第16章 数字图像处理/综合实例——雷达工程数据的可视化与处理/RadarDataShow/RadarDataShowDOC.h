// RadarDataShowDoc.h : interface of the CRadarDataShowDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RadarDataShowDOC_H__8C80D987_5A2E_4016_82D2_AEC4F0520EAD__INCLUDED_)
#define AFX_RadarDataShowDOC_H__8C80D987_5A2E_4016_82D2_AEC4F0520EAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct stDATA_HEAD {
       unsigned short rh_data;  //数据位置偏移
       unsigned short rh_nsamp; //每道采样点数
       unsigned short rh_bits;  //数据位数
       unsigned short rh_zero;  //数据零偏
	   unsigned short rh_slice;  //剖面的道数
};
class CRadarDataShowDoc : public CDocument
{
protected: // create from serialization only
	CRadarDataShowDoc();
	DECLARE_DYNCREATE(CRadarDataShowDoc)

// Attributes
public:

// Operations
public:

	double max_Raw;
	double min_Raw;
    double *lpBufPtr_Raw_data;
	unsigned char *lpBufPtr_Ascan;//存储Ascan数据
	int Window;
	//unsigned char *lpBufPtr_bmp;
	stDATA_HEAD   data_head;//the file header
	CString filename;//存贮打开文件的文件名字
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRadarDataShowDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRadarDataShowDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:



// Generated message map functions
protected:
	//{{AFX_MSG(CRadarDataShowDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RadarDataShowDOC_H__8C80D987_5A2E_4016_82D2_AEC4F0520EAD__INCLUDED_)
