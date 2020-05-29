#include <stdio.h>
int power(int m, int n);
int power(int m, int n) {
	if (n == 0) 
		return 1;
	return power(m,n-1)*m;
}

int main() {
	int m = 5;
	int n = 2;
	
	int powval = power(n,m);
	printf("%d\n", powval);
}
