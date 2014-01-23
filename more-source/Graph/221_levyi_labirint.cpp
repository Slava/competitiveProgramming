#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

const int maxn = 25;
const int maxk = 7;
int n, m, k, i, j,
	a[maxn][maxn][maxk][4],
	can[maxn][maxn],
	sx, sy, fx, fy, ans = 1 << 30, 
	d[] = {-1,0, 0,1, 1,0, 0,-1};

struct item
{
	int x, y, l, D, dir;
	item(){}
	item(int _x, int _y, int _l, int _D = 0, int _dir = 0)
	{
		x = _x; y = _y; l = _l; D = _D; dir = _dir;
	}
	item (const item &b)
	{
		x = b.x; y = b.y; l = b.l; D = b.D; dir = b.dir;
	}
};
queue<item>q;

bool check (int X, int Y, int Z, int D, int K)
{
	if (X == sx && Y == sy && Z == 0)
		return 0;
	if (!(X >= 0 && X < n && Y >= 0 && Y < m && Z >= 0 && Z <= k))
		return 0;
	if (can[X][Y])
		return 0;
	if (!a[X][Y][Z][K] || a[X][Y][Z][K] < D){
		a[X][Y][Z][K] = D;
		return 1;
	}
	
	return 0;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	FILE *IN = fopen("input.txt", "r");

	fscanf (IN, "%d%d%d", &k, &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			fscanf (IN, "%d", &can[i][j]);
			if (can[i][j] == 2)
				sx = i, sy = j, can[i][j] = 0;
			if (can[i][j] == 3)
				fx = i, fy = j, can[i][j] = 0;
		}
	
		item hz;
		hz.x = sx, hz.y = sy, hz.dir = 0, hz.D = 0; hz.l = 0;
		for (int i = 0; i < 4; i++)
		{
			hz.dir = i;
			q.push(hz);
		}
		while (q.size())
		{
//cin.get();
			item v(q.front()), ch(q.front());
			q.pop();
		//	printf("cur is (%d,%d) with %d turns, %d dist, %d direction={%d,%d}\n", v.x,v.y,v.l,v.D,v.dir,d[v.dir*2],d[v.dir*2+1]);
			if (v.x == fx && v.y == fy)
				break;
			ch.x += d[ch.dir*2];
			ch.y += d[ch.dir*2+1];
			ch.D++;
			if (check(ch.x, ch.y, ch.l, ch.D, ch.dir))
				q.push(ch);
			ch = v;
			ch.dir = (ch.dir + 3) % 4;
			ch.x += d[ch.dir*2];
			ch.y += d[ch.dir*2+1];
			ch.D++;
			if (check(ch.x, ch.y, ch.l, ch.D, ch.dir))
				q.push(ch);
			ch = v;
			ch.dir = (ch.dir + 1) % 4;
			ch.x += d[ch.dir*2];
			ch.y += d[ch.dir*2+1];
			ch.D++;
			ch.l++;
			if (check(ch.x, ch.y, ch.l, ch.D, ch.dir))
				q.push(ch);
		}
		for (int K = 0; K < 4; K++)
		for(i = 0; i <= k; i++)
			if (a[fx][fy][i][K])
				ans = min(ans, a[fx][fy][i][K]);

	if(ans != 1 << 30)
		printf ("%d", ans);
	else puts("-1");

	return 0;
}


