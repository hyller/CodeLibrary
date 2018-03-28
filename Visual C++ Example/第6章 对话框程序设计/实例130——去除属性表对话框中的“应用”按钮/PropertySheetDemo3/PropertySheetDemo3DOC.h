// PropertySheetDemo3Doc.h : interface of the CPropertySheetDemo3Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PropertySheetDemo3DOC_H__DBDD6105_0288_4A46_9302_C04BD05E32CD__INCLUDED_)
#define AFX_PropertySheetDemo3DOC_H__DBDD6105_0288_4A46_9302_C04BD05E32CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPropertySheetDemo3Doc : public CDocument
{
protected: // create from serialization only
	CPropertySheetDemo3Doc();
	DECLARE_DYNCREATE(CPropertySheetDemo3Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertySheetDemo3Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPropertySheetDemo3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPropertySheetDemo3Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PropertySheetDemo3DOC_H__DBDD6105_0288_4A46_9302_C04BD05E32CD__INCLUDED_)
