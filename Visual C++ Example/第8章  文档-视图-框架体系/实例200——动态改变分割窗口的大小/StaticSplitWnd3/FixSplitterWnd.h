// FixSplitterWnd.h: interface for the CFixSplitterWnd class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIXSPLITTERWND_H__9BE119B5_D196_4FB9_93F9_104866BF6185__INCLUDED_)
#define AFX_FIXSPLITTERWND_H__9BE119B5_D196_4FB9_93F9_104866BF6185__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFixSplitterWnd : public CSplitterWnd  
{
public:
	CFixSplitterWnd(BOOL b_lock=true);
	virtual ~CFixSplitterWnd();
public:
	BOOL m_block;
	void Lock(){m_block=true;};//锁定分割线
	void UnLock(){m_block=false;};//不锁定分割线
protected:
	//{{AFX_MSG(CStaticSplitWnd3View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_FIXSPLITTERWND_H__9BE119B5_D196_4FB9_93F9_104866BF6185__INCLUDED_)
