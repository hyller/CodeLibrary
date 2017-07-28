#if !defined(AFX_LISTENSOCKET_H__F0A651C9_F382_4B2B_9219_881E4D432FB3__INCLUDED_)
#define AFX_LISTENSOCKET_H__F0A651C9_F382_4B2B_9219_881E4D432FB3__INCLUDED_
#include "NewSocket.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListenSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CListenSocket command target

class CListenSocket : public CAsyncSocket
{
// Attributes
public:
	CNewSocket*  m_pSocket;
// Operations
public:
	CListenSocket();
	virtual ~CListenSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListenSocket)
	public:
	virtual void OnAccept(int nErrorCode);
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

#endif // !defined(AFX_LISTENSOCKET_H__F0A651C9_F382_4B2B_9219_881E4D432FB3__INCLUDED_)
