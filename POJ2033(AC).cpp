#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[50000];
char s[50000];

void reverse(char s[])
{
	int i, len;
	char ch;
	
	len = strlen(s);
	i = 0;
	while(i < len - 1 - i){
		ch = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = ch;
		++i;
	}
}

int main()
{
	int i, tmp;
	int len;
	
	while(scanf("%s", s) == 1){
		if(strcmp(s, "0") == 0){
			break;
		}
		
		len = strlen(s);
		reverse(s);
		
		a[0] = 1;
		if(s[0] != '0'){
			a[1] = 1;
		}else{
			a[1] = 0;
		}
		for(i = 2; i <= len; ++i){
			if(s[i - 1] == '0'){
				a[i] = 0;
			}else{
				tmp = (s[i - 1] - '0') * 10 + (s[i - 2] - '0');
				if(tmp >= 10 && tmp <= 26){
					a[i] = a[i - 1] + a[i - 2];
				}else{
					a[i] = a[i - 1];
				}
			}
		}
		
		printf("%d\n", a[len]);
	}
	
	return 0;
}

