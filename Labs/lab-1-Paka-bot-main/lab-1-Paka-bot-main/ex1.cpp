#include <iostream>

void function (int x[], int n) { 
	int i, t, j = n, s = 1;
	while (s) {
		s = 0;
		for (i = 1; i < j; i++) {
			if (x[i] < x[i - 1]) {
				t = x[i];
				x[i] = x[i - 1];
				x[i - 1] = t;
				s = 1;
			}
		}
		j--;
	}
}

/*This code uses a while statement, a for statement, and an if statement. 
The while statement sets the conditions under which the loop will run, and 
the for statement executes the code repeatedly under those conditions.*/
 
int main () {
	int x[] = {15, 56, 12, -21, 1, 659, 3, 83, 51, 3, 135, 0};
	int n = sizeof(x) / sizeof(x[0]);
	int i;
	for (i = 0; i < n; i++) {
		std::cout << x[i] << " ";
	}
	std::cout << std::endl;
	
	function(x, n);
	
	for (i = 0; i < n; i++) {
		std::cout << x[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}

/* First, the code creates an array called x. 
It uses sizeof to count the number of elements in the array. 
It uses a for statement to print the values in the array. 
It then calls the function above to perform the calculation using the array.*/