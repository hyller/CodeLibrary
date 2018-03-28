// MultiDocDemoDoc.h : interface of the CMultiDocDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MultiDocDemoDOC_H__7F238541_21CF_461E_8CD8_A6B938637E2B__INCLUDED_)
#define AFX_MultiDocDemoDOC_H__7F238541_21CF_461E_8CD8_A6B938637E2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMultiDocDemoDoc : public CDocument
{
protected: // create from serialization only
	CMultiDocDemoDoc();
	DECLARE_DYNCREATE(CMultiDocDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiDocDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	LOGFONT m_lf;//字体结构
	CString m_str;//输出的文字
	virtual ~CMultiDocDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMultiDocDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MultiDocDemoDOC_H__7F238541_21CF_461E_8CD8_A6B938637E2B__INCLUDED_)
