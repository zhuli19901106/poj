#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long int LL;
double a[3][3];
double b[3];
double r[4];

void swap(double &a, double &b)
{
	double t;

	t = a;
	a = b;
	b = t;
}

double calc(double a[][3])
{
	return (
		a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - 
		a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + 
		a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0])
		);
}

int main()
{
	int i, j;
	int n, ni;
	double x;

	while(scanf("%d", &n) == 1){
		for(ni = 0; ni < n; ++ni){
			for(i = 0; i < 3; ++i){
				scanf("%lf%lf%lf%lf", &a[i][0], &a[i][1], &a[i][2], &b[i]);
			}
			for(i = 0; i < 3; ++i){
				for(j = 0; j < 3; ++j){
					swap(a[j][i], b[j]);
				}
				r[i] = calc(a);
				for(j = 0; j < 3; ++j){
					swap(a[j][i], b[j]);
				}
			}
			r[3] = calc(a);
			printf("%lld %lld %lld %lld\n", (LL)r[0], (LL)r[1], (LL)r[2], (LL)r[3]);
			if(r[3] == 0.0){
				printf("No unique solution\n\n");
			}else{
				printf("Unique solution:");
				for(i = 0; i < 3; ++i){
					x = r[i] / r[3];
					if(x > -0.0005 && x < +0.0005){
						printf(" 0.000");
					}else{
						printf(" %.3f", x);
					}
				}
				printf("\n\n");
			}
		}
	}
	
	return 0;
}
