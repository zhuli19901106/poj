#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;

int a[10];
int m[10][10];
vector<int> vv;
map<int, int> mm;
const int dir[4][2] = {
	{-1, 0}, {+1, 0}, {0, -1}, {0, +1}
};

void dfs(int number, int x, int y, int len)
{
	int i;
	int x1, y1;

	if(len == 6){
		if(mm.find(number) == mm.end()){
			mm[number] = 1;
			vv.push_back(number);
			//printf("%06d\n", number);
		}
		return;
	}
	
	for(i = 0; i < 4; ++i){
		x1 = x + dir[i][0];
		y1 = y + dir[i][1];
		if(x1 < 1 || x1 > 5 || y1 < 1 || y1 > 5){
			continue;
		}
		dfs(number * 10 + m[x][y], x1, y1, len + 1);
	}
}

int main()
{
	int i, j;

	for(i = 1; i <= 5; ++i){
		for(j = 1; j <= 5; ++j){
			scanf("%d", &m[i][j]);
		}
	}
	
	mm.clear();
	vv.clear();
	
	for(i = 1; i <= 5; ++i){
		for(j = 1; j <= 5; ++j){
			dfs(0, i, j, 0);
		}
	}

	printf("%d\n", (int)vv.size());
	mm.clear();
	vv.clear();

	return 0;
}

