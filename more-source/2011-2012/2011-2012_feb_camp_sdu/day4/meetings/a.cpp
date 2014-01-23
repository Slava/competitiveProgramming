#include <cstdio>
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

int P, V;
long long N;
int a[700000];

int main() {
	cin >> N >> P >> V;
	// 60 solution
	// O(N sqrt N)

	for (int i = 2; i <= N; i++) {
		a[i] = P * i + V;
		for (int j = 1; j * j <= i; j++) {
			int k = (i - 1) / j + 1,
				t = a[k] + a[j];
			if (a[i] > a[k] + a[j])
				a[i] = a[k] + a[j];
		}
	}
	
	cout << a[N] << endl;

	return 0;
}

