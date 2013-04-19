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
#include <bitset>

using namespace std; 

const int N = 110;
int Ans;

int gauss(vector<bitset<N> > a, int n, int m, bitset<N> &ans) {
	vector<int> where(m, -1);
	for (int row = 0, col = 0; row < n && col < m; col++) {
		for (int i = row; i < n; i++)
			if (a[i][col]) {
				swap(a[i], a[row]);
				break;
			}
		if (!a[row][col])
			continue;
		where[col] = row;

		for (int i = 0; i < n; i++)
			if (i != row && a[i][col])
				a[i] ^= a[row];
		row++;
	}

	ans.reset();
	for (int i = 0; i < m; i++)
		if (where[i] != -1)
			ans[i] = a[where[i]][m] / a[where[i]][i];

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++)
			sum ^= a[i][j] * ans[j];
		if (sum ^ a[i][m])
			return 0;
	}

	for (int i = 0; i < m; i++)
		if (where[i] == -1)
			Ans++;

	return 1;
}

int s[N] = {1};
int pr[N], prn;
bool prime(int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<bitset<N> > a(n, bitset<N>());

	for (int i = 2; prn < n; i++)
		if (prime(i))
			pr[prn++] = i;

	for (int i = 0; i < m; i++) {
		int x; scanf("%d", &x);
		for (int j = 0; j < n; j++)
			while (x % pr[j] == 0) {
				x /= pr[j];
				a[j].set(i, a[j].test(i)^1);
			}
	}


	bitset<N> ans;
	if (gauss(a, n, m, ans) && Ans){
		for (int i = 0; i < Ans; i++) {
			for (int j = 0; j < 50; j++)
				s[j] <<= 1;
			for (int j = 0; j < 50; j++)
				s[j+1] += s[j]/10, s[j] %= 10;
		}
		s[0]--;
		bool was = 0;
		for (int j = 50; j >= 0; j--)
			if (s[j]) {
				printf("%d", s[j]);
				was = 1;
			} else if (was)
				printf("0");
	}
	else cout << "0\n";

	return 0;
}
