#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct{
	int a[6];
}st;
int n;
vector<st> v;

bool comparator(st &x, st &y)
{
	int i;

	for(i = 0; i < 5; ++i){
		if(x.a[i] < y.a[i]){
			return true;
		}else if(x.a[i] > y.a[i]){
			return false;
		}
	}

	return x.a[i] < y.a[i];
}

int main()
{
	int i, j;

	while(scanf("%d", &n) == 1){
		v.clear();
		for(i = 0; i < n; ++i){
			v.push_back(st());
			for(j = 0; j < 6; ++j){
				scanf("%d", &v[i].a[j]);
			}
		}
		for(i = 0; i < n; ++i){
			sort(v[i].a, v[i].a + 6);
		}
		sort(v.begin(), v.end(), comparator);

		for(i = 0; i < n - 1; ++i){
			for(j = 0; j < 6; ++j){
				if(v[i].a[j] != v[i + 1].a[j]){
					break;
				}
			}
			if(j == 6){
				break;
			}
		}
		if(i == n - 1){
			printf("No two snowflakes are alike.\n");
		}else{
			printf("Twin snowflakes found.\n");
		}
	}

	return 0;
}

