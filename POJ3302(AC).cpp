#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 105;
int f[2][MAXN];
char s1[MAXN], s2[MAXN], len1, len2;

inline const int min(const int &a, const int &b)
{
	return (a < b) ? a : b;
}

inline const int max(const int &a, const int &b)
{
	return (a > b) ? a : b;
}

int main()
{
	int t, ti;
	int i, j;
	int b;

	while(scanf("%d", &t) == 1){
		for(ti = 1; ti <= t; ++ti){
			scanf("%s%s", s1, s2);
			len1 = strlen(s1);
			len2 = strlen(s2);

			memset(f, 0, 2 * MAXN * sizeof(int));
			b = 0;
			for(i = 1; i <= len1; ++i){
				for(j = 1; j <= len2; ++j){
					if(s1[i - 1] == s2[j - 1]){
						f[b][j] = max(f[!b][j - 1] + 1, max(f[!b][j], f[b][j - 1]));
					}else{
						f[b][j] = max(f[!b][j], f[b][j - 1]);
					}
				}
				b = !b;
			}
			b = !b;
			if(f[b][len2] == min(len1, len2)){
				printf("YES\n");
				continue;
			}

			char tch;
			for(i = 0; i < len1 - 1 - i; ++i){
				tch = s1[i];
				s1[i] = s1[len1 - 1 - i];
				s1[len1 - 1 - i] = tch;
			}

			memset(f, 0, 2 * MAXN * sizeof(int));
			b = 0;
			for(i = 1; i <= len1; ++i){
				for(j = 1; j <= len2; ++j){
					if(s1[i - 1] == s2[j - 1]){
						f[b][j] = max(f[!b][j - 1] + 1, max(f[!b][j], f[b][j - 1]));
					}else{
						f[b][j] = max(f[!b][j], f[b][j - 1]);
					}
				}
				b = !b;
			}
			b = !b;
			if(f[b][len2] == min(len1, len2)){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}

	return 0;
}

