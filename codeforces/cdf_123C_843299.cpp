#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, x, a[300], d[300];
long long k, inf = (long long)1e9 * (long long)1e9 + 1;
long long dp[300][300];
bool used[300][300];
char s[300];

bool cmp(int x, int y) {
    return a[x] < a[y];
}

long long go(int pos, int bal) {
    if (used[pos][bal])
        return dp[pos][bal];
    long long &res = dp[pos][bal];
    res = 0;
    used[pos][bal] = 1;
    if (pos == n + m - 1)
        return !bal;
    if (s[pos] == '*') {
        res += go(pos + 1, bal + 1);
        if (bal > 0)
            res += go(pos + 1, bal -  1);
    }
    else if (s[pos] == '(')
        res = go(pos + 1, bal + 1);
    else if (s[pos] == ')' && bal > 0)
        res = go(pos + 1, bal - 1);
    res = min(res, inf);
    return res;
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d%d%I64d", &n, &m, &k);
    for (int i = 0; i < n + m; i++) {
        a[i] = n * m;
        d[i] = i;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &x);
            if (a[i + j] > x)
                a[i + j] = x;
        }

    sort(d, d + n + m - 1, cmp);

    k--;
    memset(s, '*', sizeof s);
    for (int i = 0; i < n + m - 1; i++) {
        memset(used, 0, sizeof used);
        int p = d[i];
        s[p] = '(';
        long long cost = go(0,0);
        if (k >= cost) {
            s[p] = ')';
            k -= cost;
        }
//        printf("finished %d. %I64d\n", i, k);
//        fflush(stdout);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%c", s[i + j]);
        puts("");
    }

    return 0;
}




// lang: GNU C++
// memory: 2100 KB
// author: imslavko
// submit_date: Nov 9, 2011 7:00:55 PM
// contest: 123
// link: /contest/123/submission/843299
// time: 60 ms
// verdict: Accepted
// problem: 123C - Brackets
// ID: 843299
// downloaded by very stupid script
