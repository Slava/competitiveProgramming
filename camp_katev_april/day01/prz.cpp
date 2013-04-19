#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define a first
#define b second
typedef pair<int,int> pii;

pii operator + (pii a, pii b)
{	return pii(min(a.a, b.a), max(a.b, b.b));	}
bool intersect (pii a, pii b)
{
	if (a > b)
		swap(a, b);
	return (a.a == b.a || a.b >= b.a || a.b >= b.b);
}
vector<pii>a, b;
int main ()
{
	freopen ("PRZ.IN", "r", stdin);
	freopen ("PRZ.OUT", "w", stdout);
	int n, x, y;
	scanf ("%d", &n);
	a.reserve(n);
	b.reserve(n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d%d", &x, &y);
		a.push_back(pii(x,y));
	}
	for (;;){
		sort (a.begin(), a.end());
		int prev = a.size();
		while (a.size())
		{
			if (a.size() == 1){
				b.push_back(a[0]);
				a.clear();
				break;
			}
			pii z(a.back());
			a.pop_back();
			while (a.size() && intersect(z, a.back()))
			{
				z = z + a.back();
				a.pop_back();
			}
			b.push_back(z);
		}
		if (prev == b.size())
			break;
		swap (a, b);
	}
	sort(b.begin(), b.end());
	for (int i = 0; i < b.size(); i++)
		printf("%d %d\n", b[i].a, b[i].b);
	return 0;
}

