#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

double f[105][10];
int n, k;
double tot, sum;
//high-precision is not necessary, as we could use double to calculate the fraction.

int main()
{
	int i, j;

	while(scanf("%d%d", &k, &n) == 2){
		tot = 1;
		for(i = 0; i < n; ++i){
			tot *= (k + 1);
		}

		memset(f, 0, 105 * 10 * sizeof(double));
		for(j = 0; j <= k; ++j){
			f[0][j] = 1;
		}
		for(i = 1; i < n; ++i){
			for(j = 0; j <= k; ++j){
				if(j == 0){
					f[i][j] += f[i - 1][j];
					f[i][j + 1] += f[i - 1][j];
				}else if(j == k){
					f[i][j - 1] += f[i - 1][j];
					f[i][j] += f[i - 1][j];
				}else{
					f[i][j - 1] += f[i - 1][j];
					f[i][j] += f[i - 1][j];
					f[i][j + 1] += f[i - 1][j];
				}
			}
		}

		sum = 0;
		for(j = 0; j <= k; ++j){
			sum += f[n - 1][j];
		}
		printf("%.5f\n", sum * 100.0 / tot);
	}

	return 0;
}

