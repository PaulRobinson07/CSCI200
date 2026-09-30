/* CSCI 200: Lab 2B 
 *
 * Author: Paul Rayford Robinson
 *
 *
 */

#include <iostream>


/*
 */

using namespace std;

int main() {
	//1
	int iNum = 4;
	int iNum2 = 5;

	//2
	int* pINum1 = nullptr;
	int* pINum2 = nullptr;

	//3
	pINum1 = &iNum;

	//4
	pINum2 = &iNum2;

	//5
	cout << "The address of the first pointer is: " << pINum2 << 
	" and the address of the first variable is: " << &iNum2 << endl;

	//6
	cout << "The address of the second pointer is: " << pINum2 << 
	" and the address of the second variable is: " << &iNum2 << endl;
	
	//7
	cout << "The value of variable one is: " << *pINum1 << endl;

	//8
	cout << "The value of variable two is: " << *pINum2 << endl;

	//9
	iNum = 6;

	//10
	cout << "The value of variable one is: " << iNum << endl;

	//11
	cout << "The value of the variable that pointer one points to is: " << *pINum1 << endl;

	//12
	*pINum1 = 7;
	
	//13
	cout << "The value of variable one is: " << iNum << endl;
	
	//14
	pINum2 = pINum1;

	//15
	cout << "The address of the second pointer is: " << pINum2 << 
	" and the address of the first variable is: " << &iNum << endl;

	//16
	cout << "The value that pointer two holds is: " << *pINum2 << endl;

	//17
	*pINum2 = 8;

	//18
	cout << "Variable one: " << iNum << endl;
	cout << "Pointer  one: " << *pINum1 << endl;
	cout << "Pointer  two: " << *pINum2 << endl;

	//19 
	cout << "Variable two: " << iNum2 << endl;

	//20
	double* pDNum = nullptr;

	//21
	//pDNum = &iNum;
	//error: incompatible pointer types assigning to 'double *' from 'int *'
	
	//22
	//pDNum = pINum1;
	//error: incompatible pointer types assigning to 'double *' from 'int *'
	
	//23
	double dNum = 14.25;

	//24
	pDNum = &dNum;

	//25
	cout << "The value of the variable that pointer three points to is: " << *pDNum << endl;
	cout << "The value of variable three is: " << dNum << endl;

	//26
	*pDNum = *pINum1;

	//27
	cout << "The value of the variable that pointer three points to is: " << *pDNum << endl;
	cout << "The value of variable three is: " << dNum << endl;

	return 0;
}
