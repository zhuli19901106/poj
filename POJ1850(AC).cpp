#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdio>
#include <cstring>
using namespace std;

int f[11][26];

int main()
{
	int i, j, k;
	int len;
	int res;
	char s[20];

	memset(f, 0, 11 * 26 * sizeof(int));
	for(i = 0; i < 26; ++i){
		f[1][i] = 1;
	}
	for(i = 2; i <= 10; ++i){
		for(j = 0; j < 26; ++j){
			f[i][j] = 0;
			for(k = j + 1; k < 26; ++k){
				f[i][j] += f[i - 1][k];
			}
		}
	}

	while(scanf("%s", s) == 1){
		len = strlen(s);
		for(i = 0; i < len - 1; ++i){
			if(s[i] >= s[i + 1]){
				break;
			}
		}
		if(i < len - 1){
			printf("0\n");
			continue;
		}
		res = 1;
		for(i = 0; i < s[0] - 'a'; ++i){
			res += f[len][i];
		}
		for(i = 1; i < len; ++i){
			for(j = s[i - 1] - 'a' + 1; j < s[i] - 'a'; ++j){
				res += f[len - i][j];
			}
		}
		for(i = 1; i < len; ++i){
			for(j = 0; j < 26; ++j){
				res += f[i][j];
			}
		}

		printf("%d\n", res);
	}

	return 0;
}
