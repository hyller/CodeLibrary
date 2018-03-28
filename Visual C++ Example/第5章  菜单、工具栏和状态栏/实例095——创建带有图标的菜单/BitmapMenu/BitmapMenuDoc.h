// BitmapMenuDoc.h : interface of the CBitmapMenuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BITMAPMENUDOC_H__C2C38891_B1A7_49BC_8C8C_804D78E3165B__INCLUDED_)
#define AFX_BITMAPMENUDOC_H__C2C38891_B1A7_49BC_8C8C_804D78E3165B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBitmapMenuDoc : public CDocument
{
protected: // create from serialization only
	CBitmapMenuDoc();
	DECLARE_DYNCREATE(CBitmapMenuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapMenuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBitmapMenuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBitmapMenuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPMENUDOC_H__C2C38891_B1A7_49BC_8C8C_804D78E3165B__INCLUDED_)
