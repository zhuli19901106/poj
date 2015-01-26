#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long int LL;
const int MAXB = 1000005;
int b[MAXB];
const int MAXA = 200005;
LL a[MAXA];
int ac;
const int MAXP = 10000;
LL p[MAXP];
int pc;
LL left, right;
LL ri, dist;

inline LL mymax(const LL &a, const LL &b)
{
	return a > b ? a : b;
}

int main()
{
	LL i, j;

	memset(b, 0, MAXB * sizeof(int));
	b[0] = b[1] = 1;
	for(i = 2; i * i < 50000; ++i){
		if(b[i]){
			continue;
		}
		for(j = i; i * j < 50000; ++j){
			b[i * j] = 1;
		}
	}

	memset(p, 0, MAXP * sizeof(LL));
	pc = 0;
	for(i = 0; i < 50000; ++i){
		b[i] = !b[i];
		if(b[i]){
			p[pc++] = i;
		}
	}

	while(scanf("%lld%lld", &left, &right) == 2){
		memset(b, 0, MAXB * sizeof(int));
		if(left == 1){
			b[0] = 1;
		}
		for(i = 0; i < pc; ++i){
			if(p[i] > right / p[i]){
				break;
			}
			for(j = mymax(p[i], (left + p[i] - 1) / p[i]); j <= right / p[i]; ++j){
				b[p[i] * j - left] = 1;
			}
		}

		memset(a, 0, MAXA * sizeof(LL));
		ac = 0;
		for(i = left; i <= right; ++i){
			b[i - left] = !b[i - left];
			if(b[i - left]){
				a[ac++] = i;
			}
		}

		if(ac < 2){
			printf("There are no adjacent primes.\n");
		}else{
			dist = 1073741824;
			ri = -1;
			for(i = 0; i < ac - 1; ++i){
				if(a[i + 1] - a[i] < dist){
					dist = a[i + 1] - a[i];
					ri = i;
				}
			}
			printf("%lld,%lld are closest, ", a[ri], a[ri + 1]);

			dist = -1;
			ri = -1;
			for(i = 0; i < ac - 1; ++i){
				if(a[i + 1] - a[i] > dist){
					dist = a[i + 1] - a[i];
					ri = i;
				}
			}
			printf("%lld,%lld are most distant.\n", a[ri], a[ri + 1]);
		}
	}

	return 0;
}
