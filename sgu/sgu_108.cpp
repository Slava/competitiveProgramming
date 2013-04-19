#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int arr[10000], u[10000000/32+20];

int getshort(int x) {
	int t = 0;
	while(x>0) {
		t += x % 10;
		x /= 10;
	}
	return t;
}

int get(int x) {
	int t = x;
	while(x>0) {
		t += arr[x%10000];
		x /= 10000;
	}
	return t;
}

bool test(int x) {
	return (u[x/32]>>(x%32))&1;
}

void setbit(int x) {
	u[x/32] |= 1 << (x%32);
}

int k, n, m;
pair<int,int> q[5010];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < 10000; i++)
		arr[i] = getshort(i);

	for (int i = 0; i < m; i++)
		scanf("%d", &q[i].first), q[i].second = i;
	sort(q,q+m);
	int i = 0;

	for (int j = 1; j <= n; j++) {
		if (!test(j)) {
			k++;
			while (q[i].first == k) {
				q[i].first = q[i].second;
				q[i].second = j;
				i++;
			}
		}
		setbit(get(j));
	}

	sort(q,q+m);
	printf("%d\n", k);
	for (int i = 0; i < m; i++)
		printf("%d ", q[i].second);
	puts("");

	return 0;
}
