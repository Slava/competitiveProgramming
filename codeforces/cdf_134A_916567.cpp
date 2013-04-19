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

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
        if ((sum - a[i]) == (n - 1) * a[i])
            ans.push_back(i);

    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] + 1 << " ";
        

    return 0;
}




// lang: GNU C++
// memory: 4500 KB
// author: imslavko
// submit_date: Dec 2, 2011 7:01:45 PM
// contest: 134
// link: /contest/134/submission/916567
// time: 330 ms
// verdict: Accepted
// problem: 134A - Average Numbers
// ID: 916567
// downloaded by very stupid script
