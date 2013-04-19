#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int N = 17;
int a[N][N], n, m, best, bestn;
string s, t, S[N]; char buff[20];
map<string, int> M;
vector<string> ans;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", buff); s = buff;
		M[s] = i; S[i] = s;
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", buff); s = buff;
		scanf("%s", buff); t = buff;
		a[M[s]][M[t]] = a[M[t]][M[s]] = 1;
	}
	for (int i = 0; i < (1 << n); i++) {
		bool bad = 0; int num = 0;
		for (int j = 0; j < n; j++)
			if (i & (1 << j)) {
				for (int k = 0; k < n; k++)
					if (i & (1 << k))
						bad |= a[j][k];
				num++;
			}
		if (!bad && num > bestn)
			best = i, bestn = num;
	}
	
	for (int i = 0; i < n; i++)
		if (best & (1 << i))
			ans.push_back(S[i]);
	sort (ans.begin(), ans.end());

	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++)
		printf("%s\n", ans[i].c_str());

	return 0;
}




// lang: MS C++
// memory: 1400 KB
// author: imslavko
// submit_date: Sep 9, 2011 7:12:43 PM
// contest: 114
// link: /contest/114/submission/686371
// time: 60 ms
// verdict: Accepted
// problem: 114B - PFAST Inc.
// ID: 686371
// downloaded by very stupid script
