#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> mm;
const double pi = 3.141592653589793;
double lat[200];
double lon[200];
const double r = 6378.0;
int n;

int main()
{
	string sa, sb;
	int ia, ib;
	map<string, int>::iterator mit;
	double x1, y1, z1, x2, y2, z2;
	double d;

	mm.clear();
	while(cin >> sa){
		if(sa == "#"){
			break;
		}else{
			mm[sa] = n++;
			cin >> lat[n - 1] >> lon[n - 1];
			lat[n - 1] = lat[n - 1] * pi / 180.0;
			lon[n - 1] = lon[n - 1] * pi / 180.0;
		}
	}

	while(cin >> sa >> sb){
		if(sa == "#" && sb == "#"){
			break;
		}
		cout << sa << " - " << sb << endl;
		mit = mm.find(sa);
		if(mit == mm.end()){
			cout << "Unknown\n" << endl;
			continue;
		}
		ia = mit->second;
		mit = mm.find(sb);
		if(mit == mm.end()){
			cout << "Unkknown\n" << endl;
			continue;
		}
		ib = mit->second;
		
		x1 = r * cos(lon[ia]) * cos(lat[ia]);
		y1 = r * cos(lon[ia]) * sin(lat[ia]);
		z1 = r * sin(lon[ia]);
		x2 = r * cos(lon[ib]) * cos(lat[ib]);
		y2 = r * cos(lon[ib]) * sin(lat[ib]);
		z2 = r * sin(lon[ib]);
		d = r * acos(cos(lat[ia]) * cos(lat[ib]) * cos(lon[ia] - lon[ib]) + sin(lat[ia]) * sin(lat[ib]));
		cout << (int)(d + 0.5) << " km\n" << endl;
	}

	return 0;
}
