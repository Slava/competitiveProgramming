// Kim Vyacheslav KarKTL
#include <cstdio>
#include <set>
#include <string>
#include <iostream>

using namespace std;
long long n;
int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n;
    if (n % 2 == 0) printf("0 0");
    else cout << 2 << " " << n + 2;
    return 0;
}
