#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[200];
char t[200];
int a, b, c;

void reverse(char s[])
{
	int i, len;
	char t;

	len = strlen(s);
	i = 0;
	while(i < len - 1 - i){
		t = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = t;
		++i;
	}
}

int main()
{
	int l, r, len;

	while(scanf("%s", s) == 1){
		if(strcmp(s, "0+0=0") == 0){
			printf("True\n");
			break;
		}
		len = strlen(s);

		l = 0;
		r = l;
		while(r < len && s[r] != '+'){
			t[r - l] = s[r];
			++r;
		}
		t[r - l] = 0;
		reverse(t);
		sscanf(t, "%d", &a);

		l = r + 1;
		r = l;
		while(r < len && s[r] != '='){
			t[r - l] = s[r];
			++r;
		}
		t[r - l] = 0;
		reverse(t);
		sscanf(t, "%d", &b);

		l = r + 1;
		r = l;
		while(r < len){
			t[r - l] = s[r];
			++r;
		}
		t[r - l] = 0;
		reverse(t);
		sscanf(t, "%d", &c);

		if(a + b == c){
			printf("True\n");
		}else{
			printf("False\n");
		}
	}

	return 0;
}

