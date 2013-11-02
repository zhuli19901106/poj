#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct st{
	int c;
	char s;
}st;
st a[5];

bool comparator(const st &a, const st &b)
{
	return a.c < b.c;
}

inline bool same_suit(const st a[])
{
	return a[0].s == a[1].s && a[1].s == a[2].s && a[2].s == a[3].s && a[3].s == a[4].s;
}

inline bool sequence(const st a[])
{
	if(a[0].c == 1){
		return 
			(a[0].c == a[1].c - 1 && a[1].c == a[2].c - 1 && a[2].c == a[3].c - 1 && a[3].c == a[4].c - 1 && a[0].c <= 10)
			||
			(a[1].c == 10 && a[2].c == 11 && a[3].c == 12 && a[4].c == 13);
	}else{
		return a[0].c == a[1].c - 1 && a[1].c == a[2].c - 1 && a[2].c == a[3].c - 1 && a[3].c == a[4].c - 1 && a[0].c <= 10;
	}
}

int main()
{
	int t, ti;
	char s[5];
	int i;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			for(i = 0; i < 5; ++i){
				scanf("%s", s);
				a[i].s = s[0];
				if(s[1] == 'A'){
					a[i].c = 1;
				}else if(s[1] == '2'){
					a[i].c = 2;
				}else if(s[1] >= '3' && s[1] <= '9'){
					a[i].c = s[1] - '0';
				}else if(s[1] == 'X'){
					a[i].c = 10;
				}else if(s[1] == 'J'){
					a[i].c = 11;
				}else if(s[1] == 'Q'){
					a[i].c = 12;
				}else if(s[1] == 'K'){
					a[i].c = 13;
				}
			}
			sort(a, a + 5, comparator);

			if(same_suit(a) && sequence(a)){
				printf("1000\n");
			}else if(a[0].c == a[1].c && a[1].c == a[2].c && a[2].c == a[3].c){
				printf("750\n");
			}else if(
				(a[0].c == a[1].c && a[1].c == a[2].c && a[3].c == a[4].c)
				||
				(a[0].c == a[1].c && a[2].c == a[3].c && a[3].c == a[4].c)
			){
				printf("500\n");
			}else if(same_suit(a)){
				printf("350\n");
			}else if(sequence(a)){
				printf("250\n");
			}else if(
				(a[0].c == a[1].c && a[1].c == a[2].c)
				||
				(a[1].c == a[2].c && a[2].c == a[3].c)
				||
				(a[2].c == a[3].c && a[3].c == a[4].c)
			){
				printf("200\n");
			}else if(
				(a[0].c == a[1].c && a[2].c == a[3].c)
				||
				(a[0].c == a[1].c && a[3].c == a[4].c)
				||
				(a[1].c == a[2].c && a[3].c == a[4].c)
			){
				printf("100\n");
			}else if(a[0].c == a[1].c || a[1].c == a[2].c || a[2].c == a[3].c || a[3].c == a[4].c){
				printf("50\n");
			}else{
				printf("0\n");
			}
		}
	}

	return 0;
}

