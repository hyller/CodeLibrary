// MedicSearch.h: interface for the CMedicSearch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEDICSEARCH_H__A78099FA_DC4F_434D_A9F9_1F6B6C2CCB08__INCLUDED_)
#define AFX_MEDICSEARCH_H__A78099FA_DC4F_434D_A9F9_1F6B6C2CCB08__INCLUDED_

#include "MedicSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMedicSearch  
{
public:
	void SearchOverdueMedic();
	void SearchZeroNumber();
	void SearchAll();
	void Search(CString str,int flag);
	void SetMedicSet(CMedicSet* theMedicSet);
	void SetListCtrl(CListCtrl* theListCtrl);
	CMedicSearch();
	virtual ~CMedicSearch();
protected:
	CMedicSet* m_theMedicSet;
	CListCtrl* m_theListCtrl;
};

#endif // !defined(AFX_MEDICSEARCH_H__A78099FA_DC4F_434D_A9F9_1F6B6C2CCB08__INCLUDED_)
