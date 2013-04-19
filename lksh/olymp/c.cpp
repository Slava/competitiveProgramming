#include <iostream>
#include <cstdio>
#include <cassert>

using namespace std;

const int N = 200007;

int lvl[N];
int up[N][25];
int lv = 1;
int p[N], r[N];

int ans[N];

int fs (int x) {
	if (p[x] != x) p[x] = fs(p[x]);
	return p[x];
}

void un (int x, int y, int a) {
	if (r[x] < r[y]) p[x] = y;
	else		 p[y] = x;
	if (r[x] == r[y]) r[x]++;
	ans[fs(x)] = a;
}                      
int main ()
{
	freopen ("carno.in", "r", stdin);
	freopen ("carno.out", "w", stdout);

	int x, y;
        int m;
        int n = 1;
        for (int i = 0; i < N; i++) p[i] = ans[i] = i;
        cin >> m;
        char t[20];
        
        for (int i = 0; i < m; i++) {
        	scanf ("%s", t);
        	if (t[0] == '+') {
        		scanf ("%d", &x);x--;
        		lvl[n] = lvl[x] + 1;
        		up[n][0] = x;
        		for (int i = 1; i <= 21; i++) 
        			up[n][i] = up[up[n][i-1]][i-1];
        		n++;
  //      		printf ("adding %d to %d\n", n, x+1);
        	}else if (t[0] == '-') {
        		scanf ("%d", &x); x--;
//        		printf ("deleting %d\n", x+1);
        		un(fs(x),fs(up[x][0]),ans[fs(up[x][0])]);
        	}else {
			scanf ("%d %d", &x, &y);
			x--, y--;
			assert (x <= n && y <= n);
        		if (lvl[x] < lvl[y]) swap (x,y);
      //  		printf ("was %d %d\n",x+1, y+1);
        		if (lvl[x] != lvl[y]) {
        			for (int i = 20; i >= 0; i--) 
        				if (lvl[up[x][i]] >= lvl[y]) x = up[x][i];
        		}
  //      		printf("now %d %d %d %d\n", x+1, y+1, lvl[x], lvl[y]);
        		for (int i = 20; i >= 0; i--) {
        			if (up[x][i] != up[y][i]) {
        				x = up[x][i];
        				y = up[y][i];
        			}
        		}
        		int res = up[x][0];
        		if (x == y) res = x;
    //    		printf ("last %d %d\n", x+1, y+1);
        		printf ("%d\n", ans[fs(res)]+1);
        	}
        } 	

	return 0;
}
