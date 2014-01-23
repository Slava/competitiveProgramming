#include <iostream>
using namespace std;

int main()
{
    freopen("parts.in","r",stdin);
    freopen("parts.out","w",stdout);

    char s[1000];
    bool a[1000],t=1;int sum=0,sum1=0;
    cin>>s;
    for(int i=0;i<strlen(s);i++)
        switch(s[i]){
            case 'e':a[i]=1;break;
            case 'u':a[i]=1;break;
            case 'i':a[i]=1;break;
            case 'o':a[i]=1;break;
            case 'a':a[i]=1;break;
            default :a[i]=0;
            }
    for(int i=0;i<strlen(s);i++)sum+=a[i];

    for(int i=0;i<strlen(s);i++)
    {
        if(!a[i]){
            for(i;1;i++)
                if(a[i]||i==strlen(s)){sum1++;break;}
            }
        else if(a[i]){
            for(i;1;i++)
                if(!a[i]||i==strlen(s)){sum1++;i--;break;}
            }
    }

    cout<<sum1<<' '<<sum;

    return 0;
}
