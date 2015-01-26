#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;

map<string, string> mm;
map<string, string>::iterator mit;
int main()
{
	char s[1000];
	char s1[20], s2[20];

	mm.clear();
	while(true){
		gets(s);
		if(!s[0]){
			break;
		}
		sscanf(s, "%s%s", s1, s2);
		mm.insert(pair<string, string>(string(s2), string(s1)));
	}

	while(gets(s) != NULL){
		mit = mm.find(string(s));
		if(mit != mm.end()){
			printf("%s\n", mit->second.data());
		}else{
			printf("eh\n");
		}
	}

	return 0;
}
