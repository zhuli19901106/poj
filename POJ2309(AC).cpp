#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long int LL;
LL a, b;

int main()
{
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%lld", &a);
			b = a & (-a);
			printf("%lld %lld\n", (a ^ b) + 1, a | (b - 1));
		}
	}

	return 0;
}
