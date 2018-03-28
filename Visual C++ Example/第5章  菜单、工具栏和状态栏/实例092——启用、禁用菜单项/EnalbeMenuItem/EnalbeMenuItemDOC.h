// EnalbeMenuItemDoc.h : interface of the CEnalbeMenuItemDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_EnalbeMenuItemDOC_H__9711857F_BAE5_4742_9D15_FAE05D43173C__INCLUDED_)
#define AFX_EnalbeMenuItemDOC_H__9711857F_BAE5_4742_9D15_FAE05D43173C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEnalbeMenuItemDoc : public CDocument
{
protected: // create from serialization only
	CEnalbeMenuItemDoc();
	DECLARE_DYNCREATE(CEnalbeMenuItemDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnalbeMenuItemDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CEnalbeMenuItemDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEnalbeMenuItemDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EnalbeMenuItemDOC_H__9711857F_BAE5_4742_9D15_FAE05D43173C__INCLUDED_)
