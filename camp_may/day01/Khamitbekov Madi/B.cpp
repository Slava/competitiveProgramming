#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
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


int X, Y, Z;
int n;

struct boy {
	int x, y, z, id;
	int s;
	void in(int i) {
		cin >> x >> y >> z;
		x *= X;
		y *= Y;
		z *= Z;
		s = x+y+z;
		id = i+1;
	}
	bool operator < (const boy &a) const {
		return s > a.s;
	}	
}a[100007];

int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
                                                 
	cin >> X >> Y >> Z;
	cin >> n;
	for (int i = 0; i < n; i++)	a[i].in(i);
	sort (a, a+n);
	cout << a[0].id << " " << a[1].id << " " << a[2].id;// << " ";
//	cout << a[0].s + a[1].s + a[2].s << endl;

	return 0;
}