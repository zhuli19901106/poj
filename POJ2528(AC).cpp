// 2528	Accepted	10872K	94MS	G++	3383B	2015-07-24 02:49:48
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100005;
int s[N];
int e[N];

int d1[2 * N];
int dc1;

int d[3 * N];
int dc;

int n;
int b[N];
int ans;

typedef struct SegmentTreeNode {
    int start, end;
    int tag;
    SegmentTreeNode *left, *right;
    
    SegmentTreeNode(int _start = 0, int _end = 0) {
        start = _start;
        end = _end;
        tag = -1;
        left = right = NULL;
    }
} STN;
const int MAX_NODE = 500000;
STN nodes[MAX_NODE];
int nc;

int mymin(int x, int y)
{
    return x < y ? x : y;
}

int mymax(int x, int y)
{
    return x > y ? x : y;
}

STN *buildTree(int start, int end)
{
    if (start > end) {
        return NULL;
    }
    STN *root = &(nodes[nc++]);
    root->start = start;
    root->end = end;
    if (start == end) {
        return root;
    }
    int mid = start + (end - start >> 1);
    if (mid < end) {
        root->left = buildTree(start, mid);
    }
    if (mid + 1 > start) {
        root->right = buildTree(mid + 1, end);
    }
    return root;
}

void addPoster(STN *root, int start, int end, int tag)
{
    if (start > end) {
        return;
    }
    if (start == root->start && end == root->end) {
        root->tag = tag;
        return;
    }
    int mid = root->start + (root->end - root->start >> 1);
    int oldtag = root->tag;
    root->tag = -1;
    if (oldtag >= 0) {
        addPoster(root, root->start, start - 1, oldtag);
        addPoster(root, end + 1, root->end, oldtag);
    }
    
    addPoster(root->left, start, mymin(mid, end), tag);
    addPoster(root->right, mymax(mid + 1, start), end, tag);
}

void countPoster(STN *root)
{
    if (root == NULL) {
        return;
    }
    if (root->tag >= 0) {
        if (!b[root->tag]) {
            b[root->tag] = 1;
            ++ans;
        }
        return;
    }
    countPoster(root->left);
    countPoster(root->right);
}

void discretization()
{
    dc = 0;
    d[dc++] = d1[0];
    int i;
    for (i = 1; i < dc1; ++i) {
        if (d1[i] - d1[i - 1] > 1) {
            d[dc++] = d1[i - 1] + (d1[i] - d1[i - 1] >> 1);
        }
        d[dc++] = d1[i];
    }
}

void clearTree(STN *root)
{
    if (root == NULL) {
        return;
    }
    clearTree(root->left);
    clearTree(root->right);

    root->left = NULL;
    root->right = NULL;
    root->tag = -1;
    --nc;
}

int removeDuplicate(int a[], int n)
{
    int i, j;
    int n1 = 0;

    i = 0;
    while (i < n) {
        j = i + 1;
        while (j < n && a[i] == a[j]) {
            ++j;
        }
        a[n1++] = a[i];
        i = j;
    }
    return n1;
}

int bs(int x)
{
    int ll = 0;
    int rr = dc - 1;
    int mm;
    while (ll <= rr) {
        mm = ll + (rr - ll >> 1);
        if (x < d[mm]) {
            rr = mm - 1;
        } else if (x > d[mm]) {
            ll = mm + 1;
        } else {
            return mm;
        }
    }
    return -1;
}

void solve()
{
    scanf("%d", &n);
    
    int i;
    dc1 = 0;
    for (i = 0; i < n; ++i) {
        scanf("%d%d", &s[i], &e[i]);
        d1[dc1++] = s[i];
        d1[dc1++] = e[i];
    }
    sort(d1, d1 + dc1);
    dc1 = removeDuplicate(d1, dc1);
    
    discretization();
    
    STN *root = buildTree(0, dc - 1);
    for (i = 0; i < n; ++i) {
        addPoster(root, bs(s[i]), bs(e[i]), i);
    }
    
    ans = 0;
    memset(b, 0, sizeof(b));
    countPoster(root);
    printf("%d\n", ans);
    
    clearTree(root);
}

int main()
{
    int t, ti;
    
    scanf("%d", &t);
    for (ti = 0; ti < t; ++ti) {
        solve();
    }
    
    return 0;
}