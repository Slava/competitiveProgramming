#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MOD 100000000
#define sz(x) ((int)x.size())

int nextInt();
long long nextInt64();


int n[2], N, K[2], dp[220][120][2][12], ans;
int main() {
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    cin >> n[0] >> n[1] >> K[0] >> K[1];
    N = n[0] + n[1];
    dp[0][1][0][1] = dp[0][0][1][1] = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= n[0]; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 1; l < 12; l++)
                    if (dp[i][j][k][l]) {
                       // printf("%d %d %d %d\n", i, j, k, l);
                        if (i == N - 1)ans = (ans + dp[i][j][k][l]) % MOD;
                        int w[2] = {j, i - j + 1};
                        if (w[k] < n[k] && l + 1 <= K[k])
                            dp[i + 1][j + !k][k][l + 1] = ( dp[i + 1][j + !k][k][l + 1] + dp[i][j][k][l]) % MOD;
                        if (w[!k] < n[!k])
                            dp[i + 1][j + k][!k][1] = (dp[i][j][k][l] + dp[i + 1][j + k][!k][1]) % MOD;
                    }
    printf("%d\n", ans);
    return 0;
}

int nextInt() {
    int x;
    scanf("%d", &x);
    return x;
}

long long nextInt64() {
    long long x;
    scanf("%I64d", &x);
    return x;
}




// lang: GNU C++
// memory: 3800 KB
// author: imslavko
// submit_date: Oct 7, 2011 7:43:23 PM
// contest: 118
// link: /contest/118/submission/744355
// time: 30 ms
// verdict: Accepted
// problem: 118D - Caesars Legions
// ID: 744355
// downloaded by very stupid script
