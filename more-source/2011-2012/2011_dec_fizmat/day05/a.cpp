#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long Int;

Int n, l, r;
vector<Int> f;

bool fibonacci(Int x) {
	return binary_search(f.begin(), f.end(), x);
}

bool palindrome(Int l, Int r) {
	r += l - 1;
	return fibonacci(r + 2);
}

int main() {
	freopen("fib.in", "r", stdin);
	freopen("fib.out", "w", stdout);

	ios_base::sync_with_stdio(false);

	f.push_back(1);
	f.push_back(2);

	for (;;) {
		Int x = f[f.size() - 1] + f[f.size() - 2];
		f.push_back(x);
		if (x > 2000000000LL)
			break;
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		
		r = l + r - 1;
		Int prel = -1, prer = -1;
		while (l != r && !palindrome(l,r)) {
			Int fib = *lower_bound(f.begin(), f.end(), r + 2);
			fib -= 2;
			Int ll, rr;
			ll = 1 + (fib - r);
			rr = 1 + (fib - l);
			if (ll == prel && rr == prer)
				break;
			prel = l; prer = r;
			l = ll; r = rr;
		}
		cout << (palindrome(l,r) || l == r ? "TAK" : "NIE") << "\n";
	}

	return 0;
}

