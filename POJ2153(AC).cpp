#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;

typedef struct st{
	string name;
	int score;
	int rank;
}st;
st a[10005];
int idx[10005];
int n, m;
map<string, int> mm;
map<string, int>::iterator mit;
char s[1000];
int ires;

bool comparator(const int &x, const int &y)
{
	return a[x].score > a[y].score;
}

int main()
{
	int i, j, k;
	int sc, r;
	string str;

	while(gets(s) != NULL && sscanf(s, "%d", &n) == 1){
		mm.clear();
		for(i = 0; i < n; ++i){
			gets(s);
			a[i].name = string(s);
			a[i].score = 0;
			a[i].rank = -1;
			mm[a[i].name] = i;
			if(a[i].name == "Li Ming"){
				ires = i;
			}
		}
		gets(s), sscanf(s, "%d", &m);
		for(i = 0; i < m; ++i){
			for(j = 0; j < n; ++j){
				gets(s);
				sscanf(s, "%d", &sc);
				k = 0;
				while(s[k] && s[k] != ' '){
					++k;
				}
				while(s[k] && s[k] == ' '){
					++k;
				}
				str = string(s + k);
				mit = mm.find(str);
				if(mit != mm.end()){
					a[mit->second].score += sc;
				}
			}

			for(j = 0; j < n; ++j){
				idx[j] = j;
			}
			sort(idx, idx + n, comparator);
			j = 0;
			r = 1;
			while(true){
				if(j >= n){
					break;
				}else{
					k = j;
					while(k < n && a[idx[k]].score == a[idx[j]].score){
						a[idx[k]].rank = r;
						++k;
					}
					r += k - j;
					j = k;
				}
			}
			printf("%d\n", a[ires].rank);
		}
	}

	return 0;
}
