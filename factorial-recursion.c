// Program to calculate factorial of a number n using recursive method
#include<stdio.h>
int fact(int n);
int main() {
	int n = 5;
    int f =	fact(n);
	printf("%d\n",f);
	return 0;
}

int fact(int n) {
	if (n == 0 ) {

		return 1;
	}
	if (n > 0) {

		return fact(n-1) * n;
	}
}

