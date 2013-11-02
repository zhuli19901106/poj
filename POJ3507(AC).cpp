#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[6];

int main()
{
	int i;

	i = 0;
	while(scanf("%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]) == 6){
		if(!(a[0] || a[1] || a[2] || a[3] || a[4] || a[5])){
			break;
		}
		sort(a, a + 6);
		printf("%g\n", (a[1] + a[2] + a[3] + a[4]) / 4.0);
	}

	return 0;
}

