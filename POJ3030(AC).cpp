#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main()
{
	int r, e, c;
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d%d%d", &r, &e, &c);
			if(r > e - c){
				printf("do not advertise\n");
			}else if(r == e - c){
				printf("does not matter\n");
			}else{
				printf("advertise\n");
			}
		}
	}

	return 0;
}

