#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long int LL;
LL a, b, c, k;
LL gcd;
LL x, y, t;

void ext_gcd(LL a, LL b)
{
    if(b == 0){
		gcd = a;
		x = 1;
		y = 0;
	}else{
		ext_gcd(b, a % b);
		t = x;
		x = y;
		y = t - (a / b) * x;
	}
}

int main()
{
	while(scanf("%lld%lld%lld%lld",&a, &b, &c, &k) == 4 && (a || b || c || k)){
		k = 1LL << k;
		b = b > a ? b - a : b - a + k;
		//The difference
		ext_gcd(c, k);
		
		if(b % gcd == 0){
			t = x * (b / gcd) % k;
			printf("%lld\n", (t + k) % (k / gcd));
		}else{
			printf("FOREVER\n");
		}
	}
	
	return 0;
}

