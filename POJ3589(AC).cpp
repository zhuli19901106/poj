#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int ca[4];
int cb[4];

int main()
{
	int i, j;
	int t, ti;
	int ra, rb;
	char sa[100], sb[100];

	while(scanf("%d", &t) == 1){
		for(ti = 1; ti <= t; ++ti){
			scanf("%s%s", sa, sb);
			memset(ca, 0, 4 * sizeof(int));
			memset(cb, 0, 4 * sizeof(int));
			ra = rb = 0;
			for(i = 0; i < 4; ++i){
				if(sa[i] == sb[i]){
					++ra;
					ca[i] = 1;
					cb[i] = 1;
				}
			}

			for(i = 0; i < 4; ++i){
				if(ca[i]){
					continue;
				}
				for(j = 0; j < 4; ++j){
					if(cb[j]){
						continue;
					}
					if(i == j){
						continue;
					}
					if(sa[i] == sb[j]){
						++rb;
						ca[i] = 1;
						cb[j] = 1;
					}
				}
			}

			printf("%dA%dB\n", ra, rb);
		}
	}

	return 0;
}

