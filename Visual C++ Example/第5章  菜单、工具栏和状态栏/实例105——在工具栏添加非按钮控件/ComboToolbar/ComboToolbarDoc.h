// ComboToolbarDoc.h : interface of the CComboToolbarDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMBOTOOLBARDOC_H__22E49257_7065_4664_B11D_BCE4F4AFFB36__INCLUDED_)
#define AFX_COMBOTOOLBARDOC_H__22E49257_7065_4664_B11D_BCE4F4AFFB36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CComboToolbarDoc : public CDocument
{
protected: // create from serialization only
	CComboToolbarDoc();
	DECLARE_DYNCREATE(CComboToolbarDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboToolbarDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CComboToolbarDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CComboToolbarDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOTOOLBARDOC_H__22E49257_7065_4664_B11D_BCE4F4AFFB36__INCLUDED_)
