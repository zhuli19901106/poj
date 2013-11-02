#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct st{
	int x, y;
}st;
st a[800];
int n;

class st_res{
public:
	int i;
	int j;
	int k;

	st_res(int i, int j, int k)
	{
		this->i = i;
		this->j = j;
		this->k = k;
	}
};
vector<st_res> v_res;

bool comparator(const st &a, const st &b)
{
	if(a.x == b.x){
		return a.y < b.y;
	}else{
		return a.x < b.x;
	}
}

int main()
{
	int i, j, k;
	
	while(scanf("%d", &n) == 1){
		for(i = 1; i <= n; ++i){
			scanf("%d%d", &a[i].x, &a[i].y);
		}
		//sort(a + 1, a + n + 1, comparator);
		
		v_res.clear();
		for(i = 1; i <= n; ++i){
			for(j = i + 1; j <= n; ++j){
				for(k = j + 1; k <= n; ++k){
					if((a[i].x - a[j].x) * (a[j].y - a[k].y) == (a[i].y - a[j].y) * (a[j].x - a[k].x)){
						v_res.push_back(st_res(i, j, k));
					}
				}
			}
		}

		printf("%d\n", (int)v_res.size());
		for(i = 0; i < (int)v_res.size(); ++i){
			printf("%d %d %d\n", v_res[i].i, v_res[i].j, v_res[i].k);
		}
	}

	return 0;
}

