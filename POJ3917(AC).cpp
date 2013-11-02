#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	char s1[1000], s2[1000];
	int c1, c2;
	int i;

	while(scanf("%s%s", s1, s2) == 2){
		if(strcmp(s1, "E") == 0 && strcmp(s2, "E") == 0){
			break;
		}
		c1 = c2 = 0;
		i = 0;
		while(s1[i] && s2[i]){
			if(s1[i] == 'R' && s2[i] == 'S'){
				++c1;
			}else if(s1[i] == 'S' && s2[i] == 'P'){
				++c1;
			}else if(s1[i] == 'P' && s2[i] == 'R'){
				++c1;
			}else if(s1[i] == 'R' && s2[i] == 'P'){
				++c2;
			}else if(s1[i] == 'P' && s2[i] == 'S'){
				++c2;
			}else if(s1[i] == 'S' && s2[i] == 'R'){
				++c2;
			}

			++i;
		}

		printf("P1: %d\nP2: %d\n", c1, c2);
	}

	return 0;
}

