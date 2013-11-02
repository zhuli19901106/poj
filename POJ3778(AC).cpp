#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef struct st{
	string name;
	int score;
	bool suc;
	bool checked;
}st;
vector<st> vv;
int suc_count;
int n;

bool score_comparator(const st &a, const st &b)
{
	return a.score < b.score;
}

bool name_comparator(const st &a, const st &b)
{
	return a.name < b.name;
}

int bin_search(int key)
{
	int high, mid, low;

	low = 0;
	high = (int)vv.size();
	while(low <= high){
		mid = (low + high) / 2;
		if(key < vv[mid].score){
			high = mid - 1;
		}else if(key > vv[mid].score){
			low = mid + 1;
		}else{
			return mid;
		}
	}

	return -1;
}

void dfs(int sum, int count)
{
	int i;

	if(sum > vv[vv.size() - 1].score){
		return;
	}

	if(count == 2){
		i = bin_search(sum);
		if(i >= 0 && i < (int)vv.size() && !vv[i].checked){
			if(!vv[i].suc){
				++suc_count;
			}
			vv[i].suc = true;
		}
	}

	if(count == 3){
		i = bin_search(sum);
		if(i >= 0 && i < (int)vv.size() && !vv[i].checked){
			if(!vv[i].suc){
				++suc_count;
			}
			vv[i].suc = true;
		}
		return;
	}

	for(i = 0; i < (int)vv.size(); ++i){
		if(!vv[i].checked){
			vv[i].checked = true;
			dfs(sum + vv[i].score, count + 1);
			vv[i].checked = false;
		}
	}
}

int main()
{
	int t, ti;
	int i, c0;
	st tst;
	
	ios::sync_with_stdio(false);

	while(cin >> t){
		for(ti = 0; ti < t; ++ti){
			cin >> n;
			vv.clear();
			for(i = 0; i < n; ++i){
				cin >> tst.name >> tst.score;
				tst.suc = false;
				tst.checked = false;
				vv.push_back(tst);
			}
			sort(vv.begin(), vv.end(), score_comparator);
			c0 = 0;
			for(n = 0; n < (int)vv.size(); ++n){
				if(vv[n].score == 0){
					++c0;
				}else if(vv[n].score > 0){
					break;
				}
			}

			suc_count = 0;
			
			if(n >= 3){
				for(i = 0; i < n; ++i){
					vv[i].suc = true;
					++suc_count;
				}
			}

			if(c0 > 0){
				for(i = 2; i < (int)vv.size(); ++i){
					if(vv[i].score == vv[i - 1].score){
						if(!vv[i].suc){
							vv[i].suc = true;
							++suc_count;
						}
						if(!vv[i - 1].suc){
							vv[i - 1].suc = true;
							++suc_count;
						}
					}
				}
			}
			
			dfs(0, 0);

			sort(vv.begin(), vv.end(), name_comparator);
			cout << suc_count << endl;
			for(i = 0; i < (int)vv.size(); ++i){
				if(vv[i].suc){
					cout << vv[i].name << endl;
				}
			}
		}
	}
	
	return 0;
}

