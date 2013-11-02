#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

typedef struct st{
	int x;
	int y;
}st;
queue<st> qq;
int a[305][305];
int dir[8][2] = {
	{-2, -1},
	{-1, -2},
	{-2, +1},
	{-1, +2},
	{+1, -2},
	{+2, -1},
	{+1, +2},
	{+2, +1}
};

int main()
{
	int t, ti;
	int p[2][2];
	int s;
	int i;
	st m_st, m_st2;
	bool found;
	
	while(scanf("%d", &t) == 1){
		for(ti = 0; ti < t; ++ti){
			scanf("%d", &s);
			scanf("%d%d", &p[0][0], &p[0][1]);
			scanf("%d%d", &p[1][0], &p[1][1]);
			while(!qq.empty()){
				qq.pop();
			}
			memset(a, 0, 305 * 305 * sizeof(int));
			a[p[0][0]][p[0][1]] = 1;
			m_st.x = p[0][0];
			m_st.y = p[0][1];
			qq.push(m_st);
			found = false;
			while(!found){
				m_st = qq.front();
				qq.pop();
				for(i = 0; i < 8; ++i){
					m_st2.x =  m_st.x + dir[i][0];
					m_st2.y =  m_st.y + dir[i][1];
					if(
						m_st2.x >= 0 && m_st2.x <= s - 1 &&
						m_st2.y >= 0 && m_st2.y <= s - 1 &&
						!a[m_st2.x][m_st2.y]
					){
						a[m_st2.x][m_st2.y] = a[m_st.x][m_st.y] + 1;
						qq.push(m_st2);
						if(a[p[1][0]][p[1][1]] != 0){
							found = true;
						}

						if(found){
							break;
						}
					}
				}
				if(found){
					break;
				}
			}

			printf("%d\n", a[p[1][0]][p[1][1]] - a[p[0][0]][p[0][1]]);
		}
	}
	
	
	return 0;
}

