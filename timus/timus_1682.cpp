#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100001;
vector<int>g[100001];
int p[N];

int get(int x) {
	return p[x]==x?x:(p[x]=get(p[x]));
}

void unite(int x, int y) {
	x = get(x);
	y = get(y);
	if(rand()&1)p[y] = x;
	else p[x] = y;
}

int main() {
	int k;
	scanf("%d", &k);

	for (int i = 1; i < N; i++)
		g[(i*1LL*i)%k].push_back(i);

	for (int i = 0; i < N; i++)
		p[i] = i;

	for (int i = 1; i < N; i++) {
		int v = k - (i%k);
		if (v==k)v=0;
		for (int j = 0; j < (int)g[v].size(); j++) {
			int to = g[v][j];
			if (to >= i)
				break;
			if (get(to)==get(i)) {
				printf("%d\n", i);
				return 0;
			}
			unite(to,i);
		}

		int vv = k - ((i*1LL*i)%k);
		for (; vv < i; vv += k) {
			if (binary_search(g[v].begin(),g[v].end(),vv))
				continue;
			if (get(vv)==get(i)) {
				printf("%d\n", i);
				return 0;
			}
			unite(vv,i);
		}
	}

	assert(0);
	return 0;
}
