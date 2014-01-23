#include <iostream.h>
int main () {
int a[10];
float sum=0;
for (int i=0;i<7;i++){
    if (i==0) {
        cout<<"Monday - >";
        }
            if (i==1) {
        cout<<"Tuesday - >";
        }
            if (i==2) {
        cout<<"Wednesday - >";
        }
            if (i==3) {
        cout<<"Thursday - >";
        }
            if (i==4) {
        cout<<"Friday - >";
        }
            if (i==5) {
        cout<<"Saturday - >";
        }
            if (i==6) {
        cout<<"Sunday - >";
        }
    cin>>a[i];
sum+=a[i];
        }
sum=sum/7;

cout<<"average is "<<sum<<endl;

system ("pause");
return 0;
}
