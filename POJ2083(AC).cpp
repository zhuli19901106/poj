#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char a[7][729][730];
int b3[] = {1, 3, 9, 27, 81, 243, 729};

int main()
{
	int base3;
	int i, j;
	int x, y;
	int n;
	
	strcpy(a[0][0], "X");
	
	base3 = 1;
	for(n = 1; n < 7; ++n){
		for(i = 0; i < 3; ++i){
			for(j = 0; j < 3; ++j){
				if((i + j) % 2 == 0){
					for(x = 0; x < base3; ++x){
						for(y = 0; y < base3; ++y){
							a[n][i * base3 + x][j * base3 + y] = a[n - 1][x][y];
						}
					}
				}else{
					for(x = 0; x < base3; ++x){
						for(y = 0; y < base3; ++y){
							a[n][i * base3 + x][j * base3 + y] = ' ';
						}
					}
				}
			}
			a[n][i][j * base3] = 0;
		}
		base3 *= 3;
	}
	
	while(scanf("%d", &n) == 1 && n > 0){
		for(i = 0; i < b3[n - 1]; ++i){
			printf("%s\n", a[n - 1][i]);
		}
		printf("-\n");
	}
	
	return 0;
}
