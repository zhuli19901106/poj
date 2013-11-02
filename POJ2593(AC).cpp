#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 100005;
int a[MAXN];
int s1[MAXN];
int s2[MAXN];
int m1, m2;
int n;

void myswap(int &a, int &b)
{
	int t;

	t = a;
	a = b;
	b = t;
}

int main()
{
	int i, t;
	int sum;

	while(scanf("%d", &n) == 1 && n){
		memset(a, 0, MAXN * sizeof(int));
		memset(s1, 0, MAXN * sizeof(int));
		memset(s2, 0, MAXN * sizeof(int));
		for(i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}

		m1 = a[0];
		m2 = a[1];
		if(m1 < m2){
			myswap(m1, m2);
		}
		for(i = 2; i < n; ++i){
			if(a[i] > m2){
				m2 = a[i];
			}
			if(m1 < m2){
				myswap(m1, m2);
			}
		}

		if(m2 <= 0){
			printf("%d\n", m1 + m2);
			continue;
		}

		if(a[0] > 0){
			s1[0] = a[0];
		}else{
			s1[0] = 0;
		}
		sum = s1[0];
		for(i = 1; i < n; ++i){
			sum = sum + a[i];
			if(sum < 0){
				sum = 0;
			}
			if(sum > s1[i - 1]){
				s1[i] = sum;
			}else{
				s1[i] = s1[i - 1];
			}
		}

		if(a[n - 1] > 0){
			s2[n - 1] = a[n - 1];
		}else{
			s2[n - 1] = 0;
		}
		sum = s2[n - 1];
		for(i = n - 2; i >= 0; --i){
			sum = sum + a[i];
			if(sum < 0){
				sum = 0;
			}
			if(sum > s2[i + 1]){
				s2[i] = sum;
			}else{
				s2[i] = s2[i + 1];
			}
		}
		t = s1[0] + s2[1];
		for(i = 1; i < n - 1; ++i){
			if(s1[i] + s2[i + 1] > t){
				t = s1[i] + s2[i + 1];
			}
		}
		printf("%d\n", t);
	}

	return 0;
}

