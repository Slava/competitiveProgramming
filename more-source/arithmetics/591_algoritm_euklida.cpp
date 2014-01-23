#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

const int N = 100100;
struct edge {
	int x, y, c, id;
	edge(int _, int __, int ___, int ____) {
		x = _; y = __; c = ___; id = ____;
	}
};

int n, m, cnt;
vector<edge> e;
vector<int> ans;

int p[N], r[N];
int get(int x) {
	return x == p[x] ? x : (p[x] = get(p[x]));
}

void unite(int x, int y) {
	if (r[x] < r[y])
		swap(x, y);
	p[y] = x;
	r[x] += r[y];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		e.push_back(edge(x,y,c-1,i+1));
	}

	while (true) {
		if (double(clock())/CLOCKS_PER_SEC > 0.90)
			break;
		random_shuffle(e.begin(), e.end());
		ans.clear(); cnt = 0;
		for (int i = 1; i <= n; i++)
			p[i] = i, r[i] = 1;
		for (vector<edge>::iterator ed = e.begin(); ed != e.end(); ed++) {
			int x = ed->x, y = ed->y, c = ed->c;
			if (get(x) == get(y)) continue;
			unite(x,y); ans.push_back(ed->id);
			cnt += c;
		}
		if (cnt & 1) continue;
		bool ok = 1;
		for (int i = 1; ok && i <= n; i++)
			if (get(i) != get(1))
				ok = 0;
		if (!ok) continue;
		for (int i = 0; i < (int)ans.size(); i++)
			printf("%d\n", ans[i]);
		return 0;
	}

	printf("-1");
	return 0;
}
