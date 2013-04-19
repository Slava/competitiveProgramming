#include <cstdio>
#define bit(x, y) ((x>>(y))&1)
#define min(a,b) (a<b?a:b)

const int inf = 1e9;
int n, m;
int nxt[80];
int d[2][1 << 8][1 << 8];
bool gd[1 << 8];

void input()
{
	scanf ("%d%d", &n, &m);
	char s[9];
	for (int i = 0; i < n; i++)
	{
		scanf ("%s", s);
		for (int j = 0; j < m; j++)
			if (s[j] == '*')
				nxt[i] |= (1 << j);
	}
}

bool good (int x)
{
	for (int i = 1; i < m; i++)
		if (!bit(x,i) && !bit(x, i - 1))
			return 0;
	return 1;
}

void go (int x, int y, int p, int p1, int p2, int c)
{
	if (y == m)
	{
		d[!x][p1][p2] = min(d[!x][p1][p2], c);
		return ;
	}
	int bp = bit(p,y),
		bp1 = bit(p1,y),
		bp2 = bit(p2, y);
	if (bp1)
		go (x, y + 1, p, p1, p2, c);
	if (bp && !bp1 && (!y || bit(p1, y - 1)))
		go (x, y + 1, p, p1, p2, c);
	if (!bp1 && !bp2)
		go(x, y + 1, p, p1 | (1 << y), p2 | (1 << y), c + 1);
	if (!bp1 && y + 1 < m && !bit(p1, y + 1))
		go (x, y + 2, p, p1 | (1 << y) | (1 << (y + 1)), p2,  c + 1);
}

int main ()
{
	input();
	for (int k = 0; k < (1 << m); k++)
		for (int j = 0; j < (1 << m); j++)
			d[0][j][k] = inf;
	for (int i = 0; i < (1 << m); i++)
		gd[i] = good(i);
	d[0][(1 << m) - 1][nxt[0]] = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < (1 << m); j++)
			for (int k = 0; k < (1 << m); k++)
				d[(i + 1)%2][j][k] = inf;
		for (int j = 0; j < (1 << m); j++)
			for (int k = 0; k < (1 << m); k++)
				if (d[i%2][j][k] != inf && gd[j])
					go (i%2, 0, j, k, nxt[i + 1], d[i%2][j][k]);
	}
	int res = inf;
	for (int i = 0; i < (1 << m); i++)
		if(gd[i])res = min(d[n%2][i][0], res);
	printf("%d", res);
	return 0;
}

