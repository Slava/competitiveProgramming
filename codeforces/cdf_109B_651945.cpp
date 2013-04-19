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

typedef long long Int;
int pl, pr, vl, vr, k, n, a[2000];

void rec(Int v) {
    if (v > 1000000000)
        return;
    a[n++] = v;
    rec(v * 10 + 4);
    rec(v * 10 + 7);
}

int num(int l, int r, int L, int R) {
    int ll, rr;
    ll = max(l, L); rr = min(r, R);
    return rr - ll + 1 < 0 ? 0 : rr - ll + 1;
}

bool debug = 0;
int main() {
    rec(0); a[n++] = 1000000100;
    sort(a, a + n);
    cin >> pl >> pr >> vl >> vr >> k;
    double sum = 0, div;
    div = (pr - pl + 1);
    div *= (vr - vl + 1);
    for (int i = 1; i + k < n; i++) {
        int j = i + k - 1;
        int al = a[i - 1], ar = a[i], bl = a[j], br = a[j + 1];
        Int alp = num(al + 1, ar, pl, pr) * 1LL * num(bl, br - 1, vl, vr);
        Int bet = num(al + 1, ar, vl, vr) * 1LL * num(bl, br - 1, pl, pr);
        if (k == 1 && bet && alp)
            bet--;
        sum += (alp + bet + 0.) / div;
    }
    printf("%.16lf\n", sum);
    return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Aug 30, 2011 2:27:22 PM
// contest: 109
// link: /contest/109/submission/651945
// time: 30 ms
// verdict: Accepted
// problem: 109B - Lucky Probability
// ID: 651945
// downloaded by very stupid script
