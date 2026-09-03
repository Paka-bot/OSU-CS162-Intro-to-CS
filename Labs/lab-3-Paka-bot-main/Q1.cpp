/*CS162 - Lab 3 - Q1*/

#include <iostream>

using namespace std;

void fooA(int* iptr){
	/*Print the value pointed to by iptr*/

	cout << *iptr << endl;

	/*Print the address stored in iptr*/

	cout << iptr << endl;

	/*Print the address of iptr itself*/

	cout << &iptr << endl;
}

int main(){
	/*declare an integer x and initialize it with value 0*/

	int x = 0;

	/*print the address of x*/

	cout << &x << endl;

	/*Call fooA() with the address of x*/

	fooA(&x);

	/*print the value of x*/

	cout << x << endl;

	return 0;
}
