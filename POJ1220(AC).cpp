#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int b1, b2;
const int MAXLEN = 1000;
char s[2000];
int a[MAXLEN];

void fix_format(int a[], int n, int b)
{
	int i;

	if(b <= 0){
		return;
	}
	for(i = 0; i < n - 1; ++i){
		a[i + 1] += a[i] / b;
		a[i] %= b;
	}
	a[n - 1] %= b;
}

int val(const char ch)
{
	if(ch >= '0' && ch <= '9'){
		return ch - '0';
	}else if(ch >= 'A' && ch <= 'Z'){
		return ch - 'A' + 10;
	}else if(ch >= 'a' && ch <= 'z'){
		return ch - 'a' + 36;
	}else{
		return -1;
	}
}

char digit(const int i)
{
	if(i >= 0 && i <= 9){
		return i + '0';
	}else if(i >= 10 && i <= 35){
		return i - 10 + 'A';
	}else if(i >= 36 && i <= 61){
		return i - 36 + 'a';
	}else{
		return 0;
	}
}

int main()
{
	int ti, t;
	int i, j, v;
	char ch;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			memset(a, 0, MAXLEN * sizeof(int));
			scanf("%d%d%s", &b1, &b2, s);
			for(i = 0; s[i]; ++i){
				j = MAXLEN - 1;
				while(j >= 0 && !a[j]){
					--j;
				}
				if(j >= 0){
					while(j >= 0){
						a[j] *= b1;
						--j;
					}
					fix_format(a, MAXLEN, b2);
				}
				v = val(s[i]);
				if(v > 0){
					a[0] += v;
					fix_format(a, MAXLEN, b2);
				}
			}

			printf("%d %s\n", b1, s);
			printf("%d ", b2);
			j = MAXLEN - 1;
			while(j >= 0 && !a[j]){
				--j;
			}
			if(j < 0){
				printf("0\n");
			}else{
				while(j >= 0){
					ch = digit(a[j]);
					if(ch){
						printf("%c", ch);
					}
					--j;
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	return 0;
}

