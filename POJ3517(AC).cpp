#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int f[10001];
int n, k, m;

int main()
{
	int i;

	ios::sync_with_stdio(false);

	memset(f, 0, 10001 * sizeof(int));
	f[1] = 0;

	while(scanf("%d%d%d", &n, &k, &m) == 3 && (n || k || m)){
		for(i = 2; i <= n; ++i){
			f[i] = (f[i - 1] + k) % i;
		}
		printf("%d\n", (f[n] + n + m - k % n) % n + 1);
	}
	
	return 0;
}

