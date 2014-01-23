#include <iostream>
using namespace std;

int q[1000],a[40][80],n,k,l,i;
long long sum=0;


void L()
{
    a[q[i]-1][k]=a[q[i]][k]+1;
    a[q[i]-1][a[q[i]-1][k]]+=a[q[i]][a[q[i]][k]];
    q[l]=q[i]-1;l++;
}

void R()
{
    a[q[i]+1][k]=a[q[i]][k]+1;
    a[q[i]+1][a[q[i]+1][k]]+=a[q[i]][a[q[i]][k]];
    q[l]=q[i]+1;l++;
}

void show()
{
    cout<<q[i]-n<<endl;
    for(int j=1;j<=k;j++)
    {
        for(int z=0;z<n+n;z++)
        {
            cout<<a[z][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>k;
    q[0]=n;l=1;
    a[n][0]=1;
    a[n][k]=0;

    for(i=0;i<l;i++)
    {
        if(q[i]==q[i-1])continue;
        if(q[i]==n+n-1)
        {
            if(a[q[i]][k]==k-1)sum+=a[q[i]][a[q[i]][k]];
            else L();
            continue;
        }
        if(a[q[i]][k]==k-1)continue;
        R();L();
        //show();
    }
    cout<<sum;

    return 0;
}
