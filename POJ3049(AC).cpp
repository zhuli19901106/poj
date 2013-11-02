#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char word[100];
char a[100];
int ac;
int n;
int vow[26] = {
	1, 0, 0, 0, 1, 
	0, 0, 0, 1, 0, 
	0, 0, 0, 0, 1, 
	0, 0, 0, 0, 0, 
	1, 0, 0, 0, 0, 
	0
};

void dfs(int idx, int len, int vc, int cc)
{
	if(len == n){
		if(vc >= 1 && cc >= 2){
			puts(word);
		}
		return;
	}

	if(idx >= ac){
		return;
	}

	int i;
	for(i = idx; i < ac; ++i){
		word[len] = a[i];
		if(vow[a[i] - 'a']){
			dfs(i + 1, len + 1, vc + 1, cc);
		}else{
			dfs(i + 1, len + 1, vc, cc + 1);
		}
		word[len] = 0;
	}
}

int main()
{
	int i;
	char s[100];

	while(scanf("%d%d", &n, &ac) == 2){
		for(i = 0; i < ac; ++i){
			scanf("%s", s);
			a[i] = s[0];
		}
		sort(a, a + ac);
		memset(word, 0, 100 * sizeof(char));
		dfs(0, 0, 0, 0); 
	}

	return 0;
}

