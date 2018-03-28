// HotKeyDemoDoc.h : interface of the CHotKeyDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HOTKEYDEMODOC_H__0E055F40_67DB_4B4F_AB40_25B89E0FCA65__INCLUDED_)
#define AFX_HOTKEYDEMODOC_H__0E055F40_67DB_4B4F_AB40_25B89E0FCA65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHotKeyDemoDoc : public CDocument
{
protected: // create from serialization only
	CHotKeyDemoDoc();
	DECLARE_DYNCREATE(CHotKeyDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHotKeyDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHotKeyDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHotKeyDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOTKEYDEMODOC_H__0E055F40_67DB_4B4F_AB40_25B89E0FCA65__INCLUDED_)
