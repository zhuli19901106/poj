#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[105][105];
int m[105][105];
int n;
int msum;

int max(int a, int b)
{
	return (a > b ? a : b);
}

int main()
{
	int i, j;
	
	while(true){
		if(scanf("%d", &n) != 1){
			break;
		}
		msum = -1;
		for(i = 1; i <= n; ++i){
			for(j = 1; j <= i; ++j){
				scanf("%d", &a[i][j]);
			}
		}
		m[1][1] = a[1][1];
		for(i = 2; i <= n; ++i){
			m[i][1] = m[i - 1][1] + a[i][1];
			m[i][i] = m[i - 1][i - 1] + a[i][i];
		}
		for(i = 3; i <= n; ++i){
			for(j = 2; j <= n - 1; ++j){
				m[i][j] = max(m[i - 1][j - 1], m[i - 1][j]) + a[i][j];
				if(m[i][j] > msum){
					msum = m[i][j];
				}
			}
		}
		
		printf("%d\n", msum);
	}
	
	return 0;
}
