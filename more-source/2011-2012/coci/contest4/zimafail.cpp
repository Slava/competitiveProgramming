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

const int N = 100100;
struct FenwickTree {
	int t[N];

	FenwickTree() { memset(t, 0, sizeof t); }
	void inc(int i, int x) {
		for (; i < N; i |= i+1)
			t[i] += x;
	}
	int sum(int i) {
		int r = 0;
		for (; i >= 0; i &= i+1, i--)
			r += t[i];
		return r;
	}

	int sum(int l, int r) { return sum(r)-sum(l-1); }
	void inc(int l, int r, int x) { inc(l, x); inc(r+1, -x); }
	int get(int i) { return sum(i); } 
}winters, canPredict;

int n, a[N], longest, winterLong;
vector<int> pos;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		canPredict.inc(i,1);
		if (a[i] >= 0) {
			winterLong = 0;
			continue;
		}

		winterLong++;
		if (winterLong > longest) {
			longest = winterLong;
			pos.clear();
		}

		int start = i-longest+1;

		if (winterLong == longest)
			pos.push_back(start);

		if (i == n || a[i+1] >= 0)
			winters.inc(max(start-2*winterLong,0),max(start-1,0),1);
	}

	int answer = 0, plus = 0;
	for (int i = 1; i <= n; i++)
		if (winters.get(i) > 0)
			answer++, canPredict.inc(i, -1);

	for (int i = 0; i < (int)pos.size(); i++)
		plus = max(plus, canPredict.sum(max(pos[i]-3*longest,0), max(pos[i]-1,0)));

	printf("%d\n", answer+plus);
	return 0;
}
