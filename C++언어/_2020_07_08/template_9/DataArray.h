#pragma once

template<typename T>
class DataArray
{
private:
	T* arr;		// 동적 배열 시작주소
	int arrSize;	// 배열의 할당 크기

public:
	DataArray(int arrSize = 100);
	~DataArray();
	bool setData(int idx, T value);		// idx : index
	bool getData(int idx, T& value);
	T& operator[](int idx);				// 값을 대입할때 - set할때 호출
	const T& operator[](int idx) const;	// 값을 꺼내올때 - get할때 호출
};

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
template<typename T>
T& DataArray<T>::operator[](int idx)
{
	return this->arr[idx];
}
template<typename T>
const T& DataArray<T>::operator[](int idx) const
{
	return this->arr[idx];
}