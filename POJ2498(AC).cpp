#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[7];
int f[7] = {9, 3, 7, 9, 3, 7, 9};
char s[100];

int main()
{
	int t, ti;
	int i, j;
	int len;
	int sum;

	while(scanf("%d", &t) == 1){
		for(ti = 1; ti <= t; ++ti){
			scanf("%s", s);
			len = strlen(s);
			memset(a, 0, 7 * sizeof(int));
			j = 0;
			for(i = len - 1; i >= 0; --i){
				if(s[i] == '?'){
					a[j++] = -1;
				}else{
					a[j++] = s[i] - '0';
				}
			}
			sum = 0;
			for(i = 0; i < 7; ++i){
				if(a[i] == -1){
					j = i;
				}else{
					sum += f[i] * a[i];
				}
			}

			for(i = 0; i < 10; ++i){
				if((sum + f[j] * i) % 10 == 0){
					break;
				}
			}
			a[j] = i;

			printf("Scenario #%d:\n", ti);
			for(i = len - 1; i >= 0; --i){
				printf("%d", a[i]);
			}
			printf("\n\n");
		}
	}

	return 0;
}

