#include <iostream>
#include <string>
using namespace std;


// ptr is a pointer to int
void func1(int * ptr) {
	cout << *ptr << endl;
}

// ptr is a pointer to constant int
void func2(int const * ptr) {
//	*ptr *= 2;  // error
	cout << *ptr << endl;
}

/*
	Now the first const can be on either side of the type so:

	const int * ptr         equal to   int const * ptr
	const int * const ptr   equal to   int const * const ptr
*/

// ptr is a constant pointer to int
void func3(int * const ptr) {
	int y = 3;
//	ptr = &y;  // error
	*ptr = 43;
	cout << *ptr << endl;
}

// ptr is a constant pointer to const int
void func4(const int * const ptr) {
	int z = 44;
//	ptr = &z;  // error
//	*ptr = 4;  // error
	cout << *ptr << endl;
}


int main() {
	cout << "Core CPP..." << endl;

	char *str[10]={0};
	char err[] = "ERROR";
	str[1] = err;
	for (auto& c : str) {
		if (c) {
			cout << c << endl;
		}
	}

	std:string xxx[3] = { "x", "xx", "xxxx"};
	xxx[2] = "xxx";
	for (auto& c : xxx) {
		cout << c << endl;
	}

	int x = 42;
	func1(&x);
	func2(&x);
	func3(&x);
	func4(&x);

	return 0;
}
