#include <iostream>
#include <fstream>
using namespace std;
ifstream f("b.in");
ofstream t("b.out");
int n,m,x,y,a[10009],i,j,k;
int main ()
{
    f>>n>>m;
    for (i=0;i<n;i++) a[i]=i;
    for (i=1;i<=m;i++) {
        f>>x>>y;
        if (a[x]>a[y]) swap(x,y);
        k=0;
        for (j=0;j<n;j++) {
            if (a[j]==a[y])
                a[j]=a[x];
            if (a[j]==0)
                k++;
        }
        if (k==n)
            break;
    }
    t<<i;
    return 0;
}
