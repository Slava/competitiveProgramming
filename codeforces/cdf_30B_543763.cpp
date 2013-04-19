//#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long Int;
typedef pair<int,int> ii;
#define sz(x) ((int)x.size())
#define pb push_back
#define forc(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); ++i)
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)

int M[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int d, m, y, dd, mm, yy;

bool g(int d, int m, int y) {
	if (m < 1 || m > 12)return 0;
	if (d < 1 || ((y%4 || (m != 2 || d != 29)) && d > M[m])) return 0;
	y += 18;
	if (yy > y || (y == yy && (mm > m || (mm == m && dd >= d))))
		return 1;
	return 0;
}

int main() {
	scanf("%d.%d.%d", &dd, &mm, &yy);
	scanf("%d.%d.%d", &d, &m, &y);
	if (g(d,m,y) || g(d,y,m) || g(m,d,y) || g(m,y,d) || g(y,d,m) || g(y,m,d))
		puts("YES");
	else puts("NO");
	return 0;
}





// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 13, 2011 3:14:42 AM
// contest: 30
// link: /contest/30/submission/543763
// time: 30 ms
// verdict: Accepted
// problem: 30B - Codeforces World Finals
// ID: 543763
// downloaded by very stupid script
