#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int sieve[50000];
int prime[50000];
int pc;
long long int f[1000];
int r[1000];
int frc;

int gcd(int a, int b)
{
	if(a == 0 || b == 0){
		return -1;
	}
	if(a < 0){
		return -gcd(-a, b);
	}
	if(b < 0){
		return -gcd(a, -b);
	}
	if(a == b){
		return a;
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

int main()
{
	long long int n;
	long long int rt;
	int i;
	int j;
	int p;
	bool neg;
	
	for(i = 0; i < 50000; ++i){
		sieve[i] = 1;
	}
	sieve[0] = 0;
	sieve[1] = 0;
	for(i = 2; i < 50000; ++i){
		if(!sieve[i]){
			continue;
		}else{
			for(j = 2; i * j < 50000; ++j){
				sieve[i * j] = false;
			}
		}
	}
	
	pc = 0;
	for(i = 2; i < 50000; ++i){
		if(sieve[i]){
			prime[pc++] = i;
		}
	}
	
	while(true){
		if(scanf("%lld", &n) != 1){
			break;
		}else if(0 == n){
			break;
		}
		
		if(n < 0){
			neg = true;
			n = -n;
		}else{
			neg = false;
		}
		i = 0;
		frc = 0;
		rt = (long long int)sqrt(1.0 * n);
		while(prime[i] <= rt && i < pc){
			if(n % prime[i] == 0){
				f[frc] = prime[i];
				r[frc] = 0;
				while(n % prime[i] == 0){
					n = n / prime[i];
					++r[frc];
				}
				++frc;
			}else{
				++i;
			}
		}
		
		if(frc == 0){
			printf("1\n");
			continue;
		}
		
		p = r[0];
		for(i = 1; i < frc; ++i){
			p = gcd(p, r[i]);
			if(1 == p){
				break;
			}
		}
		if(neg){
			while(p % 2 == 0){
				p = p / 2;
			}
		}
		
		printf("%d\n", p);
	}
	
	return 0;
}

