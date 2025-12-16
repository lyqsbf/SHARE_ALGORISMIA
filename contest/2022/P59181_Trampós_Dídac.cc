#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int> v(n);
		for (int& i : v) cin >> i;
		if (n < 4 and v[n-1] == n) {
			cout << ((n == 3 and v[0] == 2) ? "SI 1 2 3" : "NO") << endl;
		}
		else {
			cout << "SI";
			for (int i : v) 
				cout << ' ' << (i == n ? 1 : i + 1);
			cout << endl;
		}
	}
}
