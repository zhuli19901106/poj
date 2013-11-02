#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
using namespace std;

int p[4][2];
int a1, b1, c1;
int a2, b2, c2;

int main()
{
	int n, ni;
	int i;

	while(scanf("%d", &n) == 1){
		printf("INTERSECTING LINES OUTPUT\n");
		for(ni = 0; ni < n; ++ni){
			for(i = 0; i < 4; ++i){
				scanf("%d%d", &p[i][0], &p[i][1]);
			}
			b1 = -(p[1][0] - p[0][0]);
			a1 = +(p[1][1] - p[0][1]);
			c1 = - a1 * p[0][0] - b1 * p[0][1];
			b2 = -(p[3][0] - p[2][0]);
			a2 = +(p[3][1] - p[2][1]);
			c2 = - a2 * p[2][0] - b2 * p[2][1];

			if(!a1 && b1){
				if(!a2 && b2){
					if(b1 * c2 == b2 * c1){
						printf("LINE\n");
					}else{
						printf("NONE\n");
					}
					continue;
				}else if(a2 && !b2){
					printf("POINT %.2f %.2f\n", -1.0 * c2 / a2, -1.0 * c1 / b1);
					continue;
				}
			}else if(a1 && !b1){
				if(!a2 && b2){
					printf("POINT %.2f %.2f\n", -1.0 * c1 / a1, -1.0 * c2 / b2);
					continue;
				}else if(a2 && !b2){
					if(a1 * c2 == a2 * c1){
						printf("LINE\n");
					}else{
						printf("NONE\n");
					}
					continue;
				}
			}

			if(a1 * b2 == a2 * b1){
				if(a1 * c2 == a2 * c1 && b1 * c2 == b2 * c1){
					printf("LINE\n");
				}else{
					printf("NONE\n");
				}
			}else{
				printf("POINT %.2f %.2f\n", 1.0 * (c2 * b1 - c1 * b2) / (a1 * b2 - a2 * b1), 1.0 * (c2 * a1 - c1 * a2) / (b1 * a2 - b2 * a1));
			}
		}
		printf("END OF OUTPUT\n");
	}

	return 0;
}

