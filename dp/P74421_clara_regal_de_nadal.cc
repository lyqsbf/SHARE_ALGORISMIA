#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
VI bolets, dp1, dp2;
int n;


int main() {
	int k = 1;
	while (cin >> n) {
		cout << '#' << k << endl;
		bolets = dp1 = dp2 = VI(n + 2, 0);
		for (int i = 1; i < n + 1; ++i) cin >> bolets[i];
		
		for (int i = 1; i < n + 1; ++i) {
			dp1[i] = dp1[i - 1] + bolets[i];
		}

		for (int i = n; i > 0; --i) {
			dp2[i] = dp2[i + 1] + bolets[i];
		}
		int q;
		cin >> q;
		for (int i = 0; i < q; ++i) {
			int p, c;
			cin >> p >> c;
			if (p == c) cout << bolets[c] << endl;
			else if (p < c) cout << dp1[c] - dp1[p - 1] << endl;
			else cout << dp2[c] - dp2[p + 1] << endl;
		}
		++k;
	}
}
