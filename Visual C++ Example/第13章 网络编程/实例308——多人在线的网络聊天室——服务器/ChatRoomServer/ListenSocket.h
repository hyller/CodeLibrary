#if !defined(AFX_LISTENSOCKET_H__5D655304_370E_4680_A556_E417552D24EC__INCLUDED_)
#define AFX_LISTENSOCKET_H__5D655304_370E_4680_A556_E417552D24EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListenSocket.h : header file
//

#include "ClientSocketList.h"

/////////////////////////////////////////////////////////////////////////////
// CListenSocket command target

class CListenSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CClientSocketList CCSL;//客户socket列表
	CListenSocket();
	virtual ~CListenSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListenSocket)
	public:
	virtual void OnAccept(int nErrorCode);	//重载OnAccept函数
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CListenSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTENSOCKET_H__5D655304_370E_4680_A556_E417552D24EC__INCLUDED_)
