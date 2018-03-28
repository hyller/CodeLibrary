// TrayIconDoc.h : interface of the CTrayIconDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRAYICONDOC_H__CFEAB6A4_FAA6_4775_8577_C45B2E648608__INCLUDED_)
#define AFX_TRAYICONDOC_H__CFEAB6A4_FAA6_4775_8577_C45B2E648608__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTrayIconDoc : public CDocument
{
protected: // create from serialization only
	CTrayIconDoc();
	DECLARE_DYNCREATE(CTrayIconDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrayIconDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTrayIconDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTrayIconDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAYICONDOC_H__CFEAB6A4_FAA6_4775_8577_C45B2E648608__INCLUDED_)
