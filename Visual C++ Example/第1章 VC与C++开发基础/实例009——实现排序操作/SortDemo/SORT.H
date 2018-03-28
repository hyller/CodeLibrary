// Sort.h: interface for the CSort class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SORT_H__A188801C_AC96_4A65_A800_119AE5E5C08F__INCLUDED_)
#define AFX_SORT_H__A188801C_AC96_4A65_A800_119AE5E5C08F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

template <class T>//声明函数模板
class CSort  
{
public:
	CSort(int nArraySize);
	virtual ~CSort();

	void Bubble(T array[]);        // 冒泡排序
	void Insertion(T array[]);     // 插入排序
	void Quick(T array[], int nLeftLimit, int nRightLimit);	// 快速排序
	void Selection(T array[]);	   // 选择排序	

private:
	int m_nArraySize;				//成员变量
};

template <class T>
CSort<T>::CSort(int nArraySize)//构造函数
{
	if (nArraySize<0)
		m_nArraySize = 0;
	else
		m_nArraySize = nArraySize;
}

template <class T>
CSort<T>::~CSort()
{
}
template <class T>
void CSort<T>::Bubble(T array[])//冒泡排序函数模板
{	
	T temp;
	int nLast = m_nArraySize - 1;
	BOOL bSorted = TRUE;
	do 
	{
		bSorted = TRUE;
		for (int i = 0; i < nLast; i++) 
		{
			// 如果前一个元素比后一个元素大，则交换两个元素
			if (array[i] > array[i + 1])
			{	
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				bSorted = FALSE;
			}
		}
		nLast--;
	} while (!bSorted);

}

template <class T>
void CSort<T>::Insertion(T array[]) //插入排序函数模板
{
	T cVal;		// 记录当前被测试的值
	for (int i = 1; i < m_nArraySize; i++) 
	{
		cVal = array[i];
		for (int n = i - 1; n >= 0 && cVal < array[n]; n--) 
		{
			array[n + 1] = array[n];
		}
		array[n + 1] = cVal;
	}
}
template <class T>
void CSort<T>::Quick(T array[], int llimit, int rlimit)//快速排序函数模板
{
	T temp;
	int nLeft = llimit;
	int nRight = rlimit;
	int pivot = (nLeft + nRight) / 2;	//中间值
	T nMedian = array[pivot];
	do 
	{
		while ((array[nLeft] < nMedian) && (nLeft < rlimit))
		{
			nLeft++;
		}
		while ((nMedian < array[nRight]) && (nRight > llimit)) 
		{
			nRight--;
		}
		if (nLeft <= nRight)
		{
			// 交换元素
			temp = array[nLeft];
			array[nLeft] = array[nRight];
			array[nRight] = temp;
			nLeft++;
			nRight--;
		}

	} while (nLeft <= nRight);
	if (llimit < nRight)
	{
		CSort<T>::Quick(array, llimit, nRight);
	}
	if (nLeft < rlimit) 
	{
		CSort<T>::Quick(array, nLeft, rlimit);
	}

}

template <class T>
void CSort<T>::Selection(T array[]) //选择排序函数模板
{
	T temp;
	int min;
	for (int i = 0; i < m_nArraySize - 1; i++)
	{
		min = i;
		for (int n = i + 1; n < m_nArraySize; n++)
		{
			if (array[n] < array[min])
			{
				min = n;
			}
		}
		temp = array[min];
		array[min] = array[i];
		array[i] = temp;		
	}
}

#endif // !defined(AFX_SORT_H__A188801C_AC96_4A65_A800_119AE5E5C08F__INCLUDED_)
