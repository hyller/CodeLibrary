// RestoreWinPosDoc.h : interface of the CRestoreWinPosDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RESTOREWINPOSDOC_H__1E10CA7E_F641_415E_A370_9FC587239C1E__INCLUDED_)
#define AFX_RESTOREWINPOSDOC_H__1E10CA7E_F641_415E_A370_9FC587239C1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRestoreWinPosDoc : public CDocument
{
protected: // create from serialization only
	CRestoreWinPosDoc();
	DECLARE_DYNCREATE(CRestoreWinPosDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRestoreWinPosDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRestoreWinPosDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRestoreWinPosDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESTOREWINPOSDOC_H__1E10CA7E_F641_415E_A370_9FC587239C1E__INCLUDED_)
