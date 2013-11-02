#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef struct st{
	int a;
	int b;
	int d;
}st;

bool comparator(const st &a, const st &b)
{
	return a.d > b.d;
}

map<string, int> mm;
vector<st> vv;
int n, r;
int dj[300];
int res;

void myswap(int &a, int &b)
{
	int t;

	t = a;
	a = b;
	b = t;
}

int find_root(int x)
{
	int r, k;

	r = x;
	while(r != dj[r]){
		r = dj[r];
	}

	k = x;
	while(x != r){
		x = dj[x];
		dj[k] = r;
		k = x;
	}

	return r;
}

int main()
{
	int ti;
	int i, cc;
	int ra, rb, ia, ib;
	string sa, sb;
	st mst;
	map<string, int>::iterator mit;

	ti = 0;
	while(cin >> n >> r && (n || r)){
		++ti;
		mm.clear();
		vv.clear();
		cc = 0;
		for(i = 0; i < r; ++i){
			cin >> sa >> sb >> mst.d;
			mit = mm.find(sa);
			if(mit != mm.end()){
				mst.a = mit->second;
			}else{
				mst.a = cc;
				mm[sa] = cc++;
			}
			mit = mm.find(sb);
			if(mit != mm.end()){
				mst.b = mit->second;
			}else{
				mst.b = cc;
				mm[sb] = cc++;
			}

			vv.push_back(mst);
			myswap(mst.a, mst.b);
			vv.push_back(mst);
		}
		sort(vv.begin(), vv.end(), comparator);

		cin >> sa >> sb;
		ia = mm[sa];
		ib = mm[sb];
		for(i = 0; i < n; ++i){
			dj[i] = i;
		}

		res = vv[0].d;
		for(i = 0; i < (int)vv.size(); ++i){
			if(find_root(ia) == find_root(ib)){
				break;
			}

			ra = find_root(vv[i].a);
			rb = find_root(vv[i].b);
			if(ra != rb){
				dj[ra] = rb;
				if(vv[i].d < res){
					res = vv[i].d;
				}
				find_root(vv[i].a);
				find_root(vv[i].b);
			}
		}

		cout << "Scenario #" << ti << "\n" << res << " tons\n" << endl;
		mm.clear();
		vv.clear();
	}

	return 0;
}

