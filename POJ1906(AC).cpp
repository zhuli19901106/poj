#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 100;
int b3[100][MAXN];
typedef unsigned long long int ULL;

void print_digit(const int a[])
{
	int i;

	i = MAXN - 1;
	while(i >= 0 && a[i] == 0){
		--i;
	}
	if(i == -1){
		printf("0");
	}else{
		while(i >= 0){
			printf("%d", a[i]);
			--i;
		}
	}
}

int main()
{
	int i, j, c;
	ULL n;
	int a[100];

	memset(b3, 0, 100 * MAXN * sizeof(int));
	b3[0][0] = 1;
	for(i = 1; i < 100; ++i){
		for(j = 0; j < MAXN; ++j){
			b3[i][j] = b3[i - 1][j] * 3;
		}
		for(j = 0; j < MAXN - 1; ++j){
			b3[i][j + 1] += b3[i][j] / 10;
			b3[i][j] %= 10;
		}
		b3[i][MAXN - 1] %= 10;
	}

	while(scanf("%llu", &n) == 1 && n){
		memset(a, 0, 100 * sizeof(int));
		i = 0;
		--n;
		c = 0;
		while(n > 0){
			a[i++] = n % 2;
			if(a[i - 1]){
				++c;
			}
			n /= 2;
		}
		if(c){
			printf("{ ");
			for(i = 0; i < 100; ++i){
				if(a[i]){
					print_digit(b3[i]);
					if(c == 1){
						printf(" }\n");
					}else{
						printf(", ");
					}
					--c;
				}
			}
		}else{
			printf("{ }\n");
		}
	}

	return 0;
}
