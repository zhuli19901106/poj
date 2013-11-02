#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long int LL;
LL a[60000];
LL m1[60000];
LL m2[60000];
int n;

int main()
{
	int i;
	int t, ti;
	int maxi, si;
	LL maxs, s;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &n);
			memset(a, 0, 60000 * sizeof(LL));
			memset(m1, 0, 60000 * sizeof(LL));
			memset(m2, 0, 60000 * sizeof(LL));
			for(i = 0; i < n; ++i){
				scanf("%lld", &a[i]);
			}

			maxi = 0;
			for(i = 1; i < n; ++i){
				if(a[i] > a[maxi]){
					maxi = i;
				}
			}
			if(maxi == 0){
				si = 1;
			}else{
				si = 0;
			}
			for(i = 0; i < n; ++i){
				if(i == maxi){
					continue;
				}else if(a[i] > a[si]){
					si = i;
				}
			}
			if(a[maxi] <= 0){
				printf("%lld\n", a[maxi] + a[si]);
				continue;
			}else{
				if(a[si] <= 0){
					printf("%lld\n", a[maxi] + a[si]);
					continue;
				}
			}

			maxs = 0;
			s = 0;
			for(i = 0; i <= n - 1; ++i){
				s += a[i];
				if(s < 0){
					s = 0;
				}
				if(s >= maxs){
					maxs = s;
				}
				m1[i] = maxs;
			}

			maxs = 0;
			s = 0;
			for(i = n - 1; i >= 0; --i){
				s += a[i];
				if(s < 0){
					s = 0;
				}
				if(s >= maxs){
					maxs = s;
				}
				m2[i] = maxs;
			}

			maxs = 0;
			for(i = 0; i < n - 1; ++i){
				if(m1[i] + m2[i + 1] > maxs){
					maxs = m1[i] + m2[i + 1];
				}
			}
			printf("%lld\n", maxs);
		}
	}

	return 0;
}

