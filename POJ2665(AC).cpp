#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int ll, rr;
	int L, M;
	int i;

	while(scanf("%d%d", &L, &M) == 2 && (L || M)){
		++L;
		for(i = 0; i < M; ++i){
			scanf("%d%d", &ll, &rr);
			L -= (rr - ll + 1);
		}

		printf("%d\n", L);
	}

	return 0;
}

