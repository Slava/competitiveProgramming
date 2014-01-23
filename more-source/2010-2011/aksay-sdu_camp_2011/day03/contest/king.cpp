#include <iostream>
#include <cstdio>

using namespace std;

#ifdef _WIN32_ || __WIN32__
#define i64 "%I64d"
#else
#define i64 "%lld"
#endif

int const N=52, L=62;
int g[N][2], f[N], l;
long long z[L][N];
void kth(long long k, char *s, int x = 1, int len = l) {
	if(!len) {
		s[0]='\0';
		return;
	}
	if (k <= z[len - 1][g[x][0]]) {
		s[0] = '0';
		kth(k, s + 1, g[x][0], len - 1);
	}
	else {
		s[0] = '1';
		kth(k - z[len - 1][g[x][0]], s + 1, g[x][1], len - 1);
	}
}
void kth(char *s, long long &k, int x = 1, int len = l) {
	if (!len) {
		k = 1;
		return;
	}
	if (s[0] == '0')
		kth(s + 1, k, g[x][0], len - 1);
	else {
		kth(s + 1, k, g[x][1], len - 1);
		k += z[len - 1][g[x][0]];
	}
}
int main () {
	freopen ("king.in", "r", stdin);
	freopen ("king.out", "w", stdout);

	int n, m, ff, q, i, a, b, j, d;
	long long k;
	char c, s[100];

	scanf ("%d%d%d%d%d", &n, &m, &ff, &l, &q);
	for (i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &d);
		g[a][d] = b;
	}
	for (i = 0; i < ff; i++) {
        scanf("%d", &a);
		f[a] = 1;
	}
	for (i = 1; i <= n; i++)
		z[0][i] = f[i];
	for (i = 1; i <= l; i++)
		for (j = 1; j <= n; j++)
			z[i][j] = z[i - 1][g[j][0]] + z[i - 1][g[j][1]];
	for(i = 0; i < q; i++) {
        scanf("\n%c", &c);
		if (c == '?') {
			scanf(i64, &k);
			kth(k, s);
			printf("%s\n", s);
		}
		else {
            if(c == '!') {
                scanf("%s", s);
                kth(s, k);
                printf(i64"\n", k);
            }
            else {
                if (c == '>') {
                    scanf("%s", s);
                    kth(s, k);
                    kth(++k, s);
                    printf("%s\n", s);
                }
                else {
                    if (c == '<') {
                        scanf("%s", s);
                        kth(s, k);
                        kth(--k, s);
                        printf("%s\n", s);
                    }
                }
            }
		}
	}
}
