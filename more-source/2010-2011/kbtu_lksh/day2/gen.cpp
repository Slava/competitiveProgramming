#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n = 100000, m = 100000;
    vector<int> a(n);
    for (int i = 1; i <= n; i++)
        a[i - 1] = i;
    for (;;) {
        FILE *out = fopen("permutations.in", "w");
        random_shuffle(a.begin(), a.end());
        fprintf(out, "%d %d\n", n, m);
        for (int i = 0; i < n; i++)
            fprintf(out, "%d ", a[i]);
        fprintf(out, "\n");
        for (int i = 0; i < m; i++) {
            int x, y, k, l;
            x = rand() % n + 1;
            y = rand() % n + 1;
            k = rand() % n + 1;
            l = rand() % n + 1;
            if (x > y)swap(x, y);
            if (k > l)swap(k, l);
            fprintf(out, "%d %d %d %d\n", x, y, k, l);
        }
        fclose(out);
        puts("gened");
        system("permutations.exe");
        puts("Slavko end");
        system("copy permutations.out ans");
        system("dauren.exe");
        puts("Dauren end");
        if (system("FC permutations.out ans"))
            break;
    }
}
