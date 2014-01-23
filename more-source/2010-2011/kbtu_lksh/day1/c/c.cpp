#define file "heaps2"
#include <cstdio>
#include <iostream>

using namespace std;

int n, m, a[30], N;
bool d[1000100];

int main() {
    freopen(file ".in", "r", stdin);
    freopen(file ".out", "w", stdout);

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
    scanf("%d", &m);
    for (int i = 1; i < 1000100; i++) {
        for (int j = 0; j < N; j++) {
            if(i - a[j] >= 0 && d[i - a[j]] == 0) {
                d[i] = 1; break;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &n);
        printf("%s\n", d[n] ? "First" : "Second");
    }
    return 0;
}
