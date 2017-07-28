// Medic.h: interface for the CMedic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEDIC_H__DC1599F9_DCCF_480A_8BEB_39AE5740E3A2__INCLUDED_)
#define AFX_MEDIC_H__DC1599F9_DCCF_480A_8BEB_39AE5740E3A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMedic  
{
public:
	CMedic();
	virtual ~CMedic();
public:
	CString	m_MedicineID;
	CString	m_MedicineName;
	CString	m_MedicineClassification;
	CTime	m_ProduceDate;
	CString	m_Produceplace;
	int		m_MedicineNumber;
	CString	m_Description;
	float	m_UnitPrice;
	int		m_QeulityAssurancePeriod;
	int		m_LowestNumber;
	int		m_HighestNumber;
	CString	m_ProduceCompany;
};

#endif // !defined(AFX_MEDIC_H__DC1599F9_DCCF_480A_8BEB_39AE5740E3A2__INCLUDED_)
