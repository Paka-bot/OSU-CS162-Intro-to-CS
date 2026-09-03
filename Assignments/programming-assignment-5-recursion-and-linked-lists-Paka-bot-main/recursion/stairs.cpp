#include "stairs.hpp"

int ways_to_top(int n) {
	// TODO Complete this function
	// TODO Remove the below return statement. It's a placeholder just to get
	// the starter code to compile.

	if (n == 0) return 1;

	if (n < 0) return 0;

	return ways_to_top(n - 1) + ways_to_top(n - 2) + ways_to_top(n - 3);
}
