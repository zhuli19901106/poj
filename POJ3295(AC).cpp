#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

int last_i;
int len;
char s[1000];
int v[5];
int vc;
map<char, int> mm;

int evaluate(int si)
{
	int vi;
	int res1, res2;
	map<char, int>::iterator mit;

	switch(s[si]){
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
		mit = mm.find(s[si]);
		if(mit != mm.end()){
			vi = mit->second;
			last_i = si + 1;
			return v[vi];
		}
		break;
	case 'K':
		res1 = evaluate(si + 1);
		res2 = evaluate(last_i);
		return !!((!!res1) & (!!res2));
		break;
	case 'A':
		res1 = evaluate(si + 1);
		res2 = evaluate(last_i);
		return !!((!!res1) | (!!res2));
		break;
	case 'N':
		res1 = evaluate(si + 1);
		return (!!!res1);
		break;
	case 'C':
		res1 = evaluate(si + 1);
		res2 = evaluate(last_i);
		return !!((!!!res1) | (!!res2));
		break;
	case 'E':
		res1 = evaluate(si + 1);
		res2 = evaluate(last_i);
		return (!!res1) == (!!res2);
		break;
	}
}

int main()
{
	int res;
	int i, b2;
	int n, ni;

	while(scanf("%s", s) == 1 && strcmp(s, "0")){
		vc = 0;
		mm.clear();
		for(i = 0; s[i]; ++i){
			switch(s[i]){
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
				if(mm.find(s[i]) == mm.end()){
					mm.insert(pair<char, int>(s[i], vc++));
				}
				break;
			}
		}

		n = 1 << vc;
		last_i = 0;
		for(ni = 0; ni < n; ++ni){
			b2 = 1;
			for(i = 0; i < vc; ++i){
				v[i] = !!(ni & b2);
				b2 <<= 1;
			}
			res = evaluate(0);
			if(!res){
				break;
			}
		}
		
		if(ni == n){
			printf("tautology\n");
		}else{
			printf("not\n");
		}
	}

	return 0;
}
