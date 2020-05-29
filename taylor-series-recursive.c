// Program to compute taylor series using recursion for n terms

#include <stdio.h>

double taylorSeries(int x, int n);

double taylorSeries(int x, int n) {
	static double p = 1; 
	static double f = 1;
	double res;
	if (n == 0) {
		return 1;
	}
	else {
		res =  taylorSeries(x,n-1);
		p = p*x;
		f = f*n;
		return res = res + (p/f); 
	}

}

int main() {
	int x = 3;
	int n = 10;

	double ts = taylorSeries(x,n);
	printf("%lf\n", ts);
	return 0;
}
