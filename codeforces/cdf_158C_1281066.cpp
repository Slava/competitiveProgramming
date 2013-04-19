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



char s[10010010], t[100100];
int st[10010010], sz, n, k = 1;

void solve() {
	cin >> n;
	s[0] = '/';
	while (n--) {
		cin >> t;
		if (!strcmp("cd", t)) {
			cin >> t;
			int len = strlen(t), i = 0;
			while (i < len) {
				if (t[i] == '/') {
					k = 0;
					s[k++] = '/';
					i++;
					while (i < len && t[i] != '/')
						s[k++] = t[i++];
					i++;
				} else if (t[i] == '.') {
					if (t[i+1] == '.') {
						if (k != 1) {
							while (k > 1 && s[k-2] != '/')
								k--;
							k--; s[k-1] = '/';
						}
						i++;
					}
					i+= 2;
				} else {
					while (i < len && t[i] != '/')
						s[k++] = t[i++];
					i++;
				}
				if (s[k-1] != '/')
					s[k++] = '/';
			}
		} else {
			for (int i = 0; i < k; i++)
				cout << s[i];
			cout << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}





// lang: GNU C++
// memory: 50400 KB
// author: imslavko
// submit_date: Mar 4, 2012 6:34:11 PM
// contest: 158
// link: /contest/158/submission/1281066
// time: 30 ms
// verdict: Accepted
// problem: 158C - Cd and pwd commands
// ID: 1281066
// downloaded by very stupid script
