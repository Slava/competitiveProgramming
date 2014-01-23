#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char s[3000100];
int n, Max, Min = 1 << 30, a[3] = {0,1,2};
int A[3000100], p[3000100], r[300100];

int get(int x) {
	return p[x] == x ? x : (p[x] = get(p[x]));
}

void doit() {
	for (int i = 0; i < n; i++)
		A[i] = s[i], p[i] = i, r[i] = 1;
	for (;;) {
		bool was = 0;
		for (int j = 0; j < 3; j++)
			for (int i = 0; i < n; i++) {
				int cur = get(i);
				int pre = get((get(i) - 1 + n) % n);
				if (A[cur] != A[pre] && 3 - A[cur] - A[pre] == a[j]) {
	//				printf("was! %d and %d are %d and %d, now %d\n", pre, cur, A[pre], A[cur], a[j]);
					p[cur] = pre;
					r[cur] = 0;
					A[pre] = a[j];
					was = 1;
					break;
				}
			}
		if (!was)break;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += r[i];
	Max = max(Max, cnt);
	Min = min(Min, cnt);
}

int main() {
	freopen("alien.in", "r", stdin);
	freopen("alien.out", "w", stdout);

	scanf("%d", &n);
	scanf("%s", s);

	for (int i = 0; i < n; i++)
		s[i] = s[i] == 'R' ? 2 : (s[i] == 'G');

	do doit(); while(next_permutation(a, a + 3));
	
	printf("%d %d\n", Min, Max);

	return 0;
}
