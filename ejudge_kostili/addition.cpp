#include <string>
#include <iostream>

using namespace std;

string s;

int main() {
	while (getline(cin, s))
		if (s == "[problem]")
			break;
	do cout << s << endl; while(getline(cin,s));
	return 0;
}

