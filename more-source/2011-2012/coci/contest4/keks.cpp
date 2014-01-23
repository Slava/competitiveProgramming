#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 500100;
int n, k;
char s[N], u[N];

typedef pair<int,int> ii;

ii t[N*4];
void upd(int i, ii x) {
	i += n;
	t[i] = x;
	while (i /= 2)
		t[i] = max(t[i+i],t[i+i+1]);
}

ii get(int l, int r) {
	ii ret(-1,-1);
	l += n; r += n;

	while (l <= r) {
		if (l & 1)
			ret = max(ret, t[l]);
		if (!(r&1))
			ret = max(ret, t[r]);

		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}

	return ret;
}

int main() {
	scanf("%d%d%s", &n, &k, s);

	for (int i = 0; i < n; i++)
		upd(i, ii(s[i]-'0',-i));

	int i = 0;

	while (k > 0) {
		if (n-i == k) {
			i = n; break;
		}	
		ii best = get(i, i+k);
		printf("%d", best.first);
		k -= -best.second - i;
		i = -best.second + 1;
	}

	while (i < n)
		printf("%c", s[i++]);
	puts("");

	return 0;
}
