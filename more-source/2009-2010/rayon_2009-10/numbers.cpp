#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
    freopen("numbers.in","r",stdin);
    freopen("numbers.out","w",stdout);

    double z[16];int l=0;
    double A,B,C,D;

    cin>>A>>B>>C;

    z[l]=A+B+C;l++;

    D=A+B-C;


    if((find(z,z+l,D)-z)==l){z[l]=D;l++;}

    D=A+B*C;
    if((find(z,z+l,D)-z)==l){z[l]=D;l++;}

    D=A+B/C;
    if((find(z,z+l,D)-z)==l){z[l]=D;l++;}

    D=A-B+C;
    if((find(z,z+l,D)-z)==l){z[l]=D;l++;}

    D=A-B-C;
    if((find(z,z+l,D)-z)==l){z[l]=D;l++;}

    D=A-B*C;
    if((find(z,z+l,D)-z)==l){z[l]=D;l++;}

    D=A-B/C;
    if((find(z,z+l,D)-z)==l){z[l]=D;l++;}

    D=A*B+C;
    if((find(z,z+l,D)-z)==l){z[l]=D;l++;}

    D=A*B-C;
    if((find(z,z+l,D)-z)==l){z[l]=D;l++;}

    D=A*B*C;
    if((find(z,z+l,D)-z)==l){z[l]=D;l++;}

    D=A*B/C;
    if((find(z,z+l,D)-z)==l){z[l]=D;l++;}

    D=A/B+C;
    if((find(z,z+l,D)-z)==l){z[l]=D;l++;}

    D=A/B-C;
    if((find(z,z+l,D)-z)==l){z[l]=D;l++;}

    D=A/B*C;
    if((find(z,z+l,D)-z)==l){z[l]=D;l++;}

    D=A/B/C;
    if((find(z,z+l,D)-z)==l){z[l]=D;l++;}

    cout<<l;

    return 0;
}
