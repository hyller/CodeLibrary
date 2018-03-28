// BrushDemoDoc.h : interface of the CBrushDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BRUSHDEMODOC_H__0F58B384_34E5_465D_B078_DC0C9506AE4F__INCLUDED_)
#define AFX_BRUSHDEMODOC_H__0F58B384_34E5_465D_B078_DC0C9506AE4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBrushDemoDoc : public CDocument
{
protected: // create from serialization only
	CBrushDemoDoc();
	DECLARE_DYNCREATE(CBrushDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrushDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBrushDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBrushDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BRUSHDEMODOC_H__0F58B384_34E5_465D_B078_DC0C9506AE4F__INCLUDED_)
