// EmbeddedGUIDoc.h : interface of the CEmbeddedGUIDoc class
//


#pragma once


class CEmbeddedGUIDoc : public CDocument
{
protected: // create from serialization only
	CEmbeddedGUIDoc();
	DECLARE_DYNCREATE(CEmbeddedGUIDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CEmbeddedGUIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void SetTitle(LPCTSTR lpszTitle);
};


