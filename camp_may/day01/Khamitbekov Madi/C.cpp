#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

typedef long long ll;
typedef vector < int > vi;

#define abs(x) ((x) >= 0 ? x : -x)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define len length()
#define sz size()
#define f first
#define s second

int w, h;
int k1, k2;
int n, m;
int a[200000], b[200000];
int da[200000], db[200000];
int ac[20000007]={0}, bc[20000007]={0};

ll val (int x) {
	if (x < 0) return 0;
	return x;
}
ll calc (int n, int m, int mn, int mx) {
//	cout << n << " " << m << " ";
//	cout << n << " " << m << " " << mn << " " << mx  << " ";
	ll res = 0;
	if (mn < 0) mn = 0;
	res = val(n-2*mn)*1LL*val(m-2*mn);
//	cout << res << " ";
	if (res <= 0){ /*cout << 0 << endl;*/return 0;}
//	cout << val(n-2*mx)*1LL*val(m-2*mx) << endl;
//	cout <<res - val(n-2*mx)*1LL*val(m-2*mx) << endl;
	return res - val(n-2*mx)*1LL*val(m-2*mx);
}

int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	cin >> w >> h;
	cin >> k1 >> k2;
	cin >> n >> m;
	n++, m++;
	a[0] = 0;
	a[n] = h;
	b[0] = 0;
	b[m] = w;
	if (w < 20000000 && h < 20000000) {
		for (int i = 1; i < n; i++) 	cin >> a[i];
		for (int i = 1; i < m; i++)	cin >> b[i];        
		for (int i = 1; i <= n; i++) 	da[i] = a[i]-a[i-1], ac[da[i]]++;
		for (int i = 1; i <= m; i++) 	db[i] = b[i]-b[i-1], bc[db[i]]++;
		sort (da+1, da+n+1);
		sort (db+1, db+m+1);
		n = unique (da+1, da+n+1)-da;
		m = unique (db+1, db+m+1)-db;
		ll res = 0;
		for (int i = 1; i < n; i++){
		        if (da[i] <= (k1<<1)) continue;
			for (int j = 1; j < m; j++)
				res += calc (da[i], db[j], k1, k2+1)*1LL*ac[da[i]]*1LL*bc[db[j]];//, cout << res << endl;
		}
		cout << res;
		return 0;
	}
	for (int i = 1; i < n; i++) 	cin >> a[i];
	for (int i = 1; i < m; i++)	cin >> b[i];        
	for (int i = 1; i <= n; i++) 	da[i] = a[i]-a[i-1];
	for (int i = 1; i <= m; i++) 	db[i] = b[i]-b[i-1];
	ll res = 0;
	for (int i = 1; i <= n; i++){
	        if (da[i] <= (k1<<1)) continue;
		for (int j = 1; j <= m; j++)
			res += calc (da[i], db[j], k1, k2+1);
	}
	cout << res;

	return 0;
}