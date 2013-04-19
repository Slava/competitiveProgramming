#include <cstdio>
#include <cstdlib>
#include <cstring>

#define sz(x) ((int)x.size())

int nextInt();
long long nextInt64();

char s[2000];
int main() {
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
#endif
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 'a' - 'A';
        if (s[i] == 'a' || s[i] == 'o' || s[i] == 'y' || s[i] == 'e' || s[i] == 'u' || s[i] == 'i');
        else printf(".%c", s[i]);
    }
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
// memory: 1300 KB
// author: imslavko
// submit_date: Oct 7, 2011 7:02:43 PM
// contest: 118
// link: /contest/118/submission/740901
// time: 30 ms
// verdict: Accepted
// problem: 118A - String Task
// ID: 740901
// downloaded by very stupid script
