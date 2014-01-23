#include <iostream>

using namespace std;

int main ()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

    char s[105];
    int a[250]={0},i,c=0,z, b;
    cin>>s;z=strlen(s);
    for(i=0;i<z;i++)
        a[i]=s[z-i-1]-48;
    cin>>b;
    for(i=0;i<z;i++)
    {
        a[i]=a[i]*b+c;
        c=a[i]/10;
        a[i]=a[i]%10;
    }
    while(c>0){a[z]=c%10;z++;c=c/10;}
    for(i=z-1;i>=0;i--)if(a[i])break;else z--;
    for(i=z-1;i>=0;i--)
        cout<<a[i];
    if(!z)cout<<0;

}
