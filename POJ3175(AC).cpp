#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef long long LL;

int main()
{
	LL d;
	double n, c, err;
	double f;

	while(cin >> n){
		cin >> d;
		if(d == 0){
			cout << "0" << endl;
			continue;
		}
		c = (double)d / pow(10.0, n);
		err = pow(10.0, -n);
		f = 1;
		while(f < 1000000000){
			if((LL)((f + c) * (f + c)) + 1 < (f + c + err) * (f + c + err)){
				break;
			}
			f = f + 1;
		}
		
		cout << (LL)(ceil((f + c) * (f + c))) <<endl;
	}

	return 0;
}

