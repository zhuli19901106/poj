#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

const int MAXN = 510001;
int a[MAXN];
int b[MAXN];
int prime[MAXN];
int pc;
int sprime[MAXN];
int spc;
map<int, int> mm;

int main()
{
	int i, j;
	int hi, hj;
	int n;
	int high, mid, low;
	
	memset(a, 0, MAXN * sizeof(int));
	memset(b, 0, MAXN * sizeof(int));

	a[0] = 1;
	for(i = 1; ; ++i){
		hi = 4 * i + 1;
		if(i > (int)(sqrt((MAXN - 1) * 4.0 + 1) / 4.0 + 1)){
			break;
		}
		if(a[i]){
			continue;
		}

		for(j = i; ; ++j){
			hj = 4 * j + 1;
			if(hi * hj > 4 * (MAXN - 1) + 1){
				break;
			}

			a[((hi * hj) - 1) / 4] = 1;
		}
	}

	pc = 0;
	for(i = 0; i < MAXN; ++i){
		if(!a[i]){
			prime[pc++] = 4 * i + 1;
		}
	}

	spc = 0;
	mm.clear();
	for(i = 0; i < 1005; ++i){
		for(j = i; j < pc && prime[i] * prime[j] <= 1000001; ++j){
			if(mm.find(prime[i] * prime[j]) == mm.end()){
				mm.insert(pair<int, int>(prime[i] * prime[j], spc));
				sprime[spc++] = prime[i] * prime[j];
			}
		}
	}
	sort(sprime, sprime + spc);

	while(scanf("%d", &n) == 1 && n){
		if(n < sprime[0]){
			printf("%d 0\n", n);
		}else if(n >= sprime[spc - 1]){
			printf("%d %d\n", n, sprime[spc - 1]);
		}else{
			high = spc - 1;
			low = 0;
			while(high > low){
				if(n >= sprime[low] && n < sprime[high] && high - low >= 0 && high - low <= 1){
					break;
				}
				mid = (low + high) / 2;
				if(n < sprime[mid]){
					high = mid;
				}else if(n >= sprime[mid]){
					low = mid;
				}
			}

			printf("%d %d\n", n, low + 1);
		}
	}

	return 0;
}
