#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long int LL;
LL x, y;
const LL mod = 9901;
int b[50001];
LL p[12000];
int pc;
LL f[100];
LL r[100];
int frc;
LL res;

LL mypow(LL base, LL exp, LL mod)
{
	if(exp == 0){
		return 1 % mod;
	}else if(exp == 1){
		return base % mod;
	}else if(exp % 2){
		LL res = mypow(base, exp / 2, mod) % mod;
		return base * res % mod * res % mod;
	}else{
		LL res = mypow(base, exp / 2, mod) % mod;
		return res * res % mod;
	}
}

LL calc_series(LL base, LL exp, LL mod)
{
	if(exp == 0){
		return 1 % mod;
	}else if(exp % 2){
		LL t1, t2;

		t1 = calc_series(base, (exp - 1) / 2, mod);
		t2 = mypow(base, (exp + 1) / 2, mod);

		return t1 * (1 + t2) % mod;
	}else{
		return (base * calc_series(base, exp - 1, mod) + 1) % mod;
	}
}

int main()
{
	int i, j;

	memset(b, 0, 50001 * sizeof(int));
	b[0] = b[1] = 1;
	for(i = 2; i <= 50000 / i; ++i){
		if(b[i]){
			continue;
		}
		for(j = i; j <= 50000 / i; ++j){
			b[i * j] = 1;
		}
	}

	pc = 0;
	for(i = 0; i <= 50000; ++i){
		b[i] = !b[i];
		if(b[i]){
			p[pc++] = i;
		}
	}

	while(scanf("%lld%lld", &x, &y) == 2){
		if(x == 0 || x == 1){
			printf("%lld\n", x);
			continue;
		}
		if(y == 0){
			printf("1\n");
			continue;
		}

		frc = i = 0;
		while(i < pc && p[i] <= x / p[i]){
			if(x % p[i] == 0){
				f[frc] = p[i];
				r[frc] = 0;
				while(x % p[i] == 0){
					++r[frc];
					x /= p[i];
				}
				++frc;
			}
			++i;
		}
		if(x > 1){
			f[frc] = x;
			r[frc] = 1;
			++frc;
			x = 1;
		}

		for(i = 0; i < frc; ++i){
			r[i] *= y;
		}

		res = 1;
		for(i = 0; i < frc; ++i){
			res = res * calc_series(f[i], r[i], mod) % mod;
		}

		printf("%lld\n", res);
	}

	return 0;
}
