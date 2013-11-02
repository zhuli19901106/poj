#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

double p[16][16];
double f[4][16];
char s[16][16];

int main()
{
	int i, j, k;
	int tmp;

	while(true){
		memset(s, 0, 16 * 16 * sizeof(char));
		for(i = 0; i < 16; ++i){
			if(scanf("%s", s[i]) != 1){
				break;
			}
		}
		if(i < 16){
			break;
		}

		memset(p, 0, 16 * 16 * sizeof(double));
		memset(f, 0, 4 * 16 * sizeof(double));

		for(i = 0; i < 16; ++i){
			for(j = 0; j < 16; ++j){
				scanf("%lf", &p[i][j]);
				p[i][j] /= 100.0;
			}
		}

		for(i = 0; i < 16; ++i){
			if(i % 2){
				f[0][i] = p[i][i - 1];
			}else{
				f[0][i] = p[i][i + 1];
			}
		}

		tmp = 2;
		for(k = 1; k < 4; ++k){
			for(i = 0; i < 16; ++i){
				if(i / tmp % 2){
					f[k][i] = 0;
					for(j = i / tmp * tmp - tmp; j < i / tmp * tmp; ++j){
						f[k][i] += (f[k - 1][j] * p[i][j]);
					}
					f[k][i] *= f[k - 1][i];
				}else{
					f[k][i] = 0;
					for(j = i / tmp * tmp + tmp; j < i / tmp * tmp + 2 * tmp; ++j){
						f[k][i] += (f[k - 1][j] * p[i][j]);
					}
					f[k][i] *= f[k - 1][i];
				}
			}
			tmp *= 2;
		}

		for(i = 0; i < 16; ++i){
			printf("%-10s p=%.2f%%\n", s[i], f[3][i] * 100.0);
		}
	}

	return 0;
}

