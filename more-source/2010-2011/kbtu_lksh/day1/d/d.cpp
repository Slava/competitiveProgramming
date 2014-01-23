#define file "comfort"
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, gr[200];
bool was[200];
int doit(int n) {
    if (was[n])
        return gr[n];
    was[n] = 1;
    vector<int>w(n + 1, 0);
    for (int i = 2; i < n; i++)
        w[doit(i - 1) ^ doit(n - i)] = 1;
    int &res = gr[n];
    while (w[res])
        res++;
    return res;
}

int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);

    scanf("%d", &n);
    was[3] = was[2] = was[1] = 1; gr[3] = 1;
    printf("%s\n", doit(n + 2) ? "FIRST" : "SECOND");

    return 0;
}
