#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
	string str, s;
	getline(cin, str);
	int j = 0;
	vector<int>u(str.size());
	for (; cin >> s; ) {
		int pos = str.find(s, j);
		if(pos == -1) {
			cout << "I HAVE FAILED!!!";
			return 0;
		}
		for (int i = 0; i < s.size(); i++)
			u[pos + i] = 1;
		j = pos + s.size() + 1;
	}
	for (int i = 0; i < str.size(); i++)
		if (str[i] == ' ' || u[i])
			cout << str[i];
		else cout << "_";
	return 0;
}

