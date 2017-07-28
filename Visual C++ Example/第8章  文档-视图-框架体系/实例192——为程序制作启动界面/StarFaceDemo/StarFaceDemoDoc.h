// StarFaceDemoDoc.h : interface of the CStarFaceDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STARFACEDEMODOC_H__217BDC6E_ED0A_4CFB_8390_D5E071C80779__INCLUDED_)
#define AFX_STARFACEDEMODOC_H__217BDC6E_ED0A_4CFB_8390_D5E071C80779__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStarFaceDemoDoc : public CDocument
{
protected: // create from serialization only
	CStarFaceDemoDoc();
	DECLARE_DYNCREATE(CStarFaceDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStarFaceDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStarFaceDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStarFaceDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARFACEDEMODOC_H__217BDC6E_ED0A_4CFB_8390_D5E071C80779__INCLUDED_)
