#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int a, b;
int sl, sr;

int main()
{
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 1; ti <= t; ++ti){
			scanf("%d%d", &a, &b);
			sl = sr = 0;
			while(a > 1 && b > 1){
				if(a > b){
					sl += a / b;
					a = a % b;
				}else if(a < b){
					sr += b / a;
					b = b % a;
				}
			}
			if(a > 1){
				sl += a - 1;
				a = 1;
			}else if(b > 1){
				sr += b - 1;
				b = 1;
			}

			printf("Scenario #%d:\n", ti);
			printf("%d %d\n\n", sl, sr);
		}
	}

	return 0;
}

