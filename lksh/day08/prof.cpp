#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

void zf(char s[], int n, int z[]) {
	int l, r; l = r = -1;
	for (int i = 1; i < n; i++)
		if (z[i-l]+i <= r)
			z[i] = z[i-l];
		else {
			l = i;
			if (i > r) r = i;
			for (z[i] = r-i; r < n; r++, z[i]++)
				if (s[r] != s[z[i]])
					break;
			r--;
		}
}

const int N = 3010;
int n, z[N], w[N], take, ans;
char s[N];
int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++) {
		memset(z, 0, sizeof z);
		zf(s + i, n - i, z + i);
		take = 0;
		for (int j = i + 1; j < n; j++)
			take = max(take, min(z[j], j - i));
		int pl = 0;
		for (int j = i + 1; j < n; j++)
			if (min(z[j], j - i) == take)
				pl = max(pl, take - w[j]);
		for (int j = i + 1; j < n; j++)
			w[j] = max(w[j], min(take, z[j]));
		
		ans += pl;
	}
	printf("%d\n", ans);
	return 0;
}
