#include <iostream>
using namespace std;
int N,size=1;
short a[1000000]={0};

void stepen (){
    short carry=0;
    short temp;
    int i;
  for (i=0; i<size;i++) {
    temp = a[i]*2 + carry;
    carry = temp / 10;
    a[i] = temp - carry*10;
 }
if (carry) {
  a[i] = carry;size++;
 }

}
int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);

    a[0]=1;
    cin>>N;
    for (int j=0;j<N;j++){
        stepen();
    }
    for (int i=size-1;i>=0;i--){
cout<<a[i];
}
return 0;
}

