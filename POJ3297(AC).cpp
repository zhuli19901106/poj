#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, int> ms;
int sc;

vector<int> vps[100];
vector<int> vsp[10000];

unsigned char b[100][10000];

typedef struct st{
	string name;
	int signup;
}st;
st a[100];
int pc;

bool comparator(const st &a, const st &b)
{
	if(a.signup == b.signup){
		return a.name < b.name;
	}else{
		return a.signup > b.signup;
	}
}

int main()
{
	string str;
	char s[1000], *pstr;
	bool terminate;
	int i, j;
	map<string, int>::iterator mit;

	terminate = false;
	while(true){
		sc = 0;
		pc = 0;
		memset(b, 0, 100 * 10000 * sizeof(unsigned char));
		ms.clear();
		for(i = 0; i < 100; ++i){
			vps[i].clear();
		}
		for(i = 0; i < 10000; ++i){
			vsp[i].clear();
		}
		while((pstr = gets(s)) != NULL){
			if(s[0] == '1'){
				break;
			}else if(s[0] == '0'){
				terminate = true;
				break;
			}else{
				str = string(s);
				if(str[0] >= 'a' && str[0] <= 'z'){
					//student
					mit = ms.find(str);
					if(mit != ms.end()){
						if(!b[pc - 1][mit->second]){
							b[pc - 1][mit->second] = 1;
							vsp[mit->second].push_back(pc - 1);
							vps[pc - 1].push_back(mit->second);
						}
					}else{
						ms[str] = sc;
						++sc;
						b[pc - 1][sc - 1] = 1;
						vsp[sc - 1].push_back(pc - 1);
						vps[pc - 1].push_back(sc - 1);
					}
				}else if(str[0] >= 'A' && str[0] <= 'Z'){
					//project
					++pc;
					a[pc - 1].name = str;
					a[pc - 1].signup = 0;
				}
			}
		}
		if(terminate){
			break;
		}else if(pstr == NULL){
			break;
		}
		for(i = 0; i < pc; ++i){
			for(j = 0; j < (int)vps[i].size(); ++j){
				if(vsp[vps[i][j]].size() == 1){
					++(a[i].signup);
				}
			}
		}

		sort(a, a + pc, comparator);
		for(i = 0; i < pc; ++i){
			printf("%s %d\n", a[i].name.data(), a[i].signup);
		}
	}

	return 0;
}
