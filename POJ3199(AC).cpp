#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int f[1000];
int n, d;

int main()
{
	int i, j;

	while(scanf("%d%d", &n, &d) == 2 && (n || d)){
		memset(f, 0, 1000 * sizeof(int));
		f[0] = 1;
		for(i = 0; i < d; ++i){
			for(j = 0; j < 1000; ++j){
				f[j] = f[j] * n;
			}
			for(j = 0; j < 999; ++j){
				f[j + 1] += f[j] / 10;
				f[j] %= 10;
			}
			f[999] %= 10;
		}

		i = 999;
		while(i >= 0 && !f[i]){
			--i;
		}
		if(i == -1){
			printf("0\n");
		}else{
			while(i >= 0){
				printf("%d", f[i]);
				--i;
			}
			printf("\n");
		}
	}

	return 0;
}
