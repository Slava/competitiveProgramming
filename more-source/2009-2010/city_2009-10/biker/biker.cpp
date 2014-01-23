#include <iostream>
using namespace std;

int main()
{
    freopen("biker.in","r",stdin);
    freopen("biker.out","w",stdout);

    double a[100000],n, sum=0;
    cin>>n;

    cin>>a[0];
    for(int i=1;i<n;i++){
            cin>>a[i];
        sum+=(a[i]+a[i-1])/2;
    }
    if(n==1){cout<<a[0]<<".00";goto end;}

    cout.precision(2);
    cout<<fixed<<(double)sum/(n-1);
    end:

    return 0;
}
