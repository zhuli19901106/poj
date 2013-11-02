#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, string> assoc;
	map<string, int> vote;
	map<string, int>::iterator it, max_it;
	string name, party;
	char buffer[1000];
	int i;
	int n, m;
	
	while(true){
		if(gets(buffer) == NULL){
			break;
		}
		sscanf(buffer, "%d", &n);
		for(i = 0; i < n; i++){
			gets(buffer);
			name = string(buffer);
			gets(buffer);
			party = string(buffer);
			assoc.insert(pair<string, string>(name, party));
			vote.insert(pair<string, int>(name, 0));
		}
		
		gets(buffer);
		sscanf(buffer, "%d", &m);
		for(i = 0; i < m; i++){
			gets(buffer);
			name = string(buffer);
			it = vote.find(name);
			if(it != vote.end()){
				it->second++;
			}
		}

		bool tie;
		tie = false;
		max_it = vote.begin();
		for(it = vote.begin(), it++; it != vote.end(); it++){
			if(it->second > max_it->second){
				max_it = it;
				tie = false;
			}else if(it->second == max_it->second){
				tie = true;
			}
		}

		if(tie){
			printf("tie\n");
		}else{
			printf("%s\n", assoc.find(max_it->first)->second.data());
		}

		assoc.clear();
		vote.clear();
	}
	
	return 0;
}

