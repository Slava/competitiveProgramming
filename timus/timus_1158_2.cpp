#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

const int base = 1000000000;
const int N = 110, K = 60;
int link[N][K], suff[N], leaf[N],
    goArr[N][K], p[N], pch[N];
int nodesUsed;

map<char,int> Map;
int conv(char c) {
    return Map[c];
}

void init() {
    memset(link, -1, sizeof link);
    memset(goArr, -1, sizeof goArr);
    memset(suff, -1, sizeof suff);
    memset(leaf, 0, sizeof leaf);
    memset(p, -1, sizeof p);

    nodesUsed = 1;
}

int go(int v, int ch);
int getSuff(int v) {
    if (suff[v] + 1)
        return suff[v];
    if (!v || !p[v])
        return suff[v] = 0;
    return suff[v] = go(getSuff(p[v]), pch[v]);
}

int go(int v, int ch) {
    if (goArr[v][ch] + 1)
        return goArr[v][ch];
    if (!v && link[v][ch] == -1)
        return goArr[v][ch] = 0;
    if (link[v][ch] != -1)
        return goArr[v][ch] = link[v][ch];
    return goArr[v][ch] = go(getSuff(v), ch);
}

void addString(char *s, int len) {
    int v = 0;
    for (int i = 0; i < len; i++) {
        int ch = conv(s[i]);
        int &to = link[v][ch];
        if (to == -1) {
            to = nodesUsed++;
            p[to] = v;
            pch[to] = ch;
        }

        v = to;
    }
    leaf[v] = 1;
}

struct bigint {
    vector<int> a;
	bigint operator+(const bigint &v) const {
		bigint res = v;
		for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
			if (i == (int) res.a.size())
				res.a.push_back(0);
			res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
			carry = res.a[i] >= base;
			if (carry)
				res.a[i] -= base;
		}
		return res;
	}
};

char s[100];
bigint dp[62][N];
int main() {
    init();
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p); gets(s);

    gets(s);
    for (int i=0; i<n; i++)
        Map[s[i]] = i;

    for (int i=0; i<p; i++) {
        gets(s);
        addString(s, strlen(s));
    }

    for (int i=0; i<nodesUsed; i++)
        leaf[i] |= leaf[getSuff(i)];

    dp[0][0].a.push_back(1);
    for (int i=0; i<m; i++)
        for (int j=0; j<nodesUsed; j++) if(!leaf[j])
            for (int k=0; k<n; k++)
                if (!leaf[go(j,k)])
                    dp[i+1][go(j,k)] = dp[i+1][go(j,k)] + dp[i][j];

    bigint ans;
    for (int i=0; i<nodesUsed; i++)
        ans = ans + dp[m][i];

    if (ans.a.size())
        printf("%d", ans.a.back());
    else printf("0");
    for (int i = (int)ans.a.size()-2; i>=0; i--)
        printf("%09d", ans.a[i]);

    puts("");

    return 0;
}


