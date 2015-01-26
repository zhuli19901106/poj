#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct st{
	int x;
	int y;
}st;

st a[10005];
int n;
int dp[10005];

inline void myswap(int &a, int &b)
{
	int t;

	t = a;
	a = b;
	b = t;
}

inline int mymax(const int &a, const int &b)
{
	return a > b ? a : b;
}

bool comparator(const st &a, const st &b)
{
	if(a.x == b.x){
		return a.y < b.y;
	}else{
		return a.x < b.x;
	}
}

int main()
{
	int i, j;

	while(scanf("%d", &n) == 1){
		if(n == 0){
			printf("*\n");
			break;
		}
		memset(a, 0, 10005 * sizeof(st));
		memset(dp, 0, 10005 * sizeof(int));
		for(i = 0; i < n; ++i){
			scanf("%d%d", &a[i].x, &a[i].y);
			/*
			if(a[i].x > a[i].y){
				myswap(a[i].x, a[i].y);
			}
			*/
		}
		sort(a, a + n, comparator);

		dp[0] = 1;
		for(i = 1; i < n; ++i){
			dp[i] = 1;
			for(j = 0; j < i; ++j){
				if(a[i].x >= a[j].x && a[i].y >= a[j].y){
					dp[i] = mymax(dp[i], dp[j] + 1);
				}
			}
		}

		j = dp[0];
		for(i = 1; i < n; ++i){
			if(dp[i] > j){
				j = dp[i];
			}
		}
		printf("%d\n", j);
	}

	return 0;
}
