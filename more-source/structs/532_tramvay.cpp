#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define f first
#define s second
typedef pair<int,int> pii;

int nextInt() {
	int x; 
	scanf("%d", &x);
	return x;
}

struct ev {
	int o, i, a, b;
	ev(int O, int I, int A, int B) {
		o = O; i = I; a = A; b = B;
	}
};

bool cmp(ev a, ev b) { 
	if (a.i == b.i)
		return a.o;
	return a.i < b.i; 
}

vector<ev>events;
multiset<pii>Sit, Stand;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m, p;
	n = nextInt(); m = nextInt(); p = nextInt();
	for (int i = 0; i < n; i++) {
		int a, b; a = nextInt(); b = nextInt();
		events.push_back(ev(1,nextInt(),a,b));
		events.push_back(ev(0,nextInt(),a,b));
	}

	sort(events.begin(), events.end(), cmp);

	long long ans = 0, pl = 0;

	vector<ev>::iterator event = events.begin();
	for (int stop = 1; stop <= p; stop++) {
		ans += pl;

		while (event != events.end() && event->i == stop) {
			if (event->o)
				Stand.insert(pii(event->b - event->a, event->b)),
					pl += event->b;
			else {
				pii er(event->b - event->a, event->b);
				if (Stand.find(er) != Stand.end())
					Stand.erase(Stand.find(er)),
						pl -= event->b;
				else Sit.erase(Sit.find(er)),
					pl -= event->b - er.first;
			}
			event++;
		}

		while (Sit.size() < m && !Stand.empty() && Stand.begin()->f < 0) {
			Sit.insert(*Stand.begin());
			pl -= Stand.begin()->f;
			Stand.erase(Stand.begin());
		}

		while (!Sit.empty() && !Stand.empty() && 
				Sit.rbegin()->f > Stand.begin()->f) {
			pii toStand = *Sit.rbegin();
			Sit.erase(Sit.find(toStand));
			pl += toStand.f;
			Stand.insert(toStand);
			pii toSit = *Stand.begin();
			Stand.erase(Stand.begin());
			pl -= toSit.f;
			Sit.insert(toSit);
		}
	}

	printf("%I64d\n", ans);

	return 0;
}


