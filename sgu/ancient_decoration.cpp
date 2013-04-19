// 286
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2000;
typedef vector<int> vi;
int n, m, k, ans, a[N][N], st[N], x, y;
vi g[N], eu, u, mt;
vector<pair<int,int> > edge;

void euler (int v){
	while (st[v])
		for (int i = 0; i < n; i++)if(a[v][i]){
			a[v][i]--, a[i][v]--;
			st[v]--;st[i]--;
			euler(i);
		}
	eu.push_back(v);
}

bool dfs (int v){
	if (u[v])return false;
	u[v] = true;
	for (vi::iterator i = g[v].begin(); i != g[v].end(); ++i)
		if (mt[*i] == -1 || dfs(mt[*i])){
			mt[*i] = v;
			return true;
		}
	return false;
}

int main (){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n * k / 2; i++){
		scanf("%d%d", &x, &y);
		a[--x][--y] = a[y][x] = 1;
		st[x]++;st[y]++;
		if (x > y)swap(x,y);
		edge.push_back(make_pair(x,y));
	}
	for (int i = 0; i < n; i++)
		if (st[i]){
			euler(i);
			for (int j = 1; j < eu.size(); j++)
				g[eu[j - 1]].push_back(eu[j]);
			if (eu.back() != eu.front())
				g[eu.back()].push_back(eu.front());
			eu.clear();
		}
	mt.assign(n, -1);
	for (int i = 0; i < n; i++){
		u.assign(n, 0);
		dfs(i);
	}
	for (int i = 0; i < n; i++)
		ans += mt[i] != -1;
	if (ans == n){
		puts("YES");
		for (int i = 0; i < n; i++){
			x = i, y = mt[i];
			if (x > y)swap(x,y);
			for (int j = 0; j < edge.size(); j++)
				if (x == edge[j].first && y == edge[j].second){
					printf("%d\n", j + 1);break;}
		}
	} else puts("NO");
	return 0;
}


