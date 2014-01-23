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
