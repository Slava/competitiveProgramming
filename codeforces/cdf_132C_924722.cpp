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
#include <ctime>

using namespace std; 

char s[2000];
int n, len, ans;
int dpmin[120][55][2],
        dpmax[120][55][2];
bool u[120][55][2];
int inf = 10005000;

bool go(int i, int n, int d) {
        if (i == len) {
                if (n % 2 == 0)
                        return 1;
                return 0;
        }
        if (u[i][n][d])
                return 1;
        u[i][n][d] = 1;
        dpmin[i][n][d] = inf;
        dpmax[i][n][d] = -inf;
        if (s[i] == 'F') {
                if (go(i + 1, n, d)) {
                        dpmin[i][n][d] = min(dpmin[i][n][d], (d?-1:1) + dpmin[i + 1][n][d]);
                        dpmax[i][n][d] = max(dpmax[i][n][d], (d?-1:1) + dpmax[i + 1][n][d]);
                }
                if (n > 0 && go(i + 1, n - 1, d ^ 1)) {
                        dpmin[i][n][d] = min(dpmin[i][n][d], dpmin[i+1][n-1][d^1]);
                        dpmax[i][n][d] = max(dpmax[i][n][d], dpmax[i+1][n-1][d^1]);
                }
        }
        else {
                if (n > 0 && go(i + 1, n - 1, d)) {
                        dpmin[i][n][d] = min(dpmin[i][n][d], (d?-1:1) + dpmin[i+1][n-1][d]);
                        dpmax[i][n][d] = max(dpmax[i][n][d], (d?-1:1) + dpmax[i+1][n-1][d]);
                }
                if (go(i + 1, n, d ^ 1)) {
                        dpmin[i][n][d] = min(dpmin[i][n][d], dpmin[i+1][n][d^1]);
                        dpmax[i][n][d] = max(dpmax[i][n][d], dpmax[i+1][n][d^1]);
                }
        }
//      printf("%d %d %d  %d %d\n", i, n, d, dpmin[i][n][d], dpmax[i][n][d]);
        return 1;
}

int main() {
        scanf("%s%d", s, &n);
        len = strlen(s);

        go(0,n,0);
        ans = max(-dpmin[0][n][0],dpmax[0][n][0]);
        printf("%d\n", ans);
        return 0;
}




// lang: GNU C++
// memory: 1500 KB
// author: imslavko
// submit_date: Dec 3, 2011 8:19:36 PM
// contest: 132
// link: /contest/132/submission/924722
// time: 30 ms
// verdict: Accepted
// problem: 132C - Logo Turtle
// ID: 924722
// downloaded by very stupid script
