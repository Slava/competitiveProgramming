#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int a[100500];
char cmd[100];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a,a+n);

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%s%d%d", cmd, &x, &y);
		if (cmd[0] == 'F')
			for (int j = 0; j < n && x > 0; j++)
				if (a[j] >= y) {
					a[j]++; x--;
				}
		if (cmd[0] == 'C') {
			int res = 0;
			for (int j = 0; j < n; j++)
				if (a[j] >= x && a[j] <= y)
					res++;
			printf("%d\n", res);
		}
		sort(a,a+n);
	}

	return 0;
}

