#include <iostream>
#include <algorithm>
using namespace std;


int main ()
{
    freopen("apples.in","r",stdin);
    freopen("apples.out","w",stdout);

    short n, k, a[20000];
    long long sum=0;
    cin>>n>>k;

    for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
    sort(a,a+n);
    for(int i=0;i<k;i++){
        sum-=a[i];
        }
    cout<<sum;

    return 0;
}
