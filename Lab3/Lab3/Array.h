#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Array
{
private:
	unsigned int size;               
	int * arr;                   
public:
	Array();                      
	Array(unsigned int n, int val = 0);
	Array(const int * pn, unsigned int n);
	Array(const Array & a);         
	~Array();                       

	unsigned int ArSize() const { return size; }
	double Average() const;                 
											
	void show()const;
	void init();
	Array add(const Array &ob)const;


	int & operator[](int i);
	const int & operator[](int i) const;
	Array & operator=(const Array & a);

	Array  operator+(int k)const;
	Array  operator+(const Array &a)const;
	Array & operator+=(int k);
	friend Array  operator+(int k, const Array &a);

	friend ostream & operator<<(ostream & os, const Array & a);
	friend istream & operator>>(istream & is, Array & a);
	
	operator int();


	Array & operator=(Array && a);
	Array(Array && a);


	void SaveToFile(FILE * f);
	void ReadFromFile(FILE *f);



	friend ofstream & operator<<(ofstream & os, const Array & s);
	friend ifstream & operator>>(ifstream & is, Array & s);
};


