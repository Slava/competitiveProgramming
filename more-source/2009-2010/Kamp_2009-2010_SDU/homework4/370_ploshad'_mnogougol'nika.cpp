#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    long x,y,xi,yi,s=0,x1,y1,n,i;
    cin >> n;
    cin >> x1 >> y1;
    x1 += 30000;
    y1 += 30000;
    x = x1;
    y = y1;

    for(i=1;i<n;i++)
    {
        cin >> xi >> yi;
        xi += 30000;
        yi += 30000;
        s+=(x-xi)*(y+yi);
        swap(x,xi);
        swap(y,yi);
    }
    s+=(x-x1)*(y+y1);
    cout.precision(1);
    cout << fixed << fabs((double)s/2);

    return 0;
}
