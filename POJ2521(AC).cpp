#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int n, m, p, c;

	while(scanf("%d%d%d%d", &n, &m, &p, &c) == 4 && (n || m || p || c)){
		printf("%d\n", n + p - m);
	}

	return 0;
}
