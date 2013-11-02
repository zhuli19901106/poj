#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;

map<string, int> mm;
map<string, int>::iterator mit;
int n;
char s[100];

int main()
{
	string str;

	mm.clear();
	n = 0;
	while(gets(s) != NULL){
		++n;
		str = string(s);
		mit = mm.find(str);
		if(mit != mm.end()){
			++(mit->second);
		}else{
			mm.insert(pair<string, int>(str, 1));
		}
	}

	for(mit = mm.begin(); mit != mm.end(); ++mit){
		printf("%s %.4f\n", mit->first.data(), 100.0 * mit->second / n);
	}

	return 0;
}

