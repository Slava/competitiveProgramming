#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;
typedef unsigned char uchar;
typedef unsigned short ushort;

#define MAX_LEN 3100
#define bigint ushort *
#define base 10

bigint tmp = new ushort[MAX_LEN];
bigint prr = new ushort[MAX_LEN];
bigint tmp1 = new ushort[MAX_LEN];
bigint tmp2 = new ushort[MAX_LEN];

int cmp(bigint a, bigint b){
    if(a[0]!=b[0]) return (int)a[0]-b[0];
    for(register int i=a[0];i>0;i--)
        if(a[i]!=b[i]) return (int)a[i]-b[i];
    return 0;
}

bigint read(){
    bigint r = new ushort[MAX_LEN];
    char s[MAX_LEN];
    scanf("%s",s);
    int c = 0, l = strlen(s);
    if(l>1)
        for(int i=0;i<l;i++, c++)
            if(s[i]!='0') break;
    r[0]=l-c;
    for(register int i=l-1; i>=c; i--)
        r[l-i]=s[i]-'0';
    return r;
}

void write(bigint n){
    for(int i=n[0];i>0;i--)
        printf("%d",n[i]);
}

void smul(bigint a, ushort b, bigint c) {
    long i, temp;
    ushort carry=0;
    for (i=1; i<=a[0];i++) {
        temp = a[i]*b + carry;
        carry = temp / base;
        c[i] = temp - carry*base;
    }
    if (carry) {
        c[i] = carry;
        c[0] = a[0]+1;
    }
    else c[0] = a[0];
    while(c[0]>0 && c[c[0]]==0) c[0]--;
}

void shift(bigint a, int s){
    for(int i=a[0];i>0;i--)
        a[i+s] = a[i];
    for(int i=1;i<=s;i++) a[i]=0;
    a[0]+=s;
}

void summ(bigint a, bigint b, bigint c){
    long i, temp;
    ushort carry = 0;
    if ( a[0] < b[0] ) {
        summ(b,a,c);
        return;
    }
    for (i=1; i<=b[0]; i++) {
        temp = a[i] + b[i] + carry;
        if (temp >= base) {
            c[i] = temp - base;
            carry = 1;
        } else {
            c[i] = temp;
            carry = 0;
        }
    }
    for (; i <= a[0]; i++) {
        temp = a[i] + carry;
        if (temp >= base) {
            c[i] = temp - base;
            carry = 1;
        } else {
            c[i] = temp;
            carry = 0;
        }
    }
    if (carry) {
        c[i] = carry;
        c[0] = a[0]+1;
    }
    else c[0] = a[0];
    while(c[0]>0 && c[c[0]]==0) c[0]--;
}

ushort findBin(bigint a, bigint r, int cur){
    // though... it's not a binary search.
    short res = base-1;
    ushort up = base-1, down = 0;
    while(res>0){
        smul(r, 2, tmp1);
        smul(tmp1, res, tmp2);
        shift(tmp2, cur-1);
        summ(prr, tmp2, tmp);
        tmp1[0]=1; tmp1[1]=res;
        smul(tmp1, res, tmp2);
        shift(tmp2, cur*2-2);
        summ(tmp, tmp2, tmp1);
        if(cmp(tmp1,a)<=0){
            break;
        }
        res--;
    }
    while(res>=base) res--;
    smul(r, 2, tmp1);
    smul(tmp1, res, tmp2);
    shift(tmp2, cur-1);
    summ(prr, tmp2, tmp);
    tmp1[0]=1; tmp1[1]=res;
    smul(tmp1, res, tmp2);
    shift(tmp2, cur*2-2);
    summ(tmp, tmp2, prr);
    return r[cur]=res;
}

bigint sqrt(bigint a){
    bigint r = new ushort[MAX_LEN];
    r[0] = (a[0]+1)>>1;
    for(register int i=1;i<=r[0];i++)
        r[i]=0;
    register int cur = r[0];
    while(cur){
        r[0] = (a[0]+1)>>1;
        r[cur]=findBin(a, r, cur);
        cur--;
    }
    return r;
}

bigint n; bigint s;
ushort z[1000000];
void hmm ()
{

    int carry = 0, temp=0,i,j;
    for (i = 1; i <=s[0]*3;i++)z[i]=0;
    z[0]=s[0]*2;

    for (i = 1; i <= s[0]; i++)
    {
        carry = 0;
        for ( j = 1; j <= s[0]; j++)
        {
            temp=z[i+j-1] + s[i]*s[j]+carry;
            carry = temp/10;
            z[i+j-1] = temp - carry*10;
        }
        z[i+j-1]=carry;
    }
    z[0]=i+j;
    while(!z[0])
    {
        z[0]--;
    }
}

bool cmp2 ()
{
    if (z[0] != n[0])return 0;
    for (int i = 1; i <= z[0];i++)
        if(z[i]!=n[i])return 0;
    return 1;
}

int main() {
    freopen("sqrt.in","r",stdin);
    freopen("sqrt.out","w",stdout);

    prr[0]=0;
    n = read();
    s = sqrt(n);
    hmm();
    if (cmp2()==0)write(s);
    else puts("-1");
    return 0;
}
