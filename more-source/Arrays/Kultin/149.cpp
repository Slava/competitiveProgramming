#include <iostream.h>
int main () {
int a[10000],j,b;
cout<<"How much elements in arrey? ";
cin>>j;
for (int i=0;i<j;i++){
cout<<"Enter element No "<<i+1<<" ";
cin>>a[i];
        }
cout<<"Enter searchkey ";
cin>>b;
for (int i=0;i<j;i++){
cout<<"Now cheking element No "<<i+1<<" "<<a[i]<<endl;
    if (b==a[i]){
        cout<<"Found! Element No "<<i+1<<" "<<a[i]<<endl;
        break;}
    else{
        cout<<"failed"<<endl<<endl;
        }

        }

system ("pause");
return 0;
}
