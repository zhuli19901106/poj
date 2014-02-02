#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int b[15005];
int p[5000];
int pc;

int main()
{
	int i, j;
	int n;

	memset(b, 0, 15005 * sizeof(int));
	b[0] = b[1] = 1;
	for(i = 2; i * i <= 15000; ++i){
		if(b[i]){
			continue;
		}
		for(j = i; i * j <= 15000; ++j){
			b[i * j] = 1;
		}
	}

	pc = 0;
	for(i = 0; i <= 15000; ++i){
		b[i] = !b[i];
		if(b[i]){
			p[pc++] = i;
		}
	}

	memset(b, 0, 15005 * sizeof(int));
	for(i = 0; i < pc; ++i){
		j = i;
		n = 0;
		while(true){
			n += p[j];
			++j;
			if(n > 15000){
				break;
			}else{
				++b[n];
			}
		}
	}

	while(scanf("%d", &n) == 1 && n){
		if (n < 2 || n > 15000) {
			continue;
		}
		printf("%d\n", b[n]);
	}

	return 0;
}
