#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 512;
const int b2[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
int ab[513];
int a[MAXN][MAXN];
int n;
vector<int> v, v2;
vector<int> vb[10];

void quad_encode(int top, int left, int scale)
{
	int i, j, val;

	val = a[top][left];
	for(i = top; i < top + scale; ++i){
		for(j = left; j < left + scale; ++j){
			if(a[i][j] != val){
				break;
			}
		}
		if(j < left + scale){
			break;
		}
	}

	if(i == top + scale){
		//all pixel are of the same value;
		vb[ab[scale]].push_back(0);
		vb[ab[scale]].push_back(val);
	}else{
		vb[ab[scale]].push_back(1);
		quad_encode(top, left, scale / 2);
		quad_encode(top, left + scale / 2, scale / 2);
		quad_encode(top + scale / 2, left, scale / 2);
		quad_encode(top + scale / 2, left + scale / 2, scale / 2);
	}
}

int main()
{
	int k, ki;
	int i, j, tmp, len;

	ab[1] = 0;
	ab[2] = 1;
	ab[4] = 2;
	ab[8] = 3;
	ab[16] = 4;
	ab[32] = 5;
	ab[64] = 6;
	ab[128] = 7;
	ab[256] = 8;
	ab[512] = 9;

	while(scanf("%d", &k) == 1){
		for(ki = 0; ki < k; ++ki){
			memset(a, 0, MAXN * MAXN * sizeof(int));
			scanf("%d", &n);
			for(i = 0; i < n; ++i){
				for(j = 0; j < n; ++j){
					scanf("%d", &a[i][j]);
				}
			}

			for(i = 0; i < 10; ++i){
				vb[i].clear();
			}
			quad_encode(0, 0, n);

			v.clear();
			for(i = 9; i >= 0; --i){
				for(j = 0; j < (int)vb[i].size(); ++j){
					v.push_back(vb[i][j]);
				}
				vb[i].clear();
			}

			len = v.size();
			v2.clear();
			j = 0;
			tmp = 0;
			for(i = len - 1; i >= 0; --i){
				tmp += v[i] * b2[j];
				++j;
				if(j == 4){
					v2.push_back(tmp);
					j = tmp = 0;
				}
			}
			v.clear();
			if(j > 0){
				v2.push_back(tmp);
				j = tmp = 0;
			}

			len = v2.size();
			for(i = len - 1; i >= 0; --i){
				printf("%X", v2[i]);
			}
			printf("\n");
			v2.clear();
		}
	}

	return 0;
}

