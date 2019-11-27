//#include "pch.h"
//#include "stdafx.h"
#include <iostream>
#include "array.h"
#include <assert.h>
#include <fstream>
using namespace std;
//-------------------------------------------
Array::Array()
{
	/*arr = nullptr;
	size = 0;*/
	size = 5;
	arr = new int[size] {0};
}
//-------------------------------------------
Array::Array(unsigned int n, int val)
{
	size = n;
	arr = new int[size];
	
	for (int i = 0; i < size; i++)
		arr[i] = val;
}

//-------------------------------------------
Array::Array(const int *pn, unsigned int n)
{
	size = n;
	arr = new int[size];
	
	for (int i = 0; i < size; i++)
		arr[i] = pn[i];
}

//-------------------------------------------
Array::Array(const Array & a)
{
	size = a.size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = a.arr[i];
}
//-------------------------------------------
Array::~Array()
{
	delete[] arr;
	arr = nullptr;
}
//-------------------------------------------
double Array::Average() const
{
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return sum / size;
	
}
//-------------------------------------------
void Array::show()const
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

//-------------------------------------------
void Array::init()
{
	for (int i = 0; i < size; i++)
		cin>>arr[i];
}

//-------------------------------------------

Array Array::add(const Array &ob)const
{
	int k = size + ob.size;
	Array t(k);
	int i, j=0;
	for (i = 0; i < size; i++)
		t.arr[i] = arr[i];
	for (; i < t.size; i++)
		t.arr[i] = ob.arr[j++];
	return t;
}




//---------------------------------------------

int & Array::operator[](int i)
{
	assert(i >= 0 && i < size);
	return arr[i];
}
//---------------------------------------------

const int & Array::operator[](int i) const
{
	assert(i >= 0 && i < size);
	return arr[i];
}
//-----------------------------------------------

Array & Array::operator=(const Array & a)
{
	if (this == &a)    
		return *this;  
	delete[] arr;
	size = a.size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = a.arr[i];
	return *this;
}
//----------------------------------------------------

ostream & operator<<(ostream & os, const Array & a)
{
	int i;
	for (i = 0; i < a.size; i++)
	{
		os << a.arr[i] << " ";
	}

	return os;
}

//----------------------------------------------------
istream & operator>>(istream & is, Array & a)
{
	int i;
	for (i = 0; i < a.size; i++)
	{
		is >> a.arr[i];
	}

	return is;
}

//----------------------------------------------------
Array  Array::operator+(int k)const
{
	Array t;
	int i;
	t.size = size + k;
	t.arr = new int[t.size];
	for (i = 0; i < size; i++)
		t.arr[i] = arr[i];
	for (; i < t.size; i++)
		t.arr[i] = 0;
	return t;
}

//----------------------------------------------------
Array & Array::operator+=(int k)
{
	int i, s = size;
	int * t = arr;
	size += k;
	arr = new int[size];
	for (i = 0; i < s; i++)
		arr[i] = t[i];
	for (; i < size; i++)
		arr[i] = 0;
	delete[]t;
	return *this;
}
//----------------------------------------------------
Array  Array::operator+(const Array &a)const
{
	Array t;
	int i, k = 0;
	t.size = size + a.size;
	t.arr = new int[t.size];
	for (i = 0; i < size; i++)
		t.arr[i] = arr[i];
	for (; i < t.size; i++)
		t.arr[i] = a.arr[k++];
	return t;

}
//----------------------------------------------------
Array  operator+(int k, const Array &a)
{
	Array t;
	int i, j = 0;
	t.size = a.size + k;
	t.arr = new int[t.size];

	for (i = 0; i < k; i++)
		t.arr[i] = 0;
	for (; i < t.size; i++)
		t.arr[i] = a.arr[j++];
	return t;

}

//----------------------------------------------------
Array::operator int()
{
	int s = 0;
	for (int i = 0; i < size; i++)
	{
		s += arr[i];
	}
	return s;
}

//----------------------------------------------------
Array::Array(Array && a)
{
	size = a.size;
	arr = a.arr;

	a.size = 0;
	a.arr = nullptr;

}

//----------------------------------------------------
Array & Array::operator=(Array && a)
{
	delete[] arr;
	size = a.size;
	arr = a.arr;

	a.size = 0;
	a.arr = nullptr;

	return *this;
}


//Урок 17------------------------------------------------
//-------------------------------------------------------
void Array::SaveToFile(FILE * f)
{
	fwrite(&size, sizeof(size), 1, f);
	fwrite(arr, sizeof(int)*size, 1, f);
}

//-------------------------------------------------------
void Array::ReadFromFile(FILE *f)
{
	delete[]arr;
	fread(&size, sizeof(size), 1, f);
	arr = new int[size];

	fread(arr, sizeof(int)*size, 1, f);
}

//-------------------------------------------------------
ofstream & operator<<(ofstream & fos, const Array & m)
{
	if (m.size) {
		fos.write((char*)&m.size, sizeof(m.size));
		fos.write((char*)m.arr, m.size * sizeof(m[0]));
	}
	return fos;
}
//----------------------------------------------------------
ifstream & operator>>(ifstream & fis, Array & m)
{
	fis.read((char*)&m.size, sizeof(m.size));
	if (m.arr) delete[]m.arr;
		
	m.arr = new int[m.size];
	fis.read((char*)m.arr, m.size * sizeof(m[0]));

	return fis;
}
