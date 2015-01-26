#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int idx[30000];
typedef vector<string> vstr;
vector<vstr> vv;
int vc;
map<string, int> mm;
map<string, int> mw;
char t[1000];

bool comparator(const int &a, const int &b)
{
	if(vv[a].size() == vv[b].size()){
		return vv[a][0] < vv[b][0];
	}else{
		return vv[a].size() > vv[b].size();
	}
}

int main()
{
	int i, j, k;
	string str, s;
	map<string, int>::iterator mit;

	ios::sync_with_stdio(false);
	vc = 0;
	mm.clear();
	mw.clear();
	vv.clear();
	while(cin >> s){
		strcpy(t, s.data());
		sort(t, t + strlen(t));
		str = string(t);
		mit = mm.find(str);
		if(mit != mm.end()){
			vv[mit->second].push_back(s);
		}else{
			vv.push_back(vstr());
			mm[str] = vc++;
			vv[vc - 1].push_back(s);
		}
	}
	for(i = 0; i < vc; ++i){
		idx[i] = i;
		sort(vv[i].begin(), vv[i].end());
	}
	sort(idx, idx + vc, comparator);

	if(vc > 5){
		vc = 5;
	}
	for(i = 0; i < vc; ++i){
		cout << "Group of size " << vv[idx[i]].size() << ": ";
		j = 0;
		while(j < (int)vv[idx[i]].size()){
			k = j + 1;
			cout << vv[idx[i]][j] << " ";
			while(k < (int)vv[idx[i]].size() && vv[idx[i]][j] == vv[idx[i]][k]){
				++k;
			}
			j = k;
		}
		cout << "." << endl;
	}

	return 0;
}
