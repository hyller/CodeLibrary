// DlgDocFrameDoc.h : interface of the CDlgDocFrameDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DlgDocFrameDOC_H__A838B3DC_1F94_4FB0_A979_B8B0470A3CAE__INCLUDED_)
#define AFX_DlgDocFrameDOC_H__A838B3DC_1F94_4FB0_A979_B8B0470A3CAE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAX_POINT 250

class CDlgDocFrameDoc : public CDocument
{
protected: // create from serialization only
	CDlgDocFrameDoc();
	DECLARE_DYNCREATE(CDlgDocFrameDoc)

// Attributes
public:
	double m_dbXdata[MAX_POINT];	//点的X坐标
	double m_dbYdata[MAX_POINT];	//点的Y坐标
	int  m_nPointCount;			//存放数组中点的实际数量


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDocFrameDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDlgDocFrameDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDlgDocFrameDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DlgDocFrameDOC_H__A838B3DC_1F94_4FB0_A979_B8B0470A3CAE__INCLUDED_)
