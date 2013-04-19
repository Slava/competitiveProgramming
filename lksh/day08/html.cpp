#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

const int SIZE = 550;
typedef long long ll;
char c, s[10100];
int n, m, a[SIZE], r, d[SIZE][SIZE];
map<ll, int>Map;
ll h, P;

int get(int l, int r) {
	if (l > r)
		return 0;
	if (l == r)
		return 1;
	if (d[l][r] != -1)
		return d[l][r];
	d[l][r] = r - l + 1;
	d[l][r] = min(d[l][r], 1 + get(l + 1, r));
	if (a[l] & 1)
		return d[l][r];
	for (int i = 0; i <= r - l; i++)
		if (a[r - i] == (a[l] ^ 1))
			d[l][r] = min(d[l][r], get(l + 1, r - i - 1) + get(r - i + 1, r));
	return d[l][r];
}

int input_tag() {
	bool was, cl;
	was = cl = m = 0;
	while (!was) {
		scanf("%c", &c);
		if (c == '/') {
			cl = 1; continue;
		}
		if (c == ' ')
			break;
		if (c == '>') {
			was = 1;
			break;
		}
		s[m++] = c;
	}
	while (!was) {
		scanf("%c", &c);
		if (c == '>')
			was = 1;
	}
	h = 0; P = 1;
	for (int i = 0; i < m; i++, P *= 97)
		h += P * (s[i] - 31);
	if (!Map.count(h))
		Map[h] = n++;
	s[m] = 0;
	return Map[h] * 2 + cl;
}

int main() {
	memset(d, -1, sizeof d);
	
	while (scanf("%c", &c) == 1)
		if (c == '<')
			a[r++] = input_tag();

	int ans = r;
	r--;
	ans = get(0, r);
	printf("%d\n", ans);
	return 0;
}
