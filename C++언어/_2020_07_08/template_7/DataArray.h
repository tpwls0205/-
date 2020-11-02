#pragma once

template<typename T>
class DataArray
{
private:
	T* arr;		// ���� �迭 �����ּ�
	int arrSize;	// �迭�� �Ҵ� ũ��

public:
	DataArray(int arrSize = 100);
	~DataArray();
	bool setData(int idx, T value);		// idx : index
	bool getData(int idx, T& value);
};

template<typename T>
DataArray<T>::DataArray(int arrSize)
{
	this->arr = new T[arrSize]();		// ()�ȳ־��ָ� ������ ���� ������.
	this->arrSize = arrSize;
}
template<typename T>
DataArray<T>::~DataArray()
{
	delete[] this->arr;
}
template<typename T>
bool DataArray<T>::setData(int idx, T value)	// ���� Ŭ����:�⺻�ڷ����� ����ִ�(���� Ŭ����)
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