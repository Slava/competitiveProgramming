#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    long long n,a[10000],five,three,jana[100000]={0};
    cin>>a[0]>>n;
    for(int i=1;i<n;i++)
    {
        three=five=0;
        while(1)
        {
            if((a[i-1]-three*3)%5==0&&(a[i-1]-three*3)){five=(a[i-1]-three*3)/5;break;}
            else if((a[i-1]-three*3)/3>0)three++;
                else break;
        }

        jana[i]=five*9+three*5;
        a[i]=a[i-1]+jana[i];
        if(i>2)a[i]-=jana[i-3];
    }
    cout<<a[n-1];

    return 0;
}
