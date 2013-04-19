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
#define sq(x) ((x)*(x))
#define mp make_pair
#define len length()
#define sz size()
#define f first
#define s second

int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int n, x;
	int mn = 34000;
	int s = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x, s += x, mn = min (mn, x);
	cout << s - mn;

	return 0;
}