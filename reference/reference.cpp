#include <iostream>

int main()
{
	int number = 3;
	
	int *p = & number;
	std::cout << *p << std::endl;
	*p = 10;
	
	int meh = 2;
	const int *cip = &number; // only locks the value of cp(*cp)
	cip = &meh; // Still this can happen - changeable address
	// Cant change the value of the address contains
	
	int* const icp =  &number;
	*icp = 20; // Changeable value
	// Cant change the address where its pointing
	
	int& ref = number;
	
	std::cout << number << std::endl;
	std::cout << ref << std::endl;
	
	int number2 = 10;
	
	ref = number2;
	
	std::cout << number << std::endl;
	std::cout << ref << std::endl;
	
	// coonstant number can be taken as const reference
	const int& ref2 = 5;
	
	std::cout << ref2 << std::endl;
	
	int number3 = 12;
	p = &number3;
	
	std::cout << *p << std::endl;
	
	int* const p1 = &number;
	std::cout << *p1 << std::endl;
	// p1 = number3; // This invokes an error
	
	const int& c_ref = number;
	// c_ref = number2; // This invokes an error
	
	int arr[3[ = {a,b,c};
	int &(rarra)[3] = arr;
	
	int a; 
	
	int& b = a  // b does not exist in the memory
	int *pb = a; // pb exists in the memory
	
	return 0;
}