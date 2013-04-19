#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
long long x, y, z, r;
struct pupil {
	long long a, b, c;
	int i;
}a[101010];
bool cmp (pupil a, pupil b) {
	return x * a.a + y * a.b + z * a.c > x * b.a + y * b.b + z * b.c;
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	cin >> x >> y >> z >> n;
	for (int i = 0; i < n; i++) {
		a[i].i = i + 1;
		cin >> a[i].a >> a[i].b >> a[i].c;
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < 3; i++) {
		cout << a[i].i << " ";
		r += a[i].a * x + a[i].b * y + a[i].c * z;
	}
//	cerr << r;

	return 0;
}

