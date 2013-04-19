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

#define abs(x) (x<0?-(x):x)

const int N = 101000;

int t[N];

void inc(int i, int x) {
	for (; i < N; i |= i+1)
		t[i] += x;
}

int sum(int i) {
	int r = 0;
	for (; i >= 0; i &= i+1, i--)
		r += t[i];
	return r;
}

int sum(int i, int j) { return sum(j)-sum(i-1); }

int a[N], s[N], n, k, m, res[N], id[N];
vector<int> pl[N];
pair<pair<int,int>,int>q[N];

int indx(int x) {
	return lower_bound(s,s+k,x)-s;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", a+i);
		s[i] = a[i];
	}

	sort(s,s+n);
	k = unique(s,s+n)-s;

	for (int i = 0; i < n; i++)
		pl[indx(a[i])].push_back(i);


	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--; r--;
		q[i] = make_pair(make_pair(r,l),i);
	}


	sort(q,q+m);
	int j = 0;
	for (int i = 0; i < m; i++) {
		int l, r, I;
		l = q[i].first.second;
		r = q[i].first.first;
		I = q[i].second;

	//	cout << l << " " << r << endl;

		for (; j <= r; j++) {
			int x = a[j], ix = indx(x);
			int &thatIdx = id[ix];
/*
			cout << "move " << j << endl;
				cout << x << endl;
				cout << thatIdx << endl;
				cout << ix << endl;
*/
			if (pl[ix][thatIdx] != j)
				cout << "FUU" << endl;

			if (thatIdx-x-1 >= 0) {
		//		cout << "try +1 " << pl[ix][thatIdx-x-1] << endl;
				inc(pl[ix][thatIdx-x-1],1);
			}
			if (thatIdx-x >= 0) {
		//		cout << "try -2 " << pl[ix][thatIdx-x] << endl;
				inc(pl[ix][thatIdx-x],-2);
			}
			if (thatIdx-x+1 >= 0) {
		//		cout << "try +1 " << pl[ix][thatIdx-x+1] << endl;
				inc(pl[ix][thatIdx-x+1],1);
			}

			thatIdx++;
		//	cout << "next" <<endl;
		}

		res[I] = sum(l,r);
	}

	for (int i = 0; i < m; i++)
		printf("%d\n", res[i]);

	return 0;
}




// lang: GNU C++
// memory: 6200 KB
// author: imslavko
// submit_date: Aug 31, 2012 8:57:55 PM
// contest: 220
// link: /contest/220/submission/2080439
// time: 200 ms
// verdict: Accepted
// problem: 220B - Little Elephant and Array
// ID: 2080439
// downloaded by very stupid script
