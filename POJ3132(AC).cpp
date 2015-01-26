#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int isprime[1121];
int prime[1000];
int pc;
int f[1500][15];

int main()
{
	int i, j, k, n;
	
	for(i = 1; i <= 1120; ++i){
		isprime[i] = 1;
	}
	isprime[1] = 0;
	i = 1;
	while(true){
		while(i <= 1120 && !isprime[i]){
			++i;
		}
		if(i > 1120){
			break;
		}else{
			for(j = 2; i * j <= 1120; ++j){
				isprime[i * j] = 0;
			}
			++i;
		}
	}
	
	pc = 0;
	for(i = 1; i <= 1120; ++i){
		if(isprime[i]){
			prime[pc++] = i;
		}
	}
	
	memset(f, 0, 1500 * 15 * sizeof(int));
	f[0][0] = 1;
	for(i = 0; i < pc; ++i){
		for(j = 14; j >= 1; --j){
			for(k = 1120; k >= prime[i]; --k){
				f[k][j] += f[k - prime[i]][j - 1];
			}
		}
	}
	
	while(true){
		if(scanf("%d%d", &n, &k) != 2){
			break;
		}else if(0 == n && 0 == k){
			break;
		}
		
		printf("%d\n", f[n][k]);
	}
	
	return 0;
}
