#include <cstdio>
#include <queue>

using namespace std;

struct pos{
	int x, y, p;
};
const int N = 1010;
int n, m, sx, sy, fx, fy, here, 
	a[N][N][4], inf = (1 << 30),
	d[] = {1,2, 2,1, -1,2, 2,-1, 1,-2, -2,1, -1,-2, -2,-1};
pos f, s;
bool cant[N][N][4];
queue<pos> q;

bool check(int x, int y)
{	return x >= 1 && x <= n && y >= 1 && y <= m;	}

void paint (int x, int y)
{
	if (check(x, y))
		cant[x][y][here] = 
		cant[x][y][3] = 1;
}

void put (pos s)
{
	if (s.p == 1)
		paint(s.x, s.y + 1),
		paint(s.x, s.y - 1),
		paint(s.x + 1, s.y),
		paint(s.x - 1, s.y),
		paint(s.x + 1, s.y + 1),
		paint(s.x - 1, s.y - 1),
		paint(s.x + 1, s.y - 1),
		paint(s.x - 1, s.y + 1);
	if (s.p == 2 || s.p == 3)
		for (int i = 1; i <= 1000; i++)
			paint(s.x + i, s.y),
			paint(s.x - i, s.y),
			paint(s.x, s.y + i),
			paint(s.x, s.y - i);
	if (s.p == 2 || s.p == 5)
		for (int i = 1; i <= 1000; i++)
			paint(s.x + i, s.y + i),
			paint(s.x - i, s.y - i),
			paint(s.x - i, s.y + i),
			paint(s.x + i, s.y - i);
	if (s.p == 4)
		for (int i = 0; i < 16; i += 2)
			paint(s.x + d[i], s.y + d[i + 1]);
}

int main ()
{
	freopen ("hors2.in", "r", stdin);
	freopen ("hors2.out", "w", stdout);
	
	scanf ("%d%d", &n, &m);
	scanf ("%d%d%d", &f.p, &f.x, &f.y);
	scanf ("%d%d%d", &s.p, &s.x, &s.y);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 0; k < 4; k++)
				a[i][j][k] = inf;
	here = 1; put(f);
	here = 2; put(s);
	scanf ("%d%d%d%d", &sx, &sy, &fx, &fy);
	a[sx][sy][3] = 0;
	pos start; start.x = sx, start.y = sy, start.p = 3;
	q.push(start);
	while(!q.empty())
	{
		start = q.front();
		q.pop();
//		printf("cur pos : %d %d %d\n", start.x, start.y, start.p);
		for (int i = 0; i < 16; i += 2)
		{
			int dx = start.x + d[i], dy = start.y + d[i + 1];
			if (check(dx,dy) && !cant[dx][dy][start.p])			{
				pos to; to.x = dx; to.y = dy; to.p = start.p;
				if (dx == s.x && dy == s.y && ((to.p >> 1)&1))
					to.p -= 2;
				if (dx == f.x && dy == f.y && (to.p & 1))
					to.p -= 1;
				if (a[dx][dy][to.p] > a[start.x][start.y][start.p])
				{
					a[dx][dy][to.p] = a[start.x][start.y][start.p] + 1;
					q.push(to);
				}
			}
		}
	}
	int ans = inf;
	for (int i = 0; i < 4; i++)
//		printf("%d\n", a[fx][fy][i]);
		ans = min(ans, a[fx][fy][i]);
	if (ans == inf)
		ans = -1;
	printf("%d", ans);
	return 0;
}

