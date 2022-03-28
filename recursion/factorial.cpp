#include <iostream>


// iterative factorial function
long long fact(size_t n) {
	if (n == 0)
		return 1;
	size_t i = n - 1;
	long long sum = n;
	while (i > 0) {
		sum *= i;
		--i;
	}
	return sum;
}

long long fact2(size_t n) {
	if (n >= 1)
		return n * fact2(n - 1);
	else // n == 0;
		return 1;
}

int main() {
	std::cout << fact2(5) << '\n';
	return 0;
}
