// BitmapDemoDoc.h : interface of the CBitmapDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BITMAPDEMODOC_H__B6FF64C2_5721_409B_8B59_786FD0DB2A2E__INCLUDED_)
#define AFX_BITMAPDEMODOC_H__B6FF64C2_5721_409B_8B59_786FD0DB2A2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBitmapDemoDoc : public CDocument
{
protected: // create from serialization only
	CBitmapDemoDoc();
	DECLARE_DYNCREATE(CBitmapDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBitmapDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBitmapDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPDEMODOC_H__B6FF64C2_5721_409B_8B59_786FD0DB2A2E__INCLUDED_)
