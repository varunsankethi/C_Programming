#include<stdio.h>

int power(int x, int n);
int factorial(int n);
int taylorSeries(int x, int n);

int taylorSeries(int x, int n) {
	if (n == 0) {
		return 1;
	} else {
		return 1 + ((power(x,n-1)/factorial(n-1)) + (power(x,n)/factorial(n)));
		 
	}
}

int power(int x, int n) {
	
	if (n == 0 ) {
		return 1;
	}
	return power(x,n-1) * x;
}

int factorial(int n) {
	
	if (n == 0) 
		return 1;
	return factorial(n-1) * n;
}

int main() {
	int n = 3;
	int x = 10;

	int ts = taylorSeries(0,0);
	printf("%d\n", ts);
	return 0;
}
