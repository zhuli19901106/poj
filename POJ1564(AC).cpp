#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <vector>
using namespace std;

int total;
int a[100];
int ac;
int s[100];
int sp;
map<string, int> m;
vector<string> v;
char str[1000];

void dfs(int index, int sum)
{
	int i;

	if(sum == total){
		string res = "";

		str[0] = 0;
		for(i = 0; i < sp; ++i){
			if(!i){
				sprintf(str + strlen(str), "%d", s[i]);
			}else{
				sprintf(str + strlen(str), "+%d", s[i]);
			}
		}
		res = string(str);
		if(m.find(res) == m.end()){
			m.insert(pair<string, int>(res, v.size()));
			v.push_back(res);
		}
	}else if(index >= ac || sum > total){
		return;
	}else{
		for(i = index; i < ac; ++i){
			s[sp++] = a[i];
			dfs(i + 1, sum + a[i]);
			--sp;
		}
	}
}

bool int_comparator(const int &a, const int &b)
{
	return a > b;
}

int main()
{
	int i;

	while(scanf("%d%d", &total, &ac) == 2 && (total || ac)){
		for(i = 0; i < ac; ++i){
			scanf("%d", &a[i]);
		}
		sort(a, a + ac, int_comparator);
		m.clear();
		v.clear();
		sp = 0;
		dfs(0, 0);

		printf("Sums of %d:\n", total);
		if(v.size()){
			for(i = 0; i < (int)v.size(); ++i){
				printf("%s\n", v[i].data());
			}
		}else{
			printf("NONE\n");
		}
	}

	return 0;
}
