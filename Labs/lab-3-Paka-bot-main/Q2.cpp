/*CS 162 - Lab 3 - Q.2*/

#include <iostream>

using namespace std;

// This is an exercise in pass-by-value vs pass-by-pointer
// vs pass-by-reference. When the inline comments say "a", they're
// really referring to the value pointed to by a. When they say
// "b", they're really referring to the value referenced by b.
int foo(int* a, int& b, int c){
	/*Set a to 2 times its original value*/

	*a = *a * 2;

	/*Set b to half of its original value*/

	b = b / 2;

	/*Assign a + b to c*/

	c = *a + b;

	/*Return c*/

	return c;
}

int main(){
	/*Declare three integers x, y, and z, and initialize them to 7, 8, 9 respectively*/

	int x = 7;
	int y = 8;
	int z = 9;

	/*Print the values of x, y and z*/

	cout << x << endl << y << endl << z << endl;

	/*Call foo() appropriately, passing x, y, and z as arguments by pointer, reference, and value*/

	int foo_value = foo(&x, y, z);


	/*Print the value returned by the previous call to foo() (did you remember to store it?)*/

	cout << foo_value << endl;

	/*Print the values of x, y and z again*/

	cout << x << endl << y << endl << z << endl;

	/*Is the return value different than the value of z? Why or why not? */
	
	/*it's different, because the z value is passed as an argument to the function, it does not change even if the c value is changed inside foo.*/

	return 0;
}
