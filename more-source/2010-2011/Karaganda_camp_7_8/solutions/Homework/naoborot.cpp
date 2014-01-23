#include <iostream>

using namespace std;

int n;
void r (int i = 0)
{
int x;
cin >> x;
if (i < n) r(i+1);
cout << x << ' ';
}

int main ()
{
cin >> n;
r ();

}