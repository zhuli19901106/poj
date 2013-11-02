#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void swap_char(char &x, char &y)
{
	char t;

	t = x;
	x = y;
	y = t;
}

int main()
{
	char s[1000];
	int i, len;
	int p, q, mq;
	
	while(true){
		if(scanf("%s", s) != 1){
			break;
		}else if(strcmp(s, "#") == 0){
			break;
		}
		len = strlen(s);
		for(i = len - 1; i > 0; --i){
			if(s[i - 1] < s[i]){
				break;
			}
		}
		if(!i){
			printf("No Successor\n");
		}else{
			p = i - 1;
			q = p + 1;
			mq = q;
			while(q < len){
				if(s[q] > s[p] && s[q] < s[mq]){
					mq = q;
				}
				++q;
			}
			--q;
			swap_char(s[p], s[mq]);
			sort(s + p + 1, s + len);
			printf("%s\n", s);
		}
	}
	
	return 0;
}

