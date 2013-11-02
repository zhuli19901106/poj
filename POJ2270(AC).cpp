#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[512][512];
int n;

void xbm_encode(int top, int left, int n)
{
	int bc, wc;
	int i, j;

	bc = 0;
	wc = n * n;
	for(i = 0; i < n; ++i){
		for(j = 0; j < n; ++j){
			if(a[top + i][left + j]){
				++bc;
				--wc;
			}
		}
	}

	if(wc == n * n){
		printf("W");
	}else if(bc == n * n){
		printf("B");
	}else{
		printf("Q");
		xbm_encode(top, left, n / 2);
		xbm_encode(top, left + n / 2, n / 2);
		xbm_encode(top + n / 2, left, n / 2);
		xbm_encode(top + n / 2, left + n / 2, n / 2);
	}
}

int vhex(const char ch)
{
	if(ch >= '0' && ch <= '9'){
		return ch - '0';
	}else if(ch >= 'a' && ch <= 'f'){
		return ch - 'a' + 10;
	}else if(ch >= 'A' && ch <= 'F'){
		return ch - 'A' + 10;
	}else{
		return -1;
	}
}

int main()
{
	int i, j, k;
	unsigned char tmp;
	char s[1000];

	//0 for white
	//1 for black
	scanf("%*s%*s%d", &n);
	scanf("%*s%*s%d", &n);
	scanf("%*s%*s%*s%*s%*s");
	memset(a, 0, 512 * 512 * sizeof(int));
	for(i = 0; i < n; ++i){
		for(j = 0; j < n; j += 8){
			scanf("%5s", s);
			tmp = 16 * vhex(s[2]) + vhex(s[3]);
			for(k = 0; k < 8; ++k){
				a[i][j + k] = !!(tmp & (1 << k));
			}
		}
	}
	scanf("%*s");

	printf("%d\n", n);
	xbm_encode(0, 0, n);
	printf("\n");

	return 0;
}

