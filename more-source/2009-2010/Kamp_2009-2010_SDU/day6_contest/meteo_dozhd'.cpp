#include <iostream>
#include <cmath>

using namespace std;

struct dot
{
    double x,y;
};

double AxB(dot a1,dot a2,dot b1,dot b2)
{
    return (a2.x-a1.x)*(b2.y-b1.y)-(b2.x-b1.x)*(a2.y-a1.y);
}
int main()
{
    long n,i,m,now,pre;
    double A=0,B=0;
    bool b[30000];
    cin>>n;
    dot a[30000],S;
    for(i=0;i<n;i++)
        cin>>a[i].x>>a[i].y;

    cin>>m;
    for(int j=0;j<m;j++)
    {
        cin>>S.x>>S.y;
        if(AxB(a[n-1],a[0],a[n-1],S)<0)pre=-1;
        if(AxB(a[n-1],a[0],a[n-1],S)>0)pre=1;
        if(AxB(a[n-1],a[0],a[n-1],S)==0)continue;
        bool z=0;
        for(i=0;i<n-1;i++)
        {
            if(AxB(a[i],a[i+1],a[i],S)<0)now=-1;
            if(AxB(a[i],a[i+1],a[i],S)>0)now=1;
            if(AxB(a[i],a[i+1],a[i],S)==0){z=1;break;}

            if(now!=pre){z=1;break;}
            swap(now,pre);
        }
        if(z)continue;
        b[j]=1;
    }
    for(int j=0;j<m;j++)
        if(b[j])cout<<"YES\n";
        else cout<<"NO\n";

}


