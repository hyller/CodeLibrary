// StatusComboDoc.h : interface of the CStatusComboDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATUSCOMBODOC_H__F3F294F2_7BB7_496B_81EF_40A5281A13DE__INCLUDED_)
#define AFX_STATUSCOMBODOC_H__F3F294F2_7BB7_496B_81EF_40A5281A13DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStatusComboDoc : public CDocument
{
protected: // create from serialization only
	CStatusComboDoc();
	DECLARE_DYNCREATE(CStatusComboDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatusComboDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStatusComboDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStatusComboDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATUSCOMBODOC_H__F3F294F2_7BB7_496B_81EF_40A5281A13DE__INCLUDED_)
