#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, int> m;
vector<string> v;
int s;
int x[500];
int y[500];
int cc;

int main()
{
	int i;
	string a, b;
	int ia, ib;
	int t, ti;
	map<string, int>::iterator mit;

	cin >> t;
	for(ti = 1; ti <= t; ++ti){
		cin >> s;
		m.clear();
		v.clear();
		cc = 0;
		for(i = 0; i < s; ++i){
			x[i] = i;
			y[i] = i;
		}
		for(i = 0; i < s - 1; ++i){
			cin >> a >> b;
			mit = m.find(a);
			if(mit == m.end()){
				m.insert(pair<string, int>(a, cc));
				v.push_back(a);
				ia = cc;
				++cc;
			}else{
				ia = mit->second;
			}
			mit = m.find(b);
			if(mit == m.end()){
				m.insert(pair<string, int>(b, cc));
				v.push_back(b);
				ib = cc;
				++cc;
			}else{
				ib = mit->second;
			}
			x[ia] = ib;
			y[ib] = ia;
		}

		for(i = 0; i < s; ++i){
			if(y[i] == i){
				break;
			}
		}

		cout << "Scenario #" << ti << ":" << endl;
		while(true){
			if(i == x[i]){
				cout << v[i] << endl;
				cout << endl;
				break;
			}else{
				cout << v[i] << endl;
				i = x[i];
			}
		}
	}

	return 0;
}
