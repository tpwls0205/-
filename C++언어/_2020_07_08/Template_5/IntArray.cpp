#include "IntArray.h"

IntArray::IntArray(int arrSize)
{
	this->arr = new int[arrSize]();		// ()안넣어주면 쓰레기 값이 들어가있음.
	this->arrSize = arrSize;
}
IntArray::~IntArray()
{
	delete[] this->arr;
}
bool IntArray::setInt(int idx, int value)	// 래퍼 클래스
{
	if (idx < 0 || idx >= this->arrSize)
		return false;
	this->arr[idx] = value;
	return true;
}
bool IntArray::getInt(int idx, int& value)
{
	if (idx < 0 || idx >= this->arrSize)
		return false;
	value = this->arr[idx];
	return true;
}