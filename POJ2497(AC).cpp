#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int p[30];
int b[30];
int pc;
int sc, score, st;
int ct;

int main()
{
	int t, ti;
	int i;

	while(scanf("%d", &t) == 1){
		for(ti = 1; ti <= t; ++ti){
			scanf("%d%d", &ct, &pc);
			memset(p, 0, 30 * sizeof(int));
			for(i = 0; i < pc; ++i){
				scanf("%d", &p[i]);
			}
			sort(p, p + pc);
			b[0] = p[0];
			for(i = 1; i < pc; ++i){
				b[i] = b[i - 1] + p[i];
			}
			sc = 0;
			score = 0;
			for(i = 0; i < pc; ++i){
				if(b[i] <= ct){
					score += b[i];
					++sc;
				}
			}

			printf("Scenario #%d:\n", ti);
			printf("Steve wins with %d solved problems and a score of %d.\n\n", sc, score);
		}
	}

	return 0;
}
