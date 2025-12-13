#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;
VVI V;
int n, k;


int f(int n, int k) {
	if (k > n) return 0;
	else if (V[n][k] != -1) return V[n][k];
	else if (k == 0) {
		V[n][k] = 1;
		return V[n][k];
	}
	else {
		return V[n][k] = f(n - 1, k - 1) + f(n - 1, k);
	}
}


int main() {
	V = VVI(31, VI(31, -1));
	while (cin >> n >> k) {
		V[0][0] = 1;
		V[1][0] = 1;
		V[1][1] = 1;
		
		cout << f(n, k) << endl;
	}
}
