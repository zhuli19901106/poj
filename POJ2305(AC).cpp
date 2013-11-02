#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int p[1005];
int lp;
int m[1005];
int lm;
int b;
char s[2000];
char s1[500], s2[500];

int main()
{
	int i, j;
	int l, r;

	while(scanf("%d", &b) == 1 && b){
		memset(p, 0, 1005 * sizeof(int));
		memset(m, 0, 1005 * sizeof(int));
		scanf("%s", s);
		lp = strlen(s);
		for(i = lp - 1; i >= 0; --i){
			p[lp - 1 - i ] = s[i] - '0';
		}

		scanf("%s", s);
		lm = strlen(s);
		for(i = lm - 1; i >= 0; --i){
			m[lm - 1 - i ] = s[i] - '0';
		}

		l = lp - 1;
		while(l >= lm - 1){
			r = l - (lm - 1);
			if(r < 0){
				break;
			}

			j = 0;
			for(i = l; i >= r; --i){
				s1[j++] = p[i] + '0';
			}
			s1[j++] = 0;

			j = 0;
			for(i = lm - 1; i >= 0; --i){
				s2[j++] = m[i] + '0';
			}
			s2[j++] = 0;

			if(strcmp(s1, s2) >= 0){
				//perform the subtraction here
				for(i = r; i <= l; ++i){
					p[i] -= m[i - r];
				}
				for(i = r; i <= l; ++i){
					if(p[i] < 0){
						p[i] += b;
						--p[i + 1];
					}
				}
			}else{
				--r;
				if(r < 0){
					break;
				}

				j = 0;
				for(i = l; i >= r; --i){
					s1[j++] = p[i] + '0';
				}
				s1[j++] = 0;

				j = 0;
				s2[j++] = '0';
				for(i = lm - 1; i >= 0; --i){
					s2[j++] = m[i] + '0';
				}
				s2[j++] = 0;

				if(strcmp(s1, s2) >= 0){
					for(i = r; i <= l - 1; ++i){
						p[i] -= m[i - r];
					}
					for(i = r; i <= l; ++i){
						if(p[i] < 0){
							p[i] += b;
							--p[i + 1];
						}
					}
				}else{
					--l;
				}
			}
		}

		i = 1004;
		while(i >= 0 && !p[i]){
			--i;
		}
		if(i == -1){
			printf("0\n");
		}else{
			while(i >= 0){
				printf("%d", p[i]);
				--i;
			}
			printf("\n");
		}
	}

	return 0;
}

