// Program to sum up n natural numbers using recursion

#include <stdio.h>

int summation(int n);

int main() {
	int	n = 10;
	int s = summation(10);
	printf("%d\n",s);
	return 0;
}

int summation(int n) {
	if (n >= 1) {
		return summation(n - 1)+n;
	}
	return 0;
}

