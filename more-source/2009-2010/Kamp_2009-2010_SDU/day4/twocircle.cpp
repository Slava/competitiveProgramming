#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    freopen ("twocircle.in", "r", stdin);
    freopen ("twocircle.out", "w", stdout);
    double r1 ,r2 ,x1 ,x2 ,y1 ,y2, d, ansx, ansy, ansx2, ansy2;
    int n,i;
    cin >> n;

    cout.precision(6);

    for(i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;
        if(r2 < r1)
        {
            swap(r1,r2);
            swap(x1,x2);
            swap(y1,y2);
        }
        d = sqrt( (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) );

        if(x1==x2 && y1==y2 && r1==r2)cout << "I can't count them - too many points :(\n";
        else if( r2 > r1 + d || d > r1 + r2 )cout << "There are no points!!!\n";
        else if( r2 == d + r1 || r1 + r2 == d )
        {
            ansx = r1*(x2-x1)/d + x1;
            if( r2 == d + r1 )ansx*=-1;

            ansy = (y2 - y1)*(ansx - x1)/(x2 - x1) + y1;
            cout << "There are only 1 of them....\n" << fixed << ansx << ' ' << ansy << endl;
        }
        else
        {
            cout << "There are only 2 of them....\n" ;

        }

    }
}
