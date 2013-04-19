#include <cstdio>
#include <queue>

using namespace std;

struct pos {int x, y, k;};

int n, ans;
int a[6][30][30], d[] = {0,1, 1,0, -1,0, 0,-1};
queue<pos>q;
bool check (int x, int y)	{	return 0 <= x && x < n && 0 <= y && y < n;	}
void bfs (int k, int x, int y)
{
	int c = a[k][x][y], dk, dx, dy;
	pos cur; cur.x = x; cur.y = y; cur.k = k;
	q.push(cur);
	a[k][x][y] = 0;
	while(!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		k = q.front().k;
		q.pop();
		for (int i = 0; i < 8; i += 2)
		{
			int dx = x + d[i],
				dy = y + d[i + 1];
			if (check(x,y) && a[k][dx][dy] == c)
			{
				a[k][dx][dy] = 0;
				cur.x = dx; cur.y = dy; cur.k = k;
				q.push(cur);
			}
		}
		if (!x)
		{
			if (k == 0)
			{
				dx = 0;
				dy = n - 1 - y;
				dk = 3;
			}
			if (k == 5)
			{
				dx = n - 1;
				dk = 1;
				dy = y;
			}
			if (k == 1)
			{
				dx = n - 1;
				dk = 0;
				dy = y;
			}
			if (k == 2)
			{
				dk = 0;
				dx = n - 1 - y;
				dy = n - 1;
			}
			if (k == 3)
			{
				dk = 0;
				dy = n - 1 - y;
				dx = 0;
			}
			if (k == 4)
			{
				dk = dy = 0;
				dx = y;
			}
			if (a[dk][dx][dy] == c)
			{
				a[dk][dx][dy] = 0;
				cur.x = dx; cur.y = dy;
				cur.k = dk;
				q.push(cur);
			}
		}
		if (x == n - 1)
		{
			if (k == 0)
			{
				dk = 1; dx = 0; dy = y;
			}
			if (k == 1)
			{
				dk = 5; dx = 0; dy = y;
			}
			if (k == 5)
			{
				dk = 3; dx =  n - 1; dy = n - 1 - y;
			}
			if (k == 2)
			{
				dk = 5; dx = y; dy = n - 1;
			}
			if (k == 4)
			{
				dk = 5; dx = n - 1 - y; dy = 0;
			}
			if (k == 3)
			{
				dk = 5; dx = n - 1; dy = n - 1 - y;
			}

			if (a[dk][dx][dy] == c)
			{
				a[dk][dx][dy] = 0;
				cur.x = dx; cur.y = dy;
				cur.k = dk;
				q.push(cur);
			}
		}
		if (!y)
		{
			if (k == 0)
			{
				dk = 4;
				dx = 0; dy = x;
			}
			if (k == 1)
			{
				dk = 4; dx = x; dy = n - 1;
			}
			if (k == 2)
			{
				dk = 1; dx = x; dy = n - 1;
			}
			if (k == 3)
			{
				dk = 2; dx = x; dy = n - 1;
			}
			if (k == 4)
			{
				dk = 3; dx = x; dy = n - 1;
			}
			if (k == 5)
			{
				dk = 4; dx = n - 1; dy = n - 1 - x;
			}
			if (a[dk][dx][dy] == c)
			{
				a[dk][dx][dy] = 0;
				cur.x = dx; cur.y = dy;
				cur.k = dk;
				q.push(cur);
			}
		}
		if (y == n - 1)
		{
			if (k == 1 || k == 2 || k == 3 || k == 4)
			{
				dk = k%4 + 1;dx = x; dy = 0;
			}
			if (!k)
			{
				dk = 2; dx = 0; dy = n - 1 - x;
			}
			if (k == 5)
			{
				dk = 2;
				dx = n - 1; dy = x;
			}
			if (a[dk][dx][dy] == c)
			{
				a[dk][dx][dy] = 0;
				cur.x = dx; cur.y = dy;
				cur.k = dk;
				q.push(cur);
			}
		}
	}
}

int main ()
{
	freopen ("newcut.in", "r", stdin);
//	freopen ("newcut.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf ("%d", &a[0][i][j]);
	for (int i = 0; i < n; i++)
		for (int k = 1; k <= 4; k++)
			for (int j = 0; j < n; j++)
				scanf ("%d", &a[k][i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf ("%d", &a[5][i][j]);
			int res = 0;
	for (int k = 0; k < 6; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (a[k][i][j])
					{res++;bfs(k, i, j);}
	FILE *out = fopen("newcut.out", "w");
	fprintf(out,"%d", res);
	return 0;
}

