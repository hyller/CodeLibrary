// DySplitterWndDoc.h : interface of the CDySplitterWndDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DYSPLITTERWNDDOC_H__533568E9_09C4_4261_A689_54243EC7D3DE__INCLUDED_)
#define AFX_DYSPLITTERWNDDOC_H__533568E9_09C4_4261_A689_54243EC7D3DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDySplitterWndDoc : public CDocument
{
protected: // create from serialization only
	CDySplitterWndDoc();
	DECLARE_DYNCREATE(CDySplitterWndDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDySplitterWndDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDySplitterWndDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDySplitterWndDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYSPLITTERWNDDOC_H__533568E9_09C4_4261_A689_54243EC7D3DE__INCLUDED_)
