#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long int LL;
LL mypow(LL x, LL y, LL m)
{
	if(y < 0){
		return 0;
	}else if(y == 0){
		return 1;
	}else if(y == 1){
		return x % m;
	}else{
		if(y % 2){
			return ((x % m) * mypow((x * x) % m, y / 2, m)) % m;
		}else{
			return mypow((x * x) % m, y / 2, m) % m;
		}
	}
}

int main()
{
	int z, zi;
	int i;
	int h;
	LL a[45000], b[45000];
	LL m;
	LL sum;
	
	while(true){
		if(scanf("%d", &z) != 1){
			break;
		}
		for(zi = 0; zi < z; ++zi){
			scanf("%lld", &m);
			scanf("%d", &h);
			for(i = 0; i < h; ++i){
				scanf("%lld%lld", &a[i], &b[i]);
				a[i] %= m;
			}
			if(1 == m){
				printf("0\n");
				continue;
			}
			sum = 0;
			for(i = 0; i < h; ++i){
				if(a[i] == 0){
					continue;
				}else if(b[i] == 0){
					sum += 1;
					sum %= m;
					continue;
				}else{
					sum += mypow(a[i], b[i], m);
					sum %= m;
				}
			}
			sum %= m;
			printf("%lld\n", sum);
		}
	}
	
	return 0;
}
