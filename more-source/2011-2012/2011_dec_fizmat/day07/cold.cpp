#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

const int N = 101010;
typedef long long Int;
Int H, W, ans[N];
int n;
typedef pair<pair<Int,Int>, Int> ppIII;
pair<pair<Int, Int>, int> a[N];
set<ppIII> Set;

#define x first.first
#define y first.second
#define id second
#define l first.first
#define r first.second
#define X second
#define mp make_pair

#ifdef WIN32
#define i64 "%I64d"
#else
#define i64 "%lld"
#endif


int main() {
	scanf(i64 i64 "%d", &W, &H, &n);
	for (int i = 0; i < n; i++) {
		double xx, yy;
		scanf("%lf%lf", &xx, &yy);
		a[i].x = (Int)(xx * 2);
		a[i].y = (Int)(yy * 2);
		a[i].id = i;
	}
	
	sort(a, a + n);
	Set.insert(mp(mp(0,H*2),0LL));
	for (int i = 0; i < n; i++) {
//		cout << "current = " << a[i].x << ", " << a[i].y << " " << a[i].id << endl;
		set<ppIII>::iterator p = 
		Set.lower_bound(mp(mp(a[i].y,1LL<<60),1LL<<60));p--;
//		cout << p->l << " " << p->r << " " << p->X << endl;
		Int rad = a[i].x - p->X;
		ans[a[i].id] = rad;
		Int L = 1LL << 60, 
			R = -1;
		p = Set.lower_bound(mp(mp(a[i].y-rad,1LL<<60),1LL<<60));p--; 
		while (p != Set.end() && p->l < a[i].y+rad) {
			if (p->r <= a[i].y-rad) {
				p++;
				continue;
			}
			L = min(L, p->l);
			R = max(R, p->r);
//			cout << "erase " << p->l << " " << p->r << " " << p->X << endl;
			Set.erase(p);
			p++;
		}
		if(L != (1LL << 60) && L != a[i].y-rad) {
			Set.insert(mp(mp(L,a[i].y-rad),a[i].x-rad));
//			cout << "insert " << L << " " << a[i].y-rad << "  " << a[i].x-rad<<endl;
		}
		if(R != -1 && R != a[i].y+rad) {
			Set.insert(mp(mp(a[i].y+rad,R),a[i].x-rad));
//			cout << "insert " << a[i].y+rad << " " << R << "  " << a[i].x-rad<<endl;
		}
		Set.insert(mp(mp(a[i].y-rad,a[i].y+rad),a[i].x+rad));
//		cout << "insert " << a[i].y-rad << " " << a[i].y+rad << " " << a[i].x+rad << endl;
//		cout << "ans["<<a[i].id<<"] = " << rad << endl;
	}

	for (int i = 0; i < n; i++)
		printf(i64 "\n", ans[i]);

	return 0;
}

