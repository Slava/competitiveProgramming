#include <iostream>
#include <fstream>
using namespace std;
ifstream f("d.in");
ofstream t("d.out");
int n,m,l,r,s,x,y[50009],k,h,a,i,j;
int main ()
{
    f>>n>>m;
    for (i=1;i<=m;i++) {
        f>>x;
        if (x==1) {
            f>>l>>r>>s;
            for (j=l;j<r;j++) {
                if (y[j]+s>0)
                    y[j]+=s;
                else y[j]=0;
            }
        }
        else {
            f>>l>>r;
            s=0;
            for (j=l;j<r;j++)
                s+=y[j];
            t<<s<<endl;
        }
    }
    return 0;
}
