#include <iostream>
#include <cmath>

using namespace std;

struct dot
{
    double x,y;
};

double A(dot a, dot b, dot c)
{
    return fabs(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,i,s=0;
    cin>>n;
    dot a,b,c,d,x;
    for(i=0;i<n;i++)
    {
        cin>>x.x>>x.y>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
        s+=(A(a,b,c)+A(a,d,c)==A(a,b,x)+A(b,c,x)+A(c,d,x)+A(d,a,x));
    }
    cout<<s;
}
