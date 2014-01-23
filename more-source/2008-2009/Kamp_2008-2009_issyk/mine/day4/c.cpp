#include <iostream>
#include <fstream>

using namespace std;

template <class T>
T GCD(T a, T b)
 {
    while(a!=0 && b!=0)
    {
       if(a>=b) a=a%b;
           else b=b%a;
    }
 return a+b;
 }



main () {
    ifstream fin ("c.in");
    ofstream fout ("c.out");

    int a,b,d,y,x;
    fin>>a>>b;
    d=GCD(a,b);
    fout<<d<<endl;

    for(x=0;x<100000;x++){
        for(y=0;y<100000;y++){
            if((x*a)+(y*b)==d){goto end;}
            if((-1*x*a)+(y*b)==d){x*=-1;goto end;}
            if((x*a)+(y*b*-1)==d){y*=-1;goto end;}
        }
    }
    x=0;y=0;
    end:

fout<<x<<" "<<y;
    return 0;
    }
