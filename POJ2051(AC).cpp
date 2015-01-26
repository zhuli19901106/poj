#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

struct node{
	int id;
	int f;
	int cf;
};

struct comp{
	bool operator()(const node &a, const node &b)
	{
		if(a.cf == b.cf){
			return a.id > b.id;
		}else{
			return a.cf > b.cf;
		}
	}
};

int main()
{
#ifdef DEBUG
	bool suc;

	suc = true;
	if(freopen("stdin.txt", "r", stdin) == NULL){
		fprintf(stderr, "Error redirecting stdin.\n");
		suc = false;
	}
	if(freopen("stdout.txt", "w", stdout) == NULL){
		fprintf(stderr, "Error redirecting stdout.\n");
		suc = false;
	}
	if(!suc){
		return -1;
	}
#endif
	char str[1000];
	char s1[1000];
	int i, k;
	struct node n;
	priority_queue<node, vector<node>, comp>pq;
	
	while(true){
		if(gets(str) == NULL){
			break;
		}
		
		while(!pq.empty()){
			pq.pop();
		}

		while(strcmp(str, "#") != 0){
			if(sscanf(str, "%s%d%d", s1, &(n.id), &(n.f)) == 3){
				n.cf = n.f;
				pq.push(n);
			}
			gets(str);
		}
		gets(str);
		sscanf(str, "%d", &k);
		for(i = 0; i < k; ++i){
			n = pq.top();
			printf("%d\n", n.id);
			pq.pop();
			n.cf += n.f;
			pq.push(n);
		}
	}

#ifdef DEBUG
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
