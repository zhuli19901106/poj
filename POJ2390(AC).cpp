#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

double m, r;
int y;
double sum;

double mypow(double x, int y)
{
	if(y == 0){
		return 1.0;
	}else if(y == 1){
		return x;
	}else  if(y & 1){
		double sum = mypow(x, y / 2);
		return x * sum * sum;
	}else{
		double sum = mypow(x, y / 2);
		return sum * sum;
	}
}

int main()
{
	while(scanf("%lf%lf%d", &r, &m, &y) == 3){
		r = (r + 100.0) / 100.0;
		printf("%d\n", (int)(m * mypow(r, y)));
	}

	return 0;
}

