#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

char s1[100], s2[100];
int sum1, sum2;

int main()
{
	int i;

	while(scanf("%s%s", s1, s2) == 2){
		sum1 = 0;
		for(i = 0; s1[i]; ++i){
			sum1 += (s1[i] - '0');
		}
		sum2 = 0;
		for(i = 0; s2[i]; ++i){
			sum2 += (s2[i] - '0');
		}
		printf("%d\n", sum1 * sum2);
	}

	return 0;
}

