#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char sa[105], sb[105];

bool check_friends(const char sa[], const char sb[])
{
	int i;
	int ca[10], cb[10];
	int ba[10], bb[10];

	memset(ca, 0, 10 * sizeof(int));
	memset(cb, 0, 10 * sizeof(int));
	memset(ba, 0, 10 * sizeof(int));
	memset(bb, 0, 10 * sizeof(int));

	for(i = 0; sa[i]; ++i){
		if(sa[i] >= '0' && sa[i] <= '9'){
			++ca[sa[i] - '0'];
		}
	}
	for(i = 0; sb[i]; ++i){
		if(sb[i] >= '0' && sb[i] <= '9'){
			++cb[sb[i] - '0'];
		}
	}
	for(i = 0; i < 10; ++i){
		ba[i] = (ca[i] > 0);
		bb[i] = (cb[i] > 0);
	}
	for(i = 0; i < 10; ++i){
		if(ba[i] != bb[i]){
			return false;
		}
	}

	return true;
}

bool almost_friends(char sa[], char sb[])
{
	int i, j;
	int lena;
	int ca[10], cb[10];
	int ba[10], bb[10];

	memset(ca, 0, 10 * sizeof(int));
	memset(cb, 0, 10 * sizeof(int));
	memset(ba, 0, 10 * sizeof(int));
	memset(bb, 0, 10 * sizeof(int));

	for(i = 0; sa[i]; ++i){
		if(sa[i] >= '0' && sa[i] <= '9'){
			++ca[sa[i] - '0'];
		}
	}
	for(i = 0; sb[i]; ++i){
		if(sb[i] >= '0' && sb[i] <= '9'){
			++cb[sb[i] - '0'];
		}
	}
	for(i = 0; i < 10; ++i){
		ba[i] = (ca[i] > 0);
		bb[i] = (cb[i] > 0);
	}

	lena = strlen(sa);
	if(lena <= 1){
		return false;
	}
	
	for(i = 0; i < lena - 1; ++i){
		if(sa[i] > '0' && sa[i + 1] < '9'){
			--ca[sa[i] - '0'];
			--ca[sa[i + 1] - '0'];
			--sa[i];
			++sa[i + 1];
			++ca[sa[i] - '0'];
			++ca[sa[i + 1] - '0'];
			for(j = 0; j < 10; ++j){
				ba[j] = (ca[j] > 0);
			}
			for(j = 0; j < 10; ++j){
				if(ba[j] != bb[j]){
					break;
				}
			}
			if(j == 10 && sa[0] != '0'){
				--ca[sa[i] - '0'];
				--ca[sa[i + 1] - '0'];
				++sa[i];
				--sa[i + 1];
				++ca[sa[i] - '0'];
				++ca[sa[i + 1] - '0'];
				for(j = 0; j < 10; ++j){
					ba[j] = (ca[j] > 0);
				}
				return true;
			}else{
				--ca[sa[i] - '0'];
				--ca[sa[i + 1] - '0'];
				++sa[i];
				--sa[i + 1];
				++ca[sa[i] - '0'];
				++ca[sa[i + 1] - '0'];
				for(j = 0; j < 10; ++j){
					ba[j] = (ca[j] > 0);
				}
			}
		}

		if(sa[i] < '9' && sa[i + 1] > '0'){
			--ca[sa[i] - '0'];
			--ca[sa[i + 1] - '0'];
			++sa[i];
			--sa[i + 1];
			++ca[sa[i] - '0'];
			++ca[sa[i + 1] - '0'];
			for(j = 0; j < 10; ++j){
				ba[j] = (ca[j] > 0);
			}
			for(j = 0; j < 10; ++j){
				if(ba[j] != bb[j]){
					break;
				}
			}
			if(j == 10 && sa[0] != '0'){
				--ca[sa[i] - '0'];
				--ca[sa[i + 1] - '0'];
				--sa[i];
				++sa[i + 1];
				++ca[sa[i] - '0'];
				++ca[sa[i + 1] - '0'];
				for(j = 0; j < 10; ++j){
					ba[j] = (ca[j] > 0);
				}
				return true;
			}else{
				--ca[sa[i] - '0'];
				--ca[sa[i + 1] - '0'];
				--sa[i];
				++sa[i + 1];
				++ca[sa[i] - '0'];
				++ca[sa[i + 1] - '0'];
				for(j = 0; j < 10; ++j){
					ba[j] = (ca[j] > 0);
				}
			}
		}
	}

	return false;
}

int main()
{
	int t, ti;

	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%s%s", sa, sb);
			if(check_friends(sa, sb)){
				printf("friends\n");
				continue;
			}

			if(almost_friends(sa, sb) || almost_friends(sb, sa)){
				printf("almost friends\n");
				continue;
			}

			printf("nothing\n");
		}
	}

	return 0;
}

