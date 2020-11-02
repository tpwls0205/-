#include "DataArray.h"

template<typename T>
DataArray<T>::DataArray(int arrSize)
{
	this->arr = new T[arrSize]();		// ()안넣어주면 쓰레기 값이 들어가있음.
	this->arrSize = arrSize;
}
template<typename T>
DataArray<T>::~DataArray()
{
	delete[] this->arr;
}
template<typename T>
bool DataArray<T>::setData(int idx, T value)	// 래퍼 클래스
{
	if (idx < 0 || idx >= this->arrSize)
		return false;
	this->arr[idx] = value;
	return true;
}
template<typename T>
bool DataArray<T>::getData(int idx, T& value)
{
	if (idx < 0 || idx >= this->arrSize)
		return false;
	value = this->arr[idx];
	return true;
}