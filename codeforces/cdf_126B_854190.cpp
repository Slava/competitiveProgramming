#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
//#include <cmath>

#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1000100;
typedef long long Int;
Int P = 31, p[N], pr[N];
char s[N];
int n, can[N], k;

Int hash(int l, int r) {
    Int h = pr[r];
    if (l) h -= pr[l - 1];
    return h * p[N - l - 1];
}

bool ok(int l) {
    Int h = hash(0, l);
    for (int i = 1; i + l + 1 < n; i++)
        if (h == hash(i, i + l))
            return true;
    return false;
}

int main() {
    p[N - 1] = 1;
    for (int i = N - 2; i >= 0; i--)
        p[i] = p[i + 1] * P;
    
    scanf("%s", s);
    n = strlen(s);
    
    for (int i = 0; i < n; i++)
        pr[i] = p[i] * (s[i] - 'a' + 1) + (i ? pr[i - 1] : 0);
    
    for (int i = 0; i + 1 < n; i++)
        if (hash(0,i) == hash(n - i - 1, n - 1))
            can[k++] = i;
        
    int l = 0, r = k - 1, m, ans = 0;

    while (l <= r) {
        m = (l + r) / 2;
        if (ok(can[m]))
            l = m + 1, ans = can[m] + 1;
        else r = m - 1;
    }    
    
    if (!ans)
        puts("Just a legend");
    else
        for (int i = 0; i < ans; i++)
            printf("%c", s[i]);
    
    return 0;
}





// lang: MS C++
// memory: 21900 KB
// author: imslavko
// submit_date: Nov 10, 2011 7:37:27 AM
// contest: 126
// link: /contest/126/submission/854190
// time: 270 ms
// verdict: Accepted
// problem: 126B - Password
// ID: 854190
// downloaded by very stupid script
