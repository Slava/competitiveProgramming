#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

typedef long long Int;
typedef pair<int,int> ii;
#define sz(x) ((int)x.size())
#define pb push_back
#define forc(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); ++i)
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)

int n, a[2000];
char s[20], t[20];

void doit(int p, int &x) {
	sprintf(s, "%d", x);
	int b = -1;
	if (x > p)
		for (int i = x; i >= p; i--) {
			sprintf(t, "%d", i); int c = 0;
			for (int k = 0; k < 4; k++)
				c += (t[k] != s[k]);
			if (c < 2)
				b = i;
		}
	else 
		for (int i = p; i < 2012; i++) {
			sprintf(t, "%d", i); int c = 0;
			for (int k = 0; k < 4; k++)
				c += (t[k] != s[k]);
			if (c < 2) {
				b = i; break;
			}
		}
	x = b;
}

int main() {
	scanf("%d", &n);
	a[0] = 1000;
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++) {
		doit(a[i - 1], a[i]);
		if (a[i] < a[i - 1] || a[i] > 2011) {
			puts("No solution");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", a[i]);
	return 0;
}






// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Jul 11, 2011 9:42:00 AM
// contest: 65
// link: /contest/65/submission/541602
// time: 200 ms
// verdict: Accepted
// problem: 65B - Harry Potter and the History of Magic
// ID: 541602
// downloaded by very stupid script
