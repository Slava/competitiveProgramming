#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long Int;
#define sz(x) ((int)x.size())
#define pb push_back
#define forc(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); ++i)
#define all(x) x.begin(),x.end()

int a[6][3][3], p[3], k, b[3][3], c[6][3];
char s[4], o[4];
void di(int a[3][3], int p[3], int c[3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = (p[i] < p[j]);
//			printf("%d ", a[i][j]);
		}
//		printf("    %d\n", p[i]);
		c[i] = p[i];
	}
//	printf("\n\n");
}

int main() {
	p[1] = 1; p[2] = 2;
	do {di(a[k], p, c[k]); k++;} while(next_permutation(p, p + 3));
	for (int i = 0; i < 3; i++) {
		cin >> s;
		if (s[0] == s[2]) {
			cout << "Impossible";
			return 0;
		}
		int x = s[0] - 'A', y = s[2] - 'A';
		if (s[1] == '<')
			b[x][y] = 1;
		else b[y][x] = 1;
	}
	for (int k = 0; k < 6; k++) {
		int ok = 1;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (a[k][i][j] != b[i][j])
					ok = 0;
		if (ok) {
			for (int i = 0; i < 3; i++)
				o[c[k][i]] = 'A' + i;
			cout << o;
			return 0;
		}
	}
	cout << "Impossible";
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 10, 2011 10:11:44 AM
// contest: 47
// link: /contest/47/submission/540422
// time: 30 ms
// verdict: Accepted
// problem: 47B - Coins
// ID: 540422
// downloaded by very stupid script
