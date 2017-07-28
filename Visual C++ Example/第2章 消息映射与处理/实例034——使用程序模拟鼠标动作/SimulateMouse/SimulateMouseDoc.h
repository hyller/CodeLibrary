// SimulateMouseDoc.h : interface of the CSimulateMouseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIMULATEMOUSEDOC_H__4364FD56_D710_45A0_B993_270397A3116C__INCLUDED_)
#define AFX_SIMULATEMOUSEDOC_H__4364FD56_D710_45A0_B993_270397A3116C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSimulateMouseDoc : public CDocument
{
protected: // create from serialization only
	CSimulateMouseDoc();
	DECLARE_DYNCREATE(CSimulateMouseDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimulateMouseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSimulateMouseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSimulateMouseDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMULATEMOUSEDOC_H__4364FD56_D710_45A0_B993_270397A3116C__INCLUDED_)
