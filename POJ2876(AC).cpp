#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string a[13];
string e;

int main()
{
	int n;
	
	a[0] = "-";
	e = " ";
	for(n = 1; n <= 12; ++n){
		a[n] = a[n - 1] + e + a[n - 1];
		e = e + e + e;
	}

	while(cin >> n){
		cout << a[n] << endl;
	}

	return 0;
}
