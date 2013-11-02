#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

char a[100005];
int res;
int count;

int main()
{
	int i;
	int m, t, u, f, d;
	char s[10];
	
	while(scanf("%d%d%d%d%d", &m, &t, &u, &f, &d) == 5){
		for(i = 0; i < t; ++i){
			scanf("%s", s);
			a[i] = s[0];
		}
		res = 0;
		count = 0;
		for(i = 0; i < t; ++i){
			if(a[i] == 'u' || a[i] == 'd'){
				res += u + d;
			}else if(a[i] == 'f'){
				res += 2 * f;
			}
			if(res > m){
				break;
			}else{
				++count;
			}
		}
		printf("%d\n", count);
	}

	return 0;
}

