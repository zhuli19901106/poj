#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, k;
int a[10005];
int b[200];
int c[200];
int cc;

int main()
{
	int i, j;
	int tmp;

	while(scanf("%d%d", &n, &k) == 2){
		memset(a, 0, 10005 * sizeof(int));
		j = 1;
		for(i = 1; i <= n; ++i){
			scanf("%d", &tmp);
			if(tmp > 0){
				tmp = tmp % k;
			}else if(tmp < 0){
				tmp = (k - (k - tmp) % k) % k;
			}

			if(tmp > 0){
				a[j++] = tmp % k;
			}
		}
		n = j;
		memset(b, 0, 200 * sizeof(int));
		b[a[1]] = b[k - a[1]] = 1;
		for(i = 2; i <= n; ++i){
			cc = 0;
			for(j = 0; j < k; ++j){
				if(b[j] == i - 1){
					c[cc++] = j;
				}
			}
			for(j = 0; j < cc; ++j){
				b[(c[j] + a[i]) % k] = i;
				b[(c[j] + k - a[i]) % k] = i;
			}
		}

		if(b[0] == n){
			printf("Divisible\n");
		}else{
			printf("Not divisible\n");
		}
	}

	return 0;
}

