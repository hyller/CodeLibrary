// DyScrollRectDoc.h : interface of the CDyScrollRectDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DYSCROLLRECTDOC_H__E1BC136A_FA78_40D3_9572_7B67DAB426F6__INCLUDED_)
#define AFX_DYSCROLLRECTDOC_H__E1BC136A_FA78_40D3_9572_7B67DAB426F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDyScrollRectDoc : public CDocument
{
protected: // create from serialization only
	CDyScrollRectDoc();
	DECLARE_DYNCREATE(CDyScrollRectDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDyScrollRectDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDyScrollRectDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDyScrollRectDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYSCROLLRECTDOC_H__E1BC136A_FA78_40D3_9572_7B67DAB426F6__INCLUDED_)
