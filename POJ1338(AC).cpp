#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[1501];
int n;

inline int mymin(const int &a, const int &b, const int &c)
{
	return (a < b ? (a < c ? a : c) : (b < c ? b : c));
}

int main()
{
	int n2, n3, n5;
	int p2, p3, p5;
	int i;

	p2 = p3 = p5 = 1;
	a[1] = 1;
	for(i = 2; i <= 1500; ++i){
		n2 = a[p2] * 2;
		n3 = a[p3] * 3;
		n5 = a[p5] * 5;
		a[i] = mymin(n2, n3, n5);
		if(a[i] == n2){
			++p2;
		}
		if(a[i] == n3){
			++p3;
		}
		if(a[i] == n5){
			++p5;
		}
	}

	while(scanf("%d", &i) == 1 && i){
		printf("%d\n", a[i]);
	}

	return 0;
}

