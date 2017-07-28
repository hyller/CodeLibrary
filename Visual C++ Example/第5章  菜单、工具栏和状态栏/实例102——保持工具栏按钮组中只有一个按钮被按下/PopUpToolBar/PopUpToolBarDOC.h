// PopUpToolBarDoc.h : interface of the CPopUpToolBarDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PopUpToolBarDOC_H__11712290_9CEC_4217_8549_46006C160922__INCLUDED_)
#define AFX_PopUpToolBarDOC_H__11712290_9CEC_4217_8549_46006C160922__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPopUpToolBarDoc : public CDocument
{
protected: // create from serialization only
	CPopUpToolBarDoc();
	DECLARE_DYNCREATE(CPopUpToolBarDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopUpToolBarDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPopUpToolBarDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPopUpToolBarDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PopUpToolBarDOC_H__11712290_9CEC_4217_8549_46006C160922__INCLUDED_)
