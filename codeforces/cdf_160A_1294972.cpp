#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <bitset>

#include <cmath>
#include <cstring>

using namespace std; 



const int N = 100*100+100;
int n, a[N], c, b[N], sum;
void solve() {
	cin >> n;
	
	fill(b+1,b+N,100500);
	a[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> c;
		sum += c;
		for (int j = N-c-1; j >= 0; j--)
			if (a[j]) {
				a[j+c] = 1;
				b[j+c] = min(b[j+c], b[j]+1);
			}
	}

	int ans = 1e5;
	for (int i = sum/2+1; i < N; i++)
		if (a[i])
			ans = min(ans,b[i]);
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}





// lang: GNU C++
// memory: 1500 KB
// author: imslavko
// submit_date: Mar 6, 2012 7:05:49 PM
// contest: 160
// link: /contest/160/submission/1294972
// time: 30 ms
// verdict: Accepted
// problem: 160A - Twins
// ID: 1294972
// downloaded by very stupid script
