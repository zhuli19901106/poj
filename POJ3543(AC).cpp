#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int b, w;
	int i;
	int x, y;

	while(scanf("%d%d", &b, &w) == 2){
		i = 1;
		while(true){
			if(i % 2){
				x = (i * i - 1) / 2;
				y = (i * i + 1) / 2;
			}else{
				x = y = i * i / 2;
			}

			if((b >= x && w >= y) || (b >= y && w >= x)){
				++i;
				continue;
			}else{
				break;
			}
		}
		--i;
		if(i > 0){
			printf("%d\n", i);
		}else{
			printf("Impossible\n");
		}
	}

	return 0;
}

