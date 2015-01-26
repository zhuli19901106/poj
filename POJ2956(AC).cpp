#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[9];
int ac;
int f[1000005], fc;

int main()
{
	int j, n;
	int b[10];

	memset(a, 0, 9 * sizeof(int));
	a[0] = 1;
	fc = 0;
	memset(f, 0, 1000005 * sizeof(int));
	while(true){
		while(true){
			memset(b, 0, 10 * sizeof(int));
			ac = 8;
			while(a[ac] == 0){
				--ac;
			}
			for(j = ac; j >= 0; --j){
				if(b[a[j]]){
					break;
				}else{
					b[a[j]] = 1;
				}
			}
			if(j == -1){
				break;
			}else{
				++a[j];
				n = j - 1;
				for(j = n; j >= 0; --j){
					a[j] = 0;
				}
				for(j = 0; j < 8; ++j){
					a[j + 1] += (a[j] / 10);
					a[j] %= 10;
				}
				a[8] %= 10;
			}
		}

		n = 0;
		for(j = 8; j >= 0; --j){
			n = n * 10 + a[j];
		}
		f[fc++] = n;
		if(fc >= 1000000){
			break;
		}

		++a[0];
		for(j = 0; j < 8; ++j){
			a[j + 1] += (a[j] / 10);
			a[j] %= 10;
		}
		a[8] %= 10;
	}

	j = 0;

	while(scanf("%d", &n) == 1 && n){
		printf("%d\n", f[n - 1]);
	}

	return 0;
}
