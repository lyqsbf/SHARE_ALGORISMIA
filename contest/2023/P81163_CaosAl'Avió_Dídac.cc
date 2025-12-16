#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(4);
	int n;
	while (cin >> n) {
		if (n == 1) cout << 1.0 << endl;
		else cout << 1.0 / 2 << endl;
	}
}
