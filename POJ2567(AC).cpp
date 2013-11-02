#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 51;
int b[MAXN];
vector<int> v[MAXN];
int a[MAXN][MAXN];
int sp;
int st[MAXN];
int n;

typedef struct dj{
	int p;
	int c;
}dj;
dj p[MAXN];

void construct_tree(int r)
{
	int i;

	for(i = 1; i <= n; ++i){
		if(a[r][i] && !b[i]){
			v[r].push_back(i);
			p[i].p = r;
			++(p[r].c);
			b[i] = 1;
			construct_tree(i);
		}
	}
}

int main()
{
	char s[1000];
	int cur;
	int i, j;

	while(gets(s) != NULL){
		for(i = 0; i < MAXN; ++i){
			v[i].clear();
			p[i].p = i;
			p[i].c = 0;
		}
		memset(a, 0, MAXN * MAXN * sizeof(int));
		sp = n = i = 0;
		while(true){
			if(!s[i]){
				break;
			}else if(s[i] == '('){
				++i;
				sscanf(s + i, "%d", &cur);
				if(cur > n){
					n = cur;
				}
				st[sp++] = cur;
				if(sp > 1){
					a[st[sp - 2]][st[sp - 1]] = a[st[sp - 1]][st[sp - 2]] = 1;
				}
				while(s[i] >= '0' && s[i] <= '9'){
					++i;
				}
			}else if(s[i] == ' '){
				++i;
			}else if(s[i] == ')'){
				--sp;
				if(sp == 0){
					break;
				}
				++i;
			}else{
				++i;
			}
		}

		memset(b, 0, MAXN * sizeof(int));
		b[n] = 1;
		construct_tree(n);
		/*
		for(i = 1; i <= n; ++i){
			printf("%d:", i);
			for(j = 0; j < (int)v[i].size(); ++j){
				printf(" %d", v[i][j]);
			}
			printf("\n");
		}
		*/

		j = 0;
		while(true){
			for(i = 1; i < n; ++i){
				if(p[i].c == 0){
					break;
				}
			}
			if(i == n){
				break;
			}else{
				if(j == 0){
					printf("%d", p[i].p);
				}else{
					printf(" %d", p[i].p);
				}
				--(p[p[i].p].c);
				p[i].c = -1;
				++j;
			}
		}
		printf("\n");
	}

	return 0;
}

