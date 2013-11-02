#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	char s[105], s1[105], s2[105];
	char a[5][105];
	int n, ni;
	int i, j;
	
	while(gets(s) != NULL){
		sscanf(s, "%d", &n);
		for(ni = 0; ni < n; ++ni){
			gets(s1);
			gets(s2);
			i = 0;
			j = 0;
			while(s1[i] != '<'){
				a[0][j++] = s1[i++];
			}
			++i;
			a[0][j++] = 0;
			j = 0;
			while(s1[i] != '>'){
				a[1][j++] = s1[i++];
			}
			++i;
			a[1][j++] = 0;
			j = 0;
			while(s1[i] != '<'){
				a[2][j++] = s1[i++];
			}
			++i;
			a[2][j++] = 0;
			j = 0;
			while(s1[i] != '>'){
				a[3][j++] = s1[i++];
			}
			++i;
			a[3][j++] = 0;
			j = 0;
			while(s1[i] != 0){
				a[4][j++] = s1[i++];
			}
			++i;
			a[4][j++] = 0;
			printf("%s%s%s%s%s\n", a[0], a[1], a[2], a[3], a[4]);
			s2[strlen(s2) - 3] = 0;
			printf("%s%s%s%s%s\n", s2, a[3], a[2], a[1], a[4]);
		}
	}
	
	return 0;
}

