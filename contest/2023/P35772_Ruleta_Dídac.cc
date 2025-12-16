#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(5);
	int x, y;
	while (cin >> x >> y) {
		const double p = 18.0 / 37;
		double pr = 1;
		while (x < y and pr > 0.00000) {
			pr *= p;
			x *= 2;
		}
		cout << pr << endl;
	}
}
