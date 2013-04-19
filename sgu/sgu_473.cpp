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
#include <iomanip>
#include <ctime>

using namespace std; 



const int base = 1000000000;
const int base_digits = 9;
const int SIZE = 4000;
int buff[SIZE];

struct bigint {
    int a[SIZE], n;

    void mult(int v) {
        for (int i = 0, carry = 0; i < n || carry; ++i) {
            if (i == n)
                a[n++] = 0;
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
        }
        while (n && !a[n-1])
            n--;
    }

    void mult(const bigint &b) {
		memset(buff, 0, sizeof buff);
		for (int i = 0; i < n; ++i)
			for (int j = 0, carry = 0; j < b.n || carry; ++j) {
				long long cur = buff[i+j] + a[i] * 1ll * (j < b.n ? b.a[j] : 0) + carry;
				buff[i+j] = int (cur % base);
				carry = int (cur / base);
			}
		memcpy(a,buff,sizeof(buff));
		n += b.n + 5;
		while (n && !a[n-1])
			n--;
	}

	void print() {
		printf("%d", !n ? 0 : a[n-1]);
		for (int i = n - 2; i >= 0; --i)
	 	   printf("%09d", a[i]);
	}

	void clear() {
		memset(a,0,sizeof a);
		n = 1;
	}
};


bigint a, b, c;
typedef long long ll;

void power(int base, int exp) {
	b.clear(); c.clear();
	b.a[0] = 1;
	c.a[0] = base;

	while (exp > 0) {
		if (exp & 1)
			b.mult(c);
		c.mult(c);
		exp >>= 1;
	}
}

ll p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409, 419,421,431,433,439,443,449,457,461,463, 467,479,487,491,499,503,509,521,523,541, 547,557,563,569,571,577,587,593,599,601, 607,613,617,619,631,641,643,647,653,659, 661,673,677,683,691,701,709,719,727,733, 739,743,751,757,761,769,773,787,797,809, 811,821,823,827,829,839,853,857,859,863, 877,881,883,887,907,911,919,929,937,941, 947,953,967,971,977,983,991,997};
ll k;
typedef vector<int> vi;
double MAXANS = 1e100;
vi d, best;
set<int> _map;

void RR(vi &d) {
	double A = 0;

	for (int i = 0; i < (int)d.size(); i++) {
		A += (d[i]-1)*log(p[i]);
	}
	if (MAXANS > A) {
		MAXANS = A;
		best = d;
	}
}

bool D(vi d) {
	if (d.empty())
		return 1;
	if (double(clock())/CLOCKS_PER_SEC > 0.3)
		return 0;

	sort(d.begin(),d.end());
	reverse(d.begin(),d.end());

	int HASH = 0;
	for (int i = 1; i < (int)d.size(); i++)
		HASH = HASH * 1993287 + (d[i] - d[i-1]);

	if (_map.find(HASH) != _map.end())
		return 1;
	_map.insert(HASH);

	RR(d);
	if (d.size() == 1)return 1;
	int prev = -1;
	for (int j = 0; j < (int)d.size(); j++) {
		int x = d[j];
		if (x == prev)
			continue;
		prev = x;
		swap(d[j], d[d.size()-1]);
		d.pop_back();
		for (int i = 0; i < (int)d.size(); i++) {
			d[i] *= x;
			if(!D(d))
				return 0;
			d[i] /= x;
		}
		d.push_back(x);
		sort(d.begin(),d.end());
		reverse(d.begin(),d.end());
	}
	return 1;
}

int main() {
	scanf("%lld", &k);
	if (k == 1) {
		puts("1");
		return 0;
	}

	for (int i = 2; i <= k; i++) {
		while (k % i == 0) {
			k /= i;
			d.push_back(i);
		}
	}

	a.n = a.a[0] = 1;
	D(d);
	for (int i = 0; i < (int)best.size(); i++) {
		power(p[i], best[i]-1);
		a.mult(b);
	}

	a.print();
	return 0;
}

