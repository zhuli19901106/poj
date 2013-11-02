#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[105];
int f[105][105];
int len;

int main()
{
	int i, j, k;

	while(gets(s) != NULL){
		if(strcmp(s, "end") == 0){
			break;
		}

		len = strlen(s);
		if(len == 0){
			printf("0\n");
			continue;
		}
		memset(f, 0, 105 * 105 * sizeof(int));
		for(i = 0; i < len - 1; ++i){
			if(s[i] == '(' && s[i + 1] == ')'){
				f[i][i + 1] = 2;
			}else if(s[i] == '[' && s[i + 1] == ']'){
				f[i][i + 1] = 2;
			}
		}

		for(j = 2; j <= len - 1; ++j){
			for(i = 0; i + j <= len - 1; ++i){
				if((s[i] == '(' && s[i + j] == ')') || (s[i] == '[' && s[i + j] == ']')){
					f[i][i + j] = f[i + 1][i + j - 1] + 2;
				}
				for(k = i; k < i + j; ++k){
					if(f[i][i + j] < f[i][k] + f[k + 1][i + j]){
						f[i][i + j] = f[i][k] + f[k + 1][i + j];
					}
				}
			}
		}
		/*
		for(i = 0; i < len; ++i){
			for(j = 0; j < len; ++j){
				if(i <= j){
					printf("%4d", f[i][j]);
				}else{
					printf("    ");
				}
			}
			printf("\n");
		}
		*/
		printf("%d\n", f[0][len - 1]);
	}

	return 0;
}

