#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct st{
	int a;
	int c;
}st;

int n, m;
int a[26][26];
int c[26];
st b[26];

bool check_res()
{
	int b1[26];
	int i;
	int res;

	memset(b1, 0, 26 * sizeof(int));
	res = 0;
	for(i = 0; i < n; ++i){
		if(!b1[b[i].c]){
			b1[b[i].c] = true;
			++res;
		}
	}
	if(res == n){
		return true;
	}else{
		return false;
	}
}

int main()
{
	int i, j, p;
	char s[2000];
	int ia, ib;
	bool known;

	while(scanf("%d%d", &n, &m) == 2 && (n || m)){
		known = false;
		memset(a, 0, 26 * 26 * sizeof(int));
		for(i = 0; i < n; ++i){
			b[i].a = i;
			b[i].c = 0;
		}

		for(i = 1; i <= m; ++i){
			scanf("%s", s);
			if(known){
				continue;
			}
			ia = s[0] - 'A';
			ib = s[2] - 'A';
			if(ia == ib){
				printf("Inconsistency found after %d relations.\n", i);
				known = true;
				continue;
			}
			if(a[ib][ia]){
				printf("Inconsistency found after %d relations.\n", i);
				known = true;
				continue;
			}else{
				a[ia][ib] = 1;
				for(j = 0; j < n; ++j){
					if(a[j][ia]){
						a[j][ib] = 1;
					}
				}

				for(j = 0; j < n; ++j){
					if(a[ib][j]){
						a[ia][j] = 1;
					}
				}

				for(j = 0; j < n; ++j){
					for(p = 0; p < n; ++p){
						if(a[j][ia] && a[ib][p]){
							a[j][p] = 1;
						}
					}
				}

				for(j = 0; j < n; ++j){
					b[j].c = 0;
					for(p = 0; p < n; ++p){
						if(a[j][p]){
							++(b[j].c);
						}
					}
				}
			}

			if(check_res()){
				printf("Sorted sequence determined after %d relations: ", i);
				for(j = 0; j < n; ++j){
					c[n - 1 - b[j].c] = b[j].a;
				}
				for(j = 0; j < n; ++j){
					printf("%c", c[j] + 'A');
				}
				printf(".\n");
				known = true;
				continue;
			}
		}

		if(!known){
			printf("Sorted sequence cannot be determined.\n");
		}
	}

	return 0;
}

