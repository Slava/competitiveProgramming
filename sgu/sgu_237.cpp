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

const int N = 1000;

string t, s;
int inf=1000, n, nn, i, j;
string a[3][N];
int c[3][N];
int l0, l1, l2, T;

void upd(int x, string y) {
	if (c[l2][i] > x || (c[l2][i] == x && y < a[l2][i])) {
		c[l2][i] = x;
		a[l2][i] = y;
	}
}

int main() {
	cin >> t;
	nn = (int)t.length();
	for (i = 0; i < nn; i++)
		if (t[i] == '!') {
			s += '?';
			s += '?';
			s += '?';
		} else
			s += t[i];
	n = (int)s.length();
	l0 = 0, l1 = 1, l2 = 2;
	for (i = 0; i < n; i++) {
		if (s[i] == '*')
			c[l1][i] = 0;
		else {
			c[l1][i] = 1;
			a[l1][i] = string(1,s[i]=='?'?'a':s[i]);
		}
	}
	for (j = 2; j <= n; j++) {
		for (i = 0; i+j <= n; i++) {
			char L=s[i], R=s[i+j-1];
			if (L == '*') {
				if (R == '*') {
					c[l2][i] = c[l0][i+1];
					a[l2][i] = a[l0][i+1];

					upd(c[l1][i+1], a[l1][i+1]);
					upd(c[l1][i], a[l1][i]);
				} else {
					c[l2][i] = c[l1][i+1];
					a[l2][i] = a[l1][i+1];

					if (R == '?')
						R = 'a';
					upd(2+c[l1][i],R+a[l1][i]+R);
				}
			} else {
				if (R == '*') {
					c[l2][i] = c[l1][i];
					a[l2][i] = a[l1][i];

					if (L == '?')
						L = 'a';
					upd(2+c[l1][i+1],L+a[l1][i+1]+L);
				} else {
					if (c[l0][i+1]>=inf||(L!=R&&L!='?'&&R!='?')) {// bad
						c[l2][i] = inf;
						a[l2][i] = "";
					}
					else {
						if (L == '?')
							L = R == '?' ? 'a' : R;
						upd(2+c[l0][i+1], L+a[l0][i+1]+L);
						c[l2][i] = 2+c[l0][i+1];
						a[l2][i] = L+a[l0][i+1]+L;
					}
				}
			}
		}
		T = l0;
		l0 = l1;
		l1 = l2;
		l2 = T;
	}

	if (c[l1][0] >= inf)
		cout << "NO" << endl;
	else 
		cout << "YES\n" << a[l1][0] << "\n\n";

	return 0;
}
