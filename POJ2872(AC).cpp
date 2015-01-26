#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

string dic[100000];
int dc;
string word;
int ec;
bool correct;

bool binary_search(const string &s)
{
	int l, r, m;

	l = 0;
	r = dc - 1;
	while(l <= r){
		m = (l + r) / 2;
		if(s < dic[m]){
			r = m - 1;
		}else if(s > dic[m]){
			l = m + 1;
		}else{
			return true;
		}
	}
	return false;
}

int main()
{
	int i;

	while(cin >> dc){
		for(i = 0; i < dc; ++i){
			cin >> dic[i];
		}
		sort(dic, dic + dc);

		cin >> ec;
		for(i = 1; i <= ec; ++i){
			correct = true;
			while(cin >> word){
				if(word == "-1"){
					if(correct){
						cout << "Email " << i << " is spelled correctly." << endl;
					}
					break;
				}else{
					if(!binary_search(word)){
						if(correct){
							cout << "Email " << i << " is not spelled correctly." << endl;
							correct = false;
						}
						cout << word << endl;
					}
				}
			}
		}
		cout << "End of Output" << endl;
	}

	return 0;
}
