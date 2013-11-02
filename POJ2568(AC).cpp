#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 51;
int a[MAXN], c[MAXN];
int n;
vector<int> v[MAXN];

void print_tree(int r)
{
	int i;

	printf("(%d", r);
	for(i = 0; i < (int)v[r].size(); ++i){
		printf(" ");
		print_tree(v[r][i]);
	}
	printf(")");
}

int main()
{
	int i, j;
	char s[1000];

	while(gets(s) != NULL){
		i = 0;
		n = 1;
		while(true){
			if(!s[i]){
				break;
			}else if(s[i] >= '0' && s[i] <= '9'){
				sscanf(s + i, "%d", &a[n]);
				++n;
				while(s[i] >= '0' && s[i] <= '9'){
					++i;
				}
			}else{
				++i;
			}
		}

		if(n == 1){
			printf("(1)\n");
			continue;
		}

		for(i = 0; i < MAXN; ++i){
			v[i].clear();
			c[i] = 0;
		}
		for(i = 1; i < n; ++i){
			++c[a[i]];
		}

		for(i = 1; i <= n - 1; ++i){
			for(j = 1; j <= n - 1; ++j){
				if(c[j] == 0){
					v[a[i]].push_back(j);
					--c[a[i]];
					c[j] = -1;
					break;
				}
			}
		}

		for(i = 1; i <= n; ++i){
			sort(v[i].begin(), v[i].end());
		}
		print_tree(n);
		printf("\n");
	}

	return 0;
}

