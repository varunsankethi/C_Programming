// Program to recursively compute the ncr value ( combination value ) using pascals triangle

#include<stdio.h>

int c(int n, int r);

int c(int n, int r) {

	if (n==r || r == 0) {
		return 1;
	}

	return c(n-1,r-1) + c(n-1,r);
}

int main() {
	int n = 4;
	int r = 2;

	printf("%d\n", c(4,2));
}
