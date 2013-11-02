#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char a[1005], b[1005];
int ca[26], cb[26];

int main()
{
	int i, j;

	while(true){
		if(gets(a) == NULL){
			break;
		}else{
			gets(b);
		}
		memset(ca, 0, 26 * sizeof(int));
		memset(cb, 0, 26 * sizeof(int));
		for(i = 0; a[i]; ++i){
			if(a[i] >= 'a' && a[i] <= 'z'){
				++ca[a[i] - 'a'];
			}
		}
		for(i = 0; b[i]; ++i){
			if(b[i] >= 'a' && b[i] <= 'z'){
				++cb[b[i] - 'a'];
			}
		}
		for(i = 0; i < 26; ++i){
			ca[i] = (ca[i] < cb[i] ? ca[i] : cb[i]);
		}
		for(i = 0; i < 26; ++i){
			for(j = 0; j < ca[i]; ++j){
				putchar(i + 'a');
			}
		}
		putchar('\n');
	}

	return 0;
}

