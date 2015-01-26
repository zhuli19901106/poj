#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int b[1000005];
int c[1000005];
int bf[1000005];
int cf[1000005];
int l, u;
int p[100000];
int pc;

int main()
{
	int i, j;

	memset(b, 0, 1000005 * sizeof(int));
	b[0] = b[1] = 1;
	for(i = 2; i * i < 1000005; ++i){
		if(b[i]){
			continue;
		}
		for(j = i; i * j < 1000005; ++j){
			b[i * j] = 1;
		}
	}
	pc = 0;
	memset(c, 0, 1000005 * sizeof(int));
	b[0] = !b[0];
	c[0] = b[0];
	for(i = 1; i < 1000005; ++i){
		b[i] = !b[i];
		if(b[i]){
			p[pc++] = i;
		}
		c[i] = c[i - 1] + b[i];
	}

	memset(bf, 0, 1000005 * sizeof(int));
	memset(cf, 0, 1000005 * sizeof(int));
	bf[2] = 1;
	for(i = 5; i < 1000005; i += 4){
		if(b[i]){
			bf[i] = 1;
		}
	}
	cf[0] = 0;
	for(i = 1; i < 1000005; ++i){
		cf[i] = cf[i - 1] + bf[i];
	}

	while(scanf("%d%d", &l, &u) == 2 && !(l == -1 && u == -1)){
		if(l <= 1){
			i = 1;
		}else{
			i = l;
		}
		if(u <= 1){
			j = 1;
		}else{
			j = u;
		}
		printf("%d %d %d %d\n", l, u, c[j] - c[i - 1], cf[j] - cf[i - 1]);
	}

	return 0;
}
