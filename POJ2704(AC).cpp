#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
int a[50][50];
long long int f[50][50];

int main()
{
	int i, j, x, y;
	char s[1000];

	while(scanf("%d", &n) == 1 && n != -1){
		memset(a, 0, 50 * 50 * sizeof(int));
		memset(f, 0, 50 * 50 * sizeof(long long int));
		for(i = 0; i < n; ++i){
			scanf("%s", s);
			for(j = 0; j < n; ++j){
				a[i][j] = s[j] - '0';
			}
		}

		f[0][0] = 1;
		for(i = 0; i < n; ++i){
			for(j = 0; j < n; ++j){
				if(a[i][j] > 0){
					x = i + a[i][j];
					y = j;
					if(x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1){
						f[x][y] += f[i][j];
					}

					x = i;
					y = j + a[i][j];
					if(x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1){
						f[x][y] += f[i][j];
					}
				}
			}
		}

		printf("%lld\n", f[n - 1][n - 1]);
	}

	return 0;
}
