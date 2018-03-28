// PropertySheetDemoDoc.h : interface of the CPropertySheetDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROPERTYSHEETDEMODOC_H__DBDD6105_0288_4A46_9302_C04BD05E32CD__INCLUDED_)
#define AFX_PROPERTYSHEETDEMODOC_H__DBDD6105_0288_4A46_9302_C04BD05E32CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPropertySheetDemoDoc : public CDocument
{
protected: // create from serialization only
	CPropertySheetDemoDoc();
	DECLARE_DYNCREATE(CPropertySheetDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertySheetDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPropertySheetDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPropertySheetDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPERTYSHEETDEMODOC_H__DBDD6105_0288_4A46_9302_C04BD05E32CD__INCLUDED_)
