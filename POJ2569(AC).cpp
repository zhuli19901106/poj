#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

char s[256];
int n;
int a[256][256];
typedef struct st{
public:
	char a;
	char b;
	int f;

	st(const char _a, const char _b, const int _f)
	{
		a = _a;
		b = _b;
		f = _f;
	}
}st;
vector<st> vv;

bool comparator(const st &a, const st &b)
{
	if(a.f == b.f){
		if(a.a == b.a){
			return a.b < b.b;
		}else{
			return a.a < b.a;
		}
	}else{
		return a.f > b.f;
	}
}

int tot;

int main()
{
	int i, j, len;
	string str;

	while(gets(s) != NULL){
		memset(a, 0, 256 * 256 * sizeof(int));
		sscanf(s, "%d", &n);
		if(!n){
			break;
		}
		str = "";
		for(i = 0; i < n; ++i){
			gets(s);
			str = str + string(s);
		}

		tot = 0;
		len = str.size();
		for(i = 0; i < len - 1; ++i){
			++a[str[i]][str[i + 1]];
			++tot;
		}

		vv.clear();
		for(i = 32; i <= 126; ++i){
			for(j = 32; j <= 126; ++j){
				vv.push_back(st((char)i, (char)j, a[i][j]));
			}
		}
		sort(vv.begin(), vv.end(), comparator);
		for(i = 0; i < 5; ++i){
			printf("%c%c %d %f\n", vv[i].a, vv[i].b, vv[i].f, vv[i].f * 1.0 / tot);
		}
		printf("\n");
	}
	
	return 0;
}

