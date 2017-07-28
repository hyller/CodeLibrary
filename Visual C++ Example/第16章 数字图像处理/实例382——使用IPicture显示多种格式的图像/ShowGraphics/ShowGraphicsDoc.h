// ShowGraphicsDoc.h : interface of the CShowGraphicsDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWGRAPHICSDOC_H__90976274_0A68_42F0_8197_216545CD722D__INCLUDED_)
#define AFX_SHOWGRAPHICSDOC_H__90976274_0A68_42F0_8197_216545CD722D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowGraphicsDoc : public CDocument
{
protected: // create from serialization only
	CShowGraphicsDoc();
	DECLARE_DYNCREATE(CShowGraphicsDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowGraphicsDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShowGraphicsDoc();
	DWORD GetGlobalSize();//获取文件数据大小
	HGLOBAL GetGlobalBuffer();//获取内存
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

private:
	DWORD	m_dwSize;//文件数据大小
	HGLOBAL	m_hBuf;//内存
// Generated message map functions
protected:
	//{{AFX_MSG(CShowGraphicsDoc)
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWGRAPHICSDOC_H__90976274_0A68_42F0_8197_216545CD722D__INCLUDED_)
