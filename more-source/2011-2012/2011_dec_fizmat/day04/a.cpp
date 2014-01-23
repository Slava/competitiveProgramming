#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100100;
int n, k, z[N], s[N], l, r, j;

int main() {
	freopen("cubes.in", "r", stdin);
	freopen("cubes.out", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", s + i);
	l = 0; r = -1;
	for (int i = 0; i < n; i++) {
		int k = (i > r ? 0 : min(z[l + r - i + 1], r - i + 1)) + 1;
		while (i + k - 1 < n && i - k >= 0 && s[i - k] == s[i + k - 1])
			k++;
		z[i] = --k;
		if (i + k - 1 > r)
			r = i + k - 1, l = i - k;
		if (z[i] == i)
			printf("%d ", n - i);
	}
	return 0;
}
