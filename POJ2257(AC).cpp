#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef struct st{
	string name;
	int id;
	int money;
}st;

st a[25];
map<string, int> mm;
int n, m;

int main()
{
	int i;
	string sa, sb;
	int ia, ib, tmp;
	map<string, int>::iterator mit;
	int ti;

	ios::sync_with_stdio(false);
	ti = 0;
	while(cin >> n >> m && (n || m)){
		++ti;
		mm.clear();
		for(i = 0; i < n; ++i){
			cin >> a[i].name;
			a[i].id = i;
			a[i].money = 0;
			mm[a[i].name] = i;
		}

		for(i = 0; i < m; ++i){
			cin >> sa >> sb >> tmp;
			mit = mm.find(sa);
			if(mit == mm.end()){
				continue;
			}
			ia = mit->second;
			mit = mm.find(sb);
			if(mit == mm.end()){
				continue;
			}
			ib = mit->second;
			a[ia].money -= tmp;
			a[ib].money += tmp;
		}

		cout << "Case #" << ti << endl;
		for(i = 0; i < n - 1; ++i){
			if(a[i].money > 0){
				cout << a[i].name << " " << a[i + 1].name << " " << a[i].money << endl;
			}else if(a[i].money < 0){
				cout << a[i + 1].name << " " << a[i].name << " " << -a[i].money << endl;
			}
			a[i + 1].money += a[i].money;
			a[i].money = 0;
		}
		cout << endl;
	}

	return 0;
}

