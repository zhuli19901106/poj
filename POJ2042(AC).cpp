#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int dp[40000][4];
const int MAXN = 32768;

int main()
{
	int i, j, k, n;
	
	memset(dp, 0, 40000 * 4 * sizeof(int));
	for(i = 1; i * i <= MAXN; ++i){
		++dp[i * i][0];
		for(j = i; i * i + j * j <= MAXN; ++j){
			++dp[i * i + j * j][1];
			for(k = j; i * i + j * j + k * k <= MAXN; ++k){
				++dp[i * i + j * j + k * k][2];
				for(n = k; i * i + j * j + k * k + n * n <= MAXN; ++n){
					++dp[i * i + j * j + k * k + n * n][3];
				}
			}
		}
	}

	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}else if(0 == n){
			break;
		}

		printf("%d\n", dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3]);
	}
	
	return 0;
}

