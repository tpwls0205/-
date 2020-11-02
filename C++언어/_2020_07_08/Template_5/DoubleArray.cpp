#include "DoubleArray.h"

DoubleArray::DoubleArray(int arrSize)
{
	this->arr = new double[arrSize]();		// ()안넣어주면 쓰레기 값이 들어가있음.
	this->arrSize = arrSize;
}
DoubleArray::~DoubleArray()
{
	delete[] this->arr;
}
bool DoubleArray::setDouble(int idx, double value)	// 래퍼 클래스
{
	if (idx < 0 || idx >= this->arrSize)
		return false;
	this->arr[idx] = value;
	return true;
}
bool DoubleArray::getDouble(int idx, double& value)
{
	if (idx < 0 || idx >= this->arrSize)
		return false;
	value = this->arr[idx];
	return true;
}