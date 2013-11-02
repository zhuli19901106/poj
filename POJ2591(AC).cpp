#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAXN = 10000005;
int a[MAXN];

int mymin(const int &a, const int &b)
{
	return (a < b ? a : b);
}

int main()
{
	int p2, p3;
	int n2, n3;
	int i;

	p2 = 1;
	p3 = 1;
	a[1] = 1;
	for(i = 2; i <= 10000000; ++i){
		n2 = a[p2] * 2 + 1;
		n3 = a[p3] * 3 + 1;
		a[i] = mymin(n2, n3);
		if(a[i] == n2){
			++p2;
		}
		if(a[i] == n3){
			++p3;
		}
	}

	while(scanf("%d", &i) == 1){
		printf("%d\n", a[i]);
	}

	return 0;
}

