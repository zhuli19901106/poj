#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, t;
int a[50005];

const int myabs(const int &n)
{
	return (n > 0 ? n : -n);
}

bool comparator(const int &x, const int &y)
{
	return myabs(x) < myabs(y);
}

int main()
{
	int i;
	int tt, p;

	while(scanf("%d%d", &t, &n) == 2){
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		sort(a, a + n, comparator);
		tt = p = 0;
		for(i = 0; i < n; ++i){
			tt += myabs(p - a[i]);
			if(tt > t){
				break;
			}else{
				p = a[i];
			}
		}
		printf("%d\n", i);
	}

	return 0;
}

