#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("a.in");
ofstream t("a.out");
int a[50009],b[50009],c[50009],n,m,k,i,j,h,x,g,w,u,e,y[50009],q[50009];
void s(int l,int r) {
    int p;
    i=l;j=r;
    p=a[(i+j)/2];
    do {
        while (a[i]<p) i++;
        while (a[j]>p) j--;
        if (i<=j) {
            swap(a[i],a[j]);
            swap(c[i],c[j]);
            i++; j--;
        }
    }while (i<=j);
    if (i<r) s(i,r);
    if (l<j) s(l,j);
}
void s2(int l,int r) {
    int p;
    i=l;j=r;
    p=c[(i+j)/2];
    do {
        while (c[i]<p) i++;
        while (c[j]>p) j--;
        if (i<=j) {
            swap(a[i],a[j]);
            swap(c[i],c[j]);
            i++; j--;
        }
    }while (i<=j);
    if (i<r) s2(i,r);
    if (l<j) s2(l,j);
}
int main()
{
    f>>n>>k>>m;
    for (i=1;i<=m;i++) {
        f>>a[i]>>b[i];
        c[i]=i;
    }
    s(1,m);
    x=-1; g=1; e=0;
    for (h=1;h<=m;h++) {
        if (g==1) {
            if (a[h]!=x)
                x=a[h];
            else {
                e=2;
                g=0;
                if (m==h)
                { h--; x=-1; w=1;}
            }
        }
        else {
            if (a[h]==x) {
                e++;
                if (m==h)
                { h--; x=-1; w=1;}
            }
            else {
                s2(h-e+w,h-1+w);
                e=0;
                g=1;
                h--;
               // cout<<"i"<<endl;
            }
        }
        //cout<<e<<" "<<h<<endl;
    }
   // for (i=1;i<=m;i++)
       // cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
    for (i=1;i<=m;i++) {
        cout<<a[i]<<" "<<c[i]<<" "<<k<<endl;
        if (a[i]==b[c[i]]){
            if (k>0) q[c[i]]=1;
            else q[c[i]]=0;
        }
        else {
            if (a[i]!=a[i-1])
                for (j=a[i-1]+1;j<=a[i];j++)
                    k+=y[j];
            if (k>0) {
                y[b[c[i]]]++;
                k--;
                q[c[i]]=1;
            }
            else q[c[i]]=0;
        }
    }
    for (i=1;i<=m;i++)
        t<<q[i]<<endl;
    return 0;
}





















