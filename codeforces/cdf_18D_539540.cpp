#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> c(2010, -1), can(5010, 1);
int n, x[5010];
char s[5010][20];

struct bigint {
	vector<int>a;
	void print() {
		if (a.empty())
			printf("0");
		for (int i = (int)a.size() - 1; i >= 0; i--)
			printf("%d", a[i]);
	}
	void trim() {
		while (!a.empty() && !a.back())
			a.pop_back();
	}
	void operator = (int x) {
		a.clear();
		for (; x; x /= 10)
			a.push_back(x % 10);
	}
	void operator = (bigint b) {
		a = b.a;
	}
	void operator *= (bigint B) {
		vector<int> &b = B.a;
		vector<int> c(a.size() + b.size() + 2, 0);
		int i, j, carry = 0;
		for (i = 0; i < a.size(); i++) {
			for (j = 0; j < b.size(); j++) {
				c[i + j] += a[i] * b[j] + carry;
				carry = c[i + j] / 10;
				c[i + j] %= 10;
			}
			for (; carry; j++) {
				c[i + j] += carry;
				carry = c[i + j] / 10;
				c[i + j] %= 10;
			}
		}
		a = c;
		this->trim();
	}
	void operator += (bigint B) {
		vector<int> &b = B.a;
		vector<int> c(max(a.size(), b.size()) + 2, 0);
		int carry = 0;
		a.resize(c.size()); b.resize(c.size());
		for (int i = 0; i < a.size(); i++) {
			c[i] = a[i] + b[i] + carry;
			carry = c[i] / 10;
			c[i] %= 10;
		}
		a = c;
		this->trim();
	}
};
bigint ans;

bigint pow2(int n) {
	bigint res, a;
	res = 1; a = 2;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%d", s[i], x + i);
		if (s[i][0] == 's')
			c[x[i]] = i;
	}
	for (int i = 2000; i >= 0; i--)
		if (c[i] != -1) {
			int acc = -1;
			for (int j = c[i] - 1; j >= 0; j--)
				if (!can[j])break; else
				if (s[j][0] == 'w' && x[j] == i) {
					acc = j;
					break;
				}
			if (acc != -1) {
				ans += pow2(i);
				for (int j = acc; j <= c[i]; j++)
					can[j] = 0;
			}
		}
	ans.print();
	return 0;
}






// lang: GNU C++
// memory: 1600 KB
// author: imslavko
// submit_date: Jul 9, 2011 5:50:18 PM
// contest: 18
// link: /contest/18/submission/539540
// time: 1230 ms
// verdict: Accepted
// problem: 18D - Seller Bob
// ID: 539540
// downloaded by very stupid script
