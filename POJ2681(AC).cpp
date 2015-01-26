#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int lena, lenb;
char sa[100], sb[100];
char *a, *b;
int ca[26], cb[26];
int n;

int main()
{
	int ni, i, res;

	gets(sa);
	sscanf(sa, "%d", &n);
	for(ni = 0; ni < n; ++ni){
		gets(sa);
		gets(sb);
		lena = strlen(sa);
		lenb = strlen(sb);
		if(lena > lenb){
			i = lena;
			lena = lenb;
			lenb = i;
			a = sb;
			b = sa;
		}else{
			a = sa;
			b = sb;
		}

		memset(ca, 0, 26 * sizeof(int));
		memset(cb, 0, 26 * sizeof(int));
		for(i = 0; i < lena; ++i){
			++ca[a[i] - 'a'];
		}
		for(i = 0; i < lenb; ++i){
			++cb[b[i] - 'a'];
		}
		for(i = 0; i < 26; ++i){
			ca[i] = ca[i] - cb[i];
			if(ca[i] < 0){
				ca[i] = -ca[i];
			}
		}
		
		res = 0;
		for(i = 0; i < 26; ++i){
			res += ca[i];
		}

		printf("Case #%d:  %d \n", ni + 1, res);
	}

	return 0;
}
