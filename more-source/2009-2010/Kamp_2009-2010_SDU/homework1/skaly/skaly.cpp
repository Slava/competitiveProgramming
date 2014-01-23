#include <iostream>

using namespace std;

float m[10000][10000];
long a[100009],n,l;

void R(long p, long h)
{
    long i,j;
    a[p]+=h;
    for(i=1;i<=h;i++)
    {
        if(p+i<=l)a[p+i]+=h-i;
        if(p-i>0)a[p-i]+=h-i;
    }
    for(i=1;i<=min(p+h,l);i++)
        for(j=max(p-h,i+1);j<=l;j++)
            m[i][j]=(i!=j)*(m[i][j-1]+(float)(a[j-1]+a[j])/2);
}

int main()
{
    freopen("rocks.in","r",stdin);
    freopen("rocks.out","w",stdout);

    cin>>n>>l;
    long i,c,p,h;
    for(i=0;i<n;i++)
    {
        cin>>c;
        if(c==1)
        {
            cin>>p>>h;
            cout<<"-1\n";
            R(p,h);
        }
        if(c==2)
        {
            cin>>p>>h;
            cout<<m[p][h]<<endl;
        }
    }


    return 0;
}
