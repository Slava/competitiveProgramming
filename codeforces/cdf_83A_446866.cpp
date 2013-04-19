#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

int n, m, x, pr, i;
long long res, b[101010];
int main(int argc, const char *argv[])
{
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x;
		if (m && x == pr)
			b[m - 1]++;
		else b[m++] = 1;
		pr = x;
	}
	for (int i = 0; i < m; i++){
		res += (b[i] * (b[i] + 1))/2;
	}
	cout << res;
	return 0;
}





// lang: GNU C++
// memory: 2200 KB
// author: imslavko
// submit_date: May 13, 2011 7:17:42 PM
// contest: 83
// link: /contest/83/submission/446866
// time: 200 ms
// verdict: Accepted
// problem: 83A - Magical Array
// ID: 446866
// downloaded by very stupid script
