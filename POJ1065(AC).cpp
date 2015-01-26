#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct st
{
	int l;
	int w;
};

bool comp(const struct st &sa, const struct st &sb)
{
	if(sa.l == sb.l){
		return sa.w < sb.w;
	}else{
		return sa.l < sb.l;
	}
}

int main()
{
	int case_no, case_count;
	int count, n, res;
	int i, j, k;
	int visited[10000];
	struct st a[10000];
	
	scanf("%d", &case_count);
	for(case_no = 0; case_no < case_count; ++case_no){
		scanf("%d", &n);
		memset(a, 0, 10000 * sizeof(struct st));
		for(i = 0; i < n; ++i){
			scanf("%d%d", &a[i].l, &a[i].w);
		}
		sort(a, a + n, comp);
		count = 0;
		memset(visited, 0, 10000 * sizeof(int));
		res = 0;
		for(i = 0; i < n; ++i){
			if(!visited[i]){
				++res;
				visited[i] = 1;
				k = i;
				for(j = k + 1; j < n; ++j){
					if(!visited[j] && a[k].w <= a[j].w){
						k = j;
						visited[j] = 1;
					}
				}
			}
		}

		printf("%d\n", res);
	}
	
	return 0;
}
