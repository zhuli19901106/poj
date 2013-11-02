#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int res[10001];

int main()
{
	int f;
	int n;
	int i;

	memset(res, 0, 10001 * sizeof(int));
	res[0] = 1;
	f = 1;
	for(i = 1; i <= 10000; ++i){
		f = f * i;
		while(f > 0  && f % 10 == 0){
			f = f / 10;
		}
		f = f % 100000;
		res[i] = f % 10;
	}

	while(scanf("%d", &n) == 1){
		printf("%5d -> %d\n", n, res[n]);
	}

	return 0;
}

