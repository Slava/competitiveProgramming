#include <iostream>

using namespace std;

double n, m;
double f(double x, double r = 1)
{
    double i = 1;
    for(; i <= x; i++)r *= i;
    return r;
}

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> n >> m;
    double sum = 0;

    for(; m <= n; m++)
        sum += f(n)/f(n-m)/f(m);

    cout << sum;

    return 0;
}
