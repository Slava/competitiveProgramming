#include <iostream>
using namespace std;
int main () {
int j,temp;
cout<<"How much elements in arrey? ";
cin>>j;
int a[j];
cout<<"Enter elements :"<<endl;
    for (int i=0;i<j;i++){
        cin>>a[i];
        }
    for (int i=1;i<j;i++){
        for (int i1=j-1;i1>=i;i1++) {
            if (a[i1-1]<a[i1]){
                temp=a[i1-1];
                a[i1-1]=a[i1];
                a[i1]=temp;
                }

            }

        }
    for (int i=0;i<j;i++){
        cout<<a[i]<<endl;
        }

system ("pause");
return 0;
}
