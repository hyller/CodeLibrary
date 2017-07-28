// CursorMouseDemoDoc.h : interface of the CCursorMouseDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CURSORMOUSEDEMODOC_H__DA570F2C_9AD7_4493_B4A8_25ADB488C789__INCLUDED_)
#define AFX_CURSORMOUSEDEMODOC_H__DA570F2C_9AD7_4493_B4A8_25ADB488C789__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCursorMouseDemoDoc : public CDocument
{
protected: // create from serialization only
	CCursorMouseDemoDoc();
	DECLARE_DYNCREATE(CCursorMouseDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCursorMouseDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCursorMouseDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCursorMouseDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CURSORMOUSEDEMODOC_H__DA570F2C_9AD7_4493_B4A8_25ADB488C789__INCLUDED_)
