// DockToolbarDoc.h : interface of the CDockToolbarDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOCKTOOLBARDOC_H__40371A1A_6FD8_4265_9F43_FC99CB0704B4__INCLUDED_)
#define AFX_DOCKTOOLBARDOC_H__40371A1A_6FD8_4265_9F43_FC99CB0704B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDockToolbarDoc : public CDocument
{
protected: // create from serialization only
	CDockToolbarDoc();
	DECLARE_DYNCREATE(CDockToolbarDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDockToolbarDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDockToolbarDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDockToolbarDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOCKTOOLBARDOC_H__40371A1A_6FD8_4265_9F43_FC99CB0704B4__INCLUDED_)
