#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n % 2 == 1 and n > 3) {
			cout << "SI ";
			for (int i = 2; i <= n; ++i) cout << i << ' ';
			cout << '2' << endl;
		}
		else cout << "NO" << endl;
	}
}
