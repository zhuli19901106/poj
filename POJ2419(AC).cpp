#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;

int p, t;
char a[105][105];
map<string, int> mm;
map<string, int>::iterator mit;

int main()
{
	int i, j;
	int x, y;
	string s;
	int nc;

	scanf("%d%d", &p, &t);
	memset(a, 0, 105 * 105 * sizeof(char));
	while(scanf("%d%d", &x, &y) == 2){
		--x;
		--y;
		a[x][y] = 1;
	}

	mm.clear();
	nc = 0;
	for(i = 0; i < p; ++i){
		for(j = 0; j < t; ++j){
			a[i][j] += '0';
		}
		s = string(a[i]);
		mit = mm.find(s);
		if(mit == mm.end()){
			mm.insert(pair<string, int>(s, 0));
			++nc;
		}
	}
	printf("%d\n", nc);

	return 0;
}

