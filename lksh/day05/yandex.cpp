#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000100;
char str[N], s[N + N];
int n, k, m, p[N], l, r, co, need[N], mn, mx, z[N + N], bef;
int main() {
	while (~scanf("%d%d", &n, &k)) {
		if (!n && !k)break;
		scanf("%s", str); ++co;
		for (int i = 0; i < k; i++)
			scanf("%d", p + i);
		sort(p, p + k);
		s[0] = z[0] = l = r = 0;
		m = p[0] - 1; n -= m;
		strcat(s, str + m); strcat(s, "$");strcat(s, str);
		mx = n; mn = 0; bef = 0;
		for (int i = 0; i < k; i++)
			p[i] -= m + 1, need[p[i]] = co;
		for (int i = 1; i < n + m + 1; i++) {
			int k = (i > r ? 0 : min(z[i - l], r - i + 1));
			while (i + k < n + m + 1 && s[k] == s[i + k])
				k++;
			z[i] = k;
			if (r < i + k - 1)
				r = i + k - 1, l = i;
			if (need[i] == co)
				mx = min(mx, z[i]);
			else mn = max(mn, z[i]);
			if (i >= n)
				bef = max(bef, z[i]);
		}
		mn++;
		if (bef >= mn)
			mx = -10000;
		if (mn <= mx)
			printf("Correct. Length = %d..%d.\n", mn, mx);
		else printf("Mistake.\n");
	}
	return 0;
}
