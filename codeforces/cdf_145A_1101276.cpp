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

string a, b;
vector<int> f, s;

int main() {
    cin >> a >> b;
    int n = (int)a.size();
    for (int i = 0; i < n; i++)
        if (a[i] == '4' && b[i] == '7')
            f.push_back(i);
        else if (a[i] == '7' && b[i] == '4')
            s.push_back(i);

    int ans = min(f.size(), s.size());

    cout << (int)f.size() + (int)s.size() - ans << endl;

    return 0;
}




// lang: GNU C++
// memory: 2500 KB
// author: imslavko
// submit_date: Jan 22, 2012 11:04:06 AM
// contest: 145
// link: /contest/145/submission/1101276
// time: 50 ms
// verdict: Accepted
// problem: 145A - Lucky Conversion
// ID: 1101276
// downloaded by very stupid script
