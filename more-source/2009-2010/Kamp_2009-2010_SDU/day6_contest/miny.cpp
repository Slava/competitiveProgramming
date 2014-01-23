#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct dot{
    double x,y;
    };

double AxB(dot a1,dot a2,dot b1,dot b2)
{
    return (a2.x-a1.x)*(b2.y-b1.y)-(b2.x-b1.x)*(a2.y-a1.y);
}

double sqvec(dot a1,dot a2)
{
    return (a2.x-a1.x)*(a2.x-a1.x)+(a2.y-a1.y)*(a2.y-a1.y);
}

int main()
{
    freopen("input.txt","r",stdin);
    int i,j,m=1,n,min,k,ans=0,z;
    bool u[1009]={0};
    cin>>n;z=n;
    vector<dot>A,B;A.resize(n+2);B.resize(n+2);
    for(i=1;i<=n;i++)
        cin>>A[i].x>>A[i].y;

    while(z>1){
        m=1;
        ans++;
        for(i=2;i<=n;i++)
        {
            if(u[i])continue;
            if(A[i].y<A[m].y)m=i;
            else if(A[i].x>A[m].x
                  &&A[i].y==A[m].y)m=i;
        }
            B[1]=A[m];A[m]=A[1];A[1]=B[1];
            k=1;min=2;
        do
        {
            for(j=2;j<=n;j++){
            if(u[j])continue;
                if(AxB(B[k],A[min],B[k],A[j])<0 ||
                (!AxB(B[k],A[min],B[k],A[j])&&sqvec(B[k],A[min])<sqvec(B[k],A[j])))
                    min=j;
            }
                    k++;
                    B[k].x=A[min].x;
                    B[k].y=A[min].y;
                    min=1;

        }while(B[k].x!=B[1].x||B[k].y!=B[1].y);
        k--;
        if(z==2){ans--;break;}
        for(int i=1;i<=n;i++)
            for(int j=1;j<=k;j++)
                if(A[i].x==B[j].x&&A[i].y==B[j].y)
                    {u[i]=1;z--;}
        if(z==1)break;
        }

    cout<<z<<' '<<ans;
return 0;
}
