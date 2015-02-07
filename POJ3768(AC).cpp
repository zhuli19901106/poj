#include <cstdio>
#include <string>
#include <vector>
using namespace std;
 
vector<vector<string> > a;
int n, q;
int m[5][5];
 
int main()
{
    vector<string> v;
    char ss[4000];
    int i, j, k, ii, jj;
    int len;
     
    while (gets(ss) != NULL) {
        sscanf(ss, "%d", &n);
        if (n == 0) {
            break;
        }
        for (i = 0; i < n; ++i) {
            gets(ss);
            v.push_back(string(ss));
        }
 
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (v[i][j] == ' ') {
                    m[i][j] = 0;
                } else {
                    m[i][j] = 1;
                }
            }
        }
        gets(ss);
        sscanf(ss, "%d", &q);
 
        a.resize(q);
        a[0] = v;
        for (i = 1; i < q; ++i) {
            len = a[i - 1].size();
            a[i].resize(n * len);
            for (j = 0; j < n * len; ++j) {
                a[i][j].resize(n * len, ' ');
            }
        }
 
        len = n;
        for (i = 1; i < q; ++i) {
            for (j = 0; j < n; ++j) {
                for (k = 0; k < n; ++k) {
                    if (m[j][k]) {
                        for (ii = 0; ii < len; ++ii) {
                            for (jj = 0; jj < len; ++jj) {
                                a[i][j * len + ii][k * len + jj] = a[i - 1][ii][jj];
                            }
                        }
                    } else {
                        for (ii = 0; ii < len; ++ii) {
                            for (jj = 0; jj < len; ++jj) {
                                a[i][j * len + ii][k * len + jj] = ' ';
                            }
                        }
                    }
                }
            }
            len *= n;
        }
 
        for (i = 0; i < a[q - 1].size(); ++i) {
            puts(a[q - 1][i].data());
        }
 
        a.clear();
        v.clear();
    }
     
    return 0;
}