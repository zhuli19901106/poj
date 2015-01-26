#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int b[1005];
int l[1005];
int r[1005];
int heavy[1005];
int light[1005];
vector<int> vl[100], vh[100];
int ueqc;
int n, k;

int main()
{
	int p;
	int i, j;
	char s[1000];
	int res;

	while(scanf("%d%d", &n, &k) == 2){
		memset(b, 0, 1005 * sizeof(int));
		memset(heavy, 0, 1005 * sizeof(int));
		memset(light, 0, 1005 * sizeof(int));
		ueqc = 0;
		for(i = 0; i < k; ++i){
			scanf("%d", &p);
			for(j = 0; j < p; ++j){
				scanf("%d", &l[j]);
			}
			for(j = 0; j < p; ++j){
				scanf("%d", &r[j]);
			}
			scanf("%s", s);
			if(s[0] == '='){
				for(j = 0; j < p; ++j){
					heavy[l[j]] = light[l[j]] = 0;
					b[l[j]] = 1;
					heavy[r[j]] = light[r[j]] = 0;
					b[r[j]] = 1;
				}
			}else if(s[0] == '<'){
				++ueqc;
				vh[ueqc - 1].clear();
				vl[ueqc - 1].clear();
				for(j = 0; j < p; ++j){
					vh[ueqc - 1].push_back(r[j]);
					vl[ueqc - 1].push_back(l[j]);
					if(!b[l[j]]){
						++light[l[j]];
					}
					if(!b[r[j]]){
						++heavy[r[j]];
					}
				}
			}else if(s[0] == '>'){
				++ueqc;
				vh[ueqc - 1].clear();
				vl[ueqc - 1].clear();
				for(j = 0; j < p; ++j){
					vh[ueqc - 1].push_back(l[j]);
					vl[ueqc - 1].push_back(r[j]);
					if(!b[l[j]]){
						++heavy[l[j]];
					}
					if(!b[r[j]]){
						++light[r[j]];
					}
				}
			}
		}

		for(i = 1; i <= n; ++i){
			if(b[i]){
				continue;
			}
			if(heavy[i] > 0 && heavy[i] < ueqc){
				b[i] = 1;
			}else if(light[i] > 0 && light[i] < ueqc){
				b[i] = 1;
			}
		}

		p = 0;
		j = -1;
		for(i = 1; i <= n; ++i){
			if(!b[i]){
				++p;
				j = i;
			}
		}

		if(p == 1 && (j >= 1 && j <= n)){
			printf("%d\n", j);
		}else{
			res = -1;
			for(i = 0; i < ueqc; ++i){
				p = 0;
				for(j = 0; j < (int)vh[i].size(); ++j){
					if(!b[vh[i][j]]){
						res = vh[i][j];
						++p;
					}
				}
				for(j = 0; j < (int)vl[i].size(); ++j){
					if(!b[vl[i][j]]){
						res = vl[i][j];
						++p;
					}
				}

				if(p == 1){
					break;
				}else{
					res = -1;
				}
			}

			if(res >= 1 && res <= n){
				printf("%d\n", res);
			}else{
				printf("0\n");
			}
		}
	}

	return 0;
}
