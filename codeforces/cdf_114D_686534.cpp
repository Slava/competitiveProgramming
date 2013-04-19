#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

typedef long long Int;
const int N = 2100;
Int P = 31, pr[N], p[N], start, end;
char s[N]; int len, n, stlen, endlen, ans;
bool isStart[N], isEnd[N];
std::set<Int> Set;

Int hash(int l, int r) {
	Int h = pr[r];
	if (l) h -= pr[l - 1];
	return h * p[N - l - 1];
}

int main() {
	p[N - 1] = 1;
	for (int i = N - 2; i >= 0; i--)
		p[i] = p[i + 1] * P;

	scanf("%s", s); n = strlen(s);
	for (int i = 0; i < n; i++) {
		pr[i] = p[i] * (s[i] - 'a' + 1);
		if (i) pr[i] += pr[i - 1];
	}

	scanf("%s", s); stlen = len = strlen(s);
	for (int i = 0; i < len; i++)
		start += p[i] * (s[i] - 'a' + 1);

	scanf("%s", s); endlen = len = strlen(s);
	for (int i = 0; i < len; i++)
		end += p[i] * (s[i] - 'a' + 1);

	for (int i = 0; i + stlen <= n; i++)
		if (start == hash(i, i + stlen - 1))
			isStart[i] = 1;

	for (int i = 0; i + endlen <= n; i++)
		if (end == hash(i, i + endlen - 1))
			isEnd[i + endlen] = 1;

	for (len = 1; len <= n; len++) {
		if (len < stlen || len < endlen)
			continue;
		Set.clear();

		for (int i = 0; i + len <= n; i++)
			if (isStart[i] && isEnd[i + len])
				Set.insert(hash(i, i + len - 1));

		ans += (int)Set.size();
	}
	
	printf("%d\n", ans);

	return 0;
}




// lang: MS C++
// memory: 1500 KB
// author: imslavko
// submit_date: Sep 9, 2011 8:12:22 PM
// contest: 114
// link: /contest/114/submission/686534
// time: 720 ms
// verdict: Accepted
// problem: 114D - Petr#
// ID: 686534
// downloaded by very stupid script
