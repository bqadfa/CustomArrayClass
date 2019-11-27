#include "MyArray.h"
#include <iostream>

using namespace std;

void main()
{
	//Создание массива с опредением диапазона
	MyArray a1(5, 1, 19), a2(5, 18, 37), a3(6, -15, 10);

	cout << "a1:\n" << a1 << "\na2:\n" << a2 << "\na3:\n" << a3 << endl;

	//Доступ к отдельному элемету массивa
	cout << "a1[3] = " << a1[3] << endl << "a2[4] = " << a2[4] << endl;
	cout << "\nTrying to take out_of_range element of array:\n";
	cout << a1[10];

	//Перегрузка операторов + и - 
	cout << "a4 = a1 + a2 = ";
	MyArray a4 = a1 + a2;
	cout << a4 << endl;
	cout << "a2 + a3 = ";
	a4 = a2 + a3;
	cout << "a4 = a3 - a1 = ";
	a4 = a3 - a1;
	cout << a4 << endl;

	system("pause");
}