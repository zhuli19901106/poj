#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int b[1000005];
int a, d, n;

int main()
{
	int i, j;

	memset(b, 0, 1000005 * sizeof(int));
	b[0] = 1;
	b[1] = 1;
	for(i = 2; i * i <= 1000000; ++i){
		if(b[i]){
			continue;
		}
		for(j = i; j <= 1000000 / i; ++j){
			b[i * j] = 1;
		}
	}
	for(i = 0; i <= 1000000; ++i){
		b[i] = !b[i];
	}

	while(scanf("%d%d%d", &a, &d, &n) == 3 && (a || d || n)){
		i = a;
		j = 0;
		while(true){
			if(b[i]){
				++j;
			}
			if(j == n){
				break;
			}else{
				i = i + d;
			}
		}
		printf("%d\n", i);
	}

	return 0;
}

