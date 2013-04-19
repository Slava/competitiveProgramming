// Kim Vyacheslav Karaganda KTL
// 2011
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <string>
#include <cstring>


using namespace std;


#define maxn 500000
#define x(X) a[X].first
#define h(X) a[X].second
long n, ans[maxn], t[maxn*2];
pair<long, long>a[maxn], b[maxn];


long sum (long l, long r, long i = 1, long tl = 0, long tr = n-1) {
	if (l == tl && r == tr)
		return t[i];
	long m = (tl + tr) / 2;
	if (r <= m)
		return sum (l, r, i*2, tl, m);
	if (l > m)
		return sum (l, r, i*2+1, m+1, tr);
    return max( sum (l, m, i*2, tl, m),
                sum (m+1, r, i*2+1, m+1, tr));

}

void update (long pos, long newval, long i = 1, long l = 0, long r = n-1) {
	if (l == r)
		t[i] = newval;
	else {
		long m = (l + r) / 2;
		if (pos <= m)
			update (pos, newval, i*2, l, m);
		else
			update (pos, newval, i*2+1, m+1, r);
		t[i] = max(t[i+i], t[i+i+1]);
	}
}
long bs(long c, long l, long r)
{
    long m;
    while (l + 1 < r)
    {
        m = (l + r) / 2;
        if (x(m) <= x(c) + h(c) - 1)
            l = m;
        else r = m;
    }
    if (x(r) <= x(c) + h(c) - 1)
            l = r;
    return l;
}

 int main ()
{
    cin >> n;
    for (long i = 0; i < n; i++)
    {
        scanf ("%ld%ld", &a[i].first, &a[i].second);
        b[i] = a[i];
    }
    sort(a, a + n);
    for (long i = 0; i < n; i++)
    {
        ans[i] = 1;
        update(i, i);
    }
    for (long i = n - 2; i >= 0; i--)
    {
        long pp = bs(i, i, n - 1);
        if ( pp > i)
        {
            long olabilir = sum(i + 1,pp);
            ans[i] = olabilir - i + 1;
            update(i, olabilir);
        }
    }
    for (long i = 0; i < n; i++)
    {
        long pos = lower_bound(a, a + n, b[i]) - a;
        cout << ans[pos] << " ";
    }
    return 0;
}





// lang: GNU C++
// memory: 15000 KB
// author: imslavko
// submit_date: Jan 22, 2011 5:56:10 PM
// contest: 56
// link: /contest/56/submission/259739
// time: 270 ms
// verdict: Accepted
// problem: 56E - Domino Principle
// ID: 259739
// downloaded by very stupid script
