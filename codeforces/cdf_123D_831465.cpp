#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;


const int MAXLEN = 101000;
const int K = 26;
struct state {
	int length, link;
	int next[K];
	bool clonned;
};
state st[MAXLEN*2-1];
int sz, last;

void init() {
	st[0].link = -1;
	memset (st[0].next, -1, sizeof st[0].next);
	++sz;
}

void sa_extend (char c) {
    c -= 'a';
	int nlast = sz++;
	st[nlast].length = st[last].length + 1;
	memset (st[nlast].next, -1, sizeof st[nlast].next);
	int p;
	for (p=last; p!=-1 && st[p].next[c]==-1; p=st[p].link)
		st[p].next[c] = nlast;
	if (p == -1)
		st[nlast].link = 0;
	else {
		int q = st[p].next[c];
		if (st[p].length + 1 == st[q].length)
			st[nlast].link = q;
		else {
			int clone = sz++;
			st[clone].length = st[p].length + 1;
			memcpy (st[clone].next, st[q].next, sizeof st[clone].next);
			st[clone].link = st[q].link;
			for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[nlast].link = clone;
			st[clone].clonned = 1;
		}
	}
	last = nlast;
}

string s;
vector<int>g[MAXLEN*2], bg[MAXLEN*2];

bool u[MAXLEN*2], used[MAXLEN*2];
long long dp[MAXLEN*2], dp2[MAXLEN*2];

long long go(int v) {
    if (u[v])
        return dp[v];
    u[v] = 1;
    dp[v] = !st[v].clonned;
    for (int i = 0; i < (int)g[v].size(); i++)
        dp[v] += go(g[v][i]);
    return dp[v];
}

long long go2(int v) {
    if (!v)return 1;
    if (used[v])
        return dp2[v];
    used[v] = 1;
    for (int i = 0; i < (int)bg[v].size(); i++)
        dp2[v] += go2(bg[v][i]);
    return dp2[v];
}

int main() {
    cin >> s;
    int n = (int)s.size();
    init();
    for (int i = 0; i < n; i++)
        sa_extend(s[i]);

    for (int i = 0; i < sz; i++) {
        if(i)g[st[i].link].push_back(i);
        for (int j = 0; j < K; j++)
            if (st[i].next[j] != -1)
                bg[st[i].next[j]].push_back(i);
    }

    long long ans = 0;
    for (int i = 1; i < sz; i++) {
        long long t = go(i);
        if (t % 2 == 0)
            t = (t / 2) * (t + 1);
        else t = ((t + 1) / 2) * t;
        t *= go2(i);
        ans += t;
    }

    cout << ans <<endl;

    return 0;
}





// lang: GNU C++
// memory: 40800 KB
// author: imslavko
// submit_date: Nov 3, 2011 8:49:03 PM
// contest: 123
// link: /contest/123/submission/831465
// time: 280 ms
// verdict: Accepted
// problem: 123D - String
// ID: 831465
// downloaded by very stupid script
