#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long int LL;

LL gcd(LL a, LL b)
{
	if(a < 0){
		return gcd(-a, b);
	}
	if(b < 0){
		return gcd(a, -b);
	}
	
	while(true){
		if(a > b){
			if(a % b == 0){
				return b;
			}else{
				a = a % b;
			}
		}else{
			if(b % a == 0){
				return a;
			}else{
				b = b % a;
			}
		}
	}
}

void ext_gcd(LL a, LL b, LL &m, LL &n)
{
	if(b == 0){
		m = 1;
		n = 0;
		return;
	}
	ext_gcd(b, a % b, m, n);
	LL t;
	t = m;
	m = n;
	n = t - a / b * n;
}

int main()
{
	LL m, n, x, y, l;
	LL a, b, t, c;
	LL k1, k2;
	
	while(scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l) == 5){
		a = n - m;
		b = l;
		c = x - y;
		
		t = gcd(a, b);
		if(c % t){
			printf("Impossible\n");
			continue;
		}
		a /= t;
		b /= t;
		c /= t;
		ext_gcd(a, b, k1, k2);
		t = c * k1 / b;
		k1 = c * k1 - t * b;
		if(k1 < 0){
			k1 = (b - (b - k1) % b) % b;
		}
		printf("%lld\n", k1);
	}
	
	return 0;
}
