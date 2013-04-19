#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, z[400100], l, r, j;
char s[400100];
unsigned long long ans;

int main() {
	scanf("%s", s);
	n = strlen(s);
	l = 0; r = -1;
	for (int i = 0; i < n; i++) {
		int k = (i > r ? 0 : min(z[l + r - i], r - i) + 1);
		while (i - k >= 0 && i + k < n && s[i - k] == s[i + k])
			k++;
		z[i] = --k;
		if (r < i + k)
			l = i - k, r = i + k;
		ans += z[i];
	}
	l = 0; r = -1;
	for (int i = 0; i < n; i++) {
		int k = (i > r ? 0 : min(z[l + r - i + 1], r - i + 1)) + 1;
		while (i + k - 1 < n && i - k >= 0 && s[i - k] == s[i + k - 1])
			k++;
		z[i] = --k;
		if (i + k - 1 > r)
			r = i + k - 1, l = i - k;
		ans += z[i];
	}
	printf("%llu\n", ans);
	return 0;
}
