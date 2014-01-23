#include <iostream>
using namespace std;
int t[1<<18],a[500];
int n, m, i, j, cmd, l, r;

void build (int a[], int i = 1, int l = 0, int r = n-1) {
	if (l == r)
		t[i] = a[l];
	else {
		int m = (l + r) / 2;
		build (a, i*2, l, m);
		build (a, i*2+1, m+1, r);
		t[i] = t[i*2] + t[i*2+1];
	}
}

long long sum (int l, int r, int i = 1, int tl = 0, int tr = n-1) {
	if (l == tl && r == tr)
		return t[i];
	int m = (tl + tr) / 2;
	if (r <= m)
		return sum (l, r, i*2, tl, m);
	if (l > m)
		return sum (l, r, i*2+1, m+1, tr);
	return sum (l, m, i*2, tl, m) + sum (m+1, r, i*2+1, m+1, tr);
}

void update (int pos, int newval, int i = 1, int l = 0, int r = n-1) {
	if (l == r)
		t[i] = newval;
	else {
		int m = (l + r) / 2;
		if (pos <= m)
			update (pos, newval, i*2, l, m);
		else
			update (pos, newval, i*2+1, m+1, r);
		t[i] = t[i*2] + t[i*2+1];
	}
}

int main()
{
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];
    build(a);
    cin >> m;
    for(i = 0; i < m; i++)
    {
        cin >> cmd >> l >> r;
        if(!cmd)update(l,r);
        else cout << sum(l,r);
    }
}
