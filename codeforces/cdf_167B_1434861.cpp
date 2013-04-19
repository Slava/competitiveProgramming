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

int n, l, k, a[300];
double p[300], dp[250][450][250];
int main() {
    cin >> n >> l >> k;
    for (int i = 0; i < n; i++)
        cin >> p[i], p[i] /= 100.;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp[0][k+210][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 423; j++)
            for (int won = 0; won < 210; won++)
                if (dp[i][j][won]) {
                    dp[i+1][min(j+a[i],422)][won+1] += dp[i][j][won] * p[i];
                    dp[i+1][j][won] += dp[i][j][won] * (1-p[i]);
                }

    double answer = 0;
    for (int i = 210; i < 423; i++)
        for (int j = l; j < 210; j++)
            answer += dp[n][i][j];

    cout.precision(8);
    cout << fixed << answer << endl;
    return 0;
}



// lang: GNU C++
// memory: 221500 KB
// author: imslavko
// submit_date: Mar 28, 2012 7:29:13 AM
// contest: 167
// link: /contest/167/submission/1434861
// time: 130 ms
// verdict: Accepted
// problem: 167B - Wizards and Huge Prize
// ID: 1434861
// downloaded by very stupid script
