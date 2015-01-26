#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

long long int a[50];

int main()
{
	int i;
	int t, ti;
	int n;
	
	a[0] = 1;
	a[1] = 2;
	for(i = 2; i < 50; ++i){
		a[i] = a[i - 1] + a[i - 2];
	}
	
	while(scanf("%d", &t) == 1){
		for(ti = 1; ti <= t; ++ti){
			scanf("%d", &n);
			printf("Scenario #%d:\n", ti);
			printf("%lld\n\n", a[n]);
		}
	}
	
	return 0;
}
