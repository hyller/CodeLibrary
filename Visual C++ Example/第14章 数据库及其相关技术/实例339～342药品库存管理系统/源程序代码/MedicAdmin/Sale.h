// Sale.h: interface for the CSale class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SALE_H__4123B9FF_CA72_42BB_9943_66D063B57854__INCLUDED_)
#define AFX_SALE_H__4123B9FF_CA72_42BB_9943_66D063B57854__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSale  
{
public:
	CSale();
	virtual ~CSale();

public:
	CString	m_MedicineID;
	CString	m_MedicineName;
	int		m_MedicineNumber;
	float	m_MedicinePrice;

};

#endif // !defined(AFX_SALE_H__4123B9FF_CA72_42BB_9943_66D063B57854__INCLUDED_)
