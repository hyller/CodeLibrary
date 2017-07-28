// MultiPrint2Doc.h : interface of the CMultiPrint2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MultiPrint2DOC_H__F766CAE5_EB3A_4346_AE80_D3F26B8DB8DE__INCLUDED_)
#define AFX_MultiPrint2DOC_H__F766CAE5_EB3A_4346_AE80_D3F26B8DB8DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMultiPrint2Doc : public CDocument
{
protected: // create from serialization only
	CMultiPrint2Doc();
	DECLARE_DYNCREATE(CMultiPrint2Doc)

// Attributes
public:
	CStringArray m_stringArray;
	int m_LinePerPage;//每页打印的行数

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiPrint2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMultiPrint2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMultiPrint2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MultiPrint2DOC_H__F766CAE5_EB3A_4346_AE80_D3F26B8DB8DE__INCLUDED_)
