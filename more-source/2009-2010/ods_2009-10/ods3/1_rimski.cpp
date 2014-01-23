#include <iostream>
#include <string>
using namespace std;

int main () {
	freopen ("rimski.in", "r", stdin);
	freopen ("rimski.out", "w", stdout);

	string s;
	cin>>s;
	if(s=="I"||"i"){cout<<s;goto end;}
	if(s=="II"||"ii"){cout<<s;goto end;}
	if(s=="III"||"iii"){cout<<s;goto end;}
	if(s=="IV"||"iv"||"Iv"){cout<<s;goto end;}
	if(s=="V"||"v"){cout<<s;goto end;}
	if(s=="VI"||"vi"||"vI"){cout<<"IV";goto end;}
	if(s=="VII"||"vii"||"vII"){cout<<"VII";goto end;}
	if(s=="VIII"||"viii"||"vIII"){cout<<"";goto end;}
	if(s=="I"||"i"){cout<<"";goto end;}
end:
return 0;
}
