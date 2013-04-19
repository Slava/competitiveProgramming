#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

#define pb push_back

class item
{
    public :
        long a, id;
};

bool u[400];
vector <int> ans;

int main ()
{
    long n;
    item a[400], b[400];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].a;
        a[i].id = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i].a;
        for (int j = n  - 1; j >= 0; j--)
            if (a[j].a == b[i].a && !u[j])
            {
                b[i].id = a[j].id;
                u[j] = 1;break;
            }
    }
    for (int i = 0; i < n; i++)
        for (int j = n - 2; j >= 0; j--)
            if (b[j].id > b[j + 1].id)
            {
                ans.pb(j + 1);
                swap (b[j], b[j + 1]);
            }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " " << ans[i] + 1 << "\n";

    return 0;
}






// lang: GNU C++
// memory: 1800 KB
// author: imslavko
// submit_date: Jan 6, 2011 8:02:24 PM
// contest: 53
// link: /contest/53/submission/239202
// time: 60 ms
// verdict: Accepted
// problem: 53D - Physical Education
// ID: 239202
// downloaded by very stupid script
