#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[1000];
char t[1000];
int tc;
int len;

int main()
{
	int i;
	bool cc, jj;

	while(scanf("%s", s) == 1){
		cc = true;
		jj = true;
		len = strlen(s);
		for(i = 0; s[i]; ++i){
			if(s[i] >= 'A' && s[i] <= 'Z'){
				cc = false;
			}else if(s[i] == '_'){
				jj = false;
				if(i > 0 && s[i - 1] == '_'){
					cc = false;
				}
				if(i < len - 1 && s[i + 1] == '_'){
					cc = false;
				}
			}
		}
		if(s[0] == '_' || s[len - 1] == '_'){
			cc = false;
			jj = false;
		}
		if(s[0] >= 'A' && s[0] <= 'Z'){
			jj = false;
		}

		if(!cc && !jj){
			printf("Error!\n");
		}else if(!cc && jj){
			i = 0;
			tc = 0;
			while(s[i]){
				if(s[i] >= 'A' && s[i] <= 'Z'){
					t[tc++] = '_';
					t[tc++] = s[i] - 'A' + 'a';
				}else{
					t[tc++] = s[i];
				}
				++i;
			}
			t[tc] = 0;
			printf("%s\n", t);
		}else if(cc && !jj){
			i = 0;
			tc = 0;
			while(s[i]){
				if(s[i] == '_'){
					if(i < len - 1){
						++i;
					}
					t[tc++] = s[i] - 'a' + 'A';
				}else{
					t[tc++] = s[i];
				}
				++i;
			}
			t[tc] = 0;
			printf("%s\n", t);
		}else{
			printf("%s\n", s);
		}
	}

	return 0;
}
