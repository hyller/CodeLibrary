// ManageMedic.h: interface for the CManageMedic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANAGEMEDIC_H__8CFE87BA_9356_4917_9B89_64840A0E2A94__INCLUDED_)
#define AFX_MANAGEMEDIC_H__8CFE87BA_9356_4917_9B89_64840A0E2A94__INCLUDED_
#include "medicSet.h"
#include "medic.h"
#include "sale.h"
#include "saleset.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CManageMedic  
{
public:
	void DeleteOverdueMedic();
	void DeleteAllZeroNumber();
	CTime GetExpireTime();
	float CheckOut();
	BOOL Recover();
	BOOL DeleteFromSaleTable();
	BOOL ModifyFromSaleTable();
	BOOL AddToSaleTable();
	void SetSaleSet(CSaleSet* theSaleSet);
	void SetSale(CSale* theSale);
	void Import();
	void SetMedicSet(CMedicSet* theMedicSet);
	void SetMedic(CMedic* theMedic);
	CManageMedic();
	virtual ~CManageMedic();
protected:
	CMedic* m_theMedic;
	CMedicSet* m_theMedicSet;
	CSale* m_theSale;
	CSaleSet* m_theSaleSet;
};

#endif // !defined(AFX_MANAGEMEDIC_H__8CFE87BA_9356_4917_9B89_64840A0E2A94__INCLUDED_)
