#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

int n, m, k, can[256], fx, fy, sx, sy;
int d[] = {0,1,1,0,-1,0,0,-1};
int a[70][70], ans = (1 << 30);
char Map[70][70];
bool u[70][70];
queue<int>qx, qy, Qx[2], Qy[2];
string strans, str;

bool check(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void path(int steps){
	str = "";steps--;
	int x, y, dx, dy, mn;char want;
	Qx[steps & 1].push(sx);
	Qy[steps & 1].push(sy);
	for(;steps >= 0; steps--){
		queue<int> &qX = Qx[steps & 1], &qY = Qy[steps & 1],
				   &nx = Qx[(steps + 1) & 1], &ny = Qy[(steps + 1) & 1];
		want = 'z' + 1;
		memset(u, 0, sizeof u);
		while (!qX.empty()){
			x = qX.front(); y = qY.front();
			qX.pop(); qY.pop(); 
			for (int i = 0; i < 8; i += 2) {
				dx = x + d[i]; dy = y + d[i + 1];
				if (!check(dx,dy))continue;
				if (a[dx][dy] != a[x][y] - 1)continue;
				if (Map[dx][dy] < want){
					while(!nx.empty())nx.pop(), ny.pop();
					want = Map[dx][dy];
				}
				if (Map[dx][dy] == want && !u[dx][dy])
					nx.push(dx), ny.push(dy), u[dx][dy] = 1;
			}
		}
		if (want == 'T')break;
		str.push_back(want);
	}
}

void solve(){
	int x, y, dx, dy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = (1 << 30);
		}
	}
	qx.push(fx);qy.push(fy);
	a[fx][fy] = 0;
	while (!qx.empty()){
		x = qx.front();
		y = qy.front();
		qx.pop();qy.pop();
		for (int i = 0; i < 8; i += 2){
			dx = x + d[i]; dy = y + d[i + 1];
			if (check(dx, dy) && a[dx][dy] > a[x][y] + 1 && can[Map[dx][dy]]){
				a[dx][dy] = a[x][y] + 1;
				qx.push(dx);qy.push(dy);
			}
		}
	}
	if (a[sx][sy] == (1 << 30))return;
	if (a[sx][sy] < ans){
		ans = a[sx][sy];
		path(a[sx][sy]);
		strans = str;
	}
	else if (a[sx][sy] == ans){
		path(a[sx][sy]);
		if (str < strans)
			strans = str;
	}
}

void rec (int d, int i = 0){
	if (d == k){
		solve();
		return;
	}
	for(; i < 27; i++){
		can['a' + i] = 1;
		rec(d + 1, i + 1);
		can['a' + i] = 0;
	}
}

/* START */
int main (){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s", Map[i]);
		for (int j = 0; j < m; j++) {
			if (Map[i][j] == 'S')
				sx = i, sy = j;
			if (Map[i][j] == 'T')
				fx = i, fy = j;
		}
	}
	can['S'] = can['T'] = 1;
	rec(0);
	if (ans < (1 << 30))
		printf("%s\n", strans.c_str());
	else printf("-1\n");
	return 0;
}

/*
3 4 2
cccT
aaca
Sdab
*/




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: May 16, 2011 11:40:45 AM
// contest: 84
// link: /contest/84/submission/456561
// time: 470 ms
// verdict: Accepted
// problem: 84E - Track
// ID: 456561
// downloaded by very stupid script
