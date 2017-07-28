// MappingDemoDoc.h : interface of the CMappingDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAPPINGDEMODOC_H__42D6D7A2_A8C7_4DB1_ADD6_3A1D0CC73815__INCLUDED_)
#define AFX_MAPPINGDEMODOC_H__42D6D7A2_A8C7_4DB1_ADD6_3A1D0CC73815__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMappingDemoDoc : public CDocument
{
protected: // create from serialization only
	CMappingDemoDoc();
	DECLARE_DYNCREATE(CMappingDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMappingDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMappingDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMappingDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPPINGDEMODOC_H__42D6D7A2_A8C7_4DB1_ADD6_3A1D0CC73815__INCLUDED_)
