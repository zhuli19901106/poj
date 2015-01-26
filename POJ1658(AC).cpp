#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int a, b, c, d, e;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d%d%d", &a, &b, &c, &d);
			if(a - b == b - c && b - c == c - d){
				e = 2 * d - c;
			}else if(c <= d){
				e = d * (d / c);
			}else{
				e = d / (c / d);
			}
			printf("%d %d %d %d %d\n", a, b, c, d, e);
		}
	}

	return 0;
}
