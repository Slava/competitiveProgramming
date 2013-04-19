#include <iostream>
#include <string>
#include <vector>

using namespace std;

string a[300], b;
int n;
vector<int> child, cap, man, captain, rat;
int main ()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b;
        if (b == "rat")
            rat.push_back(i);
        if (b == "child" || b == "woman")
            child.push_back(i);
        if (b == "man")
            man.push_back(i);
        if (b == "captain")
            cap.push_back(i);
    }
    for (int i = 0; i < rat.size(); i++)
        cout << a[rat[i]] << "\n";
    for (int i = 0; i < child.size(); i++)
        cout << a[child[i]] << "\n";
    for (int i = 0; i < man.size(); i++)
        cout << a[man[i]] << "\n";
    for (int i = 0; i < cap.size(); i++)
        cout << a[cap[i]] << "\n";
    return 0;
}




// lang: GNU C++
// memory: 1400 KB
// author: imslavko
// submit_date: Feb 28, 2011 7:08:13 PM
// contest: 63
// link: /contest/63/submission/309798
// time: 30 ms
// verdict: Accepted
// problem: 63A - Sinking Ship
// ID: 309798
// downloaded by very stupid script
