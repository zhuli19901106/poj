#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

const int MAXN = 505;
typedef long long int LL;
int n;
LL a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];
LL v[MAXN], r1[MAXN], r2[MAXN], tmp[MAXN];

void generate_rand(LL v[], const int n, const LL upper_bound)
{
	int i;

	srand(unsigned(time(NULL)));
	for(i = 0; i < n; ++i){
		v[i] = rand() % upper_bound + 1;
	}
}

void right_multiply(int n, LL a[][MAXN], LL v[], LL res[])
{
	int i, j;

	for(i = 0; i < n; ++i){
		res[i] = 0;
		for(j = 0; j < n; ++j){
			res[i] += (a[i][j] * v[j]);
		}
	}
}

int main()
{
	int i, j;
	int ti;
	const int time_to_test = 10;

	while(scanf("%d", &n) == 1){
		for(i = 0; i < n; ++i){
			for(j = 0; j < n; ++j){
				scanf("%lld", &a[i][j]);
			}
		}
		for(i = 0; i < n; ++i){
			for(j = 0; j < n; ++j){
				scanf("%lld", &b[i][j]);
			}
		}
		for(i = 0; i < n; ++i){
			for(j = 0; j < n; ++j){
				scanf("%lld", &c[i][j]);
			}
		}

		for(ti = 0; ti < time_to_test; ++ti){
			generate_rand(v, n, 1000);
			right_multiply(n, b, v, tmp);
			right_multiply(n, a, tmp, r1);
			right_multiply(n, c, v, r2);
			for(i = 0; i < n; ++i){
				if(r1[i] != r2[i]){
					break;
				}
			}
			if(i != n){
				break;
			}
		}
		if(ti == time_to_test){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}

	return 0;
}
