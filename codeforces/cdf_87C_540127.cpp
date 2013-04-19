#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long Int;

int g[100010], n, ans;

int main() {
	cin >> n;
	for (int i = 3; i <= n; i++) {
		set<int>st; ans = 1 << 30;
		for (int j = 2; ; j++) {
			int k = i - j * (j + 1) / 2;
			if (k < 0) break;
			if (k % j != 0)
				continue;
			int l = 1 + k / j, r = j + k / j, nim = 0;
			for (; l <= r; l++)
				nim ^= g[l];
			st.insert(nim);
			if (!nim)
				ans = min(ans, j);
		}
		int res = 0;
		while (st.find(res) != st.end())
			res++;
		g[i] = res;
	}
	if (g[n])printf("%d\n", ans);
	else printf("%d\n", -1);
	return 0;
}





// lang: GNU C++
// memory: 1800 KB
// author: imslavko
// submit_date: Jul 10, 2011 2:50:13 AM
// contest: 87
// link: /contest/87/submission/540127
// time: 360 ms
// verdict: Accepted
// problem: 87C - Interesting Game
// ID: 540127
// downloaded by very stupid script
