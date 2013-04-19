#include <iostream>
#include <ctime>
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

#define abs(x) ((x) >= 0 ? (x) : -(x))
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define len length()
#define sz size()
#define f first
#define s second

int n, k;
int D;
int mn, mx;
int a[2000];
bool u[2000]={0};
ll s[2000]={0};
ll res = 0;

bool ok (int x, int y) {
	int d = abs(x-y);
	return (d >= mn && d <= mx);
}
bool bad (int x, int y) {
	int d = abs(x-y);
	return d > mx;
}                       
double Time () {
	return double (clock()) / double (CLOCKS_PER_SEC);
}
void rec (int x, int k, int pr) {
	if (Time() >= 1.4) {
		cout << res;
		exit(0);		
	}
	if (k == 0) {
		ll sum = 0;
		for (int i = 0 ;i < n; i++)
			if (u[i]){
//				cout << i+1 << " ";
				for (int j = i+1; j < n; j++)
					if (u[j])sum += abs(a[j]-a[i]);
			}           
		sum <<= 1;

//		cout << sum << endl;
		res = max(res, sum);
		return;
	}
	for (int i = x; i < n; i++) {  	
		if (ok(a[pr], a[i]) || pr == -1) {
			if (k == 1 && !ok(a[i], D)) continue;
			if (x == 0 && !ok(0,a[i])) continue;
			u[i] = 1;
			rec (i+1, k-1, i);
			u[i] = 0;
		}
		if (pr != -1 && bad(a[pr], a[i])) return;
	}
}

ll res1 = 0;
void check () {
	ll sum = 0;
	int c = 0;
	for (int i = 0 ;i < n; i++)
		if (u[i]){
		c++;
//			cout << i+1 << " ";
			for (int j = i+1; j < n; j++)
					if (u[j])sum += abs(a[j]-a[i]);
			}           
	sum <<= 1;
	if (c != k) return;
//	cout << sum << endl;
	res1 = max(res1, sum);
}

ll greedy () {
	for (int i = 0; i < n; i++) {
		u[i] = 1;
		if (ok(0,a[i])) {
			int kk = k;
			int ii = i;
			while (kk > 1) {
				int j = ii+1;
				while (!bad(a[j], a[ii])) j++;
				j--;
				if (!ok(a[ii],a[j]))break;
				u[j] = 1;
				kk--;
				ii = j;
			}
		}else break;
		check();
		for (int j = 0; j < n; j++) u[j] = 0;
	}
	return res1;
}

int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	cin >> n >> k;
	cin >> mn >> mx;
	cin >> D;
	for (int i = 0; i < n; i++) cin >> a[i];

	if (k == 1) {
		cout << 0;
		return 0;
	}
	if (k == n) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)	
				res += abs(a[i]-a[j]);
		cout << res;
		return 0;
	}
	rec (0,k, -1);
	if (n > 30 && k > 10) cout << greedy();
	else {
		rec (0,k,-1);
		cout << res;
	}

	return 0;
}