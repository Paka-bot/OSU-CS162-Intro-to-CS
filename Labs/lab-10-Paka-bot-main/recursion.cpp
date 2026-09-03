#include "recursion.hpp"

int no_zero_strings(int n) {
	// TODO Complete this function

	if (n == 0) return 1;
	if (n == 1) return 2;

	return no_zero_strings(n - 1) + no_zero_strings(n - 2);
}

// S(n) = S(n-1) + s(n-2)

// case 1 - S(n-1): Start with 1

// case 2 - S(n-2): Start with 0