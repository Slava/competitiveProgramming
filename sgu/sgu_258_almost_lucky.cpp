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

string number;
int dp[10][2][200][22][22]; // len, flag, bal, min, max
int n; // n == number.length()

int numAt(int i) {
	return number[i]-'0';
}

int ind(int i) {
	return 100 + i;
}

int inx(int i) {
	return 11 + i;
}

int goCount() {
	// len, flag, bal, min, max
//	cout << "goCount " << number << endl;
	memset(dp, 0, sizeof dp);
	int res = 0;
	for (int i = 1; i < 10; i++)
		if (numAt(0) > i) {
			dp[0][0][ind(-i)][inx(i-9)][inx(i-1)] = 1;
		} else if (numAt(0) == i) {
			dp[0][1][ind(-i)][inx(i-9)][inx(i-1)] = 1;
		}
	for (int i = 0; i < n/2-1; i++)
		for (int f = 0; f < 2; f++)
			for (int b = 0; b < 200; b++)
				for (int cmin = 0; cmin < 22; cmin++)
					for (int cmax = 0; cmax < 22; cmax++) {
						int &r = dp[i][f][b][cmin][cmax];
						if (!r)
							continue;
//						cout << "i="<<i<<" fl=" << f << " bal="<<b-100<<" min="<<cmin-11<<" max="<<cmax-11<<" r="<<r<<endl;
						for (int q = 0; q < 10; q++) {
							if (f && q > numAt(i+1))
								break;
							int nf = f & (q == numAt(i+1));
							int nb = b - q;
							int nmin = min(cmin, inx(q-9));
							int nmax = max(cmax, inx(q));

							dp[i+1][nf][nb][nmin][nmax] += r;
						}
					}
//	cout << "RAZRYV"<<endl;
	for (int i = n/2-1; i < n-1; i++)
		for (int f = 0; f < 2; f++)
			for (int b = 0; b < 200; b++)
				for (int cmin = 0; cmin < 22; cmin++)
					for (int cmax = 0; cmax < 22; cmax++) {
						int &r = dp[i][f][b][cmin][cmax];
						if (!r)
							continue;
//						cout << "i="<<i<<" fl=" << f << " bal="<<b-100<<" min="<<cmin-11<<" max="<<cmax-11<<" r="<<r<<endl;
						for (int q = 0; q < 10; q++) {
							if (f && q > numAt(i+1))
								break;
							int nf = f & (q == numAt(i+1));
							int nb = b + q;
							int nmin = min(cmin, inx(-q));
							int nmax = max(cmax, inx(9-q));

							dp[i+1][nf][nb][nmin][nmax] += r;
						}
					}
	for (int b = 0; b < 200; b++)
		for (int f = 0; f < 2; f++)
			for (int cmin = 0; cmin < 22; cmin++)
				for (int cmax = 0; cmax < 22; cmax++) {
					if (!dp[n-1][f][b][cmin][cmax])continue;
//					cout << "i="<<n-1<<" fl=" << f << " bal="<<b-100<<" min="<<cmin-11<<" max="<<cmax-11<<" r="<<dp[n-1][f][b][cmin][cmax]<<endl;
					int bal = b-100;
					int min = cmin-11;
					int max = cmax-11;
					if (!bal)continue;
					if (-bal >= min && -bal <= max)
						res += dp[n-1][f][b][cmin][cmax];
				}
//	cout << res << endl;
	return res;
}

int nNotLucky(string inp) {
//	cout << "nNotLucky < " << inp << " >\n";
	if (inp == "-1")
		return 0;
	int len = (int)inp.length();
	int res = 0;
	for (int i = 2; i < len; i += 2) {
		number = string(i, '9');
		n = i;
		res += goCount();
	}

	if (len % 2 == 0) {
		number = inp;
		n = len;
		res += goCount();
	}
	return res;
}

int main() {
	int l, r;
	char s[20];
	string L, R;
	cin >> l >> r;
	l--;
	sprintf(s, "%d", l);
	L = s;
	sprintf(s, "%d", r);
	R = s;
	cout << nNotLucky(R) - nNotLucky(L) << endl;
	return 0;
}

