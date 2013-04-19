#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

int n, a[9], b[9], h[9], found, bad;

void check() {
	for (int i = 0; i < n*n; i++)
		if (h[i] != a[i])
			return;
	found = 1;
}

void rec(int v) {
	if (v == n*n) {
		check();
		return;
	}
	if (found)
		return;
	for (int i = 0; i < 10; i++) {
		b[v] = i;
		if (v-n >= 0) {
			if (b[v-n] < b[v])
				h[v-n]++;
			else if (b[v-n] > b[v])
				h[v]++;
		}
		if (v%n != 0) {
		   	if (b[v-1] < b[v])
				h[v-1]++;
			else if (b[v-1] > b[v])
				h[v]++;
		}
		if (v-n < 0 || h[v-n] == a[v-n])
			rec(v+1);
		if (v-n >= 0) {
			if (b[v-n] < b[v])
				h[v-n]--;
			else if (b[v-n] > b[v])
				h[v]--;
		}
		if (v%n != 0) {
		   	if (b[v-1] < b[v])
				h[v-1]--;
			else if (b[v-1] > b[v])
				h[v]--;
		}
		if (found)return;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n*n; i++)
		cin >> a[i];

	rec(0);

	if (found) {
		for (int i = 0 ;i < 3; i++) {
			for (int j =0; j < 3; j++)
				printf("%d ", b[i*3+j]);
			puts("");
		}
	} else puts("NO SOLUTION"); 

	return 0;
}
