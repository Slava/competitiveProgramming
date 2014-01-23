#include <cstdio>
#include <map>

using namespace std;

typedef long long Int;
map<int,int> a;
int n, k, pr[60], p;

int gcd(int a, int b) {
	return a ? gcd(b%a, a) : b;
}

void add(int lcm, int c) {
	a[lcm] += c;
	if (!a[lcm])
		a.erase(lcm);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &p);
		pr[p] ^= 1;
	}
	for (p = 1; p < 60; p++)
		if (pr[p]) {
			map<int,int> b(a);
			for (map<int,int>::iterator j = b.begin(); j != b.end(); ++j) {
				Int lcm = p / gcd(p, j->first) * (Int)j->first;
				if (lcm > n) continue;
				add(lcm, -2 * j->second);
			}
			add(p, 1);
		}
 
	int ans = 0;
	for (map<int,int>::iterator j = a.begin(); j != a.end(); ++j)
		ans += (n / j->first) * j->second;

	printf("%d\n", ans);

	return 0;
}
