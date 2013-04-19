// slavko - myasko
#include <cstdio>
#include <queue>

using namespace std;

struct pos {	int x, y, k;	} cur, ne;
queue<pos>q;
int n, a[2][50][50], cant[50][50], ch, fx = -1, fy, fk, inf = (1 << 30);
int main ()
{
	freopen("trees.in", "r", stdin);
	freopen("trees.out", "w", stdout);

	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ch = getchar();
			if (ch == 'e')
				if (fx == -1)
					fx = i, fy = j;
				else if (i == fx + 1)
					fk = 1;
				else if (j == fy + 1)
					fk = 0;
			if (ch == '1')
				cant[i][j] = 1;
		}
		scanf("\n");
	}
	cur.x = cur.y = cur.k = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[0][i][j] = a[1][i][j] = inf;
	a[0][0][0] = 0;
	q.push(cur);
	while(!q.empty())
	{
		cur = q.front(); q.pop();
//		printf("%d (%d, %d) %d\n", cur.k, cur.x, cur.y, a[cur.k][cur.x][cur.y]);
		if (!cur.k)
		{
			// to the up
			if (cur.x && !(cant[cur.x - 1][cur.y] | cant[cur.x - 1][cur.y + 1] | cant[cur.x - 1][cur.y + 2]) && a[0][cur.x - 1][cur.y] > a[0][cur.x][cur.y] + 1)
			{
				a[0][cur.x - 1][cur.y] = a[0][cur.x][cur.y] + 1;
				ne = cur;
				ne.x--;
				q.push(ne);
			}
			// to the down
			if (cur.x != n - 1 && !(cant[cur.x + 1][cur.y] | cant[cur.x + 1][cur.y + 1] | cant[cur.x + 1][cur.y + 2]) && a[0][cur.x + 1][cur.y] > a[0][cur.x][cur.y] + 1)
			{
				a[0][cur.x + 1][cur.y] = a[0][cur.x][cur.y] + 1;
				ne = cur;
				ne.x++;
				q.push(ne);
			}
			// to the left
			if (cur.y && !cant[cur.x][cur.y - 1] && a[0][cur.x][cur.y - 1] > a[0][cur.x][cur.y] + 1)
			{
				a[0][cur.x][cur.y - 1] = a[0][cur.x][cur.y] + 1;
				ne = cur;
				ne.y--;
				q.push(ne);
			}
			// to the right
			if (cur.y != n - 3 && !cant[cur.x][cur.y + 3] && a[0][cur.x][cur.y + 1] > a[0][cur.x][cur.y] + 1)
			{
				a[0][cur.x][cur.y + 1] = a[0][cur.x][cur.y] + 1;
				ne = cur;
				ne.y++;
				q.push(ne);
			}
			// rotate
			if (cur.x && cur.x != n - 1 && !(cant[cur.x + 1][cur.y] | cant[cur.x + 1][cur.y + 1] | cant[cur.x + 1][cur.y + 2] | cant[cur.x - 1][cur.y] | cant[cur.x - 1][cur.y + 1] | cant[cur.x - 1][cur.y + 2]) && a[1][cur.x - 1][cur.y + 1] > a[0][cur.x][cur.y] + 1)
			{
				a[1][cur.x - 1][cur.y + 1] = a[0][cur.x][cur.y] + 1;
				ne = cur;
				ne.k = 1;
				ne.x--;ne.y++;
				q.push(ne);
			}
			// take poisson
		}
		else
		{
			// to the left
			if (cur.y && !(cant[cur.x][cur.y - 1] | cant[cur.x + 1][cur.y - 1] | cant[cur.x + 2][cur.y - 1]) && a[1][cur.x][cur.y - 1] > a[1][cur.x][cur.y] + 1)
			{
				a[1][cur.x][cur.y - 1] = a[1][cur.x][cur.y] + 1;
				ne = cur;
				ne.y--;
				q.push(ne);
			}
			// to the right
			if (cur.y != n - 1 && !(cant[cur.x][cur.y + 1] | cant[cur.x + 1][cur.y + 1] | cant[cur.x + 2][cur.y + 1]) && a[1][cur.x][cur.y + 1] > a[1][cur.x][cur.y] + 1)
			{
				a[1][cur.x][cur.y + 1] = a[1][cur.x][cur.y] + 1;
				ne = cur;
				ne.y++;
				q.push(ne);
			}
			// to the up
			if (cur.x && !cant[cur.x - 1][cur.y] && a[1][cur.x - 1][cur.y] > a[1][cur.x][cur.y] + 1)
			{
				a[1][cur.x - 1][cur.y] = a[1][cur.x][cur.y] + 1;
				ne = cur;
				ne.x--;
				q.push(ne);
			}
			// to the down
			if (cur.x != n - 3 && !cant[cur.x + 3][cur.y] && a[1][cur.x + 1][cur.y] > a[1][cur.x][cur.y] + 1)
			{
				a[1][cur.x + 1][cur.y] = a[1][cur.x][cur.y] + 1;
				ne = cur;
				ne.x++;
				q.push(ne);
			}
			// rotate
			if (cur.y && cur.y != n - 1 && !(cant[cur.x][cur.y + 1] | cant[cur.x + 1][cur.y + 1] | cant[cur.x + 2][cur.y + 1] | cant[cur.x][cur.y - 1] | cant[cur.x + 1][cur.y - 1] | cant[cur.x + 2][cur.y - 1]) && a[0][cur.x + 1][cur.y - 1] > a[1][cur.x][cur.y] + 1)
			{
				a[0][cur.x + 1][cur.y - 1] = a[1][cur.x][cur.y] + 1;
				ne = cur;
				ne.k = 0; ne.x++; ne.y--;
				q.push(ne);
			}
			// take poisson
		}
	}
	printf("%d", a[fk][fx][fy]);
//	printf("\n%d %d %d", fk, fx,fy);
	return 0;
}
/*
  y 0 1 2 3 4 5
 x   
 0  c
 1  c
 2  c
 3
 4
*/
