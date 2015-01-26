#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int i, j;
int cl, len;
char s[1000005];

int main()
{
	while(gets(s) != NULL){
		if(strcmp(s,".") == 0){
			break;
		}
		for(len = 0; s[len]; ++len){
			;
		}

		cl = 1;
		j = 0;
		for(i = 1; i < len; ++i){
			if(s[i] == s[j]){
				++j;
				if(j == cl){
					j = 0;
				}
			}else{
				cl = i + 1;
				j = 0;
			}
		}
		if(j != 0){
			cl = len;
		}

		printf("%d\n", len / cl);
	}

	return 0;
}
