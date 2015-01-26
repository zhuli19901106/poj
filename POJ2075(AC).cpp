#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, int> mm;
vector<string> vv;
int *dj;
int n, m;

typedef struct edge{
	int a;
	int b;
	double d;
}Edge;
int ec;
double stock, mincost;
vector<Edge> ve;

bool edge_comparator(const Edge &a, const Edge &b)
{
	if(a.d == b.d){
		if(a.a == b.a){
			return a.b < b.b;
		}else{
			return a.a < b.a;
		}
	}else{
		return a.d < b.d;
	}
}

int find_root(int x)
{
	int k;
	int r;

	r = x;
	while(dj[r] != r){
		r = dj[r];
	}

	k = x;
	while(k != r){
		x = dj[x];
		dj[k] = r;
		k = x;
	}

	return r;
}

int main()
{
	int i;
	int ra, rb;
	Edge e;
	string s;
	string sa, sb;
	map<string, int>::iterator mit;

	while(cin >> stock){
		mm.clear();
		vv.clear();
		cin >> n;
		dj = NULL;
		if(n > 0){
			dj = new int[n];
			memset(dj, 0, n * sizeof(int));

			if(!dj){
				exit(1);
			}
		}
		for(i = 0; i < n; ++i){
			dj[i] = i;
			cin >> s;
			mm.insert(pair<string, int>(s, i));
			vv.push_back(s);
		}
		cin >> m;
		ve.clear();
		for(i = 0; i < m; ++i){
			cin >> sa >> sb >> e.d;
			mit = mm.find(sa);
			if(mit != mm.end()){
				e.a = mit->second;
			}else{
				continue;
			}
			mit = mm.find(sb);
			if(mit != mm.end()){
				e.b = mit->second;
			}else{
				continue;
			}
			ve.push_back(e);
		}
		sort(ve.begin(), ve.end(), edge_comparator);

		ec = 0;
		mincost = 0.0;
		for(i = 0; i < (int)ve.size(); ++i){
			ra = find_root(ve[i].a);
			rb = find_root(ve[i].b);
			if(ra != rb){
				dj[ra] = rb;
				mincost += ve[i].d;
				find_root(ve[i].a);
				find_root(ve[i].b);
				++ec;
			}

			if(ec == n - 1){
				break;
			}
		}

		if(ec == n - 1){
			if(mincost <= stock){
				printf("Need %.1f miles of cable\n", mincost);
			}else{
				printf("Not enough cable\n");
			}
		}else{
			printf("Not enough cable\n");
		}

		delete[] dj;
		dj = NULL;
	}

	return 0;
}
