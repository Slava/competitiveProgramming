#include <iostream.h>
int main () {
int counter;
for (counter=1;counter<100;counter++){
if (counter==5)
continue;
if (counter==11)
break;

cout<<counter<<" ";

}
return 0;
}
