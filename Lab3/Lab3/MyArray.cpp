#include "MyArray.h"
#include <iostream>
#include <iomanip>
#include <assert.h>
using namespace std;

//MyArray::MyArray()
//{
//	size = 5;
//	arr = new int[size];
//	for (int i = 0; i < size; i++)
//		arr[i] = 0;
//}

MyArray::MyArray(int num, int size)
{
	this->size = size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = num;
}

MyArray::MyArray(int * arr, int size)
{
	this->size = size;
	this->arr = new int[size];
	for (int i = 0; i < size; i++)
		this->arr[i] = arr[i];
}

MyArray::MyArray(int size, int start, int end)
{
	this->size = size;
	arr = new int[this->size];
	for (int i = 0; i < size; i++)
		arr[i] = start + rand() % (end - start);
}

MyArray::MyArray(const MyArray & arr)
{
	size = arr.size;
	this->arr = new int[size];
	for (int i = 0; i < size; i++)
		this->arr[i] = arr.arr[i];
}


MyArray & MyArray::operator=(const MyArray & ob)
{
	if (this == &ob)
		return *this;
	if (size != ob.size) {
		size = ob.size;
		arr = new int[size];
	}
	for (int i = 0; i < size; i++)
		arr[i] = ob.arr[i];
	return *this;
}

MyArray MyArray::coonect(MyArray &obj)const
{
	int newSize = this->size + obj.size;
	MyArray tmp(1, newSize);
	for (int i = 0; i < this->size; i++)
		tmp.arr[i] = this->arr[i];
	for (int i = this->size, j = 0; i < newSize; i++, j++)
		tmp.arr[i] = obj.arr[j];
	return tmp;
}

MyArray & MyArray::operator+=(int n)
{
	int *tmp, tsize;
	tsize = size;
	tmp = new int[tsize];
	for (int i = 0; i < size; i++)
		tmp[i] = arr[i];
	delete[]arr;
	size = tsize + n;
	arr = new int[size];
	for (int i = 0; i < tsize; i++)
		arr[i] = tmp[i];
	for (int i = tsize; i < size; i++)
		arr[i] = 0;
	return *this;
}

MyArray MyArray::operator+(int n)
{
	MyArray tmp;
	//int tsize;
	tmp.size = size + n;
	for (int i = 0; i < size; i++)
		tmp.arr[i] = arr[i];
	for (int i = size; i < tmp.size; i++)
		tmp.arr[i] = 0;
	return tmp;
}
MyArray MyArray::operator+(MyArray & obj)const
{
	/*tmp.size = this->size + obj.size;
	delete[] tmp.arr;
	tmp.arr = new int[tmp.size];
	int j = 0;
	for (int i = 0; i < this->size; i++)
		tmp.arr[i] = this->arr[i];
	for (int i = this->size; i < tmp.size; i++)
		tmp.arr[i] = obj.arr[j++];*/

	if (size == obj.size)
	{
		MyArray tmp;
		tmp.size = this->size;
		tmp.arr = new int[tmp.size];
		for (int i = 0; i < tmp.size; i++)
			tmp.arr[i] = obj.arr[i] + arr[i];
		return tmp;
	}
	else
	{
		cout << "Error. The arrays have different sizes.\n";
		return 0;
	}
	
}

MyArray MyArray::operator-(MyArray & obj) const
{
	if (size == obj.size)
	{
		MyArray tmp;
		tmp.size = this->size;
		tmp.arr = new int[tmp.size];
		for (int i = 0; i < tmp.size; i++)
			tmp.arr[i] = obj.arr[i] - arr[i];
		return tmp;
	}
	else
	{
		cout << "Error. The arrays have different sizes.\n";
		return 0;
	}
}



int & MyArray::operator[](int i)
{
	assert(i >= 0 && i < size);
	return arr[i];
}

const int & MyArray::operator[](int i) const
{
	assert(i >= 0 && i < size);
	return arr[i];
}

float MyArray::getMM() const
{
	float m = 0;
	for (int i = 0; i < size; i++)
		m += arr[i];
	return m / size;
}

MyArray::~MyArray()
{
	delete[]arr;
	arr = nullptr;
}

ostream & operator<<(ostream & out, const MyArray & ob)
{
	for (int i = 0; i < ob.size; i++) {
		out << setw(3) << ob.arr[i];
	}
	return out;
}

istream & operator>>(istream & in, MyArray & ob)
{
	for (int i = 0; i < ob.size; i++)
		in >> ob.arr[i];
	return in;
}
