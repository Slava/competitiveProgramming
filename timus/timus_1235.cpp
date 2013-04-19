#include <cstdio>
#include <cstdlib>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a<b?b:a)

int n, w, h, x[110], y[110];
int ansx, ansy;

bool go(int l) {
	for (int k = 0; k < n; k++) {
		int left = x[k];
		for (int up = 0; up <= h; up++) {
			bool can = 1;
			int right = left + l, down = up + l;
			if (right > w || down > h)
				can = 0;
			for (int i = 0; i < n && can; i++)
				if (x[i] > left && x[i] < right &&
					y[i] > up && y[i] < down)
					can = 0;
			if (can) {
				ansx = left; ansy = up;
				return 1;
			}
		}
	}
	for (int k = 0; k < n; k++) {
		int up = y[k];
		for (int left = 0; left <= w; left++) {
			int right = left + l, down = up + l;
			bool can = 1;
			if (right > w || down > h)
				can = 0;
			for (int i = 0; i < n && can; i++)
				if (x[i] > left && x[i] < right &&
					y[i] > up && y[i] < down)
					can = 0;
			if (can) {
				ansx = left; ansy = up;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	scanf("%d%d%d", &n, &w, &h);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", x + i, y + i);
	x[n + 1] = w; y[n + 1] = h; n += 2;
	int l = 0, r = min(w, h), m;
	while (l <= r) {
		m = (l + r) / 2;
		if (go(m))
			l = m + 1;
		else r = m - 1;
	}
	printf("%d %d %d\n", ansx, ansy, l - 1);
	return 0;
}
