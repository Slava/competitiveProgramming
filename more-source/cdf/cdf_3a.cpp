#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

#define x first
#define y second
#define dbg(x) cout<<#x<<" = "<<x<<"\n";
string ans[] = {"L", "LD", "D", "RD", "R", "RU", "U", "LU"}, 
		start, finish, answer;
int sx, sy, fx, fy, dx, dy, a[10][10],
	d[] = {1,0, 1,1, 0,1, -1,1, -1,0, -1,-1, 0,-1, 1,-1};
queue<pair<int, int> >q;

bool check (int x, int y, int D)
{
	return x && y && x < 9 && y < 9 && a[x][y] > D;
}

int main ()
{
	cin >> start >> finish;
	sx = start[0] - 'a' + 1;
	sy = start[1] - '0';
	fx = finish[0] - 'a' + 1;
	fy = finish[1] - '0';
	memset (a, 0x2710, sizeof a);
	a[sx][sy] = 0;
	q.push(make_pair(sx,sy));
	while (q.size())
	{
		dx = q.front().x;
		dy = q.front().y;
		q.pop();
		for (int i = 0; i < 16; i++)
			if (check(dx + d[i*2], dy + d[i*2+1], a[dx][dy] + 1))
			{
				a[dx + d[i*2]][dy + d[i*2+1]] = a[dx][dy] + 1;
				q.push(make_pair(dx + d[i*2], dy + d[i*2+1]));
			}
	}
	cout << a[fx][fy] << "\n";
	while (fx != sx || fy != sy)
	{
		for (int i = 0; i < 16; i++)
			if (check(fx + d[i*2], fy + d[i*2+1], -1) && a[fx + d[i*2]][fy + d[i*2+1]] == a[fx][fy] - 1)
			{
				answer = ans[i] + "\n" + answer;
				fx += d[i*2];
				fy += d[i*2+1];
				break;
			}
	}
	cout << answer;
	return 0;
}


