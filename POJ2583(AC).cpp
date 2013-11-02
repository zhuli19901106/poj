#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	double a, b, c;
	double f0, f1, f2;
	double f3, f4, f5;
	
	while(true){
		if(scanf("%lf%lf%lf", &f0, &f1, &f2) != 3){
			break;
		}
		c = f0;
		b = (4 * (f1 - f0) - (f2 - f0)) / 2;
		a = f1 - b - c;
		f3 = 9 * a + 3 * b + c;
		f4 = 16 * a + 4 * b + c;
		f5 = 25 * a + 5 * b + c;
		printf("%d %d %d\n", (int)f3, (int)f4, (int)f5);
	}
	
	return 0;
}

