#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 100110;
int l, r, mn[N*4], mx[N*4], n = 100010;
int getmin(int i = 1, int tl = 0, int tr = n - 1) {
	if (l <= tl && r >= tr)
		return mn[i];
	if (l > tr || r < tl)
		return (1 << 30);
	int tm = (tl + tr) / 2;
	return min(getmin(i + i, tl, tm), getmin(i + i + 1, tm + 1, tr));
}

int getmax(int i = 1, int tl = 0, int tr = n - 1) {
	if (l <= tl && r >= tr)
		return mx[i];
	if (l > tr || r < tl)
		return -(1 << 30);
	int tm = (tl + tr) / 2;
	return max(getmax(i + i, tl, tm), getmax(i + i + 1, tm + 1, tr));
}

void update(int i = 1, int tl = 0, int tr = n - 1) {
	if (tl == tr)
		mn[i] = mx[i] = r;
	else {
		int tm = (tl + tr) / 2;
		if (l > tm)
			update(i + i + 1, tm + 1, tr);
		else update(i + i, tl, tm);
		mn[i] = min(mn[i + i], mn[i + i + 1]);
		mx[i] = max(mx[i + i], mx[i + i + 1]);
	}
}

int newelement(int i) {
	i++; long long r = 0, sq = i * 1LL * i, cb = i * 1LL * i * i;
	r = sq % 12345LL + cb % 23456LL;
	return (int)r;
}

int main() {
	int k; scanf("%d", &k);	
	for (int i = 0; i < n; i++) {
		l = i; r = newelement(i);
		update();
	}
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &l, &r);
		if (l > 0) {
			l--; r--; printf("%d\n", getmax() - getmin());
		}
		else {
			l = -(l + 1);
			update();
		}
	}
	return 0;
}
