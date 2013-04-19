#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

const int N = 6100;
int S, T, n, l[N], q[N + N], h, t, ptr[N];
int a[500][500];
map<int,int> f[N], c[N];
vector<int> g[N];

bool bfs() {
    for (int i = 0; i < n; i++)
        l[i] = 0;
    l[S] = 1;
    h = t = 0;
    q[t++] = S;
    while(h < t) {
        int v = q[h++];
        for (int j = 0; j < (int)g[v].size(); j++) {
            int i = g[v][j];
            if (c[v][i] - f[v][i] > 0 && !l[i]) {
                l[i] = l[v] + 1;
                q[t++] = i;
            }
        }
    }
    return l[T] != 0;
}

int dfs(int v, int flow) {
    if (v == T)
        return flow;
    for (int &j = ptr[v]; j < (int)g[v].size(); j++) {
        int i = g[v][j];
        if (c[v][i] - f[v][i] <= 0 || l[i] != l[v] + 1)
            continue;
        int push = dfs(i, min(flow, c[v][i] - f[v][i]));
        if (push != 0) {
            f[v][i] += push;
            f[i][v] = -f[v][i];
            return push;
        }
    }
    return 0;
}


int R, C, NN;
char s[500][500];

int main() {
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; i++)
        scanf("%s", s[i]);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (s[i][j] != '.')
                a[i][j] = ++n;
    NN = n;
    T = n + n + 1;
    for (int i = 0; i <= T; i++) {
        g[0].push_back(i);
        g[i].push_back(0);
        g[T].push_back(i);
        g[i].push_back(T);
    }
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (a[i][j]) {
                int cur = a[i][j];
                c[0][cur] = s[i][j] == 'H' ? 1 :
                            s[i][j] == 'O' ? 2 :
                            s[i][j] == 'N' ? 3 :
                            s[i][j] == 'C' ? 4 : 0;
                c[cur + n][T] = c[0][cur];
                if (i > 0 && a[i - 1][j]) {
                    c[cur][a[i - 1][j] + n] = 1;
                    g[cur].push_back(a[i - 1][j] + n);
                    g[a[i - 1][j] + n].push_back(cur);
                }
                if (j > 0 && a[i][j - 1]) {
                    c[cur][a[i][j - 1] + n] = 1;
                    g[cur].push_back(a[i][j - 1] + n);
                    g[a[i][j - 1] + n].push_back(cur);
                }
                if (i != R - 1 && a[i + 1][j]) {
                    c[cur][a[i + 1][j] + n] = 1;
                    g[cur].push_back(a[i + 1][j] + n);
                    g[a[i + 1][j] + n].push_back(cur);
                }
                if (j != C - 1 && a[i][j + 1]) {
                    c[cur][a[i][j + 1] + n] = 1;
                    g[cur].push_back(a[i][j + 1] + n);
                    g[a[i][j + 1] + n].push_back(cur);
                }
            }
    n = n + n + 2;
    for (; bfs(); ) {
        memset(ptr, 0, sizeof ptr);
        while(dfs(S, (1 << 30)));
    }
    int ans = 0, need = 0;
    for (int i = 0; i < n; i++) {
        ans += f[S][i];
        need += c[S][i];
    }
    if (ans != need || !need) {
        printf("Invalid\n");
    }
    else printf("Valid\n");
    return 0;
}

