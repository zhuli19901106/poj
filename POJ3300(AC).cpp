#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

double f[20];
double r[20];
int fc, rc;
double d[1000];
int dc;
double maxr;

int main()
{
	int i, j;
	double r1;

	while(scanf("%d", &fc) == 1 && fc){
		scanf("%d", &rc);
		for(i = 0; i < fc; ++i){
			scanf("%lf", &f[i]);
		}
		for(i = 0; i < rc; ++i){
			scanf("%lf", &r[i]);
		}
		dc = 0;
		for(i = 0; i < fc; ++i){
			for(j = 0; j < rc; ++j){
				d[dc++] = f[i] / r[j];
			}
		}
		sort(d, d + dc);
		
		maxr = d[1] / d[0];
		for(i = 1; i < dc - 1; ++i){
			r1 = d[i + 1] / d[i];
			if(r1 > maxr){
				maxr = r1;
			}
		}
		
		printf("%.2f\n", maxr);
	}
	
	return 0;
}
