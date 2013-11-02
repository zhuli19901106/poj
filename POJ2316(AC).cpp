#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	char s[20];
	char t[20];
	int d, i;

	if(scanf("%s", s) != 1){
		return 0;
	}
	d = strlen(s);
	for(i = 0; i < d; ++i){
		s[i] -= '0';
	}

	while(scanf("%s", t) == 1){
		for(i = 0; i < d; ++i){
			t[i] -= '0';
		}
		for(i = 0; i < d; ++i){
			s[i] = (s[i] + t[i]) % 10;
		}
	}

	for(i = 0; i < d; ++i){
		s[i] += '0';
	}
	puts(s);

	return 0;
}

