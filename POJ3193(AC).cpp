#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

vector<string> vp;
vector<string> vm;
int m, n;
int res;

int my_bsearch(vector<string> &v, string key)
{
	int left, right, mid;

	if(v.size() == 0 || key > v[v.size() - 1]){
		return -1;
	}

	if(key <= v[0]){
		return 0;
	}

	left = 0;
	right = v.size() - 1;
	while(right - left > 1){
		mid = (left + right) / 2;
		if(key > v[mid]){
			left = mid;
		}else{
			right = mid;
		}
	}

	return right;
}

int main()
{
	int i, j;
	char str[100];

	while(gets(str) != NULL && sscanf(str, "%d%d", &m, &n)){
		vp.clear();
		vm.clear();
		for(i = 0; i < m; ++i){
			gets(str);
			vp.push_back(string(str));
		}

		sort(vp.begin(), vp.end());
		for(i = 0; i < n; ++i){
			gets(str);
			vm.push_back(string(str));
		}

		res = 0;
		for(i = 0; i < n; ++i){
			j = my_bsearch(vp, vm[i]);
			if(j < 0){
				continue;
			}
			if(vm[i].length() <= vp[j].length() && vp[j].substr(0, vm[i].length()) == vm[i]){
				++res;
			}
		}

		printf("%d\n", res);
	}

	return 0;
}

