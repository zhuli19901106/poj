#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int sum;
	int t, n, i, tmp;
	char s[1000];

	while(scanf("%d%d", &t, &n) == 2 && t){
		sum = 0;
		for(i = 0; i < t; ++i){
			scanf("%s%d", s, &tmp);
			sum += tmp;
		}
		printf("%d\n", n * 3 - sum);
	}

	return 0;
}
