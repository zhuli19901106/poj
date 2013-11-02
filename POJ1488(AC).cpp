#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[1005];
bool quote;

int main()
{
	int i;

	quote = false;
	while(gets(s) != NULL){
		for(i = 0; s[i]; ++i){
			if(s[i] == '"'){
				if(quote){
					printf("''");
				}else{
					printf("``");
				}
				quote = !quote;
			}else{
				printf("%c", s[i]);
			}
		}
		printf("\n");
	}

	return 0;
}

