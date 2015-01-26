#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long int LL;
LL f[19][201];
int n, inv;

int main()
{
	int i, j, k;

	memset(f, 0, 19 * 201 * sizeof(LL));
	f[1][0] = 1;
	for(i = 2; i <= 18; ++i){
		for(j = 0; f[i - 1][j] > 0; ++j){
			for(k = 0; k <= i - 1 && j + k <= 200; ++k){
				f[i][j + k] += f[i - 1][j];
			}
		}
	}

	while(scanf("%d%d", &n, &inv) == 2 && (n || inv)){
		printf("%lld\n", f[n][inv]);
	}

	return 0;
}
