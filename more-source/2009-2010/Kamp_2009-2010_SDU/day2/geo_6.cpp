#include <iostream>
#include <cmath>
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
    dot a[1000],b[1000];
    int i,j,m=1,n,min,k;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y;
    //nahodim tochki vypuklogo mnogougol'nika
    for(i=2;i<=n;i++)
        if(a[i].y<a[m].y)m=i;
        else if(a[i].x>a[m].x
              &&a[i].y==a[m].y)m=i;
        b[1]=a[m];a[m]=a[1];a[1]=b[1];
        k=1;min=2;
    do
    {
        for(j=2;j<=n;j++)
            if(AxB(b[k],a[min],b[k],a[j])<0 ||
            (!AxB(b[k],a[min],b[k],a[j])&&sqvec(b[k],a[min])<sqvec(b[k],a[j])))
                min=j;
                k++;
                b[k].x=a[min].x;
                b[k].y=a[min].y;
                min=1;

    }while(b[k].x!=b[1].x||b[k].y!=b[1].y);
    k--;
    //nashli tochki i  pomestili v b[k] [1,k]
    //for(i=1;i<=k;i++)cout<<b[i].x<<' '<<b[i].y<<endl;

    //ishem ploshad'
    double sum=0;
    for(i=1;i<k-1;i++)
        sum+=a[i].x*(a[i+1].y-a[i+2].y);
    sum+=a[k-1].x*(a[k].y-a[1].y)+a[k].x*(a[1].y-a[2].y);
    sum=fabs(sum)/2;
    cout<<sum;

}
//s kodom tak i ne razobralsya, pro vypuklyy. potom nado ponyat'. Slava
