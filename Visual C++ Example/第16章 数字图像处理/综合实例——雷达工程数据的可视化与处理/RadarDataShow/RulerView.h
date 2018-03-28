#if !defined(AFX_RULERVIEW_H__98259BC6_C9F4_4AB9_ADC8_3F1B64DBCF88__INCLUDED_)
#define AFX_RULERVIEW_H__98259BC6_C9F4_4AB9_ADC8_3F1B64DBCF88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RullerSplliterWnd.h"
// RulerView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRulerView view



class CRulerView : public CView
{
protected:
	CRulerView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CRulerView)

// Attributes
private:
	CSize  m_DocSize;
	UINT   m_rulerType;
	CPoint m_lastPos;
	CPoint m_scrollPos;

// Operations
public:
	void SetRulerType(UINT rulerType)
    {
        m_rulerType   = rulerType;
    }
	//bool lay;
	void UpdateRulersInfo(stRULER_INFO stRulerInfo);
private:
    void DrawTicker(CDC* pDC, CRect rulerRect, int nFactor, int nBegin = 0, bool bShowPos=TRUE,bool thick_flag=FALSE);
	void DrawCursorPos(CPoint NewPos);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRulerView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CRulerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CRulerView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RULERVIEW_H__98259BC6_C9F4_4AB9_ADC8_3F1B64DBCF88__INCLUDED_)
