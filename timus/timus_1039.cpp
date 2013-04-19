#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
int n, w[6010], dw[6010], dq[6010], uq[6010], uw[6010];
vi g[6010];
int dfsw (int);
int dfsq (int);

int main (){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", w + i);
	for (int x, y;;){
		scanf("%d%d", &x, &y);
		if (!x && !y)break;
		x--;y--;
		g[y].push_back(x);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, max(dfsw(i), dfsq(i)));
	printf("%d\n", ans);
	return 0;
}

int dfsq (int v){
	if (uq[v])
		return dq[v];
	int &res = dq[v];
	uq[v] = 1;
	for (vi::iterator j = g[v].begin(); j != g[v].end(); j++){
		int i = *j, t = dfsw(i), q = dfsq(i);
		if (q > t)
			t = q;
		if (t > 0)
			res += t;
	}
	return res;
}

int dfsw (int v){
	if (uw[v])
		return dw[v];
	int &res = dw[v];
	res = w[v];
	uw[v] = 1;
	for (vi::iterator j = g[v].begin(); j != g[v].end(); j++){
		int i = *j, t = dfsq(i);
		if (t > 0)
			res += t;
	}
	return res;
}

