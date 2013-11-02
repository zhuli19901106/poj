#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 800;
int f[MAXN];
int res[367][10];
/*
void print_digit(const int f[], int maxn)
{
	int i;

	i = maxn - 1;
	while(i >= 0 && !f[i]){
		--i;
	}
	if(i >= 0){
		while(i >= 0){
			printf("%d", f[i]);
			--i;
		}
	}else{
		printf("0");
	}
}
*/
int main()
{
	int n;
	int i;
	int j;

	memset(f, 0, MAXN * sizeof(int));
	f[0] = 1;
	res[0][1] = 1;
	for(n = 1; n <= 366; ++n){
		i = MAXN - 1;
		while(i >= 0 && !f[i]){
			--i;
		}
		while(i >= 0){
			if(f[i]){
				f[i] *= n;
			}
			--i;
		}

		for(i = 0; i < MAXN - 1; ++i){
			f[i + 1] += f[i] / 10;
			f[i] %= 10;
		}
		f[MAXN - 1] %= 10;

		i = MAXN - 1;
		while(i >= 0 && !f[i]){
			--i;
		}
		for(j = 0; j < 10; ++j){
			res[n][j] = 0;
		}
		if(i >= 0){
			while(i >= 0){
				++res[n][f[i]];
				--i;
			}
		}else{
			++res[n][0];
		}
		/*
		print_digit(f, MAXN);
		printf("\n");
		*/
	}

	while(scanf("%d", &n) == 1 && n){
		printf("%d! --\n", n);
		for(i = 0; i < 10; ++i){
			if(i == 0 || i == 5){
				printf("   (%1d)", i);
			}else{
				printf("    (%1d)", i);
			}
			printf("%5d", res[n][i]);
			if(i == 4 || i == 9){
				printf("\n");
			}
		}
	}
	return 0;
}

