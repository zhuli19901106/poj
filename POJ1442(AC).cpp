#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

int a[31000];
int u[31000];

struct st_big{
public:
	int x;
	bool operator < (const st_big &a) const
	{
		return x < a.x;
	}
};

struct st_small{
public:
	int x;
	bool operator < (const st_small &a) const
	{
		return x > a.x;
	}
};

//the greater numbers are stored in the minimal heap
priority_queue<st_big> big;
//the smalll numbers are stored in the maximal heap
priority_queue<st_small> small;
int m, n;

int main()
{
	int i, j;
	int c;
	st_big b;
	st_small s;

	while(scanf("%d%d", &m, &n) == 2){
		while(!big.empty()){
			big.pop();
		}
		while(!small.empty()){
			small.pop();
		}
		for(i = 0; i < m; ++i){
			scanf("%d", &a[i]);
		}
		for(i = 0; i < n; ++i){
			scanf("%d", &u[i]);
		}
		j = 0;
		for(i = 0; i < n; ++i){
			while(j < u[i]){
				s.x = a[j];
				small.push(s);
				while(!big.empty() && (s = small.top()).x < (b = big.top()).x){
					c = s.x;
					s.x = b.x;
					b.x = c;
					small.pop();
					big.pop();
					small.push(s);
					big.push(b);
				}
				++j;
			}
			s = small.top();
			printf("%d\n", s.x);
			b.x = s.x;
			small.pop();
			big.push(b);
		}
	}

	return 0;
}
