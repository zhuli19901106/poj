#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[1005];
int len;

bool comparator(const char &a, const char &b)
{
	return a > b;
}

int main()
{
	int sum;
	int i, j, k, l;
	bool suc;
	char t[1005];
	
	while(scanf("%s", s) == 1){
		suc = false;
		len = strlen(s);
		sort(s, s + len, comparator);
		sum = 0;
		for(i = 0; s[i]; ++i){
			sum += s[i] - '0';
		}
		if(s[len - 1] != '0'){
			i = len - 1;
			while(i >= 0 && s[i] != '5'){
				--i;
			}
			if(i != -1){
				while(i < len - 1){
					s[i] = s[i + 1];
					++i;
				}
				s[len - 1] = '5';
			}
		}

		if(s[len - 1] == '0' || s[len - 1] == '5'){
			if(sum % 3){
				i = len - 2;
				while(i >= 0 && sum % 3 != (s[i] - '0') % 3){
					--i;
				}
				if(i == -1){
					i = len - 2;
					while(i >= 0 && (s[i] - '0') % 3 + sum % 3 != 3){
						--i;
					}

					if(i >= 0){
						j = i;
						i = j - 1;
						while(i >= 0 && (s[i] - '0') % 3 + sum % 3 != 3){
							--i;
						}
						if(i >= 0){
							memset(t, 0, 1005 * sizeof(char));
							k = 0;
							for(l = 0; l < len; ++l){
								if(l == i || l == j){
									continue;
								}else{
									t[k++] = s[l];
								}
							}
							t[k] = 0;
							memcpy(s, t, 1005 * sizeof(char));
							len = strlen(s);
							suc = true;
						}
					}
				}else{
					while(i < len){
						s[i] = s[i + 1];
						++i;
					}
					--len;
					suc = true;
				}
			}else{
				suc = true;
			}
		}

		len = strlen(s);
		i = 0;
		while(i < len - 1 && s[i] == '0'){
			++i;
		}

		if(suc){
			printf("%s\n", s + i);
		}else{
			printf("impossible\n");
		}
	}

	return 0;
}
