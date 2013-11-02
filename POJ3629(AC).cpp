#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int n, m, k, p;
int b[100005], bc;
vector<int> res;

int main()
{
	int i;
	int pi, ci;

	while(scanf("%d%d%d", &n, &k, &p) == 3){
		m = k / n;
		memset(b, 0, k * sizeof(int));
		bc = k;
		res.clear();
		pi = 1;
		ci = 1;
		while(bc > 0){
			b[ci] = 1;
			--bc;
			++pi;
			if(pi > n){
				res.push_back(ci);
				pi = 1;
			}
			if(bc <= 0){
				break;
			}

			do{
				++ci;
				if(ci > k){
					ci = 1;
				}
			}while(b[ci]);
			for(i = 0; i < p; ++i){
				do{
					++ci;
					if(ci > k){
						ci = 1;
					}
				}while(b[ci]);
			}
		}
		sort(res.begin(), res.end());
		for(i = 0; i < (int)res.size(); ++i){
			printf("%d\n", res[i]);
		}
	}

	return 0;
}

