#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

vector<string>str, cmd;
int n;char s[10101];

int main (){
	freopen("grep.in", "r", stdin);
	freopen("grep.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s", s);
		cmd.push_back(s);
	}
	for (; scanf("%s", s) == 1;){
		str.push_back(s);
	}
	for (int i = 0; i < n; i++)
		if (cmd[i] == "-n")
			printf("%d\n", str.size());
		else{
			for (int j = 0; j < str.size(); j++)
				if (str[j].find(cmd[i]) != string::npos)
					printf("%s\n", str[j].c_str());
		}

	return 0;
}

