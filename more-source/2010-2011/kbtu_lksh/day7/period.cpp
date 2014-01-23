#include <cstdio>
#include <cstring>

char s[1000100];
int n, pi[1000100], j;

int main() {
    freopen("period.in", "r", stdin);
    freopen("period.out", "w", stdout);
    scanf("%s", s);
    n = strlen(s);
    for (int i = 1; i < n; i++) {
        while (j > 0 && s[j] != s[i])
            j = pi[j - 1];
        if (s[j] == s[i])
            j++;
        pi[i] = j;
    }
    j = n - j;
    if (j && (n % j == 0))
        printf("%d\n", j);
    else printf("%d\n", n);
    return 0;
}

