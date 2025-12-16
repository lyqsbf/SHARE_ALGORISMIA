#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(4);
	int n;
	while (cin >> n) cout << (n == 1 ? 1.0 : 1.0 / 2) << endl;
}
