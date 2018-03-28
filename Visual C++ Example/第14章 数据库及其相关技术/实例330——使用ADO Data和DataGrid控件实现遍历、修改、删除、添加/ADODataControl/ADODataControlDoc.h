// ADODataControlDoc.h : interface of the CADODataControlDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADODATACONTROLDOC_H__44F3E02F_8D66_45B7_8DF5_59CF84DEE51A__INCLUDED_)
#define AFX_ADODATACONTROLDOC_H__44F3E02F_8D66_45B7_8DF5_59CF84DEE51A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CADODataControlDoc : public CDocument
{
protected: // create from serialization only
	CADODataControlDoc();
	DECLARE_DYNCREATE(CADODataControlDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADODataControlDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CADODataControlDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CADODataControlDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODATACONTROLDOC_H__44F3E02F_8D66_45B7_8DF5_59CF84DEE51A__INCLUDED_)
