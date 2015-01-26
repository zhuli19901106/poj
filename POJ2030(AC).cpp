#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 100;
char a[MAXN][MAXN];
int h, w;
string f[MAXN][MAXN];
int len[MAXN][MAXN];
vector<string> v;
int max_len;

bool isd(const char &ch)
{
	return ch >= '0' && ch <= '9';
}

inline int mymax(const int &a, const int &b)
{
	return a > b ? a : b;
}

int main()
{
	int i, j;
	char s[1000];

	while(gets(s) != NULL){
		if(sscanf(s, "%d%d", &w, &h) != 2){
			break;
		}else if(!(h || w)){
			break;
		}
		memset(a, 0, MAXN * MAXN * sizeof(char));

		for(i = 1; i <= h; ++i){
			gets(s);
			for(j = 1; j <= w; ++j){
				a[i][j] = s[j - 1];
			}
		}

		memset(len, 0, MAXN * MAXN * sizeof(int));
		max_len = -1;
		for(i = 1; i <= h; ++i){
			for(j = 1; j <= w; ++j){
				if(isd(a[i][j])){
					len[i][j] = mymax(len[i][j - 1] + 1, len[i - 1][j] + 1);
					if(a[i][j] == '0' && len[i][j] == 1){
						len[i][j] = 0;
					}
				}else{
					len[i][j] = 0;
				}
				if(len[i][j] > max_len){
					max_len = len[i][j];
				}
			}
		}

		for(i = 1; i <= h; ++i){
			for(j = 1; j <= w; ++j){
				f[i][j] = "";
			}
		}

		for(i = 1; i <= h; ++i){
			for(j = 1; j <= w; ++j){
				if(isd(a[i][j])){
					if(len[i][j] == 0){
						f[i][j] = "";
					}else if(len[i - 1][j] > len[i][j - 1]){
						f[i][j] = f[i - 1][j] + a[i][j];
					}else if(len[i - 1][j] < len[i][j - 1]){
						f[i][j] = f[i][j - 1] + a[i][j];
					}else if(f[i - 1][j] > f[i][j - 1]){
						f[i][j] = f[i - 1][j] + a[i][j];
					}else{
						f[i][j] = f[i][j - 1] + a[i][j];
					}
				}else{
					f[i][j] = "";
				}
			}
		}

		v.clear();
		for(i = 1; i <= h; ++i){
			for(j = 1; j <= w; ++j){
				if(len[i][j] == max_len){
					v.push_back(f[i][j]);
				}
			}
		}
		sort(v.begin(), v.end());

		strcpy(s, v[v.size() - 1].data());
		printf("%s\n", s);
	}

	return 0;
}
