// Tq@JCVi7
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct MonoidMin {
	int a;
	MonoidMin() { a = 1<<30; }
	MonoidMin(int _) { a = _; }
	MonoidMin merge(MonoidMin b) {
		return MonoidMin(min(a,b.a));
	}
};

template <class T, class U>
struct SegmentTree {
	vector<T> t;
	SegmentTree(int size) {
		int sz = 1;
		while (sz < size)
			sz <<= 1;
		t.resize(sz);
	}

	void update(int place, U newValue, int i = 1, int l = 0, int r = (int)t.size()/2) {
		if (l == r)
			t[i] = T(newValue);
		else {
			int m = (l+r) / 2;
			if (place <= m)
				update(place, newValue, i+i, l, m);
			else update(place, newValue, i+i+1, m+1, r);
		}
	}

	T getOnRange(int l, int r, int i = 1, int tl = 0, int tr = (int)t.size()/2) {
		if (l == tl && r == tr)
			return t[i];
		int tm = (tl+tr) / 2;
		if (r <= tl)
			return getOnRange(l, r, i+i, tl, tm);
		if (l > tm)
			return getOnRange(l, r, i+i+1, tm+1, tr);
		return getOnRange(l, tm, i+i, tl, tm).merge(getOnRange(tm+1, r, i+i+1, tm+1, tr));
	}
};

int main() {
#ifndef imslavko
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	
	return 0;
}

