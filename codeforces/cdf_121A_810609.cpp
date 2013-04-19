#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

vector<long long> lucky;

void dfs(long long v) {
        if (v > 7777777777LL)
                return;
        if (v) lucky.push_back(v);
        dfs(v * 10 + 4);
        dfs(v * 10 + 7);
}

long long get(long long r) {
        long long cnt, i, j;
        cnt = i = j = 0;
        while (j <= r) {
                cnt += (min(r, lucky[i]) - j + 1) * lucky[i];
                j = lucky[i] + 1;
                i++;
        }
        return cnt;
}

int main() {
        dfs(0);
        sort (lucky.begin(), lucky.end());
        int l, r;
        scanf("%d%d", &l, &r);
#ifdef ONLINE_JUDGE
        printf("%I64d\n", get(r) - get(l - 1));
#else
        printf("%Ld %Ld\n%Ld\n", get(r), get(l - 1), get(r) - get(l - 1));
#endif
        return 0;
}



// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Oct 28, 2011 8:31:49 AM
// contest: 121
// link: /contest/121/submission/810609
// time: 30 ms
// verdict: Accepted
// problem: 121A - Lucky Sum
// ID: 810609
// downloaded by very stupid script
