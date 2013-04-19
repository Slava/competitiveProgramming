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



const int N = 103010, Bl = 320;

struct SegmentTree {
	vector<int> a;
	int n;
	SegmentTree(int size) {
		n = size;
		a.resize(n*2, 1<<30);
	}
	
	int get(int l, int r) {
		if (l > r || l == n)
			return 1<<30;
		l += n; r += n;
		int res = 1<<30;
		while (l <= r) {
			if (l & 1)
				res = min(res, a[l]);
			if (!(r&1))
				res = min(res, a[r]);
			l = (l+1)/2;
			r = (r-1)/2;
		}
		return res;
	}

	void upd(int i, int x) {
//		printf("update on %d to %d\n", i, x);
		i += n;
		a[i] = x;
		while (i /= 2)
			a[i] = min(a[i+i],a[i+i+1]);
	}
};

int n, m, l[N], r[N], t[N], p[N], pp[N], rl[N/Bl], ql[N], qr[N], qb[N], place[N], ans[N];
vector<int> rr[N/Bl];
map<int,int> which;
vector<SegmentTree> st;

bool byL(int i, int j) {
	return l[i] < l[j];
}
bool byR(int i, int j) {
	return r[i] < r[j];
}

int GET(int R, int bl) {
	int p = lower_bound(rr[bl].begin(), rr[bl].end(), R) - rr[bl].begin();
	while (p < Bl && rr[bl][p] < R)
		p++;
//	printf("it will be get for %d:", R);
//	for (int i = p; i < Bl; i++)
//		printf("%d ", rr[bl][i]);puts("");
	return st[bl].get(p,Bl-1);
}

int query(int L, int R, int B) {
	int res = 1<<30;
	for (int i = 0; i < n;) {
		if (i%Bl == 0 && rl[i/Bl] <= L) {
			res = min(res, GET(R, i/Bl));
			i += Bl;
		} else {
			if (l[pp[i]] > L)
				break;
			if (r[pp[i]] >= R && B <= t[pp[i]]) {
				res = min(res, t[pp[i]]);
			}
			i++;
		}
	}

//	printf("query for %d %d %d ans is time %d\n", L, R, B, res);
	if (res < B)
		res = 1<<30;
	return which[res];
}

struct event {
	int q, t, i;
	event(int T, int Q, int I) {
		t = T; q = Q; i = I;
	}
	bool operator < (const event v) const {
		if (v.t == t)
			return !q;
		return t > v.t;
	}
};

vector<event> events;

void solve() {
	cin >> n >> m;
	int newn = (n+Bl-1)/Bl*Bl;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i] >> t[i];
		p[i] = i;
		which[t[i]] = i+1;
		events.push_back(event(t[i],0,i));
	}

	which[1<<30] = -1;


	for (int i = n; i < newn; i++) {
		l[i] = r[i] = t[i] = 1<<30;
		p[i] = i;
	}
	n = newn;
	
	sort(p,p+n,byL);
	memcpy(pp, p, sizeof p);
	
	for (int i = 0, bl = 0; i < n; i += Bl, bl++) {
		rl[bl] = l[p[i+Bl-1]];
		vector<int> b;
		sort(p+i,p+i+Bl, byR);
		for (int j = 0; j < Bl; j++) {
			b.push_back(r[p[i+j]]);
			place[p[i+j]] = i+j;
		}
		st.push_back(Bl);
		rr[bl] = b;
	}
	
	for (int i = 0; i < m; i++) {
		cin >> ql[i] >> qr[i] >> qb[i];
		events.push_back(event(qb[i],1,i));
	}

	sort(events.begin(), events.end());
	for (int i = 0; i < (int)events.size(); i++) {
//		printf("cur %d, %d, %d\n", events[i].t, events[i].q, events[i].i);
		int q = events[i].q, id = events[i].i;
		if (q)ans[id] = query(ql[id], qr[id], qb[id]);
		else st[place[id]/Bl].upd(place[id]%Bl, t[id]);
	}

	for (int i = 0; i < m; i++)
		cout << ans[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}





// lang: GNU C++
// memory: 15000 KB
// author: imslavko
// submit_date: Mar 7, 2012 1:06:46 PM
// contest: 160
// link: /contest/160/submission/1308081
// time: 3190 ms
// verdict: Accepted
// problem: 160E - Buses and People
// ID: 1308081
// downloaded by very stupid script
