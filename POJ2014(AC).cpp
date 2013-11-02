#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int w[20];
int h[20];
int ww;
int rc;

int main()
{
	int i;
	int w0, h0;

	while(scanf("%d", &ww) == 1 && ww){
		rc = 0;
		memset(w, 0, 20 * sizeof(int));
		memset(h, 0, 20 * sizeof(int));
		while(scanf("%d%d", &w0, &h0) == 2 && !(w0 == -1 && h0 == -1)){
			if(w0 <= ww - w[rc]){
				w[rc] += w0;
				if(h[rc] < h0){
					h[rc] = h0;
				}
			}else{
				++rc;
				w[rc] = w0;
				h[rc] = h0;
			}
		}

		w0 = 0;
		h0 = 0;
		for(i = 0; i <= rc; ++i){
			if(w[i] > w0){
				w0 = w[i];
			}
			h0 += h[i];
		}

		printf("%d x %d\n", w0, h0);
	}

	return 0;
}

