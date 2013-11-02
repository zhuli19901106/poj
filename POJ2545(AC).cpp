#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	long long int p1, p2, p3;
	int n;
	int a1, a2, a3;
	long long int m1, m2, m3;
	long long int a[100000];
	long long int min;
	int i;
	
	while(scanf("%lld%lld%lld%d", &p1, &p2, &p3, &n) == 4){
		a[0] = 1;
		a1 = a2 = a3 = 0;
		for(i = 1; i <= n; ++i){
			min = -1;
			m1 = a[a1] * p1;
			m2 = a[a2] * p2;
			m3 = a[a3] * p3;

			if(-1 == min || m1 < min){
				min = m1;
			}
			if(-1 == min || m2 < min){
				min = m2;
			}
			if(-1 == min || m3 < min){
				min = m3;
			}

			if(min == m1){
				++a1;
			}
			if(min == m2){
				++a2;
			}
			if(min == m3){
				++a3;
			}
			a[i] = min;
		}
		printf("%lld\n", a[n]);
	}
	
	return 0;
}

