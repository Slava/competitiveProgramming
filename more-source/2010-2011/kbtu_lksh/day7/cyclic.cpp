#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>

using namespace std;

const int maxlen = 2010010;

typedef int uiint;
char S[maxlen];
int n, N, c;
uiint P = 31, pr[maxlen], p[maxlen];

uiint h(int l, int r) {
    uiint h = pr[r];
    if (l)
        h -= pr[l - 1];
    h *= p[N - l - 1];
    return h;
}
bool cmp(int f, int s) {
    int l = 0, r = n - 1, m;
    if (S[f] != S[s])
        return S[f] < S[s];
    while (l <= r) {
        m = (l + r) / 2;
        if (h(f, f + m) == h(s, s + m))
            l = m + 1;
        else r = m - 1;
    }
    return S[f + l] < S[s + l];
}

int main() {
    freopen("cyclic.in", "r", stdin);
    freopen("cyclic.out", "w", stdout);

    scanf("%s", S);
    n = strlen(S);
    N = 2 * n;
    for (int i = 0; i < n; i++)
        S[i + n] = S[i];
    p[N - 1] = 1;
    for (int i = N - 2; i >= 0; i--)
        p[i] = p[i + 1] * P;
    for (int i = 0; i < n * 2; i++) {
        if (i) pr[i] = pr[i - 1];
        pr[i] += (S[i] - 'a' + 1) * p[i];
    }
    for (int i = 1; i < n; i++)
        c += cmp(i, 0);
    printf("%d\n", c + 1);
    return 0;
}

