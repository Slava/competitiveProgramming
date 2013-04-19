#include <iostream>
#include <algorithm>

using namespace std;

int main (){
	int n,k;
	long long x1,x2;
	cin >> n >> k;
	x1 = k - 1;
	x2 = k * x1;

	for(int i = 3; i <= n; i++){
		swap(x1,x2);
		x2 +=x1;
		x2 *= k - 1;
	}
	cout << x2;

	return 0;
}
