// Program to generate the factorial of a number 'n' iteratively

#include<stdio.h>
int fact(int n);
int main() {
	int n = 5;
	int f = fact(n);
	printf("%d\n", f);
	return 0;
}

int fact(int n) {
	int f = 1;
	if (n == 0) {
		return f;
	}

	while(n>=1) {
		f = f * n;
		n--;
	}
	return f;
}
