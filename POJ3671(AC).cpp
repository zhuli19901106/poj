#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

const int &min(const int &a, const int &b)
{
	return a < b ? a : b;
}

int main()
{
	const int MAXN = 30005;
	int a[MAXN];
	int n1[MAXN];
	int n2[MAXN];
	int n, i, c;

	while(scanf("%d", &n) == 1){
		for(i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		c = 0;
		for(i = 0; i < n; ++i){
			if(a[i] == 2){
				++c;
			}
			n1[i] = c;
		}
		if(a[0] == 1){
			//1
			n2[0] = 1;
		}else{
			//2 otherwise
			n2[0] = 0;
		}
		for(i = 1; i < n; ++i){
			if(a[i] == 1){
				n2[i] = min(n1[i - 1], n2[i - 1]) + 1;
			}else{
				n2[i] = min(n1[i - 1], n2[i - 1]);
			}
		}

		printf("%d\n", min(n1[n - 1], n2[n - 1]));
	}

	return 0;
}

