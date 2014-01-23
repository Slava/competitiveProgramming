#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

long long a[200000], n, ans;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	
	for (int i = 1; i <= n; i++) {
		ans += i-(lower_bound(a,a+i,a[i]*9)-a);
		a[i] *= 10;
	}

	cout << ans << endl;

	return 0;
}

