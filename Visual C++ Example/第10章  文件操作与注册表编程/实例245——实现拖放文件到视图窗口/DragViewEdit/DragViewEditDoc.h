// DragViewEditDoc.h : interface of the CDragViewEditDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAGVIEWEDITDOC_H__11E3FC84_CD2A_4357_BF15_394688ABE097__INCLUDED_)
#define AFX_DRAGVIEWEDITDOC_H__11E3FC84_CD2A_4357_BF15_394688ABE097__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDragViewEditDoc : public CDocument
{
protected: // create from serialization only
	CDragViewEditDoc();
	DECLARE_DYNCREATE(CDragViewEditDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDragViewEditDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDragViewEditDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDragViewEditDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAGVIEWEDITDOC_H__11E3FC84_CD2A_4357_BF15_394688ABE097__INCLUDED_)
