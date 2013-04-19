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
#include <climits>

using namespace std; 

int gcd(int a, int b) {
    int res = 0;
    while (a && b) {
        if (a > b) {
            res += a / b;
            a %= b;
        } else {
            res += b / a;
            b %= a;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
        if (__gcd(i,n) == 1)
            ans = min(ans, gcd(i,n));
        
    cout << ans - 1 << endl;

    return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Dec 2, 2011 7:10:25 PM
// contest: 134
// link: /contest/134/submission/916662
// time: 220 ms
// verdict: Accepted
// problem: 134B - Pairs of Numbers
// ID: 916662
// downloaded by very stupid script
