#include <iostream>
using namespace std;

int main()
{
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);

    long long d,m,y,sum=6;
    cin>>d>>m>>y;
    for(int i=2000;i<y;i++)
    {
         if(i%4==0)sum++;
         sum+=365;
    }
    for(int i=1;i<m;i++){
        switch(i){
            case 1: sum+=31; break;
            case 2: sum+=28;if(y%4==0)sum+=1; break;
            case 3: sum+=31; break;
            case 4: sum+=30; break;
            case 5: sum+=31; break;
            case 6: sum+=30; break;
            case 7: sum+=31; break;
            case 8: sum+=31; break;
            case 9: sum+=30; break;
            case 10: sum+=31; break;
            case 11: sum+=30; break;
            }
        }
    sum+=d;sum--;
    if(sum%7==0)cout<<"7";
    else cout<<sum%7;

    return 0;
}
