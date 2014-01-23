#include <iostream>
#include <fstream>
using namespace std;
ifstream f("c.in");
ofstream t("c.out");
int a[50009],b[50009],i,n,j,y[999],k,c;
void s(int l,int r) {
    int p;
    i=l;j=r;
    p=a[(i+j)/2];
    do {
        while (a[i]<p) i++;
        while (a[j]>p) j--;
        if (i<=j) {
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            i++; j--;
        }
    }while (i<=j);
    if (i<r) s(i,r);
    if (l<j) s(l,j);
}
int main()
{
    f>>n;
    for (i=1;i<=n;i++)
        f>>a[i]>>b[i];
    s(1,n);
    for (i=1;i<=n;i++) {
        if (a[i]!=a[i-1])
            for (j=a[i-1]+1;j<=a[i];j++)
                k+=y[a[i]];
        if (k==0) c++;
        else k--;
        y[a[i]+b[i]]++;
    }
    t<<c;
    return 0;
}
