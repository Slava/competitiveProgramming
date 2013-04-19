#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

string s;
int n, c[26], p[1001];
char bel[1001];
bool prime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}


int main() {
    cin >> s;
    n = (int)s.size();
//    for (int i = 0; i < n; i++)
//        p[i] = i;
    //vector<int> t(n);
    string ans(n, '?');
    for (int i = 0; i < n; i++)
        c[s[i] - 'a']++;

    int cnt = 1;
    for (int i = 2; i <= n; i++)
        if (prime(i) && i + i > n)
            cnt++;

    int sum = n - cnt;
    int take = -1;

    for (int i = 0; i < 26; i++)
        if (c[i] >= sum && c[i])
            take = i;

    if(take == -1) {
        puts("NO");
        return 0;
    }

    c[take] -= sum;
//    cerr << take << endl;
    for (int i = 1; i < n; i++)
        if (prime(i + 1) && i + i + 2 > n);
        else
            ans[i] = take + 'a';

    for (int i = 0; i < n; i++)
        if (ans[i] == '?') {
            int j = -1;
            for (int k = 0; k < 26; k++)
                if (c[k] > 0)
                    j = k;
            ans[i] = 'a' + j;
            c[j]--;
        }
    cout << "YES" << endl << ans << endl;
    return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Nov 3, 2011 7:46:19 PM
// contest: 123
// link: /contest/123/submission/829317
// time: 30 ms
// verdict: Accepted
// problem: 123A - Prime Permutation
// ID: 829317
// downloaded by very stupid script
