#include <iostream.h>
int main () {
int a[10],non0=0;
float sum=0;
long long min=100000000,max=-100000000;
    cout<<"Enter ten numbers --> ";
for (int i=0;i<10;i++){
    cin>>a[i];
    if (a[i]!=0){
        non0++;
        sum+=a[i];
        if (a[i]<min)
            {
            min=a[i];
            }
        if (a[i]>max)
            {
            max=a[i];
            }
        }

    }
    non0-=2;
sum=sum-(max+min);
sum=sum/non0;

cout<<"number of non-zero elements whithout max and min is "<<non0<<endl;
cout<<"minimum element is"<<min<<endl;
cout<<"maximum element is"<<max<<endl;
cout<<"average without counteing max and min is "<<sum<<endl;

system ("pause");
return 0;
}
