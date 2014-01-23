#include <iostream>
using namespace std;
int main () {
int j,key;
int counter=0;
cout<<"How much elements in arrey? ";
cin>>j;
int a[j];
cout<<"Enter elements :"<<endl;
    for (int i=0;i<j;i++){
        cin>>a[i];
        }
cout<<"Enter search key: ";
cin>>key;

    for (int i=0;i<j;i++){
        if (a[i]==key){
            counter++;
            }
        }
if (counter<=1)
cout<<"It was found!"<<endl;
if (counter==0)
cout<<"Was not found."<<endl;
system ("pause");
return 0;
}
