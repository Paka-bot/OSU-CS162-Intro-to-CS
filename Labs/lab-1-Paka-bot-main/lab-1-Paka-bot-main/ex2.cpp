#include <iostream>

bool function(int num) {
	if (num == 1) {
		return false;
	}

	for(int i = 2; i <= num/2; i++){
		if(num % i == 0) {
			return false;
		}
	}
	return true;
}

/*This function is determining if the number we're given is a prime number or not.*/

int main() {

	int num;
	std::cout << "Input a number: ";
	std::cin >> num;
	
	bool result = function(num);
	if (result) {
		std::cout << "True" << std::endl;
	} else {
		std::cout << "False" << std::endl;
	}

	return 0;
}

/*This code outputs true if the number input is a prime number, otherwise it outputs false*/

