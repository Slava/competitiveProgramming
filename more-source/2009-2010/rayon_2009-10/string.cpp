#include <iostream>
#include <string>
using namespace std;


int main ()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    char s[10000],a[26];
    for(int i=0;i<26;i++)a[i]=0;
    cin>>s;

    for(int i=0;i<strlen(s);i++)a[s[i]-97]++;
    for(int i=0;i<26;i++)if(a[i]>1)cout<<(char)(i+97);

    return 0;
}
