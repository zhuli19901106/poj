#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;

int b[1100];
int n;

int main()
{
	int i, j;
	bool terminate;
	bool success;
	stack<int> st;
	
	while(true){
		scanf("%d", &n);
		if(0 == n){
			break;
		}
		
		terminate = false;
		while(!terminate){
			for(i = 1; i <= n; ++i){
				scanf("%d", &b[i]);
				if(1 == i && 0 == b[i]){
					terminate = true;
					break;
				}
			}
			if(terminate){
				break;
			}
		
			while(!st.empty()){
				st.pop();
			}
			success = true;
			i = 1;
			j = 1;
			while(j <= n){
				if(i == b[j]){
					++i;
					++j;
				}else if(!st.empty() && st.top() == b[j]){
					st.pop();
					++j;
				}else if(i <= n){
					st.push(i);
					++i;
				}else{
					success = false;
					break;
				}
			}

			if(success){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}
		printf("\n");
	}
	
	return 0;
}

