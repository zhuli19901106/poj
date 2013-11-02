#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int a, b, c, d;
	int t, ti;

	scanf("%d", &t);
	for(ti = 1; ti <= t; ++ti){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("Scenario #%d:\n", ti);
		printf("%d\n\n", (a + b + c + d) % 2);
	}

	return 0;
}

