#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long int LL;
const int MAXN = 1000005;
LL a[MAXN];
LL b[MAXN];
LL c[MAXN];
LL prime[80000];
int pc;

int main()
{
	int i, j;

	memset(a, 0, MAXN * sizeof(LL));
	a[0] = 0;
	a[1] = 0;
	for(i = 2; i <= 1000000; ++i){
		a[i] = i;
	}

	memset(b, 0, MAXN * sizeof(LL));
	b[0] = b[1] = 1;
	for(i = 2; i * i <= 1000000; ++i){
		if(b[i]){
			continue;
		}
		for(j = i; i * j <= 1000000; ++j){
			b[i * j] = 1;
		}
	}

	pc = 0;
	for(i = 0; i <= 1000000; ++i){
		b[i] = !b[i];
		if(b[i]){
			prime[pc++] = i;
		}
	}

	for(i = 0; i < pc; ++i){
		for(j = 1; prime[i] * j <= 1000000; ++j){
			a[prime[i] * j] = a[prime[i] * j] / prime[i] * (prime[i] - 1);
		}
	}

	memset(c, 0, MAXN * sizeof(LL));
	c[0] = a[0];
	for(i = 1; i <= 1000000; ++i){
		c[i] = c[i - 1] + a[i];
	}

	while(scanf("%d", &i) == 1 && i){
		printf("%lld\n", c[i]);
	}

	return 0;
}
