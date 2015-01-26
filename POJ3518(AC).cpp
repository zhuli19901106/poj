#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int b[1300000];

int main()
{
	int i, j, n;
	
	memset(b, 0, 1300000 * sizeof(int));
	b[0] = b[1] = 1;
	for(i = 2; i * i < 1300000; ++i){
		if(b[i]){
			continue;
		}
		for(j = i; i * j < 1300000; ++j){
			b[i * j] = 1;
		}
	}

	while(scanf("%d", &n) == 1 && n){
		if(!b[n]){
			printf("0\n");
		}else{
			i = n - 1;
			j = n + 1;
			while(b[i]){
				--i;
			}
			while(b[j]){
				++j;
			}
			printf("%d\n", j - i);
		}
	}

	return 0;
}
