#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define pb push_back
#define MAX_N 101010
#define INF (1<<30)

int n, m, res;
std::vector<int> g[MAX_N];
int result[MAX_N][2];
bool u[MAX_N];

void dp(int v, int p = -1, int output = -1) {
  if (u[v] && output < 0)
    return;
  u[v] = true;
  int &res0 = result[v][0];
  int &res1 = result[v][1];

  int minCostDiff = INF;
  int minCostDiffV = -1;

  res0 = 0;
  res1 = 0;

  for (unsigned int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (to == p)
      continue;

    dp(to, v);

    int r0 = result[to][0], r1 = result[to][1];
    int minCostDiffC;

    if (r0 > r1) {
      res0 += r0;
      minCostDiffC = 0;
    } else {
      res0 += r1;
      minCostDiffC = r1 - r0;
    }

    if (minCostDiffC < minCostDiff) {
      minCostDiff = minCostDiffC;
      minCostDiffV = to;
    }
  }

  res1 = std::max(res0, res0 - minCostDiff + 1);

  if (output > -1) {
    for (unsigned int i = 0; i < g[v].size(); i++) {
      int to = g[v][i];
      if (to == p)
        continue;

      if (result[to][0] > result[to][1] || (to == minCostDiffV && output == 1))
        dp(to, v, 0);
      else
        dp(to, v, 1);

      if (to == minCostDiffV && output > 0 && res1 == res0 - minCostDiff + 1) {
        printf("%d %d\n", v + 1, to + 1);
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int x, y; scanf("%d%d", &x, &y); x--; y--;
    g[x].pb(y); g[y].pb(x);
  }

  int root = rand() % n;
  dp(root);
  res = result[root][1];

  printf("%d\n", res);
  dp(root, -1, 1);

  return 0;
}

