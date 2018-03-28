// DynaMemuDoc.h : interface of the CDynaMemuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DYNAMEMUDOC_H__DE6A9CE7_8846_4339_B60F_53EC80022190__INCLUDED_)
#define AFX_DYNAMEMUDOC_H__DE6A9CE7_8846_4339_B60F_53EC80022190__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDynaMemuDoc : public CDocument
{
protected: // create from serialization only
	CDynaMemuDoc();
	DECLARE_DYNCREATE(CDynaMemuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynaMemuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDynaMemuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDynaMemuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNAMEMUDOC_H__DE6A9CE7_8846_4339_B60F_53EC80022190__INCLUDED_)
