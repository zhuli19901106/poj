#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1000005;
char sum[MAXN];
int n;

int main()
{
	int i;
	char s[10];
	char tmp;

	if(scanf("%d", &n) == 1){
		getchar();
		memset(sum, 0, MAXN * sizeof(char));
		for(i = 0; i < n; ++i){
			gets(s);
			tmp = (s[0] - '0') + (s[2] - '0');
			sum[i] = tmp;
		}
		for(i = n - 1; i > 0; --i){
			if(sum[i] > 9){
				++sum[i - 1];
				sum[i] -= 10;
			}
			sum[i] = sum[i] + '0';
		}
		sum[0] = sum[0] + '0';

		puts(sum);
	}

	return 0;
}
