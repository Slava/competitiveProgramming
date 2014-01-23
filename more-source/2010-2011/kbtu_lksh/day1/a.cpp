#include <cstdio>
#include <cstring>

int gr[6000], w[6000], a, b, c;
int main() {
    for (int i = 2; i <= 5000; i++) {
        memset(gr, 0, sizeof gr);
        for (int j = 1; j <= i / 2; j++)
            w[gr[i - j]]++;
        for (; w[gr[i]]; w++);
    }
    scanf("%d%d%d", &a, &b, &c);
    printf("%s\n", gr[a]^gr[b]^gr[c] ? );
    // finish it
    return 0;
}

