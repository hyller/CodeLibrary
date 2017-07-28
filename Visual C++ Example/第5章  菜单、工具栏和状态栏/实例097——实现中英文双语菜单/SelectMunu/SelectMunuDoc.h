// SelectMunuDoc.h : interface of the CSelectMunuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SELECTMUNUDOC_H__E27EEAE0_9ABB_4714_8D7B_DC04A4641B44__INCLUDED_)
#define AFX_SELECTMUNUDOC_H__E27EEAE0_9ABB_4714_8D7B_DC04A4641B44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSelectMunuDoc : public CDocument
{
protected: // create from serialization only
	CSelectMunuDoc();
	DECLARE_DYNCREATE(CSelectMunuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectMunuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSelectMunuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSelectMunuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTMUNUDOC_H__E27EEAE0_9ABB_4714_8D7B_DC04A4641B44__INCLUDED_)
