#include <cstdio>
#include <iostream>
using namespace std;

int main ()
{
int n, k, a = 1;
cin >> n >> k;
for (k=n-k+1;k <= n; k++)
  a *= k;
cout << a;
}
