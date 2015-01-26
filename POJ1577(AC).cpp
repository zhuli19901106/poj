#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef struct Node{
	char c;
	char l;
	char r;
}Node;
Node a[26];
vector<string> v;

bool find(char r, char k)
{
	char c;

	c = r;
	while(true){
		if(k > c){
			if(!a[c - 'A'].r){
				return false;
			}else{
				c = a[c - 'A'].r;
			}
		}else if(k < c){
			if(!a[c - 'A'].l){
				return false;
			}else{
				c = a[c - 'A'].l;
			}
		}else{
			return true;
		}
	}
}

void insert(char r, char k)
{
	char c;

	c = r;
	while(true){
		if(k > c){
			if(!a[c - 'A'].r){
				a[c - 'A'].r = k;
				return;
			}else{
				c = a[c - 'A'].r;
			}
		}else if(k < c){
			if(!a[c - 'A'].l){
				a[c - 'A'].l = k;
				return;
			}else{
				c = a[c - 'A'].l;
			}
		}else{
			return;
		}
	}
}

void preorder(char r)
{
	printf("%c", r);
	if(a[r - 'A'].l){
		preorder(a[r - 'A'].l);
	}
	if(a[r - 'A'].r){
		preorder(a[r - 'A'].r);
	}
}

int main()
{
	char s[1000];
	bool last_case;
	int i, j;
	char r;

	while(true){
		last_case = false;
		for(i = 0; i < 26; ++i){
			a[i].c = 'A' + i;
			a[i].l = 0;
			a[i].r = 0;
		}
		r = -1;
		v.clear();
		while(scanf("%s", s) == 1){
			if(!strcmp(s, "$")){
				last_case = true;
				break;
			}else if(!strcmp(s, "*")){
				break;
			}else{
				v.push_back(string(s));
			}
		}

		r = v[v.size() - 1][0];
		for(i = (int)v.size() - 2; i >= 0; --i){
			for(j = 0; j < (int)v[i].size(); ++j){
				insert(r, v[i][j]);
			}
		}

		preorder(r);
		printf("\n");

		if(last_case){
			break;
		}
	}

	return 0;
}
