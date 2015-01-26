#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	double  x0, y0;
	double x1, y1, x2, y2;
	int n, i;

	while(scanf("%d", &n) == 1){
		scanf("%lf%lf", &x0, &y0);
		x1 = x0;
		y1 = y0;
		printf("%d", n);
		for(i = 1; i < n; ++i){
			scanf("%lf%lf", &x2, &y2);
			printf(" %f %f", (x1 + x2) * 0.5, (y1 + y2) * 0.5);
			x1 = x2;
			y1 = y2;
		}
		x2 = x0;
		y2 = y0;
		printf(" %f %f", (x1 + x2) * 0.5, (y1 + y2) * 0.5);
		printf("\n");
	}

	return 0;
}
