#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	int t, ti;
	char s[1100];
	char s1[1100];
	int len, ll, rr, i;
	bool suc;
	int ep, ec, dp, dc;
	int sc, sp, nc;

	while(gets(s1) != NULL){
		sscanf(s1, "%d", &t);
		for(ti = 0; ti < t; ++ti){
			gets(s1);
			len = strlen(s1);
			ll = 0;
			rr = len - 1;
			while(ll < len && s1[ll] == ' '){
				++ll;
			}
			while(rr >= 0 && s1[rr] == ' '){
				--rr;
			}

			if(ll <= rr){
				for(i = ll; i <= rr; ++i){
					s[i - ll] = s1[i];
				}
				s[i - ll] = 0;
			}

			suc = true;
			//check for spaces
			len = strlen(s);
			for(i = 0; i < len; ++i){
				if(s[i] == ' '){
					suc = false;
					break;
				}
			}
			if(!suc){
				printf("ILLEGAL\n");
				continue;
			}

			for(i = 0; i < len; ++i){
				if(
					!(
					(s[i] >= '0' && s[i] <= '9') || (s[i] == '+') || (s[i] == '-') 
					|| (s[i] == '.') || (s[i] == 'e') || (s[i] == 'E')
					)
				){
					suc = false;
					break;
				}
			}
			if(!suc){
				printf("ILLEGAL\n");
				continue;
			}

			ec = 0;
			ep = -1;
			dc = 0;
			dp = -1;
			for(i = 0; i < len; ++i){
				if(s[i] == 'e' || s[i] == 'E'){
					ep = i;
					++ec;
				}
				if(s[i] == '.'){
					dp = i;
					++dc;
				}
			}
			if(ec > 1 || dc > 1){
				suc = false;
			}
			if(ec > 0 && dc > 0 && dp > ep){
				suc = false;
			}
			if(!suc){
				printf("ILLEGAL\n");
				continue;
			}

			sc = 0;
			sp = -1;
			for(i = 0; i < len; ++i){
				if(s[i] == '+' || s[i] == '-'){
					if(i == 0 || (i > 0 && (s[i - 1] == 'e' || s[i - 1] == 'E'))){
						//OK
					}else{
						suc = false;
						break;
					}

					sp = i;
					++sc;
				}
			}

			if(dc > 0){
				if(
					dp > 0 && dp < len - 1 && 
					(s[dp - 1] >= '0' && s[dp - 1] <= '9')
					&& (s[dp + 1] >= '0' && s[dp + 1] <= '9')
				){
					//OK
				}else{
					suc = false;
				}
			}

			if(ec > 0){
				nc = 0;
				for(i = ep + 1; i < len; ++i){
					if(s[i] >= '0' && s[i] <= '9'){
						++nc;
					}
				}

				if(nc == 0){
					suc = false;
				}
			}

			if(!suc){
				printf("ILLEGAL\n");
				continue;
			}

			printf("LEGAL\n");
		}
	}

	return 0;
}

