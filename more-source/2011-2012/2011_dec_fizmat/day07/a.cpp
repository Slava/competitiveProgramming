#include <cstdio>
#include <cstring>

int n, m, a[200], max, r[200], u[200];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", a + i);
		if (max < a[i])
			max = a[i];
	}

	printf("%d\n", max * n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			r[j] = ((i + j) % n) * max;
		puts("");
		int min; memset(u, 0, sizeof u);
		for (int j = 0; j < m; j++) {
			min = -1;
			for (int k = 0; k < m; k++)
				if (!u[k] && (min == -1 || r[min] > r[k]))
					min = k;
			u[min] = 1;
			printf("%d %d\n", min + 1, r[min]);
		}
	}


	return 0;
}
