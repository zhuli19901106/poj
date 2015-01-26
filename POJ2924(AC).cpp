#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

long long int n, m, tmp;

int main()
{
	int t, ti;

	scanf("%d", &t);
	for(ti = 1; ti <= t; ++ti){
		scanf("%lld%lld", &n, &m);
		if(m < n){
			tmp = n;
			n = m;
			m = tmp;
		}
		printf("Scenario #%d:\n%lld\n\n", ti, (n + m) * (m - n + 1) / 2);
	}

	return 0;
}
