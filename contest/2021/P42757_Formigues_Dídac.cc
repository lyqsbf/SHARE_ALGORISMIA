#include <iostream>
using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b) {
		int sum = 0;
		while (a > 0 and b > 0) {
			sum += a + b - 1;
			--a;
			--b;
		}
		cout << sum << endl;
	}
}
