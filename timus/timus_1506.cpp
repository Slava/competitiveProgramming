#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int>v[101];
int n, k, a[200], j;

int main() {
	scanf("%d%d", &n, &k); k = (n + k - 1) / k;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		if (j == k) j = 0;
		v[j].push_back(a[i]);
		j++;
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < v[i].size(); j++)
			printf("%4d", v[i][j]);
		printf("\n");
	}
	return 0;
}
