#pragma once
#include <iostream>

using namespace std;
class MyArray
{
	int *arr;
	unsigned int size;
public:
	//MyArray();
	MyArray(int num = 0, int size = 5);
	MyArray(int *arr, int size);
	MyArray(int size, int start, int end);
	MyArray(const MyArray &arr);

	MyArray & operator=(const MyArray & ob);
	MyArray coonect(MyArray &)const;
	MyArray & operator+=(int n);
	MyArray operator+(int n);
	MyArray operator+(MyArray & obj)const;
	MyArray operator-(MyArray & obj)const;
	

	int getSize()const { return size; }
	int & operator[](int i);
	const int & operator[](int i)const;
	float getMM()const;
	

	friend ostream & operator<<(ostream & out, const MyArray & ob);
	friend istream & operator>>(istream & in, MyArray & ob);
	~MyArray();
};

