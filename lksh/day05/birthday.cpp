#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;
char s[200];
int n, len;
set<ll>Set;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		ll h = 0, p = 1; len = strlen(s);
		for (int j = 0; j < len; j++, p *= 37LL)
			h += (s[j] - 'a' + 1) * p;
		Set.insert(h);
	}
	printf("%d\n", (int)Set.size());
	return 0;
}
